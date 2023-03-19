
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
80000078:	00003497          	auipc	s1,0x3
8000007c:	09c48493          	addi	s1,s1,156 # 80003114 <signature_x9_0>

80000080 <inst_0>:
80000080:	00002a17          	auipc	s4,0x2
80000084:	f70a0a13          	addi	s4,s4,-144 # 80001ff0 <fromhost+0xef0>
80000088:	020a4f83          	lbu	t6,32(s4)
8000008c:	00000013          	nop
80000090:	00000013          	nop
80000094:	01f4a023          	sw	t6,0(s1)

80000098 <inst_1>:
80000098:	00002b17          	auipc	s6,0x2
8000009c:	f6fb0b13          	addi	s6,s6,-145 # 80002007 <rvtest_trap_sig+0x7>
800000a0:	009b4b03          	lbu	s6,9(s6)
800000a4:	00000013          	nop
800000a8:	00000013          	nop
800000ac:	0164a223          	sw	s6,4(s1)

800000b0 <inst_2>:
800000b0:	00002397          	auipc	t2,0x2
800000b4:	f6a38393          	addi	t2,t2,-150 # 8000201a <rvtest_data_begin+0xa>
800000b8:	ff63c683          	lbu	a3,-10(t2)
800000bc:	00000013          	nop
800000c0:	00000013          	nop
800000c4:	00d4a423          	sw	a3,8(s1)

800000c8 <inst_3>:
800000c8:	00002897          	auipc	a7,0x2
800000cc:	14988893          	addi	a7,a7,329 # 80002211 <rvtest_data_end+0x1e9>
800000d0:	dff8c703          	lbu	a4,-513(a7)
800000d4:	00000013          	nop
800000d8:	00000013          	nop
800000dc:	00e4a623          	sw	a4,12(s1)

800000e0 <inst_4>:
800000e0:	00002117          	auipc	sp,0x2
800000e4:	b3210113          	addi	sp,sp,-1230 # 80001c12 <fromhost+0xb12>
800000e8:	40014203          	lbu	tp,1024(sp)
800000ec:	00000013          	nop
800000f0:	00000013          	nop
800000f4:	0044a823          	sw	tp,16(s1)

800000f8 <inst_5>:
800000f8:	00002697          	auipc	a3,0x2
800000fc:	f1168693          	addi	a3,a3,-239 # 80002009 <rvtest_trap_sig+0x9>
80000100:	0096ce03          	lbu	t3,9(a3)
80000104:	00000013          	nop
80000108:	00000013          	nop
8000010c:	01c4aa23          	sw	t3,20(s1)

80000110 <inst_6>:
80000110:	00002d17          	auipc	s10,0x2
80000114:	f08d0d13          	addi	s10,s10,-248 # 80002018 <rvtest_data_begin+0x8>
80000118:	ffad4503          	lbu	a0,-6(s10)
8000011c:	00000013          	nop
80000120:	00000013          	nop
80000124:	00a4ac23          	sw	a0,24(s1)

80000128 <inst_7>:
80000128:	00001917          	auipc	s2,0x1
8000012c:	6eb90913          	addi	s2,s2,1771 # 80001813 <fromhost+0x713>
80000130:	7ff94d83          	lbu	s11,2047(s2)
80000134:	00000013          	nop
80000138:	00000013          	nop
8000013c:	01b4ae23          	sw	s11,28(s1)

80000140 <inst_8>:
80000140:	00002717          	auipc	a4,0x2
80000144:	e9170713          	addi	a4,a4,-367 # 80001fd1 <fromhost+0xed1>
80000148:	04074383          	lbu	t2,64(a4)
8000014c:	00000013          	nop
80000150:	00000013          	nop
80000154:	0274a023          	sw	t2,32(s1)

80000158 <inst_9>:
80000158:	00002097          	auipc	ra,0x2
8000015c:	96408093          	addi	ra,ra,-1692 # 80001abc <fromhost+0x9bc>
80000160:	5550cb83          	lbu	s7,1365(ra)
80000164:	00000013          	nop
80000168:	00000013          	nop
8000016c:	0374a223          	sw	s7,36(s1)

80000170 <inst_10>:
80000170:	00002417          	auipc	s0,0x2
80000174:	ea040413          	addi	s0,s0,-352 # 80002010 <rvtest_data_begin>
80000178:	00044c03          	lbu	s8,0(s0)
8000017c:	00000013          	nop
80000180:	00000013          	nop
80000184:	0384a423          	sw	s8,40(s1)

80000188 <inst_11>:
80000188:	00002517          	auipc	a0,0x2
8000018c:	e8f50513          	addi	a0,a0,-369 # 80002017 <rvtest_data_begin+0x7>
80000190:	ffa54103          	lbu	sp,-6(a0)
80000194:	00000013          	nop
80000198:	00000013          	nop
8000019c:	0224a623          	sw	sp,44(s1)

800001a0 <inst_12>:
800001a0:	00002c17          	auipc	s8,0x2
800001a4:	eb2c0c13          	addi	s8,s8,-334 # 80002052 <rvtest_data_end+0x2a>
800001a8:	fbfc4f03          	lbu	t5,-65(s8)
800001ac:	00000013          	nop
800001b0:	00000013          	nop
800001b4:	03e4a823          	sw	t5,48(s1)

800001b8 <inst_13>:
800001b8:	00002597          	auipc	a1,0x2
800001bc:	e5358593          	addi	a1,a1,-429 # 8000200b <rvtest_trap_sig+0xb>
800001c0:	0085c303          	lbu	t1,8(a1)
800001c4:	00000013          	nop
800001c8:	00000013          	nop
800001cc:	0264aa23          	sw	t1,52(s1)

800001d0 <inst_14>:
800001d0:	00002617          	auipc	a2,0x2
800001d4:	8ee60613          	addi	a2,a2,-1810 # 80001abe <fromhost+0x9be>
800001d8:	55564083          	lbu	ra,1365(a2)
800001dc:	00000013          	nop
800001e0:	00000013          	nop
800001e4:	0214ac23          	sw	ra,56(s1)

800001e8 <inst_15>:
800001e8:	00002997          	auipc	s3,0x2
800001ec:	e2998993          	addi	s3,s3,-471 # 80002011 <rvtest_data_begin+0x1>
800001f0:	0029cc83          	lbu	s9,2(s3)
800001f4:	00000013          	nop
800001f8:	00000013          	nop
800001fc:	0394ae23          	sw	s9,60(s1)

80000200 <inst_16>:
80000200:	00002a97          	auipc	s5,0x2
80000204:	f14a8a93          	addi	s5,s5,-236 # 80002114 <rvtest_data_end+0xec>
80000208:	effac283          	lbu	t0,-257(s5)
8000020c:	00000013          	nop
80000210:	00000013          	nop
80000214:	0454a023          	sw	t0,64(s1)

80000218 <inst_17>:
80000218:	00002e17          	auipc	t3,0x2
8000021c:	5f8e0e13          	addi	t3,t3,1528 # 80002810 <rvtest_data_end+0x7e8>
80000220:	800e4a03          	lbu	s4,-2048(t3)
80000224:	00000013          	nop
80000228:	00000013          	nop
8000022c:	0544a223          	sw	s4,68(s1)

80000230 <inst_18>:
80000230:	00002197          	auipc	gp,0x2
80000234:	5e018193          	addi	gp,gp,1504 # 80002810 <rvtest_data_end+0x7e8>
80000238:	8001c603          	lbu	a2,-2048(gp)
8000023c:	00000013          	nop
80000240:	00000013          	nop
80000244:	04c4a423          	sw	a2,72(s1)

80000248 <inst_19>:
80000248:	00002317          	auipc	t1,0x2
8000024c:	5c830313          	addi	t1,t1,1480 # 80002810 <rvtest_data_end+0x7e8>
80000250:	80034803          	lbu	a6,-2048(t1)
80000254:	00000013          	nop
80000258:	00000013          	nop
8000025c:	0504a623          	sw	a6,76(s1)
80000260:	00003097          	auipc	ra,0x3
80000264:	f0408093          	addi	ra,ra,-252 # 80003164 <signature_x1_0>

80000268 <inst_20>:
80000268:	00002797          	auipc	a5,0x2
8000026c:	5a878793          	addi	a5,a5,1448 # 80002810 <rvtest_data_end+0x7e8>
80000270:	8007ca83          	lbu	s5,-2048(a5)
80000274:	00000013          	nop
80000278:	00000013          	nop
8000027c:	0150a023          	sw	s5,0(ra)

80000280 <inst_21>:
80000280:	00002e97          	auipc	t4,0x2
80000284:	590e8e93          	addi	t4,t4,1424 # 80002810 <rvtest_data_end+0x7e8>
80000288:	800ec983          	lbu	s3,-2048(t4)
8000028c:	00000013          	nop
80000290:	00000013          	nop
80000294:	0130a223          	sw	s3,4(ra)

80000298 <inst_22>:
80000298:	00002c97          	auipc	s9,0x2
8000029c:	578c8c93          	addi	s9,s9,1400 # 80002810 <rvtest_data_end+0x7e8>
800002a0:	800cc583          	lbu	a1,-2048(s9)
800002a4:	00000013          	nop
800002a8:	00000013          	nop
800002ac:	00b0a423          	sw	a1,8(ra)

800002b0 <inst_23>:
800002b0:	00002f17          	auipc	t5,0x2
800002b4:	560f0f13          	addi	t5,t5,1376 # 80002810 <rvtest_data_end+0x7e8>
800002b8:	800f4883          	lbu	a7,-2048(t5)
800002bc:	00000013          	nop
800002c0:	00000013          	nop
800002c4:	0110a623          	sw	a7,12(ra)

800002c8 <inst_24>:
800002c8:	00002217          	auipc	tp,0x2
800002cc:	54820213          	addi	tp,tp,1352 # 80002810 <rvtest_data_end+0x7e8>
800002d0:	80024903          	lbu	s2,-2048(tp) # fffff800 <imm12sh+0xfffffa25>
800002d4:	00000013          	nop
800002d8:	00000013          	nop
800002dc:	0120a823          	sw	s2,16(ra)

800002e0 <inst_25>:
800002e0:	00002297          	auipc	t0,0x2
800002e4:	53028293          	addi	t0,t0,1328 # 80002810 <rvtest_data_end+0x7e8>
800002e8:	8002c483          	lbu	s1,-2048(t0)
800002ec:	00000013          	nop
800002f0:	00000013          	nop
800002f4:	0090aa23          	sw	s1,20(ra)

800002f8 <inst_26>:
800002f8:	00002f97          	auipc	t6,0x2
800002fc:	518f8f93          	addi	t6,t6,1304 # 80002810 <rvtest_data_end+0x7e8>
80000300:	800fc783          	lbu	a5,-2048(t6)
80000304:	00000013          	nop
80000308:	00000013          	nop
8000030c:	00f0ac23          	sw	a5,24(ra)

80000310 <inst_27>:
80000310:	00002817          	auipc	a6,0x2
80000314:	50080813          	addi	a6,a6,1280 # 80002810 <rvtest_data_end+0x7e8>
80000318:	80084d03          	lbu	s10,-2048(a6)
8000031c:	00000013          	nop
80000320:	00000013          	nop
80000324:	01a0ae23          	sw	s10,28(ra)

80000328 <inst_28>:
80000328:	00002d97          	auipc	s11,0x2
8000032c:	4e8d8d93          	addi	s11,s11,1256 # 80002810 <rvtest_data_end+0x7e8>
80000330:	800dc403          	lbu	s0,-2048(s11)
80000334:	00000013          	nop
80000338:	00000013          	nop
8000033c:	0280a023          	sw	s0,32(ra)

80000340 <inst_29>:
80000340:	00002497          	auipc	s1,0x2
80000344:	4d048493          	addi	s1,s1,1232 # 80002810 <rvtest_data_end+0x7e8>
80000348:	8004c003          	lbu	zero,-2048(s1)
8000034c:	00000013          	nop
80000350:	00000013          	nop
80000354:	0200a223          	sw	zero,36(ra)

80000358 <inst_30>:
80000358:	00002b97          	auipc	s7,0x2
8000035c:	4b8b8b93          	addi	s7,s7,1208 # 80002810 <rvtest_data_end+0x7e8>
80000360:	800bc183          	lbu	gp,-2048(s7)
80000364:	00000013          	nop
80000368:	00000013          	nop
8000036c:	0230a423          	sw	gp,40(ra)

80000370 <inst_31>:
80000370:	00002617          	auipc	a2,0x2
80000374:	4a060613          	addi	a2,a2,1184 # 80002810 <rvtest_data_end+0x7e8>
80000378:	80064e83          	lbu	t4,-2048(a2)
8000037c:	00000013          	nop
80000380:	00000013          	nop
80000384:	03d0a623          	sw	t4,44(ra)

80000388 <cleanup_epilogs>:
80000388:	0040006f          	j	8000038c <exit_cleanup>

8000038c <exit_cleanup>:
8000038c:	00100093          	li	ra,1

80000390 <write_tohost>:
80000390:	00001f17          	auipc	t5,0x1
80000394:	c61f2823          	sw	ra,-912(t5) # 80001000 <tohost>
80000398:	ff9ff06f          	j	80000390 <write_tohost>
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
80003110:	a309                	j	80003612 <_end+0x472>
80003112:	6f5c                	flw	fa5,28(a4)

80003114 <signature_x9_0>:
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

80003164 <signature_x1_0>:
80003164:	deadbeef          	jal	t4,7ffde74e <absimmsh+0x2a1e973>
80003168:	deadbeef          	jal	t4,7ffde752 <absimmsh+0x2a1e977>
8000316c:	deadbeef          	jal	t4,7ffde756 <absimmsh+0x2a1e97b>
80003170:	deadbeef          	jal	t4,7ffde75a <absimmsh+0x2a1e97f>
80003174:	deadbeef          	jal	t4,7ffde75e <absimmsh+0x2a1e983>
80003178:	deadbeef          	jal	t4,7ffde762 <absimmsh+0x2a1e987>
8000317c:	deadbeef          	jal	t4,7ffde766 <absimmsh+0x2a1e98b>
80003180:	deadbeef          	jal	t4,7ffde76a <absimmsh+0x2a1e98f>
80003184:	deadbeef          	jal	t4,7ffde76e <absimmsh+0x2a1e993>
80003188:	deadbeef          	jal	t4,7ffde772 <absimmsh+0x2a1e997>
8000318c:	deadbeef          	jal	t4,7ffde776 <absimmsh+0x2a1e99b>
80003190:	deadbeef          	jal	t4,7ffde77a <absimmsh+0x2a1e99f>

80003194 <sig_end_canary>:
80003194:	a309                	j	80003696 <_end+0x4f6>
80003196:	6f5c                	flw	fa5,28(a4)

80003198 <rvtest_sig_end>:
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
   0:	0168                	addi	a0,sp,140
   2:	0000                	unimp
   4:	007a0003          	lb	zero,7(s4)
   8:	0000                	unimp
   a:	0101                	addi	sp,sp,0
   c:	000d0efb          	0xd0efb
  10:	0101                	addi	sp,sp,0
  12:	0101                	addi	sp,sp,0
  14:	0000                	unimp
  16:	0100                	addi	s0,sp,128
  18:	0000                	unimp
  1a:	2f01                	jal	72a <offset+0x6fa>
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
  44:	612d7663          	bgeu	s10,s2,650 <offset+0x620>
  48:	6372                	flw	ft6,28(sp)
  4a:	2d68                	fld	fa0,216(a0)
  4c:	6574                	flw	fa3,76(a0)
  4e:	722f7473          	csrrci	s0,0x722,30
  52:	7369                	lui	t1,0xffffa
  54:	742d7663          	bgeu	s10,sp,7a0 <offset+0x770>
  58:	7365                	lui	t1,0xffff9
  5a:	2d74                	fld	fa3,216(a0)
  5c:	74697573          	csrrci	a0,0x746,18
  60:	2f65                	jal	818 <offset+0x7e8>
  62:	7672                	flw	fa2,60(sp)
  64:	5f693233          	0x5f693233
  68:	2f6d                	jal	822 <offset+0x7f2>
  6a:	2f49                	jal	7fc <offset+0x7cc>
  6c:	00637273          	csrrci	tp,0x6,6
  70:	6c00                	flw	fs0,24(s0)
  72:	7562                	flw	fa0,56(sp)
  74:	612d                	addi	sp,sp,224
  76:	696c                	flw	fa1,84(a0)
  78:	302d6e67          	0x302d6e67
  7c:	2e31                	jal	398 <offset+0x368>
  7e:	00010053          	fadd.s	ft0,ft2,ft0,rne
  82:	0000                	unimp
  84:	0500                	addi	s0,sp,640
  86:	0002                	c.slli64	zero
  88:	0000                	unimp
  8a:	0380                	addi	s0,sp,448
  8c:	0119                	addi	sp,sp,6
  8e:	78090603          	lb	a2,1920(s2)
  92:	0100                	addi	s0,sp,128
  94:	08090503          	lb	a0,128(s2)
  98:	0100                	addi	s0,sp,128
  9a:	18090503          	lb	a0,384(s2)
  9e:	0100                	addi	s0,sp,128
  a0:	18090503          	lb	a0,384(s2)
  a4:	0100                	addi	s0,sp,128
  a6:	18090503          	lb	a0,384(s2)
  aa:	0100                	addi	s0,sp,128
  ac:	18090503          	lb	a0,384(s2)
  b0:	0100                	addi	s0,sp,128
  b2:	18090503          	lb	a0,384(s2)
  b6:	0100                	addi	s0,sp,128
  b8:	18090503          	lb	a0,384(s2)
  bc:	0100                	addi	s0,sp,128
  be:	18090503          	lb	a0,384(s2)
  c2:	0100                	addi	s0,sp,128
  c4:	18090503          	lb	a0,384(s2)
  c8:	0100                	addi	s0,sp,128
  ca:	18090503          	lb	a0,384(s2)
  ce:	0100                	addi	s0,sp,128
  d0:	18090503          	lb	a0,384(s2)
  d4:	0100                	addi	s0,sp,128
  d6:	18090503          	lb	a0,384(s2)
  da:	0100                	addi	s0,sp,128
  dc:	18090503          	lb	a0,384(s2)
  e0:	0100                	addi	s0,sp,128
  e2:	18090503          	lb	a0,384(s2)
  e6:	0100                	addi	s0,sp,128
  e8:	18090503          	lb	a0,384(s2)
  ec:	0100                	addi	s0,sp,128
  ee:	18090503          	lb	a0,384(s2)
  f2:	0100                	addi	s0,sp,128
  f4:	18090503          	lb	a0,384(s2)
  f8:	0100                	addi	s0,sp,128
  fa:	18090503          	lb	a0,384(s2)
  fe:	0100                	addi	s0,sp,128
 100:	18090503          	lb	a0,384(s2)
 104:	0100                	addi	s0,sp,128
 106:	18090503          	lb	a0,384(s2)
 10a:	0100                	addi	s0,sp,128
 10c:	18090103          	lb	sp,384(s2)
 110:	0100                	addi	s0,sp,128
 112:	08090503          	lb	a0,128(s2)
 116:	0100                	addi	s0,sp,128
 118:	18090503          	lb	a0,384(s2)
 11c:	0100                	addi	s0,sp,128
 11e:	18090503          	lb	a0,384(s2)
 122:	0100                	addi	s0,sp,128
 124:	18090503          	lb	a0,384(s2)
 128:	0100                	addi	s0,sp,128
 12a:	18090503          	lb	a0,384(s2)
 12e:	0100                	addi	s0,sp,128
 130:	18090503          	lb	a0,384(s2)
 134:	0100                	addi	s0,sp,128
 136:	18090503          	lb	a0,384(s2)
 13a:	0100                	addi	s0,sp,128
 13c:	18090503          	lb	a0,384(s2)
 140:	0100                	addi	s0,sp,128
 142:	18090503          	lb	a0,384(s2)
 146:	0100                	addi	s0,sp,128
 148:	18090503          	lb	a0,384(s2)
 14c:	0100                	addi	s0,sp,128
 14e:	18090503          	lb	a0,384(s2)
 152:	0100                	addi	s0,sp,128
 154:	18090503          	lb	a0,384(s2)
 158:	0100                	addi	s0,sp,128
 15a:	18090403          	lb	s0,384(s2)
 15e:	0100                	addi	s0,sp,128
 160:	04090103          	lb	sp,64(s2)
 164:	0100                	addi	s0,sp,128
 166:	1009                	c.nop	-30
 168:	0000                	unimp
 16a:	0101                	addi	sp,sp,0

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
  14:	039c                	addi	a5,sp,448
  16:	8000                	0x8000
  18:	0000                	unimp
  1a:	0000                	unimp
  1c:	0064                	addi	s1,sp,12
  1e:	0000                	unimp
  20:	000000b7          	lui	ra,0x0
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
  14:	039c                	addi	a5,sp,448
	...

Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	6d6f682f          	0x6d6f682f
   4:	2f65                	jal	7bc <offset+0x78c>
   6:	6f6c                	flw	fa1,92(a4)
   8:	6976                	flw	fs2,92(sp)
   a:	65442f73          	csrrs	t5,0x654,s0
   e:	6f746b73          	csrrsi	s6,0x6f7,8
  12:	2f70                	fld	fa2,216(a4)
  14:	6952                	flw	fs2,20(sp)
  16:	6556                	flw	fa0,84(sp)
  18:	5f72                	lw	t5,60(sp)
  1a:	65726f63          	bltu	tp,s7,678 <offset+0x648>
  1e:	7369722f          	0x7369722f
  22:	2f666f63          	bltu	a2,s6,320 <offset+0x2f0>
  26:	6972                	flw	fs2,28(sp)
  28:	2d766373          	csrrsi	t1,0x2d7,12
  2c:	7261                	lui	tp,0xffff8
  2e:	742d6863          	bltu	s10,sp,77e <offset+0x74e>
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
  54:	75626c2f          	0x75626c2f
  58:	612d                	addi	sp,sp,224
  5a:	696c                	flw	fa1,84(a0)
  5c:	302d6e67          	0x302d6e67
  60:	2e31                	jal	37c <offset+0x34c>
  62:	682f0053          	0x682f0053
  66:	2f656d6f          	jal	s10,5635c <offset+0x5632c>
  6a:	6f6c                	flw	fa1,92(a4)
  6c:	6976                	flw	fs2,92(sp)
  6e:	65442f73          	csrrs	t5,0x654,s0
  72:	6f746b73          	csrrsi	s6,0x6f7,8
  76:	2f70                	fld	fa2,216(a4)
  78:	6952                	flw	fs2,20(sp)
  7a:	6556                	flw	fa0,84(sp)
  7c:	5f72                	lw	t5,60(sp)
  7e:	65726f63          	bltu	tp,s7,6dc <offset+0x6ac>
  82:	7369722f          	0x7369722f
  86:	2f666f63          	bltu	a2,s6,384 <offset+0x354>
  8a:	6972                	flw	fs2,28(sp)
  8c:	666f6373          	csrrsi	t1,0x666,30
  90:	775f 726f 2f6b      	0x2f6b726f775f
  96:	7672                	flw	fa2,60(sp)
  98:	5f693233          	0x5f693233
  9c:	2f6d                	jal	856 <offset+0x826>
  9e:	2f49                	jal	830 <offset+0x800>
  a0:	2f637273          	csrrci	tp,0x2f6,6
  a4:	626c                	flw	fa1,68(a2)
  a6:	2d75                	jal	762 <offset+0x732>
  a8:	6c61                	lui	s8,0x18
  aa:	6769                	lui	a4,0x1a
  ac:	2d6e                	fld	fs10,216(sp)
  ae:	3130                	fld	fa2,96(a0)
  b0:	532e                	lw	t1,232(sp)
  b2:	7475642f          	0x7475642f
  b6:	4700                	lw	s0,8(a4)
  b8:	554e                	lw	a0,240(sp)
  ba:	4120                	lw	s0,64(a0)
  bc:	2e322053          	0x2e322053
  c0:	          	snez	a0,zero
