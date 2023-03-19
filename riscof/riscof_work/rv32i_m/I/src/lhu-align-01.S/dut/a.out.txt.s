
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
80000078:	00003717          	auipc	a4,0x3
8000007c:	09c70713          	addi	a4,a4,156 # 80003114 <signature_x14_0>

80000080 <inst_0>:
80000080:	00002f17          	auipc	t5,0x2
80000084:	e90f0f13          	addi	t5,t5,-368 # 80001f10 <fromhost+0xe10>
80000088:	100f5003          	lhu	zero,256(t5)
8000008c:	00000013          	nop
80000090:	00000013          	nop
80000094:	00072023          	sw	zero,0(a4)

80000098 <inst_1>:
80000098:	00002f97          	auipc	t6,0x2
8000009c:	f7bf8f93          	addi	t6,t6,-133 # 80002013 <rvtest_data_begin+0x3>
800000a0:	ffdfdf83          	lhu	t6,-3(t6)
800000a4:	00000013          	nop
800000a8:	00000013          	nop
800000ac:	01f72223          	sw	t6,4(a4)

800000b0 <inst_2>:
800000b0:	00002c17          	auipc	s8,0x2
800000b4:	f62c0c13          	addi	s8,s8,-158 # 80002012 <rvtest_data_begin+0x2>
800000b8:	ffec5103          	lhu	sp,-2(s8)
800000bc:	00000013          	nop
800000c0:	00000013          	nop
800000c4:	00272423          	sw	sp,8(a4)

800000c8 <inst_3>:
800000c8:	00002d17          	auipc	s10,0x2
800000cc:	049d0d13          	addi	s10,s10,73 # 80002111 <rvtest_data_end+0xe9>
800000d0:	effd5c03          	lhu	s8,-257(s10)
800000d4:	00000013          	nop
800000d8:	00000013          	nop
800000dc:	01872623          	sw	s8,12(a4)

800000e0 <inst_4>:
800000e0:	00002397          	auipc	t2,0x2
800000e4:	eb238393          	addi	t2,t2,-334 # 80001f92 <fromhost+0xe92>
800000e8:	0803d183          	lhu	gp,128(t2)
800000ec:	00000013          	nop
800000f0:	00000013          	nop
800000f4:	00372823          	sw	gp,16(a4)

800000f8 <inst_5>:
800000f8:	00002217          	auipc	tp,0x2
800000fc:	f1820213          	addi	tp,tp,-232 # 80002010 <rvtest_data_begin>
80000100:	00025c83          	lhu	s9,0(tp) # 0 <cryh>
80000104:	00000013          	nop
80000108:	00000013          	nop
8000010c:	01972a23          	sw	s9,20(a4)

80000110 <inst_6>:
80000110:	00002917          	auipc	s2,0x2
80000114:	ef990913          	addi	s2,s2,-263 # 80002009 <rvtest_trap_sig+0x9>
80000118:	00995283          	lhu	t0,9(s2)
8000011c:	00000013          	nop
80000120:	00000013          	nop
80000124:	00572c23          	sw	t0,24(a4)

80000128 <inst_7>:
80000128:	00002197          	auipc	gp,0x2
8000012c:	44018193          	addi	gp,gp,1088 # 80002568 <rvtest_data_end+0x540>
80000130:	aaa1da83          	lhu	s5,-1366(gp)
80000134:	00000013          	nop
80000138:	00000013          	nop
8000013c:	01572e23          	sw	s5,28(a4)

80000140 <inst_8>:
80000140:	00002e97          	auipc	t4,0x2
80000144:	ef3e8e93          	addi	t4,t4,-269 # 80002033 <rvtest_data_end+0xb>
80000148:	fdfed203          	lhu	tp,-33(t4)
8000014c:	00000013          	nop
80000150:	00000013          	nop
80000154:	02472023          	sw	tp,32(a4)

80000158 <inst_9>:
80000158:	00002597          	auipc	a1,0x2
8000015c:	6b858593          	addi	a1,a1,1720 # 80002810 <rvtest_data_end+0x7e8>
80000160:	8005d683          	lhu	a3,-2048(a1)
80000164:	00000013          	nop
80000168:	00000013          	nop
8000016c:	02d72223          	sw	a3,36(a4)

80000170 <inst_10>:
80000170:	00002a97          	auipc	s5,0x2
80000174:	6a0a8a93          	addi	s5,s5,1696 # 80002810 <rvtest_data_end+0x7e8>
80000178:	800ad603          	lhu	a2,-2048(s5)
8000017c:	00000013          	nop
80000180:	00000013          	nop
80000184:	02c72423          	sw	a2,40(a4)

80000188 <inst_11>:
80000188:	00002317          	auipc	t1,0x2
8000018c:	68830313          	addi	t1,t1,1672 # 80002810 <rvtest_data_end+0x7e8>
80000190:	80035483          	lhu	s1,-2048(t1)
80000194:	00000013          	nop
80000198:	00000013          	nop
8000019c:	02972623          	sw	s1,44(a4)

800001a0 <inst_12>:
800001a0:	00002097          	auipc	ra,0x2
800001a4:	67008093          	addi	ra,ra,1648 # 80002810 <rvtest_data_end+0x7e8>
800001a8:	8000d383          	lhu	t2,-2048(ra)
800001ac:	00000013          	nop
800001b0:	00000013          	nop
800001b4:	02772823          	sw	t2,48(a4)

800001b8 <inst_13>:
800001b8:	00002517          	auipc	a0,0x2
800001bc:	65850513          	addi	a0,a0,1624 # 80002810 <rvtest_data_end+0x7e8>
800001c0:	80055783          	lhu	a5,-2048(a0)
800001c4:	00000013          	nop
800001c8:	00000013          	nop
800001cc:	02f72a23          	sw	a5,52(a4)

800001d0 <inst_14>:
800001d0:	00002797          	auipc	a5,0x2
800001d4:	64078793          	addi	a5,a5,1600 # 80002810 <rvtest_data_end+0x7e8>
800001d8:	8007d083          	lhu	ra,-2048(a5)
800001dc:	00000013          	nop
800001e0:	00000013          	nop
800001e4:	02172c23          	sw	ra,56(a4)

800001e8 <inst_15>:
800001e8:	00002e17          	auipc	t3,0x2
800001ec:	628e0e13          	addi	t3,t3,1576 # 80002810 <rvtest_data_end+0x7e8>
800001f0:	800e5303          	lhu	t1,-2048(t3)
800001f4:	00000013          	nop
800001f8:	00000013          	nop
800001fc:	02672e23          	sw	t1,60(a4)

80000200 <inst_16>:
80000200:	00002817          	auipc	a6,0x2
80000204:	61080813          	addi	a6,a6,1552 # 80002810 <rvtest_data_end+0x7e8>
80000208:	80085e83          	lhu	t4,-2048(a6)
8000020c:	00000013          	nop
80000210:	00000013          	nop
80000214:	05d72023          	sw	t4,64(a4)

80000218 <inst_17>:
80000218:	00002697          	auipc	a3,0x2
8000021c:	5f868693          	addi	a3,a3,1528 # 80002810 <rvtest_data_end+0x7e8>
80000220:	8006d903          	lhu	s2,-2048(a3)
80000224:	00000013          	nop
80000228:	00000013          	nop
8000022c:	05272223          	sw	s2,68(a4)

80000230 <inst_18>:
80000230:	00002417          	auipc	s0,0x2
80000234:	5e040413          	addi	s0,s0,1504 # 80002810 <rvtest_data_end+0x7e8>
80000238:	80045a03          	lhu	s4,-2048(s0)
8000023c:	00000013          	nop
80000240:	00000013          	nop
80000244:	05472423          	sw	s4,72(a4)

80000248 <inst_19>:
80000248:	00002b17          	auipc	s6,0x2
8000024c:	5c8b0b13          	addi	s6,s6,1480 # 80002810 <rvtest_data_end+0x7e8>
80000250:	800b5883          	lhu	a7,-2048(s6)
80000254:	00000013          	nop
80000258:	00000013          	nop
8000025c:	05172623          	sw	a7,76(a4)

80000260 <inst_20>:
80000260:	00002497          	auipc	s1,0x2
80000264:	5b048493          	addi	s1,s1,1456 # 80002810 <rvtest_data_end+0x7e8>
80000268:	8004de03          	lhu	t3,-2048(s1)
8000026c:	00000013          	nop
80000270:	00000013          	nop
80000274:	05c72823          	sw	t3,80(a4)

80000278 <inst_21>:
80000278:	00002c97          	auipc	s9,0x2
8000027c:	598c8c93          	addi	s9,s9,1432 # 80002810 <rvtest_data_end+0x7e8>
80000280:	800cd983          	lhu	s3,-2048(s9)
80000284:	00000013          	nop
80000288:	00000013          	nop
8000028c:	05372a23          	sw	s3,84(a4)
80000290:	00003097          	auipc	ra,0x3
80000294:	edc08093          	addi	ra,ra,-292 # 8000316c <signature_x1_0>

80000298 <inst_22>:
80000298:	00002d97          	auipc	s11,0x2
8000029c:	578d8d93          	addi	s11,s11,1400 # 80002810 <rvtest_data_end+0x7e8>
800002a0:	800ddb03          	lhu	s6,-2048(s11)
800002a4:	00000013          	nop
800002a8:	00000013          	nop
800002ac:	0160a023          	sw	s6,0(ra)

800002b0 <inst_23>:
800002b0:	00002117          	auipc	sp,0x2
800002b4:	56010113          	addi	sp,sp,1376 # 80002810 <rvtest_data_end+0x7e8>
800002b8:	80015b83          	lhu	s7,-2048(sp)
800002bc:	00000013          	nop
800002c0:	00000013          	nop
800002c4:	0170a223          	sw	s7,4(ra)

800002c8 <inst_24>:
800002c8:	00002a17          	auipc	s4,0x2
800002cc:	548a0a13          	addi	s4,s4,1352 # 80002810 <rvtest_data_end+0x7e8>
800002d0:	800a5f03          	lhu	t5,-2048(s4)
800002d4:	00000013          	nop
800002d8:	00000013          	nop
800002dc:	01e0a423          	sw	t5,8(ra)

800002e0 <inst_25>:
800002e0:	00002297          	auipc	t0,0x2
800002e4:	53028293          	addi	t0,t0,1328 # 80002810 <rvtest_data_end+0x7e8>
800002e8:	8002dd03          	lhu	s10,-2048(t0)
800002ec:	00000013          	nop
800002f0:	00000013          	nop
800002f4:	01a0a623          	sw	s10,12(ra)

800002f8 <inst_26>:
800002f8:	00002717          	auipc	a4,0x2
800002fc:	51870713          	addi	a4,a4,1304 # 80002810 <rvtest_data_end+0x7e8>
80000300:	80075d83          	lhu	s11,-2048(a4)
80000304:	00000013          	nop
80000308:	00000013          	nop
8000030c:	01b0a823          	sw	s11,16(ra)

80000310 <inst_27>:
80000310:	00002b97          	auipc	s7,0x2
80000314:	500b8b93          	addi	s7,s7,1280 # 80002810 <rvtest_data_end+0x7e8>
80000318:	800bd503          	lhu	a0,-2048(s7)
8000031c:	00000013          	nop
80000320:	00000013          	nop
80000324:	00a0aa23          	sw	a0,20(ra)

80000328 <inst_28>:
80000328:	00002617          	auipc	a2,0x2
8000032c:	4e860613          	addi	a2,a2,1256 # 80002810 <rvtest_data_end+0x7e8>
80000330:	80065703          	lhu	a4,-2048(a2)
80000334:	00000013          	nop
80000338:	00000013          	nop
8000033c:	00e0ac23          	sw	a4,24(ra)

80000340 <inst_29>:
80000340:	00002997          	auipc	s3,0x2
80000344:	4d098993          	addi	s3,s3,1232 # 80002810 <rvtest_data_end+0x7e8>
80000348:	8009d403          	lhu	s0,-2048(s3)
8000034c:	00000013          	nop
80000350:	00000013          	nop
80000354:	0080ae23          	sw	s0,28(ra)

80000358 <inst_30>:
80000358:	00002897          	auipc	a7,0x2
8000035c:	4b888893          	addi	a7,a7,1208 # 80002810 <rvtest_data_end+0x7e8>
80000360:	8008d583          	lhu	a1,-2048(a7)
80000364:	00000013          	nop
80000368:	00000013          	nop
8000036c:	02b0a023          	sw	a1,32(ra)

80000370 <inst_31>:
80000370:	00002297          	auipc	t0,0x2
80000374:	4a028293          	addi	t0,t0,1184 # 80002810 <rvtest_data_end+0x7e8>
80000378:	8002d803          	lhu	a6,-2048(t0)
8000037c:	00000013          	nop
80000380:	00000013          	nop
80000384:	0300a223          	sw	a6,36(ra)

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

80003114 <signature_x14_0>:
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

8000316c <signature_x1_0>:
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
  1a:	2f01                	jal	72a <offset+0x702>
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
  44:	612d7663          	bgeu	s10,s2,650 <offset+0x628>
  48:	6372                	flw	ft6,28(sp)
  4a:	2d68                	fld	fa0,216(a0)
  4c:	6574                	flw	fa3,76(a0)
  4e:	722f7473          	csrrci	s0,0x722,30
  52:	7369                	lui	t1,0xffffa
  54:	742d7663          	bgeu	s10,sp,7a0 <offset+0x778>
  58:	7365                	lui	t1,0xffff9
  5a:	2d74                	fld	fa3,216(a0)
  5c:	74697573          	csrrci	a0,0x746,18
  60:	2f65                	jal	818 <offset+0x7f0>
  62:	7672                	flw	fa2,60(sp)
  64:	5f693233          	0x5f693233
  68:	2f6d                	jal	822 <offset+0x7fa>
  6a:	2f49                	jal	7fc <offset+0x7d4>
  6c:	00637273          	csrrci	tp,0x6,6
  70:	6c00                	flw	fs0,24(s0)
  72:	7568                	flw	fa0,108(a0)
  74:	612d                	addi	sp,sp,224
  76:	696c                	flw	fa1,84(a0)
  78:	302d6e67          	0x302d6e67
  7c:	2e31                	jal	398 <offset+0x370>
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
 10c:	18090503          	lb	a0,384(s2)
 110:	0100                	addi	s0,sp,128
 112:	18090503          	lb	a0,384(s2)
 116:	0100                	addi	s0,sp,128
 118:	18090103          	lb	sp,384(s2)
 11c:	0100                	addi	s0,sp,128
 11e:	08090503          	lb	a0,128(s2)
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
   4:	2f65                	jal	7bc <offset+0x794>
   6:	6f6c                	flw	fa1,92(a4)
   8:	6976                	flw	fs2,92(sp)
   a:	65442f73          	csrrs	t5,0x654,s0
   e:	6f746b73          	csrrsi	s6,0x6f7,8
  12:	2f70                	fld	fa2,216(a4)
  14:	6952                	flw	fs2,20(sp)
  16:	6556                	flw	fa0,84(sp)
  18:	5f72                	lw	t5,60(sp)
  1a:	65726f63          	bltu	tp,s7,678 <offset+0x650>
  1e:	7369722f          	0x7369722f
  22:	2f666f63          	bltu	a2,s6,320 <offset+0x2f8>
  26:	6972                	flw	fs2,28(sp)
  28:	2d766373          	csrrsi	t1,0x2d7,12
  2c:	7261                	lui	tp,0xffff8
  2e:	742d6863          	bltu	s10,sp,77e <offset+0x756>
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
  54:	75686c2f          	0x75686c2f
  58:	612d                	addi	sp,sp,224
  5a:	696c                	flw	fa1,84(a0)
  5c:	302d6e67          	0x302d6e67
  60:	2e31                	jal	37c <offset+0x354>
  62:	682f0053          	0x682f0053
  66:	2f656d6f          	jal	s10,5635c <offset+0x56334>
  6a:	6f6c                	flw	fa1,92(a4)
  6c:	6976                	flw	fs2,92(sp)
  6e:	65442f73          	csrrs	t5,0x654,s0
  72:	6f746b73          	csrrsi	s6,0x6f7,8
  76:	2f70                	fld	fa2,216(a4)
  78:	6952                	flw	fs2,20(sp)
  7a:	6556                	flw	fa0,84(sp)
  7c:	5f72                	lw	t5,60(sp)
  7e:	65726f63          	bltu	tp,s7,6dc <offset+0x6b4>
  82:	7369722f          	0x7369722f
  86:	2f666f63          	bltu	a2,s6,384 <offset+0x35c>
  8a:	6972                	flw	fs2,28(sp)
  8c:	666f6373          	csrrsi	t1,0x666,30
  90:	775f 726f 2f6b      	0x2f6b726f775f
  96:	7672                	flw	fa2,60(sp)
  98:	5f693233          	0x5f693233
  9c:	2f6d                	jal	856 <offset+0x82e>
  9e:	2f49                	jal	830 <offset+0x808>
  a0:	2f637273          	csrrci	tp,0x2f6,6
  a4:	686c                	flw	fa1,84(s0)
  a6:	2d75                	jal	762 <offset+0x73a>
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
