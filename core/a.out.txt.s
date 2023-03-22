
a.out:     file format elf32-littleriscv


Disassembly of section seg_text:

00010054 <_start>:
   10054:	00406393          	ori	t2,zero,4
   10058:	00606413          	ori	s0,zero,6
   1005c:	01806493          	ori	s1,zero,24
   10060:	02838533          	mul	a0,t2,s0
   10064:	00950463          	beq	a0,s1,1006c <_start+0x18>
   10068:	fa8f106f          	j	1810 <_bad>
   1006c:	80000437          	lui	s0,0x80000
   10070:	fff40413          	addi	s0,s0,-1 # 7fffffff <_isr_vector+0xfeffff2b>
   10074:	00106493          	ori	s1,zero,1
   10078:	02839533          	mulh	a0,t2,s0
   1007c:	00950463          	beq	a0,s1,10084 <_start+0x30>
   10080:	f90f106f          	j	1810 <_bad>
   10084:	0283b533          	mulhu	a0,t2,s0
   10088:	00950463          	beq	a0,s1,10090 <_start+0x3c>
   1008c:	f84f106f          	j	1810 <_bad>
   10090:	ffc06413          	ori	s0,zero,-4
   10094:	ff006493          	ori	s1,zero,-16
   10098:	02838533          	mul	a0,t2,s0
   1009c:	00950463          	beq	a0,s1,100a4 <_start+0x50>
   100a0:	f70f106f          	j	1810 <_bad>
   100a4:	f74f106f          	j	1818 <_good>
   100a8:	00000013          	nop
   100ac:	00000013          	nop

Disassembly of section .riscv.attributes:

00000000 <.riscv.attributes>:
   0:	2241                	jal	180 <_bad-0x1690>
   2:	0000                	unimp
   4:	7200                	flw	fs0,32(a2)
   6:	7369                	lui	t1,0xffffa
   8:	01007663          	bgeu	zero,a6,14 <_bad-0x17fc>
   c:	0018                	0x18
   e:	0000                	unimp
  10:	7205                	lui	tp,0xfffe1
  12:	3376                	fld	ft6,376(sp)
  14:	6932                	flw	fs2,12(sp)
  16:	7032                	flw	ft0,44(sp)
  18:	5f30                	lw	a2,120(a4)
  1a:	326d                	jal	fffff9c4 <_isr_vector+0x7efff8f0>
  1c:	3070                	fld	fa2,224(s0)
  1e:	0800                	addi	s0,sp,16
  20:	0a01                	addi	s4,s4,0
  22:	0b              	Address 0x0000000000000022 is out of bounds.


Disassembly of section seg_exit:

00001800 <_bad-0x10>:
	...

00001810 <_bad>:
    1810:	0000006f          	j	1810 <_bad>
    1814:	ffdff06f          	j	1810 <_bad>

00001818 <_good>:
    1818:	0000006f          	j	1818 <_good>
    181c:	ffdff06f          	j	1818 <_good>

00001820 <_exception_occur>:
    1820:	0000006f          	j	1820 <_exception_occur>
    1824:	ffdff06f          	j	1820 <_exception_occur>

Disassembly of section seg_reset:

80000000 <_reset>:
80000000:	00010e37          	lui	t3,0x10
80000004:	054e0e13          	addi	t3,t3,84 # 10054 <_start>
80000008:	01000e97          	auipc	t4,0x1000
8000000c:	ff8e8e93          	addi	t4,t4,-8 # 81000000 <_exception>
80000010:	90000f37          	lui	t5,0x90000
80000014:	80000db7          	lui	s11,0x80000
80000018:	002ede93          	srli	t4,t4,0x2
8000001c:	002e9e93          	slli	t4,t4,0x2
80000020:	000e8e93          	mv	t4,t4
80000024:	341e1073          	csrw	mepc,t3
80000028:	305e9073          	csrw	mtvec,t4
8000002c:	340f1073          	csrw	mscratch,t5
80000030:	800d9073          	csrw	0x800,s11
80000034:	00010137          	lui	sp,0x10
80000038:	01000497          	auipc	s1,0x1000
8000003c:	09c48493          	addi	s1,s1,156 # 810000d4 <_isr_vector>
80000040:	01000517          	auipc	a0,0x1000
80000044:	ff450513          	addi	a0,a0,-12 # 81000034 <_instruction_address_fault>
80000048:	01000597          	auipc	a1,0x1000
8000004c:	ffc58593          	addi	a1,a1,-4 # 81000044 <_illegal_instruction>
80000050:	01000617          	auipc	a2,0x1000
80000054:	fd460613          	addi	a2,a2,-44 # 81000024 <_instruction_address_misagligned>
80000058:	01000697          	auipc	a3,0x1000
8000005c:	03c68693          	addi	a3,a3,60 # 81000094 <_env_call_u_mode>
80000060:	01000717          	auipc	a4,0x1000
80000064:	04470713          	addi	a4,a4,68 # 810000a4 <_env_call_s_mode>
80000068:	01000797          	auipc	a5,0x1000
8000006c:	04c78793          	addi	a5,a5,76 # 810000b4 <_env_call_m_mode>
80000070:	01000817          	auipc	a6,0x1000
80000074:	fe480813          	addi	a6,a6,-28 # 81000054 <_load_adress_missaligned>
80000078:	01000897          	auipc	a7,0x1000
8000007c:	ffc88893          	addi	a7,a7,-4 # 81000074 <_store_adress_missaligned>
80000080:	01000917          	auipc	s2,0x1000
80000084:	fe490913          	addi	s2,s2,-28 # 81000064 <_load_access_fault>
80000088:	01000997          	auipc	s3,0x1000
8000008c:	ffc98993          	addi	s3,s3,-4 # 81000084 <_store_access_fault>
80000090:	01000a17          	auipc	s4,0x1000
80000094:	034a0a13          	addi	s4,s4,52 # 810000c4 <_env_call_wrong_mode>
80000098:	00c4a023          	sw	a2,0(s1)
8000009c:	00a4a223          	sw	a0,4(s1)
800000a0:	00b4a423          	sw	a1,8(s1)
800000a4:	0104a823          	sw	a6,16(s1)
800000a8:	0124aa23          	sw	s2,20(s1)
800000ac:	0114ac23          	sw	a7,24(s1)
800000b0:	0134ae23          	sw	s3,28(s1)
800000b4:	02d4a023          	sw	a3,32(s1)
800000b8:	02e4a223          	sw	a4,36(s1)
800000bc:	02f4a423          	sw	a5,40(s1)
800000c0:	0744a023          	sw	s4,96(s1)
800000c4:	00000193          	li	gp,0
800000c8:	00000213          	li	tp,0
800000cc:	00000293          	li	t0,0
800000d0:	00000313          	li	t1,0
800000d4:	00000393          	li	t2,0
800000d8:	00000413          	li	s0,0
800000dc:	00000493          	li	s1,0
800000e0:	00000513          	li	a0,0
800000e4:	00000593          	li	a1,0
800000e8:	00000613          	li	a2,0
800000ec:	00000693          	li	a3,0
800000f0:	00000713          	li	a4,0
800000f4:	00000793          	li	a5,0
800000f8:	00000813          	li	a6,0
800000fc:	00000893          	li	a7,0
80000100:	00000913          	li	s2,0
80000104:	00000993          	li	s3,0
80000108:	00000a13          	li	s4,0
8000010c:	00000a93          	li	s5,0
80000110:	00000b13          	li	s6,0
80000114:	00000b93          	li	s7,0
80000118:	00000c13          	li	s8,0
8000011c:	00000c93          	li	s9,0
80000120:	30200073          	mret

Disassembly of section seg_kernel:

81000000 <_exception>:
81000000:	34205573          	csrrwi	a0,mcause,0
81000004:	3400f5f3          	csrrci	a1,mscratch,1
81000008:	00a5a023          	sw	a0,0(a1)
8100000c:	00251513          	slli	a0,a0,0x2
81000010:	00000597          	auipc	a1,0x0
81000014:	0c458593          	addi	a1,a1,196 # 810000d4 <_isr_vector>
81000018:	00a585b3          	add	a1,a1,a0
8100001c:	0005a603          	lw	a2,0(a1)
81000020:	00060067          	jr	a2

81000024 <_instruction_address_misagligned>:
81000024:	00000013          	nop
81000028:	7f001097          	auipc	ra,0x7f001
8100002c:	7f808093          	addi	ra,ra,2040 # 1820 <_isr_vector+0x7f00174c>
81000030:	00008067          	ret

81000034 <_instruction_address_fault>:
81000034:	00000013          	nop
81000038:	7f001097          	auipc	ra,0x7f001
8100003c:	7e808093          	addi	ra,ra,2024 # 1820 <_isr_vector+0x7f00174c>
81000040:	00008067          	ret

81000044 <_illegal_instruction>:
81000044:	00000013          	nop
81000048:	7f001097          	auipc	ra,0x7f001
8100004c:	7d808093          	addi	ra,ra,2008 # 1820 <_isr_vector+0x7f00174c>
81000050:	00008067          	ret

81000054 <_load_adress_missaligned>:
81000054:	00000013          	nop
81000058:	7f001097          	auipc	ra,0x7f001
8100005c:	7c808093          	addi	ra,ra,1992 # 1820 <_isr_vector+0x7f00174c>
81000060:	00008067          	ret

81000064 <_load_access_fault>:
81000064:	00000013          	nop
81000068:	7f001097          	auipc	ra,0x7f001
8100006c:	7b808093          	addi	ra,ra,1976 # 1820 <_isr_vector+0x7f00174c>
81000070:	00008067          	ret

81000074 <_store_adress_missaligned>:
81000074:	00000013          	nop
81000078:	7f001097          	auipc	ra,0x7f001
8100007c:	7a808093          	addi	ra,ra,1960 # 1820 <_isr_vector+0x7f00174c>
81000080:	00008067          	ret

81000084 <_store_access_fault>:
81000084:	00000013          	nop
81000088:	7f001097          	auipc	ra,0x7f001
8100008c:	79808093          	addi	ra,ra,1944 # 1820 <_isr_vector+0x7f00174c>
81000090:	00008067          	ret

81000094 <_env_call_u_mode>:
81000094:	00000013          	nop
81000098:	7f001097          	auipc	ra,0x7f001
8100009c:	78808093          	addi	ra,ra,1928 # 1820 <_isr_vector+0x7f00174c>
810000a0:	00008067          	ret

810000a4 <_env_call_s_mode>:
810000a4:	00000013          	nop
810000a8:	7f001097          	auipc	ra,0x7f001
810000ac:	77808093          	addi	ra,ra,1912 # 1820 <_isr_vector+0x7f00174c>
810000b0:	00008067          	ret

810000b4 <_env_call_m_mode>:
810000b4:	00000013          	nop
810000b8:	7f001097          	auipc	ra,0x7f001
810000bc:	76808093          	addi	ra,ra,1896 # 1820 <_isr_vector+0x7f00174c>
810000c0:	00008067          	ret

810000c4 <_env_call_wrong_mode>:
810000c4:	00000013          	nop
810000c8:	7f001097          	auipc	ra,0x7f001
810000cc:	75808093          	addi	ra,ra,1880 # 1820 <_isr_vector+0x7f00174c>
810000d0:	00008067          	ret
