
my.elf:     file format elf32-littleriscv


Disassembly of section .text.init:

80000000 <rvtest_entry_point>:
80000000:	feedc0b7          	lui	ra,0xfeedc
80000004:	ead08093          	addi	ra,ra,-339 # feedbead <edge1+0xfeedbeae>
80000008:	ff76e137          	lui	sp,0xff76e
8000000c:	f5610113          	addi	sp,sp,-170 # ff76df56 <edge1+0xff76df57>
80000010:	7fbb71b7          	lui	gp,0x7fbb7
80000014:	fab18193          	addi	gp,gp,-85 # 7fbb6fab <pos+0x7fbb6f8b>
80000018:	bfddb237          	lui	tp,0xbfddb
8000001c:	7d520213          	addi	tp,tp,2005 # bfddb7d5 <edge1+0xbfddb7d6>
80000020:	00000297          	auipc	t0,0x0
80000024:	05828293          	addi	t0,t0,88 # 80000078 <rvtest_code_begin>
80000028:	00002317          	auipc	t1,0x2
8000002c:	fe830313          	addi	t1,t1,-24 # 80002010 <rvtest_data_begin>
80000030:	b7fbb3b7          	lui	t2,0xb7fbb
80000034:	6fa38393          	addi	t2,t2,1786 # b7fbb6fa <edge1+0xb7fbb6fb>
80000038:	5bfde437          	lui	s0,0x5bfde
8000003c:	b7d40413          	addi	s0,s0,-1155 # 5bfddb7d <pos+0x5bfddb5d>
80000040:	adfef4b7          	lui	s1,0xadfef
80000044:	dbe48493          	addi	s1,s1,-578 # adfeedbe <edge1+0xadfeedbf>
80000048:	56ff7537          	lui	a0,0x56ff7
8000004c:	6df50513          	addi	a0,a0,1759 # 56ff76df <pos+0x56ff76bf>
80000050:	ab7fc5b7          	lui	a1,0xab7fc
80000054:	b6f58593          	addi	a1,a1,-1169 # ab7fbb6f <edge1+0xab7fbb70>
80000058:	d5bfe637          	lui	a2,0xd5bfe
8000005c:	db760613          	addi	a2,a2,-585 # d5bfddb7 <edge1+0xd5bfddb8>
80000060:	eadff6b7          	lui	a3,0xeadff
80000064:	edb68693          	addi	a3,a3,-293 # eadfeedb <edge1+0xeadfeedc>
80000068:	f56ff737          	lui	a4,0xf56ff
8000006c:	76d70713          	addi	a4,a4,1901 # f56ff76d <edge1+0xf56ff76e>
80000070:	fab807b7          	lui	a5,0xfab80
80000074:	bb678793          	addi	a5,a5,-1098 # fab7fbb6 <edge1+0xfab7fbb7>

80000078 <rvtest_code_begin>:
80000078:	00002497          	auipc	s1,0x2
8000007c:	f9848493          	addi	s1,s1,-104 # 80002010 <rvtest_data_begin>
80000080:	fff00413          	li	s0,-1
80000084:	0084a023          	sw	s0,0(s1)
80000088:	0ff0000f          	fence
8000008c:	0004a183          	lw	gp,0(s1)
80000090:	00003497          	auipc	s1,0x3
80000094:	08448493          	addi	s1,s1,132 # 80003114 <signature_x9_1>
80000098:	0034a023          	sw	gp,0(s1)

8000009c <cleanup_epilogs>:
8000009c:	0040006f          	j	800000a0 <exit_cleanup>

800000a0 <exit_cleanup>:
800000a0:	00100093          	li	ra,1

800000a4 <write_tohost>:
800000a4:	00001f17          	auipc	t5,0x1
800000a8:	f41f2e23          	sw	ra,-164(t5) # 80001000 <tohost>
800000ac:	ff9ff06f          	j	800000a4 <write_tohost>
	...

Disassembly of section .tohost:

80001000 <tohost>:
	...

80001100 <fromhost>:
	...

Disassembly of section .data:

80002000 <rvtest_trap_sig>:
80002000:	2018                	fld	fa4,0(s0)
80002002:	8000                	0x8000
	...

80002010 <rvtest_data_begin>:
80002010:	cafe                	sw	t6,84(sp)
80002012:	babe                	fsd	fa5,368(sp)
80002014:	cafe                	sw	t6,84(sp)
80002016:	babe                	fsd	fa5,368(sp)

80002018 <mtrap_sigptr>:
80002018:	deadbeef          	jal	t4,7ffdd602 <pos+0x7ffdd5e2>
8000201c:	deadbeef          	jal	t4,7ffdd606 <pos+0x7ffdd5e6>

80002020 <rvtest_data_end>:
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

80003114 <signature_x9_1>:
80003114:	deadbeef          	jal	t4,7ffde6fe <pos+0x7ffde6de>

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
   8:	01007663          	bgeu	zero,a6,14 <MMODE_SIG+0x11>
   c:	0000000f          	fence	unknown,unknown
  10:	7205                	lui	tp,0xfffe1
  12:	3376                	fld	ft6,376(sp)
  14:	6932                	flw	fs2,12(sp)
  16:	7032                	flw	ft0,44(sp)
  18:	0030                	addi	a2,sp,8

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	00c2                	slli	ra,ra,0x10
   2:	0000                	unimp
   4:	00760003          	lb	zero,7(a2)
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
  70:	6600                	flw	fs0,8(a2)
  72:	6e65                	lui	t3,0x19
  74:	302d6563          	bltu	s10,sp,37e <pos+0x35e>
  78:	2e31                	jal	394 <pos+0x374>
  7a:	00010053          	fadd.s	ft0,ft2,ft0,rne
  7e:	0000                	unimp
  80:	0500                	addi	s0,sp,640
  82:	0002                	c.slli64	zero
  84:	0000                	unimp
  86:	0380                	addi	s0,sp,448
  88:	0110                	addi	a2,sp,128
  8a:	78090603          	lb	a2,1920(s2)
  8e:	0100                	addi	s0,sp,128
  90:	08090103          	lb	sp,128(s2)
  94:	0100                	addi	s0,sp,128
  96:	04090203          	lb	tp,64(s2)
  9a:	0100                	addi	s0,sp,128
  9c:	04090203          	lb	tp,64(s2)
  a0:	0100                	addi	s0,sp,128
  a2:	04090203          	lb	tp,64(s2)
  a6:	0100                	addi	s0,sp,128
  a8:	04090203          	lb	tp,64(s2)
  ac:	0100                	addi	s0,sp,128
  ae:	08090203          	lb	tp,128(s2)
  b2:	0100                	addi	s0,sp,128
  b4:	04090503          	lb	a0,64(s2)
  b8:	0100                	addi	s0,sp,128
  ba:	04090103          	lb	sp,64(s2)
  be:	0100                	addi	s0,sp,128
  c0:	1009                	c.nop	-30
  c2:	0000                	unimp
  c4:	0101                	addi	sp,sp,0

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
  14:	00b0                	addi	a2,sp,72
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
  14:	00b0                	addi	a2,sp,72
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
  54:	6e65662f          	0x6e65662f
  58:	302d6563          	bltu	s10,sp,362 <pos+0x342>
  5c:	2e31                	jal	378 <pos+0x358>
  5e:	682f0053          	0x682f0053
  62:	2f656d6f          	jal	s10,56358 <pos+0x56338>
  66:	6f6c                	flw	fa1,92(a4)
  68:	6976                	flw	fs2,92(sp)
  6a:	65442f73          	csrrs	t5,0x654,s0
  6e:	6f746b73          	csrrsi	s6,0x6f7,8
  72:	2f70                	fld	fa2,216(a4)
  74:	6952                	flw	fs2,20(sp)
  76:	6556                	flw	fa0,84(sp)
  78:	5f72                	lw	t5,60(sp)
  7a:	65726f63          	bltu	tp,s7,6d8 <pos+0x6b8>
  7e:	7369722f          	0x7369722f
  82:	2f666f63          	bltu	a2,s6,380 <pos+0x360>
  86:	6972                	flw	fs2,28(sp)
  88:	666f6373          	csrrsi	t1,0x666,30
  8c:	775f 726f 2f6b      	0x2f6b726f775f
  92:	7672                	flw	fa2,60(sp)
  94:	5f693233          	0x5f693233
  98:	2f6d                	jal	852 <pos+0x832>
  9a:	2f49                	jal	82c <pos+0x80c>
  9c:	2f637273          	csrrci	tp,0x2f6,6
  a0:	6566                	flw	fa0,88(sp)
  a2:	636e                	flw	ft6,216(sp)
  a4:	2d65                	jal	75c <pos+0x73c>
  a6:	3130                	fld	fa2,96(a0)
  a8:	532e                	lw	t1,232(sp)
  aa:	7475642f          	0x7475642f
  ae:	4700                	lw	s0,8(a4)
  b0:	554e                	lw	a0,240(sp)
  b2:	4120                	lw	s0,64(a0)
  b4:	2e322053          	0x2e322053
  b8:	          	snez	a0,zero
