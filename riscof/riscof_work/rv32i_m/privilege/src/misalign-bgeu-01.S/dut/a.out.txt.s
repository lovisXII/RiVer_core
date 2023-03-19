
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
80000018:	00001e97          	auipc	t4,0x1
8000001c:	9a8e8e93          	addi	t4,t4,-1624 # 800009c0 <Mtrampoline>
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
80000090:	00001f97          	auipc	t6,0x1
80000094:	8d0f8f93          	addi	t6,t6,-1840 # 80000960 <cleanup_epilogs>
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
8000011c:	55555537          	lui	a0,0x55555
80000120:	55550513          	addi	a0,a0,1365 # 55555555 <CSR_XIP+0x55555211>
80000124:	200005b7          	lui	a1,0x20000
80000128:	00000113          	li	sp,0
8000012c:	0090006f          	j	80000934 <inst_0+0x818>
80000130:	0000                	unimp
80000132:	00110113          	addi	sp,sp,1
80000136:	0170006f          	j	8000094c <inst_0+0x830>
8000013a:	0000                	unimp
8000013c:	00000013          	nop
80000140:	00000013          	nop
80000144:	00000013          	nop
80000148:	00000013          	nop
8000014c:	00000013          	nop
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
80000344:	00000013          	nop
80000348:	00000013          	nop
8000034c:	00000013          	nop
80000350:	00000013          	nop
80000354:	00000013          	nop
80000358:	00000013          	nop
8000035c:	00000013          	nop
80000360:	00000013          	nop
80000364:	00000013          	nop
80000368:	00000013          	nop
8000036c:	00000013          	nop
80000370:	00000013          	nop
80000374:	00000013          	nop
80000378:	00000013          	nop
8000037c:	00000013          	nop
80000380:	00000013          	nop
80000384:	00000013          	nop
80000388:	00000013          	nop
8000038c:	00000013          	nop
80000390:	00000013          	nop
80000394:	00000013          	nop
80000398:	00000013          	nop
8000039c:	00000013          	nop
800003a0:	00000013          	nop
800003a4:	00000013          	nop
800003a8:	00000013          	nop
800003ac:	00000013          	nop
800003b0:	00000013          	nop
800003b4:	00000013          	nop
800003b8:	00000013          	nop
800003bc:	00000013          	nop
800003c0:	00000013          	nop
800003c4:	00000013          	nop
800003c8:	00000013          	nop
800003cc:	00000013          	nop
800003d0:	00000013          	nop
800003d4:	00000013          	nop
800003d8:	00000013          	nop
800003dc:	00000013          	nop
800003e0:	00000013          	nop
800003e4:	00000013          	nop
800003e8:	00000013          	nop
800003ec:	00000013          	nop
800003f0:	00000013          	nop
800003f4:	00000013          	nop
800003f8:	00000013          	nop
800003fc:	00000013          	nop
80000400:	00000013          	nop
80000404:	00000013          	nop
80000408:	00000013          	nop
8000040c:	00000013          	nop
80000410:	00000013          	nop
80000414:	00000013          	nop
80000418:	00000013          	nop
8000041c:	00000013          	nop
80000420:	00000013          	nop
80000424:	00000013          	nop
80000428:	00000013          	nop
8000042c:	00000013          	nop
80000430:	00000013          	nop
80000434:	00000013          	nop
80000438:	00000013          	nop
8000043c:	00000013          	nop
80000440:	00000013          	nop
80000444:	00000013          	nop
80000448:	00000013          	nop
8000044c:	00000013          	nop
80000450:	00000013          	nop
80000454:	00000013          	nop
80000458:	00000013          	nop
8000045c:	00000013          	nop
80000460:	00000013          	nop
80000464:	00000013          	nop
80000468:	00000013          	nop
8000046c:	00000013          	nop
80000470:	00000013          	nop
80000474:	00000013          	nop
80000478:	00000013          	nop
8000047c:	00000013          	nop
80000480:	00000013          	nop
80000484:	00000013          	nop
80000488:	00000013          	nop
8000048c:	00000013          	nop
80000490:	00000013          	nop
80000494:	00000013          	nop
80000498:	00000013          	nop
8000049c:	00000013          	nop
800004a0:	00000013          	nop
800004a4:	00000013          	nop
800004a8:	00000013          	nop
800004ac:	00000013          	nop
800004b0:	00000013          	nop
800004b4:	00000013          	nop
800004b8:	00000013          	nop
800004bc:	00000013          	nop
800004c0:	00000013          	nop
800004c4:	00000013          	nop
800004c8:	00000013          	nop
800004cc:	00000013          	nop
800004d0:	00000013          	nop
800004d4:	00000013          	nop
800004d8:	00000013          	nop
800004dc:	00000013          	nop
800004e0:	00000013          	nop
800004e4:	00000013          	nop
800004e8:	00000013          	nop
800004ec:	00000013          	nop
800004f0:	00000013          	nop
800004f4:	00000013          	nop
800004f8:	00000013          	nop
800004fc:	00000013          	nop
80000500:	00000013          	nop
80000504:	00000013          	nop
80000508:	00000013          	nop
8000050c:	00000013          	nop
80000510:	00000013          	nop
80000514:	00000013          	nop
80000518:	00000013          	nop
8000051c:	00000013          	nop
80000520:	00000013          	nop
80000524:	00000013          	nop
80000528:	00000013          	nop
8000052c:	00000013          	nop
80000530:	00000013          	nop
80000534:	00000013          	nop
80000538:	00000013          	nop
8000053c:	00000013          	nop
80000540:	00000013          	nop
80000544:	00000013          	nop
80000548:	00000013          	nop
8000054c:	00000013          	nop
80000550:	00000013          	nop
80000554:	00000013          	nop
80000558:	00000013          	nop
8000055c:	00000013          	nop
80000560:	00000013          	nop
80000564:	00000013          	nop
80000568:	00000013          	nop
8000056c:	00000013          	nop
80000570:	00000013          	nop
80000574:	00000013          	nop
80000578:	00000013          	nop
8000057c:	00000013          	nop
80000580:	00000013          	nop
80000584:	00000013          	nop
80000588:	00000013          	nop
8000058c:	00000013          	nop
80000590:	00000013          	nop
80000594:	00000013          	nop
80000598:	00000013          	nop
8000059c:	00000013          	nop
800005a0:	00000013          	nop
800005a4:	00000013          	nop
800005a8:	00000013          	nop
800005ac:	00000013          	nop
800005b0:	00000013          	nop
800005b4:	00000013          	nop
800005b8:	00000013          	nop
800005bc:	00000013          	nop
800005c0:	00000013          	nop
800005c4:	00000013          	nop
800005c8:	00000013          	nop
800005cc:	00000013          	nop
800005d0:	00000013          	nop
800005d4:	00000013          	nop
800005d8:	00000013          	nop
800005dc:	00000013          	nop
800005e0:	00000013          	nop
800005e4:	00000013          	nop
800005e8:	00000013          	nop
800005ec:	00000013          	nop
800005f0:	00000013          	nop
800005f4:	00000013          	nop
800005f8:	00000013          	nop
800005fc:	00000013          	nop
80000600:	00000013          	nop
80000604:	00000013          	nop
80000608:	00000013          	nop
8000060c:	00000013          	nop
80000610:	00000013          	nop
80000614:	00000013          	nop
80000618:	00000013          	nop
8000061c:	00000013          	nop
80000620:	00000013          	nop
80000624:	00000013          	nop
80000628:	00000013          	nop
8000062c:	00000013          	nop
80000630:	00000013          	nop
80000634:	00000013          	nop
80000638:	00000013          	nop
8000063c:	00000013          	nop
80000640:	00000013          	nop
80000644:	00000013          	nop
80000648:	00000013          	nop
8000064c:	00000013          	nop
80000650:	00000013          	nop
80000654:	00000013          	nop
80000658:	00000013          	nop
8000065c:	00000013          	nop
80000660:	00000013          	nop
80000664:	00000013          	nop
80000668:	00000013          	nop
8000066c:	00000013          	nop
80000670:	00000013          	nop
80000674:	00000013          	nop
80000678:	00000013          	nop
8000067c:	00000013          	nop
80000680:	00000013          	nop
80000684:	00000013          	nop
80000688:	00000013          	nop
8000068c:	00000013          	nop
80000690:	00000013          	nop
80000694:	00000013          	nop
80000698:	00000013          	nop
8000069c:	00000013          	nop
800006a0:	00000013          	nop
800006a4:	00000013          	nop
800006a8:	00000013          	nop
800006ac:	00000013          	nop
800006b0:	00000013          	nop
800006b4:	00000013          	nop
800006b8:	00000013          	nop
800006bc:	00000013          	nop
800006c0:	00000013          	nop
800006c4:	00000013          	nop
800006c8:	00000013          	nop
800006cc:	00000013          	nop
800006d0:	00000013          	nop
800006d4:	00000013          	nop
800006d8:	00000013          	nop
800006dc:	00000013          	nop
800006e0:	00000013          	nop
800006e4:	00000013          	nop
800006e8:	00000013          	nop
800006ec:	00000013          	nop
800006f0:	00000013          	nop
800006f4:	00000013          	nop
800006f8:	00000013          	nop
800006fc:	00000013          	nop
80000700:	00000013          	nop
80000704:	00000013          	nop
80000708:	00000013          	nop
8000070c:	00000013          	nop
80000710:	00000013          	nop
80000714:	00000013          	nop
80000718:	00000013          	nop
8000071c:	00000013          	nop
80000720:	00000013          	nop
80000724:	00000013          	nop
80000728:	00000013          	nop
8000072c:	00000013          	nop
80000730:	00000013          	nop
80000734:	00000013          	nop
80000738:	00000013          	nop
8000073c:	00000013          	nop
80000740:	00000013          	nop
80000744:	00000013          	nop
80000748:	00000013          	nop
8000074c:	00000013          	nop
80000750:	00000013          	nop
80000754:	00000013          	nop
80000758:	00000013          	nop
8000075c:	00000013          	nop
80000760:	00000013          	nop
80000764:	00000013          	nop
80000768:	00000013          	nop
8000076c:	00000013          	nop
80000770:	00000013          	nop
80000774:	00000013          	nop
80000778:	00000013          	nop
8000077c:	00000013          	nop
80000780:	00000013          	nop
80000784:	00000013          	nop
80000788:	00000013          	nop
8000078c:	00000013          	nop
80000790:	00000013          	nop
80000794:	00000013          	nop
80000798:	00000013          	nop
8000079c:	00000013          	nop
800007a0:	00000013          	nop
800007a4:	00000013          	nop
800007a8:	00000013          	nop
800007ac:	00000013          	nop
800007b0:	00000013          	nop
800007b4:	00000013          	nop
800007b8:	00000013          	nop
800007bc:	00000013          	nop
800007c0:	00000013          	nop
800007c4:	00000013          	nop
800007c8:	00000013          	nop
800007cc:	00000013          	nop
800007d0:	00000013          	nop
800007d4:	00000013          	nop
800007d8:	00000013          	nop
800007dc:	00000013          	nop
800007e0:	00000013          	nop
800007e4:	00000013          	nop
800007e8:	00000013          	nop
800007ec:	00000013          	nop
800007f0:	00000013          	nop
800007f4:	00000013          	nop
800007f8:	00000013          	nop
800007fc:	00000013          	nop
80000800:	00000013          	nop
80000804:	00000013          	nop
80000808:	00000013          	nop
8000080c:	00000013          	nop
80000810:	00000013          	nop
80000814:	00000013          	nop
80000818:	00000013          	nop
8000081c:	00000013          	nop
80000820:	00000013          	nop
80000824:	00000013          	nop
80000828:	00000013          	nop
8000082c:	00000013          	nop
80000830:	00000013          	nop
80000834:	00000013          	nop
80000838:	00000013          	nop
8000083c:	00000013          	nop
80000840:	00000013          	nop
80000844:	00000013          	nop
80000848:	00000013          	nop
8000084c:	00000013          	nop
80000850:	00000013          	nop
80000854:	00000013          	nop
80000858:	00000013          	nop
8000085c:	00000013          	nop
80000860:	00000013          	nop
80000864:	00000013          	nop
80000868:	00000013          	nop
8000086c:	00000013          	nop
80000870:	00000013          	nop
80000874:	00000013          	nop
80000878:	00000013          	nop
8000087c:	00000013          	nop
80000880:	00000013          	nop
80000884:	00000013          	nop
80000888:	00000013          	nop
8000088c:	00000013          	nop
80000890:	00000013          	nop
80000894:	00000013          	nop
80000898:	00000013          	nop
8000089c:	00000013          	nop
800008a0:	00000013          	nop
800008a4:	00000013          	nop
800008a8:	00000013          	nop
800008ac:	00000013          	nop
800008b0:	00000013          	nop
800008b4:	00000013          	nop
800008b8:	00000013          	nop
800008bc:	00000013          	nop
800008c0:	00000013          	nop
800008c4:	00000013          	nop
800008c8:	00000013          	nop
800008cc:	00000013          	nop
800008d0:	00000013          	nop
800008d4:	00000013          	nop
800008d8:	00000013          	nop
800008dc:	00000013          	nop
800008e0:	00000013          	nop
800008e4:	00000013          	nop
800008e8:	00000013          	nop
800008ec:	00000013          	nop
800008f0:	00000013          	nop
800008f4:	00000013          	nop
800008f8:	00000013          	nop
800008fc:	00000013          	nop
80000900:	00000013          	nop
80000904:	00000013          	nop
80000908:	00000013          	nop
8000090c:	00000013          	nop
80000910:	00000013          	nop
80000914:	00000013          	nop
80000918:	00000013          	nop
8000091c:	00000013          	nop
80000920:	00000013          	nop
80000924:	00000013          	nop
80000928:	00000013          	nop
8000092c:	00000013          	nop
80000930:	00000013          	nop
80000934:	feb57f63          	bgeu	a0,a1,80000132 <inst_0+0x16>
80000938:	00210113          	addi	sp,sp,2
8000093c:	0100006f          	j	8000094c <inst_0+0x830>
80000940:	0000                	unimp
80000942:	00310113          	addi	sp,sp,3
80000946:	0060006f          	j	8000094c <inst_0+0x830>
8000094a:	0000                	unimp
8000094c:	0020a023          	sw	sp,0(ra) # 80003114 <signature_x1_0>

80000950 <rvtest_code_end>:
80000950:	0000100f          	fence.i
80000954:	00000397          	auipc	t2,0x0
80000958:	30002ef3          	csrr	t4,mstatus
8000095c:	0000100f          	fence.i

80000960 <cleanup_epilogs>:
80000960:	34002373          	csrr	t1,mscratch

80000964 <resto_Medeleg>:
80000964:	fe032383          	lw	t2,-32(t1)

80000968 <resto_Mscratch>:
80000968:	ff832f03          	lw	t5,-8(t1)
8000096c:	340f1073          	csrw	mscratch,t5

80000970 <resto_Mxtvec>:
80000970:	ff032e83          	lw	t4,-16(t1)
80000974:	305e93f3          	csrrw	t2,mtvec,t4
80000978:	ffcefe93          	andi	t4,t4,-4
8000097c:	ffc3f393          	andi	t2,t2,-4
80000980:	027e9063          	bne	t4,t2,800009a0 <rvtest_Mend>

80000984 <resto_Mtramp>:
80000984:	e4430e93          	addi	t4,t1,-444
80000988:	fd832e03          	lw	t3,-40(t1)

8000098c <resto_Mloop>:
8000098c:	000eaf83          	lw	t6,0(t4)
80000990:	01f3a023          	sw	t6,0(t2) # 80000954 <rvtest_code_end+0x4>
80000994:	00438393          	addi	t2,t2,4
80000998:	004e8e93          	addi	t4,t4,4
8000099c:	ffc3c8e3          	blt	t2,t3,8000098c <resto_Mloop>

800009a0 <rvtest_Mend>:
800009a0:	5740006f          	j	80000f14 <exit_cleanup>
800009a4:	00000013          	nop
800009a8:	00000013          	nop
800009ac:	00000013          	nop
800009b0:	00000013          	nop
800009b4:	00000013          	nop
800009b8:	00000013          	nop
800009bc:	00000013          	nop

800009c0 <Mtrampoline>:
800009c0:	0800006f          	j	80000a40 <trap_Mhandler>
800009c4:	0880006f          	j	80000a4c <trap_Mhandler+0xc>
800009c8:	0900006f          	j	80000a58 <trap_Mhandler+0x18>
800009cc:	0980006f          	j	80000a64 <trap_Mhandler+0x24>
800009d0:	0a00006f          	j	80000a70 <trap_Mhandler+0x30>
800009d4:	0a80006f          	j	80000a7c <trap_Mhandler+0x3c>
800009d8:	0b00006f          	j	80000a88 <trap_Mhandler+0x48>
800009dc:	0b80006f          	j	80000a94 <trap_Mhandler+0x54>
800009e0:	0c00006f          	j	80000aa0 <trap_Mhandler+0x60>
800009e4:	0c80006f          	j	80000aac <trap_Mhandler+0x6c>
800009e8:	0d00006f          	j	80000ab8 <trap_Mhandler+0x78>
800009ec:	0d80006f          	j	80000ac4 <trap_Mhandler+0x84>
800009f0:	0e00006f          	j	80000ad0 <trap_Mhandler+0x90>
800009f4:	0e80006f          	j	80000adc <trap_Mhandler+0x9c>
800009f8:	0f00006f          	j	80000ae8 <trap_Mhandler+0xa8>
800009fc:	0f80006f          	j	80000af4 <trap_Mhandler+0xb4>
80000a00:	1000006f          	j	80000b00 <rvtest_Mendtest>
80000a04:	0fc0006f          	j	80000b00 <rvtest_Mendtest>
80000a08:	0f80006f          	j	80000b00 <rvtest_Mendtest>
80000a0c:	0f40006f          	j	80000b00 <rvtest_Mendtest>
80000a10:	0f00006f          	j	80000b00 <rvtest_Mendtest>
80000a14:	0ec0006f          	j	80000b00 <rvtest_Mendtest>
80000a18:	0e80006f          	j	80000b00 <rvtest_Mendtest>
80000a1c:	0e40006f          	j	80000b00 <rvtest_Mendtest>
80000a20:	0e00006f          	j	80000b00 <rvtest_Mendtest>
80000a24:	0dc0006f          	j	80000b00 <rvtest_Mendtest>
80000a28:	0d80006f          	j	80000b00 <rvtest_Mendtest>
80000a2c:	0d40006f          	j	80000b00 <rvtest_Mendtest>
80000a30:	0d00006f          	j	80000b00 <rvtest_Mendtest>
80000a34:	0cc0006f          	j	80000b00 <rvtest_Mendtest>
80000a38:	0c80006f          	j	80000b00 <rvtest_Mendtest>
80000a3c:	0c40006f          	j	80000b00 <rvtest_Mendtest>

80000a40 <trap_Mhandler>:
80000a40:	34011173          	csrrw	sp,mscratch,sp
80000a44:	01f12c23          	sw	t6,24(sp)
80000a48:	0c400fef          	jal	t6,80000b0c <common_Mhandler>
80000a4c:	34011173          	csrrw	sp,mscratch,sp
80000a50:	01f12c23          	sw	t6,24(sp)
80000a54:	0b800fef          	jal	t6,80000b0c <common_Mhandler>
80000a58:	34011173          	csrrw	sp,mscratch,sp
80000a5c:	01f12c23          	sw	t6,24(sp)
80000a60:	0ac00fef          	jal	t6,80000b0c <common_Mhandler>
80000a64:	34011173          	csrrw	sp,mscratch,sp
80000a68:	01f12c23          	sw	t6,24(sp)
80000a6c:	0a000fef          	jal	t6,80000b0c <common_Mhandler>
80000a70:	34011173          	csrrw	sp,mscratch,sp
80000a74:	01f12c23          	sw	t6,24(sp)
80000a78:	09400fef          	jal	t6,80000b0c <common_Mhandler>
80000a7c:	34011173          	csrrw	sp,mscratch,sp
80000a80:	01f12c23          	sw	t6,24(sp)
80000a84:	08800fef          	jal	t6,80000b0c <common_Mhandler>
80000a88:	34011173          	csrrw	sp,mscratch,sp
80000a8c:	01f12c23          	sw	t6,24(sp)
80000a90:	07c00fef          	jal	t6,80000b0c <common_Mhandler>
80000a94:	34011173          	csrrw	sp,mscratch,sp
80000a98:	01f12c23          	sw	t6,24(sp)
80000a9c:	07000fef          	jal	t6,80000b0c <common_Mhandler>
80000aa0:	34011173          	csrrw	sp,mscratch,sp
80000aa4:	01f12c23          	sw	t6,24(sp)
80000aa8:	06400fef          	jal	t6,80000b0c <common_Mhandler>
80000aac:	34011173          	csrrw	sp,mscratch,sp
80000ab0:	01f12c23          	sw	t6,24(sp)
80000ab4:	05800fef          	jal	t6,80000b0c <common_Mhandler>
80000ab8:	34011173          	csrrw	sp,mscratch,sp
80000abc:	01f12c23          	sw	t6,24(sp)
80000ac0:	04c00fef          	jal	t6,80000b0c <common_Mhandler>
80000ac4:	34011173          	csrrw	sp,mscratch,sp
80000ac8:	01f12c23          	sw	t6,24(sp)
80000acc:	04000fef          	jal	t6,80000b0c <common_Mhandler>
80000ad0:	34011173          	csrrw	sp,mscratch,sp
80000ad4:	01f12c23          	sw	t6,24(sp)
80000ad8:	03400fef          	jal	t6,80000b0c <common_Mhandler>
80000adc:	34011173          	csrrw	sp,mscratch,sp
80000ae0:	01f12c23          	sw	t6,24(sp)
80000ae4:	02800fef          	jal	t6,80000b0c <common_Mhandler>
80000ae8:	34011173          	csrrw	sp,mscratch,sp
80000aec:	01f12c23          	sw	t6,24(sp)
80000af0:	01c00fef          	jal	t6,80000b0c <common_Mhandler>
80000af4:	34011173          	csrrw	sp,mscratch,sp
80000af8:	01f12c23          	sw	t6,24(sp)
80000afc:	01000fef          	jal	t6,80000b0c <common_Mhandler>

80000b00 <rvtest_Mendtest>:
80000b00:	00000317          	auipc	t1,0x0
80000b04:	ea030313          	addi	t1,t1,-352 # 800009a0 <rvtest_Mend>
80000b08:	00030067          	jr	t1

80000b0c <common_Mhandler>:
80000b0c:	01e12a23          	sw	t5,20(sp)
80000b10:	34011f73          	csrrw	t5,mscratch,sp
80000b14:	01e12e23          	sw	t5,28(sp)
80000b18:	00000f17          	auipc	t5,0x0
80000b1c:	00cf0f13          	addi	t5,t5,12 # 80000b24 <common_Mentry>
80000b20:	000f0067          	jr	t5

80000b24 <common_Mentry>:
80000b24:	01d12823          	sw	t4,16(sp)
80000b28:	01c12623          	sw	t3,12(sp)
80000b2c:	00712423          	sw	t2,8(sp)
80000b30:	00612223          	sw	t1,4(sp)

80000b34 <Mtrapsig_ptr_upd>:
80000b34:	01000393          	li	t2,16
80000b38:	34202f73          	csrr	t5,mcause
80000b3c:	000f5c63          	bgez	t5,80000b54 <Mxcpt_sig_sv>

80000b40 <Mint_sig_sv>:
80000b40:	001f1e13          	slli	t3,t5,0x1
80000b44:	ff2e0e13          	addi	t3,t3,-14
80000b48:	000e5e63          	bgez	t3,80000b64 <Mtrap_sig_sv>
80000b4c:	00c00393          	li	t2,12
80000b50:	0140006f          	j	80000b64 <Mtrap_sig_sv>

80000b54 <Mxcpt_sig_sv>:
80000b54:	30102373          	csrr	t1,misa
80000b58:	01831313          	slli	t1,t1,0x18
80000b5c:	00035463          	bgez	t1,80000b64 <Mtrap_sig_sv>
80000b60:	01800393          	li	t2,24

80000b64 <Mtrap_sig_sv>:
80000b64:	00001e17          	auipc	t3,0x1
80000b68:	49ce0e13          	addi	t3,t3,1180 # 80002000 <rvtest_trap_sig>
80000b6c:	000e2303          	lw	t1,0(t3)
80000b70:	00730eb3          	add	t4,t1,t2
80000b74:	01de2023          	sw	t4,0(t3)
80000b78:	fe812e03          	lw	t3,-24(sp)

80000b7c <sv_Mvect>:
80000b7c:	41cf8fb3          	sub	t6,t6,t3
80000b80:	004f9f93          	slli	t6,t6,0x4
80000b84:	007fefb3          	or	t6,t6,t2
80000b88:	003f8f93          	addi	t6,t6,3
80000b8c:	01f32023          	sw	t6,0(t1)

80000b90 <sv_Mcause>:
80000b90:	01e32223          	sw	t5,4(t1)
80000b94:	0e0f4c63          	bltz	t5,80000c8c <common_Mint_handler>

80000b98 <common_Mexcpt_handler>:
80000b98:	00ff7f13          	andi	t5,t5,15
80000b9c:	341023f3          	csrr	t2,mepc

80000ba0 <code_adj_Mepc>:
80000ba0:	fffffe17          	auipc	t3,0xfffff
80000ba4:	574e0e13          	addi	t3,t3,1396 # 80000114 <rvtest_code_begin>
80000ba8:	00000f97          	auipc	t6,0x0
80000bac:	da8f8f93          	addi	t6,t6,-600 # 80000950 <rvtest_code_end>
80000bb0:	01f3f463          	bgeu	t2,t6,80000bb8 <data_adj_Mepc>
80000bb4:	01c3fe63          	bgeu	t2,t3,80000bd0 <adj_Mepc>

80000bb8 <data_adj_Mepc>:
80000bb8:	00001e17          	auipc	t3,0x1
80000bbc:	668e0e13          	addi	t3,t3,1640 # 80002220 <rvtest_data_begin>
80000bc0:	00001f97          	auipc	t6,0x1
80000bc4:	670f8f93          	addi	t6,t6,1648 # 80002230 <rvtest_data_end>
80000bc8:	d9f3fce3          	bgeu	t2,t6,80000960 <cleanup_epilogs>
80000bcc:	d9c3eae3          	bltu	t2,t3,80000960 <cleanup_epilogs>

80000bd0 <adj_Mepc>:
80000bd0:	41c38eb3          	sub	t4,t2,t3

80000bd4 <sv_Mepc>:
80000bd4:	01d32423          	sw	t4,8(t1)

80000bd8 <adj_Mepc_rtn>:
80000bd8:	ffc3ff93          	andi	t6,t2,-4
80000bdc:	008f8f93          	addi	t6,t6,8
80000be0:	341f9073          	csrw	mepc,t6
80000be4:	34302ff3          	csrr	t6,mtval

80000be8 <chk_Mtval>:
80000be8:	0000beb7          	lui	t4,0xb
80000bec:	0fbe8e93          	addi	t4,t4,251 # b0fb <CSR_XIP+0xadb7>
80000bf0:	01eedeb3          	srl	t4,t4,t5
80000bf4:	01fe9e93          	slli	t4,t4,0x1f
80000bf8:	040ed863          	bgez	t4,80000c48 <sv_Mtval>

80000bfc <sig_adj_Mtval>:
80000bfc:	00002e17          	auipc	t3,0x2
80000c00:	514e0e13          	addi	t3,t3,1300 # 80003110 <begin_signature>
80000c04:	00002f97          	auipc	t6,0x2
80000c08:	620f8f93          	addi	t6,t6,1568 # 80003224 <rvtest_sig_end>
80000c0c:	01f3f463          	bgeu	t2,t6,80000c14 <code_adj_Mtval>
80000c10:	03c3fa63          	bgeu	t2,t3,80000c44 <adj_Mtval>

80000c14 <code_adj_Mtval>:
80000c14:	fffffe17          	auipc	t3,0xfffff
80000c18:	500e0e13          	addi	t3,t3,1280 # 80000114 <rvtest_code_begin>
80000c1c:	00000f97          	auipc	t6,0x0
80000c20:	d34f8f93          	addi	t6,t6,-716 # 80000950 <rvtest_code_end>
80000c24:	01f3f463          	bgeu	t2,t6,80000c2c <data_adj_Mtval>
80000c28:	01c3fe63          	bgeu	t2,t3,80000c44 <adj_Mtval>

80000c2c <data_adj_Mtval>:
80000c2c:	00001e17          	auipc	t3,0x1
80000c30:	5f4e0e13          	addi	t3,t3,1524 # 80002220 <rvtest_data_begin>
80000c34:	00001f97          	auipc	t6,0x1
80000c38:	5fcf8f93          	addi	t6,t6,1532 # 80002230 <rvtest_data_end>
80000c3c:	d3f3f2e3          	bgeu	t2,t6,80000960 <cleanup_epilogs>
80000c40:	d3c3e0e3          	bltu	t2,t3,80000960 <cleanup_epilogs>

80000c44 <adj_Mtval>:
80000c44:	41cf8fb3          	sub	t6,t6,t3

80000c48 <sv_Mtval>:
80000c48:	01f32623          	sw	t6,12(t1)

80000c4c <chk_Mtrapsig_overrun>:
80000c4c:	00001e17          	auipc	t3,0x1
80000c50:	3b4e0e13          	addi	t3,t3,948 # 80002000 <rvtest_trap_sig>
80000c54:	000e2e03          	lw	t3,0(t3)
80000c58:	00002e97          	auipc	t4,0x2
80000c5c:	4b8e8e93          	addi	t4,t4,1208 # 80003110 <begin_signature>
80000c60:	d1de60e3          	bltu	t3,t4,80000960 <cleanup_epilogs>
80000c64:	10000393          	li	t2,256
80000c68:	0400006f          	j	80000ca8 <spcl_Mhandler>

80000c6c <resto_Mrtn>:
80000c6c:	00412303          	lw	t1,4(sp)
80000c70:	00812383          	lw	t2,8(sp)
80000c74:	00c12e03          	lw	t3,12(sp)
80000c78:	01012e83          	lw	t4,16(sp)
80000c7c:	01412f03          	lw	t5,20(sp)
80000c80:	01812f83          	lw	t6,24(sp)
80000c84:	01c12103          	lw	sp,28(sp)
80000c88:	30200073          	mret

80000c8c <common_Mint_handler>:
80000c8c:	00100e13          	li	t3,1
80000c90:	00ff7393          	andi	t2,t5,15
80000c94:	007e1e33          	sll	t3,t3,t2
80000c98:	304e3ef3          	csrrc	t4,mie,t3
80000c9c:	344e3ef3          	csrrc	t4,mip,t3

80000ca0 <sv_Mip>:
80000ca0:	01d32423          	sw	t4,8(t1)
80000ca4:	00000393          	li	t2,0

80000ca8 <spcl_Mhandler>:
80000ca8:	00000e17          	auipc	t3,0x0
80000cac:	01ce0e13          	addi	t3,t3,28 # 80000cc4 <clrint_Mtbl>
80000cb0:	007e0e33          	add	t3,t3,t2
80000cb4:	003f1393          	slli	t2,t5,0x3
80000cb8:	007e0e33          	add	t3,t3,t2
80000cbc:	000e2e03          	lw	t3,0(t3)

80000cc0 <spcl_Mdispatch>:
80000cc0:	000e0067          	jr	t3

80000cc4 <clrint_Mtbl>:
80000cc4:	0c6c                	addi	a1,sp,540
80000cc6:	8000                	0x8000
80000cc8:	0000                	unimp
80000cca:	0000                	unimp
80000ccc:	0960                	addi	s0,sp,156
80000cce:	8000                	0x8000
80000cd0:	0000                	unimp
80000cd2:	0000                	unimp
80000cd4:	0960                	addi	s0,sp,156
80000cd6:	8000                	0x8000
80000cd8:	0000                	unimp
80000cda:	0000                	unimp
80000cdc:	0ec4                	addi	s1,sp,852
80000cde:	8000                	0x8000
80000ce0:	0000                	unimp
80000ce2:	0000                	unimp
80000ce4:	0c6c                	addi	a1,sp,540
80000ce6:	8000                	0x8000
80000ce8:	0000                	unimp
80000cea:	0000                	unimp
80000cec:	0960                	addi	s0,sp,156
80000cee:	8000                	0x8000
80000cf0:	0000                	unimp
80000cf2:	0000                	unimp
80000cf4:	0960                	addi	s0,sp,156
80000cf6:	8000                	0x8000
80000cf8:	0000                	unimp
80000cfa:	0000                	unimp
80000cfc:	0ed0                	addi	a2,sp,852
80000cfe:	8000                	0x8000
80000d00:	0000                	unimp
80000d02:	0000                	unimp
80000d04:	0c6c                	addi	a1,sp,540
80000d06:	8000                	0x8000
80000d08:	0000                	unimp
80000d0a:	0000                	unimp
80000d0c:	0960                	addi	s0,sp,156
80000d0e:	8000                	0x8000
80000d10:	0000                	unimp
80000d12:	0000                	unimp
80000d14:	0960                	addi	s0,sp,156
80000d16:	8000                	0x8000
80000d18:	0000                	unimp
80000d1a:	0000                	unimp
80000d1c:	0ed4                	addi	a3,sp,852
80000d1e:	8000                	0x8000
80000d20:	0000                	unimp
80000d22:	0000                	unimp
80000d24:	0c6c                	addi	a1,sp,540
80000d26:	8000                	0x8000
80000d28:	0000                	unimp
80000d2a:	0000                	unimp
80000d2c:	0c6c                	addi	a1,sp,540
80000d2e:	8000                	0x8000
80000d30:	0000                	unimp
80000d32:	0000                	unimp
80000d34:	0c6c                	addi	a1,sp,540
80000d36:	8000                	0x8000
80000d38:	0000                	unimp
80000d3a:	0000                	unimp
80000d3c:	0c6c                	addi	a1,sp,540
80000d3e:	8000                	0x8000
80000d40:	0000                	unimp
80000d42:	0000                	unimp
80000d44:	0960                	addi	s0,sp,156
80000d46:	8000                	0x8000
80000d48:	0000                	unimp
80000d4a:	0000                	unimp
80000d4c:	0960                	addi	s0,sp,156
80000d4e:	8000                	0x8000
80000d50:	0000                	unimp
80000d52:	0000                	unimp
80000d54:	0960                	addi	s0,sp,156
80000d56:	8000                	0x8000
80000d58:	0000                	unimp
80000d5a:	0000                	unimp
80000d5c:	0960                	addi	s0,sp,156
80000d5e:	8000                	0x8000
80000d60:	0000                	unimp
80000d62:	0000                	unimp
80000d64:	0960                	addi	s0,sp,156
80000d66:	8000                	0x8000
80000d68:	0000                	unimp
80000d6a:	0000                	unimp
80000d6c:	0960                	addi	s0,sp,156
80000d6e:	8000                	0x8000
80000d70:	0000                	unimp
80000d72:	0000                	unimp
80000d74:	0960                	addi	s0,sp,156
80000d76:	8000                	0x8000
80000d78:	0000                	unimp
80000d7a:	0000                	unimp
80000d7c:	0960                	addi	s0,sp,156
80000d7e:	8000                	0x8000
80000d80:	0000                	unimp
80000d82:	0000                	unimp
80000d84:	0960                	addi	s0,sp,156
80000d86:	8000                	0x8000
80000d88:	0000                	unimp
80000d8a:	0000                	unimp
80000d8c:	0960                	addi	s0,sp,156
80000d8e:	8000                	0x8000
80000d90:	0000                	unimp
80000d92:	0000                	unimp
80000d94:	0960                	addi	s0,sp,156
80000d96:	8000                	0x8000
80000d98:	0000                	unimp
80000d9a:	0000                	unimp
80000d9c:	0960                	addi	s0,sp,156
80000d9e:	8000                	0x8000
80000da0:	0000                	unimp
80000da2:	0000                	unimp
80000da4:	0960                	addi	s0,sp,156
80000da6:	8000                	0x8000
80000da8:	0000                	unimp
80000daa:	0000                	unimp
80000dac:	0960                	addi	s0,sp,156
80000dae:	8000                	0x8000
80000db0:	0000                	unimp
80000db2:	0000                	unimp
80000db4:	0960                	addi	s0,sp,156
80000db6:	8000                	0x8000
80000db8:	0000                	unimp
80000dba:	0000                	unimp
80000dbc:	0960                	addi	s0,sp,156
80000dbe:	8000                	0x8000
80000dc0:	0000                	unimp
	...

80000dc4 <excpt_Mhndlr_tbl>:
80000dc4:	0c6c                	addi	a1,sp,540
80000dc6:	8000                	0x8000
80000dc8:	0000                	unimp
80000dca:	0000                	unimp
80000dcc:	0c6c                	addi	a1,sp,540
80000dce:	8000                	0x8000
80000dd0:	0000                	unimp
80000dd2:	0000                	unimp
80000dd4:	0c6c                	addi	a1,sp,540
80000dd6:	8000                	0x8000
80000dd8:	0000                	unimp
80000dda:	0000                	unimp
80000ddc:	0c6c                	addi	a1,sp,540
80000dde:	8000                	0x8000
80000de0:	0000                	unimp
80000de2:	0000                	unimp
80000de4:	0c6c                	addi	a1,sp,540
80000de6:	8000                	0x8000
80000de8:	0000                	unimp
80000dea:	0000                	unimp
80000dec:	0c6c                	addi	a1,sp,540
80000dee:	8000                	0x8000
80000df0:	0000                	unimp
80000df2:	0000                	unimp
80000df4:	0c6c                	addi	a1,sp,540
80000df6:	8000                	0x8000
80000df8:	0000                	unimp
80000dfa:	0000                	unimp
80000dfc:	0c6c                	addi	a1,sp,540
80000dfe:	8000                	0x8000
80000e00:	0000                	unimp
80000e02:	0000                	unimp
80000e04:	0c6c                	addi	a1,sp,540
80000e06:	8000                	0x8000
80000e08:	0000                	unimp
80000e0a:	0000                	unimp
80000e0c:	0c6c                	addi	a1,sp,540
80000e0e:	8000                	0x8000
80000e10:	0000                	unimp
80000e12:	0000                	unimp
80000e14:	0c6c                	addi	a1,sp,540
80000e16:	8000                	0x8000
80000e18:	0000                	unimp
80000e1a:	0000                	unimp
80000e1c:	0c6c                	addi	a1,sp,540
80000e1e:	8000                	0x8000
80000e20:	0000                	unimp
80000e22:	0000                	unimp
80000e24:	0c6c                	addi	a1,sp,540
80000e26:	8000                	0x8000
80000e28:	0000                	unimp
80000e2a:	0000                	unimp
80000e2c:	0c6c                	addi	a1,sp,540
80000e2e:	8000                	0x8000
80000e30:	0000                	unimp
80000e32:	0000                	unimp
80000e34:	0c6c                	addi	a1,sp,540
80000e36:	8000                	0x8000
80000e38:	0000                	unimp
80000e3a:	0000                	unimp
80000e3c:	0c6c                	addi	a1,sp,540
80000e3e:	8000                	0x8000
80000e40:	0000                	unimp
80000e42:	0000                	unimp
80000e44:	0960                	addi	s0,sp,156
80000e46:	8000                	0x8000
80000e48:	0000                	unimp
80000e4a:	0000                	unimp
80000e4c:	0960                	addi	s0,sp,156
80000e4e:	8000                	0x8000
80000e50:	0000                	unimp
80000e52:	0000                	unimp
80000e54:	0960                	addi	s0,sp,156
80000e56:	8000                	0x8000
80000e58:	0000                	unimp
80000e5a:	0000                	unimp
80000e5c:	0960                	addi	s0,sp,156
80000e5e:	8000                	0x8000
80000e60:	0000                	unimp
80000e62:	0000                	unimp
80000e64:	0960                	addi	s0,sp,156
80000e66:	8000                	0x8000
80000e68:	0000                	unimp
80000e6a:	0000                	unimp
80000e6c:	0960                	addi	s0,sp,156
80000e6e:	8000                	0x8000
80000e70:	0000                	unimp
80000e72:	0000                	unimp
80000e74:	0960                	addi	s0,sp,156
80000e76:	8000                	0x8000
80000e78:	0000                	unimp
80000e7a:	0000                	unimp
80000e7c:	0960                	addi	s0,sp,156
80000e7e:	8000                	0x8000
80000e80:	0000                	unimp
80000e82:	0000                	unimp
80000e84:	0960                	addi	s0,sp,156
80000e86:	8000                	0x8000
80000e88:	0000                	unimp
80000e8a:	0000                	unimp
80000e8c:	0960                	addi	s0,sp,156
80000e8e:	8000                	0x8000
80000e90:	0000                	unimp
80000e92:	0000                	unimp
80000e94:	0960                	addi	s0,sp,156
80000e96:	8000                	0x8000
80000e98:	0000                	unimp
80000e9a:	0000                	unimp
80000e9c:	0960                	addi	s0,sp,156
80000e9e:	8000                	0x8000
80000ea0:	0000                	unimp
80000ea2:	0000                	unimp
80000ea4:	0960                	addi	s0,sp,156
80000ea6:	8000                	0x8000
80000ea8:	0000                	unimp
80000eaa:	0000                	unimp
80000eac:	0960                	addi	s0,sp,156
80000eae:	8000                	0x8000
80000eb0:	0000                	unimp
80000eb2:	0000                	unimp
80000eb4:	0960                	addi	s0,sp,156
80000eb6:	8000                	0x8000
80000eb8:	0000                	unimp
80000eba:	0000                	unimp
80000ebc:	0960                	addi	s0,sp,156
80000ebe:	8000                	0x8000
80000ec0:	0000                	unimp
	...

80000ec4 <Mclr_Msw_int>:
80000ec4:	020003b7          	lui	t2,0x2000
80000ec8:	0003a023          	sw	zero,0(t2) # 2000000 <CSR_XIP+0x1fffcbc>
80000ecc:	da1ff06f          	j	80000c6c <resto_Mrtn>

80000ed0 <Mclr_Mtmr_int>:
80000ed0:	d9dff06f          	j	80000c6c <resto_Mrtn>

80000ed4 <Mclr_Mext_int>:
80000ed4:	01c32623          	sw	t3,12(t1)
80000ed8:	d95ff06f          	j	80000c6c <resto_Mrtn>

80000edc <Mclr_Ssw_int>:
80000edc:	a85ff06f          	j	80000960 <cleanup_epilogs>
80000ee0:	d8dff06f          	j	80000c6c <resto_Mrtn>

80000ee4 <Mclr_Stmr_int>:
80000ee4:	a7dff06f          	j	80000960 <cleanup_epilogs>
80000ee8:	d85ff06f          	j	80000c6c <resto_Mrtn>

80000eec <Mclr_Sext_int>:
80000eec:	a75ff06f          	j	80000960 <cleanup_epilogs>
80000ef0:	01c32623          	sw	t3,12(t1)
80000ef4:	d79ff06f          	j	80000c6c <resto_Mrtn>

80000ef8 <Mclr_Vsw_int>:
80000ef8:	a69ff06f          	j	80000960 <cleanup_epilogs>
80000efc:	d71ff06f          	j	80000c6c <resto_Mrtn>

80000f00 <Mclr_Vtmr_int>:
80000f00:	a61ff06f          	j	80000960 <cleanup_epilogs>
80000f04:	d69ff06f          	j	80000c6c <resto_Mrtn>

80000f08 <Mclr_Vext_int>:
80000f08:	a59ff06f          	j	80000960 <cleanup_epilogs>
80000f0c:	01c32623          	sw	t3,12(t1)
80000f10:	d5dff06f          	j	80000c6c <resto_Mrtn>

80000f14 <exit_cleanup>:
80000f14:	00100093          	li	ra,1

80000f18 <write_tohost>:
80000f18:	00000f17          	auipc	t5,0x0
80000f1c:	0e1f2423          	sw	ra,232(t5) # 80001000 <tohost>
80000f20:	ff9ff06f          	j	80000f18 <write_tohost>
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
   0:	00c4                	addi	s1,sp,68
   2:	0000                	unimp
   4:	00860003          	lb	zero,8(a2)
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
  82:	6762                	flw	fa4,24(sp)
  84:	7565                	lui	a0,0xffff9
  86:	302d                	jal	fffff8b0 <edge2+0xfffff8b1>
  88:	2e31                	jal	3a4 <CSR_XIP+0x60>
  8a:	00010053          	fadd.s	ft0,ft2,ft0,rne
  8e:	0000                	unimp
  90:	0500                	addi	s0,sp,640
  92:	0002                	c.slli64	zero
  94:	0000                	unimp
  96:	0380                	addi	s0,sp,448
  98:	0119                	addi	sp,sp,6
  9a:	14090803          	lb	a6,320(s2)
  9e:	0101                	addi	sp,sp,0
  a0:	08090503          	lb	a0,128(s2)
  a4:	0100                	addi	s0,sp,128
  a6:	34090403          	lb	s0,832(s2)
  aa:	0108                	addi	a0,sp,128
  ac:	c4090103          	lb	sp,-960(s2)
  b0:	0105                	addi	sp,sp,1
  b2:	1009                	c.nop	-30
  b4:	0000                	unimp
  b6:	0101                	addi	sp,sp,0
  b8:	0500                	addi	s0,sp,640
  ba:	4002                	0x4002
  bc:	0020                	addi	s0,sp,8
  be:	0380                	addi	s0,sp,448
  c0:	012d                	addi	sp,sp,11
  c2:	f009                	bnez	s0,ffffffc4 <edge2+0xffffffc5>
  c4:	0011                	c.nop	4
  c6:	0101                	addi	sp,sp,0

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	001e                	c.slli	zero,0x7
   2:	0000                	unimp
   4:	0002                	c.slli64	zero
   6:	0000                	unimp
   8:	0000                	unimp
   a:	0104                	addi	s1,sp,128
	...
  18:	0070                	addi	a2,sp,12
  1a:	0000                	unimp
  1c:	000000cf          	fnmadd.s	ft1,ft0,ft0,ft0,rne
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
  14:	0f24                	addi	s1,sp,920
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
  66:	6762                	flw	fa4,24(sp)
  68:	7565                	lui	a0,0xffff9
  6a:	302d                	jal	fffff894 <edge2+0xfffff895>
  6c:	2e31                	jal	388 <CSR_XIP+0x44>
  6e:	682f0053          	0x682f0053
  72:	2f656d6f          	jal	s10,56368 <CSR_XIP+0x56024>
  76:	6f6c                	flw	fa1,92(a4)
  78:	6976                	flw	fs2,92(sp)
  7a:	65442f73          	csrrs	t5,0x654,s0
  7e:	6f746b73          	csrrsi	s6,0x6f7,8
  82:	2f70                	fld	fa2,216(a4)
  84:	6952                	flw	fs2,20(sp)
  86:	6556                	flw	fa0,84(sp)
  88:	5f72                	lw	t5,60(sp)
  8a:	65726f63          	bltu	tp,s7,6e8 <CSR_XIP+0x3a4>
  8e:	7369722f          	0x7369722f
  92:	2f666f63          	bltu	a2,s6,390 <CSR_XIP+0x4c>
  96:	6972                	flw	fs2,28(sp)
  98:	666f6373          	csrrsi	t1,0x666,30
  9c:	775f 726f 2f6b      	0x2f6b726f775f
  a2:	7672                	flw	fa2,60(sp)
  a4:	5f693233          	0x5f693233
  a8:	2f6d                	jal	862 <CSR_XIP+0x51e>
  aa:	7270                	flw	fa2,100(a2)
  ac:	7669                	lui	a2,0xffffa
  ae:	6c69                	lui	s8,0x1a
  b0:	6765                	lui	a4,0x19
  b2:	2f65                	jal	86a <CSR_XIP+0x526>
  b4:	2f637273          	csrrci	tp,0x2f6,6
  b8:	696d                	lui	s2,0x1b
  ba:	696c6173          	csrrsi	sp,0x696,24
  be:	622d6e67          	0x622d6e67
  c2:	2d756567          	0x2d756567
  c6:	3130                	fld	fa2,96(a0)
  c8:	532e                	lw	t1,232(sp)
  ca:	7475642f          	0x7475642f
  ce:	4700                	lw	s0,8(a4)
  d0:	554e                	lw	a0,240(sp)
  d2:	4120                	lw	s0,64(a0)
  d4:	2e322053          	0x2e322053
  d8:	          	snez	a0,zero

Disassembly of section .debug_ranges:

00000000 <.debug_ranges>:
   0:	ffff                	0xffff
   2:	ffff                	0xffff
   4:	0000                	unimp
   6:	0000                	unimp
   8:	0000                	unimp
   a:	8000                	0x8000
   c:	0f24                	addi	s1,sp,920
   e:	8000                	0x8000
  10:	2000                	fld	fs0,0(s0)
  12:	8000                	0x8000
  14:	3230                	fld	fa2,96(a2)
  16:	8000                	0x8000
	...
