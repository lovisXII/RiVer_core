
my.elf:     file format elf32-littleriscv


Disassembly of section .text.init:

80000000 <rvtest_entry_point>:
80000000:	feedc0b7          	lui	ra,0xfeedc
80000004:	ead08093          	addi	ra,ra,-339 # feedbead <_end+0x7eed8c2d>
80000008:	ff76e137          	lui	sp,0xff76e
8000000c:	f5610113          	addi	sp,sp,-170 # ff76df56 <_end+0x7f76acd6>
80000010:	7fbb71b7          	lui	gp,0x7fbb7
80000014:	fab18193          	addi	gp,gp,-85 # 7fbb6fab <absimm+0x7fbaefab>
80000018:	bfddb237          	lui	tp,0xbfddb
8000001c:	7d520213          	addi	tp,tp,2005 # bfddb7d5 <_end+0x3fdd8555>
80000020:	00000297          	auipc	t0,0x0
80000024:	05828293          	addi	t0,t0,88 # 80000078 <rvtest_code_begin>
80000028:	00002317          	auipc	t1,0x2
8000002c:	fe830313          	addi	t1,t1,-24 # 80002010 <rvtest_data_begin>
80000030:	b7fbb3b7          	lui	t2,0xb7fbb
80000034:	6fa38393          	addi	t2,t2,1786 # b7fbb6fa <_end+0x37fb847a>
80000038:	5bfde437          	lui	s0,0x5bfde
8000003c:	b7d40413          	addi	s0,s0,-1155 # 5bfddb7d <absimm+0x5bfd5b7d>
80000040:	adfef4b7          	lui	s1,0xadfef
80000044:	dbe48493          	addi	s1,s1,-578 # adfeedbe <_end+0x2dfebb3e>
80000048:	56ff7537          	lui	a0,0x56ff7
8000004c:	6df50513          	addi	a0,a0,1759 # 56ff76df <absimm+0x56fef6df>
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
80000078:	00003217          	auipc	tp,0x3
8000007c:	09c20213          	addi	tp,tp,156 # 80003114 <signature_x4_0>

80000080 <inst_0>:
80000080:	ff700f93          	li	t6,-9
80000084:	409fdc93          	srai	s9,t6,0x9
80000088:	01922023          	sw	s9,0(tp) # 0 <cry>

8000008c <inst_1>:
8000008c:	00500513          	li	a0,5
80000090:	40155513          	srai	a0,a0,0x1
80000094:	00a22223          	sw	a0,4(tp) # 4 <MMODE_SIG+0x1>

80000098 <inst_2>:
80000098:	ff000437          	lui	s0,0xff000
8000009c:	fff40413          	addi	s0,s0,-1 # feffffff <_end+0x7effcd7f>
800000a0:	40045e13          	srai	t3,s0,0x0
800000a4:	01c22423          	sw	t3,8(tp) # 8 <MMODE_SIG+0x5>

800000a8 <inst_3>:
800000a8:	001008b7          	lui	a7,0x100
800000ac:	4008d293          	srai	t0,a7,0x0
800000b0:	00522623          	sw	t0,12(tp) # c <MMODE_SIG+0x9>

800000b4 <inst_4>:
800000b4:	fffe0bb7          	lui	s7,0xfffe0
800000b8:	fffb8b93          	addi	s7,s7,-1 # fffdffff <_end+0x7ffdcd7f>
800000bc:	41fbdd93          	srai	s11,s7,0x1f
800000c0:	01b22823          	sw	s11,16(tp) # 10 <edge2>

800000c4 <inst_5>:
800000c4:	00100693          	li	a3,1
800000c8:	41f6da13          	srai	s4,a3,0x1f
800000cc:	01422a23          	sw	s4,20(tp) # 14 <edge2+0x4>

800000d0 <inst_6>:
800000d0:	00400b13          	li	s6,4
800000d4:	404b5593          	srai	a1,s6,0x4
800000d8:	00b22c23          	sw	a1,24(tp) # 18 <edge2+0x8>

800000dc <inst_7>:
800000dc:	800003b7          	lui	t2,0x80000
800000e0:	4003df13          	srai	t5,t2,0x0
800000e4:	01e22e23          	sw	t5,28(tp) # 1c <edge2+0xc>

800000e8 <inst_8>:
800000e8:	00000913          	li	s2,0
800000ec:	40e95713          	srai	a4,s2,0xe
800000f0:	02e22023          	sw	a4,32(tp) # 20 <pos>

800000f4 <inst_9>:
800000f4:	800001b7          	lui	gp,0x80000
800000f8:	fff18193          	addi	gp,gp,-1 # 7fffffff <_end+0xffffcd7f>
800000fc:	41f1d993          	srai	s3,gp,0x1f
80000100:	03322223          	sw	s3,36(tp) # 24 <pos+0x4>

80000104 <inst_10>:
80000104:	00200c93          	li	s9,2
80000108:	411cde93          	srai	t4,s9,0x11
8000010c:	03d22423          	sw	t4,40(tp) # 28 <pos+0x8>

80000110 <inst_11>:
80000110:	00800f13          	li	t5,8
80000114:	411f5193          	srai	gp,t5,0x11
80000118:	02322623          	sw	gp,44(tp) # 2c <pos+0xc>

8000011c <inst_12>:
8000011c:	01000113          	li	sp,16
80000120:	41215b13          	srai	s6,sp,0x12
80000124:	03622823          	sw	s6,48(tp) # 30 <pos+0x10>

80000128 <inst_13>:
80000128:	02000613          	li	a2,32
8000012c:	40d65113          	srai	sp,a2,0xd
80000130:	02222a23          	sw	sp,52(tp) # 34 <pos+0x14>

80000134 <inst_14>:
80000134:	04000093          	li	ra,64
80000138:	4170d613          	srai	a2,ra,0x17
8000013c:	02c22c23          	sw	a2,56(tp) # 38 <pos+0x18>

80000140 <inst_15>:
80000140:	08000a13          	li	s4,128
80000144:	409a5c13          	srai	s8,s4,0x9
80000148:	03822e23          	sw	s8,60(tp) # 3c <pos+0x1c>

8000014c <inst_16>:
8000014c:	10000593          	li	a1,256
80000150:	4105d013          	srai	zero,a1,0x10
80000154:	04022023          	sw	zero,64(tp) # 40 <pos+0x20>

80000158 <inst_17>:
80000158:	20000d13          	li	s10,512
8000015c:	409d5413          	srai	s0,s10,0x9
80000160:	04822223          	sw	s0,68(tp) # 44 <pos+0x24>

80000164 <inst_18>:
80000164:	40000493          	li	s1,1024
80000168:	4114d893          	srai	a7,s1,0x11
8000016c:	05122423          	sw	a7,72(tp) # 48 <pos+0x28>

80000170 <inst_19>:
80000170:	00001837          	lui	a6,0x1
80000174:	80080813          	addi	a6,a6,-2048 # 800 <offset+0x6fc>
80000178:	41b85b93          	srai	s7,a6,0x1b
8000017c:	05722623          	sw	s7,76(tp) # 4c <pos+0x2c>

80000180 <inst_20>:
80000180:	00001737          	lui	a4,0x1
80000184:	40575693          	srai	a3,a4,0x5
80000188:	04d22823          	sw	a3,80(tp) # 50 <pos+0x30>

8000018c <inst_21>:
8000018c:	00002ab7          	lui	s5,0x2
80000190:	401ad393          	srai	t2,s5,0x1
80000194:	04722a23          	sw	t2,84(tp) # 54 <pos+0x34>
80000198:	00003117          	auipc	sp,0x3
8000019c:	fd410113          	addi	sp,sp,-44 # 8000316c <signature_x2_0>

800001a0 <inst_22>:
800001a0:	000042b7          	lui	t0,0x4
800001a4:	4052d913          	srai	s2,t0,0x5
800001a8:	01212023          	sw	s2,0(sp)

800001ac <inst_23>:
800001ac:	00000013          	nop
800001b0:	41105d13          	srai	s10,zero,0x11
800001b4:	01a12223          	sw	s10,4(sp)

800001b8 <inst_24>:
800001b8:	00010c37          	lui	s8,0x10
800001bc:	40dc5213          	srai	tp,s8,0xd
800001c0:	00412423          	sw	tp,8(sp)

800001c4 <inst_25>:
800001c4:	000207b7          	lui	a5,0x20
800001c8:	4127d493          	srai	s1,a5,0x12
800001cc:	00912623          	sw	s1,12(sp)

800001d0 <inst_26>:
800001d0:	000409b7          	lui	s3,0x40
800001d4:	41f9d313          	srai	t1,s3,0x1f
800001d8:	00612823          	sw	t1,16(sp)

800001dc <inst_27>:
800001dc:	00080e37          	lui	t3,0x80
800001e0:	415e5a93          	srai	s5,t3,0x15
800001e4:	01512a23          	sw	s5,20(sp)

800001e8 <inst_28>:
800001e8:	00200db7          	lui	s11,0x200
800001ec:	417ddf93          	srai	t6,s11,0x17
800001f0:	01f12c23          	sw	t6,24(sp)

800001f4 <inst_29>:
800001f4:	00400337          	lui	t1,0x400
800001f8:	41235093          	srai	ra,t1,0x12
800001fc:	00112e23          	sw	ra,28(sp)

80000200 <inst_30>:
80000200:	00800237          	lui	tp,0x800
80000204:	40b25793          	srai	a5,tp,0xb
80000208:	02f12023          	sw	a5,32(sp)

8000020c <inst_31>:
8000020c:	01000eb7          	lui	t4,0x1000
80000210:	41fed813          	srai	a6,t4,0x1f
80000214:	03012223          	sw	a6,36(sp)

80000218 <inst_32>:
80000218:	02000537          	lui	a0,0x2000
8000021c:	40055593          	srai	a1,a0,0x0
80000220:	02b12423          	sw	a1,40(sp)

80000224 <inst_33>:
80000224:	04000537          	lui	a0,0x4000
80000228:	40655593          	srai	a1,a0,0x6
8000022c:	02b12623          	sw	a1,44(sp)

80000230 <inst_34>:
80000230:	08000537          	lui	a0,0x8000
80000234:	40755593          	srai	a1,a0,0x7
80000238:	02b12823          	sw	a1,48(sp)

8000023c <inst_35>:
8000023c:	10000537          	lui	a0,0x10000
80000240:	40055593          	srai	a1,a0,0x0
80000244:	02b12a23          	sw	a1,52(sp)

80000248 <inst_36>:
80000248:	20000537          	lui	a0,0x20000
8000024c:	40c55593          	srai	a1,a0,0xc
80000250:	02b12c23          	sw	a1,56(sp)

80000254 <inst_37>:
80000254:	40000537          	lui	a0,0x40000
80000258:	40855593          	srai	a1,a0,0x8
8000025c:	02b12e23          	sw	a1,60(sp)

80000260 <inst_38>:
80000260:	ffe00513          	li	a0,-2
80000264:	40155593          	srai	a1,a0,0x1
80000268:	04b12023          	sw	a1,64(sp)

8000026c <inst_39>:
8000026c:	ffd00513          	li	a0,-3
80000270:	41055593          	srai	a1,a0,0x10
80000274:	04b12223          	sw	a1,68(sp)

80000278 <inst_40>:
80000278:	ffb00513          	li	a0,-5
8000027c:	41255593          	srai	a1,a0,0x12
80000280:	04b12423          	sw	a1,72(sp)

80000284 <inst_41>:
80000284:	fef00513          	li	a0,-17
80000288:	40055593          	srai	a1,a0,0x0
8000028c:	04b12623          	sw	a1,76(sp)

80000290 <inst_42>:
80000290:	fdf00513          	li	a0,-33
80000294:	40855593          	srai	a1,a0,0x8
80000298:	04b12823          	sw	a1,80(sp)

8000029c <inst_43>:
8000029c:	fbf00513          	li	a0,-65
800002a0:	40455593          	srai	a1,a0,0x4
800002a4:	04b12a23          	sw	a1,84(sp)

800002a8 <inst_44>:
800002a8:	f7f00513          	li	a0,-129
800002ac:	40f55593          	srai	a1,a0,0xf
800002b0:	04b12c23          	sw	a1,88(sp)

800002b4 <inst_45>:
800002b4:	eff00513          	li	a0,-257
800002b8:	40b55593          	srai	a1,a0,0xb
800002bc:	04b12e23          	sw	a1,92(sp)

800002c0 <inst_46>:
800002c0:	dff00513          	li	a0,-513
800002c4:	40d55593          	srai	a1,a0,0xd
800002c8:	06b12023          	sw	a1,96(sp)

800002cc <inst_47>:
800002cc:	bff00513          	li	a0,-1025
800002d0:	41e55593          	srai	a1,a0,0x1e
800002d4:	06b12223          	sw	a1,100(sp)

800002d8 <inst_48>:
800002d8:	fffff537          	lui	a0,0xfffff
800002dc:	7ff50513          	addi	a0,a0,2047 # fffff7ff <_end+0x7fffc57f>
800002e0:	40d55593          	srai	a1,a0,0xd
800002e4:	06b12423          	sw	a1,104(sp)

800002e8 <inst_49>:
800002e8:	fffff537          	lui	a0,0xfffff
800002ec:	fff50513          	addi	a0,a0,-1 # ffffefff <_end+0x7fffbd7f>
800002f0:	40f55593          	srai	a1,a0,0xf
800002f4:	06b12623          	sw	a1,108(sp)

800002f8 <inst_50>:
800002f8:	ffffe537          	lui	a0,0xffffe
800002fc:	fff50513          	addi	a0,a0,-1 # ffffdfff <_end+0x7fffad7f>
80000300:	41d55593          	srai	a1,a0,0x1d
80000304:	06b12823          	sw	a1,112(sp)

80000308 <inst_51>:
80000308:	ffffc537          	lui	a0,0xffffc
8000030c:	fff50513          	addi	a0,a0,-1 # ffffbfff <_end+0x7fff8d7f>
80000310:	40355593          	srai	a1,a0,0x3
80000314:	06b12a23          	sw	a1,116(sp)

80000318 <inst_52>:
80000318:	ffff8537          	lui	a0,0xffff8
8000031c:	fff50513          	addi	a0,a0,-1 # ffff7fff <_end+0x7fff4d7f>
80000320:	40055593          	srai	a1,a0,0x0
80000324:	06b12c23          	sw	a1,120(sp)

80000328 <inst_53>:
80000328:	ffff0537          	lui	a0,0xffff0
8000032c:	fff50513          	addi	a0,a0,-1 # fffeffff <_end+0x7ffecd7f>
80000330:	40d55593          	srai	a1,a0,0xd
80000334:	06b12e23          	sw	a1,124(sp)

80000338 <inst_54>:
80000338:	fffc0537          	lui	a0,0xfffc0
8000033c:	fff50513          	addi	a0,a0,-1 # fffbffff <_end+0x7ffbcd7f>
80000340:	41155593          	srai	a1,a0,0x11
80000344:	08b12023          	sw	a1,128(sp)

80000348 <inst_55>:
80000348:	fff80537          	lui	a0,0xfff80
8000034c:	fff50513          	addi	a0,a0,-1 # fff7ffff <_end+0x7ff7cd7f>
80000350:	40955593          	srai	a1,a0,0x9
80000354:	08b12223          	sw	a1,132(sp)

80000358 <inst_56>:
80000358:	fff00537          	lui	a0,0xfff00
8000035c:	fff50513          	addi	a0,a0,-1 # ffefffff <_end+0x7fefcd7f>
80000360:	40155593          	srai	a1,a0,0x1
80000364:	08b12423          	sw	a1,136(sp)

80000368 <inst_57>:
80000368:	ffe00537          	lui	a0,0xffe00
8000036c:	fff50513          	addi	a0,a0,-1 # ffdfffff <_end+0x7fdfcd7f>
80000370:	41155593          	srai	a1,a0,0x11
80000374:	08b12623          	sw	a1,140(sp)

80000378 <inst_58>:
80000378:	ffc00537          	lui	a0,0xffc00
8000037c:	fff50513          	addi	a0,a0,-1 # ffbfffff <_end+0x7fbfcd7f>
80000380:	41155593          	srai	a1,a0,0x11
80000384:	08b12823          	sw	a1,144(sp)

80000388 <inst_59>:
80000388:	ff800537          	lui	a0,0xff800
8000038c:	fff50513          	addi	a0,a0,-1 # ff7fffff <_end+0x7f7fcd7f>
80000390:	40e55593          	srai	a1,a0,0xe
80000394:	08b12a23          	sw	a1,148(sp)

80000398 <inst_60>:
80000398:	fe000537          	lui	a0,0xfe000
8000039c:	fff50513          	addi	a0,a0,-1 # fdffffff <_end+0x7dffcd7f>
800003a0:	40455593          	srai	a1,a0,0x4
800003a4:	08b12c23          	sw	a1,152(sp)

800003a8 <inst_61>:
800003a8:	fc000537          	lui	a0,0xfc000
800003ac:	fff50513          	addi	a0,a0,-1 # fbffffff <_end+0x7bffcd7f>
800003b0:	41255593          	srai	a1,a0,0x12
800003b4:	08b12e23          	sw	a1,156(sp)

800003b8 <inst_62>:
800003b8:	f8000537          	lui	a0,0xf8000
800003bc:	fff50513          	addi	a0,a0,-1 # f7ffffff <_end+0x77ffcd7f>
800003c0:	40d55593          	srai	a1,a0,0xd
800003c4:	0ab12023          	sw	a1,160(sp)

800003c8 <inst_63>:
800003c8:	f0000537          	lui	a0,0xf0000
800003cc:	fff50513          	addi	a0,a0,-1 # efffffff <_end+0x6fffcd7f>
800003d0:	40355593          	srai	a1,a0,0x3
800003d4:	0ab12223          	sw	a1,164(sp)

800003d8 <inst_64>:
800003d8:	e0000537          	lui	a0,0xe0000
800003dc:	fff50513          	addi	a0,a0,-1 # dfffffff <_end+0x5fffcd7f>
800003e0:	40755593          	srai	a1,a0,0x7
800003e4:	0ab12423          	sw	a1,168(sp)

800003e8 <inst_65>:
800003e8:	c0000537          	lui	a0,0xc0000
800003ec:	fff50513          	addi	a0,a0,-1 # bfffffff <_end+0x3fffcd7f>
800003f0:	41355593          	srai	a1,a0,0x13
800003f4:	0ab12623          	sw	a1,172(sp)

800003f8 <inst_66>:
800003f8:	55555537          	lui	a0,0x55555
800003fc:	55550513          	addi	a0,a0,1365 # 55555555 <absimm+0x5554d555>
80000400:	41555593          	srai	a1,a0,0x15
80000404:	0ab12823          	sw	a1,176(sp)

80000408 <inst_67>:
80000408:	aaaab537          	lui	a0,0xaaaab
8000040c:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <_end+0x2aaa782a>
80000410:	40f55593          	srai	a1,a0,0xf
80000414:	0ab12a23          	sw	a1,180(sp)

80000418 <inst_68>:
80000418:	00300513          	li	a0,3
8000041c:	40a55593          	srai	a1,a0,0xa
80000420:	0ab12c23          	sw	a1,184(sp)

80000424 <inst_69>:
80000424:	33333537          	lui	a0,0x33333
80000428:	33350513          	addi	a0,a0,819 # 33333333 <absimm+0x3332b333>
8000042c:	40055593          	srai	a1,a0,0x0
80000430:	0ab12e23          	sw	a1,188(sp)

80000434 <inst_70>:
80000434:	66666537          	lui	a0,0x66666
80000438:	66750513          	addi	a0,a0,1639 # 66666667 <absimm+0x6665e667>
8000043c:	40a55593          	srai	a1,a0,0xa
80000440:	0cb12023          	sw	a1,192(sp)

80000444 <inst_71>:
80000444:	ffff5537          	lui	a0,0xffff5
80000448:	afd50513          	addi	a0,a0,-1283 # ffff4afd <_end+0x7fff187d>
8000044c:	40155593          	srai	a1,a0,0x1
80000450:	0cb12223          	sw	a1,196(sp)

80000454 <inst_72>:
80000454:	0000b537          	lui	a0,0xb
80000458:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x3505>
8000045c:	40055593          	srai	a1,a0,0x0
80000460:	0cb12423          	sw	a1,200(sp)

80000464 <inst_73>:
80000464:	55555537          	lui	a0,0x55555
80000468:	55550513          	addi	a0,a0,1365 # 55555555 <absimm+0x5554d555>
8000046c:	40255593          	srai	a1,a0,0x2
80000470:	0cb12623          	sw	a1,204(sp)

80000474 <inst_74>:
80000474:	66666537          	lui	a0,0x66666
80000478:	66650513          	addi	a0,a0,1638 # 66666666 <absimm+0x6665e666>
8000047c:	41b55593          	srai	a1,a0,0x1b
80000480:	0cb12823          	sw	a1,208(sp)

80000484 <inst_75>:
80000484:	ffff5537          	lui	a0,0xffff5
80000488:	afc50513          	addi	a0,a0,-1284 # ffff4afc <_end+0x7fff187c>
8000048c:	40c55593          	srai	a1,a0,0xc
80000490:	0cb12a23          	sw	a1,212(sp)

80000494 <inst_76>:
80000494:	0000b537          	lui	a0,0xb
80000498:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x3504>
8000049c:	40055593          	srai	a1,a0,0x0
800004a0:	0cb12c23          	sw	a1,216(sp)

800004a4 <inst_77>:
800004a4:	55555537          	lui	a0,0x55555
800004a8:	55450513          	addi	a0,a0,1364 # 55555554 <absimm+0x5554d554>
800004ac:	40655593          	srai	a1,a0,0x6
800004b0:	0cb12e23          	sw	a1,220(sp)

800004b4 <inst_78>:
800004b4:	33333537          	lui	a0,0x33333
800004b8:	33250513          	addi	a0,a0,818 # 33333332 <absimm+0x3332b332>
800004bc:	41e55593          	srai	a1,a0,0x1e
800004c0:	0eb12023          	sw	a1,224(sp)

800004c4 <inst_79>:
800004c4:	66666537          	lui	a0,0x66666
800004c8:	66550513          	addi	a0,a0,1637 # 66666665 <absimm+0x6665e665>
800004cc:	41f55593          	srai	a1,a0,0x1f
800004d0:	0eb12223          	sw	a1,228(sp)

800004d4 <inst_80>:
800004d4:	0000b537          	lui	a0,0xb
800004d8:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x3503>
800004dc:	41755593          	srai	a1,a0,0x17
800004e0:	0eb12423          	sw	a1,232(sp)

800004e4 <inst_81>:
800004e4:	55555537          	lui	a0,0x55555
800004e8:	55650513          	addi	a0,a0,1366 # 55555556 <absimm+0x5554d556>
800004ec:	41b55593          	srai	a1,a0,0x1b
800004f0:	0eb12623          	sw	a1,236(sp)

800004f4 <inst_82>:
800004f4:	aaaab537          	lui	a0,0xaaaab
800004f8:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <_end+0x2aaa782b>
800004fc:	40a55593          	srai	a1,a0,0xa
80000500:	0eb12823          	sw	a1,240(sp)

80000504 <inst_83>:
80000504:	00600513          	li	a0,6
80000508:	40655593          	srai	a1,a0,0x6
8000050c:	0eb12a23          	sw	a1,244(sp)

80000510 <inst_84>:
80000510:	33333537          	lui	a0,0x33333
80000514:	33450513          	addi	a0,a0,820 # 33333334 <absimm+0x3332b334>
80000518:	40c55593          	srai	a1,a0,0xc
8000051c:	0eb12c23          	sw	a1,248(sp)

80000520 <inst_85>:
80000520:	10000513          	li	a0,256
80000524:	41055593          	srai	a1,a0,0x10
80000528:	0eb12e23          	sw	a1,252(sp)

8000052c <inst_86>:
8000052c:	00008537          	lui	a0,0x8
80000530:	41155593          	srai	a1,a0,0x11
80000534:	10b12023          	sw	a1,256(sp)

80000538 <cleanup_epilogs>:
80000538:	0040006f          	j	8000053c <exit_cleanup>

8000053c <exit_cleanup>:
8000053c:	00100093          	li	ra,1

80000540 <write_tohost>:
80000540:	00001f17          	auipc	t5,0x1
80000544:	ac1f2023          	sw	ra,-1344(t5) # 80001000 <tohost>
80000548:	ff9ff06f          	j	80000540 <write_tohost>
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
80002020:	deadbeef          	jal	t4,7ffdd60a <absimm+0x7ffd560a>
80002024:	deadbeef          	jal	t4,7ffdd60e <absimm+0x7ffd560e>

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

80003114 <signature_x4_0>:
80003114:	deadbeef          	jal	t4,7ffde6fe <absimm+0x7ffd66fe>
80003118:	deadbeef          	jal	t4,7ffde702 <absimm+0x7ffd6702>
8000311c:	deadbeef          	jal	t4,7ffde706 <absimm+0x7ffd6706>
80003120:	deadbeef          	jal	t4,7ffde70a <absimm+0x7ffd670a>
80003124:	deadbeef          	jal	t4,7ffde70e <absimm+0x7ffd670e>
80003128:	deadbeef          	jal	t4,7ffde712 <absimm+0x7ffd6712>
8000312c:	deadbeef          	jal	t4,7ffde716 <absimm+0x7ffd6716>
80003130:	deadbeef          	jal	t4,7ffde71a <absimm+0x7ffd671a>
80003134:	deadbeef          	jal	t4,7ffde71e <absimm+0x7ffd671e>
80003138:	deadbeef          	jal	t4,7ffde722 <absimm+0x7ffd6722>
8000313c:	deadbeef          	jal	t4,7ffde726 <absimm+0x7ffd6726>
80003140:	deadbeef          	jal	t4,7ffde72a <absimm+0x7ffd672a>
80003144:	deadbeef          	jal	t4,7ffde72e <absimm+0x7ffd672e>
80003148:	deadbeef          	jal	t4,7ffde732 <absimm+0x7ffd6732>
8000314c:	deadbeef          	jal	t4,7ffde736 <absimm+0x7ffd6736>
80003150:	deadbeef          	jal	t4,7ffde73a <absimm+0x7ffd673a>
80003154:	deadbeef          	jal	t4,7ffde73e <absimm+0x7ffd673e>
80003158:	deadbeef          	jal	t4,7ffde742 <absimm+0x7ffd6742>
8000315c:	deadbeef          	jal	t4,7ffde746 <absimm+0x7ffd6746>
80003160:	deadbeef          	jal	t4,7ffde74a <absimm+0x7ffd674a>
80003164:	deadbeef          	jal	t4,7ffde74e <absimm+0x7ffd674e>
80003168:	deadbeef          	jal	t4,7ffde752 <absimm+0x7ffd6752>

8000316c <signature_x2_0>:
8000316c:	deadbeef          	jal	t4,7ffde756 <absimm+0x7ffd6756>
80003170:	deadbeef          	jal	t4,7ffde75a <absimm+0x7ffd675a>
80003174:	deadbeef          	jal	t4,7ffde75e <absimm+0x7ffd675e>
80003178:	deadbeef          	jal	t4,7ffde762 <absimm+0x7ffd6762>
8000317c:	deadbeef          	jal	t4,7ffde766 <absimm+0x7ffd6766>
80003180:	deadbeef          	jal	t4,7ffde76a <absimm+0x7ffd676a>
80003184:	deadbeef          	jal	t4,7ffde76e <absimm+0x7ffd676e>
80003188:	deadbeef          	jal	t4,7ffde772 <absimm+0x7ffd6772>
8000318c:	deadbeef          	jal	t4,7ffde776 <absimm+0x7ffd6776>
80003190:	deadbeef          	jal	t4,7ffde77a <absimm+0x7ffd677a>
80003194:	deadbeef          	jal	t4,7ffde77e <absimm+0x7ffd677e>
80003198:	deadbeef          	jal	t4,7ffde782 <absimm+0x7ffd6782>
8000319c:	deadbeef          	jal	t4,7ffde786 <absimm+0x7ffd6786>
800031a0:	deadbeef          	jal	t4,7ffde78a <absimm+0x7ffd678a>
800031a4:	deadbeef          	jal	t4,7ffde78e <absimm+0x7ffd678e>
800031a8:	deadbeef          	jal	t4,7ffde792 <absimm+0x7ffd6792>
800031ac:	deadbeef          	jal	t4,7ffde796 <absimm+0x7ffd6796>
800031b0:	deadbeef          	jal	t4,7ffde79a <absimm+0x7ffd679a>
800031b4:	deadbeef          	jal	t4,7ffde79e <absimm+0x7ffd679e>
800031b8:	deadbeef          	jal	t4,7ffde7a2 <absimm+0x7ffd67a2>
800031bc:	deadbeef          	jal	t4,7ffde7a6 <absimm+0x7ffd67a6>
800031c0:	deadbeef          	jal	t4,7ffde7aa <absimm+0x7ffd67aa>
800031c4:	deadbeef          	jal	t4,7ffde7ae <absimm+0x7ffd67ae>
800031c8:	deadbeef          	jal	t4,7ffde7b2 <absimm+0x7ffd67b2>
800031cc:	deadbeef          	jal	t4,7ffde7b6 <absimm+0x7ffd67b6>
800031d0:	deadbeef          	jal	t4,7ffde7ba <absimm+0x7ffd67ba>
800031d4:	deadbeef          	jal	t4,7ffde7be <absimm+0x7ffd67be>
800031d8:	deadbeef          	jal	t4,7ffde7c2 <absimm+0x7ffd67c2>
800031dc:	deadbeef          	jal	t4,7ffde7c6 <absimm+0x7ffd67c6>
800031e0:	deadbeef          	jal	t4,7ffde7ca <absimm+0x7ffd67ca>
800031e4:	deadbeef          	jal	t4,7ffde7ce <absimm+0x7ffd67ce>
800031e8:	deadbeef          	jal	t4,7ffde7d2 <absimm+0x7ffd67d2>
800031ec:	deadbeef          	jal	t4,7ffde7d6 <absimm+0x7ffd67d6>
800031f0:	deadbeef          	jal	t4,7ffde7da <absimm+0x7ffd67da>
800031f4:	deadbeef          	jal	t4,7ffde7de <absimm+0x7ffd67de>
800031f8:	deadbeef          	jal	t4,7ffde7e2 <absimm+0x7ffd67e2>
800031fc:	deadbeef          	jal	t4,7ffde7e6 <absimm+0x7ffd67e6>
80003200:	deadbeef          	jal	t4,7ffde7ea <absimm+0x7ffd67ea>
80003204:	deadbeef          	jal	t4,7ffde7ee <absimm+0x7ffd67ee>
80003208:	deadbeef          	jal	t4,7ffde7f2 <absimm+0x7ffd67f2>
8000320c:	deadbeef          	jal	t4,7ffde7f6 <absimm+0x7ffd67f6>
80003210:	deadbeef          	jal	t4,7ffde7fa <absimm+0x7ffd67fa>
80003214:	deadbeef          	jal	t4,7ffde7fe <absimm+0x7ffd67fe>
80003218:	deadbeef          	jal	t4,7ffde802 <absimm+0x7ffd6802>
8000321c:	deadbeef          	jal	t4,7ffde806 <absimm+0x7ffd6806>
80003220:	deadbeef          	jal	t4,7ffde80a <absimm+0x7ffd680a>
80003224:	deadbeef          	jal	t4,7ffde80e <absimm+0x7ffd680e>
80003228:	deadbeef          	jal	t4,7ffde812 <absimm+0x7ffd6812>
8000322c:	deadbeef          	jal	t4,7ffde816 <absimm+0x7ffd6816>
80003230:	deadbeef          	jal	t4,7ffde81a <absimm+0x7ffd681a>
80003234:	deadbeef          	jal	t4,7ffde81e <absimm+0x7ffd681e>
80003238:	deadbeef          	jal	t4,7ffde822 <absimm+0x7ffd6822>
8000323c:	deadbeef          	jal	t4,7ffde826 <absimm+0x7ffd6826>
80003240:	deadbeef          	jal	t4,7ffde82a <absimm+0x7ffd682a>
80003244:	deadbeef          	jal	t4,7ffde82e <absimm+0x7ffd682e>
80003248:	deadbeef          	jal	t4,7ffde832 <absimm+0x7ffd6832>
8000324c:	deadbeef          	jal	t4,7ffde836 <absimm+0x7ffd6836>
80003250:	deadbeef          	jal	t4,7ffde83a <absimm+0x7ffd683a>
80003254:	deadbeef          	jal	t4,7ffde83e <absimm+0x7ffd683e>
80003258:	deadbeef          	jal	t4,7ffde842 <absimm+0x7ffd6842>
8000325c:	deadbeef          	jal	t4,7ffde846 <absimm+0x7ffd6846>
80003260:	deadbeef          	jal	t4,7ffde84a <absimm+0x7ffd684a>
80003264:	deadbeef          	jal	t4,7ffde84e <absimm+0x7ffd684e>
80003268:	deadbeef          	jal	t4,7ffde852 <absimm+0x7ffd6852>
8000326c:	deadbeef          	jal	t4,7ffde856 <absimm+0x7ffd6856>

80003270 <sig_end_canary>:
80003270:	a309                	j	80003772 <_end+0x4f2>
80003272:	6f5c                	flw	fa5,28(a4)

80003274 <rvtest_sig_end>:
	...

Disassembly of section .riscv.attributes:

00000000 <.riscv.attributes>:
   0:	1941                	addi	s2,s2,-16
   2:	0000                	unimp
   4:	7200                	flw	fs0,32(a2)
   6:	7369                	lui	t1,0xffffa
   8:	01007663          	bgeu	zero,a6,14 <edge2+0x4>
   c:	0000000f          	fence	unknown,unknown
  10:	7205                	lui	tp,0xfffe1
  12:	3376                	fld	ft6,376(sp)
  14:	6932                	flw	fs2,12(sp)
  16:	7032                	flw	ft0,44(sp)
  18:	0030                	addi	a2,sp,8

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	02ad                	addi	t0,t0,11
   2:	0000                	unimp
   4:	00750003          	lb	zero,7(a0) # 8007 <absimm+0x7>
   8:	0000                	unimp
   a:	0101                	addi	sp,sp,0
   c:	000d0efb          	0xd0efb
  10:	0101                	addi	sp,sp,0
  12:	0101                	addi	sp,sp,0
  14:	0000                	unimp
  16:	0100                	addi	s0,sp,128
  18:	0000                	unimp
  1a:	2f01                	jal	72a <offset+0x626>
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
  44:	612d7663          	bgeu	s10,s2,650 <offset+0x54c>
  48:	6372                	flw	ft6,28(sp)
  4a:	2d68                	fld	fa0,216(a0)
  4c:	6574                	flw	fa3,76(a0)
  4e:	722f7473          	csrrci	s0,0x722,30
  52:	7369                	lui	t1,0xffffa
  54:	742d7663          	bgeu	s10,sp,7a0 <offset+0x69c>
  58:	7365                	lui	t1,0xffff9
  5a:	2d74                	fld	fa3,216(a0)
  5c:	74697573          	csrrci	a0,0x746,18
  60:	2f65                	jal	818 <offset+0x714>
  62:	7672                	flw	fa2,60(sp)
  64:	5f693233          	0x5f693233
  68:	2f6d                	jal	822 <offset+0x71e>
  6a:	2f49                	jal	7fc <offset+0x6f8>
  6c:	00637273          	csrrci	tp,0x6,6
  70:	7300                	flw	fs0,32(a4)
  72:	6172                	flw	ft2,28(sp)
  74:	2d69                	jal	70e <offset+0x60a>
  76:	3130                	fld	fa2,96(a0)
  78:	532e                	lw	t1,232(sp)
  7a:	0100                	addi	s0,sp,128
  7c:	0000                	unimp
  7e:	0000                	unimp
  80:	0205                	addi	tp,tp,1
  82:	0000                	unimp
  84:	8000                	0x8000
  86:	03011903          	lh	s2,48(sp)
  8a:	0906                	slli	s2,s2,0x1
  8c:	0078                	addi	a4,sp,12
  8e:	0301                	addi	t1,t1,0
  90:	0905                	addi	s2,s2,1
  92:	0008                	0x8
  94:	0301                	addi	t1,t1,0
  96:	0905                	addi	s2,s2,1
  98:	000c                	0xc
  9a:	0301                	addi	t1,t1,0
  9c:	0905                	addi	s2,s2,1
  9e:	000c                	0xc
  a0:	0301                	addi	t1,t1,0
  a2:	0905                	addi	s2,s2,1
  a4:	0010                	0x10
  a6:	0301                	addi	t1,t1,0
  a8:	0905                	addi	s2,s2,1
  aa:	000c                	0xc
  ac:	0301                	addi	t1,t1,0
  ae:	0905                	addi	s2,s2,1
  b0:	0010                	0x10
  b2:	0301                	addi	t1,t1,0
  b4:	0905                	addi	s2,s2,1
  b6:	000c                	0xc
  b8:	0301                	addi	t1,t1,0
  ba:	0905                	addi	s2,s2,1
  bc:	000c                	0xc
  be:	0301                	addi	t1,t1,0
  c0:	0905                	addi	s2,s2,1
  c2:	000c                	0xc
  c4:	0301                	addi	t1,t1,0
  c6:	0905                	addi	s2,s2,1
  c8:	000c                	0xc
  ca:	0301                	addi	t1,t1,0
  cc:	0905                	addi	s2,s2,1
  ce:	0010                	0x10
  d0:	0301                	addi	t1,t1,0
  d2:	0905                	addi	s2,s2,1
  d4:	000c                	0xc
  d6:	0301                	addi	t1,t1,0
  d8:	0905                	addi	s2,s2,1
  da:	000c                	0xc
  dc:	0301                	addi	t1,t1,0
  de:	0905                	addi	s2,s2,1
  e0:	000c                	0xc
  e2:	0301                	addi	t1,t1,0
  e4:	0905                	addi	s2,s2,1
  e6:	000c                	0xc
  e8:	0301                	addi	t1,t1,0
  ea:	0905                	addi	s2,s2,1
  ec:	000c                	0xc
  ee:	0301                	addi	t1,t1,0
  f0:	0905                	addi	s2,s2,1
  f2:	000c                	0xc
  f4:	0301                	addi	t1,t1,0
  f6:	0905                	addi	s2,s2,1
  f8:	000c                	0xc
  fa:	0301                	addi	t1,t1,0
  fc:	0905                	addi	s2,s2,1
  fe:	000c                	0xc
 100:	0301                	addi	t1,t1,0
 102:	0905                	addi	s2,s2,1
 104:	000c                	0xc
 106:	0301                	addi	t1,t1,0
 108:	0905                	addi	s2,s2,1
 10a:	0010                	0x10
 10c:	0301                	addi	t1,t1,0
 10e:	0905                	addi	s2,s2,1
 110:	000c                	0xc
 112:	0301                	addi	t1,t1,0
 114:	0901                	addi	s2,s2,0
 116:	000c                	0xc
 118:	0301                	addi	t1,t1,0
 11a:	0905                	addi	s2,s2,1
 11c:	0008                	0x8
 11e:	0301                	addi	t1,t1,0
 120:	0905                	addi	s2,s2,1
 122:	000c                	0xc
 124:	0301                	addi	t1,t1,0
 126:	0905                	addi	s2,s2,1
 128:	000c                	0xc
 12a:	0301                	addi	t1,t1,0
 12c:	0905                	addi	s2,s2,1
 12e:	000c                	0xc
 130:	0301                	addi	t1,t1,0
 132:	0905                	addi	s2,s2,1
 134:	000c                	0xc
 136:	0301                	addi	t1,t1,0
 138:	0905                	addi	s2,s2,1
 13a:	000c                	0xc
 13c:	0301                	addi	t1,t1,0
 13e:	0905                	addi	s2,s2,1
 140:	000c                	0xc
 142:	0301                	addi	t1,t1,0
 144:	0905                	addi	s2,s2,1
 146:	000c                	0xc
 148:	0301                	addi	t1,t1,0
 14a:	0905                	addi	s2,s2,1
 14c:	000c                	0xc
 14e:	0301                	addi	t1,t1,0
 150:	0905                	addi	s2,s2,1
 152:	000c                	0xc
 154:	0301                	addi	t1,t1,0
 156:	0905                	addi	s2,s2,1
 158:	000c                	0xc
 15a:	0301                	addi	t1,t1,0
 15c:	0905                	addi	s2,s2,1
 15e:	000c                	0xc
 160:	0301                	addi	t1,t1,0
 162:	0905                	addi	s2,s2,1
 164:	000c                	0xc
 166:	0301                	addi	t1,t1,0
 168:	0905                	addi	s2,s2,1
 16a:	000c                	0xc
 16c:	0301                	addi	t1,t1,0
 16e:	0905                	addi	s2,s2,1
 170:	000c                	0xc
 172:	0301                	addi	t1,t1,0
 174:	0905                	addi	s2,s2,1
 176:	000c                	0xc
 178:	0301                	addi	t1,t1,0
 17a:	0905                	addi	s2,s2,1
 17c:	000c                	0xc
 17e:	0301                	addi	t1,t1,0
 180:	0905                	addi	s2,s2,1
 182:	000c                	0xc
 184:	0301                	addi	t1,t1,0
 186:	0905                	addi	s2,s2,1
 188:	000c                	0xc
 18a:	0301                	addi	t1,t1,0
 18c:	0905                	addi	s2,s2,1
 18e:	000c                	0xc
 190:	0301                	addi	t1,t1,0
 192:	0905                	addi	s2,s2,1
 194:	000c                	0xc
 196:	0301                	addi	t1,t1,0
 198:	0905                	addi	s2,s2,1
 19a:	000c                	0xc
 19c:	0301                	addi	t1,t1,0
 19e:	0905                	addi	s2,s2,1
 1a0:	000c                	0xc
 1a2:	0301                	addi	t1,t1,0
 1a4:	0905                	addi	s2,s2,1
 1a6:	000c                	0xc
 1a8:	0301                	addi	t1,t1,0
 1aa:	0905                	addi	s2,s2,1
 1ac:	000c                	0xc
 1ae:	0301                	addi	t1,t1,0
 1b0:	0905                	addi	s2,s2,1
 1b2:	000c                	0xc
 1b4:	0301                	addi	t1,t1,0
 1b6:	0905                	addi	s2,s2,1
 1b8:	000c                	0xc
 1ba:	0301                	addi	t1,t1,0
 1bc:	0905                	addi	s2,s2,1
 1be:	0010                	0x10
 1c0:	0301                	addi	t1,t1,0
 1c2:	0905                	addi	s2,s2,1
 1c4:	0010                	0x10
 1c6:	0301                	addi	t1,t1,0
 1c8:	0905                	addi	s2,s2,1
 1ca:	0010                	0x10
 1cc:	0301                	addi	t1,t1,0
 1ce:	0905                	addi	s2,s2,1
 1d0:	0010                	0x10
 1d2:	0301                	addi	t1,t1,0
 1d4:	0905                	addi	s2,s2,1
 1d6:	0010                	0x10
 1d8:	0301                	addi	t1,t1,0
 1da:	0905                	addi	s2,s2,1
 1dc:	0010                	0x10
 1de:	0301                	addi	t1,t1,0
 1e0:	0905                	addi	s2,s2,1
 1e2:	0010                	0x10
 1e4:	0301                	addi	t1,t1,0
 1e6:	0905                	addi	s2,s2,1
 1e8:	0010                	0x10
 1ea:	0301                	addi	t1,t1,0
 1ec:	0905                	addi	s2,s2,1
 1ee:	0010                	0x10
 1f0:	0301                	addi	t1,t1,0
 1f2:	0905                	addi	s2,s2,1
 1f4:	0010                	0x10
 1f6:	0301                	addi	t1,t1,0
 1f8:	0905                	addi	s2,s2,1
 1fa:	0010                	0x10
 1fc:	0301                	addi	t1,t1,0
 1fe:	0905                	addi	s2,s2,1
 200:	0010                	0x10
 202:	0301                	addi	t1,t1,0
 204:	0905                	addi	s2,s2,1
 206:	0010                	0x10
 208:	0301                	addi	t1,t1,0
 20a:	0905                	addi	s2,s2,1
 20c:	0010                	0x10
 20e:	0301                	addi	t1,t1,0
 210:	0905                	addi	s2,s2,1
 212:	0010                	0x10
 214:	0301                	addi	t1,t1,0
 216:	0905                	addi	s2,s2,1
 218:	0010                	0x10
 21a:	0301                	addi	t1,t1,0
 21c:	0905                	addi	s2,s2,1
 21e:	0010                	0x10
 220:	0301                	addi	t1,t1,0
 222:	0905                	addi	s2,s2,1
 224:	0010                	0x10
 226:	0301                	addi	t1,t1,0
 228:	0905                	addi	s2,s2,1
 22a:	0010                	0x10
 22c:	0301                	addi	t1,t1,0
 22e:	0905                	addi	s2,s2,1
 230:	0010                	0x10
 232:	0301                	addi	t1,t1,0
 234:	0905                	addi	s2,s2,1
 236:	000c                	0xc
 238:	0301                	addi	t1,t1,0
 23a:	0905                	addi	s2,s2,1
 23c:	0010                	0x10
 23e:	0301                	addi	t1,t1,0
 240:	0905                	addi	s2,s2,1
 242:	0010                	0x10
 244:	0301                	addi	t1,t1,0
 246:	0905                	addi	s2,s2,1
 248:	0010                	0x10
 24a:	0301                	addi	t1,t1,0
 24c:	0905                	addi	s2,s2,1
 24e:	0010                	0x10
 250:	0301                	addi	t1,t1,0
 252:	0905                	addi	s2,s2,1
 254:	0010                	0x10
 256:	0301                	addi	t1,t1,0
 258:	0905                	addi	s2,s2,1
 25a:	0010                	0x10
 25c:	0301                	addi	t1,t1,0
 25e:	0905                	addi	s2,s2,1
 260:	0010                	0x10
 262:	0301                	addi	t1,t1,0
 264:	0905                	addi	s2,s2,1
 266:	0010                	0x10
 268:	0301                	addi	t1,t1,0
 26a:	0905                	addi	s2,s2,1
 26c:	0010                	0x10
 26e:	0301                	addi	t1,t1,0
 270:	0905                	addi	s2,s2,1
 272:	0010                	0x10
 274:	0301                	addi	t1,t1,0
 276:	0905                	addi	s2,s2,1
 278:	0010                	0x10
 27a:	0301                	addi	t1,t1,0
 27c:	0905                	addi	s2,s2,1
 27e:	0010                	0x10
 280:	0301                	addi	t1,t1,0
 282:	0905                	addi	s2,s2,1
 284:	0010                	0x10
 286:	0301                	addi	t1,t1,0
 288:	0905                	addi	s2,s2,1
 28a:	0010                	0x10
 28c:	0301                	addi	t1,t1,0
 28e:	0905                	addi	s2,s2,1
 290:	000c                	0xc
 292:	0301                	addi	t1,t1,0
 294:	0905                	addi	s2,s2,1
 296:	0010                	0x10
 298:	0301                	addi	t1,t1,0
 29a:	0905                	addi	s2,s2,1
 29c:	000c                	0xc
 29e:	0301                	addi	t1,t1,0
 2a0:	0904                	addi	s1,sp,144
 2a2:	000c                	0xc
 2a4:	0301                	addi	t1,t1,0
 2a6:	0901                	addi	s2,s2,0
 2a8:	0004                	0x4
 2aa:	0901                	addi	s2,s2,0
 2ac:	0010                	0x10
 2ae:	0100                	addi	s0,sp,128
 2b0:	01              	Address 0x00000000000002b0 is out of bounds.


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
  14:	054c                	addi	a1,sp,644
  16:	8000                	0x8000
  18:	0000                	unimp
  1a:	0000                	unimp
  1c:	005f 0000 00ad      	0xad0000005f
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
  14:	054c                	addi	a1,sp,644
	...

Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	6d6f682f          	0x6d6f682f
   4:	2f65                	jal	7bc <offset+0x6b8>
   6:	6f6c                	flw	fa1,92(a4)
   8:	6976                	flw	fs2,92(sp)
   a:	65442f73          	csrrs	t5,0x654,s0
   e:	6f746b73          	csrrsi	s6,0x6f7,8
  12:	2f70                	fld	fa2,216(a4)
  14:	6952                	flw	fs2,20(sp)
  16:	6556                	flw	fa0,84(sp)
  18:	5f72                	lw	t5,60(sp)
  1a:	65726f63          	bltu	tp,s7,678 <offset+0x574>
  1e:	7369722f          	0x7369722f
  22:	2f666f63          	bltu	a2,s6,320 <offset+0x21c>
  26:	6972                	flw	fs2,28(sp)
  28:	2d766373          	csrrsi	t1,0x2d7,12
  2c:	7261                	lui	tp,0xffff8
  2e:	742d6863          	bltu	s10,sp,77e <offset+0x67a>
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
  58:	2d69                	jal	6f2 <offset+0x5ee>
  5a:	3130                	fld	fa2,96(a0)
  5c:	532e                	lw	t1,232(sp)
  5e:	2f00                	fld	fs0,24(a4)
  60:	6f68                	flw	fa0,92(a4)
  62:	656d                	lui	a0,0x1b
  64:	766f6c2f          	0x766f6c2f
  68:	7369                	lui	t1,0xffffa
  6a:	7365442f          	0x7365442f
  6e:	706f746b          	0x706f746b
  72:	5669522f          	0x5669522f
  76:	7265                	lui	tp,0xffff9
  78:	635f 726f 2f65      	0x2f65726f635f
  7e:	6972                	flw	fs2,28(sp)
  80:	666f6373          	csrrsi	t1,0x666,30
  84:	7369722f          	0x7369722f
  88:	5f666f63          	bltu	a2,s6,686 <offset+0x582>
  8c:	6b726f77          	0x6b726f77
  90:	3376722f          	0x3376722f
  94:	6932                	flw	fs2,12(sp)
  96:	6d5f 492f 732f      	0x732f492f6d5f
  9c:	6372                	flw	ft6,28(sp)
  9e:	6172732f          	0x6172732f
  a2:	2d69                	jal	73c <offset+0x638>
  a4:	3130                	fld	fa2,96(a0)
  a6:	532e                	lw	t1,232(sp)
  a8:	7475642f          	0x7475642f
  ac:	4700                	lw	s0,8(a4)
  ae:	554e                	lw	a0,240(sp)
  b0:	4120                	lw	s0,64(a0)
  b2:	2e322053          	0x2e322053
  b6:	          	snez	a0,zero
