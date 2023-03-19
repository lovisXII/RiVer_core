
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
80000078:	00003097          	auipc	ra,0x3
8000007c:	09c08093          	addi	ra,ra,156 # 80003114 <signature_x1_0>

80000080 <inst_0>:
80000080:	00000597          	auipc	a1,0x0
80000084:	00058593          	mv	a1,a1
80000088:	00000517          	auipc	a0,0x0
8000008c:	03d50513          	addi	a0,a0,61 # 800000c5 <exit_cleanup+0x1>
80000090:	fe0505e7          	jalr	a1,-32(a0)
80000094:	00000013          	nop
80000098:	00000013          	nop
8000009c:	0025c593          	xori	a1,a1,2
800000a0:	00c0006f          	j	800000ac <inst_0+0x2c>
800000a4:	0035c593          	xori	a1,a1,3
800000a8:	0040006f          	j	800000ac <inst_0+0x2c>
800000ac:	00000117          	auipc	sp,0x0
800000b0:	fd410113          	addi	sp,sp,-44 # 80000080 <inst_0>
800000b4:	ffc17113          	andi	sp,sp,-4
800000b8:	402585b3          	sub	a1,a1,sp
800000bc:	00b0a023          	sw	a1,0(ra)

800000c0 <cleanup_epilogs>:
800000c0:	0040006f          	j	800000c4 <exit_cleanup>

800000c4 <exit_cleanup>:
800000c4:	00100093          	li	ra,1

800000c8 <write_tohost>:
800000c8:	00001f17          	auipc	t5,0x1
800000cc:	f21f2c23          	sw	ra,-200(t5) # 80001000 <tohost>
800000d0:	ff9ff06f          	j	800000c8 <write_tohost>
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
80003110:	a309                	j	80003612 <_end+0x4f2>
80003112:	6f5c                	flw	fa5,28(a4)

80003114 <signature_x1_0>:
80003114:	deadbeef          	jal	t4,7ffde6fe <absimmsh+0x2a1e923>

80003118 <sig_end_canary>:
80003118:	a309                	j	8000361a <_end+0x4fa>
8000311a:	6f5c                	flw	fa5,28(a4)

8000311c <rvtest_sig_end>:
8000311c:	0000                	unimp
	...

Disassembly of section .riscv.attributes:

00000000 <.riscv.attributes>:
   0:	1941                	addi	s2,s2,-16
   2:	0000                	unimp
   4:	7200                	flw	fs0,32(a2)
   6:	7369                	lui	t1,0xffffa
   8:	01007663          	bgeu	zero,a6,14 <offset+0x10>
   c:	0000000f          	fence	unknown,unknown
  10:	7205                	lui	tp,0xfffe1
  12:	3376                	fld	ft6,376(sp)
  14:	6932                	flw	fs2,12(sp)
  16:	7032                	flw	ft0,44(sp)
  18:	0030                	addi	a2,sp,8

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	00ad                	addi	ra,ra,11
   2:	0000                	unimp
   4:	007f0003          	lb	zero,7(t5)
   8:	0000                	unimp
   a:	0101                	addi	sp,sp,0
   c:	000d0efb          	0xd0efb
  10:	0101                	addi	sp,sp,0
  12:	0101                	addi	sp,sp,0
  14:	0000                	unimp
  16:	0100                	addi	s0,sp,128
  18:	0000                	unimp
  1a:	2f01                	jal	72a <pos+0x70a>
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
  44:	612d7663          	bgeu	s10,s2,650 <pos+0x630>
  48:	6372                	flw	ft6,28(sp)
  4a:	2d68                	fld	fa0,216(a0)
  4c:	6574                	flw	fa3,76(a0)
  4e:	722f7473          	csrrci	s0,0x722,30
  52:	7369                	lui	t1,0xffffa
  54:	742d7663          	bgeu	s10,sp,7a0 <pos+0x780>
  58:	7365                	lui	t1,0xffff9
  5a:	2d74                	fld	fa3,216(a0)
  5c:	74697573          	csrrci	a0,0x746,18
  60:	2f65                	jal	818 <pos+0x7f8>
  62:	7672                	flw	fa2,60(sp)
  64:	5f693233          	0x5f693233
  68:	2f6d                	jal	822 <pos+0x802>
  6a:	2f49                	jal	7fc <pos+0x7dc>
  6c:	00637273          	csrrci	tp,0x6,6
  70:	6d00                	flw	fs0,24(a0)
  72:	7369                	lui	t1,0xffffa
  74:	6c61                	lui	s8,0x18
  76:	6769                	lui	a4,0x1a
  78:	316e                	fld	ft2,248(sp)
  7a:	6a2d                	lui	s4,0xb
  7c:	6c61                	lui	s8,0x18
  7e:	2d72                	fld	fs10,280(sp)
  80:	3130                	fld	fa2,96(a0)
  82:	532e                	lw	t1,232(sp)
  84:	0100                	addi	s0,sp,128
  86:	0000                	unimp
  88:	0000                	unimp
  8a:	0205                	addi	tp,tp,1
  8c:	0000                	unimp
  8e:	8000                	0x8000
  90:	03011903          	lh	s2,48(sp)
  94:	0906                	slli	s2,s2,0x1
  96:	0078                	addi	a4,sp,12
  98:	0301                	addi	t1,t1,0
  9a:	0905                	addi	s2,s2,1
  9c:	0008                	0x8
  9e:	0301                	addi	t1,t1,0
  a0:	0904                	addi	s1,sp,144
  a2:	0040                	addi	s0,sp,4
  a4:	0301                	addi	t1,t1,0
  a6:	0901                	addi	s2,s2,0
  a8:	0004                	0x4
  aa:	0901                	addi	s2,s2,0
  ac:	0010                	0x10
  ae:	0100                	addi	s0,sp,128
  b0:	01              	Address 0x00000000000000b0 is out of bounds.


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
  14:	00d4                	addi	a3,sp,68
  16:	8000                	0x8000
  18:	0000                	unimp
  1a:	0000                	unimp
  1c:	0069                	c.nop	26
  1e:	0000                	unimp
  20:	00c1                	addi	ra,ra,16
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
  14:	00d4                	addi	a3,sp,68
	...

Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	6d6f682f          	0x6d6f682f
   4:	2f65                	jal	7bc <pos+0x79c>
   6:	6f6c                	flw	fa1,92(a4)
   8:	6976                	flw	fs2,92(sp)
   a:	65442f73          	csrrs	t5,0x654,s0
   e:	6f746b73          	csrrsi	s6,0x6f7,8
  12:	2f70                	fld	fa2,216(a4)
  14:	6952                	flw	fs2,20(sp)
  16:	6556                	flw	fa0,84(sp)
  18:	5f72                	lw	t5,60(sp)
  1a:	65726f63          	bltu	tp,s7,678 <pos+0x658>
  1e:	7369722f          	0x7369722f
  22:	2f666f63          	bltu	a2,s6,320 <pos+0x300>
  26:	6972                	flw	fs2,28(sp)
  28:	2d766373          	csrrsi	t1,0x2d7,12
  2c:	7261                	lui	tp,0xffff8
  2e:	742d6863          	bltu	s10,sp,77e <pos+0x75e>
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
  54:	73696d2f          	0x73696d2f
  58:	6c61                	lui	s8,0x18
  5a:	6769                	lui	a4,0x1a
  5c:	316e                	fld	ft2,248(sp)
  5e:	6a2d                	lui	s4,0xb
  60:	6c61                	lui	s8,0x18
  62:	2d72                	fld	fs10,280(sp)
  64:	3130                	fld	fa2,96(a0)
  66:	532e                	lw	t1,232(sp)
  68:	2f00                	fld	fs0,24(a4)
  6a:	6f68                	flw	fa0,92(a4)
  6c:	656d                	lui	a0,0x1b
  6e:	766f6c2f          	0x766f6c2f
  72:	7369                	lui	t1,0xffffa
  74:	7365442f          	0x7365442f
  78:	706f746b          	0x706f746b
  7c:	5669522f          	0x5669522f
  80:	7265                	lui	tp,0xffff9
  82:	635f 726f 2f65      	0x2f65726f635f
  88:	6972                	flw	fs2,28(sp)
  8a:	666f6373          	csrrsi	t1,0x666,30
  8e:	7369722f          	0x7369722f
  92:	5f666f63          	bltu	a2,s6,690 <pos+0x670>
  96:	6b726f77          	0x6b726f77
  9a:	3376722f          	0x3376722f
  9e:	6932                	flw	fs2,12(sp)
  a0:	6d5f 492f 732f      	0x732f492f6d5f
  a6:	6372                	flw	ft6,28(sp)
  a8:	73696d2f          	0x73696d2f
  ac:	6c61                	lui	s8,0x18
  ae:	6769                	lui	a4,0x1a
  b0:	316e                	fld	ft2,248(sp)
  b2:	6a2d                	lui	s4,0xb
  b4:	6c61                	lui	s8,0x18
  b6:	2d72                	fld	fs10,280(sp)
  b8:	3130                	fld	fa2,96(a0)
  ba:	532e                	lw	t1,232(sp)
  bc:	7475642f          	0x7475642f
  c0:	4700                	lw	s0,8(a4)
  c2:	554e                	lw	a0,240(sp)
  c4:	4120                	lw	s0,64(a0)
  c6:	2e322053          	0x2e322053
  ca:	          	snez	a0,zero
