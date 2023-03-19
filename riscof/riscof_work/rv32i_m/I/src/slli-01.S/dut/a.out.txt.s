
my.elf:     file format elf32-littleriscv


Disassembly of section .text.init:

80000000 <rvtest_entry_point>:
80000000:	feedc0b7          	lui	ra,0xfeedc
80000004:	ead08093          	addi	ra,ra,-339 # feedbead <_end+0x7eed8c2d>
80000008:	ff76e137          	lui	sp,0xff76e
8000000c:	f5610113          	addi	sp,sp,-170 # ff76df56 <_end+0x7f76acd6>
80000010:	7fbb71b7          	lui	gp,0x7fbb7
80000014:	fab18193          	addi	gp,gp,-85 # 7fbb6fab <absimm+0x7fba6fab>
80000018:	bfddb237          	lui	tp,0xbfddb
8000001c:	7d520213          	addi	tp,tp,2005 # bfddb7d5 <_end+0x3fdd8555>
80000020:	00000297          	auipc	t0,0x0
80000024:	05828293          	addi	t0,t0,88 # 80000078 <rvtest_code_begin>
80000028:	00002317          	auipc	t1,0x2
8000002c:	fe830313          	addi	t1,t1,-24 # 80002010 <rvtest_data_begin>
80000030:	b7fbb3b7          	lui	t2,0xb7fbb
80000034:	6fa38393          	addi	t2,t2,1786 # b7fbb6fa <_end+0x37fb847a>
80000038:	5bfde437          	lui	s0,0x5bfde
8000003c:	b7d40413          	addi	s0,s0,-1155 # 5bfddb7d <absimm+0x5bfcdb7d>
80000040:	adfef4b7          	lui	s1,0xadfef
80000044:	dbe48493          	addi	s1,s1,-578 # adfeedbe <_end+0x2dfebb3e>
80000048:	56ff7537          	lui	a0,0x56ff7
8000004c:	6df50513          	addi	a0,a0,1759 # 56ff76df <absimm+0x56fe76df>
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
80000078:	00003197          	auipc	gp,0x3
8000007c:	09c18193          	addi	gp,gp,156 # 80003114 <signature_x3_0>

80000080 <inst_0>:
80000080:	c00008b7          	lui	a7,0xc0000
80000084:	fff88893          	addi	a7,a7,-1 # bfffffff <_end+0x3fffcd7f>
80000088:	01d89d93          	slli	s11,a7,0x1d
8000008c:	01b1a023          	sw	s11,0(gp)

80000090 <inst_1>:
80000090:	66666d37          	lui	s10,0x66666
80000094:	666d0d13          	addi	s10,s10,1638 # 66666666 <absimm+0x66656666>
80000098:	00fd1d13          	slli	s10,s10,0xf
8000009c:	01a1a223          	sw	s10,4(gp)

800000a0 <inst_2>:
800000a0:	ffff0b37          	lui	s6,0xffff0
800000a4:	fffb0b13          	addi	s6,s6,-1 # fffeffff <_end+0x7ffecd7f>
800000a8:	000b1593          	slli	a1,s6,0x0
800000ac:	00b1a423          	sw	a1,8(gp)

800000b0 <inst_3>:
800000b0:	00400793          	li	a5,4
800000b4:	00079313          	slli	t1,a5,0x0
800000b8:	0061a623          	sw	t1,12(gp)

800000bc <inst_4>:
800000bc:	ffc004b7          	lui	s1,0xffc00
800000c0:	fff48493          	addi	s1,s1,-1 # ffbfffff <_end+0x7fbfcd7f>
800000c4:	01f49813          	slli	a6,s1,0x1f
800000c8:	0101a823          	sw	a6,16(gp)

800000cc <inst_5>:
800000cc:	00400593          	li	a1,4
800000d0:	01f59a13          	slli	s4,a1,0x1f
800000d4:	0141aa23          	sw	s4,20(gp)

800000d8 <inst_6>:
800000d8:	00800093          	li	ra,8
800000dc:	00809993          	slli	s3,ra,0x8
800000e0:	0131ac23          	sw	s3,24(gp)

800000e4 <inst_7>:
800000e4:	800009b7          	lui	s3,0x80000
800000e8:	01099c93          	slli	s9,s3,0x10
800000ec:	0191ae23          	sw	s9,28(gp)

800000f0 <inst_8>:
800000f0:	00000413          	li	s0,0
800000f4:	00c41613          	slli	a2,s0,0xc
800000f8:	02c1a023          	sw	a2,32(gp)

800000fc <inst_9>:
800000fc:	80000db7          	lui	s11,0x80000
80000100:	fffd8d93          	addi	s11,s11,-1 # 7fffffff <_end+0xffffcd7f>
80000104:	008d9f13          	slli	t5,s11,0x8
80000108:	03e1a223          	sw	t5,36(gp)

8000010c <inst_10>:
8000010c:	00100113          	li	sp,1
80000110:	00111213          	slli	tp,sp,0x1
80000114:	0241a423          	sw	tp,40(gp)

80000118 <inst_11>:
80000118:	00200f93          	li	t6,2
8000011c:	006f9713          	slli	a4,t6,0x6
80000120:	02e1a623          	sw	a4,44(gp)

80000124 <inst_12>:
80000124:	01000c13          	li	s8,16
80000128:	00ec1893          	slli	a7,s8,0xe
8000012c:	0311a823          	sw	a7,48(gp)

80000130 <inst_13>:
80000130:	02000213          	li	tp,32
80000134:	00321513          	slli	a0,tp,0x3
80000138:	02a1aa23          	sw	a0,52(gp)

8000013c <inst_14>:
8000013c:	04000913          	li	s2,64
80000140:	01591113          	slli	sp,s2,0x15
80000144:	0221ac23          	sw	sp,56(gp)

80000148 <inst_15>:
80000148:	08000293          	li	t0,128
8000014c:	01529b93          	slli	s7,t0,0x15
80000150:	0371ae23          	sw	s7,60(gp)

80000154 <inst_16>:
80000154:	10000693          	li	a3,256
80000158:	00169413          	slli	s0,a3,0x1
8000015c:	0481a023          	sw	s0,64(gp)

80000160 <inst_17>:
80000160:	20000a13          	li	s4,512
80000164:	000a1013          	slli	zero,s4,0x0
80000168:	0401a223          	sw	zero,68(gp)

8000016c <inst_18>:
8000016c:	40000813          	li	a6,1024
80000170:	00281493          	slli	s1,a6,0x2
80000174:	0491a423          	sw	s1,72(gp)

80000178 <inst_19>:
80000178:	00001ab7          	lui	s5,0x1
8000017c:	800a8a93          	addi	s5,s5,-2048 # 800 <offset+0x6fc>
80000180:	013a9293          	slli	t0,s5,0x13
80000184:	0451a623          	sw	t0,76(gp)

80000188 <inst_20>:
80000188:	00001bb7          	lui	s7,0x1
8000018c:	007b9093          	slli	ra,s7,0x7
80000190:	0411a823          	sw	ra,80(gp)

80000194 <inst_21>:
80000194:	00002637          	lui	a2,0x2
80000198:	01061913          	slli	s2,a2,0x10
8000019c:	0521aa23          	sw	s2,84(gp)

800001a0 <inst_22>:
800001a0:	00004eb7          	lui	t4,0x4
800001a4:	00be9793          	slli	a5,t4,0xb
800001a8:	04f1ac23          	sw	a5,88(gp)
800001ac:	00003097          	auipc	ra,0x3
800001b0:	fc408093          	addi	ra,ra,-60 # 80003170 <signature_x1_0>

800001b4 <inst_23>:
800001b4:	000081b7          	lui	gp,0x8
800001b8:	01719a93          	slli	s5,gp,0x17
800001bc:	0150a023          	sw	s5,0(ra)

800001c0 <inst_24>:
800001c0:	00000013          	nop
800001c4:	00101f93          	slli	t6,zero,0x1
800001c8:	01f0a223          	sw	t6,4(ra)

800001cc <inst_25>:
800001cc:	00020737          	lui	a4,0x20
800001d0:	01b71193          	slli	gp,a4,0x1b
800001d4:	0030a423          	sw	gp,8(ra)

800001d8 <inst_26>:
800001d8:	00040cb7          	lui	s9,0x40
800001dc:	01fc9c13          	slli	s8,s9,0x1f
800001e0:	0180a623          	sw	s8,12(ra)

800001e4 <inst_27>:
800001e4:	00080f37          	lui	t5,0x80
800001e8:	00ff1e93          	slli	t4,t5,0xf
800001ec:	01d0a823          	sw	t4,16(ra)

800001f0 <inst_28>:
800001f0:	00100e37          	lui	t3,0x100
800001f4:	017e1693          	slli	a3,t3,0x17
800001f8:	00d0aa23          	sw	a3,20(ra)

800001fc <inst_29>:
800001fc:	00200537          	lui	a0,0x200
80000200:	00751393          	slli	t2,a0,0x7
80000204:	0070ac23          	sw	t2,24(ra)

80000208 <inst_30>:
80000208:	004003b7          	lui	t2,0x400
8000020c:	01d39b13          	slli	s6,t2,0x1d
80000210:	0160ae23          	sw	s6,28(ra)

80000214 <inst_31>:
80000214:	00800337          	lui	t1,0x800
80000218:	00231e13          	slli	t3,t1,0x2
8000021c:	03c0a023          	sw	t3,32(ra)

80000220 <inst_32>:
80000220:	01000537          	lui	a0,0x1000
80000224:	00651593          	slli	a1,a0,0x6
80000228:	02b0a223          	sw	a1,36(ra)

8000022c <inst_33>:
8000022c:	02000537          	lui	a0,0x2000
80000230:	00551593          	slli	a1,a0,0x5
80000234:	02b0a423          	sw	a1,40(ra)

80000238 <inst_34>:
80000238:	04000537          	lui	a0,0x4000
8000023c:	01151593          	slli	a1,a0,0x11
80000240:	02b0a623          	sw	a1,44(ra)

80000244 <inst_35>:
80000244:	08000537          	lui	a0,0x8000
80000248:	00051593          	slli	a1,a0,0x0
8000024c:	02b0a823          	sw	a1,48(ra)

80000250 <inst_36>:
80000250:	10000537          	lui	a0,0x10000
80000254:	00351593          	slli	a1,a0,0x3
80000258:	02b0aa23          	sw	a1,52(ra)

8000025c <inst_37>:
8000025c:	20000537          	lui	a0,0x20000
80000260:	00c51593          	slli	a1,a0,0xc
80000264:	02b0ac23          	sw	a1,56(ra)

80000268 <inst_38>:
80000268:	40000537          	lui	a0,0x40000
8000026c:	00b51593          	slli	a1,a0,0xb
80000270:	02b0ae23          	sw	a1,60(ra)

80000274 <inst_39>:
80000274:	ffe00513          	li	a0,-2
80000278:	00e51593          	slli	a1,a0,0xe
8000027c:	04b0a023          	sw	a1,64(ra)

80000280 <inst_40>:
80000280:	ffd00513          	li	a0,-3
80000284:	00151593          	slli	a1,a0,0x1
80000288:	04b0a223          	sw	a1,68(ra)

8000028c <inst_41>:
8000028c:	ffb00513          	li	a0,-5
80000290:	00751593          	slli	a1,a0,0x7
80000294:	04b0a423          	sw	a1,72(ra)

80000298 <inst_42>:
80000298:	ff700513          	li	a0,-9
8000029c:	00a51593          	slli	a1,a0,0xa
800002a0:	04b0a623          	sw	a1,76(ra)

800002a4 <inst_43>:
800002a4:	fef00513          	li	a0,-17
800002a8:	01151593          	slli	a1,a0,0x11
800002ac:	04b0a823          	sw	a1,80(ra)

800002b0 <inst_44>:
800002b0:	fdf00513          	li	a0,-33
800002b4:	00e51593          	slli	a1,a0,0xe
800002b8:	04b0aa23          	sw	a1,84(ra)

800002bc <inst_45>:
800002bc:	fbf00513          	li	a0,-65
800002c0:	01351593          	slli	a1,a0,0x13
800002c4:	04b0ac23          	sw	a1,88(ra)

800002c8 <inst_46>:
800002c8:	f7f00513          	li	a0,-129
800002cc:	01051593          	slli	a1,a0,0x10
800002d0:	04b0ae23          	sw	a1,92(ra)

800002d4 <inst_47>:
800002d4:	eff00513          	li	a0,-257
800002d8:	00b51593          	slli	a1,a0,0xb
800002dc:	06b0a023          	sw	a1,96(ra)

800002e0 <inst_48>:
800002e0:	dff00513          	li	a0,-513
800002e4:	01151593          	slli	a1,a0,0x11
800002e8:	06b0a223          	sw	a1,100(ra)

800002ec <inst_49>:
800002ec:	bff00513          	li	a0,-1025
800002f0:	00751593          	slli	a1,a0,0x7
800002f4:	06b0a423          	sw	a1,104(ra)

800002f8 <inst_50>:
800002f8:	fffff537          	lui	a0,0xfffff
800002fc:	7ff50513          	addi	a0,a0,2047 # fffff7ff <_end+0x7fffc57f>
80000300:	00f51593          	slli	a1,a0,0xf
80000304:	06b0a623          	sw	a1,108(ra)

80000308 <inst_51>:
80000308:	fffff537          	lui	a0,0xfffff
8000030c:	fff50513          	addi	a0,a0,-1 # ffffefff <_end+0x7fffbd7f>
80000310:	00a51593          	slli	a1,a0,0xa
80000314:	06b0a823          	sw	a1,112(ra)

80000318 <inst_52>:
80000318:	ffffe537          	lui	a0,0xffffe
8000031c:	fff50513          	addi	a0,a0,-1 # ffffdfff <_end+0x7fffad7f>
80000320:	00651593          	slli	a1,a0,0x6
80000324:	06b0aa23          	sw	a1,116(ra)

80000328 <inst_53>:
80000328:	ffffc537          	lui	a0,0xffffc
8000032c:	fff50513          	addi	a0,a0,-1 # ffffbfff <_end+0x7fff8d7f>
80000330:	00251593          	slli	a1,a0,0x2
80000334:	06b0ac23          	sw	a1,120(ra)

80000338 <inst_54>:
80000338:	ffff8537          	lui	a0,0xffff8
8000033c:	fff50513          	addi	a0,a0,-1 # ffff7fff <_end+0x7fff4d7f>
80000340:	00351593          	slli	a1,a0,0x3
80000344:	06b0ae23          	sw	a1,124(ra)

80000348 <inst_55>:
80000348:	fffe0537          	lui	a0,0xfffe0
8000034c:	fff50513          	addi	a0,a0,-1 # fffdffff <_end+0x7ffdcd7f>
80000350:	01d51593          	slli	a1,a0,0x1d
80000354:	08b0a023          	sw	a1,128(ra)

80000358 <inst_56>:
80000358:	fffc0537          	lui	a0,0xfffc0
8000035c:	fff50513          	addi	a0,a0,-1 # fffbffff <_end+0x7ffbcd7f>
80000360:	01d51593          	slli	a1,a0,0x1d
80000364:	08b0a223          	sw	a1,132(ra)

80000368 <inst_57>:
80000368:	fff80537          	lui	a0,0xfff80
8000036c:	fff50513          	addi	a0,a0,-1 # fff7ffff <_end+0x7ff7cd7f>
80000370:	00c51593          	slli	a1,a0,0xc
80000374:	08b0a423          	sw	a1,136(ra)

80000378 <inst_58>:
80000378:	ffe00537          	lui	a0,0xffe00
8000037c:	fff50513          	addi	a0,a0,-1 # ffdfffff <_end+0x7fdfcd7f>
80000380:	00651593          	slli	a1,a0,0x6
80000384:	08b0a623          	sw	a1,140(ra)

80000388 <inst_59>:
80000388:	ff800537          	lui	a0,0xff800
8000038c:	fff50513          	addi	a0,a0,-1 # ff7fffff <_end+0x7f7fcd7f>
80000390:	01351593          	slli	a1,a0,0x13
80000394:	08b0a823          	sw	a1,144(ra)

80000398 <inst_60>:
80000398:	ff000537          	lui	a0,0xff000
8000039c:	fff50513          	addi	a0,a0,-1 # feffffff <_end+0x7effcd7f>
800003a0:	01151593          	slli	a1,a0,0x11
800003a4:	08b0aa23          	sw	a1,148(ra)

800003a8 <inst_61>:
800003a8:	fe000537          	lui	a0,0xfe000
800003ac:	fff50513          	addi	a0,a0,-1 # fdffffff <_end+0x7dffcd7f>
800003b0:	00f51593          	slli	a1,a0,0xf
800003b4:	08b0ac23          	sw	a1,152(ra)

800003b8 <inst_62>:
800003b8:	fc000537          	lui	a0,0xfc000
800003bc:	fff50513          	addi	a0,a0,-1 # fbffffff <_end+0x7bffcd7f>
800003c0:	00d51593          	slli	a1,a0,0xd
800003c4:	08b0ae23          	sw	a1,156(ra)

800003c8 <inst_63>:
800003c8:	f8000537          	lui	a0,0xf8000
800003cc:	fff50513          	addi	a0,a0,-1 # f7ffffff <_end+0x77ffcd7f>
800003d0:	00e51593          	slli	a1,a0,0xe
800003d4:	0ab0a023          	sw	a1,160(ra)

800003d8 <inst_64>:
800003d8:	f0000537          	lui	a0,0xf0000
800003dc:	fff50513          	addi	a0,a0,-1 # efffffff <_end+0x6fffcd7f>
800003e0:	00751593          	slli	a1,a0,0x7
800003e4:	0ab0a223          	sw	a1,164(ra)

800003e8 <inst_65>:
800003e8:	e0000537          	lui	a0,0xe0000
800003ec:	fff50513          	addi	a0,a0,-1 # dfffffff <_end+0x5fffcd7f>
800003f0:	00b51593          	slli	a1,a0,0xb
800003f4:	0ab0a423          	sw	a1,168(ra)

800003f8 <inst_66>:
800003f8:	55555537          	lui	a0,0x55555
800003fc:	55550513          	addi	a0,a0,1365 # 55555555 <absimm+0x55545555>
80000400:	01151593          	slli	a1,a0,0x11
80000404:	0ab0a623          	sw	a1,172(ra)

80000408 <inst_67>:
80000408:	aaaab537          	lui	a0,0xaaaab
8000040c:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <_end+0x2aaa782a>
80000410:	01751593          	slli	a1,a0,0x17
80000414:	0ab0a823          	sw	a1,176(ra)

80000418 <inst_68>:
80000418:	00300513          	li	a0,3
8000041c:	01351593          	slli	a1,a0,0x13
80000420:	0ab0aa23          	sw	a1,180(ra)

80000424 <inst_69>:
80000424:	00500513          	li	a0,5
80000428:	00151593          	slli	a1,a0,0x1
8000042c:	0ab0ac23          	sw	a1,184(ra)

80000430 <inst_70>:
80000430:	33333537          	lui	a0,0x33333
80000434:	33350513          	addi	a0,a0,819 # 33333333 <absimm+0x33323333>
80000438:	00351593          	slli	a1,a0,0x3
8000043c:	0ab0ae23          	sw	a1,188(ra)

80000440 <inst_71>:
80000440:	ffff5537          	lui	a0,0xffff5
80000444:	afc50513          	addi	a0,a0,-1284 # ffff4afc <_end+0x7fff187c>
80000448:	00651593          	slli	a1,a0,0x6
8000044c:	0cb0a023          	sw	a1,192(ra)

80000450 <inst_72>:
80000450:	66666537          	lui	a0,0x66666
80000454:	66750513          	addi	a0,a0,1639 # 66666667 <absimm+0x66656667>
80000458:	01751593          	slli	a1,a0,0x17
8000045c:	0cb0a223          	sw	a1,196(ra)

80000460 <inst_73>:
80000460:	ffff5537          	lui	a0,0xffff5
80000464:	afd50513          	addi	a0,a0,-1283 # ffff4afd <_end+0x7fff187d>
80000468:	00651593          	slli	a1,a0,0x6
8000046c:	0cb0a423          	sw	a1,200(ra)

80000470 <inst_74>:
80000470:	0000b537          	lui	a0,0xb
80000474:	50550513          	addi	a0,a0,1285 # b505 <offset+0xb401>
80000478:	01f51593          	slli	a1,a0,0x1f
8000047c:	0cb0a623          	sw	a1,204(ra)

80000480 <inst_75>:
80000480:	33333537          	lui	a0,0x33333
80000484:	33250513          	addi	a0,a0,818 # 33333332 <absimm+0x33323332>
80000488:	00451593          	slli	a1,a0,0x4
8000048c:	0cb0a823          	sw	a1,208(ra)

80000490 <inst_76>:
80000490:	ffa00513          	li	a0,-6
80000494:	01e51593          	slli	a1,a0,0x1e
80000498:	0cb0aa23          	sw	a1,212(ra)

8000049c <inst_77>:
8000049c:	0000b537          	lui	a0,0xb
800004a0:	50450513          	addi	a0,a0,1284 # b504 <offset+0xb400>
800004a4:	00751593          	slli	a1,a0,0x7
800004a8:	0cb0ac23          	sw	a1,216(ra)

800004ac <inst_78>:
800004ac:	fff00537          	lui	a0,0xfff00
800004b0:	fff50513          	addi	a0,a0,-1 # ffefffff <_end+0x7fefcd7f>
800004b4:	00851593          	slli	a1,a0,0x8
800004b8:	0cb0ae23          	sw	a1,220(ra)

800004bc <inst_79>:
800004bc:	55555537          	lui	a0,0x55555
800004c0:	55450513          	addi	a0,a0,1364 # 55555554 <absimm+0x55545554>
800004c4:	00351593          	slli	a1,a0,0x3
800004c8:	0eb0a023          	sw	a1,224(ra)

800004cc <inst_80>:
800004cc:	66666537          	lui	a0,0x66666
800004d0:	66550513          	addi	a0,a0,1637 # 66666665 <absimm+0x66656665>
800004d4:	01051593          	slli	a1,a0,0x10
800004d8:	0eb0a223          	sw	a1,228(ra)

800004dc <inst_81>:
800004dc:	0000b537          	lui	a0,0xb
800004e0:	50350513          	addi	a0,a0,1283 # b503 <offset+0xb3ff>
800004e4:	01051593          	slli	a1,a0,0x10
800004e8:	0eb0a423          	sw	a1,232(ra)

800004ec <inst_82>:
800004ec:	55555537          	lui	a0,0x55555
800004f0:	55650513          	addi	a0,a0,1366 # 55555556 <absimm+0x55545556>
800004f4:	01751593          	slli	a1,a0,0x17
800004f8:	0eb0a623          	sw	a1,236(ra)

800004fc <inst_83>:
800004fc:	aaaab537          	lui	a0,0xaaaab
80000500:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <_end+0x2aaa782b>
80000504:	00e51593          	slli	a1,a0,0xe
80000508:	0eb0a823          	sw	a1,240(ra)

8000050c <inst_84>:
8000050c:	00600513          	li	a0,6
80000510:	01e51593          	slli	a1,a0,0x1e
80000514:	0eb0aa23          	sw	a1,244(ra)

80000518 <inst_85>:
80000518:	33333537          	lui	a0,0x33333
8000051c:	33450513          	addi	a0,a0,820 # 33333334 <absimm+0x33323334>
80000520:	01d51593          	slli	a1,a0,0x1d
80000524:	0eb0ac23          	sw	a1,248(ra)

80000528 <inst_86>:
80000528:	20000513          	li	a0,512
8000052c:	00051593          	slli	a1,a0,0x0
80000530:	0eb0ae23          	sw	a1,252(ra)

80000534 <inst_87>:
80000534:	00010537          	lui	a0,0x10
80000538:	00151593          	slli	a1,a0,0x1
8000053c:	10b0a023          	sw	a1,256(ra)

80000540 <cleanup_epilogs>:
80000540:	0040006f          	j	80000544 <exit_cleanup>

80000544 <exit_cleanup>:
80000544:	00100093          	li	ra,1

80000548 <write_tohost>:
80000548:	00001f17          	auipc	t5,0x1
8000054c:	aa1f2c23          	sw	ra,-1352(t5) # 80001000 <tohost>
80000550:	ff9ff06f          	j	80000548 <write_tohost>
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
80002020:	deadbeef          	jal	t4,7ffdd60a <absimm+0x7ffcd60a>
80002024:	deadbeef          	jal	t4,7ffdd60e <absimm+0x7ffcd60e>

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

80003114 <signature_x3_0>:
80003114:	deadbeef          	jal	t4,7ffde6fe <absimm+0x7ffce6fe>
80003118:	deadbeef          	jal	t4,7ffde702 <absimm+0x7ffce702>
8000311c:	deadbeef          	jal	t4,7ffde706 <absimm+0x7ffce706>
80003120:	deadbeef          	jal	t4,7ffde70a <absimm+0x7ffce70a>
80003124:	deadbeef          	jal	t4,7ffde70e <absimm+0x7ffce70e>
80003128:	deadbeef          	jal	t4,7ffde712 <absimm+0x7ffce712>
8000312c:	deadbeef          	jal	t4,7ffde716 <absimm+0x7ffce716>
80003130:	deadbeef          	jal	t4,7ffde71a <absimm+0x7ffce71a>
80003134:	deadbeef          	jal	t4,7ffde71e <absimm+0x7ffce71e>
80003138:	deadbeef          	jal	t4,7ffde722 <absimm+0x7ffce722>
8000313c:	deadbeef          	jal	t4,7ffde726 <absimm+0x7ffce726>
80003140:	deadbeef          	jal	t4,7ffde72a <absimm+0x7ffce72a>
80003144:	deadbeef          	jal	t4,7ffde72e <absimm+0x7ffce72e>
80003148:	deadbeef          	jal	t4,7ffde732 <absimm+0x7ffce732>
8000314c:	deadbeef          	jal	t4,7ffde736 <absimm+0x7ffce736>
80003150:	deadbeef          	jal	t4,7ffde73a <absimm+0x7ffce73a>
80003154:	deadbeef          	jal	t4,7ffde73e <absimm+0x7ffce73e>
80003158:	deadbeef          	jal	t4,7ffde742 <absimm+0x7ffce742>
8000315c:	deadbeef          	jal	t4,7ffde746 <absimm+0x7ffce746>
80003160:	deadbeef          	jal	t4,7ffde74a <absimm+0x7ffce74a>
80003164:	deadbeef          	jal	t4,7ffde74e <absimm+0x7ffce74e>
80003168:	deadbeef          	jal	t4,7ffde752 <absimm+0x7ffce752>
8000316c:	deadbeef          	jal	t4,7ffde756 <absimm+0x7ffce756>

80003170 <signature_x1_0>:
80003170:	deadbeef          	jal	t4,7ffde75a <absimm+0x7ffce75a>
80003174:	deadbeef          	jal	t4,7ffde75e <absimm+0x7ffce75e>
80003178:	deadbeef          	jal	t4,7ffde762 <absimm+0x7ffce762>
8000317c:	deadbeef          	jal	t4,7ffde766 <absimm+0x7ffce766>
80003180:	deadbeef          	jal	t4,7ffde76a <absimm+0x7ffce76a>
80003184:	deadbeef          	jal	t4,7ffde76e <absimm+0x7ffce76e>
80003188:	deadbeef          	jal	t4,7ffde772 <absimm+0x7ffce772>
8000318c:	deadbeef          	jal	t4,7ffde776 <absimm+0x7ffce776>
80003190:	deadbeef          	jal	t4,7ffde77a <absimm+0x7ffce77a>
80003194:	deadbeef          	jal	t4,7ffde77e <absimm+0x7ffce77e>
80003198:	deadbeef          	jal	t4,7ffde782 <absimm+0x7ffce782>
8000319c:	deadbeef          	jal	t4,7ffde786 <absimm+0x7ffce786>
800031a0:	deadbeef          	jal	t4,7ffde78a <absimm+0x7ffce78a>
800031a4:	deadbeef          	jal	t4,7ffde78e <absimm+0x7ffce78e>
800031a8:	deadbeef          	jal	t4,7ffde792 <absimm+0x7ffce792>
800031ac:	deadbeef          	jal	t4,7ffde796 <absimm+0x7ffce796>
800031b0:	deadbeef          	jal	t4,7ffde79a <absimm+0x7ffce79a>
800031b4:	deadbeef          	jal	t4,7ffde79e <absimm+0x7ffce79e>
800031b8:	deadbeef          	jal	t4,7ffde7a2 <absimm+0x7ffce7a2>
800031bc:	deadbeef          	jal	t4,7ffde7a6 <absimm+0x7ffce7a6>
800031c0:	deadbeef          	jal	t4,7ffde7aa <absimm+0x7ffce7aa>
800031c4:	deadbeef          	jal	t4,7ffde7ae <absimm+0x7ffce7ae>
800031c8:	deadbeef          	jal	t4,7ffde7b2 <absimm+0x7ffce7b2>
800031cc:	deadbeef          	jal	t4,7ffde7b6 <absimm+0x7ffce7b6>
800031d0:	deadbeef          	jal	t4,7ffde7ba <absimm+0x7ffce7ba>
800031d4:	deadbeef          	jal	t4,7ffde7be <absimm+0x7ffce7be>
800031d8:	deadbeef          	jal	t4,7ffde7c2 <absimm+0x7ffce7c2>
800031dc:	deadbeef          	jal	t4,7ffde7c6 <absimm+0x7ffce7c6>
800031e0:	deadbeef          	jal	t4,7ffde7ca <absimm+0x7ffce7ca>
800031e4:	deadbeef          	jal	t4,7ffde7ce <absimm+0x7ffce7ce>
800031e8:	deadbeef          	jal	t4,7ffde7d2 <absimm+0x7ffce7d2>
800031ec:	deadbeef          	jal	t4,7ffde7d6 <absimm+0x7ffce7d6>
800031f0:	deadbeef          	jal	t4,7ffde7da <absimm+0x7ffce7da>
800031f4:	deadbeef          	jal	t4,7ffde7de <absimm+0x7ffce7de>
800031f8:	deadbeef          	jal	t4,7ffde7e2 <absimm+0x7ffce7e2>
800031fc:	deadbeef          	jal	t4,7ffde7e6 <absimm+0x7ffce7e6>
80003200:	deadbeef          	jal	t4,7ffde7ea <absimm+0x7ffce7ea>
80003204:	deadbeef          	jal	t4,7ffde7ee <absimm+0x7ffce7ee>
80003208:	deadbeef          	jal	t4,7ffde7f2 <absimm+0x7ffce7f2>
8000320c:	deadbeef          	jal	t4,7ffde7f6 <absimm+0x7ffce7f6>
80003210:	deadbeef          	jal	t4,7ffde7fa <absimm+0x7ffce7fa>
80003214:	deadbeef          	jal	t4,7ffde7fe <absimm+0x7ffce7fe>
80003218:	deadbeef          	jal	t4,7ffde802 <absimm+0x7ffce802>
8000321c:	deadbeef          	jal	t4,7ffde806 <absimm+0x7ffce806>
80003220:	deadbeef          	jal	t4,7ffde80a <absimm+0x7ffce80a>
80003224:	deadbeef          	jal	t4,7ffde80e <absimm+0x7ffce80e>
80003228:	deadbeef          	jal	t4,7ffde812 <absimm+0x7ffce812>
8000322c:	deadbeef          	jal	t4,7ffde816 <absimm+0x7ffce816>
80003230:	deadbeef          	jal	t4,7ffde81a <absimm+0x7ffce81a>
80003234:	deadbeef          	jal	t4,7ffde81e <absimm+0x7ffce81e>
80003238:	deadbeef          	jal	t4,7ffde822 <absimm+0x7ffce822>
8000323c:	deadbeef          	jal	t4,7ffde826 <absimm+0x7ffce826>
80003240:	deadbeef          	jal	t4,7ffde82a <absimm+0x7ffce82a>
80003244:	deadbeef          	jal	t4,7ffde82e <absimm+0x7ffce82e>
80003248:	deadbeef          	jal	t4,7ffde832 <absimm+0x7ffce832>
8000324c:	deadbeef          	jal	t4,7ffde836 <absimm+0x7ffce836>
80003250:	deadbeef          	jal	t4,7ffde83a <absimm+0x7ffce83a>
80003254:	deadbeef          	jal	t4,7ffde83e <absimm+0x7ffce83e>
80003258:	deadbeef          	jal	t4,7ffde842 <absimm+0x7ffce842>
8000325c:	deadbeef          	jal	t4,7ffde846 <absimm+0x7ffce846>
80003260:	deadbeef          	jal	t4,7ffde84a <absimm+0x7ffce84a>
80003264:	deadbeef          	jal	t4,7ffde84e <absimm+0x7ffce84e>
80003268:	deadbeef          	jal	t4,7ffde852 <absimm+0x7ffce852>
8000326c:	deadbeef          	jal	t4,7ffde856 <absimm+0x7ffce856>
80003270:	deadbeef          	jal	t4,7ffde85a <absimm+0x7ffce85a>

80003274 <sig_end_canary>:
80003274:	a309                	j	80003776 <_end+0x4f6>
80003276:	6f5c                	flw	fa5,28(a4)

80003278 <rvtest_sig_end>:
	...

Disassembly of section .riscv.attributes:

00000000 <.riscv.attributes>:
   0:	1941                	addi	s2,s2,-16
   2:	0000                	unimp
   4:	7200                	flw	fs0,32(a2)
   6:	7369                	lui	t1,0xffffa
   8:	01007663          	bgeu	zero,a6,14 <edge2+0x3>
   c:	0000000f          	fence	unknown,unknown
  10:	7205                	lui	tp,0xfffe1
  12:	3376                	fld	ft6,376(sp)
  14:	6932                	flw	fs2,12(sp)
  16:	7032                	flw	ft0,44(sp)
  18:	0030                	addi	a2,sp,8

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	000002b3          	add	t0,zero,zero
   4:	00750003          	lb	zero,7(a0) # 10007 <absimm+0x7>
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
  72:	6c6c                	flw	fa1,92(s0)
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
  98:	0010                	0x10
  9a:	0301                	addi	t1,t1,0
  9c:	0905                	addi	s2,s2,1
  9e:	0010                	0x10
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
 114:	0905                	addi	s2,s2,1
 116:	000c                	0xc
 118:	0301                	addi	t1,t1,0
 11a:	0901                	addi	s2,s2,0
 11c:	000c                	0xc
 11e:	0301                	addi	t1,t1,0
 120:	0905                	addi	s2,s2,1
 122:	0008                	0x8
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
 1be:	000c                	0xc
 1c0:	0301                	addi	t1,t1,0
 1c2:	0905                	addi	s2,s2,1
 1c4:	000c                	0xc
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
 23c:	000c                	0xc
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
 266:	000c                	0xc
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
 290:	0010                	0x10
 292:	0301                	addi	t1,t1,0
 294:	0905                	addi	s2,s2,1
 296:	000c                	0xc
 298:	0301                	addi	t1,t1,0
 29a:	0905                	addi	s2,s2,1
 29c:	0010                	0x10
 29e:	0301                	addi	t1,t1,0
 2a0:	0905                	addi	s2,s2,1
 2a2:	000c                	0xc
 2a4:	0301                	addi	t1,t1,0
 2a6:	0904                	addi	s1,sp,144
 2a8:	000c                	0xc
 2aa:	0301                	addi	t1,t1,0
 2ac:	0901                	addi	s2,s2,0
 2ae:	0004                	0x4
 2b0:	0901                	addi	s2,s2,0
 2b2:	0010                	0x10
 2b4:	0100                	addi	s0,sp,128
 2b6:	01              	Address 0x00000000000002b6 is out of bounds.


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
  14:	0554                	addi	a3,sp,644
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
  14:	0554                	addi	a3,sp,644
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
  54:	6c6c732f          	0x6c6c732f
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
  9e:	6c6c732f          	0x6c6c732f
  a2:	2d69                	jal	73c <offset+0x638>
  a4:	3130                	fld	fa2,96(a0)
  a6:	532e                	lw	t1,232(sp)
  a8:	7475642f          	0x7475642f
  ac:	4700                	lw	s0,8(a4)
  ae:	554e                	lw	a0,240(sp)
  b0:	4120                	lw	s0,64(a0)
  b2:	2e322053          	0x2e322053
  b6:	          	snez	a0,zero
