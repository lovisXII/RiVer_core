
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
80000078:	00003517          	auipc	a0,0x3
8000007c:	09c50513          	addi	a0,a0,156 # 80003114 <signature_x10_0>

80000080 <inst_0>:
80000080:	00002617          	auipc	a2,0x2
80000084:	f9860613          	addi	a2,a2,-104 # 80002018 <rvtest_data_begin+0x8>
80000088:	ff860a03          	lb	s4,-8(a2)
8000008c:	00000013          	nop
80000090:	00000013          	nop
80000094:	01452023          	sw	s4,0(a0)

80000098 <inst_1>:
80000098:	00002117          	auipc	sp,0x2
8000009c:	a2310113          	addi	sp,sp,-1501 # 80001abb <fromhost+0x9bb>
800000a0:	55510103          	lb	sp,1365(sp)
800000a4:	00000013          	nop
800000a8:	00000013          	nop
800000ac:	00252223          	sw	sp,4(a0)

800000b0 <inst_2>:
800000b0:	00002917          	auipc	s2,0x2
800000b4:	f5a90913          	addi	s2,s2,-166 # 8000200a <rvtest_trap_sig+0xa>
800000b8:	00690803          	lb	a6,6(s2)
800000bc:	00000013          	nop
800000c0:	00000013          	nop
800000c4:	01052423          	sw	a6,8(a0)

800000c8 <inst_3>:
800000c8:	00002b97          	auipc	s7,0x2
800000cc:	f69b8b93          	addi	s7,s7,-151 # 80002031 <rvtest_data_end+0x9>
800000d0:	fdfb8e83          	lb	t4,-33(s7)
800000d4:	00000013          	nop
800000d8:	00000013          	nop
800000dc:	01d52623          	sw	t4,12(a0)

800000e0 <inst_4>:
800000e0:	00002097          	auipc	ra,0x2
800000e4:	33208093          	addi	ra,ra,818 # 80002412 <rvtest_data_end+0x3ea>
800000e8:	c0008783          	lb	a5,-1024(ra)
800000ec:	00000013          	nop
800000f0:	00000013          	nop
800000f4:	00f52823          	sw	a5,16(a0)

800000f8 <inst_5>:
800000f8:	00002417          	auipc	s0,0x2
800000fc:	f2140413          	addi	s0,s0,-223 # 80002019 <rvtest_data_begin+0x9>
80000100:	ff940d03          	lb	s10,-7(s0)
80000104:	00000013          	nop
80000108:	00000013          	nop
8000010c:	01a52a23          	sw	s10,20(a0)

80000110 <inst_6>:
80000110:	00002197          	auipc	gp,0x2
80000114:	f0c18193          	addi	gp,gp,-244 # 8000201c <rvtest_data_begin+0xc>
80000118:	ff618a83          	lb	s5,-10(gp)
8000011c:	00000013          	nop
80000120:	00000013          	nop
80000124:	01552c23          	sw	s5,24(a0)

80000128 <inst_7>:
80000128:	00002497          	auipc	s1,0x2
8000012c:	ee348493          	addi	s1,s1,-285 # 8000200b <rvtest_trap_sig+0xb>
80000130:	00748883          	lb	a7,7(s1)
80000134:	00000013          	nop
80000138:	00000013          	nop
8000013c:	01152e23          	sw	a7,28(a0)

80000140 <inst_8>:
80000140:	00002e97          	auipc	t4,0x2
80000144:	ed9e8e93          	addi	t4,t4,-295 # 80002019 <rvtest_data_begin+0x9>
80000148:	ff8e8003          	lb	zero,-8(t4)
8000014c:	00000013          	nop
80000150:	00000013          	nop
80000154:	02052023          	sw	zero,32(a0)

80000158 <inst_9>:
80000158:	00002c97          	auipc	s9,0x2
8000015c:	eb4c8c93          	addi	s9,s9,-332 # 8000200c <rvtest_trap_sig+0xc>
80000160:	005c8f03          	lb	t5,5(s9)
80000164:	00000013          	nop
80000168:	00000013          	nop
8000016c:	03e52223          	sw	t5,36(a0)

80000170 <inst_10>:
80000170:	00002a97          	auipc	s5,0x2
80000174:	ea0a8a93          	addi	s5,s5,-352 # 80002010 <rvtest_data_begin>
80000178:	000a8d83          	lb	s11,0(s5)
8000017c:	00000013          	nop
80000180:	00000013          	nop
80000184:	03b52423          	sw	s11,40(a0)

80000188 <inst_11>:
80000188:	00002317          	auipc	t1,0x2
8000018c:	e8b30313          	addi	t1,t1,-373 # 80002013 <rvtest_data_begin+0x3>
80000190:	ffe30b83          	lb	s7,-2(t1)
80000194:	00000013          	nop
80000198:	00000013          	nop
8000019c:	03752623          	sw	s7,44(a0)

800001a0 <inst_12>:
800001a0:	00002217          	auipc	tp,0x2
800001a4:	e9220213          	addi	tp,tp,-366 # 80002032 <rvtest_data_end+0xa>
800001a8:	fdf20603          	lb	a2,-33(tp) # ffffffdf <imm12sh+0x204>
800001ac:	00000013          	nop
800001b0:	00000013          	nop
800001b4:	02c52823          	sw	a2,48(a0)

800001b8 <inst_13>:
800001b8:	00002b17          	auipc	s6,0x2
800001bc:	e5bb0b13          	addi	s6,s6,-421 # 80002013 <rvtest_data_begin+0x3>
800001c0:	000b0e03          	lb	t3,0(s6)
800001c4:	00000013          	nop
800001c8:	00000013          	nop
800001cc:	03c52a23          	sw	t3,52(a0)

800001d0 <inst_14>:
800001d0:	00002c17          	auipc	s8,0x2
800001d4:	e42c0c13          	addi	s8,s8,-446 # 80002012 <rvtest_data_begin+0x2>
800001d8:	001c0f83          	lb	t6,1(s8)
800001dc:	00000013          	nop
800001e0:	00000013          	nop
800001e4:	03f52c23          	sw	t6,56(a0)

800001e8 <inst_15>:
800001e8:	00002e17          	auipc	t3,0x2
800001ec:	e31e0e13          	addi	t3,t3,-463 # 80002019 <rvtest_data_begin+0x9>
800001f0:	ffae0383          	lb	t2,-6(t3)
800001f4:	00000013          	nop
800001f8:	00000013          	nop
800001fc:	02752e23          	sw	t2,60(a0)

80000200 <inst_16>:
80000200:	00002817          	auipc	a6,0x2
80000204:	e3480813          	addi	a6,a6,-460 # 80002034 <rvtest_data_end+0xc>
80000208:	fdf80683          	lb	a3,-33(a6)
8000020c:	00000013          	nop
80000210:	00000013          	nop
80000214:	04d52023          	sw	a3,64(a0)

80000218 <inst_17>:
80000218:	00002297          	auipc	t0,0x2
8000021c:	5f828293          	addi	t0,t0,1528 # 80002810 <rvtest_data_end+0x7e8>
80000220:	80028903          	lb	s2,-2048(t0)
80000224:	00000013          	nop
80000228:	00000013          	nop
8000022c:	05252223          	sw	s2,68(a0)

80000230 <inst_18>:
80000230:	00002d17          	auipc	s10,0x2
80000234:	5e0d0d13          	addi	s10,s10,1504 # 80002810 <rvtest_data_end+0x7e8>
80000238:	800d0703          	lb	a4,-2048(s10)
8000023c:	00000013          	nop
80000240:	00000013          	nop
80000244:	04e52423          	sw	a4,72(a0)
80000248:	00003117          	auipc	sp,0x3
8000024c:	f1810113          	addi	sp,sp,-232 # 80003160 <signature_x2_0>

80000250 <inst_19>:
80000250:	00002397          	auipc	t2,0x2
80000254:	5c038393          	addi	t2,t2,1472 # 80002810 <rvtest_data_end+0x7e8>
80000258:	80038c03          	lb	s8,-2048(t2)
8000025c:	00000013          	nop
80000260:	00000013          	nop
80000264:	01812023          	sw	s8,0(sp)

80000268 <inst_20>:
80000268:	00002597          	auipc	a1,0x2
8000026c:	5a858593          	addi	a1,a1,1448 # 80002810 <rvtest_data_end+0x7e8>
80000270:	80058083          	lb	ra,-2048(a1)
80000274:	00000013          	nop
80000278:	00000013          	nop
8000027c:	00112223          	sw	ra,4(sp)

80000280 <inst_21>:
80000280:	00002797          	auipc	a5,0x2
80000284:	59078793          	addi	a5,a5,1424 # 80002810 <rvtest_data_end+0x7e8>
80000288:	80078503          	lb	a0,-2048(a5)
8000028c:	00000013          	nop
80000290:	00000013          	nop
80000294:	00a12423          	sw	a0,8(sp)

80000298 <inst_22>:
80000298:	00002a17          	auipc	s4,0x2
8000029c:	578a0a13          	addi	s4,s4,1400 # 80002810 <rvtest_data_end+0x7e8>
800002a0:	800a0b03          	lb	s6,-2048(s4)
800002a4:	00000013          	nop
800002a8:	00000013          	nop
800002ac:	01612623          	sw	s6,12(sp)

800002b0 <inst_23>:
800002b0:	00002897          	auipc	a7,0x2
800002b4:	56088893          	addi	a7,a7,1376 # 80002810 <rvtest_data_end+0x7e8>
800002b8:	80088403          	lb	s0,-2048(a7)
800002bc:	00000013          	nop
800002c0:	00000013          	nop
800002c4:	00812823          	sw	s0,16(sp)

800002c8 <inst_24>:
800002c8:	00002d97          	auipc	s11,0x2
800002cc:	548d8d93          	addi	s11,s11,1352 # 80002810 <rvtest_data_end+0x7e8>
800002d0:	800d8483          	lb	s1,-2048(s11)
800002d4:	00000013          	nop
800002d8:	00000013          	nop
800002dc:	00912a23          	sw	s1,20(sp)

800002e0 <inst_25>:
800002e0:	00002697          	auipc	a3,0x2
800002e4:	53068693          	addi	a3,a3,1328 # 80002810 <rvtest_data_end+0x7e8>
800002e8:	80068583          	lb	a1,-2048(a3)
800002ec:	00000013          	nop
800002f0:	00000013          	nop
800002f4:	00b12c23          	sw	a1,24(sp)

800002f8 <inst_26>:
800002f8:	00002997          	auipc	s3,0x2
800002fc:	51898993          	addi	s3,s3,1304 # 80002810 <rvtest_data_end+0x7e8>
80000300:	80098203          	lb	tp,-2048(s3)
80000304:	00000013          	nop
80000308:	00000013          	nop
8000030c:	00412e23          	sw	tp,28(sp)

80000310 <inst_27>:
80000310:	00002f17          	auipc	t5,0x2
80000314:	500f0f13          	addi	t5,t5,1280 # 80002810 <rvtest_data_end+0x7e8>
80000318:	800f0983          	lb	s3,-2048(t5)
8000031c:	00000013          	nop
80000320:	00000013          	nop
80000324:	03312023          	sw	s3,32(sp)

80000328 <inst_28>:
80000328:	00002517          	auipc	a0,0x2
8000032c:	4e850513          	addi	a0,a0,1256 # 80002810 <rvtest_data_end+0x7e8>
80000330:	80050283          	lb	t0,-2048(a0)
80000334:	00000013          	nop
80000338:	00000013          	nop
8000033c:	02512223          	sw	t0,36(sp)

80000340 <inst_29>:
80000340:	00002717          	auipc	a4,0x2
80000344:	4d070713          	addi	a4,a4,1232 # 80002810 <rvtest_data_end+0x7e8>
80000348:	80070303          	lb	t1,-2048(a4)
8000034c:	00000013          	nop
80000350:	00000013          	nop
80000354:	02612423          	sw	t1,40(sp)

80000358 <inst_30>:
80000358:	00002f97          	auipc	t6,0x2
8000035c:	4b8f8f93          	addi	t6,t6,1208 # 80002810 <rvtest_data_end+0x7e8>
80000360:	800f8c83          	lb	s9,-2048(t6)
80000364:	00000013          	nop
80000368:	00000013          	nop
8000036c:	03912623          	sw	s9,44(sp)

80000370 <inst_31>:
80000370:	00002e97          	auipc	t4,0x2
80000374:	4a0e8e93          	addi	t4,t4,1184 # 80002810 <rvtest_data_end+0x7e8>
80000378:	800e8183          	lb	gp,-2048(t4)
8000037c:	00000013          	nop
80000380:	00000013          	nop
80000384:	02312823          	sw	gp,48(sp)

80000388 <inst_32>:
80000388:	00002517          	auipc	a0,0x2
8000038c:	c9150513          	addi	a0,a0,-879 # 80002019 <rvtest_data_begin+0x9>
80000390:	ff850583          	lb	a1,-8(a0)
80000394:	00000013          	nop
80000398:	00000013          	nop
8000039c:	02b12a23          	sw	a1,52(sp)

800003a0 <cleanup_epilogs>:
800003a0:	0040006f          	j	800003a4 <exit_cleanup>

800003a4 <exit_cleanup>:
800003a4:	00100093          	li	ra,1

800003a8 <write_tohost>:
800003a8:	00001f17          	auipc	t5,0x1
800003ac:	c41f2c23          	sw	ra,-936(t5) # 80001000 <tohost>
800003b0:	ff9ff06f          	j	800003a8 <write_tohost>
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

80003114 <signature_x10_0>:
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

80003160 <signature_x2_0>:
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
80003188:	deadbeef          	jal	t4,7ffde772 <absimmsh+0x2a1e997>
8000318c:	deadbeef          	jal	t4,7ffde776 <absimmsh+0x2a1e99b>
80003190:	deadbeef          	jal	t4,7ffde77a <absimmsh+0x2a1e99f>
80003194:	deadbeef          	jal	t4,7ffde77e <absimmsh+0x2a1e9a3>

80003198 <sig_end_canary>:
80003198:	a309                	j	8000369a <_end+0x4fa>
8000319a:	6f5c                	flw	fa5,28(a4)

8000319c <rvtest_sig_end>:
8000319c:	0000                	unimp
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
   0:	016d                	addi	sp,sp,27
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
  1a:	2f01                	jal	72a <offset+0x6f2>
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
  44:	612d7663          	bgeu	s10,s2,650 <offset+0x618>
  48:	6372                	flw	ft6,28(sp)
  4a:	2d68                	fld	fa0,216(a0)
  4c:	6574                	flw	fa3,76(a0)
  4e:	722f7473          	csrrci	s0,0x722,30
  52:	7369                	lui	t1,0xffffa
  54:	742d7663          	bgeu	s10,sp,7a0 <offset+0x768>
  58:	7365                	lui	t1,0xffff9
  5a:	2d74                	fld	fa3,216(a0)
  5c:	74697573          	csrrci	a0,0x746,18
  60:	2f65                	jal	818 <offset+0x7e0>
  62:	7672                	flw	fa2,60(sp)
  64:	5f693233          	0x5f693233
  68:	2f6d                	jal	822 <offset+0x7ea>
  6a:	2f49                	jal	7fc <offset+0x7c4>
  6c:	00637273          	csrrci	tp,0x6,6
  70:	6c00                	flw	fs0,24(s0)
  72:	2d62                	fld	fs10,24(sp)
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
 106:	0901                	addi	s2,s2,0
 108:	0018                	0x18
 10a:	0301                	addi	t1,t1,0
 10c:	0905                	addi	s2,s2,1
 10e:	0008                	0x8
 110:	0301                	addi	t1,t1,0
 112:	0905                	addi	s2,s2,1
 114:	0018                	0x18
 116:	0301                	addi	t1,t1,0
 118:	0905                	addi	s2,s2,1
 11a:	0018                	0x18
 11c:	0301                	addi	t1,t1,0
 11e:	0905                	addi	s2,s2,1
 120:	0018                	0x18
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
 15a:	0905                	addi	s2,s2,1
 15c:	0018                	0x18
 15e:	0301                	addi	t1,t1,0
 160:	0904                	addi	s1,sp,144
 162:	0018                	0x18
 164:	0301                	addi	t1,t1,0
 166:	0901                	addi	s2,s2,0
 168:	0004                	0x4
 16a:	0901                	addi	s2,s2,0
 16c:	0010                	0x10
 16e:	0100                	addi	s0,sp,128
 170:	01              	Address 0x0000000000000170 is out of bounds.


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
  14:	03b4                	addi	a3,sp,456
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
  14:	03b4                	addi	a3,sp,456
	...

Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	6d6f682f          	0x6d6f682f
   4:	2f65                	jal	7bc <offset+0x784>
   6:	6f6c                	flw	fa1,92(a4)
   8:	6976                	flw	fs2,92(sp)
   a:	65442f73          	csrrs	t5,0x654,s0
   e:	6f746b73          	csrrsi	s6,0x6f7,8
  12:	2f70                	fld	fa2,216(a4)
  14:	6952                	flw	fs2,20(sp)
  16:	6556                	flw	fa0,84(sp)
  18:	5f72                	lw	t5,60(sp)
  1a:	65726f63          	bltu	tp,s7,678 <offset+0x640>
  1e:	7369722f          	0x7369722f
  22:	2f666f63          	bltu	a2,s6,320 <offset+0x2e8>
  26:	6972                	flw	fs2,28(sp)
  28:	2d766373          	csrrsi	t1,0x2d7,12
  2c:	7261                	lui	tp,0xffff8
  2e:	742d6863          	bltu	s10,sp,77e <offset+0x746>
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
  54:	2d626c2f          	0x2d626c2f
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
  8c:	5f666f63          	bltu	a2,s6,68a <offset+0x652>
  90:	6b726f77          	0x6b726f77
  94:	3376722f          	0x3376722f
  98:	6932                	flw	fs2,12(sp)
  9a:	6d5f 492f 732f      	0x732f492f6d5f
  a0:	6372                	flw	ft6,28(sp)
  a2:	2d626c2f          	0x2d626c2f
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
