
my.elf:     file format elf32-littleriscv


Disassembly of section .text.init:

80000000 <rvtest_entry_point>:
80000000:	feedc0b7          	lui	ra,0xfeedc
80000004:	ead08093          	addi	ra,ra,-339 # feedbead <imme+0xfeedbeb3>
80000008:	ff76e137          	lui	sp,0xff76e
8000000c:	f5610113          	addi	sp,sp,-170 # ff76df56 <imme+0xff76df5c>
80000010:	7fbb71b7          	lui	gp,0x7fbb7
80000014:	fab18193          	addi	gp,gp,-85 # 7fbb6fab <pos+0x7fbb6f8b>
80000018:	bfddb237          	lui	tp,0xbfddb
8000001c:	7d520213          	addi	tp,tp,2005 # bfddb7d5 <imme+0xbfddb7db>
80000020:	00000297          	auipc	t0,0x0
80000024:	05828293          	addi	t0,t0,88 # 80000078 <rvtest_code_begin>
80000028:	00002317          	auipc	t1,0x2
8000002c:	fe830313          	addi	t1,t1,-24 # 80002010 <rvtest_data_begin>
80000030:	b7fbb3b7          	lui	t2,0xb7fbb
80000034:	6fa38393          	addi	t2,t2,1786 # b7fbb6fa <imme+0xb7fbb700>
80000038:	5bfde437          	lui	s0,0x5bfde
8000003c:	b7d40413          	addi	s0,s0,-1155 # 5bfddb7d <pos+0x5bfddb5d>
80000040:	adfef4b7          	lui	s1,0xadfef
80000044:	dbe48493          	addi	s1,s1,-578 # adfeedbe <imme+0xadfeedc4>
80000048:	56ff7537          	lui	a0,0x56ff7
8000004c:	6df50513          	addi	a0,a0,1759 # 56ff76df <pos+0x56ff76bf>
80000050:	ab7fc5b7          	lui	a1,0xab7fc
80000054:	b6f58593          	addi	a1,a1,-1169 # ab7fbb6f <imme+0xab7fbb75>
80000058:	d5bfe637          	lui	a2,0xd5bfe
8000005c:	db760613          	addi	a2,a2,-585 # d5bfddb7 <imme+0xd5bfddbd>
80000060:	eadff6b7          	lui	a3,0xeadff
80000064:	edb68693          	addi	a3,a3,-293 # eadfeedb <imme+0xeadfeee1>
80000068:	f56ff737          	lui	a4,0xf56ff
8000006c:	76d70713          	addi	a4,a4,1901 # f56ff76d <imme+0xf56ff773>
80000070:	fab807b7          	lui	a5,0xfab80
80000074:	bb678793          	addi	a5,a5,-1098 # fab7fbb6 <imme+0xfab7fbbc>

80000078 <rvtest_code_begin>:
80000078:	00003097          	auipc	ra,0x3
8000007c:	09c08093          	addi	ra,ra,156 # 80003114 <signature_x1_0>

80000080 <inst_0>:
80000080:	80000cb7          	lui	s9,0x80000
80000084:	00008113          	mv	sp,ra
80000088:	dff00613          	li	a2,-513
8000008c:	40c10133          	sub	sp,sp,a2
80000090:	df910fa3          	sb	s9,-513(sp)
80000094:	00000013          	nop
80000098:	00000013          	nop

8000009c <inst_1>:
8000009c:	00000d93          	li	s11,0
800000a0:	00408b13          	addi	s6,ra,4
800000a4:	00200613          	li	a2,2
800000a8:	40cb0b33          	sub	s6,s6,a2
800000ac:	01bb0123          	sb	s11,2(s6)
800000b0:	00000013          	nop
800000b4:	00000013          	nop

800000b8 <inst_2>:
800000b8:	800005b7          	lui	a1,0x80000
800000bc:	fff58593          	addi	a1,a1,-1 # 7fffffff <imme+0x80000005>
800000c0:	00808e93          	addi	t4,ra,8
800000c4:	20000613          	li	a2,512
800000c8:	40ce8eb3          	sub	t4,t4,a2
800000cc:	20be8023          	sb	a1,512(t4)
800000d0:	00000013          	nop
800000d4:	00000013          	nop

800000d8 <inst_3>:
800000d8:	00100f13          	li	t5,1
800000dc:	00c08f93          	addi	t6,ra,12
800000e0:	20000613          	li	a2,512
800000e4:	40cf8fb3          	sub	t6,t6,a2
800000e8:	21ef8023          	sb	t5,512(t6)
800000ec:	00000013          	nop
800000f0:	00000013          	nop

800000f4 <inst_4>:
800000f4:	fffc0e37          	lui	t3,0xfffc0
800000f8:	fffe0e13          	addi	t3,t3,-1 # fffbffff <imme+0xfffc0005>
800000fc:	01008f13          	addi	t5,ra,16
80000100:	00500613          	li	a2,5
80000104:	40cf0f33          	sub	t5,t5,a2
80000108:	01cf02a3          	sb	t3,5(t5)
8000010c:	00000013          	nop
80000110:	00000013          	nop

80000114 <inst_5>:
80000114:	00400ab7          	lui	s5,0x400
80000118:	01608d13          	addi	s10,ra,22
8000011c:	c0000613          	li	a2,-1024
80000120:	40cd0d33          	sub	s10,s10,a2
80000124:	c15d0023          	sb	s5,-1024(s10)
80000128:	00000013          	nop
8000012c:	00000013          	nop

80000130 <inst_6>:
80000130:	ff800eb7          	lui	t4,0xff800
80000134:	fffe8e93          	addi	t4,t4,-1 # ff7fffff <imme+0xff800005>
80000138:	01a08713          	addi	a4,ra,26
8000013c:	00100613          	li	a2,1
80000140:	40c70733          	sub	a4,a4,a2
80000144:	01d700a3          	sb	t4,1(a4)
80000148:	00000013          	nop
8000014c:	00000013          	nop

80000150 <inst_7>:
80000150:	00400c13          	li	s8,4
80000154:	01e08b93          	addi	s7,ra,30
80000158:	ffe00613          	li	a2,-2
8000015c:	40cb8bb3          	sub	s7,s7,a2
80000160:	ff8b8f23          	sb	s8,-2(s7)
80000164:	00000013          	nop
80000168:	00000013          	nop

8000016c <inst_8>:
8000016c:	aaaab237          	lui	tp,0xaaaab
80000170:	aaa20213          	addi	tp,tp,-1366 # aaaaaaaa <imme+0xaaaaaab0>
80000174:	02208493          	addi	s1,ra,34
80000178:	f7f00613          	li	a2,-129
8000017c:	40c484b3          	sub	s1,s1,a2
80000180:	f6448fa3          	sb	tp,-129(s1)
80000184:	00000013          	nop
80000188:	00000013          	nop

8000018c <inst_9>:
8000018c:	ff900393          	li	t2,-7
80000190:	02508293          	addi	t0,ra,37
80000194:	10000613          	li	a2,256
80000198:	40c282b3          	sub	t0,t0,a2
8000019c:	10728023          	sb	t2,256(t0)
800001a0:	00000013          	nop
800001a4:	00000013          	nop

800001a8 <inst_10>:
800001a8:	00000013          	nop
800001ac:	02908e13          	addi	t3,ra,41
800001b0:	00500613          	li	a2,5
800001b4:	40ce0e33          	sub	t3,t3,a2
800001b8:	000e02a3          	sb	zero,5(t3)
800001bc:	00000013          	nop
800001c0:	00000013          	nop

800001c4 <inst_11>:
800001c4:	fe000bb7          	lui	s7,0xfe000
800001c8:	fffb8b93          	addi	s7,s7,-1 # fdffffff <imme+0xfe000005>
800001cc:	02d08193          	addi	gp,ra,45
800001d0:	ff600613          	li	a2,-10
800001d4:	40c181b3          	sub	gp,gp,a2
800001d8:	ff718b23          	sb	s7,-10(gp)
800001dc:	00000013          	nop
800001e0:	00000013          	nop

800001e4 <inst_12>:
800001e4:	ffff0537          	lui	a0,0xffff0
800001e8:	fff50513          	addi	a0,a0,-1 # fffeffff <imme+0xffff0005>
800001ec:	03108a93          	addi	s5,ra,49
800001f0:	ffb00613          	li	a2,-5
800001f4:	40ca8ab3          	sub	s5,s5,a2
800001f8:	feaa8da3          	sb	a0,-5(s5) # 3ffffb <pos+0x3fffdb>
800001fc:	00000013          	nop
80000200:	00000013          	nop

80000204 <inst_13>:
80000204:	00800937          	lui	s2,0x800
80000208:	03708d93          	addi	s11,ra,55
8000020c:	ffc00613          	li	a2,-4
80000210:	40cd8db3          	sub	s11,s11,a2
80000214:	ff2d8e23          	sb	s2,-4(s11)
80000218:	00000013          	nop
8000021c:	00000013          	nop

80000220 <inst_14>:
80000220:	ff0007b7          	lui	a5,0xff000
80000224:	fff78793          	addi	a5,a5,-1 # feffffff <imme+0xff000005>
80000228:	03b08313          	addi	t1,ra,59
8000022c:	00900613          	li	a2,9
80000230:	40c30333          	sub	t1,t1,a2
80000234:	00f304a3          	sb	a5,9(t1)
80000238:	00000013          	nop
8000023c:	00000013          	nop

80000240 <inst_15>:
80000240:	fe000137          	lui	sp,0xfe000
80000244:	fff10113          	addi	sp,sp,-1 # fdffffff <imme+0xfe000005>
80000248:	03f08893          	addi	a7,ra,63
8000024c:	ff600613          	li	a2,-10
80000250:	40c888b3          	sub	a7,a7,a2
80000254:	fe288b23          	sb	sp,-10(a7)
80000258:	00000013          	nop
8000025c:	00000013          	nop

80000260 <inst_16>:
80000260:	200002b7          	lui	t0,0x20000
80000264:	04308c13          	addi	s8,ra,67
80000268:	f7f00613          	li	a2,-129
8000026c:	40cc0c33          	sub	s8,s8,a2
80000270:	f65c0fa3          	sb	t0,-129(s8)
80000274:	00000013          	nop
80000278:	00000013          	nop

8000027c <inst_17>:
8000027c:	ffff86b7          	lui	a3,0xffff8
80000280:	fff68693          	addi	a3,a3,-1 # ffff7fff <imme+0xffff8005>
80000284:	04408593          	addi	a1,ra,68
80000288:	00000613          	li	a2,0
8000028c:	40c585b3          	sub	a1,a1,a2
80000290:	00d58023          	sb	a3,0(a1)
80000294:	00000013          	nop
80000298:	00000013          	nop

8000029c <inst_18>:
8000029c:	00200813          	li	a6,2
800002a0:	04808413          	addi	s0,ra,72
800002a4:	fff00613          	li	a2,-1
800002a8:	40c40433          	sub	s0,s0,a2
800002ac:	ff040fa3          	sb	a6,-1(s0)
800002b0:	00000013          	nop
800002b4:	00000013          	nop

800002b8 <inst_19>:
800002b8:	00800613          	li	a2,8
800002bc:	04c08793          	addi	a5,ra,76
800002c0:	ff900293          	li	t0,-7
800002c4:	405787b3          	sub	a5,a5,t0
800002c8:	fec78ca3          	sb	a2,-7(a5)
800002cc:	00000013          	nop
800002d0:	00000013          	nop
800002d4:	00003117          	auipc	sp,0x3
800002d8:	e9010113          	addi	sp,sp,-368 # 80003164 <signature_x2_0>

800002dc <inst_20>:
800002dc:	01000a13          	li	s4,16
800002e0:	00010213          	mv	tp,sp
800002e4:	ffc00293          	li	t0,-4
800002e8:	40520233          	sub	tp,tp,t0
800002ec:	ff420e23          	sb	s4,-4(tp) # fffffffc <imme+0x2>
800002f0:	00000013          	nop
800002f4:	00000013          	nop

800002f8 <inst_21>:
800002f8:	02000093          	li	ra,32
800002fc:	00410513          	addi	a0,sp,4
80000300:	fff00293          	li	t0,-1
80000304:	40550533          	sub	a0,a0,t0
80000308:	fe150fa3          	sb	ra,-1(a0)
8000030c:	00000013          	nop
80000310:	00000013          	nop

80000314 <inst_22>:
80000314:	04000193          	li	gp,64
80000318:	00810693          	addi	a3,sp,8
8000031c:	00500293          	li	t0,5
80000320:	405686b3          	sub	a3,a3,t0
80000324:	003682a3          	sb	gp,5(a3)
80000328:	00000013          	nop
8000032c:	00000013          	nop

80000330 <inst_23>:
80000330:	08000893          	li	a7,128
80000334:	00c10993          	addi	s3,sp,12
80000338:	c0000293          	li	t0,-1024
8000033c:	405989b3          	sub	s3,s3,t0
80000340:	c1198023          	sb	a7,-1024(s3)
80000344:	00000013          	nop
80000348:	00000013          	nop

8000034c <inst_24>:
8000034c:	10000493          	li	s1,256
80000350:	01010a13          	addi	s4,sp,16
80000354:	00300293          	li	t0,3
80000358:	405a0a33          	sub	s4,s4,t0
8000035c:	009a01a3          	sb	s1,3(s4)
80000360:	00000013          	nop
80000364:	00000013          	nop

80000368 <inst_25>:
80000368:	20000d13          	li	s10,512
8000036c:	01410c93          	addi	s9,sp,20
80000370:	fbf00293          	li	t0,-65
80000374:	405c8cb3          	sub	s9,s9,t0
80000378:	fbac8fa3          	sb	s10,-65(s9) # 7fffffbf <imme+0x7fffffc5>
8000037c:	00000013          	nop
80000380:	00000013          	nop

80000384 <inst_26>:
80000384:	40000b13          	li	s6,1024
80000388:	01810913          	addi	s2,sp,24
8000038c:	3ff00293          	li	t0,1023
80000390:	40590933          	sub	s2,s2,t0
80000394:	3f690fa3          	sb	s6,1023(s2) # 8003ff <pos+0x8003df>
80000398:	00000013          	nop
8000039c:	00000013          	nop

800003a0 <inst_27>:
800003a0:	00001fb7          	lui	t6,0x1
800003a4:	800f8f93          	addi	t6,t6,-2048 # 800 <pos+0x7e0>
800003a8:	01c10393          	addi	t2,sp,28
800003ac:	20000293          	li	t0,512
800003b0:	405383b3          	sub	t2,t2,t0
800003b4:	21f38023          	sb	t6,512(t2)
800003b8:	00000013          	nop
800003bc:	00000013          	nop

800003c0 <inst_28>:
800003c0:	00001737          	lui	a4,0x1
800003c4:	02010813          	addi	a6,sp,32
800003c8:	c0000293          	li	t0,-1024
800003cc:	40580833          	sub	a6,a6,t0
800003d0:	c0e80023          	sb	a4,-1024(a6)
800003d4:	00000013          	nop
800003d8:	00000013          	nop

800003dc <inst_29>:
800003dc:	00002337          	lui	t1,0x2
800003e0:	02410093          	addi	ra,sp,36
800003e4:	00900293          	li	t0,9
800003e8:	405080b3          	sub	ra,ra,t0
800003ec:	006084a3          	sb	t1,9(ra)
800003f0:	00000013          	nop
800003f4:	00000013          	nop

800003f8 <inst_30>:
800003f8:	000049b7          	lui	s3,0x4
800003fc:	02810613          	addi	a2,sp,40
80000400:	00600293          	li	t0,6
80000404:	40560633          	sub	a2,a2,t0
80000408:	01360323          	sb	s3,6(a2)
8000040c:	00000013          	nop
80000410:	00000013          	nop

80000414 <inst_31>:
80000414:	00008437          	lui	s0,0x8
80000418:	02c10d13          	addi	s10,sp,44
8000041c:	00700293          	li	t0,7
80000420:	405d0d33          	sub	s10,s10,t0
80000424:	008d03a3          	sb	s0,7(s10)
80000428:	00000013          	nop
8000042c:	00000013          	nop

80000430 <inst_32>:
80000430:	000105b7          	lui	a1,0x10
80000434:	03010513          	addi	a0,sp,48
80000438:	00900293          	li	t0,9
8000043c:	40550533          	sub	a0,a0,t0
80000440:	00b504a3          	sb	a1,9(a0)
80000444:	00000013          	nop
80000448:	00000013          	nop

8000044c <inst_33>:
8000044c:	000205b7          	lui	a1,0x20
80000450:	03410513          	addi	a0,sp,52
80000454:	ff900293          	li	t0,-7
80000458:	40550533          	sub	a0,a0,t0
8000045c:	feb50ca3          	sb	a1,-7(a0)
80000460:	00000013          	nop
80000464:	00000013          	nop

80000468 <inst_34>:
80000468:	000405b7          	lui	a1,0x40
8000046c:	03810513          	addi	a0,sp,56
80000470:	00300293          	li	t0,3
80000474:	40550533          	sub	a0,a0,t0
80000478:	00b501a3          	sb	a1,3(a0)
8000047c:	00000013          	nop
80000480:	00000013          	nop

80000484 <inst_35>:
80000484:	000805b7          	lui	a1,0x80
80000488:	03c10513          	addi	a0,sp,60
8000048c:	ffc00293          	li	t0,-4
80000490:	40550533          	sub	a0,a0,t0
80000494:	feb50e23          	sb	a1,-4(a0)
80000498:	00000013          	nop
8000049c:	00000013          	nop

800004a0 <inst_36>:
800004a0:	001005b7          	lui	a1,0x100
800004a4:	04010513          	addi	a0,sp,64
800004a8:	7ff00293          	li	t0,2047
800004ac:	40550533          	sub	a0,a0,t0
800004b0:	7eb50fa3          	sb	a1,2047(a0)
800004b4:	00000013          	nop
800004b8:	00000013          	nop

800004bc <inst_37>:
800004bc:	002005b7          	lui	a1,0x200
800004c0:	04410513          	addi	a0,sp,68
800004c4:	ffb00293          	li	t0,-5
800004c8:	40550533          	sub	a0,a0,t0
800004cc:	feb50da3          	sb	a1,-5(a0)
800004d0:	00000013          	nop
800004d4:	00000013          	nop

800004d8 <inst_38>:
800004d8:	bff00593          	li	a1,-1025
800004dc:	04810513          	addi	a0,sp,72
800004e0:	7ff00293          	li	t0,2047
800004e4:	40550533          	sub	a0,a0,t0
800004e8:	7eb50fa3          	sb	a1,2047(a0)
800004ec:	00000013          	nop
800004f0:	00000013          	nop

800004f4 <inst_39>:
800004f4:	fffff5b7          	lui	a1,0xfffff
800004f8:	7ff58593          	addi	a1,a1,2047 # fffff7ff <imme+0xfffff805>
800004fc:	04c10513          	addi	a0,sp,76
80000500:	fbf00293          	li	t0,-65
80000504:	40550533          	sub	a0,a0,t0
80000508:	fab50fa3          	sb	a1,-65(a0)
8000050c:	00000013          	nop
80000510:	00000013          	nop

80000514 <inst_40>:
80000514:	fffff5b7          	lui	a1,0xfffff
80000518:	fff58593          	addi	a1,a1,-1 # ffffefff <imme+0xfffff005>
8000051c:	05010513          	addi	a0,sp,80
80000520:	eff00293          	li	t0,-257
80000524:	40550533          	sub	a0,a0,t0
80000528:	eeb50fa3          	sb	a1,-257(a0)
8000052c:	00000013          	nop
80000530:	00000013          	nop

80000534 <inst_41>:
80000534:	ffffe5b7          	lui	a1,0xffffe
80000538:	fff58593          	addi	a1,a1,-1 # ffffdfff <imme+0xffffe005>
8000053c:	05410513          	addi	a0,sp,84
80000540:	55500293          	li	t0,1365
80000544:	40550533          	sub	a0,a0,t0
80000548:	54b50aa3          	sb	a1,1365(a0)
8000054c:	00000013          	nop
80000550:	00000013          	nop

80000554 <inst_42>:
80000554:	ffffc5b7          	lui	a1,0xffffc
80000558:	fff58593          	addi	a1,a1,-1 # ffffbfff <imme+0xffffc005>
8000055c:	05810513          	addi	a0,sp,88
80000560:	7ff00293          	li	t0,2047
80000564:	40550533          	sub	a0,a0,t0
80000568:	7eb50fa3          	sb	a1,2047(a0)
8000056c:	00000013          	nop
80000570:	00000013          	nop

80000574 <inst_43>:
80000574:	fffe05b7          	lui	a1,0xfffe0
80000578:	fff58593          	addi	a1,a1,-1 # fffdffff <imme+0xfffe0005>
8000057c:	05c10513          	addi	a0,sp,92
80000580:	3ff00293          	li	t0,1023
80000584:	40550533          	sub	a0,a0,t0
80000588:	3eb50fa3          	sb	a1,1023(a0)
8000058c:	00000013          	nop
80000590:	00000013          	nop

80000594 <inst_44>:
80000594:	fff805b7          	lui	a1,0xfff80
80000598:	fff58593          	addi	a1,a1,-1 # fff7ffff <imme+0xfff80005>
8000059c:	06010513          	addi	a0,sp,96
800005a0:	40000293          	li	t0,1024
800005a4:	40550533          	sub	a0,a0,t0
800005a8:	40b50023          	sb	a1,1024(a0)
800005ac:	00000013          	nop
800005b0:	00000013          	nop

800005b4 <inst_45>:
800005b4:	fff005b7          	lui	a1,0xfff00
800005b8:	fff58593          	addi	a1,a1,-1 # ffefffff <imme+0xfff00005>
800005bc:	06410513          	addi	a0,sp,100
800005c0:	00300293          	li	t0,3
800005c4:	40550533          	sub	a0,a0,t0
800005c8:	00b501a3          	sb	a1,3(a0)
800005cc:	00000013          	nop
800005d0:	00000013          	nop

800005d4 <inst_46>:
800005d4:	ffe005b7          	lui	a1,0xffe00
800005d8:	fff58593          	addi	a1,a1,-1 # ffdfffff <imme+0xffe00005>
800005dc:	06810513          	addi	a0,sp,104
800005e0:	01000293          	li	t0,16
800005e4:	40550533          	sub	a0,a0,t0
800005e8:	00b50823          	sb	a1,16(a0)
800005ec:	00000013          	nop
800005f0:	00000013          	nop

800005f4 <inst_47>:
800005f4:	ffc005b7          	lui	a1,0xffc00
800005f8:	fff58593          	addi	a1,a1,-1 # ffbfffff <imme+0xffc00005>
800005fc:	06c10513          	addi	a0,sp,108
80000600:	00000293          	li	t0,0
80000604:	40550533          	sub	a0,a0,t0
80000608:	00b50023          	sb	a1,0(a0)
8000060c:	00000013          	nop
80000610:	00000013          	nop

80000614 <inst_48>:
80000614:	fc0005b7          	lui	a1,0xfc000
80000618:	fff58593          	addi	a1,a1,-1 # fbffffff <imme+0xfc000005>
8000061c:	07010513          	addi	a0,sp,112
80000620:	eff00293          	li	t0,-257
80000624:	40550533          	sub	a0,a0,t0
80000628:	eeb50fa3          	sb	a1,-257(a0)
8000062c:	00000013          	nop
80000630:	00000013          	nop

80000634 <inst_49>:
80000634:	f80005b7          	lui	a1,0xf8000
80000638:	fff58593          	addi	a1,a1,-1 # f7ffffff <imme+0xf8000005>
8000063c:	07410513          	addi	a0,sp,116
80000640:	bff00293          	li	t0,-1025
80000644:	40550533          	sub	a0,a0,t0
80000648:	beb50fa3          	sb	a1,-1025(a0)
8000064c:	00000013          	nop
80000650:	00000013          	nop

80000654 <inst_50>:
80000654:	f00005b7          	lui	a1,0xf0000
80000658:	fff58593          	addi	a1,a1,-1 # efffffff <imme+0xf0000005>
8000065c:	07810513          	addi	a0,sp,120
80000660:	f7f00293          	li	t0,-129
80000664:	40550533          	sub	a0,a0,t0
80000668:	f6b50fa3          	sb	a1,-129(a0)
8000066c:	00000013          	nop
80000670:	00000013          	nop

80000674 <inst_51>:
80000674:	e00005b7          	lui	a1,0xe0000
80000678:	fff58593          	addi	a1,a1,-1 # dfffffff <imme+0xe0000005>
8000067c:	07c10513          	addi	a0,sp,124
80000680:	ff900293          	li	t0,-7
80000684:	40550533          	sub	a0,a0,t0
80000688:	feb50ca3          	sb	a1,-7(a0)
8000068c:	00000013          	nop
80000690:	00000013          	nop

80000694 <inst_52>:
80000694:	c00005b7          	lui	a1,0xc0000
80000698:	fff58593          	addi	a1,a1,-1 # bfffffff <imme+0xc0000005>
8000069c:	08010513          	addi	a0,sp,128
800006a0:	fff00293          	li	t0,-1
800006a4:	40550533          	sub	a0,a0,t0
800006a8:	feb50fa3          	sb	a1,-1(a0)
800006ac:	00000013          	nop
800006b0:	00000013          	nop

800006b4 <inst_53>:
800006b4:	555555b7          	lui	a1,0x55555
800006b8:	55558593          	addi	a1,a1,1365 # 55555555 <pos+0x55555535>
800006bc:	08410513          	addi	a0,sp,132
800006c0:	f7f00293          	li	t0,-129
800006c4:	40550533          	sub	a0,a0,t0
800006c8:	f6b50fa3          	sb	a1,-129(a0)
800006cc:	00000013          	nop
800006d0:	00000013          	nop

800006d4 <inst_54>:
800006d4:	010005b7          	lui	a1,0x1000
800006d8:	08810513          	addi	a0,sp,136
800006dc:	02000293          	li	t0,32
800006e0:	40550533          	sub	a0,a0,t0
800006e4:	02b50023          	sb	a1,32(a0)
800006e8:	00000013          	nop
800006ec:	00000013          	nop

800006f0 <inst_55>:
800006f0:	020005b7          	lui	a1,0x2000
800006f4:	08c10513          	addi	a0,sp,140
800006f8:	10000293          	li	t0,256
800006fc:	40550533          	sub	a0,a0,t0
80000700:	10b50023          	sb	a1,256(a0)
80000704:	00000013          	nop
80000708:	00000013          	nop

8000070c <inst_56>:
8000070c:	040005b7          	lui	a1,0x4000
80000710:	09010513          	addi	a0,sp,144
80000714:	08000293          	li	t0,128
80000718:	40550533          	sub	a0,a0,t0
8000071c:	08b50023          	sb	a1,128(a0)
80000720:	00000013          	nop
80000724:	00000013          	nop

80000728 <inst_57>:
80000728:	080005b7          	lui	a1,0x8000
8000072c:	09410513          	addi	a0,sp,148
80000730:	10000293          	li	t0,256
80000734:	40550533          	sub	a0,a0,t0
80000738:	10b50023          	sb	a1,256(a0)
8000073c:	00000013          	nop
80000740:	00000013          	nop

80000744 <inst_58>:
80000744:	100005b7          	lui	a1,0x10000
80000748:	09810513          	addi	a0,sp,152
8000074c:	00800293          	li	t0,8
80000750:	40550533          	sub	a0,a0,t0
80000754:	00b50423          	sb	a1,8(a0)
80000758:	00000013          	nop
8000075c:	00000013          	nop

80000760 <inst_59>:
80000760:	400005b7          	lui	a1,0x40000
80000764:	09c10513          	addi	a0,sp,156
80000768:	ffa00293          	li	t0,-6
8000076c:	40550533          	sub	a0,a0,t0
80000770:	feb50d23          	sb	a1,-6(a0)
80000774:	00000013          	nop
80000778:	00000013          	nop

8000077c <inst_60>:
8000077c:	ffe00593          	li	a1,-2
80000780:	0a010513          	addi	a0,sp,160
80000784:	00300293          	li	t0,3
80000788:	40550533          	sub	a0,a0,t0
8000078c:	00b501a3          	sb	a1,3(a0)
80000790:	00000013          	nop
80000794:	00000013          	nop

80000798 <inst_61>:
80000798:	ffd00593          	li	a1,-3
8000079c:	0a410513          	addi	a0,sp,164
800007a0:	fff00293          	li	t0,-1
800007a4:	40550533          	sub	a0,a0,t0
800007a8:	feb50fa3          	sb	a1,-1(a0)
800007ac:	00000013          	nop
800007b0:	00000013          	nop

800007b4 <inst_62>:
800007b4:	ffb00593          	li	a1,-5
800007b8:	0a810513          	addi	a0,sp,168
800007bc:	01000293          	li	t0,16
800007c0:	40550533          	sub	a0,a0,t0
800007c4:	00b50823          	sb	a1,16(a0)
800007c8:	00000013          	nop
800007cc:	00000013          	nop

800007d0 <inst_63>:
800007d0:	ff700593          	li	a1,-9
800007d4:	0ac10513          	addi	a0,sp,172
800007d8:	ffd00293          	li	t0,-3
800007dc:	40550533          	sub	a0,a0,t0
800007e0:	feb50ea3          	sb	a1,-3(a0)
800007e4:	00000013          	nop
800007e8:	00000013          	nop

800007ec <inst_64>:
800007ec:	fef00593          	li	a1,-17
800007f0:	0b010513          	addi	a0,sp,176
800007f4:	40000293          	li	t0,1024
800007f8:	40550533          	sub	a0,a0,t0
800007fc:	40b50023          	sb	a1,1024(a0)
80000800:	00000013          	nop
80000804:	00000013          	nop

80000808 <inst_65>:
80000808:	fbf00593          	li	a1,-65
8000080c:	0b410513          	addi	a0,sp,180
80000810:	00500293          	li	t0,5
80000814:	40550533          	sub	a0,a0,t0
80000818:	00b502a3          	sb	a1,5(a0)
8000081c:	00000013          	nop
80000820:	00000013          	nop

80000824 <inst_66>:
80000824:	f7f00593          	li	a1,-129
80000828:	0b810513          	addi	a0,sp,184
8000082c:	7ff00293          	li	t0,2047
80000830:	40550533          	sub	a0,a0,t0
80000834:	7eb50fa3          	sb	a1,2047(a0)
80000838:	00000013          	nop
8000083c:	00000013          	nop

80000840 <inst_67>:
80000840:	eff00593          	li	a1,-257
80000844:	0bc10513          	addi	a0,sp,188
80000848:	00500293          	li	t0,5
8000084c:	40550533          	sub	a0,a0,t0
80000850:	00b502a3          	sb	a1,5(a0)
80000854:	00000013          	nop
80000858:	00000013          	nop

8000085c <inst_68>:
8000085c:	dff00593          	li	a1,-513
80000860:	0c010513          	addi	a0,sp,192
80000864:	ff800293          	li	t0,-8
80000868:	40550533          	sub	a0,a0,t0
8000086c:	feb50c23          	sb	a1,-8(a0)
80000870:	00000013          	nop
80000874:	00000013          	nop

80000878 <inst_69>:
80000878:	fdf00593          	li	a1,-33
8000087c:	0c510513          	addi	a0,sp,197
80000880:	00500293          	li	t0,5
80000884:	40550533          	sub	a0,a0,t0
80000888:	00b502a3          	sb	a1,5(a0)
8000088c:	00000013          	nop
80000890:	00000013          	nop

80000894 <cleanup_epilogs>:
80000894:	0040006f          	j	80000898 <exit_cleanup>

80000898 <exit_cleanup>:
80000898:	00100093          	li	ra,1

8000089c <write_tohost>:
8000089c:	00000f17          	auipc	t5,0x0
800008a0:	761f2223          	sw	ra,1892(t5) # 80001000 <tohost>
800008a4:	ff9ff06f          	j	8000089c <write_tohost>
	...

Disassembly of section .tohost:

80001000 <tohost>:
	...

80001100 <fromhost>:
	...

Disassembly of section .data:

80002000 <rvtest_trap_sig>:
80002000:	2020                	fld	fs0,64(s0)
80002002:	8000                	0x8000
	...

80002010 <rvtest_data_begin>:
80002010:	cafe                	sw	t6,84(sp)
80002012:	babe                	fsd	fa5,368(sp)
80002014:	cafe                	sw	t6,84(sp)
80002016:	babe                	fsd	fa5,368(sp)
80002018:	cafe                	sw	t6,84(sp)
8000201a:	babe                	fsd	fa5,368(sp)
8000201c:	cafe                	sw	t6,84(sp)
8000201e:	babe                	fsd	fa5,368(sp)

80002020 <mtrap_sigptr>:
80002020:	deadbeef          	jal	t4,7ffdd60a <pos+0x7ffdd5ea>
80002024:	deadbeef          	jal	t4,7ffdd60e <pos+0x7ffdd5ee>

80002028 <rvtest_data_end>:
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
80003114:	deadbeef          	jal	t4,7ffde6fe <pos+0x7ffde6de>
80003118:	deadbeef          	jal	t4,7ffde702 <pos+0x7ffde6e2>
8000311c:	deadbeef          	jal	t4,7ffde706 <pos+0x7ffde6e6>
80003120:	deadbeef          	jal	t4,7ffde70a <pos+0x7ffde6ea>
80003124:	deadbeef          	jal	t4,7ffde70e <pos+0x7ffde6ee>
80003128:	deadbeef          	jal	t4,7ffde712 <pos+0x7ffde6f2>
8000312c:	deadbeef          	jal	t4,7ffde716 <pos+0x7ffde6f6>
80003130:	deadbeef          	jal	t4,7ffde71a <pos+0x7ffde6fa>
80003134:	deadbeef          	jal	t4,7ffde71e <pos+0x7ffde6fe>
80003138:	deadbeef          	jal	t4,7ffde722 <pos+0x7ffde702>
8000313c:	deadbeef          	jal	t4,7ffde726 <pos+0x7ffde706>
80003140:	deadbeef          	jal	t4,7ffde72a <pos+0x7ffde70a>
80003144:	deadbeef          	jal	t4,7ffde72e <pos+0x7ffde70e>
80003148:	deadbeef          	jal	t4,7ffde732 <pos+0x7ffde712>
8000314c:	deadbeef          	jal	t4,7ffde736 <pos+0x7ffde716>
80003150:	deadbeef          	jal	t4,7ffde73a <pos+0x7ffde71a>
80003154:	deadbeef          	jal	t4,7ffde73e <pos+0x7ffde71e>
80003158:	deadbeef          	jal	t4,7ffde742 <pos+0x7ffde722>
8000315c:	deadbeef          	jal	t4,7ffde746 <pos+0x7ffde726>
80003160:	deadbeef          	jal	t4,7ffde74a <pos+0x7ffde72a>

80003164 <signature_x2_0>:
80003164:	deadbeef          	jal	t4,7ffde74e <pos+0x7ffde72e>
80003168:	deadbeef          	jal	t4,7ffde752 <pos+0x7ffde732>
8000316c:	deadbeef          	jal	t4,7ffde756 <pos+0x7ffde736>
80003170:	deadbeef          	jal	t4,7ffde75a <pos+0x7ffde73a>
80003174:	deadbeef          	jal	t4,7ffde75e <pos+0x7ffde73e>
80003178:	deadbeef          	jal	t4,7ffde762 <pos+0x7ffde742>
8000317c:	deadbeef          	jal	t4,7ffde766 <pos+0x7ffde746>
80003180:	deadbeef          	jal	t4,7ffde76a <pos+0x7ffde74a>
80003184:	deadbeef          	jal	t4,7ffde76e <pos+0x7ffde74e>
80003188:	deadbeef          	jal	t4,7ffde772 <pos+0x7ffde752>
8000318c:	deadbeef          	jal	t4,7ffde776 <pos+0x7ffde756>
80003190:	deadbeef          	jal	t4,7ffde77a <pos+0x7ffde75a>
80003194:	deadbeef          	jal	t4,7ffde77e <pos+0x7ffde75e>
80003198:	deadbeef          	jal	t4,7ffde782 <pos+0x7ffde762>
8000319c:	deadbeef          	jal	t4,7ffde786 <pos+0x7ffde766>
800031a0:	deadbeef          	jal	t4,7ffde78a <pos+0x7ffde76a>
800031a4:	deadbeef          	jal	t4,7ffde78e <pos+0x7ffde76e>
800031a8:	deadbeef          	jal	t4,7ffde792 <pos+0x7ffde772>
800031ac:	deadbeef          	jal	t4,7ffde796 <pos+0x7ffde776>
800031b0:	deadbeef          	jal	t4,7ffde79a <pos+0x7ffde77a>
800031b4:	deadbeef          	jal	t4,7ffde79e <pos+0x7ffde77e>
800031b8:	deadbeef          	jal	t4,7ffde7a2 <pos+0x7ffde782>
800031bc:	deadbeef          	jal	t4,7ffde7a6 <pos+0x7ffde786>
800031c0:	deadbeef          	jal	t4,7ffde7aa <pos+0x7ffde78a>
800031c4:	deadbeef          	jal	t4,7ffde7ae <pos+0x7ffde78e>
800031c8:	deadbeef          	jal	t4,7ffde7b2 <pos+0x7ffde792>
800031cc:	deadbeef          	jal	t4,7ffde7b6 <pos+0x7ffde796>
800031d0:	deadbeef          	jal	t4,7ffde7ba <pos+0x7ffde79a>
800031d4:	deadbeef          	jal	t4,7ffde7be <pos+0x7ffde79e>
800031d8:	deadbeef          	jal	t4,7ffde7c2 <pos+0x7ffde7a2>
800031dc:	deadbeef          	jal	t4,7ffde7c6 <pos+0x7ffde7a6>
800031e0:	deadbeef          	jal	t4,7ffde7ca <pos+0x7ffde7aa>
800031e4:	deadbeef          	jal	t4,7ffde7ce <pos+0x7ffde7ae>
800031e8:	deadbeef          	jal	t4,7ffde7d2 <pos+0x7ffde7b2>
800031ec:	deadbeef          	jal	t4,7ffde7d6 <pos+0x7ffde7b6>
800031f0:	deadbeef          	jal	t4,7ffde7da <pos+0x7ffde7ba>
800031f4:	deadbeef          	jal	t4,7ffde7de <pos+0x7ffde7be>
800031f8:	deadbeef          	jal	t4,7ffde7e2 <pos+0x7ffde7c2>
800031fc:	deadbeef          	jal	t4,7ffde7e6 <pos+0x7ffde7c6>
80003200:	deadbeef          	jal	t4,7ffde7ea <pos+0x7ffde7ca>
80003204:	deadbeef          	jal	t4,7ffde7ee <pos+0x7ffde7ce>
80003208:	deadbeef          	jal	t4,7ffde7f2 <pos+0x7ffde7d2>
8000320c:	deadbeef          	jal	t4,7ffde7f6 <pos+0x7ffde7d6>
80003210:	deadbeef          	jal	t4,7ffde7fa <pos+0x7ffde7da>
80003214:	deadbeef          	jal	t4,7ffde7fe <pos+0x7ffde7de>
80003218:	deadbeef          	jal	t4,7ffde802 <pos+0x7ffde7e2>
8000321c:	deadbeef          	jal	t4,7ffde806 <pos+0x7ffde7e6>
80003220:	deadbeef          	jal	t4,7ffde80a <pos+0x7ffde7ea>
80003224:	deadbeef          	jal	t4,7ffde80e <pos+0x7ffde7ee>
80003228:	deadbeef          	jal	t4,7ffde812 <pos+0x7ffde7f2>

8000322c <sig_end_canary>:
8000322c:	a309                	j	8000372e <_end+0x4fe>
8000322e:	6f5c                	flw	fa5,28(a4)

Disassembly of section .riscv.attributes:

00000000 <.riscv.attributes>:
   0:	1941                	addi	s2,s2,-16
   2:	0000                	unimp
   4:	7200                	flw	fs0,32(a2)
   6:	7369                	lui	t1,0xffffa
   8:	01007663          	bgeu	zero,a6,14 <absimm+0xf>
   c:	0000000f          	fence	unknown,unknown
  10:	7205                	lui	tp,0xfffe1
  12:	3376                	fld	ft6,376(sp)
  14:	6932                	flw	fs2,12(sp)
  16:	7032                	flw	ft0,44(sp)
  18:	0030                	addi	a2,sp,8

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	0000024b          	fnmsub.s	ft4,ft0,ft0,ft0,rne
   4:	00790003          	lb	zero,7(s2)
   8:	0000                	unimp
   a:	0101                	addi	sp,sp,0
   c:	000d0efb          	0xd0efb
  10:	0101                	addi	sp,sp,0
  12:	0101                	addi	sp,sp,0
  14:	0000                	unimp
  16:	0100                	addi	s0,sp,128
  18:	0000                	unimp
  1a:	2f01                	jal	72a <pos+0x70a>
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
  44:	612d7663          	bgeu	s10,s2,650 <pos+0x630>
  48:	6372                	flw	ft6,28(sp)
  4a:	2d68                	fld	fa0,216(a0)
  4c:	6574                	flw	fa3,76(a0)
  4e:	722f7473          	csrrci	s0,0x722,30
  52:	7369                	lui	t1,0xffffa
  54:	742d7663          	bgeu	s10,sp,7a0 <pos+0x780>
  58:	7365                	lui	t1,0xffff9
  5a:	2d74                	fld	fa3,216(a0)
  5c:	74697573          	csrrci	a0,0x746,18
  60:	2f65                	jal	818 <pos+0x7f8>
  62:	7672                	flw	fa2,60(sp)
  64:	5f693233          	0x5f693233
  68:	2f6d                	jal	822 <pos+0x802>
  6a:	2f49                	jal	7fc <pos+0x7dc>
  6c:	00637273          	csrrci	tp,0x6,6
  70:	7300                	flw	fs0,32(a4)
  72:	2d62                	fld	fs10,24(sp)
  74:	6c61                	lui	s8,0x18
  76:	6769                	lui	a4,0x1a
  78:	2d6e                	fld	fs10,216(sp)
  7a:	3130                	fld	fa2,96(a0)
  7c:	532e                	lw	t1,232(sp)
  7e:	0100                	addi	s0,sp,128
  80:	0000                	unimp
  82:	0000                	unimp
  84:	0205                	addi	tp,tp,1
  86:	0000                	unimp
  88:	8000                	0x8000
  8a:	03011903          	lh	s2,48(sp)
  8e:	0906                	slli	s2,s2,0x1
  90:	0078                	addi	a4,sp,12
  92:	0301                	addi	t1,t1,0
  94:	0905                	addi	s2,s2,1
  96:	0008                	0x8
  98:	0301                	addi	t1,t1,0
  9a:	0905                	addi	s2,s2,1
  9c:	001c                	0x1c
  9e:	0301                	addi	t1,t1,0
  a0:	0905                	addi	s2,s2,1
  a2:	001c                	0x1c
  a4:	0301                	addi	t1,t1,0
  a6:	0905                	addi	s2,s2,1
  a8:	0020                	addi	s0,sp,8
  aa:	0301                	addi	t1,t1,0
  ac:	0905                	addi	s2,s2,1
  ae:	001c                	0x1c
  b0:	0301                	addi	t1,t1,0
  b2:	0905                	addi	s2,s2,1
  b4:	0020                	addi	s0,sp,8
  b6:	0301                	addi	t1,t1,0
  b8:	0905                	addi	s2,s2,1
  ba:	001c                	0x1c
  bc:	0301                	addi	t1,t1,0
  be:	0905                	addi	s2,s2,1
  c0:	0020                	addi	s0,sp,8
  c2:	0301                	addi	t1,t1,0
  c4:	0905                	addi	s2,s2,1
  c6:	001c                	0x1c
  c8:	0301                	addi	t1,t1,0
  ca:	0905                	addi	s2,s2,1
  cc:	0020                	addi	s0,sp,8
  ce:	0301                	addi	t1,t1,0
  d0:	0905                	addi	s2,s2,1
  d2:	001c                	0x1c
  d4:	0301                	addi	t1,t1,0
  d6:	0905                	addi	s2,s2,1
  d8:	001c                	0x1c
  da:	0301                	addi	t1,t1,0
  dc:	0905                	addi	s2,s2,1
  de:	0020                	addi	s0,sp,8
  e0:	0301                	addi	t1,t1,0
  e2:	0905                	addi	s2,s2,1
  e4:	0020                	addi	s0,sp,8
  e6:	0301                	addi	t1,t1,0
  e8:	0905                	addi	s2,s2,1
  ea:	001c                	0x1c
  ec:	0301                	addi	t1,t1,0
  ee:	0905                	addi	s2,s2,1
  f0:	0020                	addi	s0,sp,8
  f2:	0301                	addi	t1,t1,0
  f4:	0905                	addi	s2,s2,1
  f6:	0020                	addi	s0,sp,8
  f8:	0301                	addi	t1,t1,0
  fa:	0905                	addi	s2,s2,1
  fc:	001c                	0x1c
  fe:	0301                	addi	t1,t1,0
 100:	0905                	addi	s2,s2,1
 102:	0020                	addi	s0,sp,8
 104:	0301                	addi	t1,t1,0
 106:	0905                	addi	s2,s2,1
 108:	001c                	0x1c
 10a:	0301                	addi	t1,t1,0
 10c:	0901                	addi	s2,s2,0
 10e:	001c                	0x1c
 110:	0301                	addi	t1,t1,0
 112:	0905                	addi	s2,s2,1
 114:	0008                	0x8
 116:	0301                	addi	t1,t1,0
 118:	0905                	addi	s2,s2,1
 11a:	001c                	0x1c
 11c:	0301                	addi	t1,t1,0
 11e:	0905                	addi	s2,s2,1
 120:	001c                	0x1c
 122:	0301                	addi	t1,t1,0
 124:	0905                	addi	s2,s2,1
 126:	001c                	0x1c
 128:	0301                	addi	t1,t1,0
 12a:	0905                	addi	s2,s2,1
 12c:	001c                	0x1c
 12e:	0301                	addi	t1,t1,0
 130:	0905                	addi	s2,s2,1
 132:	001c                	0x1c
 134:	0301                	addi	t1,t1,0
 136:	0905                	addi	s2,s2,1
 138:	001c                	0x1c
 13a:	0301                	addi	t1,t1,0
 13c:	0905                	addi	s2,s2,1
 13e:	001c                	0x1c
 140:	0301                	addi	t1,t1,0
 142:	0905                	addi	s2,s2,1
 144:	0020                	addi	s0,sp,8
 146:	0301                	addi	t1,t1,0
 148:	0905                	addi	s2,s2,1
 14a:	001c                	0x1c
 14c:	0301                	addi	t1,t1,0
 14e:	0905                	addi	s2,s2,1
 150:	001c                	0x1c
 152:	0301                	addi	t1,t1,0
 154:	0905                	addi	s2,s2,1
 156:	001c                	0x1c
 158:	0301                	addi	t1,t1,0
 15a:	0905                	addi	s2,s2,1
 15c:	001c                	0x1c
 15e:	0301                	addi	t1,t1,0
 160:	0905                	addi	s2,s2,1
 162:	001c                	0x1c
 164:	0301                	addi	t1,t1,0
 166:	0905                	addi	s2,s2,1
 168:	001c                	0x1c
 16a:	0301                	addi	t1,t1,0
 16c:	0905                	addi	s2,s2,1
 16e:	001c                	0x1c
 170:	0301                	addi	t1,t1,0
 172:	0905                	addi	s2,s2,1
 174:	001c                	0x1c
 176:	0301                	addi	t1,t1,0
 178:	0905                	addi	s2,s2,1
 17a:	001c                	0x1c
 17c:	0301                	addi	t1,t1,0
 17e:	0905                	addi	s2,s2,1
 180:	001c                	0x1c
 182:	0301                	addi	t1,t1,0
 184:	0905                	addi	s2,s2,1
 186:	001c                	0x1c
 188:	0301                	addi	t1,t1,0
 18a:	0905                	addi	s2,s2,1
 18c:	0020                	addi	s0,sp,8
 18e:	0301                	addi	t1,t1,0
 190:	0905                	addi	s2,s2,1
 192:	0020                	addi	s0,sp,8
 194:	0301                	addi	t1,t1,0
 196:	0905                	addi	s2,s2,1
 198:	0020                	addi	s0,sp,8
 19a:	0301                	addi	t1,t1,0
 19c:	0905                	addi	s2,s2,1
 19e:	0020                	addi	s0,sp,8
 1a0:	0301                	addi	t1,t1,0
 1a2:	0905                	addi	s2,s2,1
 1a4:	0020                	addi	s0,sp,8
 1a6:	0301                	addi	t1,t1,0
 1a8:	0905                	addi	s2,s2,1
 1aa:	0020                	addi	s0,sp,8
 1ac:	0301                	addi	t1,t1,0
 1ae:	0905                	addi	s2,s2,1
 1b0:	0020                	addi	s0,sp,8
 1b2:	0301                	addi	t1,t1,0
 1b4:	0905                	addi	s2,s2,1
 1b6:	0020                	addi	s0,sp,8
 1b8:	0301                	addi	t1,t1,0
 1ba:	0905                	addi	s2,s2,1
 1bc:	0020                	addi	s0,sp,8
 1be:	0301                	addi	t1,t1,0
 1c0:	0905                	addi	s2,s2,1
 1c2:	0020                	addi	s0,sp,8
 1c4:	0301                	addi	t1,t1,0
 1c6:	0905                	addi	s2,s2,1
 1c8:	0020                	addi	s0,sp,8
 1ca:	0301                	addi	t1,t1,0
 1cc:	0905                	addi	s2,s2,1
 1ce:	0020                	addi	s0,sp,8
 1d0:	0301                	addi	t1,t1,0
 1d2:	0905                	addi	s2,s2,1
 1d4:	0020                	addi	s0,sp,8
 1d6:	0301                	addi	t1,t1,0
 1d8:	0905                	addi	s2,s2,1
 1da:	0020                	addi	s0,sp,8
 1dc:	0301                	addi	t1,t1,0
 1de:	0905                	addi	s2,s2,1
 1e0:	0020                	addi	s0,sp,8
 1e2:	0301                	addi	t1,t1,0
 1e4:	0905                	addi	s2,s2,1
 1e6:	001c                	0x1c
 1e8:	0301                	addi	t1,t1,0
 1ea:	0905                	addi	s2,s2,1
 1ec:	001c                	0x1c
 1ee:	0301                	addi	t1,t1,0
 1f0:	0905                	addi	s2,s2,1
 1f2:	001c                	0x1c
 1f4:	0301                	addi	t1,t1,0
 1f6:	0905                	addi	s2,s2,1
 1f8:	001c                	0x1c
 1fa:	0301                	addi	t1,t1,0
 1fc:	0905                	addi	s2,s2,1
 1fe:	001c                	0x1c
 200:	0301                	addi	t1,t1,0
 202:	0905                	addi	s2,s2,1
 204:	001c                	0x1c
 206:	0301                	addi	t1,t1,0
 208:	0905                	addi	s2,s2,1
 20a:	001c                	0x1c
 20c:	0301                	addi	t1,t1,0
 20e:	0905                	addi	s2,s2,1
 210:	001c                	0x1c
 212:	0301                	addi	t1,t1,0
 214:	0905                	addi	s2,s2,1
 216:	001c                	0x1c
 218:	0301                	addi	t1,t1,0
 21a:	0905                	addi	s2,s2,1
 21c:	001c                	0x1c
 21e:	0301                	addi	t1,t1,0
 220:	0905                	addi	s2,s2,1
 222:	001c                	0x1c
 224:	0301                	addi	t1,t1,0
 226:	0905                	addi	s2,s2,1
 228:	001c                	0x1c
 22a:	0301                	addi	t1,t1,0
 22c:	0905                	addi	s2,s2,1
 22e:	001c                	0x1c
 230:	0301                	addi	t1,t1,0
 232:	0905                	addi	s2,s2,1
 234:	001c                	0x1c
 236:	0301                	addi	t1,t1,0
 238:	0905                	addi	s2,s2,1
 23a:	001c                	0x1c
 23c:	0301                	addi	t1,t1,0
 23e:	0904                	addi	s1,sp,144
 240:	001c                	0x1c
 242:	0301                	addi	t1,t1,0
 244:	0901                	addi	s2,s2,0
 246:	0004                	0x4
 248:	0901                	addi	s2,s2,0
 24a:	0010                	0x10
 24c:	0100                	addi	s0,sp,128
 24e:	01              	Address 0x000000000000024e is out of bounds.


Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	0022                	c.slli	zero,0x8
   2:	0000                	unimp
   4:	0002                	c.slli64	zero
   6:	0000                	unimp
   8:	0000                	unimp
   a:	0104                	addi	s1,sp,128
   c:	0000                	unimp
   e:	0000                	unimp
  10:	0000                	unimp
  12:	8000                	0x8000
  14:	08a8                	addi	a0,sp,88
  16:	8000                	0x8000
  18:	0000                	unimp
  1a:	0000                	unimp
  1c:	00000063          	beqz	zero,1c <absimm+0x17>
  20:	00b5                	addi	ra,ra,13
  22:	0000                	unimp
  24:	8001                	c.srli64	s0

Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	1101                	addi	sp,sp,-32
   2:	1000                	addi	s0,sp,32
   4:	1106                	slli	sp,sp,0x21
   6:	1201                	addi	tp,tp,-32
   8:	0301                	addi	t1,t1,0
   a:	1b0e                	slli	s6,s6,0x23
   c:	250e                	fld	fa0,192(sp)
   e:	130e                	slli	t1,t1,0x23
  10:	0005                	c.nop	1
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	001c                	0x1c
   2:	0000                	unimp
   4:	0002                	c.slli64	zero
   6:	0000                	unimp
   8:	0000                	unimp
   a:	0004                	0x4
   c:	0000                	unimp
   e:	0000                	unimp
  10:	0000                	unimp
  12:	8000                	0x8000
  14:	08a8                	addi	a0,sp,88
	...

Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	6d6f682f          	0x6d6f682f
   4:	2f65                	jal	7bc <pos+0x79c>
   6:	6f6c                	flw	fa1,92(a4)
   8:	6976                	flw	fs2,92(sp)
   a:	65442f73          	csrrs	t5,0x654,s0
   e:	6f746b73          	csrrsi	s6,0x6f7,8
  12:	2f70                	fld	fa2,216(a4)
  14:	6952                	flw	fs2,20(sp)
  16:	6556                	flw	fa0,84(sp)
  18:	5f72                	lw	t5,60(sp)
  1a:	65726f63          	bltu	tp,s7,678 <pos+0x658>
  1e:	7369722f          	0x7369722f
  22:	2f666f63          	bltu	a2,s6,320 <pos+0x300>
  26:	6972                	flw	fs2,28(sp)
  28:	2d766373          	csrrsi	t1,0x2d7,12
  2c:	7261                	lui	tp,0xffff8
  2e:	742d6863          	bltu	s10,sp,77e <pos+0x75e>
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
  4c:	6d5f 492f 732f      	0x732f492f6d5f
  52:	6372                	flw	ft6,28(sp)
  54:	2d62732f          	0x2d62732f
  58:	6c61                	lui	s8,0x18
  5a:	6769                	lui	a4,0x1a
  5c:	2d6e                	fld	fs10,216(sp)
  5e:	3130                	fld	fa2,96(a0)
  60:	532e                	lw	t1,232(sp)
  62:	2f00                	fld	fs0,24(a4)
  64:	6f68                	flw	fa0,92(a4)
  66:	656d                	lui	a0,0x1b
  68:	766f6c2f          	0x766f6c2f
  6c:	7369                	lui	t1,0xffffa
  6e:	7365442f          	0x7365442f
  72:	706f746b          	0x706f746b
  76:	5669522f          	0x5669522f
  7a:	7265                	lui	tp,0xffff9
  7c:	635f 726f 2f65      	0x2f65726f635f
  82:	6972                	flw	fs2,28(sp)
  84:	666f6373          	csrrsi	t1,0x666,30
  88:	7369722f          	0x7369722f
  8c:	5f666f63          	bltu	a2,s6,68a <pos+0x66a>
  90:	6b726f77          	0x6b726f77
  94:	3376722f          	0x3376722f
  98:	6932                	flw	fs2,12(sp)
  9a:	6d5f 492f 732f      	0x732f492f6d5f
  a0:	6372                	flw	ft6,28(sp)
  a2:	2d62732f          	0x2d62732f
  a6:	6c61                	lui	s8,0x18
  a8:	6769                	lui	a4,0x1a
  aa:	2d6e                	fld	fs10,216(sp)
  ac:	3130                	fld	fa2,96(a0)
  ae:	532e                	lw	t1,232(sp)
  b0:	7475642f          	0x7475642f
  b4:	4700                	lw	s0,8(a4)
  b6:	554e                	lw	a0,240(sp)
  b8:	4120                	lw	s0,64(a0)
  ba:	2e322053          	0x2e322053
  be:	          	snez	a0,zero
