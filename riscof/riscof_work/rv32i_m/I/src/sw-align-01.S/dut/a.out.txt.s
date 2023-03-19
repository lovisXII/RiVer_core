
my.elf:     file format elf32-littleriscv


Disassembly of section .text.init:

80000000 <rvtest_entry_point>:
80000000:	feedc0b7          	lui	ra,0xfeedc
80000004:	ead08093          	addi	ra,ra,-339 # feedbead <imme+0xfeedc403>
80000008:	ff76e137          	lui	sp,0xff76e
8000000c:	f5610113          	addi	sp,sp,-170 # ff76df56 <imme+0xff76e4ac>
80000010:	7fbb71b7          	lui	gp,0x7fbb7
80000014:	fab18193          	addi	gp,gp,-85 # 7fbb6fab <absimm+0x7fbb6a56>
80000018:	bfddb237          	lui	tp,0xbfddb
8000001c:	7d520213          	addi	tp,tp,2005 # bfddb7d5 <imme+0xbfddbd2b>
80000020:	00000297          	auipc	t0,0x0
80000024:	05828293          	addi	t0,t0,88 # 80000078 <rvtest_code_begin>
80000028:	00002317          	auipc	t1,0x2
8000002c:	fe830313          	addi	t1,t1,-24 # 80002010 <rvtest_data_begin>
80000030:	b7fbb3b7          	lui	t2,0xb7fbb
80000034:	6fa38393          	addi	t2,t2,1786 # b7fbb6fa <imme+0xb7fbbc50>
80000038:	5bfde437          	lui	s0,0x5bfde
8000003c:	b7d40413          	addi	s0,s0,-1155 # 5bfddb7d <absimm+0x5bfdd628>
80000040:	adfef4b7          	lui	s1,0xadfef
80000044:	dbe48493          	addi	s1,s1,-578 # adfeedbe <imme+0xadfef314>
80000048:	56ff7537          	lui	a0,0x56ff7
8000004c:	6df50513          	addi	a0,a0,1759 # 56ff76df <absimm+0x56ff718a>
80000050:	ab7fc5b7          	lui	a1,0xab7fc
80000054:	b6f58593          	addi	a1,a1,-1169 # ab7fbb6f <imme+0xab7fc0c5>
80000058:	d5bfe637          	lui	a2,0xd5bfe
8000005c:	db760613          	addi	a2,a2,-585 # d5bfddb7 <imme+0xd5bfe30d>
80000060:	eadff6b7          	lui	a3,0xeadff
80000064:	edb68693          	addi	a3,a3,-293 # eadfeedb <imme+0xeadff431>
80000068:	f56ff737          	lui	a4,0xf56ff
8000006c:	76d70713          	addi	a4,a4,1901 # f56ff76d <imme+0xf56ffcc3>
80000070:	fab807b7          	lui	a5,0xfab80
80000074:	bb678793          	addi	a5,a5,-1098 # fab7fbb6 <imme+0xfab8010c>

80000078 <rvtest_code_begin>:
80000078:	00003117          	auipc	sp,0x3
8000007c:	09c10113          	addi	sp,sp,156 # 80003114 <signature_x2_0>

80000080 <inst_0>:
80000080:	80000f37          	lui	t5,0x80000
80000084:	00010793          	mv	a5,sp
80000088:	08000293          	li	t0,128
8000008c:	405787b3          	sub	a5,a5,t0
80000090:	09e7a023          	sw	t5,128(a5)
80000094:	00000013          	nop
80000098:	00000013          	nop

8000009c <inst_1>:
8000009c:	00000993          	li	s3,0
800000a0:	00410613          	addi	a2,sp,4
800000a4:	f7f00293          	li	t0,-129
800000a8:	40560633          	sub	a2,a2,t0
800000ac:	f7362fa3          	sw	s3,-129(a2)
800000b0:	00000013          	nop
800000b4:	00000013          	nop

800000b8 <inst_2>:
800000b8:	80000d37          	lui	s10,0x80000
800000bc:	fffd0d13          	addi	s10,s10,-1 # 7fffffff <imme+0x80000555>
800000c0:	00810e93          	addi	t4,sp,8
800000c4:	3ff00293          	li	t0,1023
800000c8:	405e8eb3          	sub	t4,t4,t0
800000cc:	3faeafa3          	sw	s10,1023(t4)
800000d0:	00000013          	nop
800000d4:	00000013          	nop

800000d8 <inst_3>:
800000d8:	00000013          	nop
800000dc:	00c10093          	addi	ra,sp,12
800000e0:	55500293          	li	t0,1365
800000e4:	405080b3          	sub	ra,ra,t0
800000e8:	5400aaa3          	sw	zero,1365(ra)
800000ec:	00000013          	nop
800000f0:	00000013          	nop

800000f4 <inst_4>:
800000f4:	00008b37          	lui	s6,0x8
800000f8:	01010e13          	addi	t3,sp,16
800000fc:	ffe00293          	li	t0,-2
80000100:	405e0e33          	sub	t3,t3,t0
80000104:	ff6e2f23          	sw	s6,-2(t3)
80000108:	00000013          	nop
8000010c:	00000013          	nop

80000110 <inst_5>:
80000110:	fef00813          	li	a6,-17
80000114:	01410913          	addi	s2,sp,20
80000118:	00000293          	li	t0,0
8000011c:	40590933          	sub	s2,s2,t0
80000120:	01092023          	sw	a6,0(s2)
80000124:	00000013          	nop
80000128:	00000013          	nop

8000012c <inst_6>:
8000012c:	00200a13          	li	s4,2
80000130:	01810d93          	addi	s11,sp,24
80000134:	00900293          	li	t0,9
80000138:	405d8db3          	sub	s11,s11,t0
8000013c:	014da4a3          	sw	s4,9(s11)
80000140:	00000013          	nop
80000144:	00000013          	nop

80000148 <inst_7>:
80000148:	00400913          	li	s2,4
8000014c:	01c10b93          	addi	s7,sp,28
80000150:	bff00293          	li	t0,-1025
80000154:	405b8bb3          	sub	s7,s7,t0
80000158:	bf2bafa3          	sw	s2,-1025(s7)
8000015c:	00000013          	nop
80000160:	00000013          	nop

80000164 <inst_8>:
80000164:	00800f93          	li	t6,8
80000168:	02010813          	addi	a6,sp,32
8000016c:	00400293          	li	t0,4
80000170:	40580833          	sub	a6,a6,t0
80000174:	01f82223          	sw	t6,4(a6)
80000178:	00000013          	nop
8000017c:	00000013          	nop

80000180 <inst_9>:
80000180:	01000a93          	li	s5,16
80000184:	02410193          	addi	gp,sp,36
80000188:	00700293          	li	t0,7
8000018c:	405181b3          	sub	gp,gp,t0
80000190:	0151a3a3          	sw	s5,7(gp)
80000194:	00000013          	nop
80000198:	00000013          	nop

8000019c <inst_10>:
8000019c:	02000b93          	li	s7,32
800001a0:	02810493          	addi	s1,sp,40
800001a4:	00500293          	li	t0,5
800001a8:	405484b3          	sub	s1,s1,t0
800001ac:	0174a2a3          	sw	s7,5(s1)
800001b0:	00000013          	nop
800001b4:	00000013          	nop

800001b8 <inst_11>:
800001b8:	04000e93          	li	t4,64
800001bc:	02c10413          	addi	s0,sp,44
800001c0:	f7f00293          	li	t0,-129
800001c4:	40540433          	sub	s0,s0,t0
800001c8:	f7d42fa3          	sw	t4,-129(s0)
800001cc:	00000013          	nop
800001d0:	00000013          	nop

800001d4 <inst_12>:
800001d4:	08000693          	li	a3,128
800001d8:	03010213          	addi	tp,sp,48
800001dc:	ff700293          	li	t0,-9
800001e0:	40520233          	sub	tp,tp,t0
800001e4:	fed22ba3          	sw	a3,-9(tp) # fffffff7 <imme+0x54d>
800001e8:	00000013          	nop
800001ec:	00000013          	nop

800001f0 <inst_13>:
800001f0:	10000793          	li	a5,256
800001f4:	03410f93          	addi	t6,sp,52
800001f8:	ffe00293          	li	t0,-2
800001fc:	405f8fb3          	sub	t6,t6,t0
80000200:	feffaf23          	sw	a5,-2(t6)
80000204:	00000013          	nop
80000208:	00000013          	nop

8000020c <inst_14>:
8000020c:	20000613          	li	a2,512
80000210:	03810893          	addi	a7,sp,56
80000214:	dff00293          	li	t0,-513
80000218:	405888b3          	sub	a7,a7,t0
8000021c:	dec8afa3          	sw	a2,-513(a7)
80000220:	00000013          	nop
80000224:	00000013          	nop

80000228 <inst_15>:
80000228:	40000513          	li	a0,1024
8000022c:	03c10393          	addi	t2,sp,60
80000230:	08000293          	li	t0,128
80000234:	405383b3          	sub	t2,t2,t0
80000238:	08a3a023          	sw	a0,128(t2)
8000023c:	00000013          	nop
80000240:	00000013          	nop

80000244 <inst_16>:
80000244:	00001cb7          	lui	s9,0x1
80000248:	800c8c93          	addi	s9,s9,-2048 # 800 <absimm+0x2ab>
8000024c:	04010713          	addi	a4,sp,64
80000250:	ffe00293          	li	t0,-2
80000254:	40570733          	sub	a4,a4,t0
80000258:	ff972f23          	sw	s9,-2(a4)
8000025c:	00000013          	nop
80000260:	00000013          	nop

80000264 <inst_17>:
80000264:	00001c37          	lui	s8,0x1
80000268:	04410b13          	addi	s6,sp,68
8000026c:	ffd00293          	li	t0,-3
80000270:	405b0b33          	sub	s6,s6,t0
80000274:	ff8b2ea3          	sw	s8,-3(s6) # 7ffd <absimm+0x7aa8>
80000278:	00000013          	nop
8000027c:	00000013          	nop

80000280 <inst_18>:
80000280:	000022b7          	lui	t0,0x2
80000284:	04810c13          	addi	s8,sp,72
80000288:	40000793          	li	a5,1024
8000028c:	40fc0c33          	sub	s8,s8,a5
80000290:	405c2023          	sw	t0,1024(s8) # 1400 <absimm+0xeab>
80000294:	00000013          	nop
80000298:	00000013          	nop
8000029c:	00003617          	auipc	a2,0x3
800002a0:	ec460613          	addi	a2,a2,-316 # 80003160 <signature_x12_0>

800002a4 <inst_19>:
800002a4:	000040b7          	lui	ra,0x4
800002a8:	00060693          	mv	a3,a2
800002ac:	dff00793          	li	a5,-513
800002b0:	40f686b3          	sub	a3,a3,a5
800002b4:	de16afa3          	sw	ra,-513(a3)
800002b8:	00000013          	nop
800002bc:	00000013          	nop

800002c0 <inst_20>:
800002c0:	000104b7          	lui	s1,0x10
800002c4:	00460593          	addi	a1,a2,4
800002c8:	ffb00793          	li	a5,-5
800002cc:	40f585b3          	sub	a1,a1,a5
800002d0:	fe95ada3          	sw	s1,-5(a1)
800002d4:	00000013          	nop
800002d8:	00000013          	nop

800002dc <inst_21>:
800002dc:	00020137          	lui	sp,0x20
800002e0:	00860a93          	addi	s5,a2,8
800002e4:	00700793          	li	a5,7
800002e8:	40fa8ab3          	sub	s5,s5,a5
800002ec:	002aa3a3          	sw	sp,7(s5)
800002f0:	00000013          	nop
800002f4:	00000013          	nop

800002f8 <inst_22>:
800002f8:	00040e37          	lui	t3,0x40
800002fc:	00c60993          	addi	s3,a2,12
80000300:	ff700793          	li	a5,-9
80000304:	40f989b3          	sub	s3,s3,a5
80000308:	ffc9aba3          	sw	t3,-9(s3)
8000030c:	00000013          	nop
80000310:	00000013          	nop

80000314 <inst_23>:
80000314:	00080437          	lui	s0,0x80
80000318:	01060313          	addi	t1,a2,16
8000031c:	00200793          	li	a5,2
80000320:	40f30333          	sub	t1,t1,a5
80000324:	00832123          	sw	s0,2(t1)
80000328:	00000013          	nop
8000032c:	00000013          	nop

80000330 <inst_24>:
80000330:	001003b7          	lui	t2,0x100
80000334:	01460c93          	addi	s9,a2,20
80000338:	eff00793          	li	a5,-257
8000033c:	40fc8cb3          	sub	s9,s9,a5
80000340:	ee7cafa3          	sw	t2,-257(s9)
80000344:	00000013          	nop
80000348:	00000013          	nop

8000034c <inst_25>:
8000034c:	00200337          	lui	t1,0x200
80000350:	01860513          	addi	a0,a2,24
80000354:	00400793          	li	a5,4
80000358:	40f50533          	sub	a0,a0,a5
8000035c:	00652223          	sw	t1,4(a0)
80000360:	00000013          	nop
80000364:	00000013          	nop

80000368 <inst_26>:
80000368:	00400737          	lui	a4,0x400
8000036c:	01c60f13          	addi	t5,a2,28
80000370:	ffd00793          	li	a5,-3
80000374:	40ff0f33          	sub	t5,t5,a5
80000378:	feef2ea3          	sw	a4,-3(t5) # 7ffffffd <imme+0x80000553>
8000037c:	00000013          	nop
80000380:	00000013          	nop

80000384 <inst_27>:
80000384:	00800237          	lui	tp,0x800
80000388:	02060d13          	addi	s10,a2,32
8000038c:	00100793          	li	a5,1
80000390:	40fd0d33          	sub	s10,s10,a5
80000394:	004d20a3          	sw	tp,1(s10)
80000398:	00000013          	nop
8000039c:	00000013          	nop

800003a0 <inst_28>:
800003a0:	010008b7          	lui	a7,0x1000
800003a4:	02460113          	addi	sp,a2,36
800003a8:	02000793          	li	a5,32
800003ac:	40f10133          	sub	sp,sp,a5
800003b0:	03112023          	sw	a7,32(sp) # 20020 <absimm+0x1facb>
800003b4:	00000013          	nop
800003b8:	00000013          	nop

800003bc <inst_29>:
800003bc:	020005b7          	lui	a1,0x2000
800003c0:	02860a13          	addi	s4,a2,40
800003c4:	ff900793          	li	a5,-7
800003c8:	40fa0a33          	sub	s4,s4,a5
800003cc:	feba2ca3          	sw	a1,-7(s4)
800003d0:	00000013          	nop
800003d4:	00000013          	nop

800003d8 <inst_30>:
800003d8:	04000db7          	lui	s11,0x4000
800003dc:	02c60293          	addi	t0,a2,44
800003e0:	aaa00793          	li	a5,-1366
800003e4:	40f282b3          	sub	t0,t0,a5
800003e8:	abb2a523          	sw	s11,-1366(t0) # 1aaa <absimm+0x1555>
800003ec:	00000013          	nop
800003f0:	00000013          	nop

800003f4 <inst_31>:
800003f4:	080001b7          	lui	gp,0x8000
800003f8:	03060e13          	addi	t3,a2,48
800003fc:	00500793          	li	a5,5
80000400:	40fe0e33          	sub	t3,t3,a5
80000404:	003e22a3          	sw	gp,5(t3) # 40005 <absimm+0x3fab0>
80000408:	00000013          	nop
8000040c:	00000013          	nop

80000410 <inst_32>:
80000410:	100005b7          	lui	a1,0x10000
80000414:	03460513          	addi	a0,a2,52
80000418:	fef00793          	li	a5,-17
8000041c:	40f50533          	sub	a0,a0,a5
80000420:	feb527a3          	sw	a1,-17(a0)
80000424:	00000013          	nop
80000428:	00000013          	nop

8000042c <inst_33>:
8000042c:	200005b7          	lui	a1,0x20000
80000430:	03860513          	addi	a0,a2,56
80000434:	3ff00793          	li	a5,1023
80000438:	40f50533          	sub	a0,a0,a5
8000043c:	3eb52fa3          	sw	a1,1023(a0)
80000440:	00000013          	nop
80000444:	00000013          	nop

80000448 <inst_34>:
80000448:	400005b7          	lui	a1,0x40000
8000044c:	03c60513          	addi	a0,a2,60
80000450:	ff800793          	li	a5,-8
80000454:	40f50533          	sub	a0,a0,a5
80000458:	feb52c23          	sw	a1,-8(a0)
8000045c:	00000013          	nop
80000460:	00000013          	nop

80000464 <inst_35>:
80000464:	ffe00593          	li	a1,-2
80000468:	04060513          	addi	a0,a2,64
8000046c:	00600793          	li	a5,6
80000470:	40f50533          	sub	a0,a0,a5
80000474:	00b52323          	sw	a1,6(a0)
80000478:	00000013          	nop
8000047c:	00000013          	nop

80000480 <inst_36>:
80000480:	ffc005b7          	lui	a1,0xffc00
80000484:	fff58593          	addi	a1,a1,-1 # ffbfffff <imme+0xffc00555>
80000488:	04460513          	addi	a0,a2,68
8000048c:	20000793          	li	a5,512
80000490:	40f50533          	sub	a0,a0,a5
80000494:	20b52023          	sw	a1,512(a0)
80000498:	00000013          	nop
8000049c:	00000013          	nop

800004a0 <inst_37>:
800004a0:	ff8005b7          	lui	a1,0xff800
800004a4:	fff58593          	addi	a1,a1,-1 # ff7fffff <imme+0xff800555>
800004a8:	04860513          	addi	a0,a2,72
800004ac:	fef00793          	li	a5,-17
800004b0:	40f50533          	sub	a0,a0,a5
800004b4:	feb527a3          	sw	a1,-17(a0)
800004b8:	00000013          	nop
800004bc:	00000013          	nop

800004c0 <inst_38>:
800004c0:	ff0005b7          	lui	a1,0xff000
800004c4:	fff58593          	addi	a1,a1,-1 # feffffff <imme+0xff000555>
800004c8:	04c60513          	addi	a0,a2,76
800004cc:	00400793          	li	a5,4
800004d0:	40f50533          	sub	a0,a0,a5
800004d4:	00b52223          	sw	a1,4(a0)
800004d8:	00000013          	nop
800004dc:	00000013          	nop

800004e0 <inst_39>:
800004e0:	fe0005b7          	lui	a1,0xfe000
800004e4:	fff58593          	addi	a1,a1,-1 # fdffffff <imme+0xfe000555>
800004e8:	05060513          	addi	a0,a2,80
800004ec:	01000793          	li	a5,16
800004f0:	40f50533          	sub	a0,a0,a5
800004f4:	00b52823          	sw	a1,16(a0)
800004f8:	00000013          	nop
800004fc:	00000013          	nop

80000500 <inst_40>:
80000500:	fc0005b7          	lui	a1,0xfc000
80000504:	fff58593          	addi	a1,a1,-1 # fbffffff <imme+0xfc000555>
80000508:	05460513          	addi	a0,a2,84
8000050c:	ffc00793          	li	a5,-4
80000510:	40f50533          	sub	a0,a0,a5
80000514:	feb52e23          	sw	a1,-4(a0)
80000518:	00000013          	nop
8000051c:	00000013          	nop

80000520 <inst_41>:
80000520:	f80005b7          	lui	a1,0xf8000
80000524:	fff58593          	addi	a1,a1,-1 # f7ffffff <imme+0xf8000555>
80000528:	05860513          	addi	a0,a2,88
8000052c:	08000793          	li	a5,128
80000530:	40f50533          	sub	a0,a0,a5
80000534:	08b52023          	sw	a1,128(a0)
80000538:	00000013          	nop
8000053c:	00000013          	nop

80000540 <inst_42>:
80000540:	f00005b7          	lui	a1,0xf0000
80000544:	fff58593          	addi	a1,a1,-1 # efffffff <imme+0xf0000555>
80000548:	05c60513          	addi	a0,a2,92
8000054c:	ff700793          	li	a5,-9
80000550:	40f50533          	sub	a0,a0,a5
80000554:	feb52ba3          	sw	a1,-9(a0)
80000558:	00000013          	nop
8000055c:	00000013          	nop

80000560 <inst_43>:
80000560:	e00005b7          	lui	a1,0xe0000
80000564:	fff58593          	addi	a1,a1,-1 # dfffffff <imme+0xe0000555>
80000568:	06060513          	addi	a0,a2,96
8000056c:	00300793          	li	a5,3
80000570:	40f50533          	sub	a0,a0,a5
80000574:	00b521a3          	sw	a1,3(a0)
80000578:	00000013          	nop
8000057c:	00000013          	nop

80000580 <inst_44>:
80000580:	c00005b7          	lui	a1,0xc0000
80000584:	fff58593          	addi	a1,a1,-1 # bfffffff <imme+0xc0000555>
80000588:	06460513          	addi	a0,a2,100
8000058c:	40000793          	li	a5,1024
80000590:	40f50533          	sub	a0,a0,a5
80000594:	40b52023          	sw	a1,1024(a0)
80000598:	00000013          	nop
8000059c:	00000013          	nop

800005a0 <inst_45>:
800005a0:	555555b7          	lui	a1,0x55555
800005a4:	55558593          	addi	a1,a1,1365 # 55555555 <absimm+0x55555000>
800005a8:	06860513          	addi	a0,a2,104
800005ac:	00700793          	li	a5,7
800005b0:	40f50533          	sub	a0,a0,a5
800005b4:	00b523a3          	sw	a1,7(a0)
800005b8:	00000013          	nop
800005bc:	00000013          	nop

800005c0 <inst_46>:
800005c0:	aaaab5b7          	lui	a1,0xaaaab
800005c4:	aaa58593          	addi	a1,a1,-1366 # aaaaaaaa <imme+0xaaaab000>
800005c8:	06c60513          	addi	a0,a2,108
800005cc:	00700793          	li	a5,7
800005d0:	40f50533          	sub	a0,a0,a5
800005d4:	00b523a3          	sw	a1,7(a0)
800005d8:	00000013          	nop
800005dc:	00000013          	nop

800005e0 <inst_47>:
800005e0:	ffd00593          	li	a1,-3
800005e4:	07060513          	addi	a0,a2,112
800005e8:	04000793          	li	a5,64
800005ec:	40f50533          	sub	a0,a0,a5
800005f0:	04b52023          	sw	a1,64(a0)
800005f4:	00000013          	nop
800005f8:	00000013          	nop

800005fc <inst_48>:
800005fc:	ffb00593          	li	a1,-5
80000600:	07460513          	addi	a0,a2,116
80000604:	7ff00793          	li	a5,2047
80000608:	40f50533          	sub	a0,a0,a5
8000060c:	7eb52fa3          	sw	a1,2047(a0)
80000610:	00000013          	nop
80000614:	00000013          	nop

80000618 <inst_49>:
80000618:	ff700593          	li	a1,-9
8000061c:	07860513          	addi	a0,a2,120
80000620:	20000793          	li	a5,512
80000624:	40f50533          	sub	a0,a0,a5
80000628:	20b52023          	sw	a1,512(a0)
8000062c:	00000013          	nop
80000630:	00000013          	nop

80000634 <inst_50>:
80000634:	fdf00593          	li	a1,-33
80000638:	07c60513          	addi	a0,a2,124
8000063c:	80000793          	li	a5,-2048
80000640:	40f50533          	sub	a0,a0,a5
80000644:	80b52023          	sw	a1,-2048(a0)
80000648:	00000013          	nop
8000064c:	00000013          	nop

80000650 <inst_51>:
80000650:	fbf00593          	li	a1,-65
80000654:	08060513          	addi	a0,a2,128
80000658:	ffe00793          	li	a5,-2
8000065c:	40f50533          	sub	a0,a0,a5
80000660:	feb52f23          	sw	a1,-2(a0)
80000664:	00000013          	nop
80000668:	00000013          	nop

8000066c <inst_52>:
8000066c:	f7f00593          	li	a1,-129
80000670:	08460513          	addi	a0,a2,132
80000674:	ff800793          	li	a5,-8
80000678:	40f50533          	sub	a0,a0,a5
8000067c:	feb52c23          	sw	a1,-8(a0)
80000680:	00000013          	nop
80000684:	00000013          	nop

80000688 <inst_53>:
80000688:	eff00593          	li	a1,-257
8000068c:	08860513          	addi	a0,a2,136
80000690:	eff00793          	li	a5,-257
80000694:	40f50533          	sub	a0,a0,a5
80000698:	eeb52fa3          	sw	a1,-257(a0)
8000069c:	00000013          	nop
800006a0:	00000013          	nop

800006a4 <inst_54>:
800006a4:	dff00593          	li	a1,-513
800006a8:	08c60513          	addi	a0,a2,140
800006ac:	aaa00793          	li	a5,-1366
800006b0:	40f50533          	sub	a0,a0,a5
800006b4:	aab52523          	sw	a1,-1366(a0)
800006b8:	00000013          	nop
800006bc:	00000013          	nop

800006c0 <inst_55>:
800006c0:	bff00593          	li	a1,-1025
800006c4:	09060513          	addi	a0,a2,144
800006c8:	aaa00793          	li	a5,-1366
800006cc:	40f50533          	sub	a0,a0,a5
800006d0:	aab52523          	sw	a1,-1366(a0)
800006d4:	00000013          	nop
800006d8:	00000013          	nop

800006dc <inst_56>:
800006dc:	fffff5b7          	lui	a1,0xfffff
800006e0:	7ff58593          	addi	a1,a1,2047 # fffff7ff <imme+0xfffffd55>
800006e4:	09460513          	addi	a0,a2,148
800006e8:	00500793          	li	a5,5
800006ec:	40f50533          	sub	a0,a0,a5
800006f0:	00b522a3          	sw	a1,5(a0)
800006f4:	00000013          	nop
800006f8:	00000013          	nop

800006fc <inst_57>:
800006fc:	fffff5b7          	lui	a1,0xfffff
80000700:	fff58593          	addi	a1,a1,-1 # ffffefff <imme+0xfffff555>
80000704:	09860513          	addi	a0,a2,152
80000708:	ffd00793          	li	a5,-3
8000070c:	40f50533          	sub	a0,a0,a5
80000710:	feb52ea3          	sw	a1,-3(a0)
80000714:	00000013          	nop
80000718:	00000013          	nop

8000071c <inst_58>:
8000071c:	ffffe5b7          	lui	a1,0xffffe
80000720:	fff58593          	addi	a1,a1,-1 # ffffdfff <imme+0xffffe555>
80000724:	09c60513          	addi	a0,a2,156
80000728:	fef00793          	li	a5,-17
8000072c:	40f50533          	sub	a0,a0,a5
80000730:	feb527a3          	sw	a1,-17(a0)
80000734:	00000013          	nop
80000738:	00000013          	nop

8000073c <inst_59>:
8000073c:	ffffc5b7          	lui	a1,0xffffc
80000740:	fff58593          	addi	a1,a1,-1 # ffffbfff <imme+0xffffc555>
80000744:	0a060513          	addi	a0,a2,160
80000748:	00600793          	li	a5,6
8000074c:	40f50533          	sub	a0,a0,a5
80000750:	00b52323          	sw	a1,6(a0)
80000754:	00000013          	nop
80000758:	00000013          	nop

8000075c <inst_60>:
8000075c:	ffff85b7          	lui	a1,0xffff8
80000760:	fff58593          	addi	a1,a1,-1 # ffff7fff <imme+0xffff8555>
80000764:	0a460513          	addi	a0,a2,164
80000768:	fbf00793          	li	a5,-65
8000076c:	40f50533          	sub	a0,a0,a5
80000770:	fab52fa3          	sw	a1,-65(a0)
80000774:	00000013          	nop
80000778:	00000013          	nop

8000077c <inst_61>:
8000077c:	ffff05b7          	lui	a1,0xffff0
80000780:	fff58593          	addi	a1,a1,-1 # fffeffff <imme+0xffff0555>
80000784:	0a860513          	addi	a0,a2,168
80000788:	ff700793          	li	a5,-9
8000078c:	40f50533          	sub	a0,a0,a5
80000790:	feb52ba3          	sw	a1,-9(a0)
80000794:	00000013          	nop
80000798:	00000013          	nop

8000079c <inst_62>:
8000079c:	fffe05b7          	lui	a1,0xfffe0
800007a0:	fff58593          	addi	a1,a1,-1 # fffdffff <imme+0xfffe0555>
800007a4:	0ac60513          	addi	a0,a2,172
800007a8:	fff00793          	li	a5,-1
800007ac:	40f50533          	sub	a0,a0,a5
800007b0:	feb52fa3          	sw	a1,-1(a0)
800007b4:	00000013          	nop
800007b8:	00000013          	nop

800007bc <inst_63>:
800007bc:	fffc05b7          	lui	a1,0xfffc0
800007c0:	fff58593          	addi	a1,a1,-1 # fffbffff <imme+0xfffc0555>
800007c4:	0b060513          	addi	a0,a2,176
800007c8:	40000793          	li	a5,1024
800007cc:	40f50533          	sub	a0,a0,a5
800007d0:	40b52023          	sw	a1,1024(a0)
800007d4:	00000013          	nop
800007d8:	00000013          	nop

800007dc <inst_64>:
800007dc:	fff805b7          	lui	a1,0xfff80
800007e0:	fff58593          	addi	a1,a1,-1 # fff7ffff <imme+0xfff80555>
800007e4:	0b460513          	addi	a0,a2,180
800007e8:	00900793          	li	a5,9
800007ec:	40f50533          	sub	a0,a0,a5
800007f0:	00b524a3          	sw	a1,9(a0)
800007f4:	00000013          	nop
800007f8:	00000013          	nop

800007fc <inst_65>:
800007fc:	fff005b7          	lui	a1,0xfff00
80000800:	fff58593          	addi	a1,a1,-1 # ffefffff <imme+0xfff00555>
80000804:	0b860513          	addi	a0,a2,184
80000808:	00100793          	li	a5,1
8000080c:	40f50533          	sub	a0,a0,a5
80000810:	00b520a3          	sw	a1,1(a0)
80000814:	00000013          	nop
80000818:	00000013          	nop

8000081c <inst_66>:
8000081c:	ffe005b7          	lui	a1,0xffe00
80000820:	fff58593          	addi	a1,a1,-1 # ffdfffff <imme+0xffe00555>
80000824:	0bc60513          	addi	a0,a2,188
80000828:	02000793          	li	a5,32
8000082c:	40f50533          	sub	a0,a0,a5
80000830:	02b52023          	sw	a1,32(a0)
80000834:	00000013          	nop
80000838:	00000013          	nop

8000083c <inst_67>:
8000083c:	00100593          	li	a1,1
80000840:	0c060513          	addi	a0,a2,192
80000844:	55500793          	li	a5,1365
80000848:	40f50533          	sub	a0,a0,a5
8000084c:	54b52aa3          	sw	a1,1365(a0)
80000850:	00000013          	nop
80000854:	00000013          	nop

80000858 <cleanup_epilogs>:
80000858:	0040006f          	j	8000085c <exit_cleanup>

8000085c <exit_cleanup>:
8000085c:	00100093          	li	ra,1

80000860 <write_tohost>:
80000860:	00000f17          	auipc	t5,0x0
80000864:	7a1f2023          	sw	ra,1952(t5) # 80001000 <tohost>
80000868:	ff9ff06f          	j	80000860 <write_tohost>
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
80002020:	deadbeef          	jal	t4,7ffdd60a <absimm+0x7ffdd0b5>
80002024:	deadbeef          	jal	t4,7ffdd60e <absimm+0x7ffdd0b9>

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

80003114 <signature_x2_0>:
80003114:	deadbeef          	jal	t4,7ffde6fe <absimm+0x7ffde1a9>
80003118:	deadbeef          	jal	t4,7ffde702 <absimm+0x7ffde1ad>
8000311c:	deadbeef          	jal	t4,7ffde706 <absimm+0x7ffde1b1>
80003120:	deadbeef          	jal	t4,7ffde70a <absimm+0x7ffde1b5>
80003124:	deadbeef          	jal	t4,7ffde70e <absimm+0x7ffde1b9>
80003128:	deadbeef          	jal	t4,7ffde712 <absimm+0x7ffde1bd>
8000312c:	deadbeef          	jal	t4,7ffde716 <absimm+0x7ffde1c1>
80003130:	deadbeef          	jal	t4,7ffde71a <absimm+0x7ffde1c5>
80003134:	deadbeef          	jal	t4,7ffde71e <absimm+0x7ffde1c9>
80003138:	deadbeef          	jal	t4,7ffde722 <absimm+0x7ffde1cd>
8000313c:	deadbeef          	jal	t4,7ffde726 <absimm+0x7ffde1d1>
80003140:	deadbeef          	jal	t4,7ffde72a <absimm+0x7ffde1d5>
80003144:	deadbeef          	jal	t4,7ffde72e <absimm+0x7ffde1d9>
80003148:	deadbeef          	jal	t4,7ffde732 <absimm+0x7ffde1dd>
8000314c:	deadbeef          	jal	t4,7ffde736 <absimm+0x7ffde1e1>
80003150:	deadbeef          	jal	t4,7ffde73a <absimm+0x7ffde1e5>
80003154:	deadbeef          	jal	t4,7ffde73e <absimm+0x7ffde1e9>
80003158:	deadbeef          	jal	t4,7ffde742 <absimm+0x7ffde1ed>
8000315c:	deadbeef          	jal	t4,7ffde746 <absimm+0x7ffde1f1>

80003160 <signature_x12_0>:
80003160:	deadbeef          	jal	t4,7ffde74a <absimm+0x7ffde1f5>
80003164:	deadbeef          	jal	t4,7ffde74e <absimm+0x7ffde1f9>
80003168:	deadbeef          	jal	t4,7ffde752 <absimm+0x7ffde1fd>
8000316c:	deadbeef          	jal	t4,7ffde756 <absimm+0x7ffde201>
80003170:	deadbeef          	jal	t4,7ffde75a <absimm+0x7ffde205>
80003174:	deadbeef          	jal	t4,7ffde75e <absimm+0x7ffde209>
80003178:	deadbeef          	jal	t4,7ffde762 <absimm+0x7ffde20d>
8000317c:	deadbeef          	jal	t4,7ffde766 <absimm+0x7ffde211>
80003180:	deadbeef          	jal	t4,7ffde76a <absimm+0x7ffde215>
80003184:	deadbeef          	jal	t4,7ffde76e <absimm+0x7ffde219>
80003188:	deadbeef          	jal	t4,7ffde772 <absimm+0x7ffde21d>
8000318c:	deadbeef          	jal	t4,7ffde776 <absimm+0x7ffde221>
80003190:	deadbeef          	jal	t4,7ffde77a <absimm+0x7ffde225>
80003194:	deadbeef          	jal	t4,7ffde77e <absimm+0x7ffde229>
80003198:	deadbeef          	jal	t4,7ffde782 <absimm+0x7ffde22d>
8000319c:	deadbeef          	jal	t4,7ffde786 <absimm+0x7ffde231>
800031a0:	deadbeef          	jal	t4,7ffde78a <absimm+0x7ffde235>
800031a4:	deadbeef          	jal	t4,7ffde78e <absimm+0x7ffde239>
800031a8:	deadbeef          	jal	t4,7ffde792 <absimm+0x7ffde23d>
800031ac:	deadbeef          	jal	t4,7ffde796 <absimm+0x7ffde241>
800031b0:	deadbeef          	jal	t4,7ffde79a <absimm+0x7ffde245>
800031b4:	deadbeef          	jal	t4,7ffde79e <absimm+0x7ffde249>
800031b8:	deadbeef          	jal	t4,7ffde7a2 <absimm+0x7ffde24d>
800031bc:	deadbeef          	jal	t4,7ffde7a6 <absimm+0x7ffde251>
800031c0:	deadbeef          	jal	t4,7ffde7aa <absimm+0x7ffde255>
800031c4:	deadbeef          	jal	t4,7ffde7ae <absimm+0x7ffde259>
800031c8:	deadbeef          	jal	t4,7ffde7b2 <absimm+0x7ffde25d>
800031cc:	deadbeef          	jal	t4,7ffde7b6 <absimm+0x7ffde261>
800031d0:	deadbeef          	jal	t4,7ffde7ba <absimm+0x7ffde265>
800031d4:	deadbeef          	jal	t4,7ffde7be <absimm+0x7ffde269>
800031d8:	deadbeef          	jal	t4,7ffde7c2 <absimm+0x7ffde26d>
800031dc:	deadbeef          	jal	t4,7ffde7c6 <absimm+0x7ffde271>
800031e0:	deadbeef          	jal	t4,7ffde7ca <absimm+0x7ffde275>
800031e4:	deadbeef          	jal	t4,7ffde7ce <absimm+0x7ffde279>
800031e8:	deadbeef          	jal	t4,7ffde7d2 <absimm+0x7ffde27d>
800031ec:	deadbeef          	jal	t4,7ffde7d6 <absimm+0x7ffde281>
800031f0:	deadbeef          	jal	t4,7ffde7da <absimm+0x7ffde285>
800031f4:	deadbeef          	jal	t4,7ffde7de <absimm+0x7ffde289>
800031f8:	deadbeef          	jal	t4,7ffde7e2 <absimm+0x7ffde28d>
800031fc:	deadbeef          	jal	t4,7ffde7e6 <absimm+0x7ffde291>
80003200:	deadbeef          	jal	t4,7ffde7ea <absimm+0x7ffde295>
80003204:	deadbeef          	jal	t4,7ffde7ee <absimm+0x7ffde299>
80003208:	deadbeef          	jal	t4,7ffde7f2 <absimm+0x7ffde29d>
8000320c:	deadbeef          	jal	t4,7ffde7f6 <absimm+0x7ffde2a1>
80003210:	deadbeef          	jal	t4,7ffde7fa <absimm+0x7ffde2a5>
80003214:	deadbeef          	jal	t4,7ffde7fe <absimm+0x7ffde2a9>
80003218:	deadbeef          	jal	t4,7ffde802 <absimm+0x7ffde2ad>
8000321c:	deadbeef          	jal	t4,7ffde806 <absimm+0x7ffde2b1>
80003220:	deadbeef          	jal	t4,7ffde80a <absimm+0x7ffde2b5>

80003224 <sig_end_canary>:
80003224:	a309                	j	80003726 <_end+0x4f6>
80003226:	6f5c                	flw	fa5,28(a4)

80003228 <rvtest_sig_end>:
	...

Disassembly of section .riscv.attributes:

00000000 <.riscv.attributes>:
   0:	1941                	addi	s2,s2,-16
   2:	0000                	unimp
   4:	7200                	flw	fs0,32(a2)
   6:	7369                	lui	t1,0xffffa
   8:	01007663          	bgeu	zero,a6,14 <MMODE_SIG+0x11>
   c:	0000000f          	fence	unknown,unknown
  10:	7205                	lui	tp,0xfffe1
  12:	3376                	fld	ft6,376(sp)
  14:	6932                	flw	fs2,12(sp)
  16:	7032                	flw	ft0,44(sp)
  18:	0030                	addi	a2,sp,8

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	0000023f 00790003 	0x7900030000023f
   8:	0000                	unimp
   a:	0101                	addi	sp,sp,0
   c:	000d0efb          	0xd0efb
  10:	0101                	addi	sp,sp,0
  12:	0101                	addi	sp,sp,0
  14:	0000                	unimp
  16:	0100                	addi	s0,sp,128
  18:	0000                	unimp
  1a:	2f01                	jal	72a <absimm+0x1d5>
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
  44:	612d7663          	bgeu	s10,s2,650 <absimm+0xfb>
  48:	6372                	flw	ft6,28(sp)
  4a:	2d68                	fld	fa0,216(a0)
  4c:	6574                	flw	fa3,76(a0)
  4e:	722f7473          	csrrci	s0,0x722,30
  52:	7369                	lui	t1,0xffffa
  54:	742d7663          	bgeu	s10,sp,7a0 <absimm+0x24b>
  58:	7365                	lui	t1,0xffff9
  5a:	2d74                	fld	fa3,216(a0)
  5c:	74697573          	csrrci	a0,0x746,18
  60:	2f65                	jal	818 <absimm+0x2c3>
  62:	7672                	flw	fa2,60(sp)
  64:	5f693233          	0x5f693233
  68:	2f6d                	jal	822 <absimm+0x2cd>
  6a:	2f49                	jal	7fc <absimm+0x2a7>
  6c:	00637273          	csrrci	tp,0x6,6
  70:	7300                	flw	fs0,32(a4)
  72:	6c612d77          	0x6c612d77
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
  b4:	001c                	0x1c
  b6:	0301                	addi	t1,t1,0
  b8:	0905                	addi	s2,s2,1
  ba:	001c                	0x1c
  bc:	0301                	addi	t1,t1,0
  be:	0905                	addi	s2,s2,1
  c0:	001c                	0x1c
  c2:	0301                	addi	t1,t1,0
  c4:	0905                	addi	s2,s2,1
  c6:	001c                	0x1c
  c8:	0301                	addi	t1,t1,0
  ca:	0905                	addi	s2,s2,1
  cc:	001c                	0x1c
  ce:	0301                	addi	t1,t1,0
  d0:	0905                	addi	s2,s2,1
  d2:	001c                	0x1c
  d4:	0301                	addi	t1,t1,0
  d6:	0905                	addi	s2,s2,1
  d8:	001c                	0x1c
  da:	0301                	addi	t1,t1,0
  dc:	0905                	addi	s2,s2,1
  de:	001c                	0x1c
  e0:	0301                	addi	t1,t1,0
  e2:	0905                	addi	s2,s2,1
  e4:	001c                	0x1c
  e6:	0301                	addi	t1,t1,0
  e8:	0905                	addi	s2,s2,1
  ea:	001c                	0x1c
  ec:	0301                	addi	t1,t1,0
  ee:	0905                	addi	s2,s2,1
  f0:	001c                	0x1c
  f2:	0301                	addi	t1,t1,0
  f4:	0905                	addi	s2,s2,1
  f6:	001c                	0x1c
  f8:	0301                	addi	t1,t1,0
  fa:	0905                	addi	s2,s2,1
  fc:	0020                	addi	s0,sp,8
  fe:	0301                	addi	t1,t1,0
 100:	0905                	addi	s2,s2,1
 102:	001c                	0x1c
 104:	0301                	addi	t1,t1,0
 106:	0901                	addi	s2,s2,0
 108:	001c                	0x1c
 10a:	0301                	addi	t1,t1,0
 10c:	0905                	addi	s2,s2,1
 10e:	0008                	0x8
 110:	0301                	addi	t1,t1,0
 112:	0905                	addi	s2,s2,1
 114:	001c                	0x1c
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
 144:	001c                	0x1c
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
 17a:	0020                	addi	s0,sp,8
 17c:	0301                	addi	t1,t1,0
 17e:	0905                	addi	s2,s2,1
 180:	0020                	addi	s0,sp,8
 182:	0301                	addi	t1,t1,0
 184:	0905                	addi	s2,s2,1
 186:	0020                	addi	s0,sp,8
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
 1bc:	001c                	0x1c
 1be:	0301                	addi	t1,t1,0
 1c0:	0905                	addi	s2,s2,1
 1c2:	001c                	0x1c
 1c4:	0301                	addi	t1,t1,0
 1c6:	0905                	addi	s2,s2,1
 1c8:	001c                	0x1c
 1ca:	0301                	addi	t1,t1,0
 1cc:	0905                	addi	s2,s2,1
 1ce:	001c                	0x1c
 1d0:	0301                	addi	t1,t1,0
 1d2:	0905                	addi	s2,s2,1
 1d4:	001c                	0x1c
 1d6:	0301                	addi	t1,t1,0
 1d8:	0905                	addi	s2,s2,1
 1da:	001c                	0x1c
 1dc:	0301                	addi	t1,t1,0
 1de:	0905                	addi	s2,s2,1
 1e0:	001c                	0x1c
 1e2:	0301                	addi	t1,t1,0
 1e4:	0905                	addi	s2,s2,1
 1e6:	001c                	0x1c
 1e8:	0301                	addi	t1,t1,0
 1ea:	0905                	addi	s2,s2,1
 1ec:	001c                	0x1c
 1ee:	0301                	addi	t1,t1,0
 1f0:	0905                	addi	s2,s2,1
 1f2:	0020                	addi	s0,sp,8
 1f4:	0301                	addi	t1,t1,0
 1f6:	0905                	addi	s2,s2,1
 1f8:	0020                	addi	s0,sp,8
 1fa:	0301                	addi	t1,t1,0
 1fc:	0905                	addi	s2,s2,1
 1fe:	0020                	addi	s0,sp,8
 200:	0301                	addi	t1,t1,0
 202:	0905                	addi	s2,s2,1
 204:	0020                	addi	s0,sp,8
 206:	0301                	addi	t1,t1,0
 208:	0905                	addi	s2,s2,1
 20a:	0020                	addi	s0,sp,8
 20c:	0301                	addi	t1,t1,0
 20e:	0905                	addi	s2,s2,1
 210:	0020                	addi	s0,sp,8
 212:	0301                	addi	t1,t1,0
 214:	0905                	addi	s2,s2,1
 216:	0020                	addi	s0,sp,8
 218:	0301                	addi	t1,t1,0
 21a:	0905                	addi	s2,s2,1
 21c:	0020                	addi	s0,sp,8
 21e:	0301                	addi	t1,t1,0
 220:	0905                	addi	s2,s2,1
 222:	0020                	addi	s0,sp,8
 224:	0301                	addi	t1,t1,0
 226:	0905                	addi	s2,s2,1
 228:	0020                	addi	s0,sp,8
 22a:	0301                	addi	t1,t1,0
 22c:	0905                	addi	s2,s2,1
 22e:	0020                	addi	s0,sp,8
 230:	0301                	addi	t1,t1,0
 232:	0904                	addi	s1,sp,144
 234:	001c                	0x1c
 236:	0301                	addi	t1,t1,0
 238:	0901                	addi	s2,s2,0
 23a:	0004                	0x4
 23c:	0901                	addi	s2,s2,0
 23e:	0010                	0x10
 240:	0100                	addi	s0,sp,128
 242:	01              	Address 0x0000000000000242 is out of bounds.


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
  14:	086c                	addi	a1,sp,28
  16:	8000                	0x8000
  18:	0000                	unimp
  1a:	0000                	unimp
  1c:	00000063          	beqz	zero,1c <MMODE_SIG+0x19>
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
  14:	086c                	addi	a1,sp,28
	...

Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	6d6f682f          	0x6d6f682f
   4:	2f65                	jal	7bc <absimm+0x267>
   6:	6f6c                	flw	fa1,92(a4)
   8:	6976                	flw	fs2,92(sp)
   a:	65442f73          	csrrs	t5,0x654,s0
   e:	6f746b73          	csrrsi	s6,0x6f7,8
  12:	2f70                	fld	fa2,216(a4)
  14:	6952                	flw	fs2,20(sp)
  16:	6556                	flw	fa0,84(sp)
  18:	5f72                	lw	t5,60(sp)
  1a:	65726f63          	bltu	tp,s7,678 <absimm+0x123>
  1e:	7369722f          	0x7369722f
  22:	2f666f63          	bltu	a2,s6,320 <absimmsh+0x76>
  26:	6972                	flw	fs2,28(sp)
  28:	2d766373          	csrrsi	t1,0x2d7,12
  2c:	7261                	lui	tp,0xffff8
  2e:	742d6863          	bltu	s10,sp,77e <absimm+0x229>
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
  54:	2d77732f          	0x2d77732f
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
  8c:	5f666f63          	bltu	a2,s6,68a <absimm+0x135>
  90:	6b726f77          	0x6b726f77
  94:	3376722f          	0x3376722f
  98:	6932                	flw	fs2,12(sp)
  9a:	6d5f 492f 732f      	0x732f492f6d5f
  a0:	6372                	flw	ft6,28(sp)
  a2:	2d77732f          	0x2d77732f
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
