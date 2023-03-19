
my.elf:     file format elf32-littleriscv


Disassembly of section .text.init:

80000000 <rvtest_entry_point>:
80000000:	feedc0b7          	lui	ra,0xfeedc
80000004:	ead08093          	addi	ra,ra,-339 # feedbead <imm12sh+0xfeedc0d2>
80000008:	ff76e137          	lui	sp,0xff76e
8000000c:	f5610113          	addi	sp,sp,-170 # ff76df56 <imm12sh+0xff76e17b>
80000010:	7fbb71b7          	lui	gp,0x7fbb7
80000014:	fab18193          	addi	gp,gp,-85 # 7fbb6fab <absimmsh+0x25f71d0>
80000018:	bfddb237          	lui	tp,0xbfddb
8000001c:	7d520213          	addi	tp,tp,2005 # bfddb7d5 <imm12sh+0xbfddb9fa>
80000020:	00000297          	auipc	t0,0x0
80000024:	05828293          	addi	t0,t0,88 # 80000078 <rvtest_code_begin>
80000028:	00002317          	auipc	t1,0x2
8000002c:	fe830313          	addi	t1,t1,-24 # 80002010 <rvtest_data_begin>
80000030:	b7fbb3b7          	lui	t2,0xb7fbb
80000034:	6fa38393          	addi	t2,t2,1786 # b7fbb6fa <imm12sh+0xb7fbb91f>
80000038:	5bfde437          	lui	s0,0x5bfde
8000003c:	b7d40413          	addi	s0,s0,-1155 # 5bfddb7d <absimm+0x56b5d734>
80000040:	adfef4b7          	lui	s1,0xadfef
80000044:	dbe48493          	addi	s1,s1,-578 # adfeedbe <imm12sh+0xadfeefe3>
80000048:	56ff7537          	lui	a0,0x56ff7
8000004c:	6df50513          	addi	a0,a0,1759 # 56ff76df <absimm+0x51b77296>
80000050:	ab7fc5b7          	lui	a1,0xab7fc
80000054:	b6f58593          	addi	a1,a1,-1169 # ab7fbb6f <imm12sh+0xab7fbd94>
80000058:	d5bfe637          	lui	a2,0xd5bfe
8000005c:	db760613          	addi	a2,a2,-585 # d5bfddb7 <imm12sh+0xd5bfdfdc>
80000060:	eadff6b7          	lui	a3,0xeadff
80000064:	edb68693          	addi	a3,a3,-293 # eadfeedb <imm12sh+0xeadff100>
80000068:	f56ff737          	lui	a4,0xf56ff
8000006c:	76d70713          	addi	a4,a4,1901 # f56ff76d <imm12sh+0xf56ff992>
80000070:	fab807b7          	lui	a5,0xfab80
80000074:	bb678793          	addi	a5,a5,-1098 # fab7fbb6 <imm12sh+0xfab7fddb>

80000078 <rvtest_code_begin>:
80000078:	00003597          	auipc	a1,0x3
8000007c:	09c58593          	addi	a1,a1,156 # 80003114 <signature_x11_0>

80000080 <inst_0>:
80000080:	00000617          	auipc	a2,0x0
80000084:	00860613          	addi	a2,a2,8 # 80000088 <inst_0+0x8>
80000088:	00000a17          	auipc	s4,0x0
8000008c:	40ca0a33          	sub	s4,s4,a2
80000090:	0145a023          	sw	s4,0(a1)

80000094 <inst_1>:
80000094:	00000617          	auipc	a2,0x0
80000098:	00860613          	addi	a2,a2,8 # 8000009c <inst_1+0x8>
8000009c:	0000e897          	auipc	a7,0xe
800000a0:	40c888b3          	sub	a7,a7,a2
800000a4:	0115a223          	sw	a7,4(a1)

800000a8 <inst_2>:
800000a8:	00000617          	auipc	a2,0x0
800000ac:	00860613          	addi	a2,a2,8 # 800000b0 <inst_2+0x8>
800000b0:	fffff217          	auipc	tp,0xfffff
800000b4:	40c20233          	sub	tp,tp,a2
800000b8:	0045a423          	sw	tp,8(a1)

800000bc <inst_3>:
800000bc:	00000617          	auipc	a2,0x0
800000c0:	00860613          	addi	a2,a2,8 # 800000c4 <inst_3+0x8>
800000c4:	00003c17          	auipc	s8,0x3
800000c8:	40cc0c33          	sub	s8,s8,a2
800000cc:	0185a623          	sw	s8,12(a1)

800000d0 <inst_4>:
800000d0:	00000617          	auipc	a2,0x0
800000d4:	00860613          	addi	a2,a2,8 # 800000d8 <inst_4+0x8>
800000d8:	55555a97          	auipc	s5,0x55555
800000dc:	40ca8ab3          	sub	s5,s5,a2
800000e0:	0155a823          	sw	s5,16(a1)

800000e4 <inst_5>:
800000e4:	00000617          	auipc	a2,0x0
800000e8:	00860613          	addi	a2,a2,8 # 800000ec <inst_5+0x8>
800000ec:	aaaaa417          	auipc	s0,0xaaaaa
800000f0:	40c40433          	sub	s0,s0,a2
800000f4:	0085aa23          	sw	s0,20(a1)

800000f8 <inst_6>:
800000f8:	00000617          	auipc	a2,0x0
800000fc:	00860613          	addi	a2,a2,8 # 80000100 <inst_6+0x8>
80000100:	00005717          	auipc	a4,0x5
80000104:	40c70733          	sub	a4,a4,a2
80000108:	00e5ac23          	sw	a4,24(a1)

8000010c <inst_7>:
8000010c:	00000617          	auipc	a2,0x0
80000110:	00860613          	addi	a2,a2,8 # 80000114 <inst_7+0x8>
80000114:	33333d17          	auipc	s10,0x33333
80000118:	40cd0d33          	sub	s10,s10,a2
8000011c:	01a5ae23          	sw	s10,28(a1)

80000120 <inst_8>:
80000120:	00000617          	auipc	a2,0x0
80000124:	00860613          	addi	a2,a2,8 # 80000128 <inst_8+0x8>
80000128:	66666497          	auipc	s1,0x66666
8000012c:	40c484b3          	sub	s1,s1,a2
80000130:	0295a023          	sw	s1,32(a1)

80000134 <inst_9>:
80000134:	00000617          	auipc	a2,0x0
80000138:	00860613          	addi	a2,a2,8 # 8000013c <inst_9+0x8>
8000013c:	002d4797          	auipc	a5,0x2d4
80000140:	40c787b3          	sub	a5,a5,a2
80000144:	02f5a223          	sw	a5,36(a1)

80000148 <inst_10>:
80000148:	00000617          	auipc	a2,0x0
8000014c:	00860613          	addi	a2,a2,8 # 80000150 <inst_10+0x8>
80000150:	003ff917          	auipc	s2,0x3ff
80000154:	40c90933          	sub	s2,s2,a2
80000158:	0325a423          	sw	s2,40(a1)

8000015c <inst_11>:
8000015c:	00000617          	auipc	a2,0x0
80000160:	00860613          	addi	a2,a2,8 # 80000164 <inst_11+0x8>
80000164:	00002517          	auipc	a0,0x2
80000168:	40c50533          	sub	a0,a0,a2
8000016c:	02a5a623          	sw	a0,44(a1)

80000170 <inst_12>:
80000170:	00000617          	auipc	a2,0x0
80000174:	00860613          	addi	a2,a2,8 # 80000178 <inst_12+0x8>
80000178:	55554397          	auipc	t2,0x55554
8000017c:	40c383b3          	sub	t2,t2,a2
80000180:	0275a823          	sw	t2,48(a1)

80000184 <inst_13>:
80000184:	00000617          	auipc	a2,0x0
80000188:	00860613          	addi	a2,a2,8 # 8000018c <inst_13+0x8>
8000018c:	aaaa9097          	auipc	ra,0xaaaa9
80000190:	40c080b3          	sub	ra,ra,a2
80000194:	0215aa23          	sw	ra,52(a1)

80000198 <inst_14>:
80000198:	00000617          	auipc	a2,0x0
8000019c:	00860613          	addi	a2,a2,8 # 800001a0 <inst_14+0x8>
800001a0:	00004c97          	auipc	s9,0x4
800001a4:	40cc8cb3          	sub	s9,s9,a2
800001a8:	0395ac23          	sw	s9,56(a1)

800001ac <inst_15>:
800001ac:	00000617          	auipc	a2,0x0
800001b0:	00860613          	addi	a2,a2,8 # 800001b4 <inst_15+0x8>
800001b4:	33332b97          	auipc	s7,0x33332
800001b8:	40cb8bb3          	sub	s7,s7,a2
800001bc:	0375ae23          	sw	s7,60(a1)

800001c0 <inst_16>:
800001c0:	00000617          	auipc	a2,0x0
800001c4:	00860613          	addi	a2,a2,8 # 800001c8 <inst_16+0x8>
800001c8:	66665f97          	auipc	t6,0x66665
800001cc:	40cf8fb3          	sub	t6,t6,a2
800001d0:	05f5a023          	sw	t6,64(a1)

800001d4 <inst_17>:
800001d4:	00000617          	auipc	a2,0x0
800001d8:	00860613          	addi	a2,a2,8 # 800001dc <inst_17+0x8>
800001dc:	002d3297          	auipc	t0,0x2d3
800001e0:	40c282b3          	sub	t0,t0,a2
800001e4:	0455a223          	sw	t0,68(a1)

800001e8 <inst_18>:
800001e8:	00000617          	auipc	a2,0x0
800001ec:	00860613          	addi	a2,a2,8 # 800001f0 <inst_18+0x8>
800001f0:	003feb17          	auipc	s6,0x3fe
800001f4:	40cb0b33          	sub	s6,s6,a2
800001f8:	0565a423          	sw	s6,72(a1)

800001fc <inst_19>:
800001fc:	00000617          	auipc	a2,0x0
80000200:	00860613          	addi	a2,a2,8 # 80000204 <inst_19+0x8>
80000204:	55556197          	auipc	gp,0x55556
80000208:	40c181b3          	sub	gp,gp,a2
8000020c:	0435a623          	sw	gp,76(a1)

80000210 <inst_20>:
80000210:	00000617          	auipc	a2,0x0
80000214:	00860613          	addi	a2,a2,8 # 80000218 <inst_20+0x8>
80000218:	aaaabf17          	auipc	t5,0xaaaab
8000021c:	40cf0f33          	sub	t5,t5,a2
80000220:	05e5a823          	sw	t5,80(a1)

80000224 <inst_21>:
80000224:	00000617          	auipc	a2,0x0
80000228:	00860613          	addi	a2,a2,8 # 8000022c <inst_21+0x8>
8000022c:	00006017          	auipc	zero,0x6
80000230:	40c00033          	neg	zero,a2
80000234:	0405aa23          	sw	zero,84(a1)

80000238 <inst_22>:
80000238:	00000617          	auipc	a2,0x0
8000023c:	00860613          	addi	a2,a2,8 # 80000240 <inst_22+0x8>
80000240:	33334817          	auipc	a6,0x33334
80000244:	40c80833          	sub	a6,a6,a2
80000248:	0505ac23          	sw	a6,88(a1)

8000024c <inst_23>:
8000024c:	00000617          	auipc	a2,0x0
80000250:	00860613          	addi	a2,a2,8 # 80000254 <inst_23+0x8>
80000254:	66667997          	auipc	s3,0x66667
80000258:	40c989b3          	sub	s3,s3,a2
8000025c:	0535ae23          	sw	s3,92(a1)

80000260 <inst_24>:
80000260:	00000617          	auipc	a2,0x0
80000264:	00860613          	addi	a2,a2,8 # 80000268 <inst_24+0x8>
80000268:	002d5e97          	auipc	t4,0x2d5
8000026c:	40ce8eb3          	sub	t4,t4,a2
80000270:	07d5a023          	sw	t4,96(a1)

80000274 <inst_25>:
80000274:	00000617          	auipc	a2,0x0
80000278:	00860613          	addi	a2,a2,8 # 8000027c <inst_25+0x8>
8000027c:	00001317          	auipc	t1,0x1
80000280:	40c30333          	sub	t1,t1,a2
80000284:	0665a223          	sw	t1,100(a1)

80000288 <inst_26>:
80000288:	00000617          	auipc	a2,0x0
8000028c:	00860613          	addi	a2,a2,8 # 80000290 <inst_26+0x8>
80000290:	00400e17          	auipc	t3,0x400
80000294:	40ce0e33          	sub	t3,t3,a2
80000298:	07c5a423          	sw	t3,104(a1)

8000029c <inst_27>:
8000029c:	00000617          	auipc	a2,0x0
800002a0:	00860613          	addi	a2,a2,8 # 800002a4 <inst_27+0x8>
800002a4:	00008117          	auipc	sp,0x8
800002a8:	40c10133          	sub	sp,sp,a2
800002ac:	0625a623          	sw	sp,108(a1)

800002b0 <inst_28>:
800002b0:	00000117          	auipc	sp,0x0
800002b4:	00810113          	addi	sp,sp,8 # 800002b8 <inst_28+0x8>
800002b8:	00010d97          	auipc	s11,0x10
800002bc:	402d8db3          	sub	s11,s11,sp
800002c0:	07b5a823          	sw	s11,112(a1)
800002c4:	00003097          	auipc	ra,0x3
800002c8:	ec408093          	addi	ra,ra,-316 # 80003188 <signature_x1_0>

800002cc <inst_29>:
800002cc:	00000117          	auipc	sp,0x0
800002d0:	00810113          	addi	sp,sp,8 # 800002d4 <inst_29+0x8>
800002d4:	00020697          	auipc	a3,0x20
800002d8:	402686b3          	sub	a3,a3,sp
800002dc:	00d0a023          	sw	a3,0(ra)

800002e0 <inst_30>:
800002e0:	00000117          	auipc	sp,0x0
800002e4:	00810113          	addi	sp,sp,8 # 800002e8 <inst_30+0x8>
800002e8:	00040597          	auipc	a1,0x40
800002ec:	402585b3          	sub	a1,a1,sp
800002f0:	00b0a223          	sw	a1,4(ra)

800002f4 <inst_31>:
800002f4:	00000117          	auipc	sp,0x0
800002f8:	00810113          	addi	sp,sp,8 # 800002fc <inst_31+0x8>
800002fc:	00080617          	auipc	a2,0x80
80000300:	40260633          	sub	a2,a2,sp
80000304:	00c0a423          	sw	a2,8(ra)

80000308 <inst_32>:
80000308:	00000117          	auipc	sp,0x0
8000030c:	00810113          	addi	sp,sp,8 # 80000310 <inst_32+0x8>
80000310:	effff517          	auipc	a0,0xeffff
80000314:	40250533          	sub	a0,a0,sp
80000318:	00a0a623          	sw	a0,12(ra)

8000031c <inst_33>:
8000031c:	00000117          	auipc	sp,0x0
80000320:	00810113          	addi	sp,sp,8 # 80000324 <inst_33+0x8>
80000324:	dffff517          	auipc	a0,0xdffff
80000328:	40250533          	sub	a0,a0,sp
8000032c:	00a0a823          	sw	a0,16(ra)

80000330 <inst_34>:
80000330:	00000117          	auipc	sp,0x0
80000334:	00810113          	addi	sp,sp,8 # 80000338 <inst_34+0x8>
80000338:	bffff517          	auipc	a0,0xbffff
8000033c:	40250533          	sub	a0,a0,sp
80000340:	00a0aa23          	sw	a0,20(ra)

80000344 <inst_35>:
80000344:	00000117          	auipc	sp,0x0
80000348:	00810113          	addi	sp,sp,8 # 8000034c <inst_35+0x8>
8000034c:	7ffff517          	auipc	a0,0x7ffff
80000350:	40250533          	sub	a0,a0,sp
80000354:	00a0ac23          	sw	a0,24(ra)

80000358 <inst_36>:
80000358:	00000117          	auipc	sp,0x0
8000035c:	00810113          	addi	sp,sp,8 # 80000360 <inst_36+0x8>
80000360:	00100517          	auipc	a0,0x100
80000364:	40250533          	sub	a0,a0,sp
80000368:	00a0ae23          	sw	a0,28(ra)

8000036c <inst_37>:
8000036c:	00000117          	auipc	sp,0x0
80000370:	00810113          	addi	sp,sp,8 # 80000374 <inst_37+0x8>
80000374:	00200517          	auipc	a0,0x200
80000378:	40250533          	sub	a0,a0,sp
8000037c:	02a0a023          	sw	a0,32(ra)

80000380 <inst_38>:
80000380:	00000117          	auipc	sp,0x0
80000384:	00810113          	addi	sp,sp,8 # 80000388 <inst_38+0x8>
80000388:	00800517          	auipc	a0,0x800
8000038c:	40250533          	sub	a0,a0,sp
80000390:	02a0a223          	sw	a0,36(ra)

80000394 <inst_39>:
80000394:	00000117          	auipc	sp,0x0
80000398:	00810113          	addi	sp,sp,8 # 8000039c <inst_39+0x8>
8000039c:	01000517          	auipc	a0,0x1000
800003a0:	40250533          	sub	a0,a0,sp
800003a4:	02a0a423          	sw	a0,40(ra)

800003a8 <inst_40>:
800003a8:	00000117          	auipc	sp,0x0
800003ac:	00810113          	addi	sp,sp,8 # 800003b0 <inst_40+0x8>
800003b0:	02000517          	auipc	a0,0x2000
800003b4:	40250533          	sub	a0,a0,sp
800003b8:	02a0a623          	sw	a0,44(ra)

800003bc <inst_41>:
800003bc:	00000117          	auipc	sp,0x0
800003c0:	00810113          	addi	sp,sp,8 # 800003c4 <inst_41+0x8>
800003c4:	04000517          	auipc	a0,0x4000
800003c8:	40250533          	sub	a0,a0,sp
800003cc:	02a0a823          	sw	a0,48(ra)

800003d0 <inst_42>:
800003d0:	00000117          	auipc	sp,0x0
800003d4:	00810113          	addi	sp,sp,8 # 800003d8 <inst_42+0x8>
800003d8:	08000517          	auipc	a0,0x8000
800003dc:	40250533          	sub	a0,a0,sp
800003e0:	02a0aa23          	sw	a0,52(ra)

800003e4 <inst_43>:
800003e4:	00000117          	auipc	sp,0x0
800003e8:	00810113          	addi	sp,sp,8 # 800003ec <inst_43+0x8>
800003ec:	10000517          	auipc	a0,0x10000
800003f0:	40250533          	sub	a0,a0,sp
800003f4:	02a0ac23          	sw	a0,56(ra)

800003f8 <inst_44>:
800003f8:	00000117          	auipc	sp,0x0
800003fc:	00810113          	addi	sp,sp,8 # 80000400 <inst_44+0x8>
80000400:	20000517          	auipc	a0,0x20000
80000404:	40250533          	sub	a0,a0,sp
80000408:	02a0ae23          	sw	a0,60(ra)

8000040c <inst_45>:
8000040c:	00000117          	auipc	sp,0x0
80000410:	00810113          	addi	sp,sp,8 # 80000414 <inst_45+0x8>
80000414:	40000517          	auipc	a0,0x40000
80000418:	40250533          	sub	a0,a0,sp
8000041c:	04a0a023          	sw	a0,64(ra)

80000420 <inst_46>:
80000420:	00000117          	auipc	sp,0x0
80000424:	00810113          	addi	sp,sp,8 # 80000428 <inst_46+0x8>
80000428:	80000517          	auipc	a0,0x80000
8000042c:	40250533          	sub	a0,a0,sp
80000430:	04a0a223          	sw	a0,68(ra)

80000434 <inst_47>:
80000434:	00000117          	auipc	sp,0x0
80000438:	00810113          	addi	sp,sp,8 # 8000043c <inst_47+0x8>
8000043c:	ffffe517          	auipc	a0,0xffffe
80000440:	40250533          	sub	a0,a0,sp
80000444:	04a0a423          	sw	a0,72(ra)

80000448 <inst_48>:
80000448:	00000117          	auipc	sp,0x0
8000044c:	00810113          	addi	sp,sp,8 # 80000450 <inst_48+0x8>
80000450:	ffffd517          	auipc	a0,0xffffd
80000454:	40250533          	sub	a0,a0,sp
80000458:	04a0a623          	sw	a0,76(ra)

8000045c <inst_49>:
8000045c:	00000117          	auipc	sp,0x0
80000460:	00810113          	addi	sp,sp,8 # 80000464 <inst_49+0x8>
80000464:	ffffb517          	auipc	a0,0xffffb
80000468:	40250533          	sub	a0,a0,sp
8000046c:	04a0a823          	sw	a0,80(ra)

80000470 <inst_50>:
80000470:	00000117          	auipc	sp,0x0
80000474:	00810113          	addi	sp,sp,8 # 80000478 <inst_50+0x8>
80000478:	ffff7517          	auipc	a0,0xffff7
8000047c:	40250533          	sub	a0,a0,sp
80000480:	04a0aa23          	sw	a0,84(ra)

80000484 <inst_51>:
80000484:	00000117          	auipc	sp,0x0
80000488:	00810113          	addi	sp,sp,8 # 8000048c <inst_51+0x8>
8000048c:	fffef517          	auipc	a0,0xfffef
80000490:	40250533          	sub	a0,a0,sp
80000494:	04a0ac23          	sw	a0,88(ra)

80000498 <inst_52>:
80000498:	00000117          	auipc	sp,0x0
8000049c:	00810113          	addi	sp,sp,8 # 800004a0 <inst_52+0x8>
800004a0:	fffdf517          	auipc	a0,0xfffdf
800004a4:	40250533          	sub	a0,a0,sp
800004a8:	04a0ae23          	sw	a0,92(ra)

800004ac <inst_53>:
800004ac:	00000117          	auipc	sp,0x0
800004b0:	00810113          	addi	sp,sp,8 # 800004b4 <inst_53+0x8>
800004b4:	fffbf517          	auipc	a0,0xfffbf
800004b8:	40250533          	sub	a0,a0,sp
800004bc:	06a0a023          	sw	a0,96(ra)

800004c0 <inst_54>:
800004c0:	00000117          	auipc	sp,0x0
800004c4:	00810113          	addi	sp,sp,8 # 800004c8 <inst_54+0x8>
800004c8:	fff7f517          	auipc	a0,0xfff7f
800004cc:	40250533          	sub	a0,a0,sp
800004d0:	06a0a223          	sw	a0,100(ra)

800004d4 <inst_55>:
800004d4:	00000117          	auipc	sp,0x0
800004d8:	00810113          	addi	sp,sp,8 # 800004dc <inst_55+0x8>
800004dc:	ffeff517          	auipc	a0,0xffeff
800004e0:	40250533          	sub	a0,a0,sp
800004e4:	06a0a423          	sw	a0,104(ra)

800004e8 <inst_56>:
800004e8:	00000117          	auipc	sp,0x0
800004ec:	00810113          	addi	sp,sp,8 # 800004f0 <inst_56+0x8>
800004f0:	ffdff517          	auipc	a0,0xffdff
800004f4:	40250533          	sub	a0,a0,sp
800004f8:	06a0a623          	sw	a0,108(ra)

800004fc <inst_57>:
800004fc:	00000117          	auipc	sp,0x0
80000500:	00810113          	addi	sp,sp,8 # 80000504 <inst_57+0x8>
80000504:	ffbff517          	auipc	a0,0xffbff
80000508:	40250533          	sub	a0,a0,sp
8000050c:	06a0a823          	sw	a0,112(ra)

80000510 <inst_58>:
80000510:	00000117          	auipc	sp,0x0
80000514:	00810113          	addi	sp,sp,8 # 80000518 <inst_58+0x8>
80000518:	ff7ff517          	auipc	a0,0xff7ff
8000051c:	40250533          	sub	a0,a0,sp
80000520:	06a0aa23          	sw	a0,116(ra)

80000524 <inst_59>:
80000524:	00000117          	auipc	sp,0x0
80000528:	00810113          	addi	sp,sp,8 # 8000052c <inst_59+0x8>
8000052c:	fefff517          	auipc	a0,0xfefff
80000530:	40250533          	sub	a0,a0,sp
80000534:	06a0ac23          	sw	a0,120(ra)

80000538 <inst_60>:
80000538:	00000117          	auipc	sp,0x0
8000053c:	00810113          	addi	sp,sp,8 # 80000540 <inst_60+0x8>
80000540:	fdfff517          	auipc	a0,0xfdfff
80000544:	40250533          	sub	a0,a0,sp
80000548:	06a0ae23          	sw	a0,124(ra)

8000054c <inst_61>:
8000054c:	00000117          	auipc	sp,0x0
80000550:	00810113          	addi	sp,sp,8 # 80000554 <inst_61+0x8>
80000554:	fbfff517          	auipc	a0,0xfbfff
80000558:	40250533          	sub	a0,a0,sp
8000055c:	08a0a023          	sw	a0,128(ra)

80000560 <inst_62>:
80000560:	00000117          	auipc	sp,0x0
80000564:	00810113          	addi	sp,sp,8 # 80000568 <inst_62+0x8>
80000568:	f7fff517          	auipc	a0,0xf7fff
8000056c:	40250533          	sub	a0,a0,sp
80000570:	08a0a223          	sw	a0,132(ra)

80000574 <inst_63>:
80000574:	00000117          	auipc	sp,0x0
80000578:	00810113          	addi	sp,sp,8 # 8000057c <inst_63+0x8>
8000057c:	00006517          	auipc	a0,0x6
80000580:	40250533          	sub	a0,a0,sp
80000584:	08a0a423          	sw	a0,136(ra)

80000588 <cleanup_epilogs>:
80000588:	0040006f          	j	8000058c <exit_cleanup>

8000058c <exit_cleanup>:
8000058c:	00100093          	li	ra,1

80000590 <write_tohost>:
80000590:	00001f17          	auipc	t5,0x1
80000594:	a61f2823          	sw	ra,-1424(t5) # 80001000 <tohost>
80000598:	ff9ff06f          	j	80000590 <write_tohost>
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
80002020:	deadbeef          	jal	t4,7ffdd60a <absimmsh+0x2a1d82f>
80002024:	deadbeef          	jal	t4,7ffdd60e <absimmsh+0x2a1d833>

80002028 <rvtest_data_end>:
	...

80003000 <begin_regstate>:
80003000:	0080                	addi	s0,sp,64
	...

80003100 <end_regstate>:
80003100:	0004                	0x4
	...

80003110 <begin_signature>:
80003110:	a309                	j	80003612 <_end+0x3f2>
80003112:	6f5c                	flw	fa5,28(a4)

80003114 <signature_x11_0>:
80003114:	deadbeef          	jal	t4,7ffde6fe <absimmsh+0x2a1e923>
80003118:	deadbeef          	jal	t4,7ffde702 <absimmsh+0x2a1e927>
8000311c:	deadbeef          	jal	t4,7ffde706 <absimmsh+0x2a1e92b>
80003120:	deadbeef          	jal	t4,7ffde70a <absimmsh+0x2a1e92f>
80003124:	deadbeef          	jal	t4,7ffde70e <absimmsh+0x2a1e933>
80003128:	deadbeef          	jal	t4,7ffde712 <absimmsh+0x2a1e937>
8000312c:	deadbeef          	jal	t4,7ffde716 <absimmsh+0x2a1e93b>
80003130:	deadbeef          	jal	t4,7ffde71a <absimmsh+0x2a1e93f>
80003134:	deadbeef          	jal	t4,7ffde71e <absimmsh+0x2a1e943>
80003138:	deadbeef          	jal	t4,7ffde722 <absimmsh+0x2a1e947>
8000313c:	deadbeef          	jal	t4,7ffde726 <absimmsh+0x2a1e94b>
80003140:	deadbeef          	jal	t4,7ffde72a <absimmsh+0x2a1e94f>
80003144:	deadbeef          	jal	t4,7ffde72e <absimmsh+0x2a1e953>
80003148:	deadbeef          	jal	t4,7ffde732 <absimmsh+0x2a1e957>
8000314c:	deadbeef          	jal	t4,7ffde736 <absimmsh+0x2a1e95b>
80003150:	deadbeef          	jal	t4,7ffde73a <absimmsh+0x2a1e95f>
80003154:	deadbeef          	jal	t4,7ffde73e <absimmsh+0x2a1e963>
80003158:	deadbeef          	jal	t4,7ffde742 <absimmsh+0x2a1e967>
8000315c:	deadbeef          	jal	t4,7ffde746 <absimmsh+0x2a1e96b>
80003160:	deadbeef          	jal	t4,7ffde74a <absimmsh+0x2a1e96f>
80003164:	deadbeef          	jal	t4,7ffde74e <absimmsh+0x2a1e973>
80003168:	deadbeef          	jal	t4,7ffde752 <absimmsh+0x2a1e977>
8000316c:	deadbeef          	jal	t4,7ffde756 <absimmsh+0x2a1e97b>
80003170:	deadbeef          	jal	t4,7ffde75a <absimmsh+0x2a1e97f>
80003174:	deadbeef          	jal	t4,7ffde75e <absimmsh+0x2a1e983>
80003178:	deadbeef          	jal	t4,7ffde762 <absimmsh+0x2a1e987>
8000317c:	deadbeef          	jal	t4,7ffde766 <absimmsh+0x2a1e98b>
80003180:	deadbeef          	jal	t4,7ffde76a <absimmsh+0x2a1e98f>
80003184:	deadbeef          	jal	t4,7ffde76e <absimmsh+0x2a1e993>

80003188 <signature_x1_0>:
80003188:	deadbeef          	jal	t4,7ffde772 <absimmsh+0x2a1e997>
8000318c:	deadbeef          	jal	t4,7ffde776 <absimmsh+0x2a1e99b>
80003190:	deadbeef          	jal	t4,7ffde77a <absimmsh+0x2a1e99f>
80003194:	deadbeef          	jal	t4,7ffde77e <absimmsh+0x2a1e9a3>
80003198:	deadbeef          	jal	t4,7ffde782 <absimmsh+0x2a1e9a7>
8000319c:	deadbeef          	jal	t4,7ffde786 <absimmsh+0x2a1e9ab>
800031a0:	deadbeef          	jal	t4,7ffde78a <absimmsh+0x2a1e9af>
800031a4:	deadbeef          	jal	t4,7ffde78e <absimmsh+0x2a1e9b3>
800031a8:	deadbeef          	jal	t4,7ffde792 <absimmsh+0x2a1e9b7>
800031ac:	deadbeef          	jal	t4,7ffde796 <absimmsh+0x2a1e9bb>
800031b0:	deadbeef          	jal	t4,7ffde79a <absimmsh+0x2a1e9bf>
800031b4:	deadbeef          	jal	t4,7ffde79e <absimmsh+0x2a1e9c3>
800031b8:	deadbeef          	jal	t4,7ffde7a2 <absimmsh+0x2a1e9c7>
800031bc:	deadbeef          	jal	t4,7ffde7a6 <absimmsh+0x2a1e9cb>
800031c0:	deadbeef          	jal	t4,7ffde7aa <absimmsh+0x2a1e9cf>
800031c4:	deadbeef          	jal	t4,7ffde7ae <absimmsh+0x2a1e9d3>
800031c8:	deadbeef          	jal	t4,7ffde7b2 <absimmsh+0x2a1e9d7>
800031cc:	deadbeef          	jal	t4,7ffde7b6 <absimmsh+0x2a1e9db>
800031d0:	deadbeef          	jal	t4,7ffde7ba <absimmsh+0x2a1e9df>
800031d4:	deadbeef          	jal	t4,7ffde7be <absimmsh+0x2a1e9e3>
800031d8:	deadbeef          	jal	t4,7ffde7c2 <absimmsh+0x2a1e9e7>
800031dc:	deadbeef          	jal	t4,7ffde7c6 <absimmsh+0x2a1e9eb>
800031e0:	deadbeef          	jal	t4,7ffde7ca <absimmsh+0x2a1e9ef>
800031e4:	deadbeef          	jal	t4,7ffde7ce <absimmsh+0x2a1e9f3>
800031e8:	deadbeef          	jal	t4,7ffde7d2 <absimmsh+0x2a1e9f7>
800031ec:	deadbeef          	jal	t4,7ffde7d6 <absimmsh+0x2a1e9fb>
800031f0:	deadbeef          	jal	t4,7ffde7da <absimmsh+0x2a1e9ff>
800031f4:	deadbeef          	jal	t4,7ffde7de <absimmsh+0x2a1ea03>
800031f8:	deadbeef          	jal	t4,7ffde7e2 <absimmsh+0x2a1ea07>
800031fc:	deadbeef          	jal	t4,7ffde7e6 <absimmsh+0x2a1ea0b>
80003200:	deadbeef          	jal	t4,7ffde7ea <absimmsh+0x2a1ea0f>
80003204:	deadbeef          	jal	t4,7ffde7ee <absimmsh+0x2a1ea13>
80003208:	deadbeef          	jal	t4,7ffde7f2 <absimmsh+0x2a1ea17>
8000320c:	deadbeef          	jal	t4,7ffde7f6 <absimmsh+0x2a1ea1b>
80003210:	deadbeef          	jal	t4,7ffde7fa <absimmsh+0x2a1ea1f>

80003214 <sig_end_canary>:
80003214:	a309                	j	80003716 <_end+0x4f6>
80003216:	6f5c                	flw	fa5,28(a4)

80003218 <rvtest_sig_end>:
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
   0:	0224                	addi	s1,sp,264
   2:	0000                	unimp
   4:	00760003          	lb	zero,7(a2) # 80080303 <_end+0x7d0e3>
   8:	0000                	unimp
   a:	0101                	addi	sp,sp,0
   c:	000d0efb          	0xd0efb
  10:	0101                	addi	sp,sp,0
  12:	0101                	addi	sp,sp,0
  14:	0000                	unimp
  16:	0100                	addi	s0,sp,128
  18:	0000                	unimp
  1a:	2f01                	jal	72a <offset+0x69e>
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
  44:	612d7663          	bgeu	s10,s2,650 <offset+0x5c4>
  48:	6372                	flw	ft6,28(sp)
  4a:	2d68                	fld	fa0,216(a0)
  4c:	6574                	flw	fa3,76(a0)
  4e:	722f7473          	csrrci	s0,0x722,30
  52:	7369                	lui	t1,0xffffa
  54:	742d7663          	bgeu	s10,sp,7a0 <offset+0x714>
  58:	7365                	lui	t1,0xffff9
  5a:	2d74                	fld	fa3,216(a0)
  5c:	74697573          	csrrci	a0,0x746,18
  60:	2f65                	jal	818 <offset+0x78c>
  62:	7672                	flw	fa2,60(sp)
  64:	5f693233          	0x5f693233
  68:	2f6d                	jal	822 <offset+0x796>
  6a:	2f49                	jal	7fc <offset+0x770>
  6c:	00637273          	csrrci	tp,0x6,6
  70:	6100                	flw	fs0,0(a0)
  72:	6975                	lui	s2,0x1d
  74:	6370                	flw	fa2,68(a4)
  76:	302d                	jal	fffff8a0 <imm12sh+0xfffffac5>
  78:	2e31                	jal	394 <offset+0x308>
  7a:	00010053          	fadd.s	ft0,ft2,ft0,rne
  7e:	0000                	unimp
  80:	0500                	addi	s0,sp,640
  82:	0002                	c.slli64	zero
  84:	0000                	unimp
  86:	0380                	addi	s0,sp,448
  88:	0119                	addi	sp,sp,6
  8a:	78090603          	lb	a2,1920(s2) # 1d780 <offset+0x1d6f4>
  8e:	0100                	addi	s0,sp,128
  90:	08090503          	lb	a0,128(s2)
  94:	0100                	addi	s0,sp,128
  96:	14090503          	lb	a0,320(s2)
  9a:	0100                	addi	s0,sp,128
  9c:	14090503          	lb	a0,320(s2)
  a0:	0100                	addi	s0,sp,128
  a2:	14090503          	lb	a0,320(s2)
  a6:	0100                	addi	s0,sp,128
  a8:	14090503          	lb	a0,320(s2)
  ac:	0100                	addi	s0,sp,128
  ae:	14090503          	lb	a0,320(s2)
  b2:	0100                	addi	s0,sp,128
  b4:	14090503          	lb	a0,320(s2)
  b8:	0100                	addi	s0,sp,128
  ba:	14090503          	lb	a0,320(s2)
  be:	0100                	addi	s0,sp,128
  c0:	14090503          	lb	a0,320(s2)
  c4:	0100                	addi	s0,sp,128
  c6:	14090503          	lb	a0,320(s2)
  ca:	0100                	addi	s0,sp,128
  cc:	14090503          	lb	a0,320(s2)
  d0:	0100                	addi	s0,sp,128
  d2:	14090503          	lb	a0,320(s2)
  d6:	0100                	addi	s0,sp,128
  d8:	14090503          	lb	a0,320(s2)
  dc:	0100                	addi	s0,sp,128
  de:	14090503          	lb	a0,320(s2)
  e2:	0100                	addi	s0,sp,128
  e4:	14090503          	lb	a0,320(s2)
  e8:	0100                	addi	s0,sp,128
  ea:	14090503          	lb	a0,320(s2)
  ee:	0100                	addi	s0,sp,128
  f0:	14090503          	lb	a0,320(s2)
  f4:	0100                	addi	s0,sp,128
  f6:	14090503          	lb	a0,320(s2)
  fa:	0100                	addi	s0,sp,128
  fc:	14090503          	lb	a0,320(s2)
 100:	0100                	addi	s0,sp,128
 102:	14090503          	lb	a0,320(s2)
 106:	0100                	addi	s0,sp,128
 108:	14090503          	lb	a0,320(s2)
 10c:	0100                	addi	s0,sp,128
 10e:	14090503          	lb	a0,320(s2)
 112:	0100                	addi	s0,sp,128
 114:	14090503          	lb	a0,320(s2)
 118:	0100                	addi	s0,sp,128
 11a:	14090503          	lb	a0,320(s2)
 11e:	0100                	addi	s0,sp,128
 120:	14090503          	lb	a0,320(s2)
 124:	0100                	addi	s0,sp,128
 126:	14090503          	lb	a0,320(s2)
 12a:	0100                	addi	s0,sp,128
 12c:	14090503          	lb	a0,320(s2)
 130:	0100                	addi	s0,sp,128
 132:	14090503          	lb	a0,320(s2)
 136:	0100                	addi	s0,sp,128
 138:	14090503          	lb	a0,320(s2)
 13c:	0100                	addi	s0,sp,128
 13e:	14090103          	lb	sp,320(s2)
 142:	0100                	addi	s0,sp,128
 144:	08090503          	lb	a0,128(s2)
 148:	0100                	addi	s0,sp,128
 14a:	14090503          	lb	a0,320(s2)
 14e:	0100                	addi	s0,sp,128
 150:	14090503          	lb	a0,320(s2)
 154:	0100                	addi	s0,sp,128
 156:	14090503          	lb	a0,320(s2)
 15a:	0100                	addi	s0,sp,128
 15c:	14090503          	lb	a0,320(s2)
 160:	0100                	addi	s0,sp,128
 162:	14090503          	lb	a0,320(s2)
 166:	0100                	addi	s0,sp,128
 168:	14090503          	lb	a0,320(s2)
 16c:	0100                	addi	s0,sp,128
 16e:	14090503          	lb	a0,320(s2)
 172:	0100                	addi	s0,sp,128
 174:	14090503          	lb	a0,320(s2)
 178:	0100                	addi	s0,sp,128
 17a:	14090503          	lb	a0,320(s2)
 17e:	0100                	addi	s0,sp,128
 180:	14090503          	lb	a0,320(s2)
 184:	0100                	addi	s0,sp,128
 186:	14090503          	lb	a0,320(s2)
 18a:	0100                	addi	s0,sp,128
 18c:	14090503          	lb	a0,320(s2)
 190:	0100                	addi	s0,sp,128
 192:	14090503          	lb	a0,320(s2)
 196:	0100                	addi	s0,sp,128
 198:	14090503          	lb	a0,320(s2)
 19c:	0100                	addi	s0,sp,128
 19e:	14090503          	lb	a0,320(s2)
 1a2:	0100                	addi	s0,sp,128
 1a4:	14090503          	lb	a0,320(s2)
 1a8:	0100                	addi	s0,sp,128
 1aa:	14090503          	lb	a0,320(s2)
 1ae:	0100                	addi	s0,sp,128
 1b0:	14090503          	lb	a0,320(s2)
 1b4:	0100                	addi	s0,sp,128
 1b6:	14090503          	lb	a0,320(s2)
 1ba:	0100                	addi	s0,sp,128
 1bc:	14090503          	lb	a0,320(s2)
 1c0:	0100                	addi	s0,sp,128
 1c2:	14090503          	lb	a0,320(s2)
 1c6:	0100                	addi	s0,sp,128
 1c8:	14090503          	lb	a0,320(s2)
 1cc:	0100                	addi	s0,sp,128
 1ce:	14090503          	lb	a0,320(s2)
 1d2:	0100                	addi	s0,sp,128
 1d4:	14090503          	lb	a0,320(s2)
 1d8:	0100                	addi	s0,sp,128
 1da:	14090503          	lb	a0,320(s2)
 1de:	0100                	addi	s0,sp,128
 1e0:	14090503          	lb	a0,320(s2)
 1e4:	0100                	addi	s0,sp,128
 1e6:	14090503          	lb	a0,320(s2)
 1ea:	0100                	addi	s0,sp,128
 1ec:	14090503          	lb	a0,320(s2)
 1f0:	0100                	addi	s0,sp,128
 1f2:	14090503          	lb	a0,320(s2)
 1f6:	0100                	addi	s0,sp,128
 1f8:	14090503          	lb	a0,320(s2)
 1fc:	0100                	addi	s0,sp,128
 1fe:	14090503          	lb	a0,320(s2)
 202:	0100                	addi	s0,sp,128
 204:	14090503          	lb	a0,320(s2)
 208:	0100                	addi	s0,sp,128
 20a:	14090503          	lb	a0,320(s2)
 20e:	0100                	addi	s0,sp,128
 210:	14090503          	lb	a0,320(s2)
 214:	0100                	addi	s0,sp,128
 216:	14090403          	lb	s0,320(s2)
 21a:	0100                	addi	s0,sp,128
 21c:	04090103          	lb	sp,64(s2)
 220:	0100                	addi	s0,sp,128
 222:	1009                	c.nop	-30
 224:	0000                	unimp
 226:	0101                	addi	sp,sp,0

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
  14:	059c                	addi	a5,sp,704
  16:	8000                	0x8000
  18:	0000                	unimp
  1a:	0000                	unimp
  1c:	0060                	addi	s0,sp,12
  1e:	0000                	unimp
  20:	000000af          	0xaf
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
  14:	059c                	addi	a5,sp,704
	...

Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	6d6f682f          	0x6d6f682f
   4:	2f65                	jal	7bc <offset+0x730>
   6:	6f6c                	flw	fa1,92(a4)
   8:	6976                	flw	fs2,92(sp)
   a:	65442f73          	csrrs	t5,0x654,s0
   e:	6f746b73          	csrrsi	s6,0x6f7,8
  12:	2f70                	fld	fa2,216(a4)
  14:	6952                	flw	fs2,20(sp)
  16:	6556                	flw	fa0,84(sp)
  18:	5f72                	lw	t5,60(sp)
  1a:	65726f63          	bltu	tp,s7,678 <offset+0x5ec>
  1e:	7369722f          	0x7369722f
  22:	2f666f63          	bltu	a2,s6,320 <offset+0x294>
  26:	6972                	flw	fs2,28(sp)
  28:	2d766373          	csrrsi	t1,0x2d7,12
  2c:	7261                	lui	tp,0xffff8
  2e:	742d6863          	bltu	s10,sp,77e <offset+0x6f2>
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
  54:	6975612f          	0x6975612f
  58:	6370                	flw	fa2,68(a4)
  5a:	302d                	jal	fffff884 <imm12sh+0xfffffaa9>
  5c:	2e31                	jal	378 <offset+0x2ec>
  5e:	682f0053          	0x682f0053
  62:	2f656d6f          	jal	s10,56358 <offset+0x562cc>
  66:	6f6c                	flw	fa1,92(a4)
  68:	6976                	flw	fs2,92(sp)
  6a:	65442f73          	csrrs	t5,0x654,s0
  6e:	6f746b73          	csrrsi	s6,0x6f7,8
  72:	2f70                	fld	fa2,216(a4)
  74:	6952                	flw	fs2,20(sp)
  76:	6556                	flw	fa0,84(sp)
  78:	5f72                	lw	t5,60(sp)
  7a:	65726f63          	bltu	tp,s7,6d8 <offset+0x64c>
  7e:	7369722f          	0x7369722f
  82:	2f666f63          	bltu	a2,s6,380 <offset+0x2f4>
  86:	6972                	flw	fs2,28(sp)
  88:	666f6373          	csrrsi	t1,0x666,30
  8c:	775f 726f 2f6b      	0x2f6b726f775f
  92:	7672                	flw	fa2,60(sp)
  94:	5f693233          	0x5f693233
  98:	2f6d                	jal	852 <offset+0x7c6>
  9a:	2f49                	jal	82c <offset+0x7a0>
  9c:	2f637273          	csrrci	tp,0x2f6,6
  a0:	7561                	lui	a0,0xffff8
  a2:	7069                	c.lui	zero,0xffffa
  a4:	31302d63          	0x31302d63
  a8:	532e                	lw	t1,232(sp)
  aa:	7475642f          	0x7475642f
  ae:	4700                	lw	s0,8(a4)
  b0:	554e                	lw	a0,240(sp)
  b2:	4120                	lw	s0,64(a0)
  b4:	2e322053          	0x2e322053
  b8:	          	snez	a0,zero
