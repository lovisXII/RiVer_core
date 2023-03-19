
my.elf:     file format elf32-littleriscv


Disassembly of section .text.init:

80000000 <rvtest_entry_point>:
80000000:	feedc0b7          	lui	ra,0xfeedc
80000004:	ead08093          	addi	ra,ra,-339 # feedbead <imm12sh+0xfeedbeaf>
80000008:	ff76e137          	lui	sp,0xff76e
8000000c:	f5610113          	addi	sp,sp,-170 # ff76df56 <imm12sh+0xff76df58>
80000010:	7fbb71b7          	lui	gp,0x7fbb7
80000014:	fab18193          	addi	gp,gp,-85 # 7fbb6fab <absimmsh+0x7f3b6fad>
80000018:	bfddb237          	lui	tp,0xbfddb
8000001c:	7d520213          	addi	tp,tp,2005 # bfddb7d5 <imm12sh+0xbfddb7d7>
80000020:	00000297          	auipc	t0,0x0
80000024:	05828293          	addi	t0,t0,88 # 80000078 <rvtest_code_begin>
80000028:	00002317          	auipc	t1,0x2
8000002c:	fe830313          	addi	t1,t1,-24 # 80002010 <rvtest_data_begin>
80000030:	b7fbb3b7          	lui	t2,0xb7fbb
80000034:	6fa38393          	addi	t2,t2,1786 # b7fbb6fa <imm12sh+0xb7fbb6fc>
80000038:	5bfde437          	lui	s0,0x5bfde
8000003c:	b7d40413          	addi	s0,s0,-1155 # 5bfddb7d <absimmsh+0x5b7ddb7f>
80000040:	adfef4b7          	lui	s1,0xadfef
80000044:	dbe48493          	addi	s1,s1,-578 # adfeedbe <imm12sh+0xadfeedc0>
80000048:	56ff7537          	lui	a0,0x56ff7
8000004c:	6df50513          	addi	a0,a0,1759 # 56ff76df <absimmsh+0x567f76e1>
80000050:	ab7fc5b7          	lui	a1,0xab7fc
80000054:	b6f58593          	addi	a1,a1,-1169 # ab7fbb6f <imm12sh+0xab7fbb71>
80000058:	d5bfe637          	lui	a2,0xd5bfe
8000005c:	db760613          	addi	a2,a2,-585 # d5bfddb7 <imm12sh+0xd5bfddb9>
80000060:	eadff6b7          	lui	a3,0xeadff
80000064:	edb68693          	addi	a3,a3,-293 # eadfeedb <imm12sh+0xeadfeedd>
80000068:	f56ff737          	lui	a4,0xf56ff
8000006c:	76d70713          	addi	a4,a4,1901 # f56ff76d <imm12sh+0xf56ff76f>
80000070:	fab807b7          	lui	a5,0xfab80
80000074:	bb678793          	addi	a5,a5,-1098 # fab7fbb6 <imm12sh+0xfab7fbb8>

80000078 <rvtest_code_begin>:
80000078:	00003217          	auipc	tp,0x3
8000007c:	09c20213          	addi	tp,tp,156 # 80003114 <signature_x4_0>

80000080 <inst_0>:
80000080:	80000d37          	lui	s10,0x80000
80000084:	00020793          	mv	a5,tp
80000088:	00700813          	li	a6,7
8000008c:	410787b3          	sub	a5,a5,a6
80000090:	01a793a3          	sh	s10,7(a5)
80000094:	00000013          	nop
80000098:	00000013          	nop

8000009c <inst_1>:
8000009c:	00000393          	li	t2,0
800000a0:	00420513          	addi	a0,tp,4 # 4 <MMODE_SIG+0x1>
800000a4:	ffb00813          	li	a6,-5
800000a8:	41050533          	sub	a0,a0,a6
800000ac:	fe751da3          	sh	t2,-5(a0)
800000b0:	00000013          	nop
800000b4:	00000013          	nop

800000b8 <inst_2>:
800000b8:	80000437          	lui	s0,0x80000
800000bc:	fff40413          	addi	s0,s0,-1 # 7fffffff <imm12sh+0x80000001>
800000c0:	00820093          	addi	ra,tp,8 # 8 <MMODE_SIG+0x5>
800000c4:	01000813          	li	a6,16
800000c8:	410080b3          	sub	ra,ra,a6
800000cc:	00809823          	sh	s0,16(ra)
800000d0:	00000013          	nop
800000d4:	00000013          	nop

800000d8 <inst_3>:
800000d8:	00100d93          	li	s11,1
800000dc:	00c20b13          	addi	s6,tp,12 # c <edge2+0x2>
800000e0:	fdf00813          	li	a6,-33
800000e4:	410b0b33          	sub	s6,s6,a6
800000e8:	fdbb1fa3          	sh	s11,-33(s6)
800000ec:	00000013          	nop
800000f0:	00000013          	nop

800000f4 <inst_4>:
800000f4:	c0000937          	lui	s2,0xc0000
800000f8:	01020713          	addi	a4,tp,16 # 10 <edge2+0x6>
800000fc:	ff900813          	li	a6,-7
80000100:	41070733          	sub	a4,a4,a6
80000104:	ff271ca3          	sh	s2,-7(a4)
80000108:	00000013          	nop
8000010c:	00000013          	nop

80000110 <inst_5>:
80000110:	fffc0137          	lui	sp,0xfffc0
80000114:	fff10113          	addi	sp,sp,-1 # fffbffff <imm12sh+0xfffc0001>
80000118:	01420993          	addi	s3,tp,20 # 14 <edge2+0xa>
8000011c:	ff600813          	li	a6,-10
80000120:	410989b3          	sub	s3,s3,a6
80000124:	fe299b23          	sh	sp,-10(s3)
80000128:	00000013          	nop
8000012c:	00000013          	nop

80000130 <inst_6>:
80000130:	ff700493          	li	s1,-9
80000134:	01a20c13          	addi	s8,tp,26 # 1a <edge2+0x10>
80000138:	00800813          	li	a6,8
8000013c:	410c0c33          	sub	s8,s8,a6
80000140:	009c1423          	sh	s1,8(s8)
80000144:	00000013          	nop
80000148:	00000013          	nop

8000014c <inst_7>:
8000014c:	40000c93          	li	s9,1024
80000150:	01e20193          	addi	gp,tp,30 # 1e <edge2+0x14>
80000154:	ffd00813          	li	a6,-3
80000158:	410181b3          	sub	gp,gp,a6
8000015c:	ff919ea3          	sh	s9,-3(gp)
80000160:	00000013          	nop
80000164:	00000013          	nop

80000168 <inst_8>:
80000168:	fffc0f37          	lui	t5,0xfffc0
8000016c:	ffff0f13          	addi	t5,t5,-1 # fffbffff <imm12sh+0xfffc0001>
80000170:	02220593          	addi	a1,tp,34 # 22 <pos+0x2>
80000174:	00200813          	li	a6,2
80000178:	410585b3          	sub	a1,a1,a6
8000017c:	01e59123          	sh	t5,2(a1)
80000180:	00000013          	nop
80000184:	00000013          	nop

80000188 <inst_9>:
80000188:	20000693          	li	a3,512
8000018c:	02620d13          	addi	s10,tp,38 # 26 <pos+0x6>
80000190:	ff700813          	li	a6,-9
80000194:	410d0d33          	sub	s10,s10,a6
80000198:	fedd1ba3          	sh	a3,-9(s10) # 7ffffff7 <imm12sh+0x7ffffff9>
8000019c:	00000013          	nop
800001a0:	00000013          	nop

800001a4 <inst_10>:
800001a4:	c00005b7          	lui	a1,0xc0000
800001a8:	02820313          	addi	t1,tp,40 # 28 <pos+0x8>
800001ac:	00000813          	li	a6,0
800001b0:	41030333          	sub	t1,t1,a6
800001b4:	00b31023          	sh	a1,0(t1)
800001b8:	00000013          	nop
800001bc:	00000013          	nop

800001c0 <inst_11>:
800001c0:	00200a13          	li	s4,2
800001c4:	02c20613          	addi	a2,tp,44 # 2c <pos+0xc>
800001c8:	00000813          	li	a6,0
800001cc:	41060633          	sub	a2,a2,a6
800001d0:	01461023          	sh	s4,0(a2)
800001d4:	00000013          	nop
800001d8:	00000013          	nop

800001dc <inst_12>:
800001dc:	00400713          	li	a4,4
800001e0:	03020393          	addi	t2,tp,48 # 30 <pos+0x10>
800001e4:	04000813          	li	a6,64
800001e8:	410383b3          	sub	t2,t2,a6
800001ec:	04e39023          	sh	a4,64(t2)
800001f0:	00000013          	nop
800001f4:	00000013          	nop

800001f8 <inst_13>:
800001f8:	00800093          	li	ra,8
800001fc:	03420693          	addi	a3,tp,52 # 34 <pos+0x14>
80000200:	fff00813          	li	a6,-1
80000204:	410686b3          	sub	a3,a3,a6
80000208:	fe169fa3          	sh	ra,-1(a3)
8000020c:	00000013          	nop
80000210:	00000013          	nop

80000214 <inst_14>:
80000214:	01000313          	li	t1,16
80000218:	03820d93          	addi	s11,tp,56 # 38 <pos+0x18>
8000021c:	ff800813          	li	a6,-8
80000220:	410d8db3          	sub	s11,s11,a6
80000224:	fe6d9c23          	sh	t1,-8(s11)
80000228:	00000013          	nop
8000022c:	00000013          	nop

80000230 <inst_15>:
80000230:	02000b13          	li	s6,32
80000234:	03c20f93          	addi	t6,tp,60 # 3c <pos+0x1c>
80000238:	04000813          	li	a6,64
8000023c:	410f8fb3          	sub	t6,t6,a6
80000240:	056f9023          	sh	s6,64(t6)
80000244:	00000013          	nop
80000248:	00000013          	nop

8000024c <inst_16>:
8000024c:	04000a93          	li	s5,64
80000250:	04020413          	addi	s0,tp,64 # 40 <pos+0x20>
80000254:	ffe00813          	li	a6,-2
80000258:	41040433          	sub	s0,s0,a6
8000025c:	ff541f23          	sh	s5,-2(s0)
80000260:	00000013          	nop
80000264:	00000013          	nop

80000268 <inst_17>:
80000268:	08000e13          	li	t3,128
8000026c:	04420293          	addi	t0,tp,68 # 44 <pos+0x24>
80000270:	80000813          	li	a6,-2048
80000274:	410282b3          	sub	t0,t0,a6
80000278:	81c29023          	sh	t3,-2048(t0)
8000027c:	00000013          	nop
80000280:	00000013          	nop

80000284 <inst_18>:
80000284:	10000793          	li	a5,256
80000288:	04820913          	addi	s2,tp,72 # 48 <pos+0x28>
8000028c:	00700813          	li	a6,7
80000290:	41090933          	sub	s2,s2,a6
80000294:	00f913a3          	sh	a5,7(s2) # c0000007 <imm12sh+0xc0000009>
80000298:	00000013          	nop
8000029c:	00000013          	nop

800002a0 <inst_19>:
800002a0:	000018b7          	lui	a7,0x1
800002a4:	80088893          	addi	a7,a7,-2048 # 800 <absimm+0x600>
800002a8:	04c20e93          	addi	t4,tp,76 # 4c <pos+0x2c>
800002ac:	ffe00813          	li	a6,-2
800002b0:	410e8eb3          	sub	t4,t4,a6
800002b4:	ff1e9f23          	sh	a7,-2(t4)
800002b8:	00000013          	nop
800002bc:	00000013          	nop
800002c0:	00003097          	auipc	ra,0x3
800002c4:	ea408093          	addi	ra,ra,-348 # 80003164 <signature_x1_0>

800002c8 <inst_20>:
800002c8:	000011b7          	lui	gp,0x1
800002cc:	00008b93          	mv	s7,ra
800002d0:	7ff00313          	li	t1,2047
800002d4:	406b8bb3          	sub	s7,s7,t1
800002d8:	7e3b9fa3          	sh	gp,2047(s7)
800002dc:	00000013          	nop
800002e0:	00000013          	nop

800002e4 <inst_21>:
800002e4:	00002637          	lui	a2,0x2
800002e8:	00408a13          	addi	s4,ra,4
800002ec:	ffe00313          	li	t1,-2
800002f0:	406a0a33          	sub	s4,s4,t1
800002f4:	feca1f23          	sh	a2,-2(s4)
800002f8:	00000013          	nop
800002fc:	00000013          	nop

80000300 <inst_22>:
80000300:	00004eb7          	lui	t4,0x4
80000304:	00808813          	addi	a6,ra,8
80000308:	00300313          	li	t1,3
8000030c:	40680833          	sub	a6,a6,t1
80000310:	01d811a3          	sh	t4,3(a6)
80000314:	00000013          	nop
80000318:	00000013          	nop

8000031c <inst_23>:
8000031c:	00000013          	nop
80000320:	00c08c93          	addi	s9,ra,12
80000324:	dff00313          	li	t1,-513
80000328:	406c8cb3          	sub	s9,s9,t1
8000032c:	de0c9fa3          	sh	zero,-513(s9)
80000330:	00000013          	nop
80000334:	00000013          	nop

80000338 <inst_24>:
80000338:	000102b7          	lui	t0,0x10
8000033c:	01008213          	addi	tp,ra,16
80000340:	02000313          	li	t1,32
80000344:	40620233          	sub	tp,tp,t1
80000348:	02521023          	sh	t0,32(tp) # 20 <pos>
8000034c:	00000013          	nop
80000350:	00000013          	nop

80000354 <inst_25>:
80000354:	00020bb7          	lui	s7,0x20
80000358:	01408f13          	addi	t5,ra,20
8000035c:	01000313          	li	t1,16
80000360:	406f0f33          	sub	t5,t5,t1
80000364:	017f1823          	sh	s7,16(t5)
80000368:	00000013          	nop
8000036c:	00000013          	nop

80000370 <inst_26>:
80000370:	00040c37          	lui	s8,0x40
80000374:	01808e13          	addi	t3,ra,24
80000378:	00000313          	li	t1,0
8000037c:	406e0e33          	sub	t3,t3,t1
80000380:	018e1023          	sh	s8,0(t3)
80000384:	00000013          	nop
80000388:	00000013          	nop

8000038c <inst_27>:
8000038c:	00080537          	lui	a0,0x80
80000390:	01c08a93          	addi	s5,ra,28
80000394:	7ff00313          	li	t1,2047
80000398:	406a8ab3          	sub	s5,s5,t1
8000039c:	7eaa9fa3          	sh	a0,2047(s5)
800003a0:	00000013          	nop
800003a4:	00000013          	nop

800003a8 <inst_28>:
800003a8:	00100837          	lui	a6,0x100
800003ac:	02008893          	addi	a7,ra,32
800003b0:	bff00313          	li	t1,-1025
800003b4:	406888b3          	sub	a7,a7,t1
800003b8:	bf089fa3          	sh	a6,-1025(a7)
800003bc:	00000013          	nop
800003c0:	00000013          	nop

800003c4 <inst_29>:
800003c4:	002009b7          	lui	s3,0x200
800003c8:	02408493          	addi	s1,ra,36
800003cc:	aaa00313          	li	t1,-1366
800003d0:	406484b3          	sub	s1,s1,t1
800003d4:	ab349523          	sh	s3,-1366(s1)
800003d8:	00000013          	nop
800003dc:	00000013          	nop

800003e0 <inst_30>:
800003e0:	00400237          	lui	tp,0x400
800003e4:	02808113          	addi	sp,ra,40
800003e8:	08000313          	li	t1,128
800003ec:	40610133          	sub	sp,sp,t1
800003f0:	08411023          	sh	tp,128(sp)
800003f4:	00000013          	nop
800003f8:	00000013          	nop

800003fc <inst_31>:
800003fc:	00800fb7          	lui	t6,0x800
80000400:	02c08e93          	addi	t4,ra,44
80000404:	00000313          	li	t1,0
80000408:	406e8eb3          	sub	t4,t4,t1
8000040c:	01fe9023          	sh	t6,0(t4) # 4000 <absimm+0x3e00>
80000410:	00000013          	nop
80000414:	00000013          	nop

80000418 <inst_32>:
80000418:	010005b7          	lui	a1,0x1000
8000041c:	03008513          	addi	a0,ra,48
80000420:	3ff00313          	li	t1,1023
80000424:	40650533          	sub	a0,a0,t1
80000428:	3eb51fa3          	sh	a1,1023(a0) # 803ff <absimm+0x801ff>
8000042c:	00000013          	nop
80000430:	00000013          	nop

80000434 <inst_33>:
80000434:	020005b7          	lui	a1,0x2000
80000438:	03408513          	addi	a0,ra,52
8000043c:	7ff00313          	li	t1,2047
80000440:	40650533          	sub	a0,a0,t1
80000444:	7eb51fa3          	sh	a1,2047(a0)
80000448:	00000013          	nop
8000044c:	00000013          	nop

80000450 <inst_34>:
80000450:	040005b7          	lui	a1,0x4000
80000454:	03808513          	addi	a0,ra,56
80000458:	55500313          	li	t1,1365
8000045c:	40650533          	sub	a0,a0,t1
80000460:	54b51aa3          	sh	a1,1365(a0)
80000464:	00000013          	nop
80000468:	00000013          	nop

8000046c <inst_35>:
8000046c:	080005b7          	lui	a1,0x8000
80000470:	03c08513          	addi	a0,ra,60
80000474:	ff800313          	li	t1,-8
80000478:	40650533          	sub	a0,a0,t1
8000047c:	feb51c23          	sh	a1,-8(a0)
80000480:	00000013          	nop
80000484:	00000013          	nop

80000488 <inst_36>:
80000488:	100005b7          	lui	a1,0x10000
8000048c:	04008513          	addi	a0,ra,64
80000490:	00600313          	li	t1,6
80000494:	40650533          	sub	a0,a0,t1
80000498:	00b51323          	sh	a1,6(a0)
8000049c:	00000013          	nop
800004a0:	00000013          	nop

800004a4 <inst_37>:
800004a4:	200005b7          	lui	a1,0x20000
800004a8:	04408513          	addi	a0,ra,68
800004ac:	ffb00313          	li	t1,-5
800004b0:	40650533          	sub	a0,a0,t1
800004b4:	feb51da3          	sh	a1,-5(a0)
800004b8:	00000013          	nop
800004bc:	00000013          	nop

800004c0 <inst_38>:
800004c0:	400005b7          	lui	a1,0x40000
800004c4:	04808513          	addi	a0,ra,72
800004c8:	80000313          	li	t1,-2048
800004cc:	40650533          	sub	a0,a0,t1
800004d0:	80b51023          	sh	a1,-2048(a0)
800004d4:	00000013          	nop
800004d8:	00000013          	nop

800004dc <inst_39>:
800004dc:	fff805b7          	lui	a1,0xfff80
800004e0:	fff58593          	addi	a1,a1,-1 # fff7ffff <imm12sh+0xfff80001>
800004e4:	04c08513          	addi	a0,ra,76
800004e8:	eff00313          	li	t1,-257
800004ec:	40650533          	sub	a0,a0,t1
800004f0:	eeb51fa3          	sh	a1,-257(a0)
800004f4:	00000013          	nop
800004f8:	00000013          	nop

800004fc <inst_40>:
800004fc:	fff005b7          	lui	a1,0xfff00
80000500:	fff58593          	addi	a1,a1,-1 # ffefffff <imm12sh+0xfff00001>
80000504:	05008513          	addi	a0,ra,80
80000508:	04000313          	li	t1,64
8000050c:	40650533          	sub	a0,a0,t1
80000510:	04b51023          	sh	a1,64(a0)
80000514:	00000013          	nop
80000518:	00000013          	nop

8000051c <inst_41>:
8000051c:	ffe005b7          	lui	a1,0xffe00
80000520:	fff58593          	addi	a1,a1,-1 # ffdfffff <imm12sh+0xffe00001>
80000524:	05408513          	addi	a0,ra,84
80000528:	00600313          	li	t1,6
8000052c:	40650533          	sub	a0,a0,t1
80000530:	00b51323          	sh	a1,6(a0)
80000534:	00000013          	nop
80000538:	00000013          	nop

8000053c <inst_42>:
8000053c:	ffc005b7          	lui	a1,0xffc00
80000540:	fff58593          	addi	a1,a1,-1 # ffbfffff <imm12sh+0xffc00001>
80000544:	05808513          	addi	a0,ra,88
80000548:	55500313          	li	t1,1365
8000054c:	40650533          	sub	a0,a0,t1
80000550:	54b51aa3          	sh	a1,1365(a0)
80000554:	00000013          	nop
80000558:	00000013          	nop

8000055c <inst_43>:
8000055c:	ff8005b7          	lui	a1,0xff800
80000560:	fff58593          	addi	a1,a1,-1 # ff7fffff <imm12sh+0xff800001>
80000564:	05c08513          	addi	a0,ra,92
80000568:	00600313          	li	t1,6
8000056c:	40650533          	sub	a0,a0,t1
80000570:	00b51323          	sh	a1,6(a0)
80000574:	00000013          	nop
80000578:	00000013          	nop

8000057c <inst_44>:
8000057c:	ff0005b7          	lui	a1,0xff000
80000580:	fff58593          	addi	a1,a1,-1 # feffffff <imm12sh+0xff000001>
80000584:	06008513          	addi	a0,ra,96
80000588:	00400313          	li	t1,4
8000058c:	40650533          	sub	a0,a0,t1
80000590:	00b51223          	sh	a1,4(a0)
80000594:	00000013          	nop
80000598:	00000013          	nop

8000059c <inst_45>:
8000059c:	fe0005b7          	lui	a1,0xfe000
800005a0:	fff58593          	addi	a1,a1,-1 # fdffffff <imm12sh+0xfe000001>
800005a4:	06408513          	addi	a0,ra,100
800005a8:	bff00313          	li	t1,-1025
800005ac:	40650533          	sub	a0,a0,t1
800005b0:	beb51fa3          	sh	a1,-1025(a0)
800005b4:	00000013          	nop
800005b8:	00000013          	nop

800005bc <inst_46>:
800005bc:	fc0005b7          	lui	a1,0xfc000
800005c0:	fff58593          	addi	a1,a1,-1 # fbffffff <imm12sh+0xfc000001>
800005c4:	06808513          	addi	a0,ra,104
800005c8:	00300313          	li	t1,3
800005cc:	40650533          	sub	a0,a0,t1
800005d0:	00b511a3          	sh	a1,3(a0)
800005d4:	00000013          	nop
800005d8:	00000013          	nop

800005dc <inst_47>:
800005dc:	f80005b7          	lui	a1,0xf8000
800005e0:	fff58593          	addi	a1,a1,-1 # f7ffffff <imm12sh+0xf8000001>
800005e4:	06c08513          	addi	a0,ra,108
800005e8:	00500313          	li	t1,5
800005ec:	40650533          	sub	a0,a0,t1
800005f0:	00b512a3          	sh	a1,5(a0)
800005f4:	00000013          	nop
800005f8:	00000013          	nop

800005fc <inst_48>:
800005fc:	f00005b7          	lui	a1,0xf0000
80000600:	fff58593          	addi	a1,a1,-1 # efffffff <imm12sh+0xf0000001>
80000604:	07008513          	addi	a0,ra,112
80000608:	08000313          	li	t1,128
8000060c:	40650533          	sub	a0,a0,t1
80000610:	08b51023          	sh	a1,128(a0)
80000614:	00000013          	nop
80000618:	00000013          	nop

8000061c <inst_49>:
8000061c:	e00005b7          	lui	a1,0xe0000
80000620:	fff58593          	addi	a1,a1,-1 # dfffffff <imm12sh+0xe0000001>
80000624:	07408513          	addi	a0,ra,116
80000628:	01000313          	li	t1,16
8000062c:	40650533          	sub	a0,a0,t1
80000630:	00b51823          	sh	a1,16(a0)
80000634:	00000013          	nop
80000638:	00000013          	nop

8000063c <inst_50>:
8000063c:	c00005b7          	lui	a1,0xc0000
80000640:	fff58593          	addi	a1,a1,-1 # bfffffff <imm12sh+0xc0000001>
80000644:	07808513          	addi	a0,ra,120
80000648:	dff00313          	li	t1,-513
8000064c:	40650533          	sub	a0,a0,t1
80000650:	deb51fa3          	sh	a1,-513(a0)
80000654:	00000013          	nop
80000658:	00000013          	nop

8000065c <inst_51>:
8000065c:	555555b7          	lui	a1,0x55555
80000660:	55558593          	addi	a1,a1,1365 # 55555555 <absimmsh+0x54d55557>
80000664:	07c08513          	addi	a0,ra,124
80000668:	04000313          	li	t1,64
8000066c:	40650533          	sub	a0,a0,t1
80000670:	04b51023          	sh	a1,64(a0)
80000674:	00000013          	nop
80000678:	00000013          	nop

8000067c <inst_52>:
8000067c:	aaaab5b7          	lui	a1,0xaaaab
80000680:	aaa58593          	addi	a1,a1,-1366 # aaaaaaaa <imm12sh+0xaaaaaaac>
80000684:	08008513          	addi	a0,ra,128
80000688:	ffc00313          	li	t1,-4
8000068c:	40650533          	sub	a0,a0,t1
80000690:	feb51e23          	sh	a1,-4(a0)
80000694:	00000013          	nop
80000698:	00000013          	nop

8000069c <inst_53>:
8000069c:	ffe00593          	li	a1,-2
800006a0:	08408513          	addi	a0,ra,132
800006a4:	fbf00313          	li	t1,-65
800006a8:	40650533          	sub	a0,a0,t1
800006ac:	fab51fa3          	sh	a1,-65(a0)
800006b0:	00000013          	nop
800006b4:	00000013          	nop

800006b8 <inst_54>:
800006b8:	ffd00593          	li	a1,-3
800006bc:	08808513          	addi	a0,ra,136
800006c0:	fef00313          	li	t1,-17
800006c4:	40650533          	sub	a0,a0,t1
800006c8:	feb517a3          	sh	a1,-17(a0)
800006cc:	00000013          	nop
800006d0:	00000013          	nop

800006d4 <inst_55>:
800006d4:	ffb00593          	li	a1,-5
800006d8:	08c08513          	addi	a0,ra,140
800006dc:	01000313          	li	t1,16
800006e0:	40650533          	sub	a0,a0,t1
800006e4:	00b51823          	sh	a1,16(a0)
800006e8:	00000013          	nop
800006ec:	00000013          	nop

800006f0 <inst_56>:
800006f0:	fef00593          	li	a1,-17
800006f4:	09008513          	addi	a0,ra,144
800006f8:	02000313          	li	t1,32
800006fc:	40650533          	sub	a0,a0,t1
80000700:	02b51023          	sh	a1,32(a0)
80000704:	00000013          	nop
80000708:	00000013          	nop

8000070c <inst_57>:
8000070c:	fdf00593          	li	a1,-33
80000710:	09408513          	addi	a0,ra,148
80000714:	04000313          	li	t1,64
80000718:	40650533          	sub	a0,a0,t1
8000071c:	04b51023          	sh	a1,64(a0)
80000720:	00000013          	nop
80000724:	00000013          	nop

80000728 <inst_58>:
80000728:	fbf00593          	li	a1,-65
8000072c:	09808513          	addi	a0,ra,152
80000730:	ffe00313          	li	t1,-2
80000734:	40650533          	sub	a0,a0,t1
80000738:	feb51f23          	sh	a1,-2(a0)
8000073c:	00000013          	nop
80000740:	00000013          	nop

80000744 <inst_59>:
80000744:	f7f00593          	li	a1,-129
80000748:	09c08513          	addi	a0,ra,156
8000074c:	ff700313          	li	t1,-9
80000750:	40650533          	sub	a0,a0,t1
80000754:	feb51ba3          	sh	a1,-9(a0)
80000758:	00000013          	nop
8000075c:	00000013          	nop

80000760 <inst_60>:
80000760:	eff00593          	li	a1,-257
80000764:	0a008513          	addi	a0,ra,160
80000768:	bff00313          	li	t1,-1025
8000076c:	40650533          	sub	a0,a0,t1
80000770:	beb51fa3          	sh	a1,-1025(a0)
80000774:	00000013          	nop
80000778:	00000013          	nop

8000077c <inst_61>:
8000077c:	dff00593          	li	a1,-513
80000780:	0a408513          	addi	a0,ra,164
80000784:	ffd00313          	li	t1,-3
80000788:	40650533          	sub	a0,a0,t1
8000078c:	feb51ea3          	sh	a1,-3(a0)
80000790:	00000013          	nop
80000794:	00000013          	nop

80000798 <inst_62>:
80000798:	bff00593          	li	a1,-1025
8000079c:	0a808513          	addi	a0,ra,168
800007a0:	00300313          	li	t1,3
800007a4:	40650533          	sub	a0,a0,t1
800007a8:	00b511a3          	sh	a1,3(a0)
800007ac:	00000013          	nop
800007b0:	00000013          	nop

800007b4 <inst_63>:
800007b4:	fffff5b7          	lui	a1,0xfffff
800007b8:	7ff58593          	addi	a1,a1,2047 # fffff7ff <imm12sh+0xfffff801>
800007bc:	0ac08513          	addi	a0,ra,172
800007c0:	fdf00313          	li	t1,-33
800007c4:	40650533          	sub	a0,a0,t1
800007c8:	fcb51fa3          	sh	a1,-33(a0)
800007cc:	00000013          	nop
800007d0:	00000013          	nop

800007d4 <inst_64>:
800007d4:	fffff5b7          	lui	a1,0xfffff
800007d8:	fff58593          	addi	a1,a1,-1 # ffffefff <imm12sh+0xfffff001>
800007dc:	0b008513          	addi	a0,ra,176
800007e0:	ffa00313          	li	t1,-6
800007e4:	40650533          	sub	a0,a0,t1
800007e8:	feb51d23          	sh	a1,-6(a0)
800007ec:	00000013          	nop
800007f0:	00000013          	nop

800007f4 <inst_65>:
800007f4:	ffffe5b7          	lui	a1,0xffffe
800007f8:	fff58593          	addi	a1,a1,-1 # ffffdfff <imm12sh+0xffffe001>
800007fc:	0b408513          	addi	a0,ra,180
80000800:	01000313          	li	t1,16
80000804:	40650533          	sub	a0,a0,t1
80000808:	00b51823          	sh	a1,16(a0)
8000080c:	00000013          	nop
80000810:	00000013          	nop

80000814 <inst_66>:
80000814:	ffffc5b7          	lui	a1,0xffffc
80000818:	fff58593          	addi	a1,a1,-1 # ffffbfff <imm12sh+0xffffc001>
8000081c:	0b808513          	addi	a0,ra,184
80000820:	ff600313          	li	t1,-10
80000824:	40650533          	sub	a0,a0,t1
80000828:	feb51b23          	sh	a1,-10(a0)
8000082c:	00000013          	nop
80000830:	00000013          	nop

80000834 <inst_67>:
80000834:	ffff85b7          	lui	a1,0xffff8
80000838:	fff58593          	addi	a1,a1,-1 # ffff7fff <imm12sh+0xffff8001>
8000083c:	0bc08513          	addi	a0,ra,188
80000840:	20000313          	li	t1,512
80000844:	40650533          	sub	a0,a0,t1
80000848:	20b51023          	sh	a1,512(a0)
8000084c:	00000013          	nop
80000850:	00000013          	nop

80000854 <inst_68>:
80000854:	ffff05b7          	lui	a1,0xffff0
80000858:	fff58593          	addi	a1,a1,-1 # fffeffff <imm12sh+0xffff0001>
8000085c:	0c008513          	addi	a0,ra,192
80000860:	aaa00313          	li	t1,-1366
80000864:	40650533          	sub	a0,a0,t1
80000868:	aab51523          	sh	a1,-1366(a0)
8000086c:	00000013          	nop
80000870:	00000013          	nop

80000874 <inst_69>:
80000874:	fffe05b7          	lui	a1,0xfffe0
80000878:	fff58593          	addi	a1,a1,-1 # fffdffff <imm12sh+0xfffe0001>
8000087c:	0c408513          	addi	a0,ra,196
80000880:	fff00313          	li	t1,-1
80000884:	40650533          	sub	a0,a0,t1
80000888:	feb51fa3          	sh	a1,-1(a0)
8000088c:	00000013          	nop
80000890:	00000013          	nop

80000894 <inst_70>:
80000894:	000085b7          	lui	a1,0x8
80000898:	0c808513          	addi	a0,ra,200
8000089c:	dff00313          	li	t1,-513
800008a0:	40650533          	sub	a0,a0,t1
800008a4:	deb51fa3          	sh	a1,-513(a0)
800008a8:	00000013          	nop
800008ac:	00000013          	nop

800008b0 <cleanup_epilogs>:
800008b0:	0040006f          	j	800008b4 <exit_cleanup>

800008b4 <exit_cleanup>:
800008b4:	00100093          	li	ra,1

800008b8 <write_tohost>:
800008b8:	00000f17          	auipc	t5,0x0
800008bc:	741f2423          	sw	ra,1864(t5) # 80001000 <tohost>
800008c0:	ff9ff06f          	j	800008b8 <write_tohost>

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
80002020:	deadbeef          	jal	t4,7ffdd60a <absimmsh+0x7f7dd60c>
80002024:	deadbeef          	jal	t4,7ffdd60e <absimmsh+0x7f7dd610>

80002028 <rvtest_data_end>:
	...

80003000 <begin_regstate>:
80003000:	0080                	addi	s0,sp,64
	...

80003100 <end_regstate>:
80003100:	0004                	0x4
	...

80003110 <begin_signature>:
80003110:	a309                	j	80003612 <_end+0x3d2>
80003112:	6f5c                	flw	fa5,28(a4)

80003114 <signature_x4_0>:
80003114:	deadbeef          	jal	t4,7ffde6fe <absimmsh+0x7f7de700>
80003118:	deadbeef          	jal	t4,7ffde702 <absimmsh+0x7f7de704>
8000311c:	deadbeef          	jal	t4,7ffde706 <absimmsh+0x7f7de708>
80003120:	deadbeef          	jal	t4,7ffde70a <absimmsh+0x7f7de70c>
80003124:	deadbeef          	jal	t4,7ffde70e <absimmsh+0x7f7de710>
80003128:	deadbeef          	jal	t4,7ffde712 <absimmsh+0x7f7de714>
8000312c:	deadbeef          	jal	t4,7ffde716 <absimmsh+0x7f7de718>
80003130:	deadbeef          	jal	t4,7ffde71a <absimmsh+0x7f7de71c>
80003134:	deadbeef          	jal	t4,7ffde71e <absimmsh+0x7f7de720>
80003138:	deadbeef          	jal	t4,7ffde722 <absimmsh+0x7f7de724>
8000313c:	deadbeef          	jal	t4,7ffde726 <absimmsh+0x7f7de728>
80003140:	deadbeef          	jal	t4,7ffde72a <absimmsh+0x7f7de72c>
80003144:	deadbeef          	jal	t4,7ffde72e <absimmsh+0x7f7de730>
80003148:	deadbeef          	jal	t4,7ffde732 <absimmsh+0x7f7de734>
8000314c:	deadbeef          	jal	t4,7ffde736 <absimmsh+0x7f7de738>
80003150:	deadbeef          	jal	t4,7ffde73a <absimmsh+0x7f7de73c>
80003154:	deadbeef          	jal	t4,7ffde73e <absimmsh+0x7f7de740>
80003158:	deadbeef          	jal	t4,7ffde742 <absimmsh+0x7f7de744>
8000315c:	deadbeef          	jal	t4,7ffde746 <absimmsh+0x7f7de748>
80003160:	deadbeef          	jal	t4,7ffde74a <absimmsh+0x7f7de74c>

80003164 <signature_x1_0>:
80003164:	deadbeef          	jal	t4,7ffde74e <absimmsh+0x7f7de750>
80003168:	deadbeef          	jal	t4,7ffde752 <absimmsh+0x7f7de754>
8000316c:	deadbeef          	jal	t4,7ffde756 <absimmsh+0x7f7de758>
80003170:	deadbeef          	jal	t4,7ffde75a <absimmsh+0x7f7de75c>
80003174:	deadbeef          	jal	t4,7ffde75e <absimmsh+0x7f7de760>
80003178:	deadbeef          	jal	t4,7ffde762 <absimmsh+0x7f7de764>
8000317c:	deadbeef          	jal	t4,7ffde766 <absimmsh+0x7f7de768>
80003180:	deadbeef          	jal	t4,7ffde76a <absimmsh+0x7f7de76c>
80003184:	deadbeef          	jal	t4,7ffde76e <absimmsh+0x7f7de770>
80003188:	deadbeef          	jal	t4,7ffde772 <absimmsh+0x7f7de774>
8000318c:	deadbeef          	jal	t4,7ffde776 <absimmsh+0x7f7de778>
80003190:	deadbeef          	jal	t4,7ffde77a <absimmsh+0x7f7de77c>
80003194:	deadbeef          	jal	t4,7ffde77e <absimmsh+0x7f7de780>
80003198:	deadbeef          	jal	t4,7ffde782 <absimmsh+0x7f7de784>
8000319c:	deadbeef          	jal	t4,7ffde786 <absimmsh+0x7f7de788>
800031a0:	deadbeef          	jal	t4,7ffde78a <absimmsh+0x7f7de78c>
800031a4:	deadbeef          	jal	t4,7ffde78e <absimmsh+0x7f7de790>
800031a8:	deadbeef          	jal	t4,7ffde792 <absimmsh+0x7f7de794>
800031ac:	deadbeef          	jal	t4,7ffde796 <absimmsh+0x7f7de798>
800031b0:	deadbeef          	jal	t4,7ffde79a <absimmsh+0x7f7de79c>
800031b4:	deadbeef          	jal	t4,7ffde79e <absimmsh+0x7f7de7a0>
800031b8:	deadbeef          	jal	t4,7ffde7a2 <absimmsh+0x7f7de7a4>
800031bc:	deadbeef          	jal	t4,7ffde7a6 <absimmsh+0x7f7de7a8>
800031c0:	deadbeef          	jal	t4,7ffde7aa <absimmsh+0x7f7de7ac>
800031c4:	deadbeef          	jal	t4,7ffde7ae <absimmsh+0x7f7de7b0>
800031c8:	deadbeef          	jal	t4,7ffde7b2 <absimmsh+0x7f7de7b4>
800031cc:	deadbeef          	jal	t4,7ffde7b6 <absimmsh+0x7f7de7b8>
800031d0:	deadbeef          	jal	t4,7ffde7ba <absimmsh+0x7f7de7bc>
800031d4:	deadbeef          	jal	t4,7ffde7be <absimmsh+0x7f7de7c0>
800031d8:	deadbeef          	jal	t4,7ffde7c2 <absimmsh+0x7f7de7c4>
800031dc:	deadbeef          	jal	t4,7ffde7c6 <absimmsh+0x7f7de7c8>
800031e0:	deadbeef          	jal	t4,7ffde7ca <absimmsh+0x7f7de7cc>
800031e4:	deadbeef          	jal	t4,7ffde7ce <absimmsh+0x7f7de7d0>
800031e8:	deadbeef          	jal	t4,7ffde7d2 <absimmsh+0x7f7de7d4>
800031ec:	deadbeef          	jal	t4,7ffde7d6 <absimmsh+0x7f7de7d8>
800031f0:	deadbeef          	jal	t4,7ffde7da <absimmsh+0x7f7de7dc>
800031f4:	deadbeef          	jal	t4,7ffde7de <absimmsh+0x7f7de7e0>
800031f8:	deadbeef          	jal	t4,7ffde7e2 <absimmsh+0x7f7de7e4>
800031fc:	deadbeef          	jal	t4,7ffde7e6 <absimmsh+0x7f7de7e8>
80003200:	deadbeef          	jal	t4,7ffde7ea <absimmsh+0x7f7de7ec>
80003204:	deadbeef          	jal	t4,7ffde7ee <absimmsh+0x7f7de7f0>
80003208:	deadbeef          	jal	t4,7ffde7f2 <absimmsh+0x7f7de7f4>
8000320c:	deadbeef          	jal	t4,7ffde7f6 <absimmsh+0x7f7de7f8>
80003210:	deadbeef          	jal	t4,7ffde7fa <absimmsh+0x7f7de7fc>
80003214:	deadbeef          	jal	t4,7ffde7fe <absimmsh+0x7f7de800>
80003218:	deadbeef          	jal	t4,7ffde802 <absimmsh+0x7f7de804>
8000321c:	deadbeef          	jal	t4,7ffde806 <absimmsh+0x7f7de808>
80003220:	deadbeef          	jal	t4,7ffde80a <absimmsh+0x7f7de80c>
80003224:	deadbeef          	jal	t4,7ffde80e <absimmsh+0x7f7de810>
80003228:	deadbeef          	jal	t4,7ffde812 <absimmsh+0x7f7de814>
8000322c:	deadbeef          	jal	t4,7ffde816 <absimmsh+0x7f7de818>

80003230 <sig_end_canary>:
80003230:	a309                	j	80003732 <_end+0x4f2>
80003232:	6f5c                	flw	fa5,28(a4)

80003234 <rvtest_sig_end>:
	...

Disassembly of section .riscv.attributes:

00000000 <.riscv.attributes>:
   0:	1941                	addi	s2,s2,-16
   2:	0000                	unimp
   4:	7200                	flw	fs0,32(a2)
   6:	7369                	lui	t1,0xffffa
   8:	01007663          	bgeu	zero,a6,14 <edge2+0xa>
   c:	0000000f          	fence	unknown,unknown
  10:	7205                	lui	tp,0xfffe1
  12:	3376                	fld	ft6,376(sp)
  14:	6932                	flw	fs2,12(sp)
  16:	7032                	flw	ft0,44(sp)
  18:	0030                	addi	a2,sp,8

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	0251                	addi	tp,tp,20
   2:	0000                	unimp
   4:	00790003          	lb	zero,7(s2)
   8:	0000                	unimp
   a:	0101                	addi	sp,sp,0
   c:	000d0efb          	0xd0efb
  10:	0101                	addi	sp,sp,0
  12:	0101                	addi	sp,sp,0
  14:	0000                	unimp
  16:	0100                	addi	s0,sp,128
  18:	0000                	unimp
  1a:	2f01                	jal	72a <absimm+0x52a>
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
  44:	612d7663          	bgeu	s10,s2,650 <absimm+0x450>
  48:	6372                	flw	ft6,28(sp)
  4a:	2d68                	fld	fa0,216(a0)
  4c:	6574                	flw	fa3,76(a0)
  4e:	722f7473          	csrrci	s0,0x722,30
  52:	7369                	lui	t1,0xffffa
  54:	742d7663          	bgeu	s10,sp,7a0 <absimm+0x5a0>
  58:	7365                	lui	t1,0xffff9
  5a:	2d74                	fld	fa3,216(a0)
  5c:	74697573          	csrrci	a0,0x746,18
  60:	2f65                	jal	818 <absimm+0x618>
  62:	7672                	flw	fa2,60(sp)
  64:	5f693233          	0x5f693233
  68:	2f6d                	jal	822 <absimm+0x622>
  6a:	2f49                	jal	7fc <absimm+0x5fc>
  6c:	00637273          	csrrci	tp,0x6,6
  70:	7300                	flw	fs0,32(a4)
  72:	2d68                	fld	fa0,216(a0)
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
  b4:	001c                	0x1c
  b6:	0301                	addi	t1,t1,0
  b8:	0905                	addi	s2,s2,1
  ba:	0020                	addi	s0,sp,8
  bc:	0301                	addi	t1,t1,0
  be:	0905                	addi	s2,s2,1
  c0:	001c                	0x1c
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
  fc:	001c                	0x1c
  fe:	0301                	addi	t1,t1,0
 100:	0905                	addi	s2,s2,1
 102:	001c                	0x1c
 104:	0301                	addi	t1,t1,0
 106:	0905                	addi	s2,s2,1
 108:	001c                	0x1c
 10a:	0301                	addi	t1,t1,0
 10c:	0901                	addi	s2,s2,0
 10e:	0020                	addi	s0,sp,8
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
 1e0:	001c                	0x1c
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
 232:	0905                	addi	s2,s2,1
 234:	0020                	addi	s0,sp,8
 236:	0301                	addi	t1,t1,0
 238:	0905                	addi	s2,s2,1
 23a:	0020                	addi	s0,sp,8
 23c:	0301                	addi	t1,t1,0
 23e:	0905                	addi	s2,s2,1
 240:	0020                	addi	s0,sp,8
 242:	0301                	addi	t1,t1,0
 244:	0904                	addi	s1,sp,144
 246:	001c                	0x1c
 248:	0301                	addi	t1,t1,0
 24a:	0901                	addi	s2,s2,0
 24c:	0004                	0x4
 24e:	0901                	addi	s2,s2,0
 250:	0010                	0x10
 252:	0100                	addi	s0,sp,128
 254:	01              	Address 0x0000000000000254 is out of bounds.


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
  14:	08c4                	addi	s1,sp,84
  16:	8000                	0x8000
  18:	0000                	unimp
  1a:	0000                	unimp
  1c:	00000063          	beqz	zero,1c <edge2+0x12>
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
  14:	08c4                	addi	s1,sp,84
	...

Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	6d6f682f          	0x6d6f682f
   4:	2f65                	jal	7bc <absimm+0x5bc>
   6:	6f6c                	flw	fa1,92(a4)
   8:	6976                	flw	fs2,92(sp)
   a:	65442f73          	csrrs	t5,0x654,s0
   e:	6f746b73          	csrrsi	s6,0x6f7,8
  12:	2f70                	fld	fa2,216(a4)
  14:	6952                	flw	fs2,20(sp)
  16:	6556                	flw	fa0,84(sp)
  18:	5f72                	lw	t5,60(sp)
  1a:	65726f63          	bltu	tp,s7,678 <absimm+0x478>
  1e:	7369722f          	0x7369722f
  22:	2f666f63          	bltu	a2,s6,320 <absimm+0x120>
  26:	6972                	flw	fs2,28(sp)
  28:	2d766373          	csrrsi	t1,0x2d7,12
  2c:	7261                	lui	tp,0xffff8
  2e:	742d6863          	bltu	s10,sp,77e <absimm+0x57e>
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
  54:	2d68732f          	0x2d68732f
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
  8c:	5f666f63          	bltu	a2,s6,68a <absimm+0x48a>
  90:	6b726f77          	0x6b726f77
  94:	3376722f          	0x3376722f
  98:	6932                	flw	fs2,12(sp)
  9a:	6d5f 492f 732f      	0x732f492f6d5f
  a0:	6372                	flw	ft6,28(sp)
  a2:	2d68732f          	0x2d68732f
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
