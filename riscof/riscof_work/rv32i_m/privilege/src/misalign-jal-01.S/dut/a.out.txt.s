
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
8000001c:	3a8e8e93          	addi	t4,t4,936 # 800003c0 <Mtrampoline>
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
80000094:	2ecf8f93          	addi	t6,t6,748 # 8000037c <cleanup_epilogs>
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

8000011c <inst_0>:
8000011c:	00000117          	auipc	sp,0x0
80000120:	02010113          	addi	sp,sp,32 # 8000013c <inst_0+0x20>
80000124:	00010067          	jr	sp
80000128:	00000117          	auipc	sp,0x0
8000012c:	23010113          	addi	sp,sp,560 # 80000358 <inst_0+0x23c>
80000130:	00010067          	jr	sp
80000134:	00154513          	xori	a0,a0,1
80000138:	fe0008e3          	beqz	zero,80000128 <inst_0+0xc>
8000013c:	20a0056f          	jal	a0,80000346 <inst_0+0x22a>
80000140:	00000013          	nop
80000144:	00000013          	nop
80000148:	00254513          	xori	a0,a0,2
8000014c:	20c0006f          	j	80000358 <inst_0+0x23c>
80000150:	00000013          	nop
80000154:	00000013          	nop
80000158:	00000013          	nop
8000015c:	00000013          	nop
80000160:	00000013          	nop
80000164:	00000013          	nop
80000168:	00000013          	nop
8000016c:	00000013          	nop
80000170:	00000013          	nop
80000174:	00000013          	nop
80000178:	00000013          	nop
8000017c:	00000013          	nop
80000180:	00000013          	nop
80000184:	00000013          	nop
80000188:	00000013          	nop
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
800001c0:	00000013          	nop
800001c4:	00000013          	nop
800001c8:	00000013          	nop
800001cc:	00000013          	nop
800001d0:	00000013          	nop
800001d4:	00000013          	nop
800001d8:	00000013          	nop
800001dc:	00000013          	nop
800001e0:	00000013          	nop
800001e4:	00000013          	nop
800001e8:	00000013          	nop
800001ec:	00000013          	nop
800001f0:	00000013          	nop
800001f4:	00000013          	nop
800001f8:	00000013          	nop
800001fc:	00000013          	nop
80000200:	00000013          	nop
80000204:	00000013          	nop
80000208:	00000013          	nop
8000020c:	00000013          	nop
80000210:	00000013          	nop
80000214:	00000013          	nop
80000218:	00000013          	nop
8000021c:	00000013          	nop
80000220:	00000013          	nop
80000224:	00000013          	nop
80000228:	00000013          	nop
8000022c:	00000013          	nop
80000230:	00000013          	nop
80000234:	00000013          	nop
80000238:	00000013          	nop
8000023c:	00000013          	nop
80000240:	00000013          	nop
80000244:	00000013          	nop
80000248:	00000013          	nop
8000024c:	00000013          	nop
80000250:	00000013          	nop
80000254:	00000013          	nop
80000258:	00000013          	nop
8000025c:	00000013          	nop
80000260:	00000013          	nop
80000264:	00000013          	nop
80000268:	00000013          	nop
8000026c:	00000013          	nop
80000270:	00000013          	nop
80000274:	00000013          	nop
80000278:	00000013          	nop
8000027c:	00000013          	nop
80000280:	00000013          	nop
80000284:	00000013          	nop
80000288:	00000013          	nop
8000028c:	00000013          	nop
80000290:	00000013          	nop
80000294:	00000013          	nop
80000298:	00000013          	nop
8000029c:	00000013          	nop
800002a0:	00000013          	nop
800002a4:	00000013          	nop
800002a8:	00000013          	nop
800002ac:	00000013          	nop
800002b0:	00000013          	nop
800002b4:	00000013          	nop
800002b8:	00000013          	nop
800002bc:	00000013          	nop
800002c0:	00000013          	nop
800002c4:	00000013          	nop
800002c8:	00000013          	nop
800002cc:	00000013          	nop
800002d0:	00000013          	nop
800002d4:	00000013          	nop
800002d8:	00000013          	nop
800002dc:	00000013          	nop
800002e0:	00000013          	nop
800002e4:	00000013          	nop
800002e8:	00000013          	nop
800002ec:	00000013          	nop
800002f0:	00000013          	nop
800002f4:	00000013          	nop
800002f8:	00000013          	nop
800002fc:	00000013          	nop
80000300:	00000013          	nop
80000304:	00000013          	nop
80000308:	00000013          	nop
8000030c:	00000013          	nop
80000310:	00000013          	nop
80000314:	00000013          	nop
80000318:	00000013          	nop
8000031c:	00000013          	nop
80000320:	00000013          	nop
80000324:	00000013          	nop
80000328:	00000013          	nop
8000032c:	00000013          	nop
80000330:	00000013          	nop
80000334:	00000013          	nop
80000338:	00000013          	nop
8000033c:	00000013          	nop
80000340:	00000013          	nop
80000344:	0000                	unimp
80000346:	00354513          	xori	a0,a0,3
8000034a:	00000117          	auipc	sp,0x0
8000034e:	00e10113          	addi	sp,sp,14 # 80000358 <inst_0+0x23c>
80000352:	00010067          	jr	sp
80000356:	0000                	unimp
80000358:	00000117          	auipc	sp,0x0
8000035c:	dc410113          	addi	sp,sp,-572 # 8000011c <inst_0>
80000360:	ffc17113          	andi	sp,sp,-4
80000364:	40250533          	sub	a0,a0,sp
80000368:	00a0a023          	sw	a0,0(ra) # 80003114 <signature_x1_0>

8000036c <rvtest_code_end>:
8000036c:	0000100f          	fence.i
80000370:	00000397          	auipc	t2,0x0
80000374:	30002ef3          	csrr	t4,mstatus
80000378:	0000100f          	fence.i

8000037c <cleanup_epilogs>:
8000037c:	34002373          	csrr	t1,mscratch

80000380 <resto_Medeleg>:
80000380:	fe032383          	lw	t2,-32(t1)

80000384 <resto_Mscratch>:
80000384:	ff832f03          	lw	t5,-8(t1)
80000388:	340f1073          	csrw	mscratch,t5

8000038c <resto_Mxtvec>:
8000038c:	ff032e83          	lw	t4,-16(t1)
80000390:	305e93f3          	csrrw	t2,mtvec,t4
80000394:	ffcefe93          	andi	t4,t4,-4
80000398:	ffc3f393          	andi	t2,t2,-4
8000039c:	027e9063          	bne	t4,t2,800003bc <rvtest_Mend>

800003a0 <resto_Mtramp>:
800003a0:	e4430e93          	addi	t4,t1,-444
800003a4:	fd832e03          	lw	t3,-40(t1)

800003a8 <resto_Mloop>:
800003a8:	000eaf83          	lw	t6,0(t4)
800003ac:	01f3a023          	sw	t6,0(t2) # 80000370 <rvtest_code_end+0x4>
800003b0:	00438393          	addi	t2,t2,4
800003b4:	004e8e93          	addi	t4,t4,4
800003b8:	ffc3c8e3          	blt	t2,t3,800003a8 <resto_Mloop>

800003bc <rvtest_Mend>:
800003bc:	5580006f          	j	80000914 <exit_cleanup>

800003c0 <Mtrampoline>:
800003c0:	0800006f          	j	80000440 <trap_Mhandler>
800003c4:	0880006f          	j	8000044c <trap_Mhandler+0xc>
800003c8:	0900006f          	j	80000458 <trap_Mhandler+0x18>
800003cc:	0980006f          	j	80000464 <trap_Mhandler+0x24>
800003d0:	0a00006f          	j	80000470 <trap_Mhandler+0x30>
800003d4:	0a80006f          	j	8000047c <trap_Mhandler+0x3c>
800003d8:	0b00006f          	j	80000488 <trap_Mhandler+0x48>
800003dc:	0b80006f          	j	80000494 <trap_Mhandler+0x54>
800003e0:	0c00006f          	j	800004a0 <trap_Mhandler+0x60>
800003e4:	0c80006f          	j	800004ac <trap_Mhandler+0x6c>
800003e8:	0d00006f          	j	800004b8 <trap_Mhandler+0x78>
800003ec:	0d80006f          	j	800004c4 <trap_Mhandler+0x84>
800003f0:	0e00006f          	j	800004d0 <trap_Mhandler+0x90>
800003f4:	0e80006f          	j	800004dc <trap_Mhandler+0x9c>
800003f8:	0f00006f          	j	800004e8 <trap_Mhandler+0xa8>
800003fc:	0f80006f          	j	800004f4 <trap_Mhandler+0xb4>
80000400:	1000006f          	j	80000500 <rvtest_Mendtest>
80000404:	0fc0006f          	j	80000500 <rvtest_Mendtest>
80000408:	0f80006f          	j	80000500 <rvtest_Mendtest>
8000040c:	0f40006f          	j	80000500 <rvtest_Mendtest>
80000410:	0f00006f          	j	80000500 <rvtest_Mendtest>
80000414:	0ec0006f          	j	80000500 <rvtest_Mendtest>
80000418:	0e80006f          	j	80000500 <rvtest_Mendtest>
8000041c:	0e40006f          	j	80000500 <rvtest_Mendtest>
80000420:	0e00006f          	j	80000500 <rvtest_Mendtest>
80000424:	0dc0006f          	j	80000500 <rvtest_Mendtest>
80000428:	0d80006f          	j	80000500 <rvtest_Mendtest>
8000042c:	0d40006f          	j	80000500 <rvtest_Mendtest>
80000430:	0d00006f          	j	80000500 <rvtest_Mendtest>
80000434:	0cc0006f          	j	80000500 <rvtest_Mendtest>
80000438:	0c80006f          	j	80000500 <rvtest_Mendtest>
8000043c:	0c40006f          	j	80000500 <rvtest_Mendtest>

80000440 <trap_Mhandler>:
80000440:	34011173          	csrrw	sp,mscratch,sp
80000444:	01f12c23          	sw	t6,24(sp)
80000448:	0c400fef          	jal	t6,8000050c <common_Mhandler>
8000044c:	34011173          	csrrw	sp,mscratch,sp
80000450:	01f12c23          	sw	t6,24(sp)
80000454:	0b800fef          	jal	t6,8000050c <common_Mhandler>
80000458:	34011173          	csrrw	sp,mscratch,sp
8000045c:	01f12c23          	sw	t6,24(sp)
80000460:	0ac00fef          	jal	t6,8000050c <common_Mhandler>
80000464:	34011173          	csrrw	sp,mscratch,sp
80000468:	01f12c23          	sw	t6,24(sp)
8000046c:	0a000fef          	jal	t6,8000050c <common_Mhandler>
80000470:	34011173          	csrrw	sp,mscratch,sp
80000474:	01f12c23          	sw	t6,24(sp)
80000478:	09400fef          	jal	t6,8000050c <common_Mhandler>
8000047c:	34011173          	csrrw	sp,mscratch,sp
80000480:	01f12c23          	sw	t6,24(sp)
80000484:	08800fef          	jal	t6,8000050c <common_Mhandler>
80000488:	34011173          	csrrw	sp,mscratch,sp
8000048c:	01f12c23          	sw	t6,24(sp)
80000490:	07c00fef          	jal	t6,8000050c <common_Mhandler>
80000494:	34011173          	csrrw	sp,mscratch,sp
80000498:	01f12c23          	sw	t6,24(sp)
8000049c:	07000fef          	jal	t6,8000050c <common_Mhandler>
800004a0:	34011173          	csrrw	sp,mscratch,sp
800004a4:	01f12c23          	sw	t6,24(sp)
800004a8:	06400fef          	jal	t6,8000050c <common_Mhandler>
800004ac:	34011173          	csrrw	sp,mscratch,sp
800004b0:	01f12c23          	sw	t6,24(sp)
800004b4:	05800fef          	jal	t6,8000050c <common_Mhandler>
800004b8:	34011173          	csrrw	sp,mscratch,sp
800004bc:	01f12c23          	sw	t6,24(sp)
800004c0:	04c00fef          	jal	t6,8000050c <common_Mhandler>
800004c4:	34011173          	csrrw	sp,mscratch,sp
800004c8:	01f12c23          	sw	t6,24(sp)
800004cc:	04000fef          	jal	t6,8000050c <common_Mhandler>
800004d0:	34011173          	csrrw	sp,mscratch,sp
800004d4:	01f12c23          	sw	t6,24(sp)
800004d8:	03400fef          	jal	t6,8000050c <common_Mhandler>
800004dc:	34011173          	csrrw	sp,mscratch,sp
800004e0:	01f12c23          	sw	t6,24(sp)
800004e4:	02800fef          	jal	t6,8000050c <common_Mhandler>
800004e8:	34011173          	csrrw	sp,mscratch,sp
800004ec:	01f12c23          	sw	t6,24(sp)
800004f0:	01c00fef          	jal	t6,8000050c <common_Mhandler>
800004f4:	34011173          	csrrw	sp,mscratch,sp
800004f8:	01f12c23          	sw	t6,24(sp)
800004fc:	01000fef          	jal	t6,8000050c <common_Mhandler>

80000500 <rvtest_Mendtest>:
80000500:	00000317          	auipc	t1,0x0
80000504:	ebc30313          	addi	t1,t1,-324 # 800003bc <rvtest_Mend>
80000508:	00030067          	jr	t1

8000050c <common_Mhandler>:
8000050c:	01e12a23          	sw	t5,20(sp)
80000510:	34011f73          	csrrw	t5,mscratch,sp
80000514:	01e12e23          	sw	t5,28(sp)
80000518:	00000f17          	auipc	t5,0x0
8000051c:	00cf0f13          	addi	t5,t5,12 # 80000524 <common_Mentry>
80000520:	000f0067          	jr	t5

80000524 <common_Mentry>:
80000524:	01d12823          	sw	t4,16(sp)
80000528:	01c12623          	sw	t3,12(sp)
8000052c:	00712423          	sw	t2,8(sp)
80000530:	00612223          	sw	t1,4(sp)

80000534 <Mtrapsig_ptr_upd>:
80000534:	01000393          	li	t2,16
80000538:	34202f73          	csrr	t5,mcause
8000053c:	000f5c63          	bgez	t5,80000554 <Mxcpt_sig_sv>

80000540 <Mint_sig_sv>:
80000540:	001f1e13          	slli	t3,t5,0x1
80000544:	ff2e0e13          	addi	t3,t3,-14
80000548:	000e5e63          	bgez	t3,80000564 <Mtrap_sig_sv>
8000054c:	00c00393          	li	t2,12
80000550:	0140006f          	j	80000564 <Mtrap_sig_sv>

80000554 <Mxcpt_sig_sv>:
80000554:	30102373          	csrr	t1,misa
80000558:	01831313          	slli	t1,t1,0x18
8000055c:	00035463          	bgez	t1,80000564 <Mtrap_sig_sv>
80000560:	01800393          	li	t2,24

80000564 <Mtrap_sig_sv>:
80000564:	00002e17          	auipc	t3,0x2
80000568:	a9ce0e13          	addi	t3,t3,-1380 # 80002000 <rvtest_trap_sig>
8000056c:	000e2303          	lw	t1,0(t3)
80000570:	00730eb3          	add	t4,t1,t2
80000574:	01de2023          	sw	t4,0(t3)
80000578:	fe812e03          	lw	t3,-24(sp)

8000057c <sv_Mvect>:
8000057c:	41cf8fb3          	sub	t6,t6,t3
80000580:	004f9f93          	slli	t6,t6,0x4
80000584:	007fefb3          	or	t6,t6,t2
80000588:	003f8f93          	addi	t6,t6,3
8000058c:	01f32023          	sw	t6,0(t1)

80000590 <sv_Mcause>:
80000590:	01e32223          	sw	t5,4(t1)
80000594:	0e0f4c63          	bltz	t5,8000068c <common_Mint_handler>

80000598 <common_Mexcpt_handler>:
80000598:	00ff7f13          	andi	t5,t5,15
8000059c:	341023f3          	csrr	t2,mepc

800005a0 <code_adj_Mepc>:
800005a0:	00000e17          	auipc	t3,0x0
800005a4:	b74e0e13          	addi	t3,t3,-1164 # 80000114 <rvtest_code_begin>
800005a8:	00000f97          	auipc	t6,0x0
800005ac:	dc4f8f93          	addi	t6,t6,-572 # 8000036c <rvtest_code_end>
800005b0:	01f3f463          	bgeu	t2,t6,800005b8 <data_adj_Mepc>
800005b4:	01c3fe63          	bgeu	t2,t3,800005d0 <adj_Mepc>

800005b8 <data_adj_Mepc>:
800005b8:	00002e17          	auipc	t3,0x2
800005bc:	c68e0e13          	addi	t3,t3,-920 # 80002220 <rvtest_data_begin>
800005c0:	00002f97          	auipc	t6,0x2
800005c4:	c70f8f93          	addi	t6,t6,-912 # 80002230 <rvtest_data_end>
800005c8:	dbf3fae3          	bgeu	t2,t6,8000037c <cleanup_epilogs>
800005cc:	dbc3e8e3          	bltu	t2,t3,8000037c <cleanup_epilogs>

800005d0 <adj_Mepc>:
800005d0:	41c38eb3          	sub	t4,t2,t3

800005d4 <sv_Mepc>:
800005d4:	01d32423          	sw	t4,8(t1)

800005d8 <adj_Mepc_rtn>:
800005d8:	ffc3ff93          	andi	t6,t2,-4
800005dc:	008f8f93          	addi	t6,t6,8
800005e0:	341f9073          	csrw	mepc,t6
800005e4:	34302ff3          	csrr	t6,mtval

800005e8 <chk_Mtval>:
800005e8:	0000beb7          	lui	t4,0xb
800005ec:	0fbe8e93          	addi	t4,t4,251 # b0fb <CSR_XIP+0xadb7>
800005f0:	01eedeb3          	srl	t4,t4,t5
800005f4:	01fe9e93          	slli	t4,t4,0x1f
800005f8:	040ed863          	bgez	t4,80000648 <sv_Mtval>

800005fc <sig_adj_Mtval>:
800005fc:	00003e17          	auipc	t3,0x3
80000600:	b14e0e13          	addi	t3,t3,-1260 # 80003110 <begin_signature>
80000604:	00003f97          	auipc	t6,0x3
80000608:	c20f8f93          	addi	t6,t6,-992 # 80003224 <rvtest_sig_end>
8000060c:	01f3f463          	bgeu	t2,t6,80000614 <code_adj_Mtval>
80000610:	03c3fa63          	bgeu	t2,t3,80000644 <adj_Mtval>

80000614 <code_adj_Mtval>:
80000614:	00000e17          	auipc	t3,0x0
80000618:	b00e0e13          	addi	t3,t3,-1280 # 80000114 <rvtest_code_begin>
8000061c:	00000f97          	auipc	t6,0x0
80000620:	d50f8f93          	addi	t6,t6,-688 # 8000036c <rvtest_code_end>
80000624:	01f3f463          	bgeu	t2,t6,8000062c <data_adj_Mtval>
80000628:	01c3fe63          	bgeu	t2,t3,80000644 <adj_Mtval>

8000062c <data_adj_Mtval>:
8000062c:	00002e17          	auipc	t3,0x2
80000630:	bf4e0e13          	addi	t3,t3,-1036 # 80002220 <rvtest_data_begin>
80000634:	00002f97          	auipc	t6,0x2
80000638:	bfcf8f93          	addi	t6,t6,-1028 # 80002230 <rvtest_data_end>
8000063c:	d5f3f0e3          	bgeu	t2,t6,8000037c <cleanup_epilogs>
80000640:	d3c3eee3          	bltu	t2,t3,8000037c <cleanup_epilogs>

80000644 <adj_Mtval>:
80000644:	41cf8fb3          	sub	t6,t6,t3

80000648 <sv_Mtval>:
80000648:	01f32623          	sw	t6,12(t1)

8000064c <chk_Mtrapsig_overrun>:
8000064c:	00002e17          	auipc	t3,0x2
80000650:	9b4e0e13          	addi	t3,t3,-1612 # 80002000 <rvtest_trap_sig>
80000654:	000e2e03          	lw	t3,0(t3)
80000658:	00003e97          	auipc	t4,0x3
8000065c:	ab8e8e93          	addi	t4,t4,-1352 # 80003110 <begin_signature>
80000660:	d1de6ee3          	bltu	t3,t4,8000037c <cleanup_epilogs>
80000664:	10000393          	li	t2,256
80000668:	0400006f          	j	800006a8 <spcl_Mhandler>

8000066c <resto_Mrtn>:
8000066c:	00412303          	lw	t1,4(sp)
80000670:	00812383          	lw	t2,8(sp)
80000674:	00c12e03          	lw	t3,12(sp)
80000678:	01012e83          	lw	t4,16(sp)
8000067c:	01412f03          	lw	t5,20(sp)
80000680:	01812f83          	lw	t6,24(sp)
80000684:	01c12103          	lw	sp,28(sp)
80000688:	30200073          	mret

8000068c <common_Mint_handler>:
8000068c:	00100e13          	li	t3,1
80000690:	00ff7393          	andi	t2,t5,15
80000694:	007e1e33          	sll	t3,t3,t2
80000698:	304e3ef3          	csrrc	t4,mie,t3
8000069c:	344e3ef3          	csrrc	t4,mip,t3

800006a0 <sv_Mip>:
800006a0:	01d32423          	sw	t4,8(t1)
800006a4:	00000393          	li	t2,0

800006a8 <spcl_Mhandler>:
800006a8:	00000e17          	auipc	t3,0x0
800006ac:	01ce0e13          	addi	t3,t3,28 # 800006c4 <clrint_Mtbl>
800006b0:	007e0e33          	add	t3,t3,t2
800006b4:	003f1393          	slli	t2,t5,0x3
800006b8:	007e0e33          	add	t3,t3,t2
800006bc:	000e2e03          	lw	t3,0(t3)

800006c0 <spcl_Mdispatch>:
800006c0:	000e0067          	jr	t3

800006c4 <clrint_Mtbl>:
800006c4:	066c                	addi	a1,sp,780
800006c6:	8000                	0x8000
800006c8:	0000                	unimp
800006ca:	0000                	unimp
800006cc:	037c                	addi	a5,sp,396
800006ce:	8000                	0x8000
800006d0:	0000                	unimp
800006d2:	0000                	unimp
800006d4:	037c                	addi	a5,sp,396
800006d6:	8000                	0x8000
800006d8:	0000                	unimp
800006da:	0000                	unimp
800006dc:	08c4                	addi	s1,sp,84
800006de:	8000                	0x8000
800006e0:	0000                	unimp
800006e2:	0000                	unimp
800006e4:	066c                	addi	a1,sp,780
800006e6:	8000                	0x8000
800006e8:	0000                	unimp
800006ea:	0000                	unimp
800006ec:	037c                	addi	a5,sp,396
800006ee:	8000                	0x8000
800006f0:	0000                	unimp
800006f2:	0000                	unimp
800006f4:	037c                	addi	a5,sp,396
800006f6:	8000                	0x8000
800006f8:	0000                	unimp
800006fa:	0000                	unimp
800006fc:	08d0                	addi	a2,sp,84
800006fe:	8000                	0x8000
80000700:	0000                	unimp
80000702:	0000                	unimp
80000704:	066c                	addi	a1,sp,780
80000706:	8000                	0x8000
80000708:	0000                	unimp
8000070a:	0000                	unimp
8000070c:	037c                	addi	a5,sp,396
8000070e:	8000                	0x8000
80000710:	0000                	unimp
80000712:	0000                	unimp
80000714:	037c                	addi	a5,sp,396
80000716:	8000                	0x8000
80000718:	0000                	unimp
8000071a:	0000                	unimp
8000071c:	08d4                	addi	a3,sp,84
8000071e:	8000                	0x8000
80000720:	0000                	unimp
80000722:	0000                	unimp
80000724:	066c                	addi	a1,sp,780
80000726:	8000                	0x8000
80000728:	0000                	unimp
8000072a:	0000                	unimp
8000072c:	066c                	addi	a1,sp,780
8000072e:	8000                	0x8000
80000730:	0000                	unimp
80000732:	0000                	unimp
80000734:	066c                	addi	a1,sp,780
80000736:	8000                	0x8000
80000738:	0000                	unimp
8000073a:	0000                	unimp
8000073c:	066c                	addi	a1,sp,780
8000073e:	8000                	0x8000
80000740:	0000                	unimp
80000742:	0000                	unimp
80000744:	037c                	addi	a5,sp,396
80000746:	8000                	0x8000
80000748:	0000                	unimp
8000074a:	0000                	unimp
8000074c:	037c                	addi	a5,sp,396
8000074e:	8000                	0x8000
80000750:	0000                	unimp
80000752:	0000                	unimp
80000754:	037c                	addi	a5,sp,396
80000756:	8000                	0x8000
80000758:	0000                	unimp
8000075a:	0000                	unimp
8000075c:	037c                	addi	a5,sp,396
8000075e:	8000                	0x8000
80000760:	0000                	unimp
80000762:	0000                	unimp
80000764:	037c                	addi	a5,sp,396
80000766:	8000                	0x8000
80000768:	0000                	unimp
8000076a:	0000                	unimp
8000076c:	037c                	addi	a5,sp,396
8000076e:	8000                	0x8000
80000770:	0000                	unimp
80000772:	0000                	unimp
80000774:	037c                	addi	a5,sp,396
80000776:	8000                	0x8000
80000778:	0000                	unimp
8000077a:	0000                	unimp
8000077c:	037c                	addi	a5,sp,396
8000077e:	8000                	0x8000
80000780:	0000                	unimp
80000782:	0000                	unimp
80000784:	037c                	addi	a5,sp,396
80000786:	8000                	0x8000
80000788:	0000                	unimp
8000078a:	0000                	unimp
8000078c:	037c                	addi	a5,sp,396
8000078e:	8000                	0x8000
80000790:	0000                	unimp
80000792:	0000                	unimp
80000794:	037c                	addi	a5,sp,396
80000796:	8000                	0x8000
80000798:	0000                	unimp
8000079a:	0000                	unimp
8000079c:	037c                	addi	a5,sp,396
8000079e:	8000                	0x8000
800007a0:	0000                	unimp
800007a2:	0000                	unimp
800007a4:	037c                	addi	a5,sp,396
800007a6:	8000                	0x8000
800007a8:	0000                	unimp
800007aa:	0000                	unimp
800007ac:	037c                	addi	a5,sp,396
800007ae:	8000                	0x8000
800007b0:	0000                	unimp
800007b2:	0000                	unimp
800007b4:	037c                	addi	a5,sp,396
800007b6:	8000                	0x8000
800007b8:	0000                	unimp
800007ba:	0000                	unimp
800007bc:	037c                	addi	a5,sp,396
800007be:	8000                	0x8000
800007c0:	0000                	unimp
	...

800007c4 <excpt_Mhndlr_tbl>:
800007c4:	066c                	addi	a1,sp,780
800007c6:	8000                	0x8000
800007c8:	0000                	unimp
800007ca:	0000                	unimp
800007cc:	066c                	addi	a1,sp,780
800007ce:	8000                	0x8000
800007d0:	0000                	unimp
800007d2:	0000                	unimp
800007d4:	066c                	addi	a1,sp,780
800007d6:	8000                	0x8000
800007d8:	0000                	unimp
800007da:	0000                	unimp
800007dc:	066c                	addi	a1,sp,780
800007de:	8000                	0x8000
800007e0:	0000                	unimp
800007e2:	0000                	unimp
800007e4:	066c                	addi	a1,sp,780
800007e6:	8000                	0x8000
800007e8:	0000                	unimp
800007ea:	0000                	unimp
800007ec:	066c                	addi	a1,sp,780
800007ee:	8000                	0x8000
800007f0:	0000                	unimp
800007f2:	0000                	unimp
800007f4:	066c                	addi	a1,sp,780
800007f6:	8000                	0x8000
800007f8:	0000                	unimp
800007fa:	0000                	unimp
800007fc:	066c                	addi	a1,sp,780
800007fe:	8000                	0x8000
80000800:	0000                	unimp
80000802:	0000                	unimp
80000804:	066c                	addi	a1,sp,780
80000806:	8000                	0x8000
80000808:	0000                	unimp
8000080a:	0000                	unimp
8000080c:	066c                	addi	a1,sp,780
8000080e:	8000                	0x8000
80000810:	0000                	unimp
80000812:	0000                	unimp
80000814:	066c                	addi	a1,sp,780
80000816:	8000                	0x8000
80000818:	0000                	unimp
8000081a:	0000                	unimp
8000081c:	066c                	addi	a1,sp,780
8000081e:	8000                	0x8000
80000820:	0000                	unimp
80000822:	0000                	unimp
80000824:	066c                	addi	a1,sp,780
80000826:	8000                	0x8000
80000828:	0000                	unimp
8000082a:	0000                	unimp
8000082c:	066c                	addi	a1,sp,780
8000082e:	8000                	0x8000
80000830:	0000                	unimp
80000832:	0000                	unimp
80000834:	066c                	addi	a1,sp,780
80000836:	8000                	0x8000
80000838:	0000                	unimp
8000083a:	0000                	unimp
8000083c:	066c                	addi	a1,sp,780
8000083e:	8000                	0x8000
80000840:	0000                	unimp
80000842:	0000                	unimp
80000844:	037c                	addi	a5,sp,396
80000846:	8000                	0x8000
80000848:	0000                	unimp
8000084a:	0000                	unimp
8000084c:	037c                	addi	a5,sp,396
8000084e:	8000                	0x8000
80000850:	0000                	unimp
80000852:	0000                	unimp
80000854:	037c                	addi	a5,sp,396
80000856:	8000                	0x8000
80000858:	0000                	unimp
8000085a:	0000                	unimp
8000085c:	037c                	addi	a5,sp,396
8000085e:	8000                	0x8000
80000860:	0000                	unimp
80000862:	0000                	unimp
80000864:	037c                	addi	a5,sp,396
80000866:	8000                	0x8000
80000868:	0000                	unimp
8000086a:	0000                	unimp
8000086c:	037c                	addi	a5,sp,396
8000086e:	8000                	0x8000
80000870:	0000                	unimp
80000872:	0000                	unimp
80000874:	037c                	addi	a5,sp,396
80000876:	8000                	0x8000
80000878:	0000                	unimp
8000087a:	0000                	unimp
8000087c:	037c                	addi	a5,sp,396
8000087e:	8000                	0x8000
80000880:	0000                	unimp
80000882:	0000                	unimp
80000884:	037c                	addi	a5,sp,396
80000886:	8000                	0x8000
80000888:	0000                	unimp
8000088a:	0000                	unimp
8000088c:	037c                	addi	a5,sp,396
8000088e:	8000                	0x8000
80000890:	0000                	unimp
80000892:	0000                	unimp
80000894:	037c                	addi	a5,sp,396
80000896:	8000                	0x8000
80000898:	0000                	unimp
8000089a:	0000                	unimp
8000089c:	037c                	addi	a5,sp,396
8000089e:	8000                	0x8000
800008a0:	0000                	unimp
800008a2:	0000                	unimp
800008a4:	037c                	addi	a5,sp,396
800008a6:	8000                	0x8000
800008a8:	0000                	unimp
800008aa:	0000                	unimp
800008ac:	037c                	addi	a5,sp,396
800008ae:	8000                	0x8000
800008b0:	0000                	unimp
800008b2:	0000                	unimp
800008b4:	037c                	addi	a5,sp,396
800008b6:	8000                	0x8000
800008b8:	0000                	unimp
800008ba:	0000                	unimp
800008bc:	037c                	addi	a5,sp,396
800008be:	8000                	0x8000
800008c0:	0000                	unimp
	...

800008c4 <Mclr_Msw_int>:
800008c4:	020003b7          	lui	t2,0x2000
800008c8:	0003a023          	sw	zero,0(t2) # 2000000 <CSR_XIP+0x1fffcbc>
800008cc:	da1ff06f          	j	8000066c <resto_Mrtn>

800008d0 <Mclr_Mtmr_int>:
800008d0:	d9dff06f          	j	8000066c <resto_Mrtn>

800008d4 <Mclr_Mext_int>:
800008d4:	01c32623          	sw	t3,12(t1)
800008d8:	d95ff06f          	j	8000066c <resto_Mrtn>

800008dc <Mclr_Ssw_int>:
800008dc:	aa1ff06f          	j	8000037c <cleanup_epilogs>
800008e0:	d8dff06f          	j	8000066c <resto_Mrtn>

800008e4 <Mclr_Stmr_int>:
800008e4:	a99ff06f          	j	8000037c <cleanup_epilogs>
800008e8:	d85ff06f          	j	8000066c <resto_Mrtn>

800008ec <Mclr_Sext_int>:
800008ec:	a91ff06f          	j	8000037c <cleanup_epilogs>
800008f0:	01c32623          	sw	t3,12(t1)
800008f4:	d79ff06f          	j	8000066c <resto_Mrtn>

800008f8 <Mclr_Vsw_int>:
800008f8:	a85ff06f          	j	8000037c <cleanup_epilogs>
800008fc:	d71ff06f          	j	8000066c <resto_Mrtn>

80000900 <Mclr_Vtmr_int>:
80000900:	a7dff06f          	j	8000037c <cleanup_epilogs>
80000904:	d69ff06f          	j	8000066c <resto_Mrtn>

80000908 <Mclr_Vext_int>:
80000908:	a75ff06f          	j	8000037c <cleanup_epilogs>
8000090c:	01c32623          	sw	t3,12(t1)
80000910:	d5dff06f          	j	8000066c <resto_Mrtn>

80000914 <exit_cleanup>:
80000914:	00100093          	li	ra,1

80000918 <write_tohost>:
80000918:	00000f17          	auipc	t5,0x0
8000091c:	6e1f2423          	sw	ra,1768(t5) # 80001000 <tohost>
80000920:	ff9ff06f          	j	80000918 <write_tohost>
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
80002220:	cafe                	sw	t6,84(sp)
80002222:	babe                	fsd	fa5,368(sp)
80002224:	cafe                	sw	t6,84(sp)
80002226:	babe                	fsd	fa5,368(sp)
80002228:	cafe                	sw	t6,84(sp)
8000222a:	babe                	fsd	fa5,368(sp)
8000222c:	cafe                	sw	t6,84(sp)
8000222e:	babe                	fsd	fa5,368(sp)

80002230 <rvtest_data_end>:
	...

80003000 <begin_regstate>:
80003000:	0080                	addi	s0,sp,64
	...

80003100 <end_regstate>:
80003100:	0004                	0x4
	...

80003110 <begin_signature>:
80003110:	a309                	j	80003612 <_end+0x3e2>
80003112:	6f5c                	flw	fa5,28(a4)

80003114 <signature_x1_0>:
80003114:	deadbeef          	jal	t4,7ffde6fe <CSR_XIP+0x7ffde3ba>

80003118 <tsig_begin_canary>:
80003118:	a309                	j	8000361a <_end+0x3ea>
8000311a:	6f5c                	flw	fa5,28(a4)

8000311c <mtrap_sigptr>:
8000311c:	deadbeef          	jal	t4,7ffde706 <CSR_XIP+0x7ffde3c2>
80003120:	deadbeef          	jal	t4,7ffde70a <CSR_XIP+0x7ffde3c6>
80003124:	deadbeef          	jal	t4,7ffde70e <CSR_XIP+0x7ffde3ca>
80003128:	deadbeef          	jal	t4,7ffde712 <CSR_XIP+0x7ffde3ce>
8000312c:	deadbeef          	jal	t4,7ffde716 <CSR_XIP+0x7ffde3d2>
80003130:	deadbeef          	jal	t4,7ffde71a <CSR_XIP+0x7ffde3d6>
80003134:	deadbeef          	jal	t4,7ffde71e <CSR_XIP+0x7ffde3da>
80003138:	deadbeef          	jal	t4,7ffde722 <CSR_XIP+0x7ffde3de>
8000313c:	deadbeef          	jal	t4,7ffde726 <CSR_XIP+0x7ffde3e2>
80003140:	deadbeef          	jal	t4,7ffde72a <CSR_XIP+0x7ffde3e6>
80003144:	deadbeef          	jal	t4,7ffde72e <CSR_XIP+0x7ffde3ea>
80003148:	deadbeef          	jal	t4,7ffde732 <CSR_XIP+0x7ffde3ee>
8000314c:	deadbeef          	jal	t4,7ffde736 <CSR_XIP+0x7ffde3f2>
80003150:	deadbeef          	jal	t4,7ffde73a <CSR_XIP+0x7ffde3f6>
80003154:	deadbeef          	jal	t4,7ffde73e <CSR_XIP+0x7ffde3fa>
80003158:	deadbeef          	jal	t4,7ffde742 <CSR_XIP+0x7ffde3fe>
8000315c:	deadbeef          	jal	t4,7ffde746 <CSR_XIP+0x7ffde402>
80003160:	deadbeef          	jal	t4,7ffde74a <CSR_XIP+0x7ffde406>
80003164:	deadbeef          	jal	t4,7ffde74e <CSR_XIP+0x7ffde40a>
80003168:	deadbeef          	jal	t4,7ffde752 <CSR_XIP+0x7ffde40e>
8000316c:	deadbeef          	jal	t4,7ffde756 <CSR_XIP+0x7ffde412>
80003170:	deadbeef          	jal	t4,7ffde75a <CSR_XIP+0x7ffde416>
80003174:	deadbeef          	jal	t4,7ffde75e <CSR_XIP+0x7ffde41a>
80003178:	deadbeef          	jal	t4,7ffde762 <CSR_XIP+0x7ffde41e>
8000317c:	deadbeef          	jal	t4,7ffde766 <CSR_XIP+0x7ffde422>
80003180:	deadbeef          	jal	t4,7ffde76a <CSR_XIP+0x7ffde426>
80003184:	deadbeef          	jal	t4,7ffde76e <CSR_XIP+0x7ffde42a>
80003188:	deadbeef          	jal	t4,7ffde772 <CSR_XIP+0x7ffde42e>
8000318c:	deadbeef          	jal	t4,7ffde776 <CSR_XIP+0x7ffde432>
80003190:	deadbeef          	jal	t4,7ffde77a <CSR_XIP+0x7ffde436>
80003194:	deadbeef          	jal	t4,7ffde77e <CSR_XIP+0x7ffde43a>
80003198:	deadbeef          	jal	t4,7ffde782 <CSR_XIP+0x7ffde43e>
8000319c:	deadbeef          	jal	t4,7ffde786 <CSR_XIP+0x7ffde442>
800031a0:	deadbeef          	jal	t4,7ffde78a <CSR_XIP+0x7ffde446>
800031a4:	deadbeef          	jal	t4,7ffde78e <CSR_XIP+0x7ffde44a>
800031a8:	deadbeef          	jal	t4,7ffde792 <CSR_XIP+0x7ffde44e>
800031ac:	deadbeef          	jal	t4,7ffde796 <CSR_XIP+0x7ffde452>
800031b0:	deadbeef          	jal	t4,7ffde79a <CSR_XIP+0x7ffde456>
800031b4:	deadbeef          	jal	t4,7ffde79e <CSR_XIP+0x7ffde45a>
800031b8:	deadbeef          	jal	t4,7ffde7a2 <CSR_XIP+0x7ffde45e>
800031bc:	deadbeef          	jal	t4,7ffde7a6 <CSR_XIP+0x7ffde462>
800031c0:	deadbeef          	jal	t4,7ffde7aa <CSR_XIP+0x7ffde466>
800031c4:	deadbeef          	jal	t4,7ffde7ae <CSR_XIP+0x7ffde46a>
800031c8:	deadbeef          	jal	t4,7ffde7b2 <CSR_XIP+0x7ffde46e>
800031cc:	deadbeef          	jal	t4,7ffde7b6 <CSR_XIP+0x7ffde472>
800031d0:	deadbeef          	jal	t4,7ffde7ba <CSR_XIP+0x7ffde476>
800031d4:	deadbeef          	jal	t4,7ffde7be <CSR_XIP+0x7ffde47a>
800031d8:	deadbeef          	jal	t4,7ffde7c2 <CSR_XIP+0x7ffde47e>
800031dc:	deadbeef          	jal	t4,7ffde7c6 <CSR_XIP+0x7ffde482>
800031e0:	deadbeef          	jal	t4,7ffde7ca <CSR_XIP+0x7ffde486>
800031e4:	deadbeef          	jal	t4,7ffde7ce <CSR_XIP+0x7ffde48a>
800031e8:	deadbeef          	jal	t4,7ffde7d2 <CSR_XIP+0x7ffde48e>
800031ec:	deadbeef          	jal	t4,7ffde7d6 <CSR_XIP+0x7ffde492>
800031f0:	deadbeef          	jal	t4,7ffde7da <CSR_XIP+0x7ffde496>
800031f4:	deadbeef          	jal	t4,7ffde7de <CSR_XIP+0x7ffde49a>
800031f8:	deadbeef          	jal	t4,7ffde7e2 <CSR_XIP+0x7ffde49e>
800031fc:	deadbeef          	jal	t4,7ffde7e6 <CSR_XIP+0x7ffde4a2>
80003200:	deadbeef          	jal	t4,7ffde7ea <CSR_XIP+0x7ffde4a6>
80003204:	deadbeef          	jal	t4,7ffde7ee <CSR_XIP+0x7ffde4aa>
80003208:	deadbeef          	jal	t4,7ffde7f2 <CSR_XIP+0x7ffde4ae>
8000320c:	deadbeef          	jal	t4,7ffde7f6 <CSR_XIP+0x7ffde4b2>
80003210:	deadbeef          	jal	t4,7ffde7fa <CSR_XIP+0x7ffde4b6>
80003214:	deadbeef          	jal	t4,7ffde7fe <CSR_XIP+0x7ffde4ba>
80003218:	deadbeef          	jal	t4,7ffde802 <CSR_XIP+0x7ffde4be>

8000321c <tsig_end_canary>:
8000321c:	a309                	j	8000371e <_end+0x4ee>
8000321e:	6f5c                	flw	fa5,28(a4)

80003220 <sig_end_canary>:
80003220:	a309                	j	80003722 <_end+0x4f2>
80003222:	6f5c                	flw	fa5,28(a4)

80003224 <rvtest_sig_end>:
	...

Disassembly of section .riscv.attributes:

00000000 <.riscv.attributes>:
   0:	2641                	jal	380 <CSR_XIP+0x3c>
   2:	0000                	unimp
   4:	7200                	flw	fs0,32(a2)
   6:	7369                	lui	t1,0xffffa
   8:	01007663          	bgeu	zero,a6,14 <offset+0x10>
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
   0:	000000c3          	fmadd.s	ft1,ft0,ft0,ft0,rne
   4:	00850003          	lb	zero,8(a0)
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
  78:	6d00                	flw	fs0,24(a0)
  7a:	7369                	lui	t1,0xffffa
  7c:	6c61                	lui	s8,0x18
  7e:	6769                	lui	a4,0x1a
  80:	2d6e                	fld	fs10,216(sp)
  82:	616a                	flw	ft2,152(sp)
  84:	2d6c                	fld	fa1,216(a0)
  86:	3130                	fld	fa2,96(a0)
  88:	532e                	lw	t1,232(sp)
  8a:	0100                	addi	s0,sp,128
  8c:	0000                	unimp
  8e:	0000                	unimp
  90:	0205                	addi	tp,tp,1
  92:	0000                	unimp
  94:	8000                	0x8000
  96:	03011903          	lh	s2,48(sp)
  9a:	0908                	addi	a0,sp,144
  9c:	0114                	addi	a3,sp,128
  9e:	0301                	addi	t1,t1,0
  a0:	0905                	addi	s2,s2,1
  a2:	0008                	0x8
  a4:	0301                	addi	t1,t1,0
  a6:	0904                	addi	s1,sp,144
  a8:	0250                	addi	a2,sp,260
  aa:	0301                	addi	t1,t1,0
  ac:	0901                	addi	s2,s2,0
  ae:	05a8                	addi	a0,sp,712
  b0:	0901                	addi	s2,s2,0
  b2:	0010                	0x10
  b4:	0100                	addi	s0,sp,128
  b6:	0001                	nop
  b8:	0205                	addi	tp,tp,1
  ba:	2040                	fld	fs0,128(s0)
  bc:	8000                	0x8000
  be:	09012d03          	lw	s10,144(sp)
  c2:	11f0                	addi	a2,sp,236
  c4:	0100                	addi	s0,sp,128
  c6:	01              	Address 0x00000000000000c6 is out of bounds.


Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	001e                	c.slli	zero,0x7
   2:	0000                	unimp
   4:	0002                	c.slli64	zero
   6:	0000                	unimp
   8:	0000                	unimp
   a:	0104                	addi	s1,sp,128
	...
  18:	0000006f          	j	18 <offset+0x14>
  1c:	00cd                	addi	ra,ra,19
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
  14:	0924                	addi	s1,sp,152
  16:	0000                	unimp
  18:	2000                	fld	fs0,0(s0)
  1a:	8000                	0x8000
  1c:	1230                	addi	a2,sp,296
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
  5c:	73696d2f          	0x73696d2f
  60:	6c61                	lui	s8,0x18
  62:	6769                	lui	a4,0x1a
  64:	2d6e                	fld	fs10,216(sp)
  66:	616a                	flw	ft2,152(sp)
  68:	2d6c                	fld	fa1,216(a0)
  6a:	3130                	fld	fa2,96(a0)
  6c:	532e                	lw	t1,232(sp)
  6e:	2f00                	fld	fs0,24(a4)
  70:	6f68                	flw	fa0,92(a4)
  72:	656d                	lui	a0,0x1b
  74:	766f6c2f          	0x766f6c2f
  78:	7369                	lui	t1,0xffffa
  7a:	7365442f          	0x7365442f
  7e:	706f746b          	0x706f746b
  82:	5669522f          	0x5669522f
  86:	7265                	lui	tp,0xffff9
  88:	635f 726f 2f65      	0x2f65726f635f
  8e:	6972                	flw	fs2,28(sp)
  90:	666f6373          	csrrsi	t1,0x666,30
  94:	7369722f          	0x7369722f
  98:	5f666f63          	bltu	a2,s6,696 <CSR_XIP+0x352>
  9c:	6b726f77          	0x6b726f77
  a0:	3376722f          	0x3376722f
  a4:	6932                	flw	fs2,12(sp)
  a6:	6d5f 702f 6972      	0x6972702f6d5f
  ac:	6976                	flw	fs2,92(sp)
  ae:	656c                	flw	fa1,76(a0)
  b0:	732f6567          	0x732f6567
  b4:	6372                	flw	ft6,28(sp)
  b6:	73696d2f          	0x73696d2f
  ba:	6c61                	lui	s8,0x18
  bc:	6769                	lui	a4,0x1a
  be:	2d6e                	fld	fs10,216(sp)
  c0:	616a                	flw	ft2,152(sp)
  c2:	2d6c                	fld	fa1,216(a0)
  c4:	3130                	fld	fa2,96(a0)
  c6:	532e                	lw	t1,232(sp)
  c8:	7475642f          	0x7475642f
  cc:	4700                	lw	s0,8(a4)
  ce:	554e                	lw	a0,240(sp)
  d0:	4120                	lw	s0,64(a0)
  d2:	2e322053          	0x2e322053
  d6:	          	snez	a0,zero

Disassembly of section .debug_ranges:

00000000 <.debug_ranges>:
   0:	ffff                	0xffff
   2:	ffff                	0xffff
   4:	0000                	unimp
   6:	0000                	unimp
   8:	0000                	unimp
   a:	8000                	0x8000
   c:	0924                	addi	s1,sp,152
   e:	8000                	0x8000
  10:	2000                	fld	fs0,0(s0)
  12:	8000                	0x8000
  14:	3230                	fld	fa2,96(a2)
  16:	8000                	0x8000
	...
