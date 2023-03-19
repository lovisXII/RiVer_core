
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
80000078:	00003197          	auipc	gp,0x3
8000007c:	09c18193          	addi	gp,gp,156 # 80003114 <signature_x3_0>

80000080 <inst_0>:
80000080:	00002a97          	auipc	s5,0x2
80000084:	e90a8a93          	addi	s5,s5,-368 # 80001f10 <fromhost+0xe10>
80000088:	100a9583          	lh	a1,256(s5)
8000008c:	00000013          	nop
80000090:	00000013          	nop
80000094:	00b1a023          	sw	a1,0(gp)

80000098 <inst_1>:
80000098:	00002f97          	auipc	t6,0x2
8000009c:	f73f8f93          	addi	t6,t6,-141 # 8000200b <rvtest_trap_sig+0xb>
800000a0:	005f9f83          	lh	t6,5(t6)
800000a4:	00000013          	nop
800000a8:	00000013          	nop
800000ac:	01f1a223          	sw	t6,4(gp)

800000b0 <inst_2>:
800000b0:	00002717          	auipc	a4,0x2
800000b4:	4b670713          	addi	a4,a4,1206 # 80002566 <rvtest_data_end+0x53e>
800000b8:	aaa71083          	lh	ra,-1366(a4)
800000bc:	00000013          	nop
800000c0:	00000013          	nop
800000c4:	0011a423          	sw	ra,8(gp)

800000c8 <inst_3>:
800000c8:	00002317          	auipc	t1,0x2
800000cc:	b4930313          	addi	t1,t1,-1207 # 80001c11 <fromhost+0xb11>
800000d0:	3ff31f03          	lh	t5,1023(t1)
800000d4:	00000013          	nop
800000d8:	00000013          	nop
800000dc:	01e1a623          	sw	t5,12(gp)

800000e0 <inst_4>:
800000e0:	00002a17          	auipc	s4,0x2
800000e4:	f12a0a13          	addi	s4,s4,-238 # 80001ff2 <fromhost+0xef2>
800000e8:	020a1683          	lh	a3,32(s4)
800000ec:	00000013          	nop
800000f0:	00000013          	nop
800000f4:	00d1a823          	sw	a3,16(gp)

800000f8 <inst_5>:
800000f8:	00002497          	auipc	s1,0x2
800000fc:	f1848493          	addi	s1,s1,-232 # 80002010 <rvtest_data_begin>
80000100:	00049883          	lh	a7,0(s1)
80000104:	00000013          	nop
80000108:	00000013          	nop
8000010c:	0111aa23          	sw	a7,20(gp)

80000110 <inst_6>:
80000110:	00002b17          	auipc	s6,0x2
80000114:	f01b0b13          	addi	s6,s6,-255 # 80002011 <rvtest_data_begin+0x1>
80000118:	001b1983          	lh	s3,1(s6)
8000011c:	00000013          	nop
80000120:	00000013          	nop
80000124:	0131ac23          	sw	s3,24(gp)

80000128 <inst_7>:
80000128:	00002917          	auipc	s2,0x2
8000012c:	eec90913          	addi	s2,s2,-276 # 80002014 <rvtest_data_begin+0x4>
80000130:	ffe91b83          	lh	s7,-2(s2)
80000134:	00000013          	nop
80000138:	00000013          	nop
8000013c:	0171ae23          	sw	s7,28(gp)

80000140 <inst_8>:
80000140:	00002d97          	auipc	s11,0x2
80000144:	ed3d8d93          	addi	s11,s11,-301 # 80002013 <rvtest_data_begin+0x3>
80000148:	fffd9e83          	lh	t4,-1(s11)
8000014c:	00000013          	nop
80000150:	00000013          	nop
80000154:	03d1a023          	sw	t4,32(gp)

80000158 <inst_9>:
80000158:	00002397          	auipc	t2,0x2
8000015c:	6b838393          	addi	t2,t2,1720 # 80002810 <rvtest_data_end+0x7e8>
80000160:	80039803          	lh	a6,-2048(t2)
80000164:	00000013          	nop
80000168:	00000013          	nop
8000016c:	0301a223          	sw	a6,36(gp)

80000170 <inst_10>:
80000170:	00002617          	auipc	a2,0x2
80000174:	6a060613          	addi	a2,a2,1696 # 80002810 <rvtest_data_end+0x7e8>
80000178:	80061203          	lh	tp,-2048(a2)
8000017c:	00000013          	nop
80000180:	00000013          	nop
80000184:	0241a423          	sw	tp,40(gp)

80000188 <inst_11>:
80000188:	00002c17          	auipc	s8,0x2
8000018c:	688c0c13          	addi	s8,s8,1672 # 80002810 <rvtest_data_end+0x7e8>
80000190:	800c1403          	lh	s0,-2048(s8)
80000194:	00000013          	nop
80000198:	00000013          	nop
8000019c:	0281a623          	sw	s0,44(gp)

800001a0 <inst_12>:
800001a0:	00002e97          	auipc	t4,0x2
800001a4:	670e8e93          	addi	t4,t4,1648 # 80002810 <rvtest_data_end+0x7e8>
800001a8:	800e9383          	lh	t2,-2048(t4)
800001ac:	00000013          	nop
800001b0:	00000013          	nop
800001b4:	0271a823          	sw	t2,48(gp)

800001b8 <inst_13>:
800001b8:	00002297          	auipc	t0,0x2
800001bc:	65828293          	addi	t0,t0,1624 # 80002810 <rvtest_data_end+0x7e8>
800001c0:	80029703          	lh	a4,-2048(t0)
800001c4:	00000013          	nop
800001c8:	00000013          	nop
800001cc:	02e1aa23          	sw	a4,52(gp)

800001d0 <inst_14>:
800001d0:	00002417          	auipc	s0,0x2
800001d4:	64040413          	addi	s0,s0,1600 # 80002810 <rvtest_data_end+0x7e8>
800001d8:	80041a03          	lh	s4,-2048(s0)
800001dc:	00000013          	nop
800001e0:	00000013          	nop
800001e4:	0341ac23          	sw	s4,56(gp)

800001e8 <inst_15>:
800001e8:	00002097          	auipc	ra,0x2
800001ec:	62808093          	addi	ra,ra,1576 # 80002810 <rvtest_data_end+0x7e8>
800001f0:	80009d83          	lh	s11,-2048(ra)
800001f4:	00000013          	nop
800001f8:	00000013          	nop
800001fc:	03b1ae23          	sw	s11,60(gp)

80000200 <inst_16>:
80000200:	00002697          	auipc	a3,0x2
80000204:	61068693          	addi	a3,a3,1552 # 80002810 <rvtest_data_end+0x7e8>
80000208:	80069e03          	lh	t3,-2048(a3)
8000020c:	00000013          	nop
80000210:	00000013          	nop
80000214:	05c1a023          	sw	t3,64(gp)

80000218 <inst_17>:
80000218:	00002d17          	auipc	s10,0x2
8000021c:	5f8d0d13          	addi	s10,s10,1528 # 80002810 <rvtest_data_end+0x7e8>
80000220:	800d1303          	lh	t1,-2048(s10)
80000224:	00000013          	nop
80000228:	00000013          	nop
8000022c:	0461a223          	sw	t1,68(gp)

80000230 <inst_18>:
80000230:	00002217          	auipc	tp,0x2
80000234:	5e020213          	addi	tp,tp,1504 # 80002810 <rvtest_data_end+0x7e8>
80000238:	80021103          	lh	sp,-2048(tp) # fffff800 <imm12sh+0xfffffa25>
8000023c:	00000013          	nop
80000240:	00000013          	nop
80000244:	0421a423          	sw	sp,72(gp)

80000248 <inst_19>:
80000248:	00002b97          	auipc	s7,0x2
8000024c:	5c8b8b93          	addi	s7,s7,1480 # 80002810 <rvtest_data_end+0x7e8>
80000250:	800b9a83          	lh	s5,-2048(s7)
80000254:	00000013          	nop
80000258:	00000013          	nop
8000025c:	0551a623          	sw	s5,76(gp)

80000260 <inst_20>:
80000260:	00002117          	auipc	sp,0x2
80000264:	5b010113          	addi	sp,sp,1456 # 80002810 <rvtest_data_end+0x7e8>
80000268:	80011d03          	lh	s10,-2048(sp)
8000026c:	00000013          	nop
80000270:	00000013          	nop
80000274:	05a1a823          	sw	s10,80(gp)

80000278 <inst_21>:
80000278:	00002c97          	auipc	s9,0x2
8000027c:	598c8c93          	addi	s9,s9,1432 # 80002810 <rvtest_data_end+0x7e8>
80000280:	800c9483          	lh	s1,-2048(s9)
80000284:	00000013          	nop
80000288:	00000013          	nop
8000028c:	0491aa23          	sw	s1,84(gp)
80000290:	00003097          	auipc	ra,0x3
80000294:	edc08093          	addi	ra,ra,-292 # 8000316c <signature_x1_0>

80000298 <inst_22>:
80000298:	00002f17          	auipc	t5,0x2
8000029c:	578f0f13          	addi	t5,t5,1400 # 80002810 <rvtest_data_end+0x7e8>
800002a0:	800f1903          	lh	s2,-2048(t5)
800002a4:	00000013          	nop
800002a8:	00000013          	nop
800002ac:	0120a023          	sw	s2,0(ra)

800002b0 <inst_23>:
800002b0:	00002517          	auipc	a0,0x2
800002b4:	56050513          	addi	a0,a0,1376 # 80002810 <rvtest_data_end+0x7e8>
800002b8:	80051b03          	lh	s6,-2048(a0)
800002bc:	00000013          	nop
800002c0:	00000013          	nop
800002c4:	0160a223          	sw	s6,4(ra)

800002c8 <inst_24>:
800002c8:	00002897          	auipc	a7,0x2
800002cc:	54888893          	addi	a7,a7,1352 # 80002810 <rvtest_data_end+0x7e8>
800002d0:	80089783          	lh	a5,-2048(a7)
800002d4:	00000013          	nop
800002d8:	00000013          	nop
800002dc:	00f0a423          	sw	a5,8(ra)

800002e0 <inst_25>:
800002e0:	00002797          	auipc	a5,0x2
800002e4:	53078793          	addi	a5,a5,1328 # 80002810 <rvtest_data_end+0x7e8>
800002e8:	80079c03          	lh	s8,-2048(a5)
800002ec:	00000013          	nop
800002f0:	00000013          	nop
800002f4:	0180a623          	sw	s8,12(ra)

800002f8 <inst_26>:
800002f8:	00002997          	auipc	s3,0x2
800002fc:	51898993          	addi	s3,s3,1304 # 80002810 <rvtest_data_end+0x7e8>
80000300:	80099603          	lh	a2,-2048(s3)
80000304:	00000013          	nop
80000308:	00000013          	nop
8000030c:	00c0a823          	sw	a2,16(ra)

80000310 <inst_27>:
80000310:	00002e17          	auipc	t3,0x2
80000314:	500e0e13          	addi	t3,t3,1280 # 80002810 <rvtest_data_end+0x7e8>
80000318:	800e1503          	lh	a0,-2048(t3)
8000031c:	00000013          	nop
80000320:	00000013          	nop
80000324:	00a0aa23          	sw	a0,20(ra)

80000328 <inst_28>:
80000328:	00002597          	auipc	a1,0x2
8000032c:	4e858593          	addi	a1,a1,1256 # 80002810 <rvtest_data_end+0x7e8>
80000330:	80059183          	lh	gp,-2048(a1)
80000334:	00000013          	nop
80000338:	00000013          	nop
8000033c:	0030ac23          	sw	gp,24(ra)

80000340 <inst_29>:
80000340:	00002817          	auipc	a6,0x2
80000344:	4d080813          	addi	a6,a6,1232 # 80002810 <rvtest_data_end+0x7e8>
80000348:	80081c83          	lh	s9,-2048(a6)
8000034c:	00000013          	nop
80000350:	00000013          	nop
80000354:	0190ae23          	sw	s9,28(ra)

80000358 <inst_30>:
80000358:	00002197          	auipc	gp,0x2
8000035c:	4b818193          	addi	gp,gp,1208 # 80002810 <rvtest_data_end+0x7e8>
80000360:	80019283          	lh	t0,-2048(gp)
80000364:	00000013          	nop
80000368:	00000013          	nop
8000036c:	0250a023          	sw	t0,32(ra)

80000370 <inst_31>:
80000370:	00002897          	auipc	a7,0x2
80000374:	4a088893          	addi	a7,a7,1184 # 80002810 <rvtest_data_end+0x7e8>
80000378:	80089003          	lh	zero,-2048(a7)
8000037c:	00000013          	nop
80000380:	00000013          	nop
80000384:	0200a223          	sw	zero,36(ra)

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

80003114 <signature_x3_0>:
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
   0:	00000167          	jalr	sp,zero # 0 <cryh>
   4:	00790003          	lb	zero,7(s2)
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
  9c:	0018                	0x18
  9e:	0301                	addi	t1,t1,0
  a0:	0905                	addi	s2,s2,1
  a2:	0018                	0x18
  a4:	0301                	addi	t1,t1,0
  a6:	0905                	addi	s2,s2,1
  a8:	0018                	0x18
  aa:	0301                	addi	t1,t1,0
  ac:	0905                	addi	s2,s2,1
  ae:	0018                	0x18
  b0:	0301                	addi	t1,t1,0
  b2:	0905                	addi	s2,s2,1
  b4:	0018                	0x18
  b6:	0301                	addi	t1,t1,0
  b8:	0905                	addi	s2,s2,1
  ba:	0018                	0x18
  bc:	0301                	addi	t1,t1,0
  be:	0905                	addi	s2,s2,1
  c0:	0018                	0x18
  c2:	0301                	addi	t1,t1,0
  c4:	0905                	addi	s2,s2,1
  c6:	0018                	0x18
  c8:	0301                	addi	t1,t1,0
  ca:	0905                	addi	s2,s2,1
  cc:	0018                	0x18
  ce:	0301                	addi	t1,t1,0
  d0:	0905                	addi	s2,s2,1
  d2:	0018                	0x18
  d4:	0301                	addi	t1,t1,0
  d6:	0905                	addi	s2,s2,1
  d8:	0018                	0x18
  da:	0301                	addi	t1,t1,0
  dc:	0905                	addi	s2,s2,1
  de:	0018                	0x18
  e0:	0301                	addi	t1,t1,0
  e2:	0905                	addi	s2,s2,1
  e4:	0018                	0x18
  e6:	0301                	addi	t1,t1,0
  e8:	0905                	addi	s2,s2,1
  ea:	0018                	0x18
  ec:	0301                	addi	t1,t1,0
  ee:	0905                	addi	s2,s2,1
  f0:	0018                	0x18
  f2:	0301                	addi	t1,t1,0
  f4:	0905                	addi	s2,s2,1
  f6:	0018                	0x18
  f8:	0301                	addi	t1,t1,0
  fa:	0905                	addi	s2,s2,1
  fc:	0018                	0x18
  fe:	0301                	addi	t1,t1,0
 100:	0905                	addi	s2,s2,1
 102:	0018                	0x18
 104:	0301                	addi	t1,t1,0
 106:	0905                	addi	s2,s2,1
 108:	0018                	0x18
 10a:	0301                	addi	t1,t1,0
 10c:	0905                	addi	s2,s2,1
 10e:	0018                	0x18
 110:	0301                	addi	t1,t1,0
 112:	0905                	addi	s2,s2,1
 114:	0018                	0x18
 116:	0301                	addi	t1,t1,0
 118:	0901                	addi	s2,s2,0
 11a:	0018                	0x18
 11c:	0301                	addi	t1,t1,0
 11e:	0905                	addi	s2,s2,1
 120:	0008                	0x8
 122:	0301                	addi	t1,t1,0
 124:	0905                	addi	s2,s2,1
 126:	0018                	0x18
 128:	0301                	addi	t1,t1,0
 12a:	0905                	addi	s2,s2,1
 12c:	0018                	0x18
 12e:	0301                	addi	t1,t1,0
 130:	0905                	addi	s2,s2,1
 132:	0018                	0x18
 134:	0301                	addi	t1,t1,0
 136:	0905                	addi	s2,s2,1
 138:	0018                	0x18
 13a:	0301                	addi	t1,t1,0
 13c:	0905                	addi	s2,s2,1
 13e:	0018                	0x18
 140:	0301                	addi	t1,t1,0
 142:	0905                	addi	s2,s2,1
 144:	0018                	0x18
 146:	0301                	addi	t1,t1,0
 148:	0905                	addi	s2,s2,1
 14a:	0018                	0x18
 14c:	0301                	addi	t1,t1,0
 14e:	0905                	addi	s2,s2,1
 150:	0018                	0x18
 152:	0301                	addi	t1,t1,0
 154:	0905                	addi	s2,s2,1
 156:	0018                	0x18
 158:	0301                	addi	t1,t1,0
 15a:	0904                	addi	s1,sp,144
 15c:	0018                	0x18
 15e:	0301                	addi	t1,t1,0
 160:	0901                	addi	s2,s2,0
 162:	0004                	0x4
 164:	0901                	addi	s2,s2,0
 166:	0010                	0x10
 168:	0100                	addi	s0,sp,128
 16a:	01              	Address 0x000000000000016a is out of bounds.


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
  54:	2d686c2f          	0x2d686c2f
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
  8c:	5f666f63          	bltu	a2,s6,68a <offset+0x662>
  90:	6b726f77          	0x6b726f77
  94:	3376722f          	0x3376722f
  98:	6932                	flw	fs2,12(sp)
  9a:	6d5f 492f 732f      	0x732f492f6d5f
  a0:	6372                	flw	ft6,28(sp)
  a2:	2d686c2f          	0x2d686c2f
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
