#include <verilated.h>
#include <verilated_fst_c.h>

#include <cstdint>
#include <iostream>

#include "VRV32I_System.h"
#include "VRV32I_System___024root.h"

namespace {

constexpr uint32_t RESET_PC      = 0x10000000u;
constexpr uint32_t TIMEOUT_CYCLE = 80u;  // pipeline + sync read memory 여유 반영

// Opcodes
constexpr uint32_t OPC_LUI       = 0b0110111;
constexpr uint32_t OPC_AUIPC     = 0b0010111;
constexpr uint32_t OPC_JAL       = 0b1101111;
constexpr uint32_t OPC_JALR      = 0b1100111;
constexpr uint32_t OPC_BRANCH    = 0b1100011;
constexpr uint32_t OPC_STORE     = 0b0100011;
constexpr uint32_t OPC_LOAD      = 0b0000011;
constexpr uint32_t OPC_ARI_RTYPE = 0b0110011;
constexpr uint32_t OPC_ARI_ITYPE = 0b0010011;

// funct3
constexpr uint32_t FNC_BEQ     = 0b000;
constexpr uint32_t FNC_BNE     = 0b001;
constexpr uint32_t FNC_BLT     = 0b100;
constexpr uint32_t FNC_BGE     = 0b101;
constexpr uint32_t FNC_BLTU    = 0b110;
constexpr uint32_t FNC_BGEU    = 0b111;
constexpr uint32_t FNC_LB      = 0b000;
constexpr uint32_t FNC_LH      = 0b001;
constexpr uint32_t FNC_LW      = 0b010;
constexpr uint32_t FNC_LBU     = 0b100;
constexpr uint32_t FNC_LHU     = 0b101;
constexpr uint32_t FNC_SB      = 0b000;
constexpr uint32_t FNC_SH      = 0b001;
constexpr uint32_t FNC_SW      = 0b010;
constexpr uint32_t FNC_ADD_SUB = 0b000;
constexpr uint32_t FNC_SLL     = 0b001;
constexpr uint32_t FNC_SLT     = 0b010;
constexpr uint32_t FNC_SLTU    = 0b011;
constexpr uint32_t FNC_XOR     = 0b100;
constexpr uint32_t FNC_OR      = 0b110;
constexpr uint32_t FNC_AND     = 0b111;
constexpr uint32_t FNC_SRL_SRA = 0b101;

constexpr uint32_t FNC7_0 = 0b0000000;
constexpr uint32_t FNC7_1 = 0b0100000;

inline uint32_t mask12(int32_t x) { return static_cast<uint32_t>(x) & 0xFFFu; }
inline uint32_t mask13(int32_t x) { return static_cast<uint32_t>(x) & 0x1FFFu; }
inline uint32_t mask21(int32_t x) { return static_cast<uint32_t>(x) & 0x1FFFFFu; }

inline uint32_t enc_r(uint32_t funct7, uint32_t rs2, uint32_t rs1,
                      uint32_t funct3, uint32_t rd, uint32_t opcode) {
    return ((funct7 & 0x7Fu) << 25) |
           ((rs2    & 0x1Fu) << 20) |
           ((rs1    & 0x1Fu) << 15) |
           ((funct3 & 0x7u)  << 12) |
           ((rd     & 0x1Fu) << 7)  |
           ( opcode & 0x7Fu);
}

inline uint32_t enc_i(uint32_t imm12, uint32_t rs1, uint32_t funct3,
                      uint32_t rd, uint32_t opcode) {
    return ((imm12  & 0xFFFu) << 20) |
           ((rs1    & 0x1Fu)  << 15) |
           ((funct3 & 0x7u)   << 12) |
           ((rd     & 0x1Fu)  << 7)  |
           ( opcode & 0x7Fu);
}

inline uint32_t enc_s(uint32_t imm12, uint32_t rs2, uint32_t rs1,
                      uint32_t funct3, uint32_t opcode) {
    return (((imm12 >> 5) & 0x7Fu) << 25) |
           ((rs2    & 0x1Fu)       << 20) |
           ((rs1    & 0x1Fu)       << 15) |
           ((funct3 & 0x7u)        << 12) |
           ((imm12  & 0x1Fu)       << 7)  |
           ( opcode & 0x7Fu);
}

inline uint32_t enc_b(uint32_t imm13, uint32_t rs2, uint32_t rs1,
                      uint32_t funct3, uint32_t opcode) {
    return (((imm13 >> 12) & 0x1u)  << 31) |
           (((imm13 >> 5)  & 0x3Fu) << 25) |
           ((rs2           & 0x1Fu) << 20) |
           ((rs1           & 0x1Fu) << 15) |
           ((funct3        & 0x7u)  << 12) |
           (((imm13 >> 1)  & 0xFu)  << 8)  |
           (((imm13 >> 11) & 0x1u)  << 7)  |
           ( opcode        & 0x7Fu);
}

inline uint32_t enc_u(uint32_t imm32, uint32_t rd, uint32_t opcode) {
    return (imm32 & 0xFFFFF000u) |
           ((rd & 0x1Fu) << 7)   |
           (opcode & 0x7Fu);
}

inline uint32_t enc_j(uint32_t imm21, uint32_t rd, uint32_t opcode) {
    return (((imm21 >> 20) & 0x1u)   << 31) |
           (((imm21 >> 1)  & 0x3FFu) << 21) |
           (((imm21 >> 11) & 0x1u)   << 20) |
           (((imm21 >> 12) & 0xFFu)  << 12) |
           ((rd            & 0x1Fu)  << 7)  |
           ( opcode        & 0x7Fu);
}

class Tb {
public:
    explicit Tb(const char* trace_name) {
        top_ = new VRV32I_System;
        tfp_ = new VerilatedFstC;
        sim_time_ = 0;

        top_->clk   = 0;
        top_->reset = 1;

        Verilated::traceEverOn(true);
        top_->trace(tfp_, 99);
        tfp_->open(trace_name);

        eval_and_dump();
    }

    ~Tb() {
        if (top_) top_->final();
        if (tfp_) tfp_->close();
        delete tfp_;
        delete top_;
    }

    uint32_t& rf(int idx) {
        return top_->rootp->RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[idx];
    }

    uint32_t& mem(uint32_t idx) {
        constexpr uint32_t AWIDTH = 12;
        return top_->rootp->RV32I_System__DOT__imem_dmem__DOT__mem[idx & ((1u << AWIDTH) - 1u)];
    }

    void reset_memories() {
        for (int i = 0; i < 32; ++i) rf(i) = 0;
        for (int i = 0; i < (1 << 12); ++i) mem(i) = 0;
        eval_only();
    }

    void init_rf() {
        for (int i = 1; i < 32; ++i) rf(i) = 100u * static_cast<uint32_t>(i) + 1u;
        eval_only();
    }

    void cpu_reset_sequence() {
        top_->reset = 1;
        for (int i = 0; i < 4; ++i) tick();
        top_->reset = 0;
        tick();
    }

    void powerup_reset_sequence() {
        top_->reset = 1;
        for (int i = 0; i < 10; ++i) tick();
        top_->reset = 0;
        tick();
    }

    void check_rf(uint32_t test_id, int rf_wa, uint32_t expected, const char* name) {
        wait_until([&]() { return rf(rf_wa) == expected; },
                   [&]() { return rf(rf_wa); },
                   test_id, name, expected);
    }

    void check_mem(uint32_t test_id, int addr, uint32_t expected, const char* name) {
        wait_until([&]() { return mem(addr) == expected; },
                   [&]() { return mem(addr); },
                   test_id, name, expected);
    }

private:
    VRV32I_System* top_ = nullptr;
    VerilatedFstC* tfp_ = nullptr;
    uint64_t sim_time_  = 0;

    void eval_only() {
        top_->eval();
    }

    void eval_and_dump() {
        top_->eval();
        tfp_->dump(sim_time_);
    }

    void tick() {
        top_->clk = 0;
        eval_and_dump();
        sim_time_ += 10;

        top_->clk = 1;
        eval_and_dump();
        sim_time_ += 10;
    }

    [[noreturn]] void fail(uint32_t test_id, const char* name, uint32_t expected, uint32_t got) {
        std::cerr << "[Failed] Timeout at [" << test_id << "] test " << name
                  << ", expected_result = 0x" << std::hex << expected
                  << ", got = 0x" << got << std::dec << '\n';
        throw 1;
    }

    template <typename CondFn, typename ReadFn>
    void wait_until(CondFn cond, ReadFn read_current, uint32_t test_id,
                    const char* name, uint32_t expected) {
        uint32_t cycle = 0;
        uint32_t current = read_current();

        while (!cond()) {
            if (cycle == TIMEOUT_CYCLE) fail(test_id, name, expected, current);
            tick();
            ++cycle;
            current = read_current();
        }

        std::cout << "[" << test_id << "] Test " << name << " passed!\n";
    }
};

}  // namespace

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    try {
        Tb tb("dump.fst");
        uint32_t test_id = 0;

        int i;
        uint32_t RD, RS1, RS2, RD1, RD2, SHAMT, IMM, IMM0, IMM1, IMM2, IMM3;
        uint32_t INST_ADDR, DATA_ADDR;
        uint32_t DATA_ADDR0, DATA_ADDR1, DATA_ADDR2, DATA_ADDR3;
        uint32_t DATA_ADDR4, DATA_ADDR5, DATA_ADDR6, DATA_ADDR7, DATA_ADDR8;
        uint32_t JUMP_ADDR;

        uint32_t BR_TAKEN_OP1[6]  = {};
        uint32_t BR_TAKEN_OP2[6]  = {};
        uint32_t BR_NTAKEN_OP1[6] = {};
        uint32_t BR_NTAKEN_OP2[6] = {};
        uint32_t BR_TYPE[6]       = {};
        const char* BR_NAME_TK1[6];
        const char* BR_NAME_TK2[6];
        const char* BR_NAME_NTK[6];

        tb.powerup_reset_sequence();

        // R-Type -----------------------------------------------------------
        tb.reset_memories();
        RS1 = 1; RD1 = static_cast<uint32_t>(-100);
        RS2 = 2; RD2 = 200;
        RD  = 3;
        tb.rf(RS1) = RD1;
        tb.rf(RS2) = RD2;
        SHAMT      = 20;
        INST_ADDR  = 0x0000;

        tb.mem(INST_ADDR + 0)  = enc_r(FNC7_0, RS2,   RS1, FNC_ADD_SUB,  3, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 1)  = enc_r(FNC7_1, RS2,   RS1, FNC_ADD_SUB,  4, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 2)  = enc_r(FNC7_0, RS2,   RS1, FNC_SLL,      5, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 3)  = enc_r(FNC7_0, RS2,   RS1, FNC_SLT,      6, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 4)  = enc_r(FNC7_0, RS2,   RS1, FNC_SLTU,     7, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 5)  = enc_r(FNC7_0, RS2,   RS1, FNC_XOR,      8, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 6)  = enc_r(FNC7_0, RS2,   RS1, FNC_OR,       9, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 7)  = enc_r(FNC7_0, RS2,   RS1, FNC_AND,     10, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 8)  = enc_r(FNC7_0, RS2,   RS1, FNC_SRL_SRA, 11, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 9)  = enc_r(FNC7_1, RS2,   RS1, FNC_SRL_SRA, 12, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 10) = enc_i((FNC7_0 << 5) | SHAMT, RS1, FNC_SLL,     13, OPC_ARI_ITYPE);
        tb.mem(INST_ADDR + 11) = enc_i((FNC7_0 << 5) | SHAMT, RS1, FNC_SRL_SRA, 14, OPC_ARI_ITYPE);
        tb.mem(INST_ADDR + 12) = enc_i((FNC7_1 << 5) | SHAMT, RS1, FNC_SRL_SRA, 15, OPC_ARI_ITYPE);
        tb.cpu_reset_sequence();

        tb.check_rf(++test_id, 3,  0x00000064u, "R-Type ADD");
        tb.check_rf(++test_id, 4,  0xfffffed4u, "R-Type SUB");
        tb.check_rf(++test_id, 5,  0xffff9c00u, "R-Type SLL");
        tb.check_rf(++test_id, 6,  0x00000001u, "R-Type SLT");
        tb.check_rf(++test_id, 7,  0x00000000u, "R-Type SLTU");
        tb.check_rf(++test_id, 8,  0xffffff54u, "R-Type XOR");
        tb.check_rf(++test_id, 9,  0xffffffdcu, "R-Type OR");
        tb.check_rf(++test_id,10,  0x00000088u, "R-Type AND");
        tb.check_rf(++test_id,11,  0x00ffffffu, "R-Type SRL");
        tb.check_rf(++test_id,12,  0xffffffffu, "R-Type SRA");
        tb.check_rf(++test_id,13,  0xf9c00000u, "R-Type SLLI");
        tb.check_rf(++test_id,14,  0x00000fffu, "R-Type SRLI");
        tb.check_rf(++test_id,15,  0xffffffffu, "R-Type SRAI");

        // I-Type arithmetic -----------------------------------------------
        tb.reset_memories();
        RS1 = 1; RD1 = static_cast<uint32_t>(-100);
        tb.rf(RS1) = RD1;
        IMM = static_cast<uint32_t>(-200);
        INST_ADDR = 0;
        tb.mem(INST_ADDR + 0) = enc_i(mask12(static_cast<int32_t>(IMM)), RS1, FNC_ADD_SUB, 3, OPC_ARI_ITYPE);
        tb.mem(INST_ADDR + 1) = enc_i(mask12(static_cast<int32_t>(IMM)), RS1, FNC_SLT,     4, OPC_ARI_ITYPE);
        tb.mem(INST_ADDR + 2) = enc_i(mask12(static_cast<int32_t>(IMM)), RS1, FNC_SLTU,    5, OPC_ARI_ITYPE);
        tb.mem(INST_ADDR + 3) = enc_i(mask12(static_cast<int32_t>(IMM)), RS1, FNC_XOR,     6, OPC_ARI_ITYPE);
        tb.mem(INST_ADDR + 4) = enc_i(mask12(static_cast<int32_t>(IMM)), RS1, FNC_OR,      7, OPC_ARI_ITYPE);
        tb.mem(INST_ADDR + 5) = enc_i(mask12(static_cast<int32_t>(IMM)), RS1, FNC_AND,     8, OPC_ARI_ITYPE);
        tb.cpu_reset_sequence();

        tb.check_rf(++test_id, 3, 0xfffffed4u, "I-Type ADD");
        tb.check_rf(++test_id, 4, 0x00000000u, "I-Type SLT");
        tb.check_rf(++test_id, 5, 0x00000000u, "I-Type SLTU");
        tb.check_rf(++test_id, 6, 0x000000a4u, "I-Type XOR");
        tb.check_rf(++test_id, 7, 0xffffffbcu, "I-Type OR");
        tb.check_rf(++test_id, 8, 0xffffff18u, "I-Type AND");

        // I-Type loads ----------------------------------------------------
        tb.reset_memories();
        tb.rf(1) = 0x30000100u;
        IMM0 = 0; IMM1 = 1; IMM2 = 2; IMM3 = 3;
        INST_ADDR = 0;
        DATA_ADDR = (tb.rf(1) + IMM0) >> 2;

        tb.mem(INST_ADDR + 0)  = enc_i(IMM0, 1, FNC_LW,  2,  OPC_LOAD);
        tb.mem(INST_ADDR + 1)  = enc_i(IMM0, 1, FNC_LH,  3,  OPC_LOAD);
        tb.mem(INST_ADDR + 4)  = enc_i(IMM2, 1, FNC_LH,  5,  OPC_LOAD);
        tb.mem(INST_ADDR + 6)  = enc_i(IMM0, 1, FNC_LB,  7,  OPC_LOAD);
        tb.mem(INST_ADDR + 7)  = enc_i(IMM1, 1, FNC_LB,  8,  OPC_LOAD);
        tb.mem(INST_ADDR + 8)  = enc_i(IMM2, 1, FNC_LB,  9,  OPC_LOAD);
        tb.mem(INST_ADDR + 9)  = enc_i(IMM3, 1, FNC_LB, 10,  OPC_LOAD);
        tb.mem(INST_ADDR + 10) = enc_i(IMM0, 1, FNC_LHU,11,  OPC_LOAD);
        tb.mem(INST_ADDR + 12) = enc_i(IMM2, 1, FNC_LHU,13,  OPC_LOAD);
        tb.mem(INST_ADDR + 14) = enc_i(IMM0, 1, FNC_LBU,15,  OPC_LOAD);
        tb.mem(INST_ADDR + 15) = enc_i(IMM1, 1, FNC_LBU,16,  OPC_LOAD);
        tb.mem(INST_ADDR + 16) = enc_i(IMM2, 1, FNC_LBU,17,  OPC_LOAD);
        tb.mem(INST_ADDR + 17) = enc_i(IMM3, 1, FNC_LBU,18,  OPC_LOAD);
        tb.mem(DATA_ADDR)      = 0xdeadbeefu;
        tb.cpu_reset_sequence();

        tb.check_rf(++test_id,  2, 0xdeadbeefu, "I-Type LW");
        tb.check_rf(++test_id,  3, 0xffffbeefu, "I-Type LH 0");
        tb.check_rf(++test_id,  5, 0xffffdeadu, "I-Type LH 2");
        tb.check_rf(++test_id,  7, 0xffffffefu, "I-Type LB 0");
        tb.check_rf(++test_id,  8, 0xffffffbeu, "I-Type LB 1");
        tb.check_rf(++test_id,  9, 0xffffffadu, "I-Type LB 2");
        tb.check_rf(++test_id, 10, 0xffffffdeu, "I-Type LB 3");
        tb.check_rf(++test_id, 11, 0x0000beefu, "I-Type LHU 0");
        tb.check_rf(++test_id, 13, 0x0000deadu, "I-Type LHU 2");
        tb.check_rf(++test_id, 15, 0x000000efu, "I-Type LBU 0");
        tb.check_rf(++test_id, 16, 0x000000beu, "I-Type LBU 1");
        tb.check_rf(++test_id, 17, 0x000000adu, "I-Type LBU 2");
        tb.check_rf(++test_id, 18, 0x000000deu, "I-Type LBU 3");

        // S-Type ----------------------------------------------------------
        tb.reset_memories();
        tb.rf(1)  = 0x12345678u;
        tb.rf(2)  = 0x30000010u;
        tb.rf(3)  = 0x30000020u;
        tb.rf(4)  = 0x30000030u;
        tb.rf(5)  = 0x30000040u;
        tb.rf(6)  = 0x30000050u;
        tb.rf(7)  = 0x30000060u;
        tb.rf(8)  = 0x30000070u;
        tb.rf(9)  = 0x30000080u;
        tb.rf(10) = 0x30000090u;

        IMM0 = 0x100; IMM1 = 0x101; IMM2 = 0x102; IMM3 = 0x103;
        INST_ADDR = 0;

        DATA_ADDR0 = (tb.rf(2)  + IMM0) >> 2;
        DATA_ADDR1 = (tb.rf(3)  + IMM0) >> 2;
        DATA_ADDR2 = (tb.rf(4)  + IMM1) >> 2;
        DATA_ADDR3 = (tb.rf(5)  + IMM2) >> 2;
        DATA_ADDR4 = (tb.rf(6)  + IMM3) >> 2;
        DATA_ADDR5 = (tb.rf(7)  + IMM0) >> 2;
        DATA_ADDR6 = (tb.rf(8)  + IMM1) >> 2;
        DATA_ADDR7 = (tb.rf(9)  + IMM2) >> 2;
        DATA_ADDR8 = (tb.rf(10) + IMM3) >> 2;

        tb.mem(INST_ADDR + 0) = enc_s(IMM0, 1, 2,  FNC_SW, OPC_STORE);
        tb.mem(INST_ADDR + 1) = enc_s(IMM0, 1, 3,  FNC_SH, OPC_STORE);
        tb.mem(INST_ADDR + 3) = enc_s(IMM2, 1, 5,  FNC_SH, OPC_STORE);
        tb.mem(INST_ADDR + 5) = enc_s(IMM0, 1, 7,  FNC_SB, OPC_STORE);
        tb.mem(INST_ADDR + 6) = enc_s(IMM1, 1, 8,  FNC_SB, OPC_STORE);
        tb.mem(INST_ADDR + 7) = enc_s(IMM2, 1, 9,  FNC_SB, OPC_STORE);
        tb.mem(INST_ADDR + 8) = enc_s(IMM3, 1, 10, FNC_SB, OPC_STORE);

        tb.mem(DATA_ADDR0) = 0;
        tb.mem(DATA_ADDR1) = 0;
        tb.mem(DATA_ADDR3) = 0;
        tb.mem(DATA_ADDR4) = 0;
        tb.mem(DATA_ADDR5) = 0;
        tb.mem(DATA_ADDR6) = 0;
        tb.mem(DATA_ADDR7) = 0;
        tb.mem(DATA_ADDR8) = 0;
        tb.cpu_reset_sequence();

        tb.check_mem(++test_id, DATA_ADDR0, 0x12345678u, "S-Type SW");
        tb.check_mem(++test_id, DATA_ADDR1, 0x00005678u, "S-Type SH 1");
        tb.check_mem(++test_id, DATA_ADDR3, 0x56780000u, "S-Type SH 3");
        tb.check_mem(++test_id, DATA_ADDR5, 0x00000078u, "S-Type SB 1");
        tb.check_mem(++test_id, DATA_ADDR6, 0x00007800u, "S-Type SB 2");
        tb.check_mem(++test_id, DATA_ADDR7, 0x00780000u, "S-Type SB 3");
        tb.check_mem(++test_id, DATA_ADDR8, 0x78000000u, "S-Type SB 4");

        // U-Type ----------------------------------------------------------
        tb.reset_memories();
        IMM = 0x7FFF0123u;
        INST_ADDR = 0;
        tb.mem(INST_ADDR + 0) = enc_u(IMM, 3, OPC_LUI);
        tb.mem(INST_ADDR + 1) = enc_u(IMM, 4, OPC_AUIPC);
        tb.cpu_reset_sequence();
        tb.check_rf(++test_id, 3, 0x7fff0000u, "U-Type LUI");
        tb.check_rf(++test_id, 4, 0x8fff0004u, "U-Type AUIPC");

        // JAL -------------------------------------------------------------
        tb.reset_memories();
        tb.rf(1) = 100; tb.rf(2) = 200; tb.rf(3) = 300; tb.rf(4) = 400;
        IMM = 0x00000FF0u;
        INST_ADDR = 0;
        JUMP_ADDR = (RESET_PC + ((IMM & 0x1FFFFEu))) >> 2;
        tb.mem(INST_ADDR + 0) = enc_j(mask21(static_cast<int32_t>(IMM)), 5, OPC_JAL);
        tb.mem(INST_ADDR + 1) = enc_r(FNC7_0, 2, 1, FNC_ADD_SUB, 6, OPC_ARI_RTYPE);
        tb.mem(JUMP_ADDR & 0x3FFFu) = enc_r(FNC7_0, 4, 3, FNC_ADD_SUB, 7, OPC_ARI_RTYPE);
        tb.cpu_reset_sequence();
        tb.check_rf(++test_id, 5, 0x10000004u, "J-Type JAL");
        tb.check_rf(++test_id, 7, 700u,       "J-Type JAL");
        tb.check_rf(++test_id, 6, 0u,         "J-Type JAL");

        // JALR ------------------------------------------------------------
        tb.reset_memories();
        tb.rf(1) = 0x10000100u; tb.rf(2) = 200; tb.rf(3) = 300; tb.rf(4) = 400;
        IMM = 0xFFFFFFF0u;
        INST_ADDR = 0;
        JUMP_ADDR = (tb.rf(1) + static_cast<int32_t>(IMM)) >> 2;
        tb.mem(INST_ADDR + 0) = enc_i(mask12(static_cast<int32_t>(IMM)), 1, 0b000, 5, OPC_JALR);
        tb.mem(INST_ADDR + 1) = enc_r(FNC7_0, 2, 1, FNC_ADD_SUB, 6, OPC_ARI_RTYPE);
        tb.mem(JUMP_ADDR & 0x3FFFu) = enc_r(FNC7_0, 4, 3, FNC_ADD_SUB, 7, OPC_ARI_RTYPE);
        tb.cpu_reset_sequence();
        tb.check_rf(++test_id, 5, 0x10000004u, "J-Type JALR");
        tb.check_rf(++test_id, 7, 700u,        "J-Type JALR");
        tb.check_rf(++test_id, 6, 0u,          "J-Type JALR");

        // B-Type ----------------------------------------------------------
        IMM       = 0x00000FF0u;
        INST_ADDR = 0;
        JUMP_ADDR = (RESET_PC + (IMM & 0x1FFFu)) >> 2;

        BR_TYPE[0] = FNC_BEQ;  BR_NAME_TK1[0] = "B-Type BEQ Taken 1";  BR_NAME_TK2[0] = "B-Type BEQ Taken 2";  BR_NAME_NTK[0] = "B-Type BEQ Not Taken";
        BR_TAKEN_OP1[0] = 100; BR_TAKEN_OP2[0] = 100; BR_NTAKEN_OP1[0] = 100; BR_NTAKEN_OP2[0] = 200;
        BR_TYPE[1] = FNC_BNE;  BR_NAME_TK1[1] = "B-Type BNE Taken 1";  BR_NAME_TK2[1] = "B-Type BNE Taken 2";  BR_NAME_NTK[1] = "B-Type BNE Not Taken";
        BR_TAKEN_OP1[1] = 100; BR_TAKEN_OP2[1] = 200; BR_NTAKEN_OP1[1] = 100; BR_NTAKEN_OP2[1] = 100;
        BR_TYPE[2] = FNC_BLT;  BR_NAME_TK1[2] = "B-Type BLT Taken 1";  BR_NAME_TK2[2] = "B-Type BLT Taken 2";  BR_NAME_NTK[2] = "B-Type BLT Not Taken";
        BR_TAKEN_OP1[2] = 100; BR_TAKEN_OP2[2] = 200; BR_NTAKEN_OP1[2] = 200; BR_NTAKEN_OP2[2] = 100;
        BR_TYPE[3] = FNC_BGE;  BR_NAME_TK1[3] = "B-Type BGE Taken 1";  BR_NAME_TK2[3] = "B-Type BGE Taken 2";  BR_NAME_NTK[3] = "B-Type BGE Not Taken";
        BR_TAKEN_OP1[3] = 300; BR_TAKEN_OP2[3] = 200; BR_NTAKEN_OP1[3] = 100; BR_NTAKEN_OP2[3] = 200;
        BR_TYPE[4] = FNC_BLTU; BR_NAME_TK1[4] = "B-Type BLTU Taken 1"; BR_NAME_TK2[4] = "B-Type BLTU Taken 2"; BR_NAME_NTK[4] = "B-Type BLTU Not Taken";
        BR_TAKEN_OP1[4] = 0x00000001u; BR_TAKEN_OP2[4] = 0xFFFF0000u; BR_NTAKEN_OP1[4] = 0xFFFF0000u; BR_NTAKEN_OP2[4] = 0x00000001u;
        BR_TYPE[5] = FNC_BGEU; BR_NAME_TK1[5] = "B-Type BGEU Taken 1"; BR_NAME_TK2[5] = "B-Type BGEU Taken 2"; BR_NAME_NTK[5] = "B-Type BGEU Not Taken";
        BR_TAKEN_OP1[5] = 0xFFFF0000u; BR_TAKEN_OP2[5] = 0x00000001u; BR_NTAKEN_OP1[5] = 0x00000001u; BR_NTAKEN_OP2[5] = 0xFFFF0000u;

        for (i = 0; i < 6; ++i) {
            tb.reset_memories();
            tb.rf(1) = BR_TAKEN_OP1[i]; tb.rf(2) = BR_TAKEN_OP2[i]; tb.rf(3) = 300; tb.rf(4) = 400;
            tb.mem(INST_ADDR + 0) = enc_b(mask13(static_cast<int32_t>(IMM)), 2, 1, BR_TYPE[i], OPC_BRANCH);
            tb.mem(INST_ADDR + 1) = enc_r(FNC7_0, 4, 3, FNC_ADD_SUB, 5, OPC_ARI_RTYPE);
            tb.mem(JUMP_ADDR & 0x3FFFu) = enc_r(FNC7_0, 4, 3, FNC_ADD_SUB, 6, OPC_ARI_RTYPE);
            tb.cpu_reset_sequence();
            tb.check_rf(++test_id, 5, 0u,   BR_NAME_TK1[i]);
            tb.check_rf(++test_id, 6, 700u, BR_NAME_TK2[i]);

            tb.reset_memories();
            tb.rf(1) = BR_NTAKEN_OP1[i]; tb.rf(2) = BR_NTAKEN_OP2[i]; tb.rf(3) = 300; tb.rf(4) = 400;
            tb.mem(INST_ADDR + 0) = enc_b(mask13(static_cast<int32_t>(IMM)), 2, 1, BR_TYPE[i], OPC_BRANCH);
            tb.mem(INST_ADDR + 1) = enc_r(FNC7_0, 4, 3, FNC_ADD_SUB, 5, OPC_ARI_RTYPE);
            tb.cpu_reset_sequence();
            tb.check_rf(++test_id, 5, 700u, BR_NAME_NTK[i]);
        }

        // Hazards ---------------------------------------------------------
        tb.reset_memories(); tb.init_rf(); INST_ADDR = 0;
        tb.mem(INST_ADDR + 0) = enc_r(FNC7_0, 1, 2, FNC_ADD_SUB, 3, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 1) = enc_r(FNC7_0, 3, 4, FNC_ADD_SUB, 5, OPC_ARI_RTYPE);
        tb.cpu_reset_sequence();
        tb.check_rf(++test_id, 5, tb.rf(1) + tb.rf(2) + tb.rf(4), "Hazard 1");

        tb.reset_memories(); tb.init_rf(); INST_ADDR = 0;
        tb.mem(INST_ADDR + 0) = enc_r(FNC7_0, 1, 2, FNC_ADD_SUB, 3, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 1) = enc_r(FNC7_0, 4, 3, FNC_ADD_SUB, 5, OPC_ARI_RTYPE);
        tb.cpu_reset_sequence();
        tb.check_rf(++test_id, 5, tb.rf(1) + tb.rf(2) + tb.rf(4), "Hazard 2");

        tb.reset_memories(); tb.init_rf(); INST_ADDR = 0;
        tb.mem(INST_ADDR + 0) = enc_r(FNC7_0, 1, 2, FNC_ADD_SUB, 3, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 1) = enc_r(FNC7_0, 4, 5, FNC_ADD_SUB, 6, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 2) = enc_r(FNC7_0, 3, 7, FNC_ADD_SUB, 8, OPC_ARI_RTYPE);
        tb.cpu_reset_sequence();
        tb.check_rf(++test_id, 8, tb.rf(1) + tb.rf(2) + tb.rf(7), "Hazard 3");

        tb.reset_memories(); tb.init_rf(); INST_ADDR = 0;
        tb.mem(INST_ADDR + 0) = enc_r(FNC7_0, 1, 2, FNC_ADD_SUB, 3, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 1) = enc_r(FNC7_0, 4, 5, FNC_ADD_SUB, 6, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 2) = enc_r(FNC7_0, 7, 3, FNC_ADD_SUB, 8, OPC_ARI_RTYPE);
        tb.cpu_reset_sequence();
        tb.check_rf(++test_id, 8, tb.rf(1) + tb.rf(2) + tb.rf(7), "Hazard 4");

        tb.reset_memories(); tb.init_rf(); INST_ADDR = 0;
        tb.mem(INST_ADDR + 0) = enc_r(FNC7_0, 1, 2, FNC_ADD_SUB, 3, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 1) = enc_r(FNC7_0, 4, 3, FNC_ADD_SUB, 5, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 2) = enc_r(FNC7_0, 5, 6, FNC_ADD_SUB, 7, OPC_ARI_RTYPE);
        tb.cpu_reset_sequence();
        tb.check_rf(++test_id, 7, tb.rf(1) + tb.rf(2) + tb.rf(4) + tb.rf(6), "Hazard 5");

        tb.reset_memories(); tb.init_rf(); tb.rf(4) = 0x30000100u; IMM = 0; INST_ADDR = 0;
        DATA_ADDR = (tb.rf(4) + IMM) >> 2;
        tb.mem(INST_ADDR + 0) = enc_r(FNC7_0, 1, 2, FNC_ADD_SUB, 3, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 1) = enc_s(IMM, 3, 4, FNC_SW, OPC_STORE);
        tb.cpu_reset_sequence();
        tb.check_mem(++test_id, DATA_ADDR, tb.rf(1) + tb.rf(2), "Hazard 6");

        tb.reset_memories(); tb.init_rf(); tb.rf(1) = 0x30000100u; IMM = 0; INST_ADDR = 0;
        DATA_ADDR = (tb.rf(1) + IMM) >> 2;
        tb.mem(DATA_ADDR) = 0x12345678u;
        tb.mem(INST_ADDR + 0) = enc_i(IMM, 1, FNC_LW, 2, OPC_LOAD);
        tb.mem(INST_ADDR + 1) = enc_r(FNC7_0, 2, 3, FNC_ADD_SUB, 4, OPC_ARI_RTYPE);
        tb.cpu_reset_sequence();
        tb.check_rf(++test_id, 4, tb.mem(DATA_ADDR) + tb.rf(3), "Hazard 7");

        tb.reset_memories(); tb.init_rf(); tb.rf(1) = 0x30000100u; tb.rf(4) = 0x30000200u; IMM = 0; INST_ADDR = 0;
        DATA_ADDR0 = (tb.rf(1) + IMM) >> 2;
        DATA_ADDR1 = (tb.rf(4) + IMM) >> 2;
        tb.mem(DATA_ADDR0) = 0x12345678u;
        tb.mem(INST_ADDR + 0) = enc_i(IMM, 1, FNC_LW, 2, OPC_LOAD);
        tb.mem(INST_ADDR + 1) = enc_s(IMM, 2, 4, FNC_SW, OPC_STORE);
        tb.cpu_reset_sequence();
        tb.check_mem(++test_id, DATA_ADDR1, tb.mem(DATA_ADDR0), "Hazard 8");

        tb.reset_memories(); tb.init_rf(); tb.rf(1) = 0x30000100u; IMM = 0; INST_ADDR = 0;
        DATA_ADDR0 = (tb.rf(1) + IMM) >> 2;
        tb.mem(DATA_ADDR0) = 0x30000200u;
        DATA_ADDR1 = (tb.mem(DATA_ADDR0) + IMM) >> 2;
        tb.mem(INST_ADDR + 0) = enc_i(IMM, 1, FNC_LW, 2, OPC_LOAD);
        tb.mem(INST_ADDR + 1) = enc_s(IMM, 4, 2, FNC_SW, OPC_STORE);
        tb.cpu_reset_sequence();
        tb.check_mem(++test_id, DATA_ADDR1, tb.rf(4), "Hazard 9");

        tb.reset_memories(); tb.init_rf(); INST_ADDR = 0; IMM = 0x00000FF0u;
        JUMP_ADDR = (0x10000008u + (IMM & 0x1FFFu)) >> 2;
        tb.mem(INST_ADDR + 0) = enc_r(FNC7_0, 1, 4, FNC_ADD_SUB, 6, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 1) = enc_r(FNC7_0, 2, 3, FNC_ADD_SUB, 7, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 2) = enc_b(mask13(static_cast<int32_t>(IMM)), 6, 7, FNC_BEQ, OPC_BRANCH);
        tb.mem(INST_ADDR + 3) = enc_r(FNC7_0, 8, 9, FNC_ADD_SUB, 10, OPC_ARI_RTYPE);
        tb.mem(JUMP_ADDR & 0x3FFFu) = enc_r(FNC7_1, 8, 9, FNC_ADD_SUB, 11, OPC_ARI_RTYPE);
        tb.cpu_reset_sequence();
        tb.check_rf(++test_id, 10, 1001u, "Hazard 10 1");
        tb.check_rf(++test_id, 11, tb.rf(9) - tb.rf(8), "Hazard 10 2");

        tb.reset_memories(); tb.init_rf(); IMM = 0x00000004u; INST_ADDR = 0;
        JUMP_ADDR = (RESET_PC + (IMM & 0x1FFFFEu)) >> 2;
        tb.mem(INST_ADDR + 0) = enc_j(mask21(static_cast<int32_t>(IMM)), 1, OPC_JAL);
        tb.mem(INST_ADDR + 1) = enc_r(FNC7_0, 2, 1, FNC_ADD_SUB, 3, OPC_ARI_RTYPE);
        tb.cpu_reset_sequence();
        tb.check_rf(++test_id, 3, tb.rf(2) + 0x10000004u, "Hazard 11");

        tb.reset_memories(); tb.init_rf(); tb.rf(4) = 0x10000000u; IMM = 0x00000004u; INST_ADDR = 0;
        JUMP_ADDR = (tb.rf(1) + IMM) >> 2;
        tb.mem(INST_ADDR + 0) = enc_i(IMM, 4, 0b000, 1, OPC_JALR);
        tb.mem(INST_ADDR + 1) = enc_r(FNC7_0, 2, 1, FNC_ADD_SUB, 3, OPC_ARI_RTYPE);
        tb.cpu_reset_sequence();
        tb.check_rf(++test_id, 3, tb.rf(2) + 0x10000004u, "Hazard 12");

        // Branch not taken ------------------------------------------------
        tb.reset_memories();
        INST_ADDR = 0;

        // x1=5, x2=8, so beq x1,x2,+8 must NOT be taken.
        // Sequential instructions after beq must execute.
        tb.mem(INST_ADDR + 0) = 0x00500093u; // addi x1,x0,5
        tb.mem(INST_ADDR + 1) = 0x00800113u; // addi x2,x0,8
        tb.mem(INST_ADDR + 2) = 0x00208463u; // beq  x1,x2,+8 (not taken)
        tb.mem(INST_ADDR + 3) = 0x00100193u; // addi x3,x0,1
        tb.mem(INST_ADDR + 4) = 0x00200213u; // addi x4,x0,2
        tb.mem(INST_ADDR + 5) = 0x00302023u; // sw   x3,0(x0)
        tb.mem(INST_ADDR + 6) = 0x00402223u; // sw   x4,4(x0)
        tb.mem(INST_ADDR + 7) = 0x00000013u; // nop

        tb.cpu_reset_sequence();

        tb.check_mem(++test_id, 0, 1u, "Branch Not Taken SW 0");
        tb.check_mem(++test_id, 1, 2u, "Branch Not Taken SW 4");

        std::cout << "[TB] branch-not-taken done. mem[0]=0x"
                  << std::hex << tb.mem(0)
                  << " mem[1]=0x" << tb.mem(1)
                  << std::dec << '\n';

        // Flush verification using JAL ------------------------------------
        tb.reset_memories();
        INST_ADDR = 0;

        // jal must redirect to 0x10000010
        // instructions at 0x08 and 0x0C must be flushed and not commit.
        tb.mem(INST_ADDR + 0) = 0x00100093u; // addi x1,x0,1
        tb.mem(INST_ADDR + 1) = 0x00C002EFu; // jal  x5,+12 -> 0x10
        tb.mem(INST_ADDR + 2) = 0x00900113u; // addi x2,x0,9  (flush candidate)
        tb.mem(INST_ADDR + 3) = 0x00900193u; // addi x3,x0,9  (flush candidate)
        tb.mem(INST_ADDR + 4) = 0x00300213u; // addi x4,x0,3
        tb.mem(INST_ADDR + 5) = 0x00102023u; // sw   x1,0(x0)
        tb.mem(INST_ADDR + 6) = 0x00202223u; // sw   x2,4(x0)
        tb.mem(INST_ADDR + 7) = 0x00302423u; // sw   x3,8(x0)
        tb.mem(INST_ADDR + 8) = 0x00402623u; // sw   x4,12(x0)
        tb.mem(INST_ADDR + 9) = 0x00000013u; // nop

        tb.cpu_reset_sequence();

        tb.check_mem(++test_id, 0, 1u, "Flush JAL SW 0");
        tb.check_mem(++test_id, 1, 0u, "Flush JAL SW 4");
        tb.check_mem(++test_id, 2, 0u, "Flush JAL SW 8");
        tb.check_mem(++test_id, 3, 3u, "Flush JAL SW 12");

        std::cout << "[TB] flush done. mem[0]=0x"
                  << std::hex << tb.mem(0)
                  << " mem[1]=0x" << tb.mem(1)
                  << " mem[2]=0x" << tb.mem(2)
                  << " mem[3]=0x" << tb.mem(3)
                  << std::dec << '\n';
        
        // Forwarding-focused test -----------------------------------------
        tb.reset_memories();
        INST_ADDR = 0;

        // x1 = 1
        // x2 = x1 + 2 = 3
        // x3 = x2 + x1 = 4
        // x4 = x3 + x2 = 7
        // store x3 -> dmem[0], x4 -> dmem[1]
        tb.mem(INST_ADDR + 0) = 0x00100093u; // addi x1,x0,1
        tb.mem(INST_ADDR + 1) = 0x00208113u; // addi x2,x1,2
        tb.mem(INST_ADDR + 2) = 0x001101B3u; // add  x3,x2,x1
        tb.mem(INST_ADDR + 3) = 0x00218233u; // add  x4,x3,x2
        tb.mem(INST_ADDR + 4) = 0x00302023u; // sw   x3,0(x0)
        tb.mem(INST_ADDR + 5) = 0x00402223u; // sw   x4,4(x0)
        tb.mem(INST_ADDR + 6) = 0x00000013u; // nop

        tb.cpu_reset_sequence();

        tb.check_mem(++test_id, 0, 4u, "Forwarding SW 0");
        tb.check_mem(++test_id, 1, 7u, "Forwarding SW 4");

        std::cout << "[TB] forwarding done. mem[0]=0x"
                  << std::hex << tb.mem(0)
                  << " mem[1]=0x" << tb.mem(1)
                  << std::dec << '\n';

        // Load-use hazard test --------------------------------------------
        tb.reset_memories();
        INST_ADDR = 0;

        // Use a non-overlapping data address
        tb.rf(10) = 0x10000080u;              // base address for data
        DATA_ADDR0 = (tb.rf(10) + 0) >> 2;    // word index for 0x10000080
        DATA_ADDR1 = (tb.rf(10) + 4) >> 2;
        DATA_ADDR2 = (tb.rf(10) + 8) >> 2;

        // Preload data memory word with 7
        tb.mem(DATA_ADDR0) = 7u;

        // lw   x1,0(x10)     -> x1 = 7
        // add  x2,x1,x1      -> x2 = 14 (requires stall)
        // addi x3,x0,1       -> x3 = 1
        // sw   x2,4(x10)     -> dmem[base+4] = 14
        // sw   x3,8(x10)     -> dmem[base+8] = 1
        tb.mem(INST_ADDR + 0) = enc_i(0, 10, FNC_LW,      1, OPC_LOAD);
        tb.mem(INST_ADDR + 1) = enc_r(FNC7_0, 1, 1, FNC_ADD_SUB, 2, OPC_ARI_RTYPE);
        tb.mem(INST_ADDR + 2) = 0x00100193u; // addi x3,x0,1
        tb.mem(INST_ADDR + 3) = enc_s(4, 2, 10, FNC_SW, OPC_STORE);
        tb.mem(INST_ADDR + 4) = enc_s(8, 3, 10, FNC_SW, OPC_STORE);
        tb.mem(INST_ADDR + 5) = 0x00000013u; // nop

        tb.cpu_reset_sequence();

        tb.check_mem(++test_id, DATA_ADDR0, 7u,  "Load-Use SW 0");
        tb.check_mem(++test_id, DATA_ADDR1, 14u, "Load-Use SW 4");
        tb.check_mem(++test_id, DATA_ADDR2, 1u,  "Load-Use SW 8");

        // Smoke test ------------------------------------------------------
        tb.reset_memories();
        INST_ADDR = 0;

        // Preload stable base registers from TB
        tb.rf(13) = 0x10000080u;              // x13 = data base
        tb.rf(10) = 0x10000140u;              // x10 = jalr target base
        DATA_ADDR0 = (tb.rf(13) + 0) >> 2;    // 0x10000080 -> word index 0x20

        // 0x00 : addi x1, x0, 5
        // 0x04 : addi x2, x0, 8
        // 0x08 : add  x3, x1, x2        -> x3 = 13
        // 0x0C : nop
        // 0x10 : sw   x3, 0(x13)        -> mem[0x10000080] = 13
        // 0x14 : nop
        // 0x18 : lw   x4, 0(x13)        -> x4 = 13
        // 0x1C : beq  x4, x3, +8        -> to 0x24, flush 0x20
        // 0x20 : addi x5, x0, 1         -> flush candidate
        // 0x24 : nop                    -> absorbs first-target-loss issue for BEQ
        // 0x28 : addi x8, x0, 2         -> normal instruction after branch target
        // 0x2C : jal  x6, +8            -> to 0x34, flush 0x30
        // 0x30 : addi x7, x0, 1         -> flush candidate
        // 0x34 : nop                    -> absorbs first-target-loss issue for JAL
        // 0x38 : addi x8, x8, 1         -> x8 = 3
        // 0x3C : jalr x9, x10, 0        -> to 0x10000140, flush 0x40
        // 0x40 : addi x11, x0, 3        -> flush candidate
        // 0x140: addi x12, x0, 4
        // 0x144: nop

        tb.mem(INST_ADDR + 0x00/4) = 0x00500093u; // addi x1,x0,5
        tb.mem(INST_ADDR + 0x04/4) = 0x00800113u; // addi x2,x0,8
        tb.mem(INST_ADDR + 0x08/4) = 0x002081B3u; // add  x3,x1,x2
        tb.mem(INST_ADDR + 0x0C/4) = 0x00000013u; // nop

        tb.mem(INST_ADDR + 0x10/4) = 0x0036A023u; // sw   x3,0(x13)
        tb.mem(INST_ADDR + 0x14/4) = 0x00000013u; // nop
        tb.mem(INST_ADDR + 0x18/4) = 0x0006A203u; // lw   x4,0(x13)

        tb.mem(INST_ADDR + 0x1C/4) = enc_b(8, 3, 4, FNC_BEQ, OPC_BRANCH); // beq x4,x3,+8 => 0x24
        tb.mem(INST_ADDR + 0x20/4) = 0x00100293u; // addi x5,x0,1 (flush candidate)

        tb.mem(INST_ADDR + 0x24/4) = 0x00000013u; // nop
        tb.mem(INST_ADDR + 0x28/4) = 0x00200413u; // addi x8,x0,2
        tb.mem(INST_ADDR + 0x2C/4) = enc_j(8, 6, OPC_JAL); // jal x6,+8 => 0x34
        tb.mem(INST_ADDR + 0x30/4) = 0x00100393u; // addi x7,x0,1 (flush candidate)

        tb.mem(INST_ADDR + 0x34/4) = 0x00000013u; // nop
        tb.mem(INST_ADDR + 0x38/4) = 0x00140413u; // addi x8,x8,1 => x8 = 3
        tb.mem(INST_ADDR + 0x3C/4) = 0x000504E7u; // jalr x9,x10,0
        tb.mem(INST_ADDR + 0x40/4) = 0x00300593u; // addi x11,x0,3 (flush candidate)

        // 0x10000140 = RESET_PC + 0x140  -> word index = 0x140 / 4 = 0x50
        tb.mem(0x140/4) = 0x00400613u; // addi x12,x0,4
        tb.mem(0x144/4) = 0x00000013u; // nop

        tb.cpu_reset_sequence();

        // Memory result
        tb.check_mem(++test_id, DATA_ADDR0, 13u, "Smoke Mem[0x10000080]");

        // Registers proving control-flow worked
        tb.check_rf(++test_id, 4,  13u,         "Smoke LW x4");
        tb.check_rf(++test_id, 5,  0u,          "Smoke BEQ flush x5");
        tb.check_rf(++test_id, 6,  0x10000030u, "Smoke JAL link x6");
        tb.check_rf(++test_id, 7,  0u,          "Smoke JAL flush x7");
        tb.check_rf(++test_id, 8,  3u,          "Smoke branch/jal path x8");
        tb.check_rf(++test_id, 9,  0x10000040u, "Smoke JALR link x9");
        tb.check_rf(++test_id, 10, 0x10000140u, "Smoke JALR base x10");
        tb.check_rf(++test_id, 11, 0u,          "Smoke JALR flush x11");
        tb.check_rf(++test_id, 12, 4u,          "Smoke JALR target x12");

        // Strict: BEQ target first-slot must execute ----------------------
        tb.reset_memories();
        INST_ADDR = 0;

        tb.mem(INST_ADDR + 0) = 0x00500093u; // addi x1,x0,5
        tb.mem(INST_ADDR + 1) = 0x00500113u; // addi x2,x0,5
        tb.mem(INST_ADDR + 2) = enc_b(8, 2, 1, FNC_BEQ, OPC_BRANCH); // beq x1,x2,+8 -> 0x10
        tb.mem(INST_ADDR + 3) = 0x00100193u; // addi x3,x0,1 (must flush)
        tb.mem(INST_ADDR + 4) = 0x00200213u; // addi x4,x0,2 (first target, must execute)
        tb.mem(INST_ADDR + 5) = 0x00402023u; // sw x4,0(x0)
        tb.mem(INST_ADDR + 6) = 0x00000013u; // nop

        tb.cpu_reset_sequence();

        tb.check_mem(++test_id, 0, 2u, "Strict BEQ target first-slot");
        tb.check_rf(++test_id, 3, 0u,  "Strict BEQ flush old path");

        // Strict: JAL target first-slot must execute ----------------------
        tb.reset_memories();
        INST_ADDR = 0;

        tb.mem(INST_ADDR + 0) = enc_j(8, 5, OPC_JAL); // jal x5,+8 -> 0x08
        tb.mem(INST_ADDR + 1) = 0x00100113u;         // addi x2,x0,1 (must flush)
        tb.mem(INST_ADDR + 2) = 0x00300193u;         // addi x3,x0,3 (first target, must execute)
        tb.mem(INST_ADDR + 3) = 0x00302023u;         // sw x3,0(x0)
        tb.mem(INST_ADDR + 4) = 0x00000013u;         // nop

        tb.cpu_reset_sequence();

        tb.check_mem(++test_id, 0, 3u,          "Strict JAL target first-slot");
        tb.check_rf(++test_id, 5, 0x10000004u,  "Strict JAL link");
        tb.check_rf(++test_id, 2, 0u,           "Strict JAL flush old path");

        // Strict: redirect-after-redirect --------------------------------
        tb.reset_memories();
        INST_ADDR = 0;

        tb.mem(INST_ADDR + 0) = 0x00100093u; // addi x1,x0,1
        tb.mem(INST_ADDR + 1) = 0x00100113u; // addi x2,x0,1
        tb.mem(INST_ADDR + 2) = enc_b(8, 2, 1, FNC_BEQ, OPC_BRANCH); // beq -> 0x10
        tb.mem(INST_ADDR + 3) = 0x00100193u; // addi x3,x0,1 (flush)
        tb.mem(INST_ADDR + 4) = enc_j(8, 6, OPC_JAL);                // jal -> 0x18
        tb.mem(INST_ADDR + 5) = 0x00100213u; // addi x4,x0,1 (flush)
        tb.mem(INST_ADDR + 6) = 0x00500293u; // addi x5,x0,5 (jal target)
        tb.mem(INST_ADDR + 7) = 0x00502023u; // sw x5,0(x0)
        tb.mem(INST_ADDR + 8) = 0x00000013u; // nop

        tb.cpu_reset_sequence();

        tb.check_mem(++test_id, 0, 5u,         "Strict redirect-after-redirect");
        tb.check_rf(++test_id, 3, 0u,          "Strict BEQ flush");
        tb.check_rf(++test_id, 4, 0u,          "Strict JAL flush");
        tb.check_rf(++test_id, 6, 0x10000014u, "Strict JAL link after BEQ");

        // Strict: store -> load same address ------------------------------
        tb.reset_memories();
        INST_ADDR = 0;
        tb.rf(13) = 0x10000080u;
        DATA_ADDR0 = (tb.rf(13) + 0) >> 2;

        tb.mem(INST_ADDR + 0) = 0x00D00193u; // addi x3,x0,13
        tb.mem(INST_ADDR + 1) = 0x0036A023u; // sw   x3,0(x13)
        tb.mem(INST_ADDR + 2) = 0x0006A203u; // lw   x4,0(x13)
        tb.mem(INST_ADDR + 3) = 0x00402023u; // sw   x4,0(x0)
        tb.mem(INST_ADDR + 4) = 0x00000013u; // nop

        tb.cpu_reset_sequence();

        tb.check_mem(++test_id, DATA_ADDR0, 13u, "Strict store data commit");
        tb.check_rf(++test_id, 4, 13u,           "Strict same-address load");
        tb.check_mem(++test_id, 0, 13u,          "Strict same-address readback");

        // Strict: base register just-produced -----------------------------
        tb.reset_memories();
        INST_ADDR = 0;

        tb.mem(INST_ADDR + 0) = 0x100006B7u; // lui  x13,0x10000
        tb.mem(INST_ADDR + 1) = 0x08068693u; // addi x13,x13,0x80
        tb.mem(INST_ADDR + 2) = 0x00700193u; // addi x3,x0,7
        tb.mem(INST_ADDR + 3) = 0x0036A023u; // sw   x3,0(x13)
        tb.mem(INST_ADDR + 4) = 0x0006A203u; // lw   x4,0(x13)
        tb.mem(INST_ADDR + 5) = 0x00000013u; // nop

        tb.cpu_reset_sequence();

        tb.check_mem(++test_id, 0x20, 7u, "Strict base-produced store");
        tb.check_rf(++test_id, 4, 7u,     "Strict base-produced load");

        // x0 protection test ----------------------------------------------
        tb.reset_memories();
        INST_ADDR = 0;

        // x0 protection test
        // addi x0,x0,5 must be ignored.
        // Insert 2 nops before stores to separate x0 protection from store-data timing.
        tb.mem(INST_ADDR + 0) = 0x00500013u; // addi x0,x0,5   (must be ignored)
        tb.mem(INST_ADDR + 1) = 0x00100093u; // addi x1,x0,1   -> x1 = 1
        tb.mem(INST_ADDR + 2) = 0x00100133u; // add  x2,x0,x1  -> x2 = 1
        tb.mem(INST_ADDR + 3) = 0x00000013u; // nop
        tb.mem(INST_ADDR + 4) = 0x00000013u; // nop
        tb.mem(INST_ADDR + 5) = 0x00002023u; // sw   x0,0(x0)  -> dmem[0] = 0
        tb.mem(INST_ADDR + 6) = 0x00102223u; // sw   x1,4(x0)  -> dmem[1] = 1
        tb.mem(INST_ADDR + 7) = 0x00202423u; // sw   x2,8(x0)  -> dmem[2] = 1
        tb.mem(INST_ADDR + 8) = 0x00000013u; // nop

        tb.cpu_reset_sequence();

        tb.check_mem(++test_id, 0, 0u, "x0 protection SW 0");
        tb.check_mem(++test_id, 1, 1u, "x0 protection SW 4");
        tb.check_mem(++test_id, 2, 1u, "x0 protection SW 8");

        std::cout << "[TB] x0-protection done. mem[0]=0x"
                  << std::hex << tb.mem(0)
                  << " mem[1]=0x" << tb.mem(1)
                  << " mem[2]=0x" << tb.mem(2)
                  << std::dec << '\n';

        // Corner 1: sb -> lb / lbu same-address
        tb.reset_memories();
        INST_ADDR = 0;
        DATA_ADDR = 0x10000080u >> 2;

        tb.mem(INST_ADDR + 0) = 0x10000537u; // lui   x10,0x10000
        tb.mem(INST_ADDR + 1) = 0x08050513u; // addi  x10,x10,128
        tb.mem(INST_ADDR + 2) = 0xf8000093u; // addi  x1,x0,-128
        tb.mem(INST_ADDR + 3) = 0x00150023u; // sb    x1,0(x10)
        tb.mem(INST_ADDR + 4) = 0x00050103u; // lb    x2,0(x10)
        tb.mem(INST_ADDR + 5) = 0x00054183u; // lbu   x3,0(x10)

        tb.cpu_reset_sequence();

        tb.check_rf(++test_id, 2, 0xffffff80u, "Corner 1 LB same-address");
        tb.check_rf(++test_id, 3, 0x00000080u, "Corner 1 LBU same-address");
        tb.check_mem(++test_id, DATA_ADDR, 0x00000080u, "Corner 1 SB commit");

        // Corner 2: sh -> lh / lhu same-address
        tb.reset_memories();
        INST_ADDR = 0;
        DATA_ADDR = 0x10000080u >> 2;

        tb.mem(INST_ADDR + 0) = 0x10000537u; // lui   x10,0x10000
        tb.mem(INST_ADDR + 1) = 0x08050513u; // addi  x10,x10,128
        tb.mem(INST_ADDR + 2) = 0xf8000093u; // addi  x1,x0,-128   -> 0xffffff80
        tb.mem(INST_ADDR + 3) = 0x00151123u; // sh    x1,2(x10)
        tb.mem(INST_ADDR + 4) = 0x00251103u; // lh    x2,2(x10)
        tb.mem(INST_ADDR + 5) = 0x00255183u; // lhu   x3,2(x10)

        tb.cpu_reset_sequence();

        tb.check_rf(++test_id, 2, 0xffffff80u, "Corner 2 LH same-address");
        tb.check_rf(++test_id, 3, 0x0000ff80u, "Corner 2 LHU same-address");
        tb.check_mem(++test_id, DATA_ADDR, 0xff800000u, "Corner 2 SH commit");

        // Corner 3: load-use + taken branch
        tb.reset_memories();
        INST_ADDR = 0;
        DATA_ADDR = 0x10000080u >> 2;

        tb.mem(INST_ADDR + 0) = 0x10000537u; // lui   x10,0x10000
        tb.mem(INST_ADDR + 1) = 0x08050513u; // addi  x10,x10,128
        tb.mem(INST_ADDR + 2) = 0x00100093u; // addi  x1,x0,1
        tb.mem(INST_ADDR + 3) = 0x00152023u; // sw    x1,0(x10)
        tb.mem(INST_ADDR + 4) = 0x00052103u; // lw    x2,0(x10)
        tb.mem(INST_ADDR + 5) = 0x00110463u; // beq   x2,x1,+8
        tb.mem(INST_ADDR + 6) = 0x00900193u; // addi  x3,x0,9 (flush)
        tb.mem(INST_ADDR + 7) = 0x00700213u; // addi  x4,x0,7

        tb.cpu_reset_sequence();

        tb.check_rf(++test_id, 2, 1u, "Corner 3 LW result");
        tb.check_rf(++test_id, 3, 0u, "Corner 3 branch flush");
        tb.check_rf(++test_id, 4, 7u, "Corner 3 branch target");
        tb.check_mem(++test_id, DATA_ADDR, 1u, "Corner 3 store commit");

        // Corner 5: branch -> branch redirect
        tb.reset_memories();
        INST_ADDR = 0;

        tb.mem(INST_ADDR + 0) = 0x00100093u; // addi x1,x0,1
        tb.mem(INST_ADDR + 1) = 0x00200113u; // addi x2,x0,2
        tb.mem(INST_ADDR + 2) = 0x00108463u; // beq  x1,x1,+8
        tb.mem(INST_ADDR + 3) = 0x00900193u; // addi x3,x0,9 (flush)
        tb.mem(INST_ADDR + 4) = 0x00210463u; // beq  x2,x2,+8
        tb.mem(INST_ADDR + 5) = 0x00800213u; // addi x4,x0,8 (flush)
        tb.mem(INST_ADDR + 6) = 0x00700293u; // addi x5,x0,7

        tb.cpu_reset_sequence();

        tb.check_rf(++test_id, 3, 0u, "Corner 5 first redirect flush");
        tb.check_rf(++test_id, 4, 0u, "Corner 5 second redirect flush");
        tb.check_rf(++test_id, 5, 7u, "Corner 5 final target");

        // Corner 6: jal -> jalr redirect
        tb.reset_memories();
        INST_ADDR = 0;

        tb.mem(INST_ADDR + 0) = 0x008002efu; // jal   x5,+8
        tb.mem(INST_ADDR + 1) = 0x00900113u; // addi  x2,x0,9 (flush)
        tb.mem(INST_ADDR + 2) = 0x100000b7u; // lui   x1,0x10000
        tb.mem(INST_ADDR + 3) = 0x01808093u; // addi  x1,x1,24 -> 0x10000018
        tb.mem(INST_ADDR + 4) = 0x00008367u; // jalr  x6,x1,0
        tb.mem(INST_ADDR + 5) = 0x00800193u; // addi  x3,x0,8 (flush)
        tb.mem(INST_ADDR + 6) = 0x00700213u; // addi  x4,x0,7

        tb.cpu_reset_sequence();

        tb.check_rf(++test_id, 2, 0u,          "Corner 6 jal flush");
        tb.check_rf(++test_id, 3, 0u,          "Corner 6 jalr flush");
        tb.check_rf(++test_id, 4, 7u,          "Corner 6 final target");
        tb.check_rf(++test_id, 5, 0x10000004u, "Corner 6 jal link");
        tb.check_rf(++test_id, 6, 0x10000014u, "Corner 6 jalr link");

        // Corner 7: x0 false hazard
        tb.reset_memories();
        INST_ADDR = 0;

        tb.mem(INST_ADDR + 0) = 0x00500093u; // addi x1,x0,5
        tb.mem(INST_ADDR + 1) = 0x00708013u; // addi x0,x1,7
        tb.mem(INST_ADDR + 2) = 0x00100133u; // add  x2,x0,x1
        tb.mem(INST_ADDR + 3) = 0x00100463u; // beq  x0,x1,+8 (not taken)
        tb.mem(INST_ADDR + 4) = 0x00100193u; // addi x3,x0,1
        tb.mem(INST_ADDR + 5) = 0x00200213u; // addi x4,x0,2

        tb.cpu_reset_sequence();

        tb.check_rf(++test_id, 0, 0u, "Corner 7 x0 constant");
        tb.check_rf(++test_id, 2, 5u, "Corner 7 no false forward");
        tb.check_rf(++test_id, 3, 1u, "Corner 7 branch not taken path");
        tb.check_rf(++test_id, 4, 2u, "Corner 7 sequential commit");

        // Corner 8: mixed mini-program
        tb.reset_memories();
        INST_ADDR  = 0;
        DATA_ADDR0 = 0x10000080u >> 2;
        DATA_ADDR1 = DATA_ADDR0 + 1;

        tb.mem(INST_ADDR +  0) = 0x10000537u; // lui   x10,0x10000
        tb.mem(INST_ADDR +  1) = 0x08050513u; // addi  x10,x10,128
        tb.mem(INST_ADDR +  2) = 0x00500093u; // addi  x1,x0,5
        tb.mem(INST_ADDR +  3) = 0x00700113u; // addi  x2,x0,7
        tb.mem(INST_ADDR +  4) = 0x002081b3u; // add   x3,x1,x2
        tb.mem(INST_ADDR +  5) = 0x00352023u; // sw    x3,0(x10)
        tb.mem(INST_ADDR +  6) = 0x00050203u; // lb    x4,0(x10)
        tb.mem(INST_ADDR +  7) = 0x00054283u; // lbu   x5,0(x10)
        tb.mem(INST_ADDR +  8) = 0x00052303u; // lw    x6,0(x10)
        tb.mem(INST_ADDR +  9) = 0x001303b3u; // add   x7,x6,x1
        tb.mem(INST_ADDR + 10) = 0x00038463u; // beq   x7,x0,+8 (not taken)
        tb.mem(INST_ADDR + 11) = 0x00100413u; // addi  x8,x0,1
        tb.mem(INST_ADDR + 12) = 0x008004efu; // jal   x9,+8
        tb.mem(INST_ADDR + 13) = 0x00840413u; // addi  x8,x8,8 (flush)
        tb.mem(INST_ADDR + 14) = 0x00240413u; // addi  x8,x8,2
        tb.mem(INST_ADDR + 15) = 0x00052583u; // lw    x11,0(x10)
        tb.mem(INST_ADDR + 16) = 0x00358463u; // beq   x11,x3,+8
        tb.mem(INST_ADDR + 17) = 0x00900613u; // addi  x12,x0,9 (flush)
        tb.mem(INST_ADDR + 18) = 0x100006b7u; // lui   x13,0x10000
        tb.mem(INST_ADDR + 19) = 0x06068693u; // addi  x13,x13,96
        tb.mem(INST_ADDR + 20) = 0x00068767u; // jalr  x14,x13,0
        tb.mem(INST_ADDR + 21) = 0x00400793u; // addi  x15,x0,4 (flush)
        tb.mem(INST_ADDR + 22) = 0x00000013u; // nop
        tb.mem(INST_ADDR + 23) = 0x00000013u; // nop
        tb.mem(INST_ADDR + 24) = 0x00b00813u; // addi  x16,x0,11   @ 0x60
        tb.mem(INST_ADDR + 25) = 0x01052223u; // sw    x16,4(x10)
        tb.mem(INST_ADDR + 26) = 0x00451883u; // lh    x17,4(x10)
        tb.mem(INST_ADDR + 27) = 0x00455903u; // lhu   x18,4(x10)

        tb.cpu_reset_sequence();

        tb.check_mem(++test_id, DATA_ADDR0, 12u,         "Corner 8 mem[base+0]");
        tb.check_mem(++test_id, DATA_ADDR1, 11u,         "Corner 8 mem[base+4]");
        tb.check_rf (++test_id, 4,  12u,                 "Corner 8 lb");
        tb.check_rf (++test_id, 5,  12u,                 "Corner 8 lbu");
        tb.check_rf (++test_id, 6,  12u,                 "Corner 8 lw");
        tb.check_rf (++test_id, 7,  17u,                 "Corner 8 alu after lw");
        tb.check_rf (++test_id, 8,  3u,                  "Corner 8 jal path");
        tb.check_rf (++test_id, 9,  0x10000034u,         "Corner 8 jal link");
        tb.check_rf (++test_id, 11, 12u,                 "Corner 8 reload");
        tb.check_rf (++test_id, 12, 0u,                  "Corner 8 beq flush");
        tb.check_rf (++test_id, 14, 0x10000054u,         "Corner 8 jalr link");
        tb.check_rf (++test_id, 15, 0u,                  "Corner 8 jalr flush");
        tb.check_rf (++test_id, 16, 11u,                 "Corner 8 target result");
        tb.check_rf (++test_id, 17, 11u,                 "Corner 8 lh");
        tb.check_rf (++test_id, 18, 11u,                 "Corner 8 lhu");

        std::cout << "All tests passed!\n";
        return 0;
    } catch (...) {
        return 1;
    }
}
