
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
80000080:	00000c97          	auipc	s9,0x0
80000084:	000c8c93          	mv	s9,s9
80000088:	00000217          	auipc	tp,0x0
8000008c:	fdc20213          	addi	tp,tp,-36 # 80000064 <rvtest_entry_point+0x64>
80000090:	04020ce7          	jalr	s9,64(tp) # 0 <cryh>
80000094:	00000013          	nop
80000098:	00000013          	nop
8000009c:	002ccc93          	xori	s9,s9,2
800000a0:	00c0006f          	j	800000ac <inst_0+0x2c>
800000a4:	003ccc93          	xori	s9,s9,3
800000a8:	0040006f          	j	800000ac <inst_0+0x2c>
800000ac:	00000797          	auipc	a5,0x0
800000b0:	fd478793          	addi	a5,a5,-44 # 80000080 <inst_0>
800000b4:	ffc7f793          	andi	a5,a5,-4
800000b8:	40fc8cb3          	sub	s9,s9,a5
800000bc:	01952023          	sw	s9,0(a0)

800000c0 <inst_1>:
800000c0:	00000897          	auipc	a7,0x0
800000c4:	00088893          	mv	a7,a7
800000c8:	00000897          	auipc	a7,0x0
800000cc:	11d88893          	addi	a7,a7,285 # 800001e5 <inst_5+0x25>
800000d0:	eff888e7          	jalr	a7,-257(a7)
800000d4:	00000013          	nop
800000d8:	00000013          	nop
800000dc:	0028c893          	xori	a7,a7,2
800000e0:	00c0006f          	j	800000ec <inst_1+0x2c>
800000e4:	0038c893          	xori	a7,a7,3
800000e8:	0040006f          	j	800000ec <inst_1+0x2c>
800000ec:	00000797          	auipc	a5,0x0
800000f0:	fd478793          	addi	a5,a5,-44 # 800000c0 <inst_1>
800000f4:	ffc7f793          	andi	a5,a5,-4
800000f8:	40f888b3          	sub	a7,a7,a5
800000fc:	01152223          	sw	a7,4(a0)

80000100 <inst_2>:
80000100:	00000817          	auipc	a6,0x0
80000104:	00080813          	mv	a6,a6
80000108:	00000197          	auipc	gp,0x0
8000010c:	01b18193          	addi	gp,gp,27 # 80000123 <inst_2+0x23>
80000110:	00118867          	jalr	a6,1(gp)
80000114:	00000013          	nop
80000118:	00000013          	nop
8000011c:	00284813          	xori	a6,a6,2
80000120:	00c0006f          	j	8000012c <inst_2+0x2c>
80000124:	00384813          	xori	a6,a6,3
80000128:	0040006f          	j	8000012c <inst_2+0x2c>
8000012c:	00000797          	auipc	a5,0x0
80000130:	fd478793          	addi	a5,a5,-44 # 80000100 <inst_2>
80000134:	ffc7f793          	andi	a5,a5,-4
80000138:	40f80833          	sub	a6,a6,a5
8000013c:	01052423          	sw	a6,8(a0)

80000140 <inst_3>:
80000140:	00000617          	auipc	a2,0x0
80000144:	00060613          	mv	a2,a2
80000148:	00000b97          	auipc	s7,0x0
8000014c:	01ab8b93          	addi	s7,s7,26 # 80000162 <inst_3+0x22>
80000150:	002b8667          	jalr	a2,2(s7)
80000154:	00000013          	nop
80000158:	00000013          	nop
8000015c:	00264613          	xori	a2,a2,2
80000160:	00c0006f          	j	8000016c <inst_3+0x2c>
80000164:	00364613          	xori	a2,a2,3
80000168:	0040006f          	j	8000016c <inst_3+0x2c>
8000016c:	00000797          	auipc	a5,0x0
80000170:	fd478793          	addi	a5,a5,-44 # 80000140 <inst_3>
80000174:	ffc7f793          	andi	a5,a5,-4
80000178:	40f60633          	sub	a2,a2,a5
8000017c:	00c52623          	sw	a2,12(a0)

80000180 <inst_4>:
80000180:	00000697          	auipc	a3,0x0
80000184:	00068693          	mv	a3,a3
80000188:	00000d97          	auipc	s11,0x0
8000018c:	018d8d93          	addi	s11,s11,24 # 800001a0 <inst_4+0x20>
80000190:	004d86e7          	jalr	a3,4(s11)
80000194:	00000013          	nop
80000198:	00000013          	nop
8000019c:	0026c693          	xori	a3,a3,2
800001a0:	00c0006f          	j	800001ac <inst_4+0x2c>
800001a4:	0036c693          	xori	a3,a3,3
800001a8:	0040006f          	j	800001ac <inst_4+0x2c>
800001ac:	00000797          	auipc	a5,0x0
800001b0:	fd478793          	addi	a5,a5,-44 # 80000180 <inst_4>
800001b4:	ffc7f793          	andi	a5,a5,-4
800001b8:	40f686b3          	sub	a3,a3,a5
800001bc:	00d52823          	sw	a3,16(a0)

800001c0 <inst_5>:
800001c0:	00000417          	auipc	s0,0x0
800001c4:	00040413          	mv	s0,s0
800001c8:	00000317          	auipc	t1,0x0
800001cc:	01430313          	addi	t1,t1,20 # 800001dc <inst_5+0x1c>
800001d0:	00830467          	jalr	s0,8(t1)
800001d4:	00000013          	nop
800001d8:	00000013          	nop
800001dc:	00244413          	xori	s0,s0,2
800001e0:	00c0006f          	j	800001ec <inst_5+0x2c>
800001e4:	00344413          	xori	s0,s0,3
800001e8:	0040006f          	j	800001ec <inst_5+0x2c>
800001ec:	00000797          	auipc	a5,0x0
800001f0:	fd478793          	addi	a5,a5,-44 # 800001c0 <inst_5>
800001f4:	ffc7f793          	andi	a5,a5,-4
800001f8:	40f40433          	sub	s0,s0,a5
800001fc:	00852a23          	sw	s0,20(a0)

80000200 <inst_6>:
80000200:	00000f17          	auipc	t5,0x0
80000204:	000f0f13          	mv	t5,t5
80000208:	00000617          	auipc	a2,0x0
8000020c:	00c60613          	addi	a2,a2,12 # 80000214 <inst_6+0x14>
80000210:	01060f67          	jalr	t5,16(a2)
80000214:	00000013          	nop
80000218:	00000013          	nop
8000021c:	002f4f13          	xori	t5,t5,2
80000220:	00c0006f          	j	8000022c <inst_6+0x2c>
80000224:	003f4f13          	xori	t5,t5,3
80000228:	0040006f          	j	8000022c <inst_6+0x2c>
8000022c:	00000797          	auipc	a5,0x0
80000230:	fd478793          	addi	a5,a5,-44 # 80000200 <inst_6>
80000234:	ffc7f793          	andi	a5,a5,-4
80000238:	40ff0f33          	sub	t5,t5,a5
8000023c:	01e52c23          	sw	t5,24(a0)

80000240 <inst_7>:
80000240:	00000017          	auipc	zero,0x0
80000244:	00000013          	nop
80000248:	00000f97          	auipc	t6,0x0
8000024c:	ffcf8f93          	addi	t6,t6,-4 # 80000244 <inst_7+0x4>
80000250:	020f8067          	jr	32(t6)
80000254:	00000013          	nop
80000258:	00000013          	nop
8000025c:	00204013          	xori	zero,zero,2
80000260:	00c0006f          	j	8000026c <inst_7+0x2c>
80000264:	00304013          	xori	zero,zero,3
80000268:	0040006f          	j	8000026c <inst_7+0x2c>
8000026c:	00000797          	auipc	a5,0x0
80000270:	fd478793          	addi	a5,a5,-44 # 80000240 <inst_7>
80000274:	ffc7f793          	andi	a5,a5,-4
80000278:	40f00033          	neg	zero,a5
8000027c:	00052e23          	sw	zero,28(a0)

80000280 <inst_8>:
80000280:	00000197          	auipc	gp,0x0
80000284:	00018193          	mv	gp,gp
80000288:	00000a17          	auipc	s4,0x0
8000028c:	f9ca0a13          	addi	s4,s4,-100 # 80000224 <inst_6+0x24>
80000290:	080a01e7          	jalr	gp,128(s4)
80000294:	00000013          	nop
80000298:	00000013          	nop
8000029c:	0021c193          	xori	gp,gp,2
800002a0:	00c0006f          	j	800002ac <inst_8+0x2c>
800002a4:	0031c193          	xori	gp,gp,3
800002a8:	0040006f          	j	800002ac <inst_8+0x2c>
800002ac:	00000797          	auipc	a5,0x0
800002b0:	fd478793          	addi	a5,a5,-44 # 80000280 <inst_8>
800002b4:	ffc7f793          	andi	a5,a5,-4
800002b8:	40f181b3          	sub	gp,gp,a5
800002bc:	02352023          	sw	gp,32(a0)

800002c0 <inst_9>:
800002c0:	00000997          	auipc	s3,0x0
800002c4:	00098993          	mv	s3,s3
800002c8:	00000697          	auipc	a3,0x0
800002cc:	f1c68693          	addi	a3,a3,-228 # 800001e4 <inst_5+0x24>
800002d0:	100689e7          	jalr	s3,256(a3)
800002d4:	00000013          	nop
800002d8:	00000013          	nop
800002dc:	0029c993          	xori	s3,s3,2
800002e0:	00c0006f          	j	800002ec <inst_9+0x2c>
800002e4:	0039c993          	xori	s3,s3,3
800002e8:	0040006f          	j	800002ec <inst_9+0x2c>
800002ec:	00000797          	auipc	a5,0x0
800002f0:	fd478793          	addi	a5,a5,-44 # 800002c0 <inst_9>
800002f4:	ffc7f793          	andi	a5,a5,-4
800002f8:	40f989b3          	sub	s3,s3,a5
800002fc:	03352223          	sw	s3,36(a0)

80000300 <inst_10>:
80000300:	00000e97          	auipc	t4,0x0
80000304:	000e8e93          	mv	t4,t4
80000308:	00000417          	auipc	s0,0x0
8000030c:	e1c40413          	addi	s0,s0,-484 # 80000124 <inst_2+0x24>
80000310:	20040ee7          	jalr	t4,512(s0)
80000314:	00000013          	nop
80000318:	00000013          	nop
8000031c:	002ece93          	xori	t4,t4,2
80000320:	00c0006f          	j	8000032c <inst_10+0x2c>
80000324:	003ece93          	xori	t4,t4,3
80000328:	0040006f          	j	8000032c <inst_10+0x2c>
8000032c:	00000797          	auipc	a5,0x0
80000330:	fd478793          	addi	a5,a5,-44 # 80000300 <inst_10>
80000334:	ffc7f793          	andi	a5,a5,-4
80000338:	40fe8eb3          	sub	t4,t4,a5
8000033c:	03d52423          	sw	t4,40(a0)

80000340 <inst_11>:
80000340:	00000b17          	auipc	s6,0x0
80000344:	000b0b13          	mv	s6,s6
80000348:	00000f17          	auipc	t5,0x0
8000034c:	c1cf0f13          	addi	t5,t5,-996 # 7fffff64 <absimmsh+0x2a40189>
80000350:	400f0b67          	jalr	s6,1024(t5)
80000354:	00000013          	nop
80000358:	00000013          	nop
8000035c:	002b4b13          	xori	s6,s6,2
80000360:	00c0006f          	j	8000036c <inst_11+0x2c>
80000364:	003b4b13          	xori	s6,s6,3
80000368:	0040006f          	j	8000036c <inst_11+0x2c>
8000036c:	00000797          	auipc	a5,0x0
80000370:	fd478793          	addi	a5,a5,-44 # 80000340 <inst_11>
80000374:	ffc7f793          	andi	a5,a5,-4
80000378:	40fb0b33          	sub	s6,s6,a5
8000037c:	03652623          	sw	s6,44(a0)

80000380 <inst_12>:
80000380:	00000a97          	auipc	s5,0x0
80000384:	000a8a93          	mv	s5,s5
80000388:	00001e97          	auipc	t4,0x1
8000038c:	81ce8e93          	addi	t4,t4,-2020 # 80000ba4 <write_tohost+0x2d4>
80000390:	800e8ae7          	jalr	s5,-2048(t4)
80000394:	00000013          	nop
80000398:	00000013          	nop
8000039c:	002aca93          	xori	s5,s5,2
800003a0:	00c0006f          	j	800003ac <inst_12+0x2c>
800003a4:	003aca93          	xori	s5,s5,3
800003a8:	0040006f          	j	800003ac <inst_12+0x2c>
800003ac:	00000797          	auipc	a5,0x0
800003b0:	fd478793          	addi	a5,a5,-44 # 80000380 <inst_12>
800003b4:	ffc7f793          	andi	a5,a5,-4
800003b8:	40fa8ab3          	sub	s5,s5,a5
800003bc:	03552823          	sw	s5,48(a0)

800003c0 <inst_13>:
800003c0:	00000597          	auipc	a1,0x0
800003c4:	00058593          	mv	a1,a1
800003c8:	00000917          	auipc	s2,0x0
800003cc:	01e90913          	addi	s2,s2,30 # 800003e6 <inst_13+0x26>
800003d0:	ffe905e7          	jalr	a1,-2(s2)
800003d4:	00000013          	nop
800003d8:	00000013          	nop
800003dc:	0025c593          	xori	a1,a1,2
800003e0:	00c0006f          	j	800003ec <inst_13+0x2c>
800003e4:	0035c593          	xori	a1,a1,3
800003e8:	0040006f          	j	800003ec <inst_13+0x2c>
800003ec:	00000797          	auipc	a5,0x0
800003f0:	fd478793          	addi	a5,a5,-44 # 800003c0 <inst_13>
800003f4:	ffc7f793          	andi	a5,a5,-4
800003f8:	40f585b3          	sub	a1,a1,a5
800003fc:	02b52a23          	sw	a1,52(a0)

80000400 <inst_14>:
80000400:	00000e17          	auipc	t3,0x0
80000404:	000e0e13          	mv	t3,t3
80000408:	00000a97          	auipc	s5,0x0
8000040c:	01fa8a93          	addi	s5,s5,31 # 80000427 <inst_14+0x27>
80000410:	ffda8e67          	jalr	t3,-3(s5)
80000414:	00000013          	nop
80000418:	00000013          	nop
8000041c:	002e4e13          	xori	t3,t3,2
80000420:	00c0006f          	j	8000042c <inst_14+0x2c>
80000424:	003e4e13          	xori	t3,t3,3
80000428:	0040006f          	j	8000042c <inst_14+0x2c>
8000042c:	00000797          	auipc	a5,0x0
80000430:	fd478793          	addi	a5,a5,-44 # 80000400 <inst_14>
80000434:	ffc7f793          	andi	a5,a5,-4
80000438:	40fe0e33          	sub	t3,t3,a5
8000043c:	03c52c23          	sw	t3,56(a0)

80000440 <inst_15>:
80000440:	00000717          	auipc	a4,0x0
80000444:	00070713          	mv	a4,a4
80000448:	00000c17          	auipc	s8,0x0
8000044c:	021c0c13          	addi	s8,s8,33 # 80000469 <inst_15+0x29>
80000450:	ffbc0767          	jalr	a4,-5(s8)
80000454:	00000013          	nop
80000458:	00000013          	nop
8000045c:	00274713          	xori	a4,a4,2
80000460:	00c0006f          	j	8000046c <inst_15+0x2c>
80000464:	00374713          	xori	a4,a4,3
80000468:	0040006f          	j	8000046c <inst_15+0x2c>
8000046c:	00000797          	auipc	a5,0x0
80000470:	fd478793          	addi	a5,a5,-44 # 80000440 <inst_15>
80000474:	ffc7f793          	andi	a5,a5,-4
80000478:	40f70733          	sub	a4,a4,a5
8000047c:	02e52e23          	sw	a4,60(a0)

80000480 <inst_16>:
80000480:	00000317          	auipc	t1,0x0
80000484:	00030313          	mv	t1,t1
80000488:	00000117          	auipc	sp,0x0
8000048c:	02510113          	addi	sp,sp,37 # 800004ad <inst_16+0x2d>
80000490:	ff710367          	jalr	t1,-9(sp)
80000494:	00000013          	nop
80000498:	00000013          	nop
8000049c:	00234313          	xori	t1,t1,2
800004a0:	00c0006f          	j	800004ac <inst_16+0x2c>
800004a4:	00334313          	xori	t1,t1,3
800004a8:	0040006f          	j	800004ac <inst_16+0x2c>
800004ac:	00000797          	auipc	a5,0x0
800004b0:	fd478793          	addi	a5,a5,-44 # 80000480 <inst_16>
800004b4:	ffc7f793          	andi	a5,a5,-4
800004b8:	40f30333          	sub	t1,t1,a5
800004bc:	04652023          	sw	t1,64(a0)

800004c0 <inst_17>:
800004c0:	00000297          	auipc	t0,0x0
800004c4:	00028293          	mv	t0,t0
800004c8:	00000097          	auipc	ra,0x0
800004cc:	02d08093          	addi	ra,ra,45 # 800004f5 <inst_17+0x35>
800004d0:	fef082e7          	jalr	t0,-17(ra)
800004d4:	00000013          	nop
800004d8:	00000013          	nop
800004dc:	0022c293          	xori	t0,t0,2
800004e0:	00c0006f          	j	800004ec <inst_17+0x2c>
800004e4:	0032c293          	xori	t0,t0,3
800004e8:	0040006f          	j	800004ec <inst_17+0x2c>
800004ec:	00000797          	auipc	a5,0x0
800004f0:	fd478793          	addi	a5,a5,-44 # 800004c0 <inst_17>
800004f4:	ffc7f793          	andi	a5,a5,-4
800004f8:	40f282b3          	sub	t0,t0,a5
800004fc:	04552223          	sw	t0,68(a0)

80000500 <inst_18>:
80000500:	00000917          	auipc	s2,0x0
80000504:	00090913          	mv	s2,s2
80000508:	00000297          	auipc	t0,0x0
8000050c:	03d28293          	addi	t0,t0,61 # 80000545 <inst_19+0x5>
80000510:	fdf28967          	jalr	s2,-33(t0)
80000514:	00000013          	nop
80000518:	00000013          	nop
8000051c:	00294913          	xori	s2,s2,2
80000520:	00c0006f          	j	8000052c <inst_18+0x2c>
80000524:	00394913          	xori	s2,s2,3
80000528:	0040006f          	j	8000052c <inst_18+0x2c>
8000052c:	00000797          	auipc	a5,0x0
80000530:	fd478793          	addi	a5,a5,-44 # 80000500 <inst_18>
80000534:	ffc7f793          	andi	a5,a5,-4
80000538:	40f90933          	sub	s2,s2,a5
8000053c:	05252423          	sw	s2,72(a0)

80000540 <inst_19>:
80000540:	00000397          	auipc	t2,0x0
80000544:	00038393          	mv	t2,t2
80000548:	00000497          	auipc	s1,0x0
8000054c:	05d48493          	addi	s1,s1,93 # 800005a5 <inst_20+0x1d>
80000550:	fbf483e7          	jalr	t2,-65(s1)
80000554:	00000013          	nop
80000558:	00000013          	nop
8000055c:	0023c393          	xori	t2,t2,2
80000560:	00c0006f          	j	8000056c <inst_19+0x2c>
80000564:	0033c393          	xori	t2,t2,3
80000568:	0040006f          	j	8000056c <inst_19+0x2c>
8000056c:	00000797          	auipc	a5,0x0
80000570:	fd478793          	addi	a5,a5,-44 # 80000540 <inst_19>
80000574:	ffc7f793          	andi	a5,a5,-4
80000578:	40f383b3          	sub	t2,t2,a5
8000057c:	04752623          	sw	t2,76(a0)
80000580:	00003197          	auipc	gp,0x3
80000584:	be418193          	addi	gp,gp,-1052 # 80003164 <signature_x3_0>

80000588 <inst_20>:
80000588:	00000517          	auipc	a0,0x0
8000058c:	00050513          	mv	a0,a0
80000590:	00000c97          	auipc	s9,0x0
80000594:	09dc8c93          	addi	s9,s9,157 # 8000062d <inst_22+0x25>
80000598:	f7fc8567          	jalr	a0,-129(s9)
8000059c:	00000013          	nop
800005a0:	00000013          	nop
800005a4:	00254513          	xori	a0,a0,2
800005a8:	00c0006f          	j	800005b4 <inst_20+0x2c>
800005ac:	00354513          	xori	a0,a0,3
800005b0:	0040006f          	j	800005b4 <inst_20+0x2c>
800005b4:	00000297          	auipc	t0,0x0
800005b8:	fd428293          	addi	t0,t0,-44 # 80000588 <inst_20>
800005bc:	ffc2f293          	andi	t0,t0,-4
800005c0:	40550533          	sub	a0,a0,t0
800005c4:	00a1a023          	sw	a0,0(gp)

800005c8 <inst_21>:
800005c8:	00000797          	auipc	a5,0x0
800005cc:	00078793          	mv	a5,a5
800005d0:	00000597          	auipc	a1,0x0
800005d4:	21d58593          	addi	a1,a1,541 # 800007ed <inst_29+0x25>
800005d8:	dff587e7          	jalr	a5,-513(a1)
800005dc:	00000013          	nop
800005e0:	00000013          	nop
800005e4:	0027c793          	xori	a5,a5,2
800005e8:	00c0006f          	j	800005f4 <inst_21+0x2c>
800005ec:	0037c793          	xori	a5,a5,3
800005f0:	0040006f          	j	800005f4 <inst_21+0x2c>
800005f4:	00000297          	auipc	t0,0x0
800005f8:	fd428293          	addi	t0,t0,-44 # 800005c8 <inst_21>
800005fc:	ffc2f293          	andi	t0,t0,-4
80000600:	405787b3          	sub	a5,a5,t0
80000604:	00f1a223          	sw	a5,4(gp)

80000608 <inst_22>:
80000608:	00000497          	auipc	s1,0x0
8000060c:	00048493          	mv	s1,s1
80000610:	00000997          	auipc	s3,0x0
80000614:	41d98993          	addi	s3,s3,1053 # 80000a2d <write_tohost+0x15d>
80000618:	bff984e7          	jalr	s1,-1025(s3)
8000061c:	00000013          	nop
80000620:	00000013          	nop
80000624:	0024c493          	xori	s1,s1,2
80000628:	00c0006f          	j	80000634 <inst_22+0x2c>
8000062c:	0034c493          	xori	s1,s1,3
80000630:	0040006f          	j	80000634 <inst_22+0x2c>
80000634:	00000297          	auipc	t0,0x0
80000638:	fd428293          	addi	t0,t0,-44 # 80000608 <inst_22>
8000063c:	ffc2f293          	andi	t0,t0,-4
80000640:	405484b3          	sub	s1,s1,t0
80000644:	0091a423          	sw	s1,8(gp)

80000648 <inst_23>:
80000648:	00000a17          	auipc	s4,0x0
8000064c:	000a0a13          	mv	s4,s4
80000650:	00000397          	auipc	t2,0x0
80000654:	81d38393          	addi	t2,t2,-2019 # 7ffffe6d <absimmsh+0x2a40092>
80000658:	7ff38a67          	jalr	s4,2047(t2)
8000065c:	00000013          	nop
80000660:	00000013          	nop
80000664:	002a4a13          	xori	s4,s4,2
80000668:	00c0006f          	j	80000674 <inst_23+0x2c>
8000066c:	003a4a13          	xori	s4,s4,3
80000670:	0040006f          	j	80000674 <inst_23+0x2c>
80000674:	00000297          	auipc	t0,0x0
80000678:	fd428293          	addi	t0,t0,-44 # 80000648 <inst_23>
8000067c:	ffc2f293          	andi	t0,t0,-4
80000680:	405a0a33          	sub	s4,s4,t0
80000684:	0141a623          	sw	s4,12(gp)

80000688 <inst_24>:
80000688:	00000d17          	auipc	s10,0x0
8000068c:	000d0d13          	mv	s10,s10
80000690:	00000717          	auipc	a4,0x0
80000694:	ac770713          	addi	a4,a4,-1337 # 80000157 <inst_3+0x17>
80000698:	55570d67          	jalr	s10,1365(a4)
8000069c:	00000013          	nop
800006a0:	00000013          	nop
800006a4:	002d4d13          	xori	s10,s10,2
800006a8:	00c0006f          	j	800006b4 <inst_24+0x2c>
800006ac:	003d4d13          	xori	s10,s10,3
800006b0:	0040006f          	j	800006b4 <inst_24+0x2c>
800006b4:	00000297          	auipc	t0,0x0
800006b8:	fd428293          	addi	t0,t0,-44 # 80000688 <inst_24>
800006bc:	ffc2f293          	andi	t0,t0,-4
800006c0:	405d0d33          	sub	s10,s10,t0
800006c4:	01a1a823          	sw	s10,16(gp)

800006c8 <inst_25>:
800006c8:	00000217          	auipc	tp,0x0
800006cc:	00020213          	mv	tp,tp
800006d0:	00000797          	auipc	a5,0x0
800006d4:	57278793          	addi	a5,a5,1394 # 80000c42 <write_tohost+0x372>
800006d8:	aaa78267          	jalr	tp,-1366(a5)
800006dc:	00000013          	nop
800006e0:	00000013          	nop
800006e4:	00224213          	xori	tp,tp,2
800006e8:	00c0006f          	j	800006f4 <inst_25+0x2c>
800006ec:	00324213          	xori	tp,tp,3
800006f0:	0040006f          	j	800006f4 <inst_25+0x2c>
800006f4:	00000297          	auipc	t0,0x0
800006f8:	fd428293          	addi	t0,t0,-44 # 800006c8 <inst_25>
800006fc:	ffc2f293          	andi	t0,t0,-4
80000700:	40520233          	sub	tp,tp,t0
80000704:	0041aa23          	sw	tp,20(gp)

80000708 <inst_26>:
80000708:	00000c17          	auipc	s8,0x0
8000070c:	000c0c13          	mv	s8,s8
80000710:	00001b17          	auipc	s6,0x1
80000714:	81cb0b13          	addi	s6,s6,-2020 # 80000f2c <write_tohost+0x65c>
80000718:	800b0c67          	jalr	s8,-2048(s6)
8000071c:	00000013          	nop
80000720:	00000013          	nop
80000724:	002c4c13          	xori	s8,s8,2
80000728:	00c0006f          	j	80000734 <inst_26+0x2c>
8000072c:	003c4c13          	xori	s8,s8,3
80000730:	0040006f          	j	80000734 <inst_26+0x2c>
80000734:	00000297          	auipc	t0,0x0
80000738:	fd428293          	addi	t0,t0,-44 # 80000708 <inst_26>
8000073c:	ffc2f293          	andi	t0,t0,-4
80000740:	405c0c33          	sub	s8,s8,t0
80000744:	0181ac23          	sw	s8,24(gp)

80000748 <inst_27>:
80000748:	00000b97          	auipc	s7,0x0
8000074c:	000b8b93          	mv	s7,s7
80000750:	00001d17          	auipc	s10,0x1
80000754:	81cd0d13          	addi	s10,s10,-2020 # 80000f6c <write_tohost+0x69c>
80000758:	800d0be7          	jalr	s7,-2048(s10)
8000075c:	00000013          	nop
80000760:	00000013          	nop
80000764:	002bcb93          	xori	s7,s7,2
80000768:	00c0006f          	j	80000774 <inst_27+0x2c>
8000076c:	003bcb93          	xori	s7,s7,3
80000770:	0040006f          	j	80000774 <inst_27+0x2c>
80000774:	00000297          	auipc	t0,0x0
80000778:	fd428293          	addi	t0,t0,-44 # 80000748 <inst_27>
8000077c:	ffc2f293          	andi	t0,t0,-4
80000780:	405b8bb3          	sub	s7,s7,t0
80000784:	0171ae23          	sw	s7,28(gp)

80000788 <inst_28>:
80000788:	00000117          	auipc	sp,0x0
8000078c:	00010113          	mv	sp,sp
80000790:	00001e17          	auipc	t3,0x1
80000794:	81ce0e13          	addi	t3,t3,-2020 # 80000fac <write_tohost+0x6dc>
80000798:	800e0167          	jalr	sp,-2048(t3)
8000079c:	00000013          	nop
800007a0:	00000013          	nop
800007a4:	00214113          	xori	sp,sp,2
800007a8:	00c0006f          	j	800007b4 <inst_28+0x2c>
800007ac:	00314113          	xori	sp,sp,3
800007b0:	0040006f          	j	800007b4 <inst_28+0x2c>
800007b4:	00000297          	auipc	t0,0x0
800007b8:	fd428293          	addi	t0,t0,-44 # 80000788 <inst_28>
800007bc:	ffc2f293          	andi	t0,t0,-4
800007c0:	40510133          	sub	sp,sp,t0
800007c4:	0221a023          	sw	sp,32(gp)

800007c8 <inst_29>:
800007c8:	00000097          	auipc	ra,0x0
800007cc:	00008093          	mv	ra,ra
800007d0:	00001517          	auipc	a0,0x1
800007d4:	81c50513          	addi	a0,a0,-2020 # 80000fec <write_tohost+0x71c>
800007d8:	800500e7          	jalr	-2048(a0)
800007dc:	00000013          	nop
800007e0:	00000013          	nop
800007e4:	0020c093          	xori	ra,ra,2
800007e8:	00c0006f          	j	800007f4 <inst_29+0x2c>
800007ec:	0030c093          	xori	ra,ra,3
800007f0:	0040006f          	j	800007f4 <inst_29+0x2c>
800007f4:	00000297          	auipc	t0,0x0
800007f8:	fd428293          	addi	t0,t0,-44 # 800007c8 <inst_29>
800007fc:	ffc2f293          	andi	t0,t0,-4
80000800:	405080b3          	sub	ra,ra,t0
80000804:	0211a223          	sw	ra,36(gp)

80000808 <inst_30>:
80000808:	00000f97          	auipc	t6,0x0
8000080c:	000f8f93          	mv	t6,t6
80000810:	00001817          	auipc	a6,0x1
80000814:	81c80813          	addi	a6,a6,-2020 # 8000102c <tohost+0x2c>
80000818:	80080fe7          	jalr	t6,-2048(a6)
8000081c:	00000013          	nop
80000820:	00000013          	nop
80000824:	002fcf93          	xori	t6,t6,2
80000828:	00c0006f          	j	80000834 <inst_30+0x2c>
8000082c:	003fcf93          	xori	t6,t6,3
80000830:	0040006f          	j	80000834 <inst_30+0x2c>
80000834:	00000297          	auipc	t0,0x0
80000838:	fd428293          	addi	t0,t0,-44 # 80000808 <inst_30>
8000083c:	ffc2f293          	andi	t0,t0,-4
80000840:	405f8fb3          	sub	t6,t6,t0
80000844:	03f1a423          	sw	t6,40(gp)

80000848 <inst_31>:
80000848:	00000d97          	auipc	s11,0x0
8000084c:	000d8d93          	mv	s11,s11
80000850:	00001817          	auipc	a6,0x1
80000854:	81c80813          	addi	a6,a6,-2020 # 8000106c <tohost+0x6c>
80000858:	80080de7          	jalr	s11,-2048(a6)
8000085c:	00000013          	nop
80000860:	00000013          	nop
80000864:	002dcd93          	xori	s11,s11,2
80000868:	00c0006f          	j	80000874 <inst_31+0x2c>
8000086c:	003dcd93          	xori	s11,s11,3
80000870:	0040006f          	j	80000874 <inst_31+0x2c>
80000874:	00000297          	auipc	t0,0x0
80000878:	fd428293          	addi	t0,t0,-44 # 80000848 <inst_31>
8000087c:	ffc2f293          	andi	t0,t0,-4
80000880:	405d8db3          	sub	s11,s11,t0
80000884:	03b1a623          	sw	s11,44(gp)

80000888 <inst_32>:
80000888:	00000597          	auipc	a1,0x0
8000088c:	00058593          	mv	a1,a1
80000890:	00000517          	auipc	a0,0x0
80000894:	ffc50513          	addi	a0,a0,-4 # 8000088c <inst_32+0x4>
80000898:	020505e7          	jalr	a1,32(a0)
8000089c:	00000013          	nop
800008a0:	00000013          	nop
800008a4:	0025c593          	xori	a1,a1,2
800008a8:	00c0006f          	j	800008b4 <inst_32+0x2c>
800008ac:	0035c593          	xori	a1,a1,3
800008b0:	0040006f          	j	800008b4 <inst_32+0x2c>
800008b4:	00000297          	auipc	t0,0x0
800008b8:	fd428293          	addi	t0,t0,-44 # 80000888 <inst_32>
800008bc:	ffc2f293          	andi	t0,t0,-4
800008c0:	405585b3          	sub	a1,a1,t0
800008c4:	02b1a823          	sw	a1,48(gp)

800008c8 <cleanup_epilogs>:
800008c8:	0040006f          	j	800008cc <exit_cleanup>

800008cc <exit_cleanup>:
800008cc:	00100093          	li	ra,1

800008d0 <write_tohost>:
800008d0:	00000f17          	auipc	t5,0x0
800008d4:	721f2823          	sw	ra,1840(t5) # 80001000 <tohost>
800008d8:	ff9ff06f          	j	800008d0 <write_tohost>
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
80003160:	deadbeef          	jal	t4,7ffde74a <absimmsh+0x2a1e96f>

80003164 <signature_x3_0>:
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
   0:	0169                	addi	sp,sp,26
   2:	0000                	unimp
   4:	00750003          	lb	zero,7(a0)
   8:	0000                	unimp
   a:	0101                	addi	sp,sp,0
   c:	000d0efb          	0xd0efb
  10:	0101                	addi	sp,sp,0
  12:	0101                	addi	sp,sp,0
  14:	0000                	unimp
  16:	0100                	addi	s0,sp,128
  18:	0000                	unimp
  1a:	2f01                	jal	72a <offset+0x6f6>
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
  44:	612d7663          	bgeu	s10,s2,650 <offset+0x61c>
  48:	6372                	flw	ft6,28(sp)
  4a:	2d68                	fld	fa0,216(a0)
  4c:	6574                	flw	fa3,76(a0)
  4e:	722f7473          	csrrci	s0,0x722,30
  52:	7369                	lui	t1,0xffffa
  54:	742d7663          	bgeu	s10,sp,7a0 <offset+0x76c>
  58:	7365                	lui	t1,0xffff9
  5a:	2d74                	fld	fa3,216(a0)
  5c:	74697573          	csrrci	a0,0x746,18
  60:	2f65                	jal	818 <offset+0x7e4>
  62:	7672                	flw	fa2,60(sp)
  64:	5f693233          	0x5f693233
  68:	2f6d                	jal	822 <offset+0x7ee>
  6a:	2f49                	jal	7fc <offset+0x7c8>
  6c:	00637273          	csrrci	tp,0x6,6
  70:	6a00                	flw	fs0,16(a2)
  72:	6c61                	lui	s8,0x18
  74:	2d72                	fld	fs10,280(sp)
  76:	3130                	fld	fa2,96(a0)
  78:	532e                	lw	t1,232(sp)
  7a:	0100                	addi	s0,sp,128
  7c:	0000                	unimp
  7e:	0000                	unimp
  80:	0205                	addi	tp,tp,1
  82:	0000                	unimp
  84:	8000                	0x8000
  86:	03011903          	lh	s2,48(sp) # 800007b8 <inst_28+0x30>
  8a:	0906                	slli	s2,s2,0x1
  8c:	0078                	addi	a4,sp,12
  8e:	0301                	addi	t1,t1,0
  90:	0905                	addi	s2,s2,1
  92:	0008                	0x8
  94:	0301                	addi	t1,t1,0
  96:	0905                	addi	s2,s2,1
  98:	0040                	addi	s0,sp,4
  9a:	0301                	addi	t1,t1,0
  9c:	0905                	addi	s2,s2,1
  9e:	0040                	addi	s0,sp,4
  a0:	0301                	addi	t1,t1,0
  a2:	0905                	addi	s2,s2,1
  a4:	0040                	addi	s0,sp,4
  a6:	0301                	addi	t1,t1,0
  a8:	0905                	addi	s2,s2,1
  aa:	0040                	addi	s0,sp,4
  ac:	0301                	addi	t1,t1,0
  ae:	0905                	addi	s2,s2,1
  b0:	0040                	addi	s0,sp,4
  b2:	0301                	addi	t1,t1,0
  b4:	0905                	addi	s2,s2,1
  b6:	0040                	addi	s0,sp,4
  b8:	0301                	addi	t1,t1,0
  ba:	0905                	addi	s2,s2,1
  bc:	0040                	addi	s0,sp,4
  be:	0301                	addi	t1,t1,0
  c0:	0905                	addi	s2,s2,1
  c2:	0040                	addi	s0,sp,4
  c4:	0301                	addi	t1,t1,0
  c6:	0905                	addi	s2,s2,1
  c8:	0040                	addi	s0,sp,4
  ca:	0301                	addi	t1,t1,0
  cc:	0905                	addi	s2,s2,1
  ce:	0040                	addi	s0,sp,4
  d0:	0301                	addi	t1,t1,0
  d2:	0905                	addi	s2,s2,1
  d4:	0040                	addi	s0,sp,4
  d6:	0301                	addi	t1,t1,0
  d8:	0905                	addi	s2,s2,1
  da:	0040                	addi	s0,sp,4
  dc:	0301                	addi	t1,t1,0
  de:	0905                	addi	s2,s2,1
  e0:	0040                	addi	s0,sp,4
  e2:	0301                	addi	t1,t1,0
  e4:	0905                	addi	s2,s2,1
  e6:	0040                	addi	s0,sp,4
  e8:	0301                	addi	t1,t1,0
  ea:	0905                	addi	s2,s2,1
  ec:	0040                	addi	s0,sp,4
  ee:	0301                	addi	t1,t1,0
  f0:	0905                	addi	s2,s2,1
  f2:	0040                	addi	s0,sp,4
  f4:	0301                	addi	t1,t1,0
  f6:	0905                	addi	s2,s2,1
  f8:	0040                	addi	s0,sp,4
  fa:	0301                	addi	t1,t1,0
  fc:	0905                	addi	s2,s2,1
  fe:	0040                	addi	s0,sp,4
 100:	0301                	addi	t1,t1,0
 102:	0905                	addi	s2,s2,1
 104:	0040                	addi	s0,sp,4
 106:	0301                	addi	t1,t1,0
 108:	0901                	addi	s2,s2,0
 10a:	0040                	addi	s0,sp,4
 10c:	0301                	addi	t1,t1,0
 10e:	0905                	addi	s2,s2,1
 110:	0008                	0x8
 112:	0301                	addi	t1,t1,0
 114:	0905                	addi	s2,s2,1
 116:	0040                	addi	s0,sp,4
 118:	0301                	addi	t1,t1,0
 11a:	0905                	addi	s2,s2,1
 11c:	0040                	addi	s0,sp,4
 11e:	0301                	addi	t1,t1,0
 120:	0905                	addi	s2,s2,1
 122:	0040                	addi	s0,sp,4
 124:	0301                	addi	t1,t1,0
 126:	0905                	addi	s2,s2,1
 128:	0040                	addi	s0,sp,4
 12a:	0301                	addi	t1,t1,0
 12c:	0905                	addi	s2,s2,1
 12e:	0040                	addi	s0,sp,4
 130:	0301                	addi	t1,t1,0
 132:	0905                	addi	s2,s2,1
 134:	0040                	addi	s0,sp,4
 136:	0301                	addi	t1,t1,0
 138:	0905                	addi	s2,s2,1
 13a:	0040                	addi	s0,sp,4
 13c:	0301                	addi	t1,t1,0
 13e:	0905                	addi	s2,s2,1
 140:	0040                	addi	s0,sp,4
 142:	0301                	addi	t1,t1,0
 144:	0905                	addi	s2,s2,1
 146:	0040                	addi	s0,sp,4
 148:	0301                	addi	t1,t1,0
 14a:	0905                	addi	s2,s2,1
 14c:	0040                	addi	s0,sp,4
 14e:	0301                	addi	t1,t1,0
 150:	0905                	addi	s2,s2,1
 152:	0040                	addi	s0,sp,4
 154:	0301                	addi	t1,t1,0
 156:	0905                	addi	s2,s2,1
 158:	0040                	addi	s0,sp,4
 15a:	0301                	addi	t1,t1,0
 15c:	0904                	addi	s1,sp,144
 15e:	0040                	addi	s0,sp,4
 160:	0301                	addi	t1,t1,0
 162:	0901                	addi	s2,s2,0
 164:	0004                	0x4
 166:	0901                	addi	s2,s2,0
 168:	0010                	0x10
 16a:	0100                	addi	s0,sp,128
 16c:	01              	Address 0x000000000000016c is out of bounds.


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
  14:	08dc                	addi	a5,sp,84
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
  14:	08dc                	addi	a5,sp,84
	...

Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	6d6f682f          	0x6d6f682f
   4:	2f65                	jal	7bc <offset+0x788>
   6:	6f6c                	flw	fa1,92(a4)
   8:	6976                	flw	fs2,92(sp)
   a:	65442f73          	csrrs	t5,0x654,s0
   e:	6f746b73          	csrrsi	s6,0x6f7,8
  12:	2f70                	fld	fa2,216(a4)
  14:	6952                	flw	fs2,20(sp)
  16:	6556                	flw	fa0,84(sp)
  18:	5f72                	lw	t5,60(sp)
  1a:	65726f63          	bltu	tp,s7,678 <offset+0x644>
  1e:	7369722f          	0x7369722f
  22:	2f666f63          	bltu	a2,s6,320 <offset+0x2ec>
  26:	6972                	flw	fs2,28(sp)
  28:	2d766373          	csrrsi	t1,0x2d7,12
  2c:	7261                	lui	tp,0xffff8
  2e:	742d6863          	bltu	s10,sp,77e <offset+0x74a>
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
  54:	6c616a2f          	0x6c616a2f
  58:	2d72                	fld	fs10,280(sp)
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
  88:	5f666f63          	bltu	a2,s6,686 <offset+0x652>
  8c:	6b726f77          	0x6b726f77
  90:	3376722f          	0x3376722f
  94:	6932                	flw	fs2,12(sp)
  96:	6d5f 492f 732f      	0x732f492f6d5f
  9c:	6372                	flw	ft6,28(sp)
  9e:	6c616a2f          	0x6c616a2f
  a2:	2d72                	fld	fs10,280(sp)
  a4:	3130                	fld	fa2,96(a0)
  a6:	532e                	lw	t1,232(sp)
  a8:	7475642f          	0x7475642f
  ac:	4700                	lw	s0,8(a4)
  ae:	554e                	lw	a0,240(sp)
  b0:	4120                	lw	s0,64(a0)
  b2:	2e322053          	0x2e322053
  b6:	          	snez	a0,zero
