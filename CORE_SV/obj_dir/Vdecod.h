// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VDECOD_H_
#define _VDECOD_H_  // guard

#include "verilated.h"

//==========

class Vdecod__Syms;

//----------

VL_MODULE(Vdecod) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset_n,0,0);
    VL_OUT8(REG_ADR1_SD,5,0);
    VL_OUT8(REG_ADR2_SD,5,0);
    VL_OUT8(WRITE_PC_ENABLE_SD,0,0);
    VL_OUT8(CMD_RD,1,0);
    VL_OUT8(NEG_OP2_RD,0,0);
    VL_OUT8(WB_RD,0,0);
    VL_OUT8(DEST_RD,5,0);
    VL_OUT8(SELECT_OPERATION_RD,3,0);
    VL_OUT8(SLT_RD,0,0);
    VL_OUT8(SLTU_RD,0,0);
    VL_OUT8(MEM_LOAD_RD,0,0);
    VL_OUT8(MEM_STORE_RD,0,0);
    VL_OUT8(MEM_SIGN_EXTEND_RD,0,0);
    VL_OUT8(MEM_SIZE_RD,1,0);
    VL_OUT8(CSR_WENABLE_RD,0,0);
    VL_IN8(DEC2IF_POP_SI,0,0);
    VL_OUT8(DEC2IF_EMPTY_SD,0,0);
    VL_IN8(IF2DEC_EMPTY_SI,0,0);
    VL_OUT8(IF2DEC_POP_SD,0,0);
    VL_OUT8(IF2DEC_FLUSH_SD,0,0);
    VL_OUT8(PRED_FAILED_RD,0,0);
    VL_OUT8(PRED_SUCCESS_RD,0,0);
    VL_OUT8(BRANCH_INST_RD,0,0);
    VL_OUT8(PRED_TAKEN_SD,0,0);
    VL_OUT8(PUSH_ADR_RAS_RD,0,0);
    VL_OUT8(POP_ADR_RAS_RD,0,0);
    VL_OUT8(RET_INST_RD,0,0);
    VL_IN8(PRED_TAKEN_RI,0,0);
    VL_IN8(DEC2EXE_POP_SE,0,0);
    VL_OUT8(DEC2EXE_EMPTY_SD,0,0);
    VL_OUT8(MULT_INST_RD,0,0);
    VL_IN8(MULT_INST_RE,0,0);
    VL_IN8(MULT_INST_RM,0,0);
    VL_IN8(BP_DEST_RE,5,0);
    VL_IN8(BP_MEM_LOAD_RE,0,0);
    VL_IN8(BP_EXE2MEM_EMPTY_SE,0,0);
    VL_IN8(BP_MEM2WBK_EMPTY_SM,0,0);
    VL_IN8(BP_DEST_RM,5,0);
    VL_OUT8(BP_R1_VALID_RD,0,0);
    VL_OUT8(BP_R2_VALID_RD,0,0);
    VL_OUT8(BP_RADR1_RD,5,0);
    VL_OUT8(BP_RADR2_RD,5,0);
    VL_OUT8(BLOCK_BP_RD,0,0);
    VL_IN8(CSR_WENABLE_RE,0,0);
    VL_IN8(CSR_WENABLE_RM,0,0);
    VL_IN8(EXCEPTION_RI,0,0);
    VL_OUT8(ILLEGAL_INSTRUCTION_RD,0,0);
    VL_OUT8(ADRESS_MISALIGNED_RD,0,0);
    VL_OUT8(ENV_CALL_U_MODE_RD,0,0);
    VL_OUT8(ENV_CALL_M_MODE_RD,0,0);
    VL_OUT8(ENV_CALL_S_MODE_RD,0,0);
    VL_OUT8(ENV_CALL_WRONG_MODE_RD,0,0);
    VL_OUT8(INSTRUCTION_ACCESS_FAULT_RD,0,0);
    VL_OUT8(MRET_RD,0,0);
    VL_OUT8(EXCEPTION_RD,0,0);
    VL_OUT8(EBREAK_RD,0,0);
    VL_IN8(CURRENT_MODE_SM,1,0);
    VL_IN8(EXCEPTION_SM,0,0);
    VL_IN8(MRET_SM,0,0);
    VL_OUT16(CSR_WADR_RD,11,0);
    VL_OUT16(CSR_RADR_SD,11,0);
    VL_IN(RDATA1_SR,31,0);
    VL_IN(RDATA2_SR,31,0);
    VL_OUT(WRITE_PC_SD,31,0);
    VL_IN(READ_PC_SR,31,0);
    VL_OUT(OP1_RD,31,0);
    VL_OUT(OP2_RD,31,0);
    VL_OUT(MEM_DATA_RD,31,0);
    VL_OUT(PC_DEC2EXE_RD,31,0);
    VL_OUT(PC_BRANCH_VALUE_RD,31,0);
    VL_OUT(CSR_RDATA_RD,31,0);
    VL_OUT(PC_RD,31,0);
    VL_IN(INSTR_RI,31,0);
    VL_IN(PC_IF2DEC_RI,31,0);
    VL_OUT(BRANCH_INST_ADR_RD,31,0);
    VL_OUT(ADR_TO_BRANCH_RD,31,0);
    VL_OUT(PRED_ADR_SD,31,0);
    VL_OUT(ADR_TO_RET_RD,31,0);
    VL_IN(PRED_ADR_RI,31,0);
    VL_IN(BP_EXE_RES_RE,31,0);
    VL_IN(BP_MEM_RES_RM,31,0);
    VL_IN(CSR_RDATA_RE,31,0);
    VL_IN(CSR_RDATA_RM,31,0);
    VL_IN(CSR_RDATA_SC,31,0);
    VL_IN(MTVEC_VALUE_RC,31,0);
    VL_IN(MCAUSE_WDATA_SM,31,0);
    VL_IN(RETURN_ADRESS_SM,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ dec__DOT__reset_sync_sd;
        CData/*0:0*/ dec__DOT__dec2if_full_sd;
        CData/*0:0*/ dec__DOT__dec2if_push_sd;
        CData/*0:0*/ dec__DOT__i_type_sd;
        CData/*0:0*/ dec__DOT__u_type_sd;
        CData/*0:0*/ dec__DOT__m_type_sd;
        CData/*0:0*/ dec__DOT__sub_i_sd;
        CData/*0:0*/ dec__DOT__slt_i_sd;
        CData/*0:0*/ dec__DOT__sltu_i_sd;
        CData/*0:0*/ dec__DOT__and_i_sd;
        CData/*0:0*/ dec__DOT__or_i_sd;
        CData/*0:0*/ dec__DOT__xor_i_sd;
        CData/*0:0*/ dec__DOT__sll_i_sd;
        CData/*0:0*/ dec__DOT__srl_i_sd;
        CData/*0:0*/ dec__DOT__sra_i_sd;
        CData/*0:0*/ dec__DOT__slti_i_sd;
        CData/*0:0*/ dec__DOT__sltiu_i_sd;
        CData/*0:0*/ dec__DOT__andi_i_sd;
        CData/*0:0*/ dec__DOT__ori_i_sd;
        CData/*0:0*/ dec__DOT__xori_i_sd;
        CData/*0:0*/ dec__DOT__slli_i_sd;
        CData/*0:0*/ dec__DOT__srli_i_sd;
        CData/*0:0*/ dec__DOT__srai_i_sd;
        CData/*0:0*/ dec__DOT__lw_i_sd;
        CData/*0:0*/ dec__DOT__lh_i_sd;
        CData/*0:0*/ dec__DOT__lhu_i_sd;
        CData/*0:0*/ dec__DOT__lb_i_sd;
        CData/*0:0*/ dec__DOT__lbu_i_sd;
        CData/*0:0*/ dec__DOT__sw_i_sd;
        CData/*0:0*/ dec__DOT__sh_i_sd;
        CData/*0:0*/ dec__DOT__sb_i_sd;
        CData/*0:0*/ dec__DOT__beq_i_sd;
        CData/*0:0*/ dec__DOT__bne_i_sd;
        CData/*0:0*/ dec__DOT__blt_i_sd;
        CData/*0:0*/ dec__DOT__bge_i_sd;
        CData/*0:0*/ dec__DOT__bltu_i_sd;
        CData/*0:0*/ dec__DOT__bgeu_i_sd;
        CData/*0:0*/ dec__DOT__mul_i_sd;
        CData/*0:0*/ dec__DOT__mulh_i_sd;
        CData/*0:0*/ dec__DOT__mulhsu_i_sd;
        CData/*0:0*/ dec__DOT__mulhu_i_sd;
        CData/*0:0*/ dec__DOT__div_i_sd;
        CData/*0:0*/ dec__DOT__divu_i_sd;
        CData/*0:0*/ dec__DOT__rem_i_sd;
        CData/*0:0*/ dec__DOT__ecall_i_sd;
        CData/*0:0*/ dec__DOT__ebreak_i_sd;
        CData/*0:0*/ dec__DOT__csrrw_i_sd;
        CData/*0:0*/ dec__DOT__csrrs_i_sd;
        CData/*0:0*/ dec__DOT__csrrc_i_sd;
        CData/*0:0*/ dec__DOT__csrrwi_i_sd;
        CData/*0:0*/ dec__DOT__csrrsi_i_sd;
        CData/*0:0*/ dec__DOT__csrrci_i_sd;
        CData/*0:0*/ dec__DOT__env_call_u_mode_sd;
        CData/*0:0*/ dec__DOT__env_call_s_mode_sd;
        CData/*0:0*/ dec__DOT__env_call_m_mode_sd;
        CData/*0:0*/ dec__DOT__env_call_wrong_mode;
        CData/*0:0*/ dec__DOT__illegal_inst;
        CData/*0:0*/ dec__DOT__illegal_inst_sd;
        CData/*0:0*/ dec__DOT__instruction_access_fault_sd;
        CData/*0:0*/ dec__DOT__instruction_adress_misaligned_sd;
        CData/*5:0*/ dec__DOT__radr1_sd;
        CData/*5:0*/ dec__DOT__radr2_sd;
        CData/*5:0*/ dec__DOT__rdest_sd;
        CData/*3:0*/ dec__DOT__select_operation_sd;
    };
    struct {
        CData/*0:0*/ dec__DOT__jump_sd;
        CData/*0:0*/ dec__DOT__different_sign;
        CData/*0:0*/ dec__DOT__add_offset_to_pc;
        CData/*0:0*/ dec__DOT__rd_link;
        CData/*0:0*/ dec__DOT__rs1_link;
        CData/*0:0*/ dec__DOT__pred_failed_sd;
        CData/*0:0*/ dec__DOT__stall_sd;
        CData/*0:0*/ dec__DOT__r1_valid_sd;
        CData/*0:0*/ dec__DOT__r2_valid_sd;
        CData/*0:0*/ dec__DOT__bpc_ed1;
        CData/*0:0*/ dec__DOT__bpc_md1;
        CData/*0:0*/ dec__DOT__bpc_ed2;
        CData/*0:0*/ dec__DOT__bpc_md2;
        CData/*0:0*/ dec__DOT__dec2if__DOT__data_v;
        CData/*0:0*/ dec__DOT__dec2exe__DOT__data_v;
        SData/*11:0*/ dec__DOT__csr_radr;
        WData/*133:0*/ dec__DOT__dec2if_din[5];
        WData/*251:0*/ dec__DOT__dec2exe_din[8];
        WData/*251:0*/ dec__DOT__dec2exe_data[8];
        WData/*251:0*/ dec__DOT__dec2exe_x[8];
        IData/*31:0*/ dec__DOT__op1_csri_type_sd;
        IData/*31:0*/ dec__DOT__mtvec_value;
        IData/*31:0*/ dec__DOT__mcause_val;
        IData/*31:0*/ dec__DOT__dec2exe_op1_sd;
        IData/*31:0*/ dec__DOT__dec2exe_op2_sd;
        IData/*31:0*/ dec__DOT__op1_u_type_sd;
        IData/*31:0*/ dec__DOT__op2_i_type_sd;
        IData/*31:0*/ dec__DOT__op2_s_type_sd;
        IData/*31:0*/ dec__DOT__rdata1_sd;
        IData/*31:0*/ dec__DOT__rdata2_sd;
        IData/*31:0*/ dec__DOT__offset_branch_sd;
        IData/*31:0*/ dec__DOT__offset_branch_j;
        IData/*31:0*/ dec__DOT__offset_branch_jalr;
        IData/*31:0*/ dec__DOT__jalr_offset;
        IData/*31:0*/ dec__DOT__offset_branch_b;
        IData/*31:0*/ dec__DOT__res;
        IData/*31:0*/ dec__DOT__res_compare;
        IData/*31:0*/ dec__DOT__pc;
        IData/*31:0*/ dec__DOT__new_pc;
        IData/*31:0*/ dec__DOT__branch_adr_sd;
        WData/*133:0*/ dec__DOT__dec2if__DOT__data[5];
        WData/*251:0*/ dec__DOT__dec2exe__DOT__data[8];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset_n;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vdecod__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vdecod);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vdecod(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vdecod();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vdecod__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vdecod__Syms* symsp, bool first);
  private:
    static QData _change_request(Vdecod__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vdecod__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(Vdecod__Syms* __restrict vlSymsp);
    static void _combo__TOP__6(Vdecod__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vdecod__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vdecod__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vdecod__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vdecod__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__4(Vdecod__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vdecod__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vdecod__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
