package river;

    localparam int unsigned PRED_REG_SIZE          =  128;
    localparam int unsigned RET_PRED_REG_SIZE      =  16;
    localparam int unsigned PRED_POINTER_SIZE      =  7;
    localparam int unsigned RET_PRED_POINTER_SIZE  =  4;
    localparam int unsigned RET_STACK_SIZE         =  16;

    localparam logic kernel_adr [32] ; 
    localparam logic one_ext_32 [32] ;

    localparam logic zero_ext_pred_size[PRED_POINTER_SIZE]    ;
    localparam logic zero_ext_ret_size[RET_PRED_POINTER_SIZE] ;
    localparam logic zero_ret_stack_size[RET_STACK_SIZE]      ;
    
    localparam logic one_ext_pred_size      [PRED_POINTER_SIZE];
    localparam logic one_ext_ret_size       [RET_PRED_POINTER_SIZE];
    localparam logic one_ext_ret_stack_size [RET_STACK_SIZE]; 
    

    typedef logic [63:0] tab_32_t [0:31];
    typedef logic [63:0] tab_20_t [0:19];
    typedef logic [63:0] tab_14_t [0:13];
    typedef logic [63:0] tab_10_t [0:9];
    typedef logic [63:0] tab_6_t [0:5];
    typedef logic [63:0] tab_5_t [0:5];
    typedef logic [63:0] tab_4_t [0:3];
    typedef logic [63:0] tab_2_t [0:1];
endpackage