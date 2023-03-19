
my.elf:     file format elf32-littleriscv


Disassembly of section .text.init:

80000000 <rvtest_entry_point>:
80000000:	feedc0b7          	lui	ra,0xfeedc
80000004:	ead08093          	addi	ra,ra,-339 # feedbead <edge2+0xfeedbeae>
80000008:	ff76e137          	lui	sp,0xff76e
8000000c:	f5610113          	addi	sp,sp,-170 # ff76df56 <edge2+0xff76df57>
80000010:	7fbb71b7          	lui	gp,0x7fbb7
80000014:	fab18193          	addi	gp,gp,-85 # 7fbb6fab <offset+0x7fbb6e9b>
80000018:	bfddb237          	lui	tp,0xbfddb
8000001c:	7d520213          	addi	tp,tp,2005 # bfddb7d5 <edge2+0xbfddb7d6>
80000020:	00000297          	auipc	t0,0x0
80000024:	05828293          	addi	t0,t0,88 # 80000078 <rvtest_code_begin>
80000028:	00002317          	auipc	t1,0x2
8000002c:	fe830313          	addi	t1,t1,-24 # 80002010 <rvtest_data_begin>
80000030:	b7fbb3b7          	lui	t2,0xb7fbb
80000034:	6fa38393          	addi	t2,t2,1786 # b7fbb6fa <edge2+0xb7fbb6fb>
80000038:	5bfde437          	lui	s0,0x5bfde
8000003c:	b7d40413          	addi	s0,s0,-1155 # 5bfddb7d <offset+0x5bfdda6d>
80000040:	adfef4b7          	lui	s1,0xadfef
80000044:	dbe48493          	addi	s1,s1,-578 # adfeedbe <edge2+0xadfeedbf>
80000048:	56ff7537          	lui	a0,0x56ff7
8000004c:	6df50513          	addi	a0,a0,1759 # 56ff76df <offset+0x56ff75cf>
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
80000078:	00003297          	auipc	t0,0x3
8000007c:	09c28293          	addi	t0,t0,156 # 80003114 <signature_x5_0>

80000080 <inst_0>:
80000080:	ffff5f37          	lui	t5,0xffff5
80000084:	afcf0f13          	addi	t5,t5,-1284 # ffff4afc <edge2+0xffff4afd>
80000088:	002f5413          	srli	s0,t5,0x2
8000008c:	0082a023          	sw	s0,0(t0)

80000090 <inst_1>:
80000090:	00700893          	li	a7,7
80000094:	0138d893          	srli	a7,a7,0x13
80000098:	0112a223          	sw	a7,4(t0)

8000009c <inst_2>:
8000009c:	ffff5db7          	lui	s11,0xffff5
800000a0:	afcd8d93          	addi	s11,s11,-1284 # ffff4afc <edge2+0xffff4afd>
800000a4:	000dd993          	srli	s3,s11,0x0
800000a8:	0132a423          	sw	s3,8(t0)

800000ac <inst_3>:
800000ac:	40000eb7          	lui	t4,0x40000
800000b0:	fffe8e93          	addi	t4,t4,-1 # 3fffffff <offset+0x3ffffeef>
800000b4:	000ed493          	srli	s1,t4,0x0
800000b8:	0092a623          	sw	s1,12(t0)

800000bc <inst_4>:
800000bc:	ff600c93          	li	s9,-10
800000c0:	01fcdb13          	srli	s6,s9,0x1f
800000c4:	0162a823          	sw	s6,16(t0)

800000c8 <inst_5>:
800000c8:	20000093          	li	ra,512
800000cc:	01f0d693          	srli	a3,ra,0x1f
800000d0:	00d2aa23          	sw	a3,20(t0)

800000d4 <inst_6>:
800000d4:	00300a93          	li	s5,3
800000d8:	003ad013          	srli	zero,s5,0x3
800000dc:	0002ac23          	sw	zero,24(t0)

800000e0 <inst_7>:
800000e0:	00000013          	nop
800000e4:	00905e93          	srli	t4,zero,0x9
800000e8:	01d2ae23          	sw	t4,28(t0)

800000ec <inst_8>:
800000ec:	00000813          	li	a6,0
800000f0:	00185913          	srli	s2,a6,0x1
800000f4:	0322a023          	sw	s2,32(t0)

800000f8 <inst_9>:
800000f8:	80000a37          	lui	s4,0x80000
800000fc:	fffa0a13          	addi	s4,s4,-1 # 7fffffff <edge2+0x80000000>
80000100:	011a5d93          	srli	s11,s4,0x11
80000104:	03b2a223          	sw	s11,36(t0)

80000108 <inst_10>:
80000108:	00100f93          	li	t6,1
8000010c:	012fd113          	srli	sp,t6,0x12
80000110:	0222a423          	sw	sp,40(t0)

80000114 <inst_11>:
80000114:	00200393          	li	t2,2
80000118:	01d3df93          	srli	t6,t2,0x1d
8000011c:	03f2a623          	sw	t6,44(t0)

80000120 <inst_12>:
80000120:	00400713          	li	a4,4
80000124:	00f75813          	srli	a6,a4,0xf
80000128:	0302a823          	sw	a6,48(t0)

8000012c <inst_13>:
8000012c:	00800613          	li	a2,8
80000130:	01b65c93          	srli	s9,a2,0x1b
80000134:	0392aa23          	sw	s9,52(t0)

80000138 <inst_14>:
80000138:	01000213          	li	tp,16
8000013c:	00f25593          	srli	a1,tp,0xf
80000140:	02b2ac23          	sw	a1,56(t0)

80000144 <inst_15>:
80000144:	02000c13          	li	s8,32
80000148:	017c5b93          	srli	s7,s8,0x17
8000014c:	0372ae23          	sw	s7,60(t0)

80000150 <inst_16>:
80000150:	04000413          	li	s0,64
80000154:	00d45e13          	srli	t3,s0,0xd
80000158:	05c2a023          	sw	t3,64(t0)

8000015c <inst_17>:
8000015c:	08000793          	li	a5,128
80000160:	01e7df13          	srli	t5,a5,0x1e
80000164:	05e2a223          	sw	t5,68(t0)

80000168 <inst_18>:
80000168:	10000913          	li	s2,256
8000016c:	01f95a13          	srli	s4,s2,0x1f
80000170:	0542a423          	sw	s4,72(t0)

80000174 <inst_19>:
80000174:	40000693          	li	a3,1024
80000178:	0126d713          	srli	a4,a3,0x12
8000017c:	04e2a623          	sw	a4,76(t0)

80000180 <inst_20>:
80000180:	000015b7          	lui	a1,0x1
80000184:	80058593          	addi	a1,a1,-2048 # 800 <offset+0x6f0>
80000188:	00f5d193          	srli	gp,a1,0xf
8000018c:	0432a823          	sw	gp,80(t0)

80000190 <inst_21>:
80000190:	00001bb7          	lui	s7,0x1
80000194:	00fbdd13          	srli	s10,s7,0xf
80000198:	05a2aa23          	sw	s10,84(t0)
8000019c:	00003417          	auipc	s0,0x3
800001a0:	fd040413          	addi	s0,s0,-48 # 8000316c <signature_x8_0>

800001a4 <inst_22>:
800001a4:	000029b7          	lui	s3,0x2
800001a8:	0029d513          	srli	a0,s3,0x2
800001ac:	00a42023          	sw	a0,0(s0)

800001b0 <inst_23>:
800001b0:	00004537          	lui	a0,0x4
800001b4:	00e55a93          	srli	s5,a0,0xe
800001b8:	01542223          	sw	s5,4(s0)

800001bc <inst_24>:
800001bc:	000082b7          	lui	t0,0x8
800001c0:	0032d393          	srli	t2,t0,0x3
800001c4:	00742423          	sw	t2,8(s0)

800001c8 <inst_25>:
800001c8:	00010137          	lui	sp,0x10
800001cc:	01715293          	srli	t0,sp,0x17
800001d0:	00542623          	sw	t0,12(s0)

800001d4 <inst_26>:
800001d4:	00020e37          	lui	t3,0x20
800001d8:	011e5313          	srli	t1,t3,0x11
800001dc:	00642823          	sw	t1,16(s0)

800001e0 <inst_27>:
800001e0:	000401b7          	lui	gp,0x40
800001e4:	0071d613          	srli	a2,gp,0x7
800001e8:	00c42a23          	sw	a2,20(s0)

800001ec <inst_28>:
800001ec:	00080d37          	lui	s10,0x80
800001f0:	01dd5213          	srli	tp,s10,0x1d
800001f4:	00442c23          	sw	tp,24(s0)

800001f8 <inst_29>:
800001f8:	001004b7          	lui	s1,0x100
800001fc:	0024dc13          	srli	s8,s1,0x2
80000200:	01842e23          	sw	s8,28(s0)

80000204 <inst_30>:
80000204:	00200337          	lui	t1,0x200
80000208:	00535793          	srli	a5,t1,0x5
8000020c:	02f42023          	sw	a5,32(s0)

80000210 <inst_31>:
80000210:	00400b37          	lui	s6,0x400
80000214:	00cb5093          	srli	ra,s6,0xc
80000218:	02142223          	sw	ra,36(s0)

8000021c <inst_32>:
8000021c:	00800537          	lui	a0,0x800
80000220:	00955593          	srli	a1,a0,0x9
80000224:	02b42423          	sw	a1,40(s0)

80000228 <inst_33>:
80000228:	01000537          	lui	a0,0x1000
8000022c:	00e55593          	srli	a1,a0,0xe
80000230:	02b42623          	sw	a1,44(s0)

80000234 <inst_34>:
80000234:	02000537          	lui	a0,0x2000
80000238:	00355593          	srli	a1,a0,0x3
8000023c:	02b42823          	sw	a1,48(s0)

80000240 <inst_35>:
80000240:	04000537          	lui	a0,0x4000
80000244:	00455593          	srli	a1,a0,0x4
80000248:	02b42a23          	sw	a1,52(s0)

8000024c <inst_36>:
8000024c:	08000537          	lui	a0,0x8000
80000250:	00755593          	srli	a1,a0,0x7
80000254:	02b42c23          	sw	a1,56(s0)

80000258 <inst_37>:
80000258:	10000537          	lui	a0,0x10000
8000025c:	00755593          	srli	a1,a0,0x7
80000260:	02b42e23          	sw	a1,60(s0)

80000264 <inst_38>:
80000264:	20000537          	lui	a0,0x20000
80000268:	00055593          	srli	a1,a0,0x0
8000026c:	04b42023          	sw	a1,64(s0)

80000270 <inst_39>:
80000270:	40000537          	lui	a0,0x40000
80000274:	01e55593          	srli	a1,a0,0x1e
80000278:	04b42223          	sw	a1,68(s0)

8000027c <inst_40>:
8000027c:	ffe00513          	li	a0,-2
80000280:	01d55593          	srli	a1,a0,0x1d
80000284:	04b42423          	sw	a1,72(s0)

80000288 <inst_41>:
80000288:	ffd00513          	li	a0,-3
8000028c:	00b55593          	srli	a1,a0,0xb
80000290:	04b42623          	sw	a1,76(s0)

80000294 <inst_42>:
80000294:	ffb00513          	li	a0,-5
80000298:	00555593          	srli	a1,a0,0x5
8000029c:	04b42823          	sw	a1,80(s0)

800002a0 <inst_43>:
800002a0:	ff700513          	li	a0,-9
800002a4:	00155593          	srli	a1,a0,0x1
800002a8:	04b42a23          	sw	a1,84(s0)

800002ac <inst_44>:
800002ac:	fef00513          	li	a0,-17
800002b0:	01d55593          	srli	a1,a0,0x1d
800002b4:	04b42c23          	sw	a1,88(s0)

800002b8 <inst_45>:
800002b8:	fdf00513          	li	a0,-33
800002bc:	01055593          	srli	a1,a0,0x10
800002c0:	04b42e23          	sw	a1,92(s0)

800002c4 <inst_46>:
800002c4:	fbf00513          	li	a0,-65
800002c8:	00855593          	srli	a1,a0,0x8
800002cc:	06b42023          	sw	a1,96(s0)

800002d0 <inst_47>:
800002d0:	f7f00513          	li	a0,-129
800002d4:	01255593          	srli	a1,a0,0x12
800002d8:	06b42223          	sw	a1,100(s0)

800002dc <inst_48>:
800002dc:	eff00513          	li	a0,-257
800002e0:	00355593          	srli	a1,a0,0x3
800002e4:	06b42423          	sw	a1,104(s0)

800002e8 <inst_49>:
800002e8:	dff00513          	li	a0,-513
800002ec:	01355593          	srli	a1,a0,0x13
800002f0:	06b42623          	sw	a1,108(s0)

800002f4 <inst_50>:
800002f4:	bff00513          	li	a0,-1025
800002f8:	00955593          	srli	a1,a0,0x9
800002fc:	06b42823          	sw	a1,112(s0)

80000300 <inst_51>:
80000300:	fffff537          	lui	a0,0xfffff
80000304:	7ff50513          	addi	a0,a0,2047 # fffff7ff <edge2+0xfffff800>
80000308:	00755593          	srli	a1,a0,0x7
8000030c:	06b42a23          	sw	a1,116(s0)

80000310 <inst_52>:
80000310:	fffff537          	lui	a0,0xfffff
80000314:	fff50513          	addi	a0,a0,-1 # ffffefff <edge2+0xfffff000>
80000318:	00055593          	srli	a1,a0,0x0
8000031c:	06b42c23          	sw	a1,120(s0)

80000320 <inst_53>:
80000320:	ffffe537          	lui	a0,0xffffe
80000324:	fff50513          	addi	a0,a0,-1 # ffffdfff <edge2+0xffffe000>
80000328:	00e55593          	srli	a1,a0,0xe
8000032c:	06b42e23          	sw	a1,124(s0)

80000330 <inst_54>:
80000330:	ffffc537          	lui	a0,0xffffc
80000334:	fff50513          	addi	a0,a0,-1 # ffffbfff <edge2+0xffffc000>
80000338:	00155593          	srli	a1,a0,0x1
8000033c:	08b42023          	sw	a1,128(s0)

80000340 <inst_55>:
80000340:	ffff8537          	lui	a0,0xffff8
80000344:	fff50513          	addi	a0,a0,-1 # ffff7fff <edge2+0xffff8000>
80000348:	01d55593          	srli	a1,a0,0x1d
8000034c:	08b42223          	sw	a1,132(s0)

80000350 <inst_56>:
80000350:	ffff0537          	lui	a0,0xffff0
80000354:	fff50513          	addi	a0,a0,-1 # fffeffff <edge2+0xffff0000>
80000358:	00955593          	srli	a1,a0,0x9
8000035c:	08b42423          	sw	a1,136(s0)

80000360 <inst_57>:
80000360:	fffe0537          	lui	a0,0xfffe0
80000364:	fff50513          	addi	a0,a0,-1 # fffdffff <edge2+0xfffe0000>
80000368:	00755593          	srli	a1,a0,0x7
8000036c:	08b42623          	sw	a1,140(s0)

80000370 <inst_58>:
80000370:	fffc0537          	lui	a0,0xfffc0
80000374:	fff50513          	addi	a0,a0,-1 # fffbffff <edge2+0xfffc0000>
80000378:	01355593          	srli	a1,a0,0x13
8000037c:	08b42823          	sw	a1,144(s0)

80000380 <inst_59>:
80000380:	fff80537          	lui	a0,0xfff80
80000384:	fff50513          	addi	a0,a0,-1 # fff7ffff <edge2+0xfff80000>
80000388:	00f55593          	srli	a1,a0,0xf
8000038c:	08b42a23          	sw	a1,148(s0)

80000390 <inst_60>:
80000390:	fff00537          	lui	a0,0xfff00
80000394:	fff50513          	addi	a0,a0,-1 # ffefffff <edge2+0xfff00000>
80000398:	01055593          	srli	a1,a0,0x10
8000039c:	08b42c23          	sw	a1,152(s0)

800003a0 <inst_61>:
800003a0:	ffe00537          	lui	a0,0xffe00
800003a4:	fff50513          	addi	a0,a0,-1 # ffdfffff <edge2+0xffe00000>
800003a8:	00655593          	srli	a1,a0,0x6
800003ac:	08b42e23          	sw	a1,156(s0)

800003b0 <inst_62>:
800003b0:	ffc00537          	lui	a0,0xffc00
800003b4:	fff50513          	addi	a0,a0,-1 # ffbfffff <edge2+0xffc00000>
800003b8:	00855593          	srli	a1,a0,0x8
800003bc:	0ab42023          	sw	a1,160(s0)

800003c0 <inst_63>:
800003c0:	ff800537          	lui	a0,0xff800
800003c4:	fff50513          	addi	a0,a0,-1 # ff7fffff <edge2+0xff800000>
800003c8:	00a55593          	srli	a1,a0,0xa
800003cc:	0ab42223          	sw	a1,164(s0)

800003d0 <inst_64>:
800003d0:	ff000537          	lui	a0,0xff000
800003d4:	fff50513          	addi	a0,a0,-1 # feffffff <edge2+0xff000000>
800003d8:	00b55593          	srli	a1,a0,0xb
800003dc:	0ab42423          	sw	a1,168(s0)

800003e0 <inst_65>:
800003e0:	fe000537          	lui	a0,0xfe000
800003e4:	fff50513          	addi	a0,a0,-1 # fdffffff <edge2+0xfe000000>
800003e8:	00155593          	srli	a1,a0,0x1
800003ec:	0ab42623          	sw	a1,172(s0)

800003f0 <inst_66>:
800003f0:	fc000537          	lui	a0,0xfc000
800003f4:	fff50513          	addi	a0,a0,-1 # fbffffff <edge2+0xfc000000>
800003f8:	01555593          	srli	a1,a0,0x15
800003fc:	0ab42823          	sw	a1,176(s0)

80000400 <inst_67>:
80000400:	f8000537          	lui	a0,0xf8000
80000404:	fff50513          	addi	a0,a0,-1 # f7ffffff <edge2+0xf8000000>
80000408:	01555593          	srli	a1,a0,0x15
8000040c:	0ab42a23          	sw	a1,180(s0)

80000410 <inst_68>:
80000410:	f0000537          	lui	a0,0xf0000
80000414:	fff50513          	addi	a0,a0,-1 # efffffff <edge2+0xf0000000>
80000418:	00e55593          	srli	a1,a0,0xe
8000041c:	0ab42c23          	sw	a1,184(s0)

80000420 <inst_69>:
80000420:	e0000537          	lui	a0,0xe0000
80000424:	fff50513          	addi	a0,a0,-1 # dfffffff <edge2+0xe0000000>
80000428:	00255593          	srli	a1,a0,0x2
8000042c:	0ab42e23          	sw	a1,188(s0)

80000430 <inst_70>:
80000430:	c0000537          	lui	a0,0xc0000
80000434:	fff50513          	addi	a0,a0,-1 # bfffffff <edge2+0xc0000000>
80000438:	01255593          	srli	a1,a0,0x12
8000043c:	0cb42023          	sw	a1,192(s0)

80000440 <inst_71>:
80000440:	55555537          	lui	a0,0x55555
80000444:	55550513          	addi	a0,a0,1365 # 55555555 <offset+0x55555445>
80000448:	01355593          	srli	a1,a0,0x13
8000044c:	0cb42223          	sw	a1,196(s0)

80000450 <inst_72>:
80000450:	aaaab537          	lui	a0,0xaaaab
80000454:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <edge2+0xaaaaaaab>
80000458:	00c55593          	srli	a1,a0,0xc
8000045c:	0cb42423          	sw	a1,200(s0)

80000460 <inst_73>:
80000460:	00500513          	li	a0,5
80000464:	00355593          	srli	a1,a0,0x3
80000468:	0cb42623          	sw	a1,204(s0)

8000046c <inst_74>:
8000046c:	66666537          	lui	a0,0x66666
80000470:	66750513          	addi	a0,a0,1639 # 66666667 <offset+0x66666557>
80000474:	01755593          	srli	a1,a0,0x17
80000478:	0cb42823          	sw	a1,208(s0)

8000047c <inst_75>:
8000047c:	ffff5537          	lui	a0,0xffff5
80000480:	afd50513          	addi	a0,a0,-1283 # ffff4afd <edge2+0xffff4afe>
80000484:	00a55593          	srli	a1,a0,0xa
80000488:	0cb42a23          	sw	a1,212(s0)

8000048c <inst_76>:
8000048c:	0000b537          	lui	a0,0xb
80000490:	50550513          	addi	a0,a0,1285 # b505 <offset+0xb3f5>
80000494:	00d55593          	srli	a1,a0,0xd
80000498:	0cb42c23          	sw	a1,216(s0)

8000049c <inst_77>:
8000049c:	33333537          	lui	a0,0x33333
800004a0:	33350513          	addi	a0,a0,819 # 33333333 <offset+0x33333223>
800004a4:	00c55593          	srli	a1,a0,0xc
800004a8:	0cb42e23          	sw	a1,220(s0)

800004ac <inst_78>:
800004ac:	66666537          	lui	a0,0x66666
800004b0:	66650513          	addi	a0,a0,1638 # 66666666 <offset+0x66666556>
800004b4:	01555593          	srli	a1,a0,0x15
800004b8:	0eb42023          	sw	a1,224(s0)

800004bc <inst_79>:
800004bc:	0000b537          	lui	a0,0xb
800004c0:	50450513          	addi	a0,a0,1284 # b504 <offset+0xb3f4>
800004c4:	00f55593          	srli	a1,a0,0xf
800004c8:	0eb42223          	sw	a1,228(s0)

800004cc <inst_80>:
800004cc:	55555537          	lui	a0,0x55555
800004d0:	55450513          	addi	a0,a0,1364 # 55555554 <offset+0x55555444>
800004d4:	01d55593          	srli	a1,a0,0x1d
800004d8:	0eb42423          	sw	a1,232(s0)

800004dc <inst_81>:
800004dc:	33333537          	lui	a0,0x33333
800004e0:	33250513          	addi	a0,a0,818 # 33333332 <offset+0x33333222>
800004e4:	01b55593          	srli	a1,a0,0x1b
800004e8:	0eb42623          	sw	a1,236(s0)

800004ec <inst_82>:
800004ec:	66666537          	lui	a0,0x66666
800004f0:	66550513          	addi	a0,a0,1637 # 66666665 <offset+0x66666555>
800004f4:	00955593          	srli	a1,a0,0x9
800004f8:	0eb42823          	sw	a1,240(s0)

800004fc <inst_83>:
800004fc:	0000b537          	lui	a0,0xb
80000500:	50350513          	addi	a0,a0,1283 # b503 <offset+0xb3f3>
80000504:	01255593          	srli	a1,a0,0x12
80000508:	0eb42a23          	sw	a1,244(s0)

8000050c <inst_84>:
8000050c:	55555537          	lui	a0,0x55555
80000510:	55650513          	addi	a0,a0,1366 # 55555556 <offset+0x55555446>
80000514:	00f55593          	srli	a1,a0,0xf
80000518:	0eb42c23          	sw	a1,248(s0)

8000051c <inst_85>:
8000051c:	aaaab537          	lui	a0,0xaaaab
80000520:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <edge2+0xaaaaaaac>
80000524:	01d55593          	srli	a1,a0,0x1d
80000528:	0eb42e23          	sw	a1,252(s0)

8000052c <inst_86>:
8000052c:	00600513          	li	a0,6
80000530:	01f55593          	srli	a1,a0,0x1f
80000534:	10b42023          	sw	a1,256(s0)

80000538 <inst_87>:
80000538:	33333537          	lui	a0,0x33333
8000053c:	33450513          	addi	a0,a0,820 # 33333334 <offset+0x33333224>
80000540:	00655593          	srli	a1,a0,0x6
80000544:	10b42223          	sw	a1,260(s0)

80000548 <inst_88>:
80000548:	00300513          	li	a0,3
8000054c:	00355593          	srli	a1,a0,0x3
80000550:	10b42423          	sw	a1,264(s0)

80000554 <inst_89>:
80000554:	80000537          	lui	a0,0x80000
80000558:	00955593          	srli	a1,a0,0x9
8000055c:	10b42623          	sw	a1,268(s0)

80000560 <cleanup_epilogs>:
80000560:	0040006f          	j	80000564 <exit_cleanup>

80000564 <exit_cleanup>:
80000564:	00100093          	li	ra,1

80000568 <write_tohost>:
80000568:	00001f17          	auipc	t5,0x1
8000056c:	a81f2c23          	sw	ra,-1384(t5) # 80001000 <tohost>
80000570:	ff9ff06f          	j	80000568 <write_tohost>
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
80002020:	deadbeef          	jal	t4,7ffdd60a <offset+0x7ffdd4fa>
80002024:	deadbeef          	jal	t4,7ffdd60e <offset+0x7ffdd4fe>

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

80003114 <signature_x5_0>:
80003114:	deadbeef          	jal	t4,7ffde6fe <offset+0x7ffde5ee>
80003118:	deadbeef          	jal	t4,7ffde702 <offset+0x7ffde5f2>
8000311c:	deadbeef          	jal	t4,7ffde706 <offset+0x7ffde5f6>
80003120:	deadbeef          	jal	t4,7ffde70a <offset+0x7ffde5fa>
80003124:	deadbeef          	jal	t4,7ffde70e <offset+0x7ffde5fe>
80003128:	deadbeef          	jal	t4,7ffde712 <offset+0x7ffde602>
8000312c:	deadbeef          	jal	t4,7ffde716 <offset+0x7ffde606>
80003130:	deadbeef          	jal	t4,7ffde71a <offset+0x7ffde60a>
80003134:	deadbeef          	jal	t4,7ffde71e <offset+0x7ffde60e>
80003138:	deadbeef          	jal	t4,7ffde722 <offset+0x7ffde612>
8000313c:	deadbeef          	jal	t4,7ffde726 <offset+0x7ffde616>
80003140:	deadbeef          	jal	t4,7ffde72a <offset+0x7ffde61a>
80003144:	deadbeef          	jal	t4,7ffde72e <offset+0x7ffde61e>
80003148:	deadbeef          	jal	t4,7ffde732 <offset+0x7ffde622>
8000314c:	deadbeef          	jal	t4,7ffde736 <offset+0x7ffde626>
80003150:	deadbeef          	jal	t4,7ffde73a <offset+0x7ffde62a>
80003154:	deadbeef          	jal	t4,7ffde73e <offset+0x7ffde62e>
80003158:	deadbeef          	jal	t4,7ffde742 <offset+0x7ffde632>
8000315c:	deadbeef          	jal	t4,7ffde746 <offset+0x7ffde636>
80003160:	deadbeef          	jal	t4,7ffde74a <offset+0x7ffde63a>
80003164:	deadbeef          	jal	t4,7ffde74e <offset+0x7ffde63e>
80003168:	deadbeef          	jal	t4,7ffde752 <offset+0x7ffde642>

8000316c <signature_x8_0>:
8000316c:	deadbeef          	jal	t4,7ffde756 <offset+0x7ffde646>
80003170:	deadbeef          	jal	t4,7ffde75a <offset+0x7ffde64a>
80003174:	deadbeef          	jal	t4,7ffde75e <offset+0x7ffde64e>
80003178:	deadbeef          	jal	t4,7ffde762 <offset+0x7ffde652>
8000317c:	deadbeef          	jal	t4,7ffde766 <offset+0x7ffde656>
80003180:	deadbeef          	jal	t4,7ffde76a <offset+0x7ffde65a>
80003184:	deadbeef          	jal	t4,7ffde76e <offset+0x7ffde65e>
80003188:	deadbeef          	jal	t4,7ffde772 <offset+0x7ffde662>
8000318c:	deadbeef          	jal	t4,7ffde776 <offset+0x7ffde666>
80003190:	deadbeef          	jal	t4,7ffde77a <offset+0x7ffde66a>
80003194:	deadbeef          	jal	t4,7ffde77e <offset+0x7ffde66e>
80003198:	deadbeef          	jal	t4,7ffde782 <offset+0x7ffde672>
8000319c:	deadbeef          	jal	t4,7ffde786 <offset+0x7ffde676>
800031a0:	deadbeef          	jal	t4,7ffde78a <offset+0x7ffde67a>
800031a4:	deadbeef          	jal	t4,7ffde78e <offset+0x7ffde67e>
800031a8:	deadbeef          	jal	t4,7ffde792 <offset+0x7ffde682>
800031ac:	deadbeef          	jal	t4,7ffde796 <offset+0x7ffde686>
800031b0:	deadbeef          	jal	t4,7ffde79a <offset+0x7ffde68a>
800031b4:	deadbeef          	jal	t4,7ffde79e <offset+0x7ffde68e>
800031b8:	deadbeef          	jal	t4,7ffde7a2 <offset+0x7ffde692>
800031bc:	deadbeef          	jal	t4,7ffde7a6 <offset+0x7ffde696>
800031c0:	deadbeef          	jal	t4,7ffde7aa <offset+0x7ffde69a>
800031c4:	deadbeef          	jal	t4,7ffde7ae <offset+0x7ffde69e>
800031c8:	deadbeef          	jal	t4,7ffde7b2 <offset+0x7ffde6a2>
800031cc:	deadbeef          	jal	t4,7ffde7b6 <offset+0x7ffde6a6>
800031d0:	deadbeef          	jal	t4,7ffde7ba <offset+0x7ffde6aa>
800031d4:	deadbeef          	jal	t4,7ffde7be <offset+0x7ffde6ae>
800031d8:	deadbeef          	jal	t4,7ffde7c2 <offset+0x7ffde6b2>
800031dc:	deadbeef          	jal	t4,7ffde7c6 <offset+0x7ffde6b6>
800031e0:	deadbeef          	jal	t4,7ffde7ca <offset+0x7ffde6ba>
800031e4:	deadbeef          	jal	t4,7ffde7ce <offset+0x7ffde6be>
800031e8:	deadbeef          	jal	t4,7ffde7d2 <offset+0x7ffde6c2>
800031ec:	deadbeef          	jal	t4,7ffde7d6 <offset+0x7ffde6c6>
800031f0:	deadbeef          	jal	t4,7ffde7da <offset+0x7ffde6ca>
800031f4:	deadbeef          	jal	t4,7ffde7de <offset+0x7ffde6ce>
800031f8:	deadbeef          	jal	t4,7ffde7e2 <offset+0x7ffde6d2>
800031fc:	deadbeef          	jal	t4,7ffde7e6 <offset+0x7ffde6d6>
80003200:	deadbeef          	jal	t4,7ffde7ea <offset+0x7ffde6da>
80003204:	deadbeef          	jal	t4,7ffde7ee <offset+0x7ffde6de>
80003208:	deadbeef          	jal	t4,7ffde7f2 <offset+0x7ffde6e2>
8000320c:	deadbeef          	jal	t4,7ffde7f6 <offset+0x7ffde6e6>
80003210:	deadbeef          	jal	t4,7ffde7fa <offset+0x7ffde6ea>
80003214:	deadbeef          	jal	t4,7ffde7fe <offset+0x7ffde6ee>
80003218:	deadbeef          	jal	t4,7ffde802 <offset+0x7ffde6f2>
8000321c:	deadbeef          	jal	t4,7ffde806 <offset+0x7ffde6f6>
80003220:	deadbeef          	jal	t4,7ffde80a <offset+0x7ffde6fa>
80003224:	deadbeef          	jal	t4,7ffde80e <offset+0x7ffde6fe>
80003228:	deadbeef          	jal	t4,7ffde812 <offset+0x7ffde702>
8000322c:	deadbeef          	jal	t4,7ffde816 <offset+0x7ffde706>
80003230:	deadbeef          	jal	t4,7ffde81a <offset+0x7ffde70a>
80003234:	deadbeef          	jal	t4,7ffde81e <offset+0x7ffde70e>
80003238:	deadbeef          	jal	t4,7ffde822 <offset+0x7ffde712>
8000323c:	deadbeef          	jal	t4,7ffde826 <offset+0x7ffde716>
80003240:	deadbeef          	jal	t4,7ffde82a <offset+0x7ffde71a>
80003244:	deadbeef          	jal	t4,7ffde82e <offset+0x7ffde71e>
80003248:	deadbeef          	jal	t4,7ffde832 <offset+0x7ffde722>
8000324c:	deadbeef          	jal	t4,7ffde836 <offset+0x7ffde726>
80003250:	deadbeef          	jal	t4,7ffde83a <offset+0x7ffde72a>
80003254:	deadbeef          	jal	t4,7ffde83e <offset+0x7ffde72e>
80003258:	deadbeef          	jal	t4,7ffde842 <offset+0x7ffde732>
8000325c:	deadbeef          	jal	t4,7ffde846 <offset+0x7ffde736>
80003260:	deadbeef          	jal	t4,7ffde84a <offset+0x7ffde73a>
80003264:	deadbeef          	jal	t4,7ffde84e <offset+0x7ffde73e>
80003268:	deadbeef          	jal	t4,7ffde852 <offset+0x7ffde742>
8000326c:	deadbeef          	jal	t4,7ffde856 <offset+0x7ffde746>
80003270:	deadbeef          	jal	t4,7ffde85a <offset+0x7ffde74a>
80003274:	deadbeef          	jal	t4,7ffde85e <offset+0x7ffde74e>
80003278:	deadbeef          	jal	t4,7ffde862 <offset+0x7ffde752>

8000327c <sig_end_canary>:
8000327c:	a309                	j	8000377e <_end+0x4fe>
8000327e:	6f5c                	flw	fa5,28(a4)

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
   0:	000002bf 00750003 	0x750003000002bf
   8:	0000                	unimp
   a:	0101                	addi	sp,sp,0
   c:	000d0efb          	0xd0efb
  10:	0101                	addi	sp,sp,0
  12:	0101                	addi	sp,sp,0
  14:	0000                	unimp
  16:	0100                	addi	s0,sp,128
  18:	0000                	unimp
  1a:	2f01                	jal	72a <offset+0x61a>
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
  44:	612d7663          	bgeu	s10,s2,650 <offset+0x540>
  48:	6372                	flw	ft6,28(sp)
  4a:	2d68                	fld	fa0,216(a0)
  4c:	6574                	flw	fa3,76(a0)
  4e:	722f7473          	csrrci	s0,0x722,30
  52:	7369                	lui	t1,0xffffa
  54:	742d7663          	bgeu	s10,sp,7a0 <offset+0x690>
  58:	7365                	lui	t1,0xffff9
  5a:	2d74                	fld	fa3,216(a0)
  5c:	74697573          	csrrci	a0,0x746,18
  60:	2f65                	jal	818 <offset+0x708>
  62:	7672                	flw	fa2,60(sp)
  64:	5f693233          	0x5f693233
  68:	2f6d                	jal	822 <offset+0x712>
  6a:	2f49                	jal	7fc <offset+0x6ec>
  6c:	00637273          	csrrci	tp,0x6,6
  70:	7300                	flw	fs0,32(a4)
  72:	6c72                	flw	fs8,28(sp)
  74:	2d69                	jal	70e <offset+0x5fe>
  76:	3130                	fld	fa2,96(a0)
  78:	532e                	lw	t1,232(sp)
  7a:	0100                	addi	s0,sp,128
  7c:	0000                	unimp
  7e:	0000                	unimp
  80:	0205                	addi	tp,tp,1
  82:	0000                	unimp
  84:	8000                	0x8000
  86:	03011903          	lh	s2,48(sp) # 10030 <offset+0xff20>
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
  9e:	000c                	0xc
  a0:	0301                	addi	t1,t1,0
  a2:	0905                	addi	s2,s2,1
  a4:	0010                	0x10
  a6:	0301                	addi	t1,t1,0
  a8:	0905                	addi	s2,s2,1
  aa:	0010                	0x10
  ac:	0301                	addi	t1,t1,0
  ae:	0905                	addi	s2,s2,1
  b0:	000c                	0xc
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
 10a:	000c                	0xc
 10c:	0301                	addi	t1,t1,0
 10e:	0905                	addi	s2,s2,1
 110:	0010                	0x10
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
 1be:	000c                	0xc
 1c0:	0301                	addi	t1,t1,0
 1c2:	0905                	addi	s2,s2,1
 1c4:	000c                	0xc
 1c6:	0301                	addi	t1,t1,0
 1c8:	0905                	addi	s2,s2,1
 1ca:	000c                	0xc
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
 236:	0010                	0x10
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
 254:	000c                	0xc
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
 290:	0010                	0x10
 292:	0301                	addi	t1,t1,0
 294:	0905                	addi	s2,s2,1
 296:	0010                	0x10
 298:	0301                	addi	t1,t1,0
 29a:	0905                	addi	s2,s2,1
 29c:	0010                	0x10
 29e:	0301                	addi	t1,t1,0
 2a0:	0905                	addi	s2,s2,1
 2a2:	000c                	0xc
 2a4:	0301                	addi	t1,t1,0
 2a6:	0905                	addi	s2,s2,1
 2a8:	0010                	0x10
 2aa:	0301                	addi	t1,t1,0
 2ac:	0905                	addi	s2,s2,1
 2ae:	000c                	0xc
 2b0:	0301                	addi	t1,t1,0
 2b2:	0904                	addi	s1,sp,144
 2b4:	000c                	0xc
 2b6:	0301                	addi	t1,t1,0
 2b8:	0901                	addi	s2,s2,0
 2ba:	0004                	0x4
 2bc:	0901                	addi	s2,s2,0
 2be:	0010                	0x10
 2c0:	0100                	addi	s0,sp,128
 2c2:	01              	Address 0x00000000000002c2 is out of bounds.


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
  14:	0574                	addi	a3,sp,652
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
  14:	0574                	addi	a3,sp,652
	...

Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	6d6f682f          	0x6d6f682f
   4:	2f65                	jal	7bc <offset+0x6ac>
   6:	6f6c                	flw	fa1,92(a4)
   8:	6976                	flw	fs2,92(sp)
   a:	65442f73          	csrrs	t5,0x654,s0
   e:	6f746b73          	csrrsi	s6,0x6f7,8
  12:	2f70                	fld	fa2,216(a4)
  14:	6952                	flw	fs2,20(sp)
  16:	6556                	flw	fa0,84(sp)
  18:	5f72                	lw	t5,60(sp)
  1a:	65726f63          	bltu	tp,s7,678 <offset+0x568>
  1e:	7369722f          	0x7369722f
  22:	2f666f63          	bltu	a2,s6,320 <offset+0x210>
  26:	6972                	flw	fs2,28(sp)
  28:	2d766373          	csrrsi	t1,0x2d7,12
  2c:	7261                	lui	tp,0xffff8
  2e:	742d6863          	bltu	s10,sp,77e <offset+0x66e>
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
  58:	2d69                	jal	6f2 <offset+0x5e2>
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
  88:	5f666f63          	bltu	a2,s6,686 <offset+0x576>
  8c:	6b726f77          	0x6b726f77
  90:	3376722f          	0x3376722f
  94:	6932                	flw	fs2,12(sp)
  96:	6d5f 492f 732f      	0x732f492f6d5f
  9c:	6372                	flw	ft6,28(sp)
  9e:	6c72732f          	0x6c72732f
  a2:	2d69                	jal	73c <offset+0x62c>
  a4:	3130                	fld	fa2,96(a0)
  a6:	532e                	lw	t1,232(sp)
  a8:	7475642f          	0x7475642f
  ac:	4700                	lw	s0,8(a4)
  ae:	554e                	lw	a0,240(sp)
  b0:	4120                	lw	s0,64(a0)
  b2:	2e322053          	0x2e322053
  b6:	          	snez	a0,zero
