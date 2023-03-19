
my.elf:     file format elf32-littleriscv


Disassembly of section .text.init:

80000000 <rvtest_entry_point>:
80000000:	feedc0b7          	lui	ra,0xfeedc
80000004:	ead08093          	addi	ra,ra,-339 # feedbead <_end+0x7eed8c2d>
80000008:	ff76e137          	lui	sp,0xff76e
8000000c:	f5610113          	addi	sp,sp,-170 # ff76df56 <_end+0x7f76acd6>
80000010:	7fbb71b7          	lui	gp,0x7fbb7
80000014:	fab18193          	addi	gp,gp,-85 # 7fbb6fab <offset+0x7fbb6e93>
80000018:	bfddb237          	lui	tp,0xbfddb
8000001c:	7d520213          	addi	tp,tp,2005 # bfddb7d5 <_end+0x3fdd8555>
80000020:	00000297          	auipc	t0,0x0
80000024:	05828293          	addi	t0,t0,88 # 80000078 <rvtest_code_begin>
80000028:	00002317          	auipc	t1,0x2
8000002c:	fe830313          	addi	t1,t1,-24 # 80002010 <rvtest_data_begin>
80000030:	b7fbb3b7          	lui	t2,0xb7fbb
80000034:	6fa38393          	addi	t2,t2,1786 # b7fbb6fa <_end+0x37fb847a>
80000038:	5bfde437          	lui	s0,0x5bfde
8000003c:	b7d40413          	addi	s0,s0,-1155 # 5bfddb7d <offset+0x5bfdda65>
80000040:	adfef4b7          	lui	s1,0xadfef
80000044:	dbe48493          	addi	s1,s1,-578 # adfeedbe <_end+0x2dfebb3e>
80000048:	56ff7537          	lui	a0,0x56ff7
8000004c:	6df50513          	addi	a0,a0,1759 # 56ff76df <offset+0x56ff75c7>
80000050:	ab7fc5b7          	lui	a1,0xab7fc
80000054:	b6f58593          	addi	a1,a1,-1169 # ab7fbb6f <_end+0x2b7f88ef>
80000058:	d5bfe637          	lui	a2,0xd5bfe
8000005c:	db760613          	addi	a2,a2,-585 # d5bfddb7 <_end+0x55bfab37>
80000060:	eadff6b7          	lui	a3,0xeadff
80000064:	edb68693          	addi	a3,a3,-293 # eadfeedb <_end+0x6adfbc5b>
80000068:	f56ff737          	lui	a4,0xf56ff
8000006c:	76d70713          	addi	a4,a4,1901 # f56ff76d <_end+0x756fc4ed>
80000070:	fab807b7          	lui	a5,0xfab80
80000074:	bb678793          	addi	a5,a5,-1098 # fab7fbb6 <_end+0x7ab7c936>

80000078 <rvtest_code_begin>:
80000078:	00003a17          	auipc	s4,0x3
8000007c:	09ca0a13          	addi	s4,s4,156 # 80003114 <signature_x20_0>

80000080 <inst_0>:
80000080:	80000837          	lui	a6,0x80000
80000084:	00800d93          	li	s11,8
80000088:	41b85db3          	sra	s11,a6,s11
8000008c:	01ba2023          	sw	s11,0(s4)

80000090 <inst_1>:
80000090:	02000637          	lui	a2,0x2000
80000094:	02000637          	lui	a2,0x2000
80000098:	40c65833          	sra	a6,a2,a2
8000009c:	010a2223          	sw	a6,4(s4)

800000a0 <inst_2>:
800000a0:	fffff0b7          	lui	ra,0xfffff
800000a4:	7ff08093          	addi	ra,ra,2047 # fffff7ff <_end+0x7fffc57f>
800000a8:	fffff0b7          	lui	ra,0xfffff
800000ac:	7ff08093          	addi	ra,ra,2047 # fffff7ff <_end+0x7fffc57f>
800000b0:	4010d0b3          	sra	ra,ra,ra
800000b4:	001a2423          	sw	ra,8(s4)

800000b8 <inst_3>:
800000b8:	333336b7          	lui	a3,0x33333
800000bc:	33368693          	addi	a3,a3,819 # 33333333 <offset+0x3333321b>
800000c0:	00000993          	li	s3,0
800000c4:	4136d6b3          	sra	a3,a3,s3
800000c8:	00da2623          	sw	a3,12(s4)

800000cc <inst_4>:
800000cc:	00600e13          	li	t3,6
800000d0:	00600113          	li	sp,6
800000d4:	402e5433          	sra	s0,t3,sp
800000d8:	008a2823          	sw	s0,16(s4)

800000dc <inst_5>:
800000dc:	00000d13          	li	s10,0
800000e0:	00300f93          	li	t6,3
800000e4:	41fd59b3          	sra	s3,s10,t6
800000e8:	013a2a23          	sw	s3,20(s4)

800000ec <inst_6>:
800000ec:	80000737          	lui	a4,0x80000
800000f0:	fff70713          	addi	a4,a4,-1 # 7fffffff <_end+0xffffcd7f>
800000f4:	01200e13          	li	t3,18
800000f8:	41c75eb3          	sra	t4,a4,t3
800000fc:	01da2c23          	sw	t4,24(s4)

80000100 <inst_7>:
80000100:	00100513          	li	a0,1
80000104:	00200d13          	li	s10,2
80000108:	41a55633          	sra	a2,a0,s10
8000010c:	00ca2e23          	sw	a2,28(s4)

80000110 <inst_8>:
80000110:	00200f13          	li	t5,2
80000114:	00400813          	li	a6,4
80000118:	410f57b3          	sra	a5,t5,a6
8000011c:	02fa2023          	sw	a5,32(s4)

80000120 <inst_9>:
80000120:	00400c13          	li	s8,4
80000124:	00000013          	nop
80000128:	400c5333          	sra	t1,s8,zero
8000012c:	026a2223          	sw	t1,36(s4)

80000130 <inst_10>:
80000130:	00800a93          	li	s5,8
80000134:	00a00793          	li	a5,10
80000138:	40fad1b3          	sra	gp,s5,a5
8000013c:	023a2423          	sw	gp,40(s4)

80000140 <inst_11>:
80000140:	01000793          	li	a5,16
80000144:	00000f13          	li	t5,0
80000148:	41e7d533          	sra	a0,a5,t5
8000014c:	02aa2623          	sw	a0,44(s4)

80000150 <inst_12>:
80000150:	02000913          	li	s2,32
80000154:	00300213          	li	tp,3
80000158:	40495b33          	sra	s6,s2,tp
8000015c:	036a2823          	sw	s6,48(s4)

80000160 <inst_13>:
80000160:	04000993          	li	s3,64
80000164:	01700893          	li	a7,23
80000168:	4119d5b3          	sra	a1,s3,a7
8000016c:	02ba2a23          	sw	a1,52(s4)

80000170 <inst_14>:
80000170:	08000293          	li	t0,128
80000174:	00800713          	li	a4,8
80000178:	40e2d033          	sra	zero,t0,a4
8000017c:	020a2c23          	sw	zero,56(s4)

80000180 <inst_15>:
80000180:	10000313          	li	t1,256
80000184:	00400c13          	li	s8,4
80000188:	418352b3          	sra	t0,t1,s8
8000018c:	025a2e23          	sw	t0,60(s4)

80000190 <inst_16>:
80000190:	20000393          	li	t2,512
80000194:	01f00913          	li	s2,31
80000198:	4123dfb3          	sra	t6,t2,s2
8000019c:	05fa2023          	sw	t6,64(s4)

800001a0 <inst_17>:
800001a0:	40000f93          	li	t6,1024
800001a4:	01000a93          	li	s5,16
800001a8:	415fdf33          	sra	t5,t6,s5
800001ac:	05ea2223          	sw	t5,68(s4)

800001b0 <inst_18>:
800001b0:	00001237          	lui	tp,0x1
800001b4:	80020213          	addi	tp,tp,-2048 # 800 <offset+0x6e8>
800001b8:	01300593          	li	a1,19
800001bc:	40b25133          	sra	sp,tp,a1
800001c0:	042a2423          	sw	sp,72(s4)

800001c4 <inst_19>:
800001c4:	00001b37          	lui	s6,0x1
800001c8:	00200c93          	li	s9,2
800001cc:	419b54b3          	sra	s1,s6,s9
800001d0:	049a2623          	sw	s1,76(s4)
800001d4:	00003097          	auipc	ra,0x3
800001d8:	f9008093          	addi	ra,ra,-112 # 80003164 <signature_x1_0>

800001dc <inst_20>:
800001dc:	00002bb7          	lui	s7,0x2
800001e0:	01f00693          	li	a3,31
800001e4:	40dbd733          	sra	a4,s7,a3
800001e8:	00e0a023          	sw	a4,0(ra)

800001ec <inst_21>:
800001ec:	00004437          	lui	s0,0x4
800001f0:	00a00e93          	li	t4,10
800001f4:	41d45e33          	sra	t3,s0,t4
800001f8:	01c0a223          	sw	t3,4(ra)

800001fc <inst_22>:
800001fc:	000088b7          	lui	a7,0x8
80000200:	01300413          	li	s0,19
80000204:	4088dd33          	sra	s10,a7,s0
80000208:	01a0a423          	sw	s10,8(ra)

8000020c <inst_23>:
8000020c:	00010eb7          	lui	t4,0x10
80000210:	01000193          	li	gp,16
80000214:	403edbb3          	sra	s7,t4,gp
80000218:	0170a623          	sw	s7,12(ra)

8000021c <inst_24>:
8000021c:	000204b7          	lui	s1,0x20
80000220:	00000293          	li	t0,0
80000224:	4054d3b3          	sra	t2,s1,t0
80000228:	0070a823          	sw	t2,16(ra)

8000022c <inst_25>:
8000022c:	00040a37          	lui	s4,0x40
80000230:	00800393          	li	t2,8
80000234:	407a5c33          	sra	s8,s4,t2
80000238:	0180aa23          	sw	s8,20(ra)

8000023c <inst_26>:
8000023c:	00080cb7          	lui	s9,0x80
80000240:	00800513          	li	a0,8
80000244:	40acd8b3          	sra	a7,s9,a0
80000248:	0110ac23          	sw	a7,24(ra)

8000024c <inst_27>:
8000024c:	00100db7          	lui	s11,0x100
80000250:	01b00b13          	li	s6,27
80000254:	416dda33          	sra	s4,s11,s6
80000258:	0140ae23          	sw	s4,28(ra)

8000025c <inst_28>:
8000025c:	002001b7          	lui	gp,0x200
80000260:	00b00313          	li	t1,11
80000264:	4061dcb3          	sra	s9,gp,t1
80000268:	0390a023          	sw	s9,32(ra)

8000026c <inst_29>:
8000026c:	00000013          	nop
80000270:	00800b93          	li	s7,8
80000274:	41705233          	sra	tp,zero,s7
80000278:	0240a223          	sw	tp,36(ra)

8000027c <inst_30>:
8000027c:	00800137          	lui	sp,0x800
80000280:	01b00a13          	li	s4,27
80000284:	41415933          	sra	s2,sp,s4
80000288:	0320a423          	sw	s2,40(ra)

8000028c <inst_31>:
8000028c:	010005b7          	lui	a1,0x1000
80000290:	00b00493          	li	s1,11
80000294:	4095dab3          	sra	s5,a1,s1
80000298:	0350a623          	sw	s5,44(ra)

8000029c <inst_32>:
8000029c:	04000537          	lui	a0,0x4000
800002a0:	00c00593          	li	a1,12
800002a4:	40b55633          	sra	a2,a0,a1
800002a8:	02c0a823          	sw	a2,48(ra)

800002ac <inst_33>:
800002ac:	08000537          	lui	a0,0x8000
800002b0:	00400593          	li	a1,4
800002b4:	40b55633          	sra	a2,a0,a1
800002b8:	02c0aa23          	sw	a2,52(ra)

800002bc <inst_34>:
800002bc:	10000537          	lui	a0,0x10000
800002c0:	00b00593          	li	a1,11
800002c4:	40b55633          	sra	a2,a0,a1
800002c8:	02c0ac23          	sw	a2,56(ra)

800002cc <inst_35>:
800002cc:	20000537          	lui	a0,0x20000
800002d0:	00a00593          	li	a1,10
800002d4:	40b55633          	sra	a2,a0,a1
800002d8:	02c0ae23          	sw	a2,60(ra)

800002dc <inst_36>:
800002dc:	40000537          	lui	a0,0x40000
800002e0:	00f00593          	li	a1,15
800002e4:	40b55633          	sra	a2,a0,a1
800002e8:	04c0a023          	sw	a2,64(ra)

800002ec <inst_37>:
800002ec:	ffe00513          	li	a0,-2
800002f0:	00700593          	li	a1,7
800002f4:	40b55633          	sra	a2,a0,a1
800002f8:	04c0a223          	sw	a2,68(ra)

800002fc <inst_38>:
800002fc:	ffd00513          	li	a0,-3
80000300:	01200593          	li	a1,18
80000304:	40b55633          	sra	a2,a0,a1
80000308:	04c0a423          	sw	a2,72(ra)

8000030c <inst_39>:
8000030c:	ffb00513          	li	a0,-5
80000310:	00400593          	li	a1,4
80000314:	40b55633          	sra	a2,a0,a1
80000318:	04c0a623          	sw	a2,76(ra)

8000031c <inst_40>:
8000031c:	ff700513          	li	a0,-9
80000320:	00500593          	li	a1,5
80000324:	40b55633          	sra	a2,a0,a1
80000328:	04c0a823          	sw	a2,80(ra)

8000032c <inst_41>:
8000032c:	fef00513          	li	a0,-17
80000330:	01d00593          	li	a1,29
80000334:	40b55633          	sra	a2,a0,a1
80000338:	04c0aa23          	sw	a2,84(ra)

8000033c <inst_42>:
8000033c:	fdf00513          	li	a0,-33
80000340:	00d00593          	li	a1,13
80000344:	40b55633          	sra	a2,a0,a1
80000348:	04c0ac23          	sw	a2,88(ra)

8000034c <inst_43>:
8000034c:	fbf00513          	li	a0,-65
80000350:	01700593          	li	a1,23
80000354:	40b55633          	sra	a2,a0,a1
80000358:	04c0ae23          	sw	a2,92(ra)

8000035c <inst_44>:
8000035c:	f7f00513          	li	a0,-129
80000360:	00d00593          	li	a1,13
80000364:	40b55633          	sra	a2,a0,a1
80000368:	06c0a023          	sw	a2,96(ra)

8000036c <inst_45>:
8000036c:	eff00513          	li	a0,-257
80000370:	01300593          	li	a1,19
80000374:	40b55633          	sra	a2,a0,a1
80000378:	06c0a223          	sw	a2,100(ra)

8000037c <inst_46>:
8000037c:	dff00513          	li	a0,-513
80000380:	00100593          	li	a1,1
80000384:	40b55633          	sra	a2,a0,a1
80000388:	06c0a423          	sw	a2,104(ra)

8000038c <inst_47>:
8000038c:	bff00513          	li	a0,-1025
80000390:	01500593          	li	a1,21
80000394:	40b55633          	sra	a2,a0,a1
80000398:	06c0a623          	sw	a2,108(ra)

8000039c <inst_48>:
8000039c:	fffff537          	lui	a0,0xfffff
800003a0:	fff50513          	addi	a0,a0,-1 # ffffefff <_end+0x7fffbd7f>
800003a4:	00e00593          	li	a1,14
800003a8:	40b55633          	sra	a2,a0,a1
800003ac:	06c0a823          	sw	a2,112(ra)

800003b0 <inst_49>:
800003b0:	ffffe537          	lui	a0,0xffffe
800003b4:	fff50513          	addi	a0,a0,-1 # ffffdfff <_end+0x7fffad7f>
800003b8:	00800593          	li	a1,8
800003bc:	40b55633          	sra	a2,a0,a1
800003c0:	06c0aa23          	sw	a2,116(ra)

800003c4 <inst_50>:
800003c4:	ffffc537          	lui	a0,0xffffc
800003c8:	fff50513          	addi	a0,a0,-1 # ffffbfff <_end+0x7fff8d7f>
800003cc:	00e00593          	li	a1,14
800003d0:	40b55633          	sra	a2,a0,a1
800003d4:	06c0ac23          	sw	a2,120(ra)

800003d8 <inst_51>:
800003d8:	ffff8537          	lui	a0,0xffff8
800003dc:	fff50513          	addi	a0,a0,-1 # ffff7fff <_end+0x7fff4d7f>
800003e0:	00c00593          	li	a1,12
800003e4:	40b55633          	sra	a2,a0,a1
800003e8:	06c0ae23          	sw	a2,124(ra)

800003ec <inst_52>:
800003ec:	ffff0537          	lui	a0,0xffff0
800003f0:	fff50513          	addi	a0,a0,-1 # fffeffff <_end+0x7ffecd7f>
800003f4:	01700593          	li	a1,23
800003f8:	40b55633          	sra	a2,a0,a1
800003fc:	08c0a023          	sw	a2,128(ra)

80000400 <inst_53>:
80000400:	fffe0537          	lui	a0,0xfffe0
80000404:	fff50513          	addi	a0,a0,-1 # fffdffff <_end+0x7ffdcd7f>
80000408:	00a00593          	li	a1,10
8000040c:	40b55633          	sra	a2,a0,a1
80000410:	08c0a223          	sw	a2,132(ra)

80000414 <inst_54>:
80000414:	fffc0537          	lui	a0,0xfffc0
80000418:	fff50513          	addi	a0,a0,-1 # fffbffff <_end+0x7ffbcd7f>
8000041c:	00b00593          	li	a1,11
80000420:	40b55633          	sra	a2,a0,a1
80000424:	08c0a423          	sw	a2,136(ra)

80000428 <inst_55>:
80000428:	fff80537          	lui	a0,0xfff80
8000042c:	fff50513          	addi	a0,a0,-1 # fff7ffff <_end+0x7ff7cd7f>
80000430:	00000593          	li	a1,0
80000434:	40b55633          	sra	a2,a0,a1
80000438:	08c0a623          	sw	a2,140(ra)

8000043c <inst_56>:
8000043c:	ff800537          	lui	a0,0xff800
80000440:	fff50513          	addi	a0,a0,-1 # ff7fffff <_end+0x7f7fcd7f>
80000444:	01300593          	li	a1,19
80000448:	40b55633          	sra	a2,a0,a1
8000044c:	08c0a823          	sw	a2,144(ra)

80000450 <inst_57>:
80000450:	ff000537          	lui	a0,0xff000
80000454:	fff50513          	addi	a0,a0,-1 # feffffff <_end+0x7effcd7f>
80000458:	00c00593          	li	a1,12
8000045c:	40b55633          	sra	a2,a0,a1
80000460:	08c0aa23          	sw	a2,148(ra)

80000464 <inst_58>:
80000464:	fe000537          	lui	a0,0xfe000
80000468:	fff50513          	addi	a0,a0,-1 # fdffffff <_end+0x7dffcd7f>
8000046c:	01f00593          	li	a1,31
80000470:	40b55633          	sra	a2,a0,a1
80000474:	08c0ac23          	sw	a2,152(ra)

80000478 <inst_59>:
80000478:	fc000537          	lui	a0,0xfc000
8000047c:	fff50513          	addi	a0,a0,-1 # fbffffff <_end+0x7bffcd7f>
80000480:	00b00593          	li	a1,11
80000484:	40b55633          	sra	a2,a0,a1
80000488:	08c0ae23          	sw	a2,156(ra)

8000048c <inst_60>:
8000048c:	f8000537          	lui	a0,0xf8000
80000490:	fff50513          	addi	a0,a0,-1 # f7ffffff <_end+0x77ffcd7f>
80000494:	00a00593          	li	a1,10
80000498:	40b55633          	sra	a2,a0,a1
8000049c:	0ac0a023          	sw	a2,160(ra)

800004a0 <inst_61>:
800004a0:	f0000537          	lui	a0,0xf0000
800004a4:	fff50513          	addi	a0,a0,-1 # efffffff <_end+0x6fffcd7f>
800004a8:	00400593          	li	a1,4
800004ac:	40b55633          	sra	a2,a0,a1
800004b0:	0ac0a223          	sw	a2,164(ra)

800004b4 <inst_62>:
800004b4:	e0000537          	lui	a0,0xe0000
800004b8:	fff50513          	addi	a0,a0,-1 # dfffffff <_end+0x5fffcd7f>
800004bc:	00700593          	li	a1,7
800004c0:	40b55633          	sra	a2,a0,a1
800004c4:	0ac0a423          	sw	a2,168(ra)

800004c8 <inst_63>:
800004c8:	c0000537          	lui	a0,0xc0000
800004cc:	fff50513          	addi	a0,a0,-1 # bfffffff <_end+0x3fffcd7f>
800004d0:	00500593          	li	a1,5
800004d4:	40b55633          	sra	a2,a0,a1
800004d8:	0ac0a623          	sw	a2,172(ra)

800004dc <inst_64>:
800004dc:	55555537          	lui	a0,0x55555
800004e0:	55550513          	addi	a0,a0,1365 # 55555555 <offset+0x5555543d>
800004e4:	00b00593          	li	a1,11
800004e8:	40b55633          	sra	a2,a0,a1
800004ec:	0ac0a823          	sw	a2,176(ra)

800004f0 <inst_65>:
800004f0:	aaaab537          	lui	a0,0xaaaab
800004f4:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <_end+0x2aaa782a>
800004f8:	01300593          	li	a1,19
800004fc:	40b55633          	sra	a2,a0,a1
80000500:	0ac0aa23          	sw	a2,180(ra)

80000504 <inst_66>:
80000504:	00300513          	li	a0,3
80000508:	01700593          	li	a1,23
8000050c:	40b55633          	sra	a2,a0,a1
80000510:	0ac0ac23          	sw	a2,184(ra)

80000514 <inst_67>:
80000514:	00500513          	li	a0,5
80000518:	00e00593          	li	a1,14
8000051c:	40b55633          	sra	a2,a0,a1
80000520:	0ac0ae23          	sw	a2,188(ra)

80000524 <inst_68>:
80000524:	66666537          	lui	a0,0x66666
80000528:	66650513          	addi	a0,a0,1638 # 66666666 <offset+0x6666654e>
8000052c:	01300593          	li	a1,19
80000530:	40b55633          	sra	a2,a0,a1
80000534:	0cc0a023          	sw	a2,192(ra)

80000538 <inst_69>:
80000538:	ffff5537          	lui	a0,0xffff5
8000053c:	afc50513          	addi	a0,a0,-1284 # ffff4afc <_end+0x7fff187c>
80000540:	00100593          	li	a1,1
80000544:	40b55633          	sra	a2,a0,a1
80000548:	0cc0a223          	sw	a2,196(ra)

8000054c <inst_70>:
8000054c:	0000b537          	lui	a0,0xb
80000550:	50550513          	addi	a0,a0,1285 # b505 <offset+0xb3ed>
80000554:	00800593          	li	a1,8
80000558:	40b55633          	sra	a2,a0,a1
8000055c:	0cc0a423          	sw	a2,200(ra)

80000560 <inst_71>:
80000560:	00000513          	li	a0,0
80000564:	01e00593          	li	a1,30
80000568:	40b55633          	sra	a2,a0,a1
8000056c:	0cc0a623          	sw	a2,204(ra)

80000570 <inst_72>:
80000570:	0000b537          	lui	a0,0xb
80000574:	50450513          	addi	a0,a0,1284 # b504 <offset+0xb3ec>
80000578:	00e00593          	li	a1,14
8000057c:	40b55633          	sra	a2,a0,a1
80000580:	0cc0a823          	sw	a2,208(ra)

80000584 <inst_73>:
80000584:	55555537          	lui	a0,0x55555
80000588:	55450513          	addi	a0,a0,1364 # 55555554 <offset+0x5555543c>
8000058c:	00c00593          	li	a1,12
80000590:	40b55633          	sra	a2,a0,a1
80000594:	0cc0aa23          	sw	a2,212(ra)

80000598 <inst_74>:
80000598:	ffc00537          	lui	a0,0xffc00
8000059c:	fff50513          	addi	a0,a0,-1 # ffbfffff <_end+0x7fbfcd7f>
800005a0:	01300593          	li	a1,19
800005a4:	40b55633          	sra	a2,a0,a1
800005a8:	0cc0ac23          	sw	a2,216(ra)

800005ac <inst_75>:
800005ac:	33333537          	lui	a0,0x33333
800005b0:	33450513          	addi	a0,a0,820 # 33333334 <offset+0x3333321c>
800005b4:	00700593          	li	a1,7
800005b8:	40b55633          	sra	a2,a0,a1
800005bc:	0cc0ae23          	sw	a2,220(ra)

800005c0 <inst_76>:
800005c0:	ffe00537          	lui	a0,0xffe00
800005c4:	fff50513          	addi	a0,a0,-1 # ffdfffff <_end+0x7fdfcd7f>
800005c8:	00200593          	li	a1,2
800005cc:	40b55633          	sra	a2,a0,a1
800005d0:	0ec0a023          	sw	a2,224(ra)

800005d4 <inst_77>:
800005d4:	33333537          	lui	a0,0x33333
800005d8:	33250513          	addi	a0,a0,818 # 33333332 <offset+0x3333321a>
800005dc:	00000593          	li	a1,0
800005e0:	40b55633          	sra	a2,a0,a1
800005e4:	0ec0a223          	sw	a2,228(ra)

800005e8 <inst_78>:
800005e8:	66666537          	lui	a0,0x66666
800005ec:	66550513          	addi	a0,a0,1637 # 66666665 <offset+0x6666654d>
800005f0:	01700593          	li	a1,23
800005f4:	40b55633          	sra	a2,a0,a1
800005f8:	0ec0a423          	sw	a2,232(ra)

800005fc <inst_79>:
800005fc:	0000b537          	lui	a0,0xb
80000600:	50350513          	addi	a0,a0,1283 # b503 <offset+0xb3eb>
80000604:	01f00593          	li	a1,31
80000608:	40b55633          	sra	a2,a0,a1
8000060c:	0ec0a623          	sw	a2,236(ra)

80000610 <inst_80>:
80000610:	55555537          	lui	a0,0x55555
80000614:	55650513          	addi	a0,a0,1366 # 55555556 <offset+0x5555543e>
80000618:	00500593          	li	a1,5
8000061c:	40b55633          	sra	a2,a0,a1
80000620:	0ec0a823          	sw	a2,240(ra)

80000624 <inst_81>:
80000624:	aaaab537          	lui	a0,0xaaaab
80000628:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <_end+0x2aaa782b>
8000062c:	00100593          	li	a1,1
80000630:	40b55633          	sra	a2,a0,a1
80000634:	0ec0aa23          	sw	a2,244(ra)

80000638 <inst_82>:
80000638:	fff00537          	lui	a0,0xfff00
8000063c:	fff50513          	addi	a0,a0,-1 # ffefffff <_end+0x7fefcd7f>
80000640:	01000593          	li	a1,16
80000644:	40b55633          	sra	a2,a0,a1
80000648:	0ec0ac23          	sw	a2,248(ra)

8000064c <inst_83>:
8000064c:	66666537          	lui	a0,0x66666
80000650:	66750513          	addi	a0,a0,1639 # 66666667 <offset+0x6666654f>
80000654:	00000593          	li	a1,0
80000658:	40b55633          	sra	a2,a0,a1
8000065c:	0ec0ae23          	sw	a2,252(ra)

80000660 <inst_84>:
80000660:	ffff5537          	lui	a0,0xffff5
80000664:	afd50513          	addi	a0,a0,-1283 # ffff4afd <_end+0x7fff187d>
80000668:	00d00593          	li	a1,13
8000066c:	40b55633          	sra	a2,a0,a1
80000670:	10c0a023          	sw	a2,256(ra)

80000674 <inst_85>:
80000674:	02000537          	lui	a0,0x2000
80000678:	01200593          	li	a1,18
8000067c:	40b55633          	sra	a2,a0,a1
80000680:	10c0a223          	sw	a2,260(ra)

80000684 <inst_86>:
80000684:	fffff537          	lui	a0,0xfffff
80000688:	7ff50513          	addi	a0,a0,2047 # fffff7ff <_end+0x7fffc57f>
8000068c:	00000593          	li	a1,0
80000690:	40b55633          	sra	a2,a0,a1
80000694:	10c0a423          	sw	a2,264(ra)

80000698 <inst_87>:
80000698:	00400513          	li	a0,4
8000069c:	00300593          	li	a1,3
800006a0:	40b55633          	sra	a2,a0,a1
800006a4:	10c0a623          	sw	a2,268(ra)

800006a8 <inst_88>:
800006a8:	08000513          	li	a0,128
800006ac:	00800593          	li	a1,8
800006b0:	40b55633          	sra	a2,a0,a1
800006b4:	10c0a823          	sw	a2,272(ra)

800006b8 <inst_89>:
800006b8:	00400537          	lui	a0,0x400
800006bc:	00800593          	li	a1,8
800006c0:	40b55633          	sra	a2,a0,a1
800006c4:	10c0aa23          	sw	a2,276(ra)

800006c8 <cleanup_epilogs>:
800006c8:	0040006f          	j	800006cc <exit_cleanup>

800006cc <exit_cleanup>:
800006cc:	00100093          	li	ra,1

800006d0 <write_tohost>:
800006d0:	00001f17          	auipc	t5,0x1
800006d4:	921f2823          	sw	ra,-1744(t5) # 80001000 <tohost>
800006d8:	ff9ff06f          	j	800006d0 <write_tohost>
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
80002020:	deadbeef          	jal	t4,7ffdd60a <offset+0x7ffdd4f2>
80002024:	deadbeef          	jal	t4,7ffdd60e <offset+0x7ffdd4f6>

80002028 <rvtest_data_end>:
	...

80003000 <begin_regstate>:
80003000:	0080                	addi	s0,sp,64
	...

80003100 <end_regstate>:
80003100:	0004                	0x4
	...

80003110 <begin_signature>:
80003110:	a309                	j	80003612 <_end+0x392>
80003112:	6f5c                	flw	fa5,28(a4)

80003114 <signature_x20_0>:
80003114:	deadbeef          	jal	t4,7ffde6fe <offset+0x7ffde5e6>
80003118:	deadbeef          	jal	t4,7ffde702 <offset+0x7ffde5ea>
8000311c:	deadbeef          	jal	t4,7ffde706 <offset+0x7ffde5ee>
80003120:	deadbeef          	jal	t4,7ffde70a <offset+0x7ffde5f2>
80003124:	deadbeef          	jal	t4,7ffde70e <offset+0x7ffde5f6>
80003128:	deadbeef          	jal	t4,7ffde712 <offset+0x7ffde5fa>
8000312c:	deadbeef          	jal	t4,7ffde716 <offset+0x7ffde5fe>
80003130:	deadbeef          	jal	t4,7ffde71a <offset+0x7ffde602>
80003134:	deadbeef          	jal	t4,7ffde71e <offset+0x7ffde606>
80003138:	deadbeef          	jal	t4,7ffde722 <offset+0x7ffde60a>
8000313c:	deadbeef          	jal	t4,7ffde726 <offset+0x7ffde60e>
80003140:	deadbeef          	jal	t4,7ffde72a <offset+0x7ffde612>
80003144:	deadbeef          	jal	t4,7ffde72e <offset+0x7ffde616>
80003148:	deadbeef          	jal	t4,7ffde732 <offset+0x7ffde61a>
8000314c:	deadbeef          	jal	t4,7ffde736 <offset+0x7ffde61e>
80003150:	deadbeef          	jal	t4,7ffde73a <offset+0x7ffde622>
80003154:	deadbeef          	jal	t4,7ffde73e <offset+0x7ffde626>
80003158:	deadbeef          	jal	t4,7ffde742 <offset+0x7ffde62a>
8000315c:	deadbeef          	jal	t4,7ffde746 <offset+0x7ffde62e>
80003160:	deadbeef          	jal	t4,7ffde74a <offset+0x7ffde632>

80003164 <signature_x1_0>:
80003164:	deadbeef          	jal	t4,7ffde74e <offset+0x7ffde636>
80003168:	deadbeef          	jal	t4,7ffde752 <offset+0x7ffde63a>
8000316c:	deadbeef          	jal	t4,7ffde756 <offset+0x7ffde63e>
80003170:	deadbeef          	jal	t4,7ffde75a <offset+0x7ffde642>
80003174:	deadbeef          	jal	t4,7ffde75e <offset+0x7ffde646>
80003178:	deadbeef          	jal	t4,7ffde762 <offset+0x7ffde64a>
8000317c:	deadbeef          	jal	t4,7ffde766 <offset+0x7ffde64e>
80003180:	deadbeef          	jal	t4,7ffde76a <offset+0x7ffde652>
80003184:	deadbeef          	jal	t4,7ffde76e <offset+0x7ffde656>
80003188:	deadbeef          	jal	t4,7ffde772 <offset+0x7ffde65a>
8000318c:	deadbeef          	jal	t4,7ffde776 <offset+0x7ffde65e>
80003190:	deadbeef          	jal	t4,7ffde77a <offset+0x7ffde662>
80003194:	deadbeef          	jal	t4,7ffde77e <offset+0x7ffde666>
80003198:	deadbeef          	jal	t4,7ffde782 <offset+0x7ffde66a>
8000319c:	deadbeef          	jal	t4,7ffde786 <offset+0x7ffde66e>
800031a0:	deadbeef          	jal	t4,7ffde78a <offset+0x7ffde672>
800031a4:	deadbeef          	jal	t4,7ffde78e <offset+0x7ffde676>
800031a8:	deadbeef          	jal	t4,7ffde792 <offset+0x7ffde67a>
800031ac:	deadbeef          	jal	t4,7ffde796 <offset+0x7ffde67e>
800031b0:	deadbeef          	jal	t4,7ffde79a <offset+0x7ffde682>
800031b4:	deadbeef          	jal	t4,7ffde79e <offset+0x7ffde686>
800031b8:	deadbeef          	jal	t4,7ffde7a2 <offset+0x7ffde68a>
800031bc:	deadbeef          	jal	t4,7ffde7a6 <offset+0x7ffde68e>
800031c0:	deadbeef          	jal	t4,7ffde7aa <offset+0x7ffde692>
800031c4:	deadbeef          	jal	t4,7ffde7ae <offset+0x7ffde696>
800031c8:	deadbeef          	jal	t4,7ffde7b2 <offset+0x7ffde69a>
800031cc:	deadbeef          	jal	t4,7ffde7b6 <offset+0x7ffde69e>
800031d0:	deadbeef          	jal	t4,7ffde7ba <offset+0x7ffde6a2>
800031d4:	deadbeef          	jal	t4,7ffde7be <offset+0x7ffde6a6>
800031d8:	deadbeef          	jal	t4,7ffde7c2 <offset+0x7ffde6aa>
800031dc:	deadbeef          	jal	t4,7ffde7c6 <offset+0x7ffde6ae>
800031e0:	deadbeef          	jal	t4,7ffde7ca <offset+0x7ffde6b2>
800031e4:	deadbeef          	jal	t4,7ffde7ce <offset+0x7ffde6b6>
800031e8:	deadbeef          	jal	t4,7ffde7d2 <offset+0x7ffde6ba>
800031ec:	deadbeef          	jal	t4,7ffde7d6 <offset+0x7ffde6be>
800031f0:	deadbeef          	jal	t4,7ffde7da <offset+0x7ffde6c2>
800031f4:	deadbeef          	jal	t4,7ffde7de <offset+0x7ffde6c6>
800031f8:	deadbeef          	jal	t4,7ffde7e2 <offset+0x7ffde6ca>
800031fc:	deadbeef          	jal	t4,7ffde7e6 <offset+0x7ffde6ce>
80003200:	deadbeef          	jal	t4,7ffde7ea <offset+0x7ffde6d2>
80003204:	deadbeef          	jal	t4,7ffde7ee <offset+0x7ffde6d6>
80003208:	deadbeef          	jal	t4,7ffde7f2 <offset+0x7ffde6da>
8000320c:	deadbeef          	jal	t4,7ffde7f6 <offset+0x7ffde6de>
80003210:	deadbeef          	jal	t4,7ffde7fa <offset+0x7ffde6e2>
80003214:	deadbeef          	jal	t4,7ffde7fe <offset+0x7ffde6e6>
80003218:	deadbeef          	jal	t4,7ffde802 <offset+0x7ffde6ea>
8000321c:	deadbeef          	jal	t4,7ffde806 <offset+0x7ffde6ee>
80003220:	deadbeef          	jal	t4,7ffde80a <offset+0x7ffde6f2>
80003224:	deadbeef          	jal	t4,7ffde80e <offset+0x7ffde6f6>
80003228:	deadbeef          	jal	t4,7ffde812 <offset+0x7ffde6fa>
8000322c:	deadbeef          	jal	t4,7ffde816 <offset+0x7ffde6fe>
80003230:	deadbeef          	jal	t4,7ffde81a <offset+0x7ffde702>
80003234:	deadbeef          	jal	t4,7ffde81e <offset+0x7ffde706>
80003238:	deadbeef          	jal	t4,7ffde822 <offset+0x7ffde70a>
8000323c:	deadbeef          	jal	t4,7ffde826 <offset+0x7ffde70e>
80003240:	deadbeef          	jal	t4,7ffde82a <offset+0x7ffde712>
80003244:	deadbeef          	jal	t4,7ffde82e <offset+0x7ffde716>
80003248:	deadbeef          	jal	t4,7ffde832 <offset+0x7ffde71a>
8000324c:	deadbeef          	jal	t4,7ffde836 <offset+0x7ffde71e>
80003250:	deadbeef          	jal	t4,7ffde83a <offset+0x7ffde722>
80003254:	deadbeef          	jal	t4,7ffde83e <offset+0x7ffde726>
80003258:	deadbeef          	jal	t4,7ffde842 <offset+0x7ffde72a>
8000325c:	deadbeef          	jal	t4,7ffde846 <offset+0x7ffde72e>
80003260:	deadbeef          	jal	t4,7ffde84a <offset+0x7ffde732>
80003264:	deadbeef          	jal	t4,7ffde84e <offset+0x7ffde736>
80003268:	deadbeef          	jal	t4,7ffde852 <offset+0x7ffde73a>
8000326c:	deadbeef          	jal	t4,7ffde856 <offset+0x7ffde73e>
80003270:	deadbeef          	jal	t4,7ffde85a <offset+0x7ffde742>
80003274:	deadbeef          	jal	t4,7ffde85e <offset+0x7ffde746>
80003278:	deadbeef          	jal	t4,7ffde862 <offset+0x7ffde74a>

8000327c <sig_end_canary>:
8000327c:	a309                	j	8000377e <_end+0x4fe>
8000327e:	6f5c                	flw	fa5,28(a4)

Disassembly of section .riscv.attributes:

00000000 <.riscv.attributes>:
   0:	1941                	addi	s2,s2,-16
   2:	0000                	unimp
   4:	7200                	flw	fs0,32(a2)
   6:	7369                	lui	t1,0xffffa
   8:	01007663          	bgeu	zero,a6,14 <absimm+0xc>
   c:	0000000f          	fence	unknown,unknown
  10:	7205                	lui	tp,0xfffe1
  12:	3376                	fld	ft6,376(sp)
  14:	6932                	flw	fs2,12(sp)
  16:	7032                	flw	ft0,44(sp)
  18:	0030                	addi	a2,sp,8

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	02be                	slli	t0,t0,0xf
   2:	0000                	unimp
   4:	00740003          	lb	zero,7(s0) # 4007 <offset+0x3eef>
   8:	0000                	unimp
   a:	0101                	addi	sp,sp,0
   c:	000d0efb          	0xd0efb
  10:	0101                	addi	sp,sp,0
  12:	0101                	addi	sp,sp,0
  14:	0000                	unimp
  16:	0100                	addi	s0,sp,128
  18:	0000                	unimp
  1a:	2f01                	jal	72a <offset+0x612>
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
  44:	612d7663          	bgeu	s10,s2,650 <offset+0x538>
  48:	6372                	flw	ft6,28(sp)
  4a:	2d68                	fld	fa0,216(a0)
  4c:	6574                	flw	fa3,76(a0)
  4e:	722f7473          	csrrci	s0,0x722,30
  52:	7369                	lui	t1,0xffffa
  54:	742d7663          	bgeu	s10,sp,7a0 <offset+0x688>
  58:	7365                	lui	t1,0xffff9
  5a:	2d74                	fld	fa3,216(a0)
  5c:	74697573          	csrrci	a0,0x746,18
  60:	2f65                	jal	818 <offset+0x700>
  62:	7672                	flw	fa2,60(sp)
  64:	5f693233          	0x5f693233
  68:	2f6d                	jal	822 <offset+0x70a>
  6a:	2f49                	jal	7fc <offset+0x6e4>
  6c:	00637273          	csrrci	tp,0x6,6
  70:	7300                	flw	fs0,32(a4)
  72:	6172                	flw	ft2,28(sp)
  74:	302d                	jal	fffff89e <_end+0x7fffc61e>
  76:	2e31                	jal	392 <offset+0x27a>
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
  94:	10090503          	lb	a0,256(s2)
  98:	0100                	addi	s0,sp,128
  9a:	10090503          	lb	a0,256(s2)
  9e:	0100                	addi	s0,sp,128
  a0:	18090503          	lb	a0,384(s2)
  a4:	0100                	addi	s0,sp,128
  a6:	14090503          	lb	a0,320(s2)
  aa:	0100                	addi	s0,sp,128
  ac:	10090503          	lb	a0,256(s2)
  b0:	0100                	addi	s0,sp,128
  b2:	10090503          	lb	a0,256(s2)
  b6:	0100                	addi	s0,sp,128
  b8:	14090503          	lb	a0,320(s2)
  bc:	0100                	addi	s0,sp,128
  be:	10090503          	lb	a0,256(s2)
  c2:	0100                	addi	s0,sp,128
  c4:	10090503          	lb	a0,256(s2)
  c8:	0100                	addi	s0,sp,128
  ca:	10090503          	lb	a0,256(s2)
  ce:	0100                	addi	s0,sp,128
  d0:	10090503          	lb	a0,256(s2)
  d4:	0100                	addi	s0,sp,128
  d6:	10090503          	lb	a0,256(s2)
  da:	0100                	addi	s0,sp,128
  dc:	10090503          	lb	a0,256(s2)
  e0:	0100                	addi	s0,sp,128
  e2:	10090503          	lb	a0,256(s2)
  e6:	0100                	addi	s0,sp,128
  e8:	10090503          	lb	a0,256(s2)
  ec:	0100                	addi	s0,sp,128
  ee:	10090503          	lb	a0,256(s2)
  f2:	0100                	addi	s0,sp,128
  f4:	10090503          	lb	a0,256(s2)
  f8:	0100                	addi	s0,sp,128
  fa:	10090503          	lb	a0,256(s2)
  fe:	0100                	addi	s0,sp,128
 100:	14090503          	lb	a0,320(s2)
 104:	0100                	addi	s0,sp,128
 106:	10090103          	lb	sp,256(s2)
 10a:	0100                	addi	s0,sp,128
 10c:	08090503          	lb	a0,128(s2)
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
 142:	10090503          	lb	a0,256(s2)
 146:	0100                	addi	s0,sp,128
 148:	10090503          	lb	a0,256(s2)
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
 1ba:	14090503          	lb	a0,320(s2)
 1be:	0100                	addi	s0,sp,128
 1c0:	14090503          	lb	a0,320(s2)
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
 226:	10090503          	lb	a0,256(s2)
 22a:	0100                	addi	s0,sp,128
 22c:	10090503          	lb	a0,256(s2)
 230:	0100                	addi	s0,sp,128
 232:	14090503          	lb	a0,320(s2)
 236:	0100                	addi	s0,sp,128
 238:	14090503          	lb	a0,320(s2)
 23c:	0100                	addi	s0,sp,128
 23e:	14090503          	lb	a0,320(s2)
 242:	0100                	addi	s0,sp,128
 244:	10090503          	lb	a0,256(s2)
 248:	0100                	addi	s0,sp,128
 24a:	14090503          	lb	a0,320(s2)
 24e:	0100                	addi	s0,sp,128
 250:	14090503          	lb	a0,320(s2)
 254:	0100                	addi	s0,sp,128
 256:	14090503          	lb	a0,320(s2)
 25a:	0100                	addi	s0,sp,128
 25c:	14090503          	lb	a0,320(s2)
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
 298:	10090503          	lb	a0,256(s2)
 29c:	0100                	addi	s0,sp,128
 29e:	14090503          	lb	a0,320(s2)
 2a2:	0100                	addi	s0,sp,128
 2a4:	10090503          	lb	a0,256(s2)
 2a8:	0100                	addi	s0,sp,128
 2aa:	10090503          	lb	a0,256(s2)
 2ae:	0100                	addi	s0,sp,128
 2b0:	10090403          	lb	s0,256(s2)
 2b4:	0100                	addi	s0,sp,128
 2b6:	04090103          	lb	sp,64(s2)
 2ba:	0100                	addi	s0,sp,128
 2bc:	1009                	c.nop	-30
 2be:	0000                	unimp
 2c0:	0101                	addi	sp,sp,0

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
  14:	06dc                	addi	a5,sp,836
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
  14:	06dc                	addi	a5,sp,836
	...

Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	6d6f682f          	0x6d6f682f
   4:	2f65                	jal	7bc <offset+0x6a4>
   6:	6f6c                	flw	fa1,92(a4)
   8:	6976                	flw	fs2,92(sp)
   a:	65442f73          	csrrs	t5,0x654,s0
   e:	6f746b73          	csrrsi	s6,0x6f7,8
  12:	2f70                	fld	fa2,216(a4)
  14:	6952                	flw	fs2,20(sp)
  16:	6556                	flw	fa0,84(sp)
  18:	5f72                	lw	t5,60(sp)
  1a:	65726f63          	bltu	tp,s7,678 <offset+0x560>
  1e:	7369722f          	0x7369722f
  22:	2f666f63          	bltu	a2,s6,320 <offset+0x208>
  26:	6972                	flw	fs2,28(sp)
  28:	2d766373          	csrrsi	t1,0x2d7,12
  2c:	7261                	lui	tp,0xffff8
  2e:	742d6863          	bltu	s10,sp,77e <offset+0x666>
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
  54:	6172732f          	0x6172732f
  58:	302d                	jal	fffff882 <_end+0x7fffc602>
  5a:	2e31                	jal	376 <offset+0x25e>
  5c:	682f0053          	0x682f0053
  60:	2f656d6f          	jal	s10,56356 <offset+0x5623e>
  64:	6f6c                	flw	fa1,92(a4)
  66:	6976                	flw	fs2,92(sp)
  68:	65442f73          	csrrs	t5,0x654,s0
  6c:	6f746b73          	csrrsi	s6,0x6f7,8
  70:	2f70                	fld	fa2,216(a4)
  72:	6952                	flw	fs2,20(sp)
  74:	6556                	flw	fa0,84(sp)
  76:	5f72                	lw	t5,60(sp)
  78:	65726f63          	bltu	tp,s7,6d6 <offset+0x5be>
  7c:	7369722f          	0x7369722f
  80:	2f666f63          	bltu	a2,s6,37e <offset+0x266>
  84:	6972                	flw	fs2,28(sp)
  86:	666f6373          	csrrsi	t1,0x666,30
  8a:	775f 726f 2f6b      	0x2f6b726f775f
  90:	7672                	flw	fa2,60(sp)
  92:	5f693233          	0x5f693233
  96:	2f6d                	jal	850 <offset+0x738>
  98:	2f49                	jal	82a <offset+0x712>
  9a:	2f637273          	csrrci	tp,0x2f6,6
  9e:	2d617273          	csrrci	tp,0x2d6,2
  a2:	3130                	fld	fa2,96(a0)
  a4:	532e                	lw	t1,232(sp)
  a6:	7475642f          	0x7475642f
  aa:	4700                	lw	s0,8(a4)
  ac:	554e                	lw	a0,240(sp)
  ae:	4120                	lw	s0,64(a0)
  b0:	2e322053          	0x2e322053
  b4:	          	snez	a0,zero
