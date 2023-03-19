
my.elf:     file format elf32-littleriscv


Disassembly of section .text.init:

80000000 <rvtest_entry_point>:
80000000:	00002317          	auipc	t1,0x2
80000004:	20030313          	addi	t1,t1,512 # 80002200 <Mtrapreg_sv>

80000008 <init_Mscratch>:
80000008:	34031e73          	csrrw	t3,mscratch,t1
8000000c:	ffc32c23          	sw	t3,-8(t1)

80000010 <init_Medeleg>:
80000010:	00000393          	li	t2,0
80000014:	fe732023          	sw	t2,-32(t1)

80000018 <init_Msatp>:
80000018:	00000e97          	auipc	t4,0x0
8000001c:	1a8e8e93          	addi	t4,t4,424 # 800001c0 <Mtrampoline>
80000020:	30502e73          	csrr	t3,mtvec
80000024:	ffc32823          	sw	t3,-16(t1)
80000028:	003e7393          	andi	t2,t3,3
8000002c:	007ee3b3          	or	t2,t4,t2
80000030:	fe732423          	sw	t2,-24(t1)
80000034:	30539073          	csrw	mtvec,t2
80000038:	30502f73          	csrr	t5,mtvec
8000003c:	067f0063          	beq	t5,t2,8000009c <rvtest_Mprolog_done>
80000040:	305e1073          	csrw	mtvec,t3
80000044:	040e0663          	beqz	t3,80000090 <abortMtest>
80000048:	ffc32423          	sw	t3,-24(t1)

8000004c <init_Mtramp>:
8000004c:	ffce7393          	andi	t2,t3,-4
80000050:	18438e13          	addi	t3,t2,388
80000054:	e4430313          	addi	t1,t1,-444

80000058 <overwt_tt_Mloop>:
80000058:	0003af83          	lw	t6,0(t2)
8000005c:	01f32023          	sw	t6,0(t1)
80000060:	000eaf03          	lw	t5,0(t4)
80000064:	01e3a023          	sw	t5,0(t2)
80000068:	0003af83          	lw	t6,0(t2)
8000006c:	01ef9a63          	bne	t6,t5,80000080 <endcopy_Mtramp>
80000070:	00438393          	addi	t2,t2,4
80000074:	00430313          	addi	t1,t1,4
80000078:	004e8e93          	addi	t4,t4,4
8000007c:	fc7e1ee3          	bne	t3,t2,80000058 <overwt_tt_Mloop>

80000080 <endcopy_Mtramp>:
80000080:	0000100f          	fence.i
80000084:	34002373          	csrr	t1,mscratch
80000088:	fc732c23          	sw	t2,-40(t1)
8000008c:	007e0863          	beq	t3,t2,8000009c <rvtest_Mprolog_done>

80000090 <abortMtest>:
80000090:	00000f97          	auipc	t6,0x0
80000094:	0b8f8f93          	addi	t6,t6,184 # 80000148 <cleanup_epilogs>
80000098:	000f8067          	jr	t6

8000009c <rvtest_Mprolog_done>:
8000009c:	feedc0b7          	lui	ra,0xfeedc
800000a0:	ead08093          	addi	ra,ra,-339 # feedbead <edge2+0xfeedbeae>
800000a4:	ff76e137          	lui	sp,0xff76e
800000a8:	f5610113          	addi	sp,sp,-170 # ff76df56 <edge2+0xff76df57>
800000ac:	7fbb71b7          	lui	gp,0x7fbb7
800000b0:	fab18193          	addi	gp,gp,-85 # 7fbb6fab <CSR_XIP+0x7fbb6c67>
800000b4:	bfddb237          	lui	tp,0xbfddb
800000b8:	7d520213          	addi	tp,tp,2005 # bfddb7d5 <edge2+0xbfddb7d6>
800000bc:	00000297          	auipc	t0,0x0
800000c0:	05828293          	addi	t0,t0,88 # 80000114 <rvtest_code_begin>
800000c4:	00002317          	auipc	t1,0x2
800000c8:	15c30313          	addi	t1,t1,348 # 80002220 <rvtest_data_begin>
800000cc:	b7fbb3b7          	lui	t2,0xb7fbb
800000d0:	6fa38393          	addi	t2,t2,1786 # b7fbb6fa <edge2+0xb7fbb6fb>
800000d4:	5bfde437          	lui	s0,0x5bfde
800000d8:	b7d40413          	addi	s0,s0,-1155 # 5bfddb7d <CSR_XIP+0x5bfdd839>
800000dc:	adfef4b7          	lui	s1,0xadfef
800000e0:	dbe48493          	addi	s1,s1,-578 # adfeedbe <edge2+0xadfeedbf>
800000e4:	56ff7537          	lui	a0,0x56ff7
800000e8:	6df50513          	addi	a0,a0,1759 # 56ff76df <CSR_XIP+0x56ff739b>
800000ec:	ab7fc5b7          	lui	a1,0xab7fc
800000f0:	b6f58593          	addi	a1,a1,-1169 # ab7fbb6f <edge2+0xab7fbb70>
800000f4:	d5bfe637          	lui	a2,0xd5bfe
800000f8:	db760613          	addi	a2,a2,-585 # d5bfddb7 <edge2+0xd5bfddb8>
800000fc:	eadff6b7          	lui	a3,0xeadff
80000100:	edb68693          	addi	a3,a3,-293 # eadfeedb <edge2+0xeadfeedc>
80000104:	f56ff737          	lui	a4,0xf56ff
80000108:	76d70713          	addi	a4,a4,1901 # f56ff76d <edge2+0xf56ff76e>
8000010c:	fab807b7          	lui	a5,0xfab80
80000110:	bb678793          	addi	a5,a5,-1098 # fab7fbb6 <edge2+0xfab7fbb7>

80000114 <rvtest_code_begin>:
80000114:	00003097          	auipc	ra,0x3
80000118:	00008093          	mv	ra,ra
8000011c:	11111137          	lui	sp,0x11111
80000120:	11110113          	addi	sp,sp,273 # 11111111 <CSR_XIP+0x11110dcd>
80000124:	00000073          	ecall
80000128:	00000013          	nop
8000012c:	00000013          	nop
80000130:	0000a023          	sw	zero,0(ra) # 80003114 <test_A_res>
80000134:	0020a223          	sw	sp,4(ra)

80000138 <rvtest_code_end>:
80000138:	0000100f          	fence.i
8000013c:	00000397          	auipc	t2,0x0
80000140:	30002ef3          	csrr	t4,mstatus
80000144:	0000100f          	fence.i

80000148 <cleanup_epilogs>:
80000148:	34002373          	csrr	t1,mscratch

8000014c <resto_Medeleg>:
8000014c:	fe032383          	lw	t2,-32(t1)

80000150 <resto_Mscratch>:
80000150:	ff832f03          	lw	t5,-8(t1)
80000154:	340f1073          	csrw	mscratch,t5

80000158 <resto_Mxtvec>:
80000158:	ff032e83          	lw	t4,-16(t1)
8000015c:	305e93f3          	csrrw	t2,mtvec,t4
80000160:	ffcefe93          	andi	t4,t4,-4
80000164:	ffc3f393          	andi	t2,t2,-4
80000168:	027e9063          	bne	t4,t2,80000188 <rvtest_Mend>

8000016c <resto_Mtramp>:
8000016c:	e4430e93          	addi	t4,t1,-444
80000170:	fd832e03          	lw	t3,-40(t1)

80000174 <resto_Mloop>:
80000174:	000eaf83          	lw	t6,0(t4)
80000178:	01f3a023          	sw	t6,0(t2) # 8000013c <rvtest_code_end+0x4>
8000017c:	00438393          	addi	t2,t2,4
80000180:	004e8e93          	addi	t4,t4,4
80000184:	ffc3c8e3          	blt	t2,t3,80000174 <resto_Mloop>

80000188 <rvtest_Mend>:
80000188:	58c0006f          	j	80000714 <exit_cleanup>
8000018c:	00000013          	nop
80000190:	00000013          	nop
80000194:	00000013          	nop
80000198:	00000013          	nop
8000019c:	00000013          	nop
800001a0:	00000013          	nop
800001a4:	00000013          	nop
800001a8:	00000013          	nop
800001ac:	00000013          	nop
800001b0:	00000013          	nop
800001b4:	00000013          	nop
800001b8:	00000013          	nop
800001bc:	00000013          	nop

800001c0 <Mtrampoline>:
800001c0:	0800006f          	j	80000240 <trap_Mhandler>
800001c4:	0880006f          	j	8000024c <trap_Mhandler+0xc>
800001c8:	0900006f          	j	80000258 <trap_Mhandler+0x18>
800001cc:	0980006f          	j	80000264 <trap_Mhandler+0x24>
800001d0:	0a00006f          	j	80000270 <trap_Mhandler+0x30>
800001d4:	0a80006f          	j	8000027c <trap_Mhandler+0x3c>
800001d8:	0b00006f          	j	80000288 <trap_Mhandler+0x48>
800001dc:	0b80006f          	j	80000294 <trap_Mhandler+0x54>
800001e0:	0c00006f          	j	800002a0 <trap_Mhandler+0x60>
800001e4:	0c80006f          	j	800002ac <trap_Mhandler+0x6c>
800001e8:	0d00006f          	j	800002b8 <trap_Mhandler+0x78>
800001ec:	0d80006f          	j	800002c4 <trap_Mhandler+0x84>
800001f0:	0e00006f          	j	800002d0 <trap_Mhandler+0x90>
800001f4:	0e80006f          	j	800002dc <trap_Mhandler+0x9c>
800001f8:	0f00006f          	j	800002e8 <trap_Mhandler+0xa8>
800001fc:	0f80006f          	j	800002f4 <trap_Mhandler+0xb4>
80000200:	1000006f          	j	80000300 <rvtest_Mendtest>
80000204:	0fc0006f          	j	80000300 <rvtest_Mendtest>
80000208:	0f80006f          	j	80000300 <rvtest_Mendtest>
8000020c:	0f40006f          	j	80000300 <rvtest_Mendtest>
80000210:	0f00006f          	j	80000300 <rvtest_Mendtest>
80000214:	0ec0006f          	j	80000300 <rvtest_Mendtest>
80000218:	0e80006f          	j	80000300 <rvtest_Mendtest>
8000021c:	0e40006f          	j	80000300 <rvtest_Mendtest>
80000220:	0e00006f          	j	80000300 <rvtest_Mendtest>
80000224:	0dc0006f          	j	80000300 <rvtest_Mendtest>
80000228:	0d80006f          	j	80000300 <rvtest_Mendtest>
8000022c:	0d40006f          	j	80000300 <rvtest_Mendtest>
80000230:	0d00006f          	j	80000300 <rvtest_Mendtest>
80000234:	0cc0006f          	j	80000300 <rvtest_Mendtest>
80000238:	0c80006f          	j	80000300 <rvtest_Mendtest>
8000023c:	0c40006f          	j	80000300 <rvtest_Mendtest>

80000240 <trap_Mhandler>:
80000240:	34011173          	csrrw	sp,mscratch,sp
80000244:	01f12c23          	sw	t6,24(sp)
80000248:	0c400fef          	jal	t6,8000030c <common_Mhandler>
8000024c:	34011173          	csrrw	sp,mscratch,sp
80000250:	01f12c23          	sw	t6,24(sp)
80000254:	0b800fef          	jal	t6,8000030c <common_Mhandler>
80000258:	34011173          	csrrw	sp,mscratch,sp
8000025c:	01f12c23          	sw	t6,24(sp)
80000260:	0ac00fef          	jal	t6,8000030c <common_Mhandler>
80000264:	34011173          	csrrw	sp,mscratch,sp
80000268:	01f12c23          	sw	t6,24(sp)
8000026c:	0a000fef          	jal	t6,8000030c <common_Mhandler>
80000270:	34011173          	csrrw	sp,mscratch,sp
80000274:	01f12c23          	sw	t6,24(sp)
80000278:	09400fef          	jal	t6,8000030c <common_Mhandler>
8000027c:	34011173          	csrrw	sp,mscratch,sp
80000280:	01f12c23          	sw	t6,24(sp)
80000284:	08800fef          	jal	t6,8000030c <common_Mhandler>
80000288:	34011173          	csrrw	sp,mscratch,sp
8000028c:	01f12c23          	sw	t6,24(sp)
80000290:	07c00fef          	jal	t6,8000030c <common_Mhandler>
80000294:	34011173          	csrrw	sp,mscratch,sp
80000298:	01f12c23          	sw	t6,24(sp)
8000029c:	07000fef          	jal	t6,8000030c <common_Mhandler>
800002a0:	34011173          	csrrw	sp,mscratch,sp
800002a4:	01f12c23          	sw	t6,24(sp)
800002a8:	06400fef          	jal	t6,8000030c <common_Mhandler>
800002ac:	34011173          	csrrw	sp,mscratch,sp
800002b0:	01f12c23          	sw	t6,24(sp)
800002b4:	05800fef          	jal	t6,8000030c <common_Mhandler>
800002b8:	34011173          	csrrw	sp,mscratch,sp
800002bc:	01f12c23          	sw	t6,24(sp)
800002c0:	04c00fef          	jal	t6,8000030c <common_Mhandler>
800002c4:	34011173          	csrrw	sp,mscratch,sp
800002c8:	01f12c23          	sw	t6,24(sp)
800002cc:	04000fef          	jal	t6,8000030c <common_Mhandler>
800002d0:	34011173          	csrrw	sp,mscratch,sp
800002d4:	01f12c23          	sw	t6,24(sp)
800002d8:	03400fef          	jal	t6,8000030c <common_Mhandler>
800002dc:	34011173          	csrrw	sp,mscratch,sp
800002e0:	01f12c23          	sw	t6,24(sp)
800002e4:	02800fef          	jal	t6,8000030c <common_Mhandler>
800002e8:	34011173          	csrrw	sp,mscratch,sp
800002ec:	01f12c23          	sw	t6,24(sp)
800002f0:	01c00fef          	jal	t6,8000030c <common_Mhandler>
800002f4:	34011173          	csrrw	sp,mscratch,sp
800002f8:	01f12c23          	sw	t6,24(sp)
800002fc:	01000fef          	jal	t6,8000030c <common_Mhandler>

80000300 <rvtest_Mendtest>:
80000300:	00000317          	auipc	t1,0x0
80000304:	e8830313          	addi	t1,t1,-376 # 80000188 <rvtest_Mend>
80000308:	00030067          	jr	t1

8000030c <common_Mhandler>:
8000030c:	01e12a23          	sw	t5,20(sp)
80000310:	34011f73          	csrrw	t5,mscratch,sp
80000314:	01e12e23          	sw	t5,28(sp)
80000318:	00000f17          	auipc	t5,0x0
8000031c:	00cf0f13          	addi	t5,t5,12 # 80000324 <common_Mentry>
80000320:	000f0067          	jr	t5

80000324 <common_Mentry>:
80000324:	01d12823          	sw	t4,16(sp)
80000328:	01c12623          	sw	t3,12(sp)
8000032c:	00712423          	sw	t2,8(sp)
80000330:	00612223          	sw	t1,4(sp)

80000334 <Mtrapsig_ptr_upd>:
80000334:	01000393          	li	t2,16
80000338:	34202f73          	csrr	t5,mcause
8000033c:	000f5c63          	bgez	t5,80000354 <Mxcpt_sig_sv>

80000340 <Mint_sig_sv>:
80000340:	001f1e13          	slli	t3,t5,0x1
80000344:	ff2e0e13          	addi	t3,t3,-14
80000348:	000e5e63          	bgez	t3,80000364 <Mtrap_sig_sv>
8000034c:	00c00393          	li	t2,12
80000350:	0140006f          	j	80000364 <Mtrap_sig_sv>

80000354 <Mxcpt_sig_sv>:
80000354:	30102373          	csrr	t1,misa
80000358:	01831313          	slli	t1,t1,0x18
8000035c:	00035463          	bgez	t1,80000364 <Mtrap_sig_sv>
80000360:	01800393          	li	t2,24

80000364 <Mtrap_sig_sv>:
80000364:	00002e17          	auipc	t3,0x2
80000368:	c9ce0e13          	addi	t3,t3,-868 # 80002000 <rvtest_trap_sig>
8000036c:	000e2303          	lw	t1,0(t3)
80000370:	00730eb3          	add	t4,t1,t2
80000374:	01de2023          	sw	t4,0(t3)
80000378:	fe812e03          	lw	t3,-24(sp)

8000037c <sv_Mvect>:
8000037c:	41cf8fb3          	sub	t6,t6,t3
80000380:	004f9f93          	slli	t6,t6,0x4
80000384:	007fefb3          	or	t6,t6,t2
80000388:	003f8f93          	addi	t6,t6,3
8000038c:	01f32023          	sw	t6,0(t1)

80000390 <sv_Mcause>:
80000390:	01e32223          	sw	t5,4(t1)
80000394:	0e0f4c63          	bltz	t5,8000048c <common_Mint_handler>

80000398 <common_Mexcpt_handler>:
80000398:	00ff7f13          	andi	t5,t5,15
8000039c:	341023f3          	csrr	t2,mepc

800003a0 <code_adj_Mepc>:
800003a0:	00000e17          	auipc	t3,0x0
800003a4:	d74e0e13          	addi	t3,t3,-652 # 80000114 <rvtest_code_begin>
800003a8:	00000f97          	auipc	t6,0x0
800003ac:	d90f8f93          	addi	t6,t6,-624 # 80000138 <rvtest_code_end>
800003b0:	01f3f463          	bgeu	t2,t6,800003b8 <data_adj_Mepc>
800003b4:	01c3fe63          	bgeu	t2,t3,800003d0 <adj_Mepc>

800003b8 <data_adj_Mepc>:
800003b8:	00002e17          	auipc	t3,0x2
800003bc:	e68e0e13          	addi	t3,t3,-408 # 80002220 <rvtest_data_begin>
800003c0:	00002f97          	auipc	t6,0x2
800003c4:	e60f8f93          	addi	t6,t6,-416 # 80002220 <rvtest_data_begin>
800003c8:	d9f3f0e3          	bgeu	t2,t6,80000148 <cleanup_epilogs>
800003cc:	d7c3eee3          	bltu	t2,t3,80000148 <cleanup_epilogs>

800003d0 <adj_Mepc>:
800003d0:	41c38eb3          	sub	t4,t2,t3

800003d4 <sv_Mepc>:
800003d4:	01d32423          	sw	t4,8(t1)

800003d8 <adj_Mepc_rtn>:
800003d8:	ffc3ff93          	andi	t6,t2,-4
800003dc:	008f8f93          	addi	t6,t6,8
800003e0:	341f9073          	csrw	mepc,t6
800003e4:	34302ff3          	csrr	t6,mtval

800003e8 <chk_Mtval>:
800003e8:	0000beb7          	lui	t4,0xb
800003ec:	0fbe8e93          	addi	t4,t4,251 # b0fb <CSR_XIP+0xadb7>
800003f0:	01eedeb3          	srl	t4,t4,t5
800003f4:	01fe9e93          	slli	t4,t4,0x1f
800003f8:	040ed863          	bgez	t4,80000448 <sv_Mtval>

800003fc <sig_adj_Mtval>:
800003fc:	00003e17          	auipc	t3,0x3
80000400:	d14e0e13          	addi	t3,t3,-748 # 80003110 <begin_signature>
80000404:	00003f97          	auipc	t6,0x3
80000408:	d2cf8f93          	addi	t6,t6,-724 # 80003130 <_end>
8000040c:	01f3f463          	bgeu	t2,t6,80000414 <code_adj_Mtval>
80000410:	03c3fa63          	bgeu	t2,t3,80000444 <adj_Mtval>

80000414 <code_adj_Mtval>:
80000414:	00000e17          	auipc	t3,0x0
80000418:	d00e0e13          	addi	t3,t3,-768 # 80000114 <rvtest_code_begin>
8000041c:	00000f97          	auipc	t6,0x0
80000420:	d1cf8f93          	addi	t6,t6,-740 # 80000138 <rvtest_code_end>
80000424:	01f3f463          	bgeu	t2,t6,8000042c <data_adj_Mtval>
80000428:	01c3fe63          	bgeu	t2,t3,80000444 <adj_Mtval>

8000042c <data_adj_Mtval>:
8000042c:	00002e17          	auipc	t3,0x2
80000430:	df4e0e13          	addi	t3,t3,-524 # 80002220 <rvtest_data_begin>
80000434:	00002f97          	auipc	t6,0x2
80000438:	decf8f93          	addi	t6,t6,-532 # 80002220 <rvtest_data_begin>
8000043c:	d1f3f6e3          	bgeu	t2,t6,80000148 <cleanup_epilogs>
80000440:	d1c3e4e3          	bltu	t2,t3,80000148 <cleanup_epilogs>

80000444 <adj_Mtval>:
80000444:	41cf8fb3          	sub	t6,t6,t3

80000448 <sv_Mtval>:
80000448:	01f32623          	sw	t6,12(t1)

8000044c <chk_Mtrapsig_overrun>:
8000044c:	00002e17          	auipc	t3,0x2
80000450:	bb4e0e13          	addi	t3,t3,-1100 # 80002000 <rvtest_trap_sig>
80000454:	000e2e03          	lw	t3,0(t3)
80000458:	00003e97          	auipc	t4,0x3
8000045c:	cb8e8e93          	addi	t4,t4,-840 # 80003110 <begin_signature>
80000460:	cfde64e3          	bltu	t3,t4,80000148 <cleanup_epilogs>
80000464:	10000393          	li	t2,256
80000468:	0400006f          	j	800004a8 <spcl_Mhandler>

8000046c <resto_Mrtn>:
8000046c:	00412303          	lw	t1,4(sp)
80000470:	00812383          	lw	t2,8(sp)
80000474:	00c12e03          	lw	t3,12(sp)
80000478:	01012e83          	lw	t4,16(sp)
8000047c:	01412f03          	lw	t5,20(sp)
80000480:	01812f83          	lw	t6,24(sp)
80000484:	01c12103          	lw	sp,28(sp)
80000488:	30200073          	mret

8000048c <common_Mint_handler>:
8000048c:	00100e13          	li	t3,1
80000490:	00ff7393          	andi	t2,t5,15
80000494:	007e1e33          	sll	t3,t3,t2
80000498:	304e3ef3          	csrrc	t4,mie,t3
8000049c:	344e3ef3          	csrrc	t4,mip,t3

800004a0 <sv_Mip>:
800004a0:	01d32423          	sw	t4,8(t1)
800004a4:	00000393          	li	t2,0

800004a8 <spcl_Mhandler>:
800004a8:	00000e17          	auipc	t3,0x0
800004ac:	01ce0e13          	addi	t3,t3,28 # 800004c4 <clrint_Mtbl>
800004b0:	007e0e33          	add	t3,t3,t2
800004b4:	003f1393          	slli	t2,t5,0x3
800004b8:	007e0e33          	add	t3,t3,t2
800004bc:	000e2e03          	lw	t3,0(t3)

800004c0 <spcl_Mdispatch>:
800004c0:	000e0067          	jr	t3

800004c4 <clrint_Mtbl>:
800004c4:	046c                	addi	a1,sp,524
800004c6:	8000                	0x8000
800004c8:	0000                	unimp
800004ca:	0000                	unimp
800004cc:	0148                	addi	a0,sp,132
800004ce:	8000                	0x8000
800004d0:	0000                	unimp
800004d2:	0000                	unimp
800004d4:	0148                	addi	a0,sp,132
800004d6:	8000                	0x8000
800004d8:	0000                	unimp
800004da:	0000                	unimp
800004dc:	06c4                	addi	s1,sp,836
800004de:	8000                	0x8000
800004e0:	0000                	unimp
800004e2:	0000                	unimp
800004e4:	046c                	addi	a1,sp,524
800004e6:	8000                	0x8000
800004e8:	0000                	unimp
800004ea:	0000                	unimp
800004ec:	0148                	addi	a0,sp,132
800004ee:	8000                	0x8000
800004f0:	0000                	unimp
800004f2:	0000                	unimp
800004f4:	0148                	addi	a0,sp,132
800004f6:	8000                	0x8000
800004f8:	0000                	unimp
800004fa:	0000                	unimp
800004fc:	06d0                	addi	a2,sp,836
800004fe:	8000                	0x8000
80000500:	0000                	unimp
80000502:	0000                	unimp
80000504:	046c                	addi	a1,sp,524
80000506:	8000                	0x8000
80000508:	0000                	unimp
8000050a:	0000                	unimp
8000050c:	0148                	addi	a0,sp,132
8000050e:	8000                	0x8000
80000510:	0000                	unimp
80000512:	0000                	unimp
80000514:	0148                	addi	a0,sp,132
80000516:	8000                	0x8000
80000518:	0000                	unimp
8000051a:	0000                	unimp
8000051c:	06d4                	addi	a3,sp,836
8000051e:	8000                	0x8000
80000520:	0000                	unimp
80000522:	0000                	unimp
80000524:	046c                	addi	a1,sp,524
80000526:	8000                	0x8000
80000528:	0000                	unimp
8000052a:	0000                	unimp
8000052c:	046c                	addi	a1,sp,524
8000052e:	8000                	0x8000
80000530:	0000                	unimp
80000532:	0000                	unimp
80000534:	046c                	addi	a1,sp,524
80000536:	8000                	0x8000
80000538:	0000                	unimp
8000053a:	0000                	unimp
8000053c:	046c                	addi	a1,sp,524
8000053e:	8000                	0x8000
80000540:	0000                	unimp
80000542:	0000                	unimp
80000544:	0148                	addi	a0,sp,132
80000546:	8000                	0x8000
80000548:	0000                	unimp
8000054a:	0000                	unimp
8000054c:	0148                	addi	a0,sp,132
8000054e:	8000                	0x8000
80000550:	0000                	unimp
80000552:	0000                	unimp
80000554:	0148                	addi	a0,sp,132
80000556:	8000                	0x8000
80000558:	0000                	unimp
8000055a:	0000                	unimp
8000055c:	0148                	addi	a0,sp,132
8000055e:	8000                	0x8000
80000560:	0000                	unimp
80000562:	0000                	unimp
80000564:	0148                	addi	a0,sp,132
80000566:	8000                	0x8000
80000568:	0000                	unimp
8000056a:	0000                	unimp
8000056c:	0148                	addi	a0,sp,132
8000056e:	8000                	0x8000
80000570:	0000                	unimp
80000572:	0000                	unimp
80000574:	0148                	addi	a0,sp,132
80000576:	8000                	0x8000
80000578:	0000                	unimp
8000057a:	0000                	unimp
8000057c:	0148                	addi	a0,sp,132
8000057e:	8000                	0x8000
80000580:	0000                	unimp
80000582:	0000                	unimp
80000584:	0148                	addi	a0,sp,132
80000586:	8000                	0x8000
80000588:	0000                	unimp
8000058a:	0000                	unimp
8000058c:	0148                	addi	a0,sp,132
8000058e:	8000                	0x8000
80000590:	0000                	unimp
80000592:	0000                	unimp
80000594:	0148                	addi	a0,sp,132
80000596:	8000                	0x8000
80000598:	0000                	unimp
8000059a:	0000                	unimp
8000059c:	0148                	addi	a0,sp,132
8000059e:	8000                	0x8000
800005a0:	0000                	unimp
800005a2:	0000                	unimp
800005a4:	0148                	addi	a0,sp,132
800005a6:	8000                	0x8000
800005a8:	0000                	unimp
800005aa:	0000                	unimp
800005ac:	0148                	addi	a0,sp,132
800005ae:	8000                	0x8000
800005b0:	0000                	unimp
800005b2:	0000                	unimp
800005b4:	0148                	addi	a0,sp,132
800005b6:	8000                	0x8000
800005b8:	0000                	unimp
800005ba:	0000                	unimp
800005bc:	0148                	addi	a0,sp,132
800005be:	8000                	0x8000
800005c0:	0000                	unimp
	...

800005c4 <excpt_Mhndlr_tbl>:
800005c4:	046c                	addi	a1,sp,524
800005c6:	8000                	0x8000
800005c8:	0000                	unimp
800005ca:	0000                	unimp
800005cc:	046c                	addi	a1,sp,524
800005ce:	8000                	0x8000
800005d0:	0000                	unimp
800005d2:	0000                	unimp
800005d4:	046c                	addi	a1,sp,524
800005d6:	8000                	0x8000
800005d8:	0000                	unimp
800005da:	0000                	unimp
800005dc:	046c                	addi	a1,sp,524
800005de:	8000                	0x8000
800005e0:	0000                	unimp
800005e2:	0000                	unimp
800005e4:	046c                	addi	a1,sp,524
800005e6:	8000                	0x8000
800005e8:	0000                	unimp
800005ea:	0000                	unimp
800005ec:	046c                	addi	a1,sp,524
800005ee:	8000                	0x8000
800005f0:	0000                	unimp
800005f2:	0000                	unimp
800005f4:	046c                	addi	a1,sp,524
800005f6:	8000                	0x8000
800005f8:	0000                	unimp
800005fa:	0000                	unimp
800005fc:	046c                	addi	a1,sp,524
800005fe:	8000                	0x8000
80000600:	0000                	unimp
80000602:	0000                	unimp
80000604:	046c                	addi	a1,sp,524
80000606:	8000                	0x8000
80000608:	0000                	unimp
8000060a:	0000                	unimp
8000060c:	046c                	addi	a1,sp,524
8000060e:	8000                	0x8000
80000610:	0000                	unimp
80000612:	0000                	unimp
80000614:	046c                	addi	a1,sp,524
80000616:	8000                	0x8000
80000618:	0000                	unimp
8000061a:	0000                	unimp
8000061c:	046c                	addi	a1,sp,524
8000061e:	8000                	0x8000
80000620:	0000                	unimp
80000622:	0000                	unimp
80000624:	046c                	addi	a1,sp,524
80000626:	8000                	0x8000
80000628:	0000                	unimp
8000062a:	0000                	unimp
8000062c:	046c                	addi	a1,sp,524
8000062e:	8000                	0x8000
80000630:	0000                	unimp
80000632:	0000                	unimp
80000634:	046c                	addi	a1,sp,524
80000636:	8000                	0x8000
80000638:	0000                	unimp
8000063a:	0000                	unimp
8000063c:	046c                	addi	a1,sp,524
8000063e:	8000                	0x8000
80000640:	0000                	unimp
80000642:	0000                	unimp
80000644:	0148                	addi	a0,sp,132
80000646:	8000                	0x8000
80000648:	0000                	unimp
8000064a:	0000                	unimp
8000064c:	0148                	addi	a0,sp,132
8000064e:	8000                	0x8000
80000650:	0000                	unimp
80000652:	0000                	unimp
80000654:	0148                	addi	a0,sp,132
80000656:	8000                	0x8000
80000658:	0000                	unimp
8000065a:	0000                	unimp
8000065c:	0148                	addi	a0,sp,132
8000065e:	8000                	0x8000
80000660:	0000                	unimp
80000662:	0000                	unimp
80000664:	0148                	addi	a0,sp,132
80000666:	8000                	0x8000
80000668:	0000                	unimp
8000066a:	0000                	unimp
8000066c:	0148                	addi	a0,sp,132
8000066e:	8000                	0x8000
80000670:	0000                	unimp
80000672:	0000                	unimp
80000674:	0148                	addi	a0,sp,132
80000676:	8000                	0x8000
80000678:	0000                	unimp
8000067a:	0000                	unimp
8000067c:	0148                	addi	a0,sp,132
8000067e:	8000                	0x8000
80000680:	0000                	unimp
80000682:	0000                	unimp
80000684:	0148                	addi	a0,sp,132
80000686:	8000                	0x8000
80000688:	0000                	unimp
8000068a:	0000                	unimp
8000068c:	0148                	addi	a0,sp,132
8000068e:	8000                	0x8000
80000690:	0000                	unimp
80000692:	0000                	unimp
80000694:	0148                	addi	a0,sp,132
80000696:	8000                	0x8000
80000698:	0000                	unimp
8000069a:	0000                	unimp
8000069c:	0148                	addi	a0,sp,132
8000069e:	8000                	0x8000
800006a0:	0000                	unimp
800006a2:	0000                	unimp
800006a4:	0148                	addi	a0,sp,132
800006a6:	8000                	0x8000
800006a8:	0000                	unimp
800006aa:	0000                	unimp
800006ac:	0148                	addi	a0,sp,132
800006ae:	8000                	0x8000
800006b0:	0000                	unimp
800006b2:	0000                	unimp
800006b4:	0148                	addi	a0,sp,132
800006b6:	8000                	0x8000
800006b8:	0000                	unimp
800006ba:	0000                	unimp
800006bc:	0148                	addi	a0,sp,132
800006be:	8000                	0x8000
800006c0:	0000                	unimp
	...

800006c4 <Mclr_Msw_int>:
800006c4:	020003b7          	lui	t2,0x2000
800006c8:	0003a023          	sw	zero,0(t2) # 2000000 <CSR_XIP+0x1fffcbc>
800006cc:	da1ff06f          	j	8000046c <resto_Mrtn>

800006d0 <Mclr_Mtmr_int>:
800006d0:	d9dff06f          	j	8000046c <resto_Mrtn>

800006d4 <Mclr_Mext_int>:
800006d4:	01c32623          	sw	t3,12(t1)
800006d8:	d95ff06f          	j	8000046c <resto_Mrtn>

800006dc <Mclr_Ssw_int>:
800006dc:	a6dff06f          	j	80000148 <cleanup_epilogs>
800006e0:	d8dff06f          	j	8000046c <resto_Mrtn>

800006e4 <Mclr_Stmr_int>:
800006e4:	a65ff06f          	j	80000148 <cleanup_epilogs>
800006e8:	d85ff06f          	j	8000046c <resto_Mrtn>

800006ec <Mclr_Sext_int>:
800006ec:	a5dff06f          	j	80000148 <cleanup_epilogs>
800006f0:	01c32623          	sw	t3,12(t1)
800006f4:	d79ff06f          	j	8000046c <resto_Mrtn>

800006f8 <Mclr_Vsw_int>:
800006f8:	a51ff06f          	j	80000148 <cleanup_epilogs>
800006fc:	d71ff06f          	j	8000046c <resto_Mrtn>

80000700 <Mclr_Vtmr_int>:
80000700:	a49ff06f          	j	80000148 <cleanup_epilogs>
80000704:	d69ff06f          	j	8000046c <resto_Mrtn>

80000708 <Mclr_Vext_int>:
80000708:	a41ff06f          	j	80000148 <cleanup_epilogs>
8000070c:	01c32623          	sw	t3,12(t1)
80000710:	d5dff06f          	j	8000046c <resto_Mrtn>

80000714 <exit_cleanup>:
80000714:	00100093          	li	ra,1

80000718 <write_tohost>:
80000718:	00001f17          	auipc	t5,0x1
8000071c:	8e1f2423          	sw	ra,-1816(t5) # 80001000 <tohost>
80000720:	ff9ff06f          	j	80000718 <write_tohost>
	...

Disassembly of section .tohost:

80001000 <tohost>:
	...

80001100 <fromhost>:
	...

Disassembly of section .data:

80002000 <rvtest_trap_sig>:
80002000:	311c                	fld	fa5,32(a0)
80002002:	8000                	0x8000
	...

80002040 <Mtramptbl_sv>:
80002040:	0000006f          	j	80002040 <Mtramptbl_sv>
80002044:	0000006f          	j	80002044 <Mtramptbl_sv+0x4>
80002048:	0000006f          	j	80002048 <Mtramptbl_sv+0x8>
8000204c:	0000006f          	j	8000204c <Mtramptbl_sv+0xc>
80002050:	0000006f          	j	80002050 <Mtramptbl_sv+0x10>
80002054:	0000006f          	j	80002054 <Mtramptbl_sv+0x14>
80002058:	0000006f          	j	80002058 <Mtramptbl_sv+0x18>
8000205c:	0000006f          	j	8000205c <Mtramptbl_sv+0x1c>
80002060:	0000006f          	j	80002060 <Mtramptbl_sv+0x20>
80002064:	0000006f          	j	80002064 <Mtramptbl_sv+0x24>
80002068:	0000006f          	j	80002068 <Mtramptbl_sv+0x28>
8000206c:	0000006f          	j	8000206c <Mtramptbl_sv+0x2c>
80002070:	0000006f          	j	80002070 <Mtramptbl_sv+0x30>
80002074:	0000006f          	j	80002074 <Mtramptbl_sv+0x34>
80002078:	0000006f          	j	80002078 <Mtramptbl_sv+0x38>
8000207c:	0000006f          	j	8000207c <Mtramptbl_sv+0x3c>
80002080:	0000006f          	j	80002080 <Mtramptbl_sv+0x40>
80002084:	0000006f          	j	80002084 <Mtramptbl_sv+0x44>
80002088:	0000006f          	j	80002088 <Mtramptbl_sv+0x48>
8000208c:	0000006f          	j	8000208c <Mtramptbl_sv+0x4c>
80002090:	0000006f          	j	80002090 <Mtramptbl_sv+0x50>
80002094:	0000006f          	j	80002094 <Mtramptbl_sv+0x54>
80002098:	0000006f          	j	80002098 <Mtramptbl_sv+0x58>
8000209c:	0000006f          	j	8000209c <Mtramptbl_sv+0x5c>
800020a0:	0000006f          	j	800020a0 <Mtramptbl_sv+0x60>
800020a4:	0000006f          	j	800020a4 <Mtramptbl_sv+0x64>
800020a8:	0000006f          	j	800020a8 <Mtramptbl_sv+0x68>
800020ac:	0000006f          	j	800020ac <Mtramptbl_sv+0x6c>
800020b0:	0000006f          	j	800020b0 <Mtramptbl_sv+0x70>
800020b4:	0000006f          	j	800020b4 <Mtramptbl_sv+0x74>
800020b8:	0000006f          	j	800020b8 <Mtramptbl_sv+0x78>
800020bc:	0000006f          	j	800020bc <Mtramptbl_sv+0x7c>
800020c0:	0000006f          	j	800020c0 <Mtramptbl_sv+0x80>
800020c4:	0000006f          	j	800020c4 <Mtramptbl_sv+0x84>
800020c8:	0000006f          	j	800020c8 <Mtramptbl_sv+0x88>
800020cc:	0000006f          	j	800020cc <Mtramptbl_sv+0x8c>
800020d0:	0000006f          	j	800020d0 <Mtramptbl_sv+0x90>
800020d4:	0000006f          	j	800020d4 <Mtramptbl_sv+0x94>
800020d8:	0000006f          	j	800020d8 <Mtramptbl_sv+0x98>
800020dc:	0000006f          	j	800020dc <Mtramptbl_sv+0x9c>
800020e0:	0000006f          	j	800020e0 <Mtramptbl_sv+0xa0>
800020e4:	0000006f          	j	800020e4 <Mtramptbl_sv+0xa4>
800020e8:	0000006f          	j	800020e8 <Mtramptbl_sv+0xa8>
800020ec:	0000006f          	j	800020ec <Mtramptbl_sv+0xac>
800020f0:	0000006f          	j	800020f0 <Mtramptbl_sv+0xb0>
800020f4:	0000006f          	j	800020f4 <Mtramptbl_sv+0xb4>
800020f8:	0000006f          	j	800020f8 <Mtramptbl_sv+0xb8>
800020fc:	0000006f          	j	800020fc <Mtramptbl_sv+0xbc>
80002100:	0000006f          	j	80002100 <Mtramptbl_sv+0xc0>
80002104:	0000006f          	j	80002104 <Mtramptbl_sv+0xc4>
80002108:	0000006f          	j	80002108 <Mtramptbl_sv+0xc8>
8000210c:	0000006f          	j	8000210c <Mtramptbl_sv+0xcc>
80002110:	0000006f          	j	80002110 <Mtramptbl_sv+0xd0>
80002114:	0000006f          	j	80002114 <Mtramptbl_sv+0xd4>
80002118:	0000006f          	j	80002118 <Mtramptbl_sv+0xd8>
8000211c:	0000006f          	j	8000211c <Mtramptbl_sv+0xdc>
80002120:	0000006f          	j	80002120 <Mtramptbl_sv+0xe0>
80002124:	0000006f          	j	80002124 <Mtramptbl_sv+0xe4>
80002128:	0000006f          	j	80002128 <Mtramptbl_sv+0xe8>
8000212c:	0000006f          	j	8000212c <Mtramptbl_sv+0xec>
80002130:	0000006f          	j	80002130 <Mtramptbl_sv+0xf0>
80002134:	0000006f          	j	80002134 <Mtramptbl_sv+0xf4>
80002138:	0000006f          	j	80002138 <Mtramptbl_sv+0xf8>
8000213c:	0000006f          	j	8000213c <Mtramptbl_sv+0xfc>
80002140:	0000006f          	j	80002140 <Mtramptbl_sv+0x100>
80002144:	0000006f          	j	80002144 <Mtramptbl_sv+0x104>
80002148:	0000006f          	j	80002148 <Mtramptbl_sv+0x108>
8000214c:	0000006f          	j	8000214c <Mtramptbl_sv+0x10c>
80002150:	0000006f          	j	80002150 <Mtramptbl_sv+0x110>
80002154:	0000006f          	j	80002154 <Mtramptbl_sv+0x114>
80002158:	0000006f          	j	80002158 <Mtramptbl_sv+0x118>
8000215c:	0000006f          	j	8000215c <Mtramptbl_sv+0x11c>
80002160:	0000006f          	j	80002160 <Mtramptbl_sv+0x120>
80002164:	0000006f          	j	80002164 <Mtramptbl_sv+0x124>
80002168:	0000006f          	j	80002168 <Mtramptbl_sv+0x128>
8000216c:	0000006f          	j	8000216c <Mtramptbl_sv+0x12c>
80002170:	0000006f          	j	80002170 <Mtramptbl_sv+0x130>
80002174:	0000006f          	j	80002174 <Mtramptbl_sv+0x134>
80002178:	0000006f          	j	80002178 <Mtramptbl_sv+0x138>
8000217c:	0000006f          	j	8000217c <Mtramptbl_sv+0x13c>
80002180:	0000006f          	j	80002180 <Mtramptbl_sv+0x140>
80002184:	0000006f          	j	80002184 <Mtramptbl_sv+0x144>
80002188:	0000006f          	j	80002188 <Mtramptbl_sv+0x148>
8000218c:	0000006f          	j	8000218c <Mtramptbl_sv+0x14c>
80002190:	0000006f          	j	80002190 <Mtramptbl_sv+0x150>
80002194:	0000006f          	j	80002194 <Mtramptbl_sv+0x154>
80002198:	0000006f          	j	80002198 <Mtramptbl_sv+0x158>
8000219c:	0000006f          	j	8000219c <Mtramptbl_sv+0x15c>
800021a0:	0000006f          	j	800021a0 <Mtramptbl_sv+0x160>
800021a4:	0000006f          	j	800021a4 <Mtramptbl_sv+0x164>
800021a8:	0000006f          	j	800021a8 <Mtramptbl_sv+0x168>
800021ac:	0000006f          	j	800021ac <Mtramptbl_sv+0x16c>
800021b0:	0000006f          	j	800021b0 <Mtramptbl_sv+0x170>
800021b4:	0000006f          	j	800021b4 <Mtramptbl_sv+0x174>
800021b8:	0000006f          	j	800021b8 <Mtramptbl_sv+0x178>
800021bc:	0000006f          	j	800021bc <Mtramptbl_sv+0x17c>
800021c0:	0000006f          	j	800021c0 <Mtramptbl_sv+0x180>
800021c4:	0000006f          	j	800021c4 <Mtramptbl_sv+0x184>

800021c8 <Msatp_sv>:
	...

800021d0 <Mmode_rtn>:
800021d0:	00838067          	jr	8(t2)
800021d4:	0000                	unimp
	...

800021d8 <Mtrampend_sv>:
	...

800021e0 <Medeleg_sv>:
	...

800021e8 <Mtvec_new>:
	...

800021f0 <Mtvec_save>:
	...

800021f8 <Mscratch_save>:
	...

80002200 <Mtrapreg_sv>:
80002200:	deadbeef          	jal	t4,7ffdd7ea <CSR_XIP+0x7ffdd4a6>
80002204:	deadbeef          	jal	t4,7ffdd7ee <CSR_XIP+0x7ffdd4aa>
80002208:	deadbeef          	jal	t4,7ffdd7f2 <CSR_XIP+0x7ffdd4ae>
8000220c:	deadbeef          	jal	t4,7ffdd7f6 <CSR_XIP+0x7ffdd4b2>
80002210:	deadbeef          	jal	t4,7ffdd7fa <CSR_XIP+0x7ffdd4b6>
80002214:	deadbeef          	jal	t4,7ffdd7fe <CSR_XIP+0x7ffdd4ba>
80002218:	deadbeef          	jal	t4,7ffdd802 <CSR_XIP+0x7ffdd4be>
8000221c:	deadbeef          	jal	t4,7ffdd806 <CSR_XIP+0x7ffdd4c2>

80002220 <rvtest_data_begin>:
	...

80003000 <begin_regstate>:
80003000:	0080                	addi	s0,sp,64
	...

80003100 <end_regstate>:
80003100:	0004                	0x4
	...

80003110 <begin_signature>:
80003110:	a309                	j	80003612 <_end+0x4e2>
80003112:	6f5c                	flw	fa5,28(a4)

80003114 <test_A_res>:
80003114:	deadbeef          	jal	t4,7ffde6fe <CSR_XIP+0x7ffde3ba>
80003118:	deadbeef          	jal	t4,7ffde702 <CSR_XIP+0x7ffde3be>

8000311c <mtrap_sigptr>:
8000311c:	deadbeef          	jal	t4,7ffde706 <CSR_XIP+0x7ffde3c2>
80003120:	deadbeef          	jal	t4,7ffde70a <CSR_XIP+0x7ffde3c6>
80003124:	deadbeef          	jal	t4,7ffde70e <CSR_XIP+0x7ffde3ca>
80003128:	deadbeef          	jal	t4,7ffde712 <CSR_XIP+0x7ffde3ce>

8000312c <sig_end_canary>:
8000312c:	a309                	j	8000362e <_end+0x4fe>
8000312e:	6f5c                	flw	fa5,28(a4)

Disassembly of section .riscv.attributes:

00000000 <.riscv.attributes>:
   0:	2641                	jal	380 <CSR_XIP+0x3c>
   2:	0000                	unimp
   4:	7200                	flw	fs0,32(a2)
   6:	7369                	lui	t1,0xffffa
   8:	01007663          	bgeu	zero,a6,14 <MMODE_SIG+0x11>
   c:	001c                	0x1c
   e:	0000                	unimp
  10:	7205                	lui	tp,0xfffe1
  12:	3376                	fld	ft6,376(sp)
  14:	6932                	flw	fs2,12(sp)
  16:	7032                	flw	ft0,44(sp)
  18:	5f30                	lw	a2,120(a4)
  1a:	697a                	flw	fs2,156(sp)
  1c:	30727363          	bgeu	tp,t2,322 <CSR_XTVEC+0x1d>
  20:	3070                	fld	fa2,224(s0)
  22:	0800                	addi	s0,sp,16
  24:	0a01                	addi	s4,s4,0
  26:	0b              	Address 0x0000000000000026 is out of bounds.


Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	000000d7          	0xd7
   4:	007b0003          	lb	zero,7(s6)
   8:	0000                	unimp
   a:	0101                	addi	sp,sp,0
   c:	000d0efb          	0xd0efb
  10:	0101                	addi	sp,sp,0
  12:	0101                	addi	sp,sp,0
  14:	0000                	unimp
  16:	0100                	addi	s0,sp,128
  18:	0000                	unimp
  1a:	2f01                	jal	72a <CSR_XIP+0x3e6>
  1c:	6f68                	flw	fa0,92(a4)
  1e:	656d                	lui	a0,0x1b
  20:	766f6c2f          	0x766f6c2f
  24:	7369                	lui	t1,0xffffa
  26:	7365442f          	0x7365442f
  2a:	706f746b          	0x706f746b
  2e:	5669522f          	0x5669522f
  32:	7265                	lui	tp,0xffff9
  34:	635f 726f 2f65      	0x2f65726f635f
  3a:	6972                	flw	fs2,28(sp)
  3c:	666f6373          	csrrsi	t1,0x666,30
  40:	7369722f          	0x7369722f
  44:	612d7663          	bgeu	s10,s2,650 <CSR_XIP+0x30c>
  48:	6372                	flw	ft6,28(sp)
  4a:	2d68                	fld	fa0,216(a0)
  4c:	6574                	flw	fa3,76(a0)
  4e:	722f7473          	csrrci	s0,0x722,30
  52:	7369                	lui	t1,0xffffa
  54:	742d7663          	bgeu	s10,sp,7a0 <CSR_XIP+0x45c>
  58:	7365                	lui	t1,0xffff9
  5a:	2d74                	fld	fa3,216(a0)
  5c:	74697573          	csrrci	a0,0x746,18
  60:	2f65                	jal	818 <CSR_XIP+0x4d4>
  62:	7672                	flw	fa2,60(sp)
  64:	5f693233          	0x5f693233
  68:	2f6d                	jal	822 <CSR_XIP+0x4de>
  6a:	7270                	flw	fa2,100(a2)
  6c:	7669                	lui	a2,0xffffa
  6e:	6c69                	lui	s8,0x1a
  70:	6765                	lui	a4,0x19
  72:	2f65                	jal	82a <CSR_XIP+0x4e6>
  74:	00637273          	csrrci	tp,0x6,6
  78:	6500                	flw	fs0,8(a0)
  7a:	6c6c6163          	bltu	s8,t1,73c <CSR_XIP+0x3f8>
  7e:	532e                	lw	t1,232(sp)
  80:	0100                	addi	s0,sp,128
  82:	0000                	unimp
  84:	0000                	unimp
  86:	0205                	addi	tp,tp,1
  88:	0000                	unimp
  8a:	8000                	0x8000
  8c:	03011203          	lh	tp,48(sp)
  90:	0906                	slli	s2,s2,0x1
  92:	0114                	addi	a3,sp,128
  94:	0301                	addi	t1,t1,0
  96:	0902                	c.slli64	s2
  98:	0008                	0x8
  9a:	0301                	addi	t1,t1,0
  9c:	0901                	addi	s2,s2,0
  9e:	0008                	0x8
  a0:	0301                	addi	t1,t1,0
  a2:	0901                	addi	s2,s2,0
  a4:	0004                	0x4
  a6:	0301                	addi	t1,t1,0
  a8:	0901                	addi	s2,s2,0
  aa:	0004                	0x4
  ac:	0301                	addi	t1,t1,0
  ae:	0901                	addi	s2,s2,0
  b0:	0004                	0x4
  b2:	0301                	addi	t1,t1,0
  b4:	0901                	addi	s2,s2,0
  b6:	0004                	0x4
  b8:	0301                	addi	t1,t1,0
  ba:	0004090b          	0x4090b
  be:	0301                	addi	t1,t1,0
  c0:	0901                	addi	s2,s2,0
  c2:	05dc                	addi	a5,sp,708
  c4:	0901                	addi	s2,s2,0
  c6:	0010                	0x10
  c8:	0100                	addi	s0,sp,128
  ca:	0001                	nop
  cc:	0205                	addi	tp,tp,1
  ce:	2040                	fld	fs0,128(s0)
  d0:	8000                	0x8000
  d2:	09012d03          	lw	s10,144(sp)
  d6:	10f0                	addi	a2,sp,108
  d8:	0100                	addi	s0,sp,128
  da:	01              	Address 0x00000000000000da is out of bounds.


Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	001e                	c.slli	zero,0x7
   2:	0000                	unimp
   4:	0002                	c.slli64	zero
   6:	0000                	unimp
   8:	0000                	unimp
   a:	0104                	addi	s1,sp,128
	...
  18:	0065                	c.nop	25
  1a:	0000                	unimp
  1c:	00b9                	addi	ra,ra,14
  1e:	0000                	unimp
  20:	8001                	c.srli64	s0

Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	1101                	addi	sp,sp,-32
   2:	1000                	addi	s0,sp,32
   4:	5506                	lw	a0,96(sp)
   6:	0306                	slli	t1,t1,0x1
   8:	1b0e                	slli	s6,s6,0x23
   a:	250e                	fld	fa0,192(sp)
   c:	130e                	slli	t1,t1,0x23
   e:	0005                	c.nop	1
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0024                	addi	s1,sp,8
   2:	0000                	unimp
   4:	0002                	c.slli64	zero
   6:	0000                	unimp
   8:	0000                	unimp
   a:	0004                	0x4
   c:	0000                	unimp
   e:	0000                	unimp
  10:	0000                	unimp
  12:	8000                	0x8000
  14:	0724                	addi	s1,sp,904
  16:	0000                	unimp
  18:	2000                	fld	fs0,0(s0)
  1a:	8000                	0x8000
  1c:	1130                	addi	a2,sp,168
	...

Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	6d6f682f          	0x6d6f682f
   4:	2f65                	jal	7bc <CSR_XIP+0x478>
   6:	6f6c                	flw	fa1,92(a4)
   8:	6976                	flw	fs2,92(sp)
   a:	65442f73          	csrrs	t5,0x654,s0
   e:	6f746b73          	csrrsi	s6,0x6f7,8
  12:	2f70                	fld	fa2,216(a4)
  14:	6952                	flw	fs2,20(sp)
  16:	6556                	flw	fa0,84(sp)
  18:	5f72                	lw	t5,60(sp)
  1a:	65726f63          	bltu	tp,s7,678 <CSR_XIP+0x334>
  1e:	7369722f          	0x7369722f
  22:	2f666f63          	bltu	a2,s6,320 <CSR_XTVEC+0x1b>
  26:	6972                	flw	fs2,28(sp)
  28:	2d766373          	csrrsi	t1,0x2d7,12
  2c:	7261                	lui	tp,0xffff8
  2e:	742d6863          	bltu	s10,sp,77e <CSR_XIP+0x43a>
  32:	7365                	lui	t1,0xffff9
  34:	2f74                	fld	fa3,216(a4)
  36:	6972                	flw	fs2,28(sp)
  38:	2d766373          	csrrsi	t1,0x2d7,12
  3c:	6574                	flw	fa3,76(a0)
  3e:	732d7473          	csrrci	s0,0x732,26
  42:	6975                	lui	s2,0x1d
  44:	6574                	flw	fa3,76(a0)
  46:	3376722f          	0x3376722f
  4a:	6932                	flw	fs2,12(sp)
  4c:	6d5f 702f 6972      	0x6972702f6d5f
  52:	6976                	flw	fs2,92(sp)
  54:	656c                	flw	fa1,76(a0)
  56:	732f6567          	0x732f6567
  5a:	6372                	flw	ft6,28(sp)
  5c:	6163652f          	0x6163652f
  60:	6c6c                	flw	fa1,92(s0)
  62:	532e                	lw	t1,232(sp)
  64:	2f00                	fld	fs0,24(a4)
  66:	6f68                	flw	fa0,92(a4)
  68:	656d                	lui	a0,0x1b
  6a:	766f6c2f          	0x766f6c2f
  6e:	7369                	lui	t1,0xffffa
  70:	7365442f          	0x7365442f
  74:	706f746b          	0x706f746b
  78:	5669522f          	0x5669522f
  7c:	7265                	lui	tp,0xffff9
  7e:	635f 726f 2f65      	0x2f65726f635f
  84:	6972                	flw	fs2,28(sp)
  86:	666f6373          	csrrsi	t1,0x666,30
  8a:	7369722f          	0x7369722f
  8e:	5f666f63          	bltu	a2,s6,68c <CSR_XIP+0x348>
  92:	6b726f77          	0x6b726f77
  96:	3376722f          	0x3376722f
  9a:	6932                	flw	fs2,12(sp)
  9c:	6d5f 702f 6972      	0x6972702f6d5f
  a2:	6976                	flw	fs2,92(sp)
  a4:	656c                	flw	fa1,76(a0)
  a6:	732f6567          	0x732f6567
  aa:	6372                	flw	ft6,28(sp)
  ac:	6163652f          	0x6163652f
  b0:	6c6c                	flw	fa1,92(s0)
  b2:	532e                	lw	t1,232(sp)
  b4:	7475642f          	0x7475642f
  b8:	4700                	lw	s0,8(a4)
  ba:	554e                	lw	a0,240(sp)
  bc:	4120                	lw	s0,64(a0)
  be:	2e322053          	0x2e322053
  c2:	          	snez	a0,zero

Disassembly of section .debug_ranges:

00000000 <.debug_ranges>:
   0:	ffff                	0xffff
   2:	ffff                	0xffff
   4:	0000                	unimp
   6:	0000                	unimp
   8:	0000                	unimp
   a:	8000                	0x8000
   c:	0724                	addi	s1,sp,904
   e:	8000                	0x8000
  10:	2000                	fld	fs0,0(s0)
  12:	8000                	0x8000
  14:	3130                	fld	fa2,96(a0)
  16:	8000                	0x8000
	...
