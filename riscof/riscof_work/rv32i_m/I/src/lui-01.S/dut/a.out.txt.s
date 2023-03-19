
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
80000080:	00000437          	lui	s0,0x0
80000084:	0084a023          	sw	s0,0(s1)

80000088 <inst_1>:
80000088:	000052b7          	lui	t0,0x5
8000008c:	0054a223          	sw	t0,4(s1)

80000090 <inst_2>:
80000090:	fffff9b7          	lui	s3,0xfffff
80000094:	0134a423          	sw	s3,8(s1)

80000098 <inst_3>:
80000098:	000036b7          	lui	a3,0x3
8000009c:	00d4a623          	sw	a3,12(s1)

800000a0 <inst_4>:
800000a0:	55555037          	lui	zero,0x55555
800000a4:	0004a823          	sw	zero,16(s1)

800000a8 <inst_5>:
800000a8:	aaaaa237          	lui	tp,0xaaaaa
800000ac:	0044aa23          	sw	tp,20(s1)

800000b0 <inst_6>:
800000b0:	33333b37          	lui	s6,0x33333
800000b4:	0164ac23          	sw	s6,24(s1)

800000b8 <inst_7>:
800000b8:	66666d37          	lui	s10,0x66666
800000bc:	01a4ae23          	sw	s10,28(s1)

800000c0 <inst_8>:
800000c0:	002d4eb7          	lui	t4,0x2d4
800000c4:	03d4a023          	sw	t4,32(s1)

800000c8 <inst_9>:
800000c8:	003ff1b7          	lui	gp,0x3ff
800000cc:	0234a223          	sw	gp,36(s1)

800000d0 <inst_10>:
800000d0:	00002f37          	lui	t5,0x2
800000d4:	03e4a423          	sw	t5,40(s1)

800000d8 <inst_11>:
800000d8:	55554837          	lui	a6,0x55554
800000dc:	0304a623          	sw	a6,44(s1)

800000e0 <inst_12>:
800000e0:	aaaa9137          	lui	sp,0xaaaa9
800000e4:	0224a823          	sw	sp,48(s1)

800000e8 <inst_13>:
800000e8:	00004c37          	lui	s8,0x4
800000ec:	0384aa23          	sw	s8,52(s1)

800000f0 <inst_14>:
800000f0:	33332db7          	lui	s11,0x33332
800000f4:	03b4ac23          	sw	s11,56(s1)

800000f8 <inst_15>:
800000f8:	66665a37          	lui	s4,0x66665
800000fc:	0344ae23          	sw	s4,60(s1)

80000100 <inst_16>:
80000100:	002d3e37          	lui	t3,0x2d3
80000104:	05c4a023          	sw	t3,64(s1)

80000108 <inst_17>:
80000108:	003fe337          	lui	t1,0x3fe
8000010c:	0464a223          	sw	t1,68(s1)

80000110 <inst_18>:
80000110:	55556537          	lui	a0,0x55556
80000114:	04a4a423          	sw	a0,72(s1)

80000118 <inst_19>:
80000118:	aaaab637          	lui	a2,0xaaaab
8000011c:	04c4a623          	sw	a2,76(s1)

80000120 <inst_20>:
80000120:	000067b7          	lui	a5,0x6
80000124:	04f4a823          	sw	a5,80(s1)

80000128 <inst_21>:
80000128:	33334bb7          	lui	s7,0x33334
8000012c:	0574aa23          	sw	s7,84(s1)

80000130 <inst_22>:
80000130:	666670b7          	lui	ra,0x66667
80000134:	0414ac23          	sw	ra,88(s1)

80000138 <inst_23>:
80000138:	002d5937          	lui	s2,0x2d5
8000013c:	0524ae23          	sw	s2,92(s1)

80000140 <inst_24>:
80000140:	000015b7          	lui	a1,0x1
80000144:	06b4a023          	sw	a1,96(s1)

80000148 <inst_25>:
80000148:	00400ab7          	lui	s5,0x400
8000014c:	0754a223          	sw	s5,100(s1)

80000150 <inst_26>:
80000150:	000088b7          	lui	a7,0x8
80000154:	0714a423          	sw	a7,104(s1)

80000158 <inst_27>:
80000158:	00010cb7          	lui	s9,0x10
8000015c:	0794a623          	sw	s9,108(s1)

80000160 <inst_28>:
80000160:	000203b7          	lui	t2,0x20
80000164:	0674a823          	sw	t2,112(s1)
80000168:	00003097          	auipc	ra,0x3
8000016c:	02008093          	addi	ra,ra,32 # 80003188 <signature_x1_0>

80000170 <inst_29>:
80000170:	00040737          	lui	a4,0x40
80000174:	00e0a023          	sw	a4,0(ra)

80000178 <inst_30>:
80000178:	000804b7          	lui	s1,0x80
8000017c:	0090a223          	sw	s1,4(ra)

80000180 <inst_31>:
80000180:	efffffb7          	lui	t6,0xeffff
80000184:	01f0a423          	sw	t6,8(ra)

80000188 <inst_32>:
80000188:	dffff537          	lui	a0,0xdffff
8000018c:	00a0a623          	sw	a0,12(ra)

80000190 <inst_33>:
80000190:	bffff537          	lui	a0,0xbffff
80000194:	00a0a823          	sw	a0,16(ra)

80000198 <inst_34>:
80000198:	7ffff537          	lui	a0,0x7ffff
8000019c:	00a0aa23          	sw	a0,20(ra)

800001a0 <inst_35>:
800001a0:	00100537          	lui	a0,0x100
800001a4:	00a0ac23          	sw	a0,24(ra)

800001a8 <inst_36>:
800001a8:	00200537          	lui	a0,0x200
800001ac:	00a0ae23          	sw	a0,28(ra)

800001b0 <inst_37>:
800001b0:	00800537          	lui	a0,0x800
800001b4:	02a0a023          	sw	a0,32(ra)

800001b8 <inst_38>:
800001b8:	01000537          	lui	a0,0x1000
800001bc:	02a0a223          	sw	a0,36(ra)

800001c0 <inst_39>:
800001c0:	02000537          	lui	a0,0x2000
800001c4:	02a0a423          	sw	a0,40(ra)

800001c8 <inst_40>:
800001c8:	04000537          	lui	a0,0x4000
800001cc:	02a0a623          	sw	a0,44(ra)

800001d0 <inst_41>:
800001d0:	08000537          	lui	a0,0x8000
800001d4:	02a0a823          	sw	a0,48(ra)

800001d8 <inst_42>:
800001d8:	10000537          	lui	a0,0x10000
800001dc:	02a0aa23          	sw	a0,52(ra)

800001e0 <inst_43>:
800001e0:	20000537          	lui	a0,0x20000
800001e4:	02a0ac23          	sw	a0,56(ra)

800001e8 <inst_44>:
800001e8:	40000537          	lui	a0,0x40000
800001ec:	02a0ae23          	sw	a0,60(ra)

800001f0 <inst_45>:
800001f0:	80000537          	lui	a0,0x80000
800001f4:	04a0a023          	sw	a0,64(ra)

800001f8 <inst_46>:
800001f8:	ffffe537          	lui	a0,0xffffe
800001fc:	04a0a223          	sw	a0,68(ra)

80000200 <inst_47>:
80000200:	ffffd537          	lui	a0,0xffffd
80000204:	04a0a423          	sw	a0,72(ra)

80000208 <inst_48>:
80000208:	ffffb537          	lui	a0,0xffffb
8000020c:	04a0a623          	sw	a0,76(ra)

80000210 <inst_49>:
80000210:	ffff7537          	lui	a0,0xffff7
80000214:	04a0a823          	sw	a0,80(ra)

80000218 <inst_50>:
80000218:	fffef537          	lui	a0,0xfffef
8000021c:	04a0aa23          	sw	a0,84(ra)

80000220 <inst_51>:
80000220:	fffdf537          	lui	a0,0xfffdf
80000224:	04a0ac23          	sw	a0,88(ra)

80000228 <inst_52>:
80000228:	fffbf537          	lui	a0,0xfffbf
8000022c:	04a0ae23          	sw	a0,92(ra)

80000230 <inst_53>:
80000230:	fff7f537          	lui	a0,0xfff7f
80000234:	06a0a023          	sw	a0,96(ra)

80000238 <inst_54>:
80000238:	ffeff537          	lui	a0,0xffeff
8000023c:	06a0a223          	sw	a0,100(ra)

80000240 <inst_55>:
80000240:	ffdff537          	lui	a0,0xffdff
80000244:	06a0a423          	sw	a0,104(ra)

80000248 <inst_56>:
80000248:	ffbff537          	lui	a0,0xffbff
8000024c:	06a0a623          	sw	a0,108(ra)

80000250 <inst_57>:
80000250:	ff7ff537          	lui	a0,0xff7ff
80000254:	06a0a823          	sw	a0,112(ra)

80000258 <inst_58>:
80000258:	fefff537          	lui	a0,0xfefff
8000025c:	06a0aa23          	sw	a0,116(ra)

80000260 <inst_59>:
80000260:	fdfff537          	lui	a0,0xfdfff
80000264:	06a0ac23          	sw	a0,120(ra)

80000268 <inst_60>:
80000268:	fbfff537          	lui	a0,0xfbfff
8000026c:	06a0ae23          	sw	a0,124(ra)

80000270 <inst_61>:
80000270:	f7fff537          	lui	a0,0xf7fff
80000274:	08a0a023          	sw	a0,128(ra)

80000278 <inst_62>:
80000278:	55555537          	lui	a0,0x55555
8000027c:	08a0a223          	sw	a0,132(ra)

80000280 <cleanup_epilogs>:
80000280:	0040006f          	j	80000284 <exit_cleanup>

80000284 <exit_cleanup>:
80000284:	00100093          	li	ra,1

80000288 <write_tohost>:
80000288:	00001f17          	auipc	t5,0x1
8000028c:	d61f2c23          	sw	ra,-648(t5) # 80001000 <tohost>
80000290:	ff9ff06f          	j	80000288 <write_tohost>
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

80003210 <sig_end_canary>:
80003210:	a309                	j	80003712 <_end+0x4f2>
80003212:	6f5c                	flw	fa5,28(a4)

80003214 <rvtest_sig_end>:
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
   0:	021c                	addi	a5,sp,256
   2:	0000                	unimp
   4:	00740003          	lb	zero,7(s0) # 7 <MMODE_SIG+0x4>
   8:	0000                	unimp
   a:	0101                	addi	sp,sp,0
   c:	000d0efb          	0xd0efb
  10:	0101                	addi	sp,sp,0
  12:	0101                	addi	sp,sp,0
  14:	0000                	unimp
  16:	0100                	addi	s0,sp,128
  18:	0000                	unimp
  1a:	2f01                	jal	72a <offset+0x6a2>
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
  44:	612d7663          	bgeu	s10,s2,650 <offset+0x5c8>
  48:	6372                	flw	ft6,28(sp)
  4a:	2d68                	fld	fa0,216(a0)
  4c:	6574                	flw	fa3,76(a0)
  4e:	722f7473          	csrrci	s0,0x722,30
  52:	7369                	lui	t1,0xffffa
  54:	742d7663          	bgeu	s10,sp,7a0 <offset+0x718>
  58:	7365                	lui	t1,0xffff9
  5a:	2d74                	fld	fa3,216(a0)
  5c:	74697573          	csrrci	a0,0x746,18
  60:	2f65                	jal	818 <offset+0x790>
  62:	7672                	flw	fa2,60(sp)
  64:	5f693233          	0x5f693233
  68:	2f6d                	jal	822 <offset+0x79a>
  6a:	2f49                	jal	7fc <offset+0x774>
  6c:	00637273          	csrrci	tp,0x6,6
  70:	6c00                	flw	fs0,24(s0)
  72:	6975                	lui	s2,0x1d
  74:	302d                	jal	fffff89e <imm12sh+0xfffffac3>
  76:	2e31                	jal	392 <offset+0x30a>
  78:	00010053          	fadd.s	ft0,ft2,ft0,rne
  7c:	0000                	unimp
  7e:	0500                	addi	s0,sp,640
  80:	0002                	c.slli64	zero
  82:	0000                	unimp
  84:	0380                	addi	s0,sp,448
  86:	0119                	addi	sp,sp,6
  88:	78090603          	lb	a2,1920(s2) # 1d780 <offset+0x1d6f8>
  8c:	0100                	addi	s0,sp,128
  8e:	08090503          	lb	a0,128(s2)
  92:	0100                	addi	s0,sp,128
  94:	08090503          	lb	a0,128(s2)
  98:	0100                	addi	s0,sp,128
  9a:	08090503          	lb	a0,128(s2)
  9e:	0100                	addi	s0,sp,128
  a0:	08090503          	lb	a0,128(s2)
  a4:	0100                	addi	s0,sp,128
  a6:	08090503          	lb	a0,128(s2)
  aa:	0100                	addi	s0,sp,128
  ac:	08090503          	lb	a0,128(s2)
  b0:	0100                	addi	s0,sp,128
  b2:	08090503          	lb	a0,128(s2)
  b6:	0100                	addi	s0,sp,128
  b8:	08090503          	lb	a0,128(s2)
  bc:	0100                	addi	s0,sp,128
  be:	08090503          	lb	a0,128(s2)
  c2:	0100                	addi	s0,sp,128
  c4:	08090503          	lb	a0,128(s2)
  c8:	0100                	addi	s0,sp,128
  ca:	08090503          	lb	a0,128(s2)
  ce:	0100                	addi	s0,sp,128
  d0:	08090503          	lb	a0,128(s2)
  d4:	0100                	addi	s0,sp,128
  d6:	08090503          	lb	a0,128(s2)
  da:	0100                	addi	s0,sp,128
  dc:	08090503          	lb	a0,128(s2)
  e0:	0100                	addi	s0,sp,128
  e2:	08090503          	lb	a0,128(s2)
  e6:	0100                	addi	s0,sp,128
  e8:	08090503          	lb	a0,128(s2)
  ec:	0100                	addi	s0,sp,128
  ee:	08090503          	lb	a0,128(s2)
  f2:	0100                	addi	s0,sp,128
  f4:	08090503          	lb	a0,128(s2)
  f8:	0100                	addi	s0,sp,128
  fa:	08090503          	lb	a0,128(s2)
  fe:	0100                	addi	s0,sp,128
 100:	08090503          	lb	a0,128(s2)
 104:	0100                	addi	s0,sp,128
 106:	08090503          	lb	a0,128(s2)
 10a:	0100                	addi	s0,sp,128
 10c:	08090503          	lb	a0,128(s2)
 110:	0100                	addi	s0,sp,128
 112:	08090503          	lb	a0,128(s2)
 116:	0100                	addi	s0,sp,128
 118:	08090503          	lb	a0,128(s2)
 11c:	0100                	addi	s0,sp,128
 11e:	08090503          	lb	a0,128(s2)
 122:	0100                	addi	s0,sp,128
 124:	08090503          	lb	a0,128(s2)
 128:	0100                	addi	s0,sp,128
 12a:	08090503          	lb	a0,128(s2)
 12e:	0100                	addi	s0,sp,128
 130:	08090503          	lb	a0,128(s2)
 134:	0100                	addi	s0,sp,128
 136:	08090503          	lb	a0,128(s2)
 13a:	0100                	addi	s0,sp,128
 13c:	08090103          	lb	sp,128(s2)
 140:	0100                	addi	s0,sp,128
 142:	08090503          	lb	a0,128(s2)
 146:	0100                	addi	s0,sp,128
 148:	08090503          	lb	a0,128(s2)
 14c:	0100                	addi	s0,sp,128
 14e:	08090503          	lb	a0,128(s2)
 152:	0100                	addi	s0,sp,128
 154:	08090503          	lb	a0,128(s2)
 158:	0100                	addi	s0,sp,128
 15a:	08090503          	lb	a0,128(s2)
 15e:	0100                	addi	s0,sp,128
 160:	08090503          	lb	a0,128(s2)
 164:	0100                	addi	s0,sp,128
 166:	08090503          	lb	a0,128(s2)
 16a:	0100                	addi	s0,sp,128
 16c:	08090503          	lb	a0,128(s2)
 170:	0100                	addi	s0,sp,128
 172:	08090503          	lb	a0,128(s2)
 176:	0100                	addi	s0,sp,128
 178:	08090503          	lb	a0,128(s2)
 17c:	0100                	addi	s0,sp,128
 17e:	08090503          	lb	a0,128(s2)
 182:	0100                	addi	s0,sp,128
 184:	08090503          	lb	a0,128(s2)
 188:	0100                	addi	s0,sp,128
 18a:	08090503          	lb	a0,128(s2)
 18e:	0100                	addi	s0,sp,128
 190:	08090503          	lb	a0,128(s2)
 194:	0100                	addi	s0,sp,128
 196:	08090503          	lb	a0,128(s2)
 19a:	0100                	addi	s0,sp,128
 19c:	08090503          	lb	a0,128(s2)
 1a0:	0100                	addi	s0,sp,128
 1a2:	08090503          	lb	a0,128(s2)
 1a6:	0100                	addi	s0,sp,128
 1a8:	08090503          	lb	a0,128(s2)
 1ac:	0100                	addi	s0,sp,128
 1ae:	08090503          	lb	a0,128(s2)
 1b2:	0100                	addi	s0,sp,128
 1b4:	08090503          	lb	a0,128(s2)
 1b8:	0100                	addi	s0,sp,128
 1ba:	08090503          	lb	a0,128(s2)
 1be:	0100                	addi	s0,sp,128
 1c0:	08090503          	lb	a0,128(s2)
 1c4:	0100                	addi	s0,sp,128
 1c6:	08090503          	lb	a0,128(s2)
 1ca:	0100                	addi	s0,sp,128
 1cc:	08090503          	lb	a0,128(s2)
 1d0:	0100                	addi	s0,sp,128
 1d2:	08090503          	lb	a0,128(s2)
 1d6:	0100                	addi	s0,sp,128
 1d8:	08090503          	lb	a0,128(s2)
 1dc:	0100                	addi	s0,sp,128
 1de:	08090503          	lb	a0,128(s2)
 1e2:	0100                	addi	s0,sp,128
 1e4:	08090503          	lb	a0,128(s2)
 1e8:	0100                	addi	s0,sp,128
 1ea:	08090503          	lb	a0,128(s2)
 1ee:	0100                	addi	s0,sp,128
 1f0:	08090503          	lb	a0,128(s2)
 1f4:	0100                	addi	s0,sp,128
 1f6:	08090503          	lb	a0,128(s2)
 1fa:	0100                	addi	s0,sp,128
 1fc:	08090503          	lb	a0,128(s2)
 200:	0100                	addi	s0,sp,128
 202:	08090503          	lb	a0,128(s2)
 206:	0100                	addi	s0,sp,128
 208:	08090503          	lb	a0,128(s2)
 20c:	0100                	addi	s0,sp,128
 20e:	08090403          	lb	s0,128(s2)
 212:	0100                	addi	s0,sp,128
 214:	04090103          	lb	sp,64(s2)
 218:	0100                	addi	s0,sp,128
 21a:	1009                	c.nop	-30
 21c:	0000                	unimp
 21e:	0101                	addi	sp,sp,0

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
  14:	0294                	addi	a3,sp,320
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
  14:	0294                	addi	a3,sp,320
	...

Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	6d6f682f          	0x6d6f682f
   4:	2f65                	jal	7bc <offset+0x734>
   6:	6f6c                	flw	fa1,92(a4)
   8:	6976                	flw	fs2,92(sp)
   a:	65442f73          	csrrs	t5,0x654,s0
   e:	6f746b73          	csrrsi	s6,0x6f7,8
  12:	2f70                	fld	fa2,216(a4)
  14:	6952                	flw	fs2,20(sp)
  16:	6556                	flw	fa0,84(sp)
  18:	5f72                	lw	t5,60(sp)
  1a:	65726f63          	bltu	tp,s7,678 <offset+0x5f0>
  1e:	7369722f          	0x7369722f
  22:	2f666f63          	bltu	a2,s6,320 <offset+0x298>
  26:	6972                	flw	fs2,28(sp)
  28:	2d766373          	csrrsi	t1,0x2d7,12
  2c:	7261                	lui	tp,0xffff8
  2e:	742d6863          	bltu	s10,sp,77e <offset+0x6f6>
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
  54:	69756c2f          	0x69756c2f
  58:	302d                	jal	fffff882 <imm12sh+0xfffffaa7>
  5a:	2e31                	jal	376 <offset+0x2ee>
  5c:	682f0053          	0x682f0053
  60:	2f656d6f          	jal	s10,56356 <offset+0x562ce>
  64:	6f6c                	flw	fa1,92(a4)
  66:	6976                	flw	fs2,92(sp)
  68:	65442f73          	csrrs	t5,0x654,s0
  6c:	6f746b73          	csrrsi	s6,0x6f7,8
  70:	2f70                	fld	fa2,216(a4)
  72:	6952                	flw	fs2,20(sp)
  74:	6556                	flw	fa0,84(sp)
  76:	5f72                	lw	t5,60(sp)
  78:	65726f63          	bltu	tp,s7,6d6 <offset+0x64e>
  7c:	7369722f          	0x7369722f
  80:	2f666f63          	bltu	a2,s6,37e <offset+0x2f6>
  84:	6972                	flw	fs2,28(sp)
  86:	666f6373          	csrrsi	t1,0x666,30
  8a:	775f 726f 2f6b      	0x2f6b726f775f
  90:	7672                	flw	fa2,60(sp)
  92:	5f693233          	0x5f693233
  96:	2f6d                	jal	850 <offset+0x7c8>
  98:	2f49                	jal	82a <offset+0x7a2>
  9a:	2f637273          	csrrci	tp,0x2f6,6
  9e:	756c                	flw	fa1,108(a0)
  a0:	2d69                	jal	73a <offset+0x6b2>
  a2:	3130                	fld	fa2,96(a0)
  a4:	532e                	lw	t1,232(sp)
  a6:	7475642f          	0x7475642f
  aa:	4700                	lw	s0,8(a4)
  ac:	554e                	lw	a0,240(sp)
  ae:	4120                	lw	s0,64(a0)
  b0:	2e322053          	0x2e322053
  b4:	          	snez	a0,zero
