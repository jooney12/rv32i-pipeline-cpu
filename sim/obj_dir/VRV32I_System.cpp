// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VRV32I_System__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

VRV32I_System::VRV32I_System(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VRV32I_System__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , MemWrite{vlSymsp->TOP.MemWrite}
    , ByteEnable{vlSymsp->TOP.ByteEnable}
    , pc{vlSymsp->TOP.pc}
    , MemAddr{vlSymsp->TOP.MemAddr}
    , MemWData{vlSymsp->TOP.MemWData}
    , inst_dbg{vlSymsp->TOP.inst_dbg}
    , data_r_dbg{vlSymsp->TOP.data_r_dbg}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VRV32I_System::VRV32I_System(const char* _vcname__)
    : VRV32I_System(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VRV32I_System::~VRV32I_System() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VRV32I_System___024root___eval_debug_assertions(VRV32I_System___024root* vlSelf);
#endif  // VL_DEBUG
void VRV32I_System___024root___eval_static(VRV32I_System___024root* vlSelf);
void VRV32I_System___024root___eval_initial(VRV32I_System___024root* vlSelf);
void VRV32I_System___024root___eval_settle(VRV32I_System___024root* vlSelf);
void VRV32I_System___024root___eval(VRV32I_System___024root* vlSelf);

void VRV32I_System::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VRV32I_System::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VRV32I_System___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VRV32I_System___024root___eval_static(&(vlSymsp->TOP));
        VRV32I_System___024root___eval_initial(&(vlSymsp->TOP));
        VRV32I_System___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VRV32I_System___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VRV32I_System::eventsPending() { return false; }

uint64_t VRV32I_System::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VRV32I_System::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VRV32I_System___024root___eval_final(VRV32I_System___024root* vlSelf);

VL_ATTR_COLD void VRV32I_System::final() {
    VRV32I_System___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VRV32I_System::hierName() const { return vlSymsp->name(); }
const char* VRV32I_System::modelName() const { return "VRV32I_System"; }
unsigned VRV32I_System::threads() const { return 1; }
void VRV32I_System::prepareClone() const { contextp()->prepareClone(); }
void VRV32I_System::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VRV32I_System::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VRV32I_System___024root__trace_decl_types(VerilatedFst* tracep);

void VRV32I_System___024root__trace_init_top(VRV32I_System___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    VRV32I_System___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRV32I_System___024root*>(voidSelf);
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    VRV32I_System___024root__trace_decl_types(tracep);
    VRV32I_System___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VRV32I_System___024root__trace_register(VRV32I_System___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void VRV32I_System::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VRV32I_System::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP), name(), false, 179);
    VRV32I_System___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
