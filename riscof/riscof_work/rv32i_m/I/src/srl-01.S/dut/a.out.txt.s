
my.elf:     file format elf32-littleriscv


Disassembly of section .text.init:

80000000 <rvtest_entry_point>:
80000000:	feedc0b7          	lui	ra,0xfeedc
80000004:	ead08093          	addi	ra,ra,-339 # feedbead <edge2+0xfeedbeae>
80000008:	ff76e137          	lui	sp,0xff76e
8000000c:	f5610113          	addi	sp,sp,-170 # ff76df56 <edge2+0xff76df57>
80000010:	7fbb71b7          	lui	gp,0x7fbb7
80000014:	fab18193          	addi	gp,gp,-85 # 7fbb6fab <offset+0x7fbb6eaf>
80000018:	bfddb237          	lui	tp,0xbfddb
8000001c:	7d520213          	addi	tp,tp,2005 # bfddb7d5 <edge2+0xbfddb7d6>
80000020:	00000297          	auipc	t0,0x0
80000024:	05828293          	addi	t0,t0,88 # 80000078 <rvtest_code_begin>
80000028:	00002317          	auipc	t1,0x2
8000002c:	fe830313          	addi	t1,t1,-24 # 80002010 <rvtest_data_begin>
80000030:	b7fbb3b7          	lui	t2,0xb7fbb
80000034:	6fa38393          	addi	t2,t2,1786 # b7fbb6fa <edge2+0xb7fbb6fb>
80000038:	5bfde437          	lui	s0,0x5bfde
8000003c:	b7d40413          	addi	s0,s0,-1155 # 5bfddb7d <offset+0x5bfdda81>
80000040:	adfef4b7          	lui	s1,0xadfef
80000044:	dbe48493          	addi	s1,s1,-578 # adfeedbe <edge2+0xadfeedbf>
80000048:	56ff7537          	lui	a0,0x56ff7
8000004c:	6df50513          	addi	a0,a0,1759 # 56ff76df <offset+0x56ff75e3>
80000050:	ab7fc5b7          	lui	a1,0xab7fc
80000054:	b6f58593          	addi	a1,a1,-1169 # ab7fbb6f <edge2+0xab7fbb70>
80000058:	d5bfe637          	lui	a2,0xd5bfe
8000005c:	db760613          	addi	a2,a2,-585 # d5bfddb7 <edge2+0xd5bfddb8>
80000060:	eadff6b7          	lui	a3,0xeadff
80000064:	edb68693          	addi	a3,a3,-293 # eadfeedb <edge2+0xeadfeedc>
80000068:	f56ff737          	lui	a4,0xf56ff
8000006c:	76d70713          	addi	a4,a4,1901 # f56ff76d <edge2+0xf56ff76e>
80000070:	fab807b7          	lui	a5,0xfab80
80000074:	bb678793          	addi	a5,a5,-1098 # fab7fbb6 <edge2+0xfab7fbb7>

80000078 <rvtest_code_begin>:
80000078:	00003997          	auipc	s3,0x3
8000007c:	09c98993          	addi	s3,s3,156 # 80003114 <signature_x19_0>

80000080 <inst_0>:
80000080:	ffc00d37          	lui	s10,0xffc00
80000084:	fffd0d13          	addi	s10,s10,-1 # ffbfffff <edge2+0xffc00000>
80000088:	00f00593          	li	a1,15
8000008c:	00bd55b3          	srl	a1,s10,a1
80000090:	00b9a023          	sw	a1,0(s3)

80000094 <inst_1>:
80000094:	55555fb7          	lui	t6,0x55555
80000098:	556f8f93          	addi	t6,t6,1366 # 55555556 <offset+0x5555545a>
8000009c:	55555fb7          	lui	t6,0x55555
800000a0:	556f8f93          	addi	t6,t6,1366 # 55555556 <offset+0x5555545a>
800000a4:	01ffd633          	srl	a2,t6,t6
800000a8:	00c9a223          	sw	a2,4(s3)

800000ac <inst_2>:
800000ac:	fff00393          	li	t2,-1
800000b0:	fff00393          	li	t2,-1
800000b4:	0073d3b3          	srl	t2,t2,t2
800000b8:	0079a423          	sw	t2,8(s3)

800000bc <inst_3>:
800000bc:	10000913          	li	s2,256
800000c0:	00000613          	li	a2,0
800000c4:	00c95933          	srl	s2,s2,a2
800000c8:	0129a623          	sw	s2,12(s3)

800000cc <inst_4>:
800000cc:	00900713          	li	a4,9
800000d0:	00900193          	li	gp,9
800000d4:	00375433          	srl	s0,a4,gp
800000d8:	0089a823          	sw	s0,16(s3)

800000dc <inst_5>:
800000dc:	80000ab7          	lui	s5,0x80000
800000e0:	00c00b13          	li	s6,12
800000e4:	016ada33          	srl	s4,s5,s6
800000e8:	0149aa23          	sw	s4,20(s3)

800000ec <inst_6>:
800000ec:	00000213          	li	tp,0
800000f0:	00f00893          	li	a7,15
800000f4:	01125f33          	srl	t5,tp,a7
800000f8:	01e9ac23          	sw	t5,24(s3)

800000fc <inst_7>:
800000fc:	800000b7          	lui	ra,0x80000
80000100:	fff08093          	addi	ra,ra,-1 # 7fffffff <edge2+0x80000000>
80000104:	01e00213          	li	tp,30
80000108:	0040d333          	srl	t1,ra,tp
8000010c:	0069ae23          	sw	t1,28(s3)

80000110 <inst_8>:
80000110:	00000013          	nop
80000114:	01d00a93          	li	s5,29
80000118:	015057b3          	srl	a5,zero,s5
8000011c:	02f9a023          	sw	a5,32(s3)

80000120 <inst_9>:
80000120:	00200e13          	li	t3,2
80000124:	00600b93          	li	s7,6
80000128:	017e52b3          	srl	t0,t3,s7
8000012c:	0259a223          	sw	t0,36(s3)

80000130 <inst_10>:
80000130:	00400493          	li	s1,4
80000134:	00a00f13          	li	t5,10
80000138:	01e4d233          	srl	tp,s1,t5
8000013c:	0249a423          	sw	tp,40(s3)

80000140 <inst_11>:
80000140:	00800693          	li	a3,8
80000144:	00200e93          	li	t4,2
80000148:	01d6d533          	srl	a0,a3,t4
8000014c:	02a9a623          	sw	a0,44(s3)

80000150 <inst_12>:
80000150:	01000113          	li	sp,16
80000154:	00700813          	li	a6,7
80000158:	01015cb3          	srl	s9,sp,a6
8000015c:	0399a823          	sw	s9,48(s3)
80000160:	00003217          	auipc	tp,0x3
80000164:	fe820213          	addi	tp,tp,-24 # 80003148 <signature_x4_0>

80000168 <inst_13>:
80000168:	02000593          	li	a1,32
8000016c:	00800e13          	li	t3,8
80000170:	01c5d9b3          	srl	s3,a1,t3
80000174:	01322023          	sw	s3,0(tp) # 0 <absimmsh>

80000178 <inst_14>:
80000178:	04000513          	li	a0,64
8000017c:	00b00313          	li	t1,11
80000180:	00655bb3          	srl	s7,a0,t1
80000184:	01722223          	sw	s7,4(tp) # 4 <MMODE_SIG+0x1>

80000188 <inst_15>:
80000188:	08000193          	li	gp,128
8000018c:	00600093          	li	ra,6
80000190:	0011d033          	srl	zero,gp,ra
80000194:	00022423          	sw	zero,8(tp) # 8 <MMODE_SIG+0x5>

80000198 <inst_16>:
80000198:	20000313          	li	t1,512
8000019c:	00e00413          	li	s0,14
800001a0:	00835733          	srl	a4,t1,s0
800001a4:	00e22623          	sw	a4,12(tp) # c <MMODE_SIG+0x9>

800001a8 <inst_17>:
800001a8:	40000a13          	li	s4,1024
800001ac:	01d00d93          	li	s11,29
800001b0:	01ba54b3          	srl	s1,s4,s11
800001b4:	00922823          	sw	s1,16(tp) # 10 <MMODE_SIG+0xd>

800001b8 <inst_18>:
800001b8:	00001f37          	lui	t5,0x1
800001bc:	800f0f13          	addi	t5,t5,-2048 # 800 <offset+0x704>
800001c0:	00d00913          	li	s2,13
800001c4:	012f5833          	srl	a6,t5,s2
800001c8:	01022a23          	sw	a6,20(tp) # 14 <MMODE_SIG+0x11>

800001cc <inst_19>:
800001cc:	00001b37          	lui	s6,0x1
800001d0:	00800513          	li	a0,8
800001d4:	00ab5c33          	srl	s8,s6,a0
800001d8:	01822c23          	sw	s8,24(tp) # 18 <MMODE_SIG+0x15>

800001dc <inst_20>:
800001dc:	000027b7          	lui	a5,0x2
800001e0:	00c00c13          	li	s8,12
800001e4:	0187d133          	srl	sp,a5,s8
800001e8:	00222e23          	sw	sp,28(tp) # 1c <MMODE_SIG+0x19>

800001ec <inst_21>:
800001ec:	000048b7          	lui	a7,0x4
800001f0:	00700493          	li	s1,7
800001f4:	0098dab3          	srl	s5,a7,s1
800001f8:	03522023          	sw	s5,32(tp) # 20 <pos>

800001fc <inst_22>:
800001fc:	00008637          	lui	a2,0x8
80000200:	01f00a13          	li	s4,31
80000204:	01465db3          	srl	s11,a2,s4
80000208:	03b22223          	sw	s11,36(tp) # 24 <pos+0x4>

8000020c <inst_23>:
8000020c:	00010db7          	lui	s11,0x10
80000210:	00300293          	li	t0,3
80000214:	005ddd33          	srl	s10,s11,t0
80000218:	03a22423          	sw	s10,40(tp) # 28 <pos+0x8>

8000021c <inst_24>:
8000021c:	00020837          	lui	a6,0x20
80000220:	00800693          	li	a3,8
80000224:	00d858b3          	srl	a7,a6,a3
80000228:	03122623          	sw	a7,44(tp) # 2c <pos+0xc>

8000022c <inst_25>:
8000022c:	00040bb7          	lui	s7,0x40
80000230:	01000793          	li	a5,16
80000234:	00fbde33          	srl	t3,s7,a5
80000238:	03c22823          	sw	t3,48(tp) # 30 <pos+0x10>

8000023c <inst_26>:
8000023c:	00080437          	lui	s0,0x80
80000240:	00500d13          	li	s10,5
80000244:	01a450b3          	srl	ra,s0,s10
80000248:	02122a23          	sw	ra,52(tp) # 34 <pos+0x14>

8000024c <inst_27>:
8000024c:	00100c37          	lui	s8,0x100
80000250:	01700113          	li	sp,23
80000254:	002c5eb3          	srl	t4,s8,sp
80000258:	03d22c23          	sw	t4,56(tp) # 38 <pos+0x18>

8000025c <inst_28>:
8000025c:	00200eb7          	lui	t4,0x200
80000260:	01000713          	li	a4,16
80000264:	00eedfb3          	srl	t6,t4,a4
80000268:	03f22e23          	sw	t6,60(tp) # 3c <pos+0x1c>
8000026c:	00003097          	auipc	ra,0x3
80000270:	f1c08093          	addi	ra,ra,-228 # 80003188 <signature_x1_0>

80000274 <inst_29>:
80000274:	004002b7          	lui	t0,0x400
80000278:	00600993          	li	s3,6
8000027c:	0132db33          	srl	s6,t0,s3
80000280:	0160a023          	sw	s6,0(ra)

80000284 <inst_30>:
80000284:	008009b7          	lui	s3,0x800
80000288:	00000013          	nop
8000028c:	0009d1b3          	srl	gp,s3,zero
80000290:	0030a223          	sw	gp,4(ra)

80000294 <inst_31>:
80000294:	01000cb7          	lui	s9,0x1000
80000298:	01e00213          	li	tp,30
8000029c:	004cd433          	srl	s0,s9,tp
800002a0:	0080a423          	sw	s0,8(ra)

800002a4 <inst_32>:
800002a4:	02000337          	lui	t1,0x2000
800002a8:	01d00c93          	li	s9,29
800002ac:	01935f33          	srl	t5,t1,s9
800002b0:	01e0a623          	sw	t5,12(ra)

800002b4 <inst_33>:
800002b4:	04000637          	lui	a2,0x4000
800002b8:	01e00493          	li	s1,30
800002bc:	009656b3          	srl	a3,a2,s1
800002c0:	00d0a823          	sw	a3,16(ra)

800002c4 <inst_34>:
800002c4:	08000537          	lui	a0,0x8000
800002c8:	00800593          	li	a1,8
800002cc:	00b55633          	srl	a2,a0,a1
800002d0:	00c0aa23          	sw	a2,20(ra)

800002d4 <inst_35>:
800002d4:	10000537          	lui	a0,0x10000
800002d8:	00c00593          	li	a1,12
800002dc:	00b55633          	srl	a2,a0,a1
800002e0:	00c0ac23          	sw	a2,24(ra)

800002e4 <inst_36>:
800002e4:	20000537          	lui	a0,0x20000
800002e8:	01b00593          	li	a1,27
800002ec:	00b55633          	srl	a2,a0,a1
800002f0:	00c0ae23          	sw	a2,28(ra)

800002f4 <inst_37>:
800002f4:	40000537          	lui	a0,0x40000
800002f8:	00600593          	li	a1,6
800002fc:	00b55633          	srl	a2,a0,a1
80000300:	02c0a023          	sw	a2,32(ra)

80000304 <inst_38>:
80000304:	ffe00513          	li	a0,-2
80000308:	00b00593          	li	a1,11
8000030c:	00b55633          	srl	a2,a0,a1
80000310:	02c0a223          	sw	a2,36(ra)

80000314 <inst_39>:
80000314:	ffd00513          	li	a0,-3
80000318:	01300593          	li	a1,19
8000031c:	00b55633          	srl	a2,a0,a1
80000320:	02c0a423          	sw	a2,40(ra)

80000324 <inst_40>:
80000324:	ffb00513          	li	a0,-5
80000328:	00200593          	li	a1,2
8000032c:	00b55633          	srl	a2,a0,a1
80000330:	02c0a623          	sw	a2,44(ra)

80000334 <inst_41>:
80000334:	ff700513          	li	a0,-9
80000338:	01300593          	li	a1,19
8000033c:	00b55633          	srl	a2,a0,a1
80000340:	02c0a823          	sw	a2,48(ra)

80000344 <inst_42>:
80000344:	fef00513          	li	a0,-17
80000348:	01700593          	li	a1,23
8000034c:	00b55633          	srl	a2,a0,a1
80000350:	02c0aa23          	sw	a2,52(ra)

80000354 <inst_43>:
80000354:	fdf00513          	li	a0,-33
80000358:	00f00593          	li	a1,15
8000035c:	00b55633          	srl	a2,a0,a1
80000360:	02c0ac23          	sw	a2,56(ra)

80000364 <inst_44>:
80000364:	fbf00513          	li	a0,-65
80000368:	00e00593          	li	a1,14
8000036c:	00b55633          	srl	a2,a0,a1
80000370:	02c0ae23          	sw	a2,60(ra)

80000374 <inst_45>:
80000374:	f7f00513          	li	a0,-129
80000378:	00600593          	li	a1,6
8000037c:	00b55633          	srl	a2,a0,a1
80000380:	04c0a023          	sw	a2,64(ra)

80000384 <inst_46>:
80000384:	eff00513          	li	a0,-257
80000388:	00e00593          	li	a1,14
8000038c:	00b55633          	srl	a2,a0,a1
80000390:	04c0a223          	sw	a2,68(ra)

80000394 <inst_47>:
80000394:	dff00513          	li	a0,-513
80000398:	00d00593          	li	a1,13
8000039c:	00b55633          	srl	a2,a0,a1
800003a0:	04c0a423          	sw	a2,72(ra)

800003a4 <inst_48>:
800003a4:	bff00513          	li	a0,-1025
800003a8:	01b00593          	li	a1,27
800003ac:	00b55633          	srl	a2,a0,a1
800003b0:	04c0a623          	sw	a2,76(ra)

800003b4 <inst_49>:
800003b4:	fffff537          	lui	a0,0xfffff
800003b8:	7ff50513          	addi	a0,a0,2047 # fffff7ff <edge2+0xfffff800>
800003bc:	01b00593          	li	a1,27
800003c0:	00b55633          	srl	a2,a0,a1
800003c4:	04c0a823          	sw	a2,80(ra)

800003c8 <inst_50>:
800003c8:	fffff537          	lui	a0,0xfffff
800003cc:	fff50513          	addi	a0,a0,-1 # ffffefff <edge2+0xfffff000>
800003d0:	00d00593          	li	a1,13
800003d4:	00b55633          	srl	a2,a0,a1
800003d8:	04c0aa23          	sw	a2,84(ra)

800003dc <inst_51>:
800003dc:	ffffe537          	lui	a0,0xffffe
800003e0:	fff50513          	addi	a0,a0,-1 # ffffdfff <edge2+0xffffe000>
800003e4:	00c00593          	li	a1,12
800003e8:	00b55633          	srl	a2,a0,a1
800003ec:	04c0ac23          	sw	a2,88(ra)

800003f0 <inst_52>:
800003f0:	ffffc537          	lui	a0,0xffffc
800003f4:	fff50513          	addi	a0,a0,-1 # ffffbfff <edge2+0xffffc000>
800003f8:	01000593          	li	a1,16
800003fc:	00b55633          	srl	a2,a0,a1
80000400:	04c0ae23          	sw	a2,92(ra)

80000404 <inst_53>:
80000404:	ffff8537          	lui	a0,0xffff8
80000408:	fff50513          	addi	a0,a0,-1 # ffff7fff <edge2+0xffff8000>
8000040c:	01e00593          	li	a1,30
80000410:	00b55633          	srl	a2,a0,a1
80000414:	06c0a023          	sw	a2,96(ra)

80000418 <inst_54>:
80000418:	ffff0537          	lui	a0,0xffff0
8000041c:	fff50513          	addi	a0,a0,-1 # fffeffff <edge2+0xffff0000>
80000420:	01200593          	li	a1,18
80000424:	00b55633          	srl	a2,a0,a1
80000428:	06c0a223          	sw	a2,100(ra)

8000042c <inst_55>:
8000042c:	fffe0537          	lui	a0,0xfffe0
80000430:	fff50513          	addi	a0,a0,-1 # fffdffff <edge2+0xfffe0000>
80000434:	01f00593          	li	a1,31
80000438:	00b55633          	srl	a2,a0,a1
8000043c:	06c0a423          	sw	a2,104(ra)

80000440 <inst_56>:
80000440:	fffc0537          	lui	a0,0xfffc0
80000444:	fff50513          	addi	a0,a0,-1 # fffbffff <edge2+0xfffc0000>
80000448:	00f00593          	li	a1,15
8000044c:	00b55633          	srl	a2,a0,a1
80000450:	06c0a623          	sw	a2,108(ra)

80000454 <inst_57>:
80000454:	fff80537          	lui	a0,0xfff80
80000458:	fff50513          	addi	a0,a0,-1 # fff7ffff <edge2+0xfff80000>
8000045c:	01b00593          	li	a1,27
80000460:	00b55633          	srl	a2,a0,a1
80000464:	06c0a823          	sw	a2,112(ra)

80000468 <inst_58>:
80000468:	fff00537          	lui	a0,0xfff00
8000046c:	fff50513          	addi	a0,a0,-1 # ffefffff <edge2+0xfff00000>
80000470:	00600593          	li	a1,6
80000474:	00b55633          	srl	a2,a0,a1
80000478:	06c0aa23          	sw	a2,116(ra)

8000047c <inst_59>:
8000047c:	ff800537          	lui	a0,0xff800
80000480:	fff50513          	addi	a0,a0,-1 # ff7fffff <edge2+0xff800000>
80000484:	01200593          	li	a1,18
80000488:	00b55633          	srl	a2,a0,a1
8000048c:	06c0ac23          	sw	a2,120(ra)

80000490 <inst_60>:
80000490:	ff000537          	lui	a0,0xff000
80000494:	fff50513          	addi	a0,a0,-1 # feffffff <edge2+0xff000000>
80000498:	01100593          	li	a1,17
8000049c:	00b55633          	srl	a2,a0,a1
800004a0:	06c0ae23          	sw	a2,124(ra)

800004a4 <inst_61>:
800004a4:	fe000537          	lui	a0,0xfe000
800004a8:	fff50513          	addi	a0,a0,-1 # fdffffff <edge2+0xfe000000>
800004ac:	00c00593          	li	a1,12
800004b0:	00b55633          	srl	a2,a0,a1
800004b4:	08c0a023          	sw	a2,128(ra)

800004b8 <inst_62>:
800004b8:	fc000537          	lui	a0,0xfc000
800004bc:	fff50513          	addi	a0,a0,-1 # fbffffff <edge2+0xfc000000>
800004c0:	01700593          	li	a1,23
800004c4:	00b55633          	srl	a2,a0,a1
800004c8:	08c0a223          	sw	a2,132(ra)

800004cc <inst_63>:
800004cc:	f8000537          	lui	a0,0xf8000
800004d0:	fff50513          	addi	a0,a0,-1 # f7ffffff <edge2+0xf8000000>
800004d4:	00100593          	li	a1,1
800004d8:	00b55633          	srl	a2,a0,a1
800004dc:	08c0a423          	sw	a2,136(ra)

800004e0 <inst_64>:
800004e0:	f0000537          	lui	a0,0xf0000
800004e4:	fff50513          	addi	a0,a0,-1 # efffffff <edge2+0xf0000000>
800004e8:	00900593          	li	a1,9
800004ec:	00b55633          	srl	a2,a0,a1
800004f0:	08c0a623          	sw	a2,140(ra)

800004f4 <inst_65>:
800004f4:	e0000537          	lui	a0,0xe0000
800004f8:	fff50513          	addi	a0,a0,-1 # dfffffff <edge2+0xe0000000>
800004fc:	00d00593          	li	a1,13
80000500:	00b55633          	srl	a2,a0,a1
80000504:	08c0a823          	sw	a2,144(ra)

80000508 <inst_66>:
80000508:	c0000537          	lui	a0,0xc0000
8000050c:	fff50513          	addi	a0,a0,-1 # bfffffff <edge2+0xc0000000>
80000510:	00800593          	li	a1,8
80000514:	00b55633          	srl	a2,a0,a1
80000518:	08c0aa23          	sw	a2,148(ra)

8000051c <inst_67>:
8000051c:	55555537          	lui	a0,0x55555
80000520:	55550513          	addi	a0,a0,1365 # 55555555 <offset+0x55555459>
80000524:	00b00593          	li	a1,11
80000528:	00b55633          	srl	a2,a0,a1
8000052c:	08c0ac23          	sw	a2,152(ra)

80000530 <inst_68>:
80000530:	aaaab537          	lui	a0,0xaaaab
80000534:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <edge2+0xaaaaaaab>
80000538:	01d00593          	li	a1,29
8000053c:	00b55633          	srl	a2,a0,a1
80000540:	08c0ae23          	sw	a2,156(ra)

80000544 <inst_69>:
80000544:	00300513          	li	a0,3
80000548:	00300593          	li	a1,3
8000054c:	00b55633          	srl	a2,a0,a1
80000550:	0ac0a023          	sw	a2,160(ra)

80000554 <inst_70>:
80000554:	00500513          	li	a0,5
80000558:	00f00593          	li	a1,15
8000055c:	00b55633          	srl	a2,a0,a1
80000560:	0ac0a223          	sw	a2,164(ra)

80000564 <inst_71>:
80000564:	33333537          	lui	a0,0x33333
80000568:	33350513          	addi	a0,a0,819 # 33333333 <offset+0x33333237>
8000056c:	00a00593          	li	a1,10
80000570:	00b55633          	srl	a2,a0,a1
80000574:	0ac0a423          	sw	a2,168(ra)

80000578 <inst_72>:
80000578:	66666537          	lui	a0,0x66666
8000057c:	66650513          	addi	a0,a0,1638 # 66666666 <offset+0x6666656a>
80000580:	01300593          	li	a1,19
80000584:	00b55633          	srl	a2,a0,a1
80000588:	0ac0a623          	sw	a2,172(ra)

8000058c <inst_73>:
8000058c:	0000b537          	lui	a0,0xb
80000590:	50550513          	addi	a0,a0,1285 # b505 <offset+0xb409>
80000594:	01f00593          	li	a1,31
80000598:	00b55633          	srl	a2,a0,a1
8000059c:	0ac0a823          	sw	a2,176(ra)

800005a0 <inst_74>:
800005a0:	00600513          	li	a0,6
800005a4:	00400593          	li	a1,4
800005a8:	00b55633          	srl	a2,a0,a1
800005ac:	0ac0aa23          	sw	a2,180(ra)

800005b0 <inst_75>:
800005b0:	fe000537          	lui	a0,0xfe000
800005b4:	fff50513          	addi	a0,a0,-1 # fdffffff <edge2+0xfe000000>
800005b8:	01500593          	li	a1,21
800005bc:	00b55633          	srl	a2,a0,a1
800005c0:	0ac0ac23          	sw	a2,184(ra)

800005c4 <inst_76>:
800005c4:	ffff5537          	lui	a0,0xffff5
800005c8:	afc50513          	addi	a0,a0,-1284 # ffff4afc <edge2+0xffff4afd>
800005cc:	00c00593          	li	a1,12
800005d0:	00b55633          	srl	a2,a0,a1
800005d4:	0ac0ae23          	sw	a2,188(ra)

800005d8 <inst_77>:
800005d8:	0000b537          	lui	a0,0xb
800005dc:	50450513          	addi	a0,a0,1284 # b504 <offset+0xb408>
800005e0:	01d00593          	li	a1,29
800005e4:	00b55633          	srl	a2,a0,a1
800005e8:	0cc0a023          	sw	a2,192(ra)

800005ec <inst_78>:
800005ec:	55555537          	lui	a0,0x55555
800005f0:	55450513          	addi	a0,a0,1364 # 55555554 <offset+0x55555458>
800005f4:	01500593          	li	a1,21
800005f8:	00b55633          	srl	a2,a0,a1
800005fc:	0cc0a223          	sw	a2,196(ra)

80000600 <inst_79>:
80000600:	ffe00537          	lui	a0,0xffe00
80000604:	fff50513          	addi	a0,a0,-1 # ffdfffff <edge2+0xffe00000>
80000608:	00e00593          	li	a1,14
8000060c:	00b55633          	srl	a2,a0,a1
80000610:	0cc0a423          	sw	a2,200(ra)

80000614 <inst_80>:
80000614:	33333537          	lui	a0,0x33333
80000618:	33250513          	addi	a0,a0,818 # 33333332 <offset+0x33333236>
8000061c:	00000593          	li	a1,0
80000620:	00b55633          	srl	a2,a0,a1
80000624:	0cc0a623          	sw	a2,204(ra)

80000628 <inst_81>:
80000628:	66666537          	lui	a0,0x66666
8000062c:	66550513          	addi	a0,a0,1637 # 66666665 <offset+0x66666569>
80000630:	00300593          	li	a1,3
80000634:	00b55633          	srl	a2,a0,a1
80000638:	0cc0a823          	sw	a2,208(ra)

8000063c <inst_82>:
8000063c:	0000b537          	lui	a0,0xb
80000640:	50350513          	addi	a0,a0,1283 # b503 <offset+0xb407>
80000644:	00100593          	li	a1,1
80000648:	00b55633          	srl	a2,a0,a1
8000064c:	0cc0aa23          	sw	a2,212(ra)

80000650 <inst_83>:
80000650:	aaaab537          	lui	a0,0xaaaab
80000654:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <edge2+0xaaaaaaac>
80000658:	00b00593          	li	a1,11
8000065c:	00b55633          	srl	a2,a0,a1
80000660:	0cc0ac23          	sw	a2,216(ra)

80000664 <inst_84>:
80000664:	33333537          	lui	a0,0x33333
80000668:	33450513          	addi	a0,a0,820 # 33333334 <offset+0x33333238>
8000066c:	01b00593          	li	a1,27
80000670:	00b55633          	srl	a2,a0,a1
80000674:	0cc0ae23          	sw	a2,220(ra)

80000678 <inst_85>:
80000678:	66666537          	lui	a0,0x66666
8000067c:	66750513          	addi	a0,a0,1639 # 66666667 <offset+0x6666656b>
80000680:	00600593          	li	a1,6
80000684:	00b55633          	srl	a2,a0,a1
80000688:	0ec0a023          	sw	a2,224(ra)

8000068c <inst_86>:
8000068c:	ffff5537          	lui	a0,0xffff5
80000690:	afd50513          	addi	a0,a0,-1283 # ffff4afd <edge2+0xffff4afe>
80000694:	00600593          	li	a1,6
80000698:	00b55633          	srl	a2,a0,a1
8000069c:	0ec0a223          	sw	a2,228(ra)

800006a0 <inst_87>:
800006a0:	55555537          	lui	a0,0x55555
800006a4:	55650513          	addi	a0,a0,1366 # 55555556 <offset+0x5555545a>
800006a8:	00800593          	li	a1,8
800006ac:	00b55633          	srl	a2,a0,a1
800006b0:	0ec0a423          	sw	a2,232(ra)

800006b4 <inst_88>:
800006b4:	fff00513          	li	a0,-1
800006b8:	00000593          	li	a1,0
800006bc:	00b55633          	srl	a2,a0,a1
800006c0:	0ec0a623          	sw	a2,236(ra)

800006c4 <inst_89>:
800006c4:	00100513          	li	a0,1
800006c8:	01d00593          	li	a1,29
800006cc:	00b55633          	srl	a2,a0,a1
800006d0:	0ec0a823          	sw	a2,240(ra)

800006d4 <inst_90>:
800006d4:	08000513          	li	a0,128
800006d8:	00600593          	li	a1,6
800006dc:	00b55633          	srl	a2,a0,a1
800006e0:	0ec0aa23          	sw	a2,244(ra)

800006e4 <inst_91>:
800006e4:	00800537          	lui	a0,0x800
800006e8:	00100593          	li	a1,1
800006ec:	00b55633          	srl	a2,a0,a1
800006f0:	0ec0ac23          	sw	a2,248(ra)

800006f4 <cleanup_epilogs>:
800006f4:	0040006f          	j	800006f8 <exit_cleanup>

800006f8 <exit_cleanup>:
800006f8:	00100093          	li	ra,1

800006fc <write_tohost>:
800006fc:	00001f17          	auipc	t5,0x1
80000700:	901f2223          	sw	ra,-1788(t5) # 80001000 <tohost>
80000704:	ff9ff06f          	j	800006fc <write_tohost>
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
80002020:	deadbeef          	jal	t4,7ffdd60a <offset+0x7ffdd50e>
80002024:	deadbeef          	jal	t4,7ffdd60e <offset+0x7ffdd512>

80002028 <rvtest_data_end>:
	...

80003000 <begin_regstate>:
80003000:	0080                	addi	s0,sp,64
	...

80003100 <end_regstate>:
80003100:	0004                	0x4
	...

80003110 <begin_signature>:
80003110:	a309                	j	80003612 <_end+0x382>
80003112:	6f5c                	flw	fa5,28(a4)

80003114 <signature_x19_0>:
80003114:	deadbeef          	jal	t4,7ffde6fe <offset+0x7ffde602>
80003118:	deadbeef          	jal	t4,7ffde702 <offset+0x7ffde606>
8000311c:	deadbeef          	jal	t4,7ffde706 <offset+0x7ffde60a>
80003120:	deadbeef          	jal	t4,7ffde70a <offset+0x7ffde60e>
80003124:	deadbeef          	jal	t4,7ffde70e <offset+0x7ffde612>
80003128:	deadbeef          	jal	t4,7ffde712 <offset+0x7ffde616>
8000312c:	deadbeef          	jal	t4,7ffde716 <offset+0x7ffde61a>
80003130:	deadbeef          	jal	t4,7ffde71a <offset+0x7ffde61e>
80003134:	deadbeef          	jal	t4,7ffde71e <offset+0x7ffde622>
80003138:	deadbeef          	jal	t4,7ffde722 <offset+0x7ffde626>
8000313c:	deadbeef          	jal	t4,7ffde726 <offset+0x7ffde62a>
80003140:	deadbeef          	jal	t4,7ffde72a <offset+0x7ffde62e>
80003144:	deadbeef          	jal	t4,7ffde72e <offset+0x7ffde632>

80003148 <signature_x4_0>:
80003148:	deadbeef          	jal	t4,7ffde732 <offset+0x7ffde636>
8000314c:	deadbeef          	jal	t4,7ffde736 <offset+0x7ffde63a>
80003150:	deadbeef          	jal	t4,7ffde73a <offset+0x7ffde63e>
80003154:	deadbeef          	jal	t4,7ffde73e <offset+0x7ffde642>
80003158:	deadbeef          	jal	t4,7ffde742 <offset+0x7ffde646>
8000315c:	deadbeef          	jal	t4,7ffde746 <offset+0x7ffde64a>
80003160:	deadbeef          	jal	t4,7ffde74a <offset+0x7ffde64e>
80003164:	deadbeef          	jal	t4,7ffde74e <offset+0x7ffde652>
80003168:	deadbeef          	jal	t4,7ffde752 <offset+0x7ffde656>
8000316c:	deadbeef          	jal	t4,7ffde756 <offset+0x7ffde65a>
80003170:	deadbeef          	jal	t4,7ffde75a <offset+0x7ffde65e>
80003174:	deadbeef          	jal	t4,7ffde75e <offset+0x7ffde662>
80003178:	deadbeef          	jal	t4,7ffde762 <offset+0x7ffde666>
8000317c:	deadbeef          	jal	t4,7ffde766 <offset+0x7ffde66a>
80003180:	deadbeef          	jal	t4,7ffde76a <offset+0x7ffde66e>
80003184:	deadbeef          	jal	t4,7ffde76e <offset+0x7ffde672>

80003188 <signature_x1_0>:
80003188:	deadbeef          	jal	t4,7ffde772 <offset+0x7ffde676>
8000318c:	deadbeef          	jal	t4,7ffde776 <offset+0x7ffde67a>
80003190:	deadbeef          	jal	t4,7ffde77a <offset+0x7ffde67e>
80003194:	deadbeef          	jal	t4,7ffde77e <offset+0x7ffde682>
80003198:	deadbeef          	jal	t4,7ffde782 <offset+0x7ffde686>
8000319c:	deadbeef          	jal	t4,7ffde786 <offset+0x7ffde68a>
800031a0:	deadbeef          	jal	t4,7ffde78a <offset+0x7ffde68e>
800031a4:	deadbeef          	jal	t4,7ffde78e <offset+0x7ffde692>
800031a8:	deadbeef          	jal	t4,7ffde792 <offset+0x7ffde696>
800031ac:	deadbeef          	jal	t4,7ffde796 <offset+0x7ffde69a>
800031b0:	deadbeef          	jal	t4,7ffde79a <offset+0x7ffde69e>
800031b4:	deadbeef          	jal	t4,7ffde79e <offset+0x7ffde6a2>
800031b8:	deadbeef          	jal	t4,7ffde7a2 <offset+0x7ffde6a6>
800031bc:	deadbeef          	jal	t4,7ffde7a6 <offset+0x7ffde6aa>
800031c0:	deadbeef          	jal	t4,7ffde7aa <offset+0x7ffde6ae>
800031c4:	deadbeef          	jal	t4,7ffde7ae <offset+0x7ffde6b2>
800031c8:	deadbeef          	jal	t4,7ffde7b2 <offset+0x7ffde6b6>
800031cc:	deadbeef          	jal	t4,7ffde7b6 <offset+0x7ffde6ba>
800031d0:	deadbeef          	jal	t4,7ffde7ba <offset+0x7ffde6be>
800031d4:	deadbeef          	jal	t4,7ffde7be <offset+0x7ffde6c2>
800031d8:	deadbeef          	jal	t4,7ffde7c2 <offset+0x7ffde6c6>
800031dc:	deadbeef          	jal	t4,7ffde7c6 <offset+0x7ffde6ca>
800031e0:	deadbeef          	jal	t4,7ffde7ca <offset+0x7ffde6ce>
800031e4:	deadbeef          	jal	t4,7ffde7ce <offset+0x7ffde6d2>
800031e8:	deadbeef          	jal	t4,7ffde7d2 <offset+0x7ffde6d6>
800031ec:	deadbeef          	jal	t4,7ffde7d6 <offset+0x7ffde6da>
800031f0:	deadbeef          	jal	t4,7ffde7da <offset+0x7ffde6de>
800031f4:	deadbeef          	jal	t4,7ffde7de <offset+0x7ffde6e2>
800031f8:	deadbeef          	jal	t4,7ffde7e2 <offset+0x7ffde6e6>
800031fc:	deadbeef          	jal	t4,7ffde7e6 <offset+0x7ffde6ea>
80003200:	deadbeef          	jal	t4,7ffde7ea <offset+0x7ffde6ee>
80003204:	deadbeef          	jal	t4,7ffde7ee <offset+0x7ffde6f2>
80003208:	deadbeef          	jal	t4,7ffde7f2 <offset+0x7ffde6f6>
8000320c:	deadbeef          	jal	t4,7ffde7f6 <offset+0x7ffde6fa>
80003210:	deadbeef          	jal	t4,7ffde7fa <offset+0x7ffde6fe>
80003214:	deadbeef          	jal	t4,7ffde7fe <offset+0x7ffde702>
80003218:	deadbeef          	jal	t4,7ffde802 <offset+0x7ffde706>
8000321c:	deadbeef          	jal	t4,7ffde806 <offset+0x7ffde70a>
80003220:	deadbeef          	jal	t4,7ffde80a <offset+0x7ffde70e>
80003224:	deadbeef          	jal	t4,7ffde80e <offset+0x7ffde712>
80003228:	deadbeef          	jal	t4,7ffde812 <offset+0x7ffde716>
8000322c:	deadbeef          	jal	t4,7ffde816 <offset+0x7ffde71a>
80003230:	deadbeef          	jal	t4,7ffde81a <offset+0x7ffde71e>
80003234:	deadbeef          	jal	t4,7ffde81e <offset+0x7ffde722>
80003238:	deadbeef          	jal	t4,7ffde822 <offset+0x7ffde726>
8000323c:	deadbeef          	jal	t4,7ffde826 <offset+0x7ffde72a>
80003240:	deadbeef          	jal	t4,7ffde82a <offset+0x7ffde72e>
80003244:	deadbeef          	jal	t4,7ffde82e <offset+0x7ffde732>
80003248:	deadbeef          	jal	t4,7ffde832 <offset+0x7ffde736>
8000324c:	deadbeef          	jal	t4,7ffde836 <offset+0x7ffde73a>
80003250:	deadbeef          	jal	t4,7ffde83a <offset+0x7ffde73e>
80003254:	deadbeef          	jal	t4,7ffde83e <offset+0x7ffde742>
80003258:	deadbeef          	jal	t4,7ffde842 <offset+0x7ffde746>
8000325c:	deadbeef          	jal	t4,7ffde846 <offset+0x7ffde74a>
80003260:	deadbeef          	jal	t4,7ffde84a <offset+0x7ffde74e>
80003264:	deadbeef          	jal	t4,7ffde84e <offset+0x7ffde752>
80003268:	deadbeef          	jal	t4,7ffde852 <offset+0x7ffde756>
8000326c:	deadbeef          	jal	t4,7ffde856 <offset+0x7ffde75a>
80003270:	deadbeef          	jal	t4,7ffde85a <offset+0x7ffde75e>
80003274:	deadbeef          	jal	t4,7ffde85e <offset+0x7ffde762>
80003278:	deadbeef          	jal	t4,7ffde862 <offset+0x7ffde766>
8000327c:	deadbeef          	jal	t4,7ffde866 <offset+0x7ffde76a>
80003280:	deadbeef          	jal	t4,7ffde86a <offset+0x7ffde76e>

80003284 <sig_end_canary>:
80003284:	a309                	j	80003786 <_end+0x4f6>
80003286:	6f5c                	flw	fa5,28(a4)

80003288 <rvtest_sig_end>:
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
   0:	02d0                	addi	a2,sp,324
   2:	0000                	unimp
   4:	00740003          	lb	zero,7(s0) # 80007 <offset+0x7ff0b>
   8:	0000                	unimp
   a:	0101                	addi	sp,sp,0
   c:	000d0efb          	0xd0efb
  10:	0101                	addi	sp,sp,0
  12:	0101                	addi	sp,sp,0
  14:	0000                	unimp
  16:	0100                	addi	s0,sp,128
  18:	0000                	unimp
  1a:	2f01                	jal	72a <offset+0x62e>
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
  44:	612d7663          	bgeu	s10,s2,650 <offset+0x554>
  48:	6372                	flw	ft6,28(sp)
  4a:	2d68                	fld	fa0,216(a0)
  4c:	6574                	flw	fa3,76(a0)
  4e:	722f7473          	csrrci	s0,0x722,30
  52:	7369                	lui	t1,0xffffa
  54:	742d7663          	bgeu	s10,sp,7a0 <offset+0x6a4>
  58:	7365                	lui	t1,0xffff9
  5a:	2d74                	fld	fa3,216(a0)
  5c:	74697573          	csrrci	a0,0x746,18
  60:	2f65                	jal	818 <offset+0x71c>
  62:	7672                	flw	fa2,60(sp)
  64:	5f693233          	0x5f693233
  68:	2f6d                	jal	822 <offset+0x726>
  6a:	2f49                	jal	7fc <offset+0x700>
  6c:	00637273          	csrrci	tp,0x6,6
  70:	7300                	flw	fs0,32(a4)
  72:	6c72                	flw	fs8,28(sp)
  74:	302d                	jal	fffff89e <edge2+0xfffff89f>
  76:	2e31                	jal	392 <offset+0x296>
  78:	00010053          	fadd.s	ft0,ft2,ft0,rne
  7c:	0000                	unimp
  7e:	0500                	addi	s0,sp,640
  80:	0002                	c.slli64	zero
  82:	0000                	unimp
  84:	0380                	addi	s0,sp,448
  86:	0119                	addi	sp,sp,6
  88:	78090603          	lb	a2,1920(s2)
  8c:	0100                	addi	s0,sp,128
  8e:	08090503          	lb	a0,128(s2)
  92:	0100                	addi	s0,sp,128
  94:	14090503          	lb	a0,320(s2)
  98:	0100                	addi	s0,sp,128
  9a:	18090503          	lb	a0,384(s2)
  9e:	0100                	addi	s0,sp,128
  a0:	10090503          	lb	a0,256(s2)
  a4:	0100                	addi	s0,sp,128
  a6:	10090503          	lb	a0,256(s2)
  aa:	0100                	addi	s0,sp,128
  ac:	10090503          	lb	a0,256(s2)
  b0:	0100                	addi	s0,sp,128
  b2:	10090503          	lb	a0,256(s2)
  b6:	0100                	addi	s0,sp,128
  b8:	10090503          	lb	a0,256(s2)
  bc:	0100                	addi	s0,sp,128
  be:	14090503          	lb	a0,320(s2)
  c2:	0100                	addi	s0,sp,128
  c4:	10090503          	lb	a0,256(s2)
  c8:	0100                	addi	s0,sp,128
  ca:	10090503          	lb	a0,256(s2)
  ce:	0100                	addi	s0,sp,128
  d0:	10090503          	lb	a0,256(s2)
  d4:	0100                	addi	s0,sp,128
  d6:	10090503          	lb	a0,256(s2)
  da:	0100                	addi	s0,sp,128
  dc:	10090103          	lb	sp,256(s2)
  e0:	0100                	addi	s0,sp,128
  e2:	08090503          	lb	a0,128(s2)
  e6:	0100                	addi	s0,sp,128
  e8:	10090503          	lb	a0,256(s2)
  ec:	0100                	addi	s0,sp,128
  ee:	10090503          	lb	a0,256(s2)
  f2:	0100                	addi	s0,sp,128
  f4:	10090503          	lb	a0,256(s2)
  f8:	0100                	addi	s0,sp,128
  fa:	10090503          	lb	a0,256(s2)
  fe:	0100                	addi	s0,sp,128
 100:	10090503          	lb	a0,256(s2)
 104:	0100                	addi	s0,sp,128
 106:	14090503          	lb	a0,320(s2)
 10a:	0100                	addi	s0,sp,128
 10c:	10090503          	lb	a0,256(s2)
 110:	0100                	addi	s0,sp,128
 112:	10090503          	lb	a0,256(s2)
 116:	0100                	addi	s0,sp,128
 118:	10090503          	lb	a0,256(s2)
 11c:	0100                	addi	s0,sp,128
 11e:	10090503          	lb	a0,256(s2)
 122:	0100                	addi	s0,sp,128
 124:	10090503          	lb	a0,256(s2)
 128:	0100                	addi	s0,sp,128
 12a:	10090503          	lb	a0,256(s2)
 12e:	0100                	addi	s0,sp,128
 130:	10090503          	lb	a0,256(s2)
 134:	0100                	addi	s0,sp,128
 136:	10090503          	lb	a0,256(s2)
 13a:	0100                	addi	s0,sp,128
 13c:	10090503          	lb	a0,256(s2)
 140:	0100                	addi	s0,sp,128
 142:	10090103          	lb	sp,256(s2)
 146:	0100                	addi	s0,sp,128
 148:	08090503          	lb	a0,128(s2)
 14c:	0100                	addi	s0,sp,128
 14e:	10090503          	lb	a0,256(s2)
 152:	0100                	addi	s0,sp,128
 154:	10090503          	lb	a0,256(s2)
 158:	0100                	addi	s0,sp,128
 15a:	10090503          	lb	a0,256(s2)
 15e:	0100                	addi	s0,sp,128
 160:	10090503          	lb	a0,256(s2)
 164:	0100                	addi	s0,sp,128
 166:	10090503          	lb	a0,256(s2)
 16a:	0100                	addi	s0,sp,128
 16c:	10090503          	lb	a0,256(s2)
 170:	0100                	addi	s0,sp,128
 172:	10090503          	lb	a0,256(s2)
 176:	0100                	addi	s0,sp,128
 178:	10090503          	lb	a0,256(s2)
 17c:	0100                	addi	s0,sp,128
 17e:	10090503          	lb	a0,256(s2)
 182:	0100                	addi	s0,sp,128
 184:	10090503          	lb	a0,256(s2)
 188:	0100                	addi	s0,sp,128
 18a:	10090503          	lb	a0,256(s2)
 18e:	0100                	addi	s0,sp,128
 190:	10090503          	lb	a0,256(s2)
 194:	0100                	addi	s0,sp,128
 196:	10090503          	lb	a0,256(s2)
 19a:	0100                	addi	s0,sp,128
 19c:	10090503          	lb	a0,256(s2)
 1a0:	0100                	addi	s0,sp,128
 1a2:	10090503          	lb	a0,256(s2)
 1a6:	0100                	addi	s0,sp,128
 1a8:	10090503          	lb	a0,256(s2)
 1ac:	0100                	addi	s0,sp,128
 1ae:	10090503          	lb	a0,256(s2)
 1b2:	0100                	addi	s0,sp,128
 1b4:	10090503          	lb	a0,256(s2)
 1b8:	0100                	addi	s0,sp,128
 1ba:	10090503          	lb	a0,256(s2)
 1be:	0100                	addi	s0,sp,128
 1c0:	10090503          	lb	a0,256(s2)
 1c4:	0100                	addi	s0,sp,128
 1c6:	14090503          	lb	a0,320(s2)
 1ca:	0100                	addi	s0,sp,128
 1cc:	14090503          	lb	a0,320(s2)
 1d0:	0100                	addi	s0,sp,128
 1d2:	14090503          	lb	a0,320(s2)
 1d6:	0100                	addi	s0,sp,128
 1d8:	14090503          	lb	a0,320(s2)
 1dc:	0100                	addi	s0,sp,128
 1de:	14090503          	lb	a0,320(s2)
 1e2:	0100                	addi	s0,sp,128
 1e4:	14090503          	lb	a0,320(s2)
 1e8:	0100                	addi	s0,sp,128
 1ea:	14090503          	lb	a0,320(s2)
 1ee:	0100                	addi	s0,sp,128
 1f0:	14090503          	lb	a0,320(s2)
 1f4:	0100                	addi	s0,sp,128
 1f6:	14090503          	lb	a0,320(s2)
 1fa:	0100                	addi	s0,sp,128
 1fc:	14090503          	lb	a0,320(s2)
 200:	0100                	addi	s0,sp,128
 202:	14090503          	lb	a0,320(s2)
 206:	0100                	addi	s0,sp,128
 208:	14090503          	lb	a0,320(s2)
 20c:	0100                	addi	s0,sp,128
 20e:	14090503          	lb	a0,320(s2)
 212:	0100                	addi	s0,sp,128
 214:	14090503          	lb	a0,320(s2)
 218:	0100                	addi	s0,sp,128
 21a:	14090503          	lb	a0,320(s2)
 21e:	0100                	addi	s0,sp,128
 220:	14090503          	lb	a0,320(s2)
 224:	0100                	addi	s0,sp,128
 226:	14090503          	lb	a0,320(s2)
 22a:	0100                	addi	s0,sp,128
 22c:	14090503          	lb	a0,320(s2)
 230:	0100                	addi	s0,sp,128
 232:	14090503          	lb	a0,320(s2)
 236:	0100                	addi	s0,sp,128
 238:	14090503          	lb	a0,320(s2)
 23c:	0100                	addi	s0,sp,128
 23e:	10090503          	lb	a0,256(s2)
 242:	0100                	addi	s0,sp,128
 244:	10090503          	lb	a0,256(s2)
 248:	0100                	addi	s0,sp,128
 24a:	14090503          	lb	a0,320(s2)
 24e:	0100                	addi	s0,sp,128
 250:	14090503          	lb	a0,320(s2)
 254:	0100                	addi	s0,sp,128
 256:	14090503          	lb	a0,320(s2)
 25a:	0100                	addi	s0,sp,128
 25c:	10090503          	lb	a0,256(s2)
 260:	0100                	addi	s0,sp,128
 262:	14090503          	lb	a0,320(s2)
 266:	0100                	addi	s0,sp,128
 268:	14090503          	lb	a0,320(s2)
 26c:	0100                	addi	s0,sp,128
 26e:	14090503          	lb	a0,320(s2)
 272:	0100                	addi	s0,sp,128
 274:	14090503          	lb	a0,320(s2)
 278:	0100                	addi	s0,sp,128
 27a:	14090503          	lb	a0,320(s2)
 27e:	0100                	addi	s0,sp,128
 280:	14090503          	lb	a0,320(s2)
 284:	0100                	addi	s0,sp,128
 286:	14090503          	lb	a0,320(s2)
 28a:	0100                	addi	s0,sp,128
 28c:	14090503          	lb	a0,320(s2)
 290:	0100                	addi	s0,sp,128
 292:	14090503          	lb	a0,320(s2)
 296:	0100                	addi	s0,sp,128
 298:	14090503          	lb	a0,320(s2)
 29c:	0100                	addi	s0,sp,128
 29e:	14090503          	lb	a0,320(s2)
 2a2:	0100                	addi	s0,sp,128
 2a4:	14090503          	lb	a0,320(s2)
 2a8:	0100                	addi	s0,sp,128
 2aa:	14090503          	lb	a0,320(s2)
 2ae:	0100                	addi	s0,sp,128
 2b0:	10090503          	lb	a0,256(s2)
 2b4:	0100                	addi	s0,sp,128
 2b6:	10090503          	lb	a0,256(s2)
 2ba:	0100                	addi	s0,sp,128
 2bc:	10090503          	lb	a0,256(s2)
 2c0:	0100                	addi	s0,sp,128
 2c2:	10090403          	lb	s0,256(s2)
 2c6:	0100                	addi	s0,sp,128
 2c8:	04090103          	lb	sp,64(s2)
 2cc:	0100                	addi	s0,sp,128
 2ce:	1009                	c.nop	-30
 2d0:	0000                	unimp
 2d2:	0101                	addi	sp,sp,0

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
  14:	0708                	addi	a0,sp,896
  16:	8000                	0x8000
  18:	0000                	unimp
  1a:	0000                	unimp
  1c:	005e                	c.slli	zero,0x17
  1e:	0000                	unimp
  20:	000000ab          	0xab
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
  14:	0708                	addi	a0,sp,896
	...

Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	6d6f682f          	0x6d6f682f
   4:	2f65                	jal	7bc <offset+0x6c0>
   6:	6f6c                	flw	fa1,92(a4)
   8:	6976                	flw	fs2,92(sp)
   a:	65442f73          	csrrs	t5,0x654,s0
   e:	6f746b73          	csrrsi	s6,0x6f7,8
  12:	2f70                	fld	fa2,216(a4)
  14:	6952                	flw	fs2,20(sp)
  16:	6556                	flw	fa0,84(sp)
  18:	5f72                	lw	t5,60(sp)
  1a:	65726f63          	bltu	tp,s7,678 <offset+0x57c>
  1e:	7369722f          	0x7369722f
  22:	2f666f63          	bltu	a2,s6,320 <offset+0x224>
  26:	6972                	flw	fs2,28(sp)
  28:	2d766373          	csrrsi	t1,0x2d7,12
  2c:	7261                	lui	tp,0xffff8
  2e:	742d6863          	bltu	s10,sp,77e <offset+0x682>
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
  54:	6c72732f          	0x6c72732f
  58:	302d                	jal	fffff882 <edge2+0xfffff883>
  5a:	2e31                	jal	376 <offset+0x27a>
  5c:	682f0053          	0x682f0053
  60:	2f656d6f          	jal	s10,56356 <offset+0x5625a>
  64:	6f6c                	flw	fa1,92(a4)
  66:	6976                	flw	fs2,92(sp)
  68:	65442f73          	csrrs	t5,0x654,s0
  6c:	6f746b73          	csrrsi	s6,0x6f7,8
  70:	2f70                	fld	fa2,216(a4)
  72:	6952                	flw	fs2,20(sp)
  74:	6556                	flw	fa0,84(sp)
  76:	5f72                	lw	t5,60(sp)
  78:	65726f63          	bltu	tp,s7,6d6 <offset+0x5da>
  7c:	7369722f          	0x7369722f
  80:	2f666f63          	bltu	a2,s6,37e <offset+0x282>
  84:	6972                	flw	fs2,28(sp)
  86:	666f6373          	csrrsi	t1,0x666,30
  8a:	775f 726f 2f6b      	0x2f6b726f775f
  90:	7672                	flw	fa2,60(sp)
  92:	5f693233          	0x5f693233
  96:	2f6d                	jal	850 <offset+0x754>
  98:	2f49                	jal	82a <offset+0x72e>
  9a:	2f637273          	csrrci	tp,0x2f6,6
  9e:	2d6c7273          	csrrci	tp,0x2d6,24
  a2:	3130                	fld	fa2,96(a0)
  a4:	532e                	lw	t1,232(sp)
  a6:	7475642f          	0x7475642f
  aa:	4700                	lw	s0,8(a4)
  ac:	554e                	lw	a0,240(sp)
  ae:	4120                	lw	s0,64(a0)
  b0:	2e322053          	0x2e322053
  b4:	          	snez	a0,zero
