package river_pkg;

    localparam int unsigned PRED_REG_SIZE          =  128;
    localparam int unsigned RET_PRED_REG_SIZE      =  16;
    localparam int unsigned PRED_POINTER_SIZE      =  7;
    localparam int unsigned RET_PRED_POINTER_SIZE  =  4;
    localparam int unsigned RET_STACK_SIZE         =  16;

    localparam logic [31:0] kernel_adr  = 32'hF0000000; 

    localparam logic zero_ext_pred_size[PRED_POINTER_SIZE]    = 0;
    localparam logic zero_ext_ret_size[RET_PRED_POINTER_SIZE] = 0;
    localparam logic zero_ret_stack_size[RET_STACK_SIZE]      = 0;
    
endpackage