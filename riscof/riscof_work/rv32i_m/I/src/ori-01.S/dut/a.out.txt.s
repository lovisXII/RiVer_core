
my.elf:     file format elf32-littleriscv


Disassembly of section .text.init:

80000000 <rvtest_entry_point>:
80000000:	feedc0b7          	lui	ra,0xfeedc
80000004:	ead08093          	addi	ra,ra,-339 # feedbead <imm12+0xfeedbeae>
80000008:	ff76e137          	lui	sp,0xff76e
8000000c:	f5610113          	addi	sp,sp,-170 # ff76df56 <imm12+0xff76df57>
80000010:	7fbb71b7          	lui	gp,0x7fbb7
80000014:	fab18193          	addi	gp,gp,-85 # 7fbb6fab <absimmsh+0x7fb76fad>
80000018:	bfddb237          	lui	tp,0xbfddb
8000001c:	7d520213          	addi	tp,tp,2005 # bfddb7d5 <imm12+0xbfddb7d6>
80000020:	00000297          	auipc	t0,0x0
80000024:	05828293          	addi	t0,t0,88 # 80000078 <rvtest_code_begin>
80000028:	00004317          	auipc	t1,0x4
8000002c:	fe830313          	addi	t1,t1,-24 # 80004010 <rvtest_data_begin>
80000030:	b7fbb3b7          	lui	t2,0xb7fbb
80000034:	6fa38393          	addi	t2,t2,1786 # b7fbb6fa <imm12+0xb7fbb6fb>
80000038:	5bfde437          	lui	s0,0x5bfde
8000003c:	b7d40413          	addi	s0,s0,-1155 # 5bfddb7d <absimmsh+0x5bf9db7f>
80000040:	adfef4b7          	lui	s1,0xadfef
80000044:	dbe48493          	addi	s1,s1,-578 # adfeedbe <imm12+0xadfeedbf>
80000048:	56ff7537          	lui	a0,0x56ff7
8000004c:	6df50513          	addi	a0,a0,1759 # 56ff76df <absimmsh+0x56fb76e1>
80000050:	ab7fc5b7          	lui	a1,0xab7fc
80000054:	b6f58593          	addi	a1,a1,-1169 # ab7fbb6f <imm12+0xab7fbb70>
80000058:	d5bfe637          	lui	a2,0xd5bfe
8000005c:	db760613          	addi	a2,a2,-585 # d5bfddb7 <imm12+0xd5bfddb8>
80000060:	eadff6b7          	lui	a3,0xeadff
80000064:	edb68693          	addi	a3,a3,-293 # eadfeedb <imm12+0xeadfeedc>
80000068:	f56ff737          	lui	a4,0xf56ff
8000006c:	76d70713          	addi	a4,a4,1901 # f56ff76d <imm12+0xf56ff76e>
80000070:	fab807b7          	lui	a5,0xfab80
80000074:	bb678793          	addi	a5,a5,-1098 # fab7fbb6 <imm12+0xfab7fbb7>

80000078 <rvtest_code_begin>:
80000078:	00005117          	auipc	sp,0x5
8000007c:	09c10113          	addi	sp,sp,156 # 80005114 <signature_x2_0>

80000080 <inst_0>:
80000080:	dff00293          	li	t0,-513
80000084:	8002eb13          	ori	s6,t0,-2048
80000088:	01612023          	sw	s6,0(sp)

8000008c <inst_1>:
8000008c:	00000d93          	li	s11,0
80000090:	000ded93          	ori	s11,s11,0
80000094:	01b12223          	sw	s11,4(sp)

80000098 <inst_2>:
80000098:	333338b7          	lui	a7,0x33333
8000009c:	33488893          	addi	a7,a7,820 # 33333334 <absimmsh+0x332f3336>
800000a0:	7ff8e413          	ori	s0,a7,2047
800000a4:	00812423          	sw	s0,8(sp)

800000a8 <inst_3>:
800000a8:	ffff5a37          	lui	s4,0xffff5
800000ac:	afca0a13          	addi	s4,s4,-1284 # ffff4afc <imm12+0xffff4afd>
800000b0:	001a6093          	ori	ra,s4,1
800000b4:	00112623          	sw	ra,12(sp)

800000b8 <inst_4>:
800000b8:	80000637          	lui	a2,0x80000
800000bc:	02d66993          	ori	s3,a2,45
800000c0:	01312823          	sw	s3,16(sp)

800000c4 <inst_5>:
800000c4:	80000437          	lui	s0,0x80000
800000c8:	fff40413          	addi	s0,s0,-1 # 7fffffff <imm12+0x80000000>
800000cc:	55546193          	ori	gp,s0,1365
800000d0:	00312a23          	sw	gp,20(sp)

800000d4 <inst_6>:
800000d4:	00100e13          	li	t3,1
800000d8:	667e6d13          	ori	s10,t3,1639
800000dc:	01a12c23          	sw	s10,24(sp)

800000e0 <inst_7>:
800000e0:	00700813          	li	a6,7
800000e4:	ff986b93          	ori	s7,a6,-7
800000e8:	01712e23          	sw	s7,28(sp)

800000ec <inst_8>:
800000ec:	00040cb7          	lui	s9,0x40
800000f0:	002cef93          	ori	t6,s9,2
800000f4:	03f12023          	sw	t6,32(sp)

800000f8 <inst_9>:
800000f8:	20000bb7          	lui	s7,0x20000
800000fc:	004be593          	ori	a1,s7,4
80000100:	02b12223          	sw	a1,36(sp)

80000104 <inst_10>:
80000104:	dff00713          	li	a4,-513
80000108:	00876893          	ori	a7,a4,8
8000010c:	03112423          	sw	a7,40(sp)

80000110 <inst_11>:
80000110:	00200f93          	li	t6,2
80000114:	010fe393          	ori	t2,t6,16
80000118:	02712623          	sw	t2,44(sp)

8000011c <inst_12>:
8000011c:	00008ab7          	lui	s5,0x8
80000120:	020ae213          	ori	tp,s5,32
80000124:	02412823          	sw	tp,48(sp)

80000128 <inst_13>:
80000128:	000017b7          	lui	a5,0x1
8000012c:	80078793          	addi	a5,a5,-2048 # 800 <offset+0x798>
80000130:	0407e293          	ori	t0,a5,64
80000134:	02512a23          	sw	t0,52(sp)

80000138 <inst_14>:
80000138:	fffc0f37          	lui	t5,0xfffc0
8000013c:	ffff0f13          	addi	t5,t5,-1 # fffbffff <imm12+0xfffc0000>
80000140:	080f6c93          	ori	s9,t5,128
80000144:	03912c23          	sw	s9,56(sp)

80000148 <inst_15>:
80000148:	ffb00593          	li	a1,-5
8000014c:	1005ef13          	ori	t5,a1,256
80000150:	03e12e23          	sw	t5,60(sp)

80000154 <inst_16>:
80000154:	fff80237          	lui	tp,0xfff80
80000158:	fff20213          	addi	tp,tp,-1 # fff7ffff <imm12+0xfff80000>
8000015c:	20026513          	ori	a0,tp,512
80000160:	04a12023          	sw	a0,64(sp)

80000164 <inst_17>:
80000164:	c00006b7          	lui	a3,0xc0000
80000168:	fff68693          	addi	a3,a3,-1 # bfffffff <imm12+0xc0000000>
8000016c:	4006e013          	ori	zero,a3,1024
80000170:	04012223          	sw	zero,68(sp)

80000174 <inst_18>:
80000174:	fdf00d13          	li	s10,-33
80000178:	ffed6313          	ori	t1,s10,-2
8000017c:	04612423          	sw	t1,72(sp)

80000180 <inst_19>:
80000180:	0000b9b7          	lui	s3,0xb
80000184:	50398993          	addi	s3,s3,1283 # b503 <absimm+0x7503>
80000188:	ffd9e913          	ori	s2,s3,-3
8000018c:	05212623          	sw	s2,76(sp)

80000190 <inst_20>:
80000190:	100003b7          	lui	t2,0x10000
80000194:	ffb3ea93          	ori	s5,t2,-5
80000198:	05512823          	sw	s5,80(sp)

8000019c <inst_21>:
8000019c:	fff80c37          	lui	s8,0xfff80
800001a0:	fffc0c13          	addi	s8,s8,-1 # fff7ffff <imm12+0xfff80000>
800001a4:	ff7c6813          	ori	a6,s8,-9
800001a8:	05012a23          	sw	a6,84(sp)
800001ac:	00005217          	auipc	tp,0x5
800001b0:	fc020213          	addi	tp,tp,-64 # 8000516c <signature_x4_0>

800001b4 <inst_22>:
800001b4:	00000013          	nop
800001b8:	fef06493          	ori	s1,zero,-17
800001bc:	00922023          	sw	s1,0(tp) # 0 <cryh>

800001c0 <inst_23>:
800001c0:	000021b7          	lui	gp,0x2
800001c4:	fdf1ee13          	ori	t3,gp,-33
800001c8:	01c22223          	sw	t3,4(tp) # 4 <MMODE_SIG+0x1>

800001cc <inst_24>:
800001cc:	555550b7          	lui	ra,0x55555
800001d0:	55608093          	addi	ra,ra,1366 # 55555556 <absimmsh+0x55515558>
800001d4:	fbf0e793          	ori	a5,ra,-65
800001d8:	00f22423          	sw	a5,8(tp) # 8 <MMODE_SIG+0x5>

800001dc <inst_25>:
800001dc:	ffff5937          	lui	s2,0xffff5
800001e0:	afc90913          	addi	s2,s2,-1284 # ffff4afc <imm12+0xffff4afd>
800001e4:	f7f96113          	ori	sp,s2,-129
800001e8:	00222623          	sw	sp,12(tp) # c <MMODE_SIG+0x9>

800001ec <inst_26>:
800001ec:	aaaabb37          	lui	s6,0xaaaab
800001f0:	aaab0b13          	addi	s6,s6,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
800001f4:	effb6a13          	ori	s4,s6,-257
800001f8:	01422823          	sw	s4,16(tp) # 10 <edge2+0x1>

800001fc <inst_27>:
800001fc:	01000337          	lui	t1,0x1000
80000200:	dff36693          	ori	a3,t1,-513
80000204:	00d22a23          	sw	a3,20(tp) # 14 <edge2+0x5>

80000208 <inst_28>:
80000208:	20000eb7          	lui	t4,0x20000
8000020c:	bffee713          	ori	a4,t4,-1025
80000210:	00e22c23          	sw	a4,24(tp) # 18 <edge2+0x9>

80000214 <inst_29>:
80000214:	ffff5137          	lui	sp,0xffff5
80000218:	afc10113          	addi	sp,sp,-1284 # ffff4afc <imm12+0xffff4afd>
8000021c:	aaa16613          	ori	a2,sp,-1366
80000220:	00c22e23          	sw	a2,28(tp) # 1c <edge2+0xd>

80000224 <inst_30>:
80000224:	00400493          	li	s1,4
80000228:	0054ec13          	ori	s8,s1,5
8000022c:	03822023          	sw	s8,32(tp) # 20 <pos>

80000230 <inst_31>:
80000230:	00800513          	li	a0,8
80000234:	00656e93          	ori	t4,a0,6
80000238:	03d22223          	sw	t4,36(tp) # 24 <pos+0x4>

8000023c <inst_32>:
8000023c:	01000513          	li	a0,16
80000240:	20056593          	ori	a1,a0,512
80000244:	02b22423          	sw	a1,40(tp) # 28 <pos+0x8>

80000248 <inst_33>:
80000248:	02000513          	li	a0,32
8000024c:	02c56593          	ori	a1,a0,44
80000250:	02b22623          	sw	a1,44(tp) # 2c <pos+0xc>

80000254 <inst_34>:
80000254:	04000513          	li	a0,64
80000258:	00356593          	ori	a1,a0,3
8000025c:	02b22823          	sw	a1,48(tp) # 30 <pos+0x10>

80000260 <inst_35>:
80000260:	08000513          	li	a0,128
80000264:	02056593          	ori	a1,a0,32
80000268:	02b22a23          	sw	a1,52(tp) # 34 <pos+0x14>

8000026c <inst_36>:
8000026c:	10000513          	li	a0,256
80000270:	fbf56593          	ori	a1,a0,-65
80000274:	02b22c23          	sw	a1,56(tp) # 38 <pos+0x18>

80000278 <inst_37>:
80000278:	20000513          	li	a0,512
8000027c:	ffa56593          	ori	a1,a0,-6
80000280:	02b22e23          	sw	a1,60(tp) # 3c <pos+0x1c>

80000284 <inst_38>:
80000284:	40000513          	li	a0,1024
80000288:	fd356593          	ori	a1,a0,-45
8000028c:	04b22023          	sw	a1,64(tp) # 40 <pos+0x20>

80000290 <inst_39>:
80000290:	00001537          	lui	a0,0x1
80000294:	00556593          	ori	a1,a0,5
80000298:	04b22223          	sw	a1,68(tp) # 44 <pos+0x24>

8000029c <inst_40>:
8000029c:	00004537          	lui	a0,0x4
800002a0:	66556593          	ori	a1,a0,1637
800002a4:	04b22423          	sw	a1,72(tp) # 48 <pos+0x28>

800002a8 <inst_41>:
800002a8:	00010537          	lui	a0,0x10
800002ac:	00956593          	ori	a1,a0,9
800002b0:	04b22623          	sw	a1,76(tp) # 4c <pos+0x2c>

800002b4 <inst_42>:
800002b4:	00020537          	lui	a0,0x20
800002b8:	20056593          	ori	a1,a0,512
800002bc:	04b22823          	sw	a1,80(tp) # 50 <pos+0x30>

800002c0 <inst_43>:
800002c0:	00080537          	lui	a0,0x80
800002c4:	00056593          	ori	a1,a0,0
800002c8:	04b22a23          	sw	a1,84(tp) # 54 <pos+0x34>

800002cc <inst_44>:
800002cc:	00100537          	lui	a0,0x100
800002d0:	20056593          	ori	a1,a0,512
800002d4:	04b22c23          	sw	a1,88(tp) # 58 <pos+0x38>

800002d8 <inst_45>:
800002d8:	00200537          	lui	a0,0x200
800002dc:	fd456593          	ori	a1,a0,-44
800002e0:	04b22e23          	sw	a1,92(tp) # 5c <pos+0x3c>

800002e4 <inst_46>:
800002e4:	00400537          	lui	a0,0x400
800002e8:	dff56593          	ori	a1,a0,-513
800002ec:	06b22023          	sw	a1,96(tp) # 60 <pos+0x40>

800002f0 <inst_47>:
800002f0:	00800537          	lui	a0,0x800
800002f4:	08056593          	ori	a1,a0,128
800002f8:	06b22223          	sw	a1,100(tp) # 64 <pos+0x44>

800002fc <inst_48>:
800002fc:	02000537          	lui	a0,0x2000
80000300:	fdf56593          	ori	a1,a0,-33
80000304:	06b22423          	sw	a1,104(tp) # 68 <offset>

80000308 <inst_49>:
80000308:	04000537          	lui	a0,0x4000
8000030c:	01056593          	ori	a1,a0,16
80000310:	06b22623          	sw	a1,108(tp) # 6c <offset+0x4>

80000314 <inst_50>:
80000314:	08000537          	lui	a0,0x8000
80000318:	55456593          	ori	a1,a0,1364
8000031c:	06b22823          	sw	a1,112(tp) # 70 <offset+0x8>

80000320 <inst_51>:
80000320:	40000537          	lui	a0,0x40000
80000324:	ffa56593          	ori	a1,a0,-6
80000328:	06b22a23          	sw	a1,116(tp) # 74 <offset+0xc>

8000032c <inst_52>:
8000032c:	ffe00513          	li	a0,-2
80000330:	fbf56593          	ori	a1,a0,-65
80000334:	06b22c23          	sw	a1,120(tp) # 78 <offset+0x10>

80000338 <inst_53>:
80000338:	ffd00513          	li	a0,-3
8000033c:	ff756593          	ori	a1,a0,-9
80000340:	06b22e23          	sw	a1,124(tp) # 7c <offset+0x14>

80000344 <inst_54>:
80000344:	ff700513          	li	a0,-9
80000348:	80056593          	ori	a1,a0,-2048
8000034c:	08b22023          	sw	a1,128(tp) # 80 <offset+0x18>

80000350 <inst_55>:
80000350:	fef00513          	li	a0,-17
80000354:	fd356593          	ori	a1,a0,-45
80000358:	08b22223          	sw	a1,132(tp) # 84 <offset+0x1c>

8000035c <inst_56>:
8000035c:	fbf00513          	li	a0,-65
80000360:	aaa56593          	ori	a1,a0,-1366
80000364:	08b22423          	sw	a1,136(tp) # 88 <offset+0x20>

80000368 <inst_57>:
80000368:	f7f00513          	li	a0,-129
8000036c:	66556593          	ori	a1,a0,1637
80000370:	08b22623          	sw	a1,140(tp) # 8c <offset+0x24>

80000374 <inst_58>:
80000374:	eff00513          	li	a0,-257
80000378:	66656593          	ori	a1,a0,1638
8000037c:	08b22823          	sw	a1,144(tp) # 90 <offset+0x28>

80000380 <inst_59>:
80000380:	bff00513          	li	a0,-1025
80000384:	66656593          	ori	a1,a0,1638
80000388:	08b22a23          	sw	a1,148(tp) # 94 <offset+0x2c>

8000038c <inst_60>:
8000038c:	fffff537          	lui	a0,0xfffff
80000390:	7ff50513          	addi	a0,a0,2047 # fffff7ff <imm12+0xfffff800>
80000394:	7ff56593          	ori	a1,a0,2047
80000398:	08b22c23          	sw	a1,152(tp) # 98 <offset+0x30>

8000039c <inst_61>:
8000039c:	fffff537          	lui	a0,0xfffff
800003a0:	fff50513          	addi	a0,a0,-1 # ffffefff <imm12+0xfffff000>
800003a4:	00756593          	ori	a1,a0,7
800003a8:	08b22e23          	sw	a1,156(tp) # 9c <offset+0x34>

800003ac <inst_62>:
800003ac:	ffffe537          	lui	a0,0xffffe
800003b0:	fff50513          	addi	a0,a0,-1 # ffffdfff <imm12+0xffffe000>
800003b4:	fdf56593          	ori	a1,a0,-33
800003b8:	0ab22023          	sw	a1,160(tp) # a0 <offset+0x38>

800003bc <inst_63>:
800003bc:	ffff8537          	lui	a0,0xffff8
800003c0:	fff50513          	addi	a0,a0,-1 # ffff7fff <imm12+0xffff8000>
800003c4:	02d56593          	ori	a1,a0,45
800003c8:	0ab22223          	sw	a1,164(tp) # a4 <offset+0x3c>

800003cc <inst_64>:
800003cc:	ffff0537          	lui	a0,0xffff0
800003d0:	fff50513          	addi	a0,a0,-1 # fffeffff <imm12+0xffff0000>
800003d4:	33256593          	ori	a1,a0,818
800003d8:	0ab22423          	sw	a1,168(tp) # a8 <offset+0x40>

800003dc <inst_65>:
800003dc:	fffe0537          	lui	a0,0xfffe0
800003e0:	fff50513          	addi	a0,a0,-1 # fffdffff <imm12+0xfffe0000>
800003e4:	ff656593          	ori	a1,a0,-10
800003e8:	0ab22623          	sw	a1,172(tp) # ac <offset+0x44>

800003ec <inst_66>:
800003ec:	fff00537          	lui	a0,0xfff00
800003f0:	fff50513          	addi	a0,a0,-1 # ffefffff <imm12+0xfff00000>
800003f4:	00656593          	ori	a1,a0,6
800003f8:	0ab22823          	sw	a1,176(tp) # b0 <offset+0x48>

800003fc <inst_67>:
800003fc:	ffe00537          	lui	a0,0xffe00
80000400:	fff50513          	addi	a0,a0,-1 # ffdfffff <imm12+0xffe00000>
80000404:	c0056593          	ori	a1,a0,-1024
80000408:	0ab22a23          	sw	a1,180(tp) # b4 <offset+0x4c>

8000040c <inst_68>:
8000040c:	ffc00537          	lui	a0,0xffc00
80000410:	fff50513          	addi	a0,a0,-1 # ffbfffff <imm12+0xffc00000>
80000414:	fd456593          	ori	a1,a0,-44
80000418:	0ab22c23          	sw	a1,184(tp) # b8 <offset+0x50>

8000041c <inst_69>:
8000041c:	ff800537          	lui	a0,0xff800
80000420:	fff50513          	addi	a0,a0,-1 # ff7fffff <imm12+0xff800000>
80000424:	ff656593          	ori	a1,a0,-10
80000428:	0ab22e23          	sw	a1,188(tp) # bc <offset+0x54>

8000042c <inst_70>:
8000042c:	ff000537          	lui	a0,0xff000
80000430:	fff50513          	addi	a0,a0,-1 # feffffff <imm12+0xff000000>
80000434:	3ff56593          	ori	a1,a0,1023
80000438:	0cb22023          	sw	a1,192(tp) # c0 <offset+0x58>

8000043c <inst_71>:
8000043c:	fe000537          	lui	a0,0xfe000
80000440:	fff50513          	addi	a0,a0,-1 # fdffffff <imm12+0xfe000000>
80000444:	ff856593          	ori	a1,a0,-8
80000448:	0cb22223          	sw	a1,196(tp) # c4 <offset+0x5c>

8000044c <inst_72>:
8000044c:	fc000537          	lui	a0,0xfc000
80000450:	fff50513          	addi	a0,a0,-1 # fbffffff <imm12+0xfc000000>
80000454:	00456593          	ori	a1,a0,4
80000458:	0cb22423          	sw	a1,200(tp) # c8 <offset+0x60>

8000045c <inst_73>:
8000045c:	f8000537          	lui	a0,0xf8000
80000460:	fff50513          	addi	a0,a0,-1 # f7ffffff <imm12+0xf8000000>
80000464:	ffa56593          	ori	a1,a0,-6
80000468:	0cb22623          	sw	a1,204(tp) # cc <offset+0x64>

8000046c <inst_74>:
8000046c:	f0000537          	lui	a0,0xf0000
80000470:	fff50513          	addi	a0,a0,-1 # efffffff <imm12+0xf0000000>
80000474:	ff956593          	ori	a1,a0,-7
80000478:	0cb22823          	sw	a1,208(tp) # d0 <offset+0x68>

8000047c <inst_75>:
8000047c:	e0000537          	lui	a0,0xe0000
80000480:	fff50513          	addi	a0,a0,-1 # dfffffff <imm12+0xe0000000>
80000484:	55456593          	ori	a1,a0,1364
80000488:	0cb22a23          	sw	a1,212(tp) # d4 <offset+0x6c>

8000048c <inst_76>:
8000048c:	55555537          	lui	a0,0x55555
80000490:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
80000494:	eff56593          	ori	a1,a0,-257
80000498:	0cb22c23          	sw	a1,216(tp) # d8 <offset+0x70>

8000049c <inst_77>:
8000049c:	00300513          	li	a0,3
800004a0:	00356593          	ori	a1,a0,3
800004a4:	0cb22e23          	sw	a1,220(tp) # dc <offset+0x74>

800004a8 <inst_78>:
800004a8:	00300513          	li	a0,3
800004ac:	55556593          	ori	a1,a0,1365
800004b0:	0eb22023          	sw	a1,224(tp) # e0 <offset+0x78>

800004b4 <inst_79>:
800004b4:	00300513          	li	a0,3
800004b8:	aaa56593          	ori	a1,a0,-1366
800004bc:	0eb22223          	sw	a1,228(tp) # e4 <offset+0x7c>

800004c0 <inst_80>:
800004c0:	00300513          	li	a0,3
800004c4:	00556593          	ori	a1,a0,5
800004c8:	0eb22423          	sw	a1,232(tp) # e8 <offset+0x80>

800004cc <inst_81>:
800004cc:	00300513          	li	a0,3
800004d0:	33356593          	ori	a1,a0,819
800004d4:	0eb22623          	sw	a1,236(tp) # ec <offset+0x84>

800004d8 <inst_82>:
800004d8:	00300513          	li	a0,3
800004dc:	66656593          	ori	a1,a0,1638
800004e0:	0eb22823          	sw	a1,240(tp) # f0 <offset+0x88>

800004e4 <inst_83>:
800004e4:	00300513          	li	a0,3
800004e8:	fd356593          	ori	a1,a0,-45
800004ec:	0eb22a23          	sw	a1,244(tp) # f4 <offset+0x8c>

800004f0 <inst_84>:
800004f0:	00300513          	li	a0,3
800004f4:	02d56593          	ori	a1,a0,45
800004f8:	0eb22c23          	sw	a1,248(tp) # f8 <offset+0x90>

800004fc <inst_85>:
800004fc:	00300513          	li	a0,3
80000500:	00256593          	ori	a1,a0,2
80000504:	0eb22e23          	sw	a1,252(tp) # fc <offset+0x94>

80000508 <inst_86>:
80000508:	00300513          	li	a0,3
8000050c:	55456593          	ori	a1,a0,1364
80000510:	10b22023          	sw	a1,256(tp) # 100 <offset+0x98>

80000514 <inst_87>:
80000514:	00300513          	li	a0,3
80000518:	00056593          	ori	a1,a0,0
8000051c:	10b22223          	sw	a1,260(tp) # 104 <offset+0x9c>

80000520 <inst_88>:
80000520:	00300513          	li	a0,3
80000524:	00456593          	ori	a1,a0,4
80000528:	10b22423          	sw	a1,264(tp) # 108 <offset+0xa0>

8000052c <inst_89>:
8000052c:	00300513          	li	a0,3
80000530:	33256593          	ori	a1,a0,818
80000534:	10b22623          	sw	a1,268(tp) # 10c <offset+0xa4>

80000538 <inst_90>:
80000538:	00300513          	li	a0,3
8000053c:	66556593          	ori	a1,a0,1637
80000540:	10b22823          	sw	a1,272(tp) # 110 <offset+0xa8>

80000544 <inst_91>:
80000544:	00300513          	li	a0,3
80000548:	02c56593          	ori	a1,a0,44
8000054c:	10b22a23          	sw	a1,276(tp) # 114 <offset+0xac>

80000550 <inst_92>:
80000550:	00300513          	li	a0,3
80000554:	55656593          	ori	a1,a0,1366
80000558:	10b22c23          	sw	a1,280(tp) # 118 <offset+0xb0>

8000055c <inst_93>:
8000055c:	00300513          	li	a0,3
80000560:	aab56593          	ori	a1,a0,-1365
80000564:	10b22e23          	sw	a1,284(tp) # 11c <offset+0xb4>

80000568 <inst_94>:
80000568:	00300513          	li	a0,3
8000056c:	00656593          	ori	a1,a0,6
80000570:	12b22023          	sw	a1,288(tp) # 120 <offset+0xb8>

80000574 <inst_95>:
80000574:	00300513          	li	a0,3
80000578:	33456593          	ori	a1,a0,820
8000057c:	12b22223          	sw	a1,292(tp) # 124 <offset+0xbc>

80000580 <inst_96>:
80000580:	00300513          	li	a0,3
80000584:	66756593          	ori	a1,a0,1639
80000588:	12b22423          	sw	a1,296(tp) # 128 <offset+0xc0>

8000058c <inst_97>:
8000058c:	00300513          	li	a0,3
80000590:	fd456593          	ori	a1,a0,-44
80000594:	12b22623          	sw	a1,300(tp) # 12c <offset+0xc4>

80000598 <inst_98>:
80000598:	00300513          	li	a0,3
8000059c:	02e56593          	ori	a1,a0,46
800005a0:	12b22823          	sw	a1,304(tp) # 130 <offset+0xc8>

800005a4 <inst_99>:
800005a4:	55555537          	lui	a0,0x55555
800005a8:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
800005ac:	00356593          	ori	a1,a0,3
800005b0:	12b22a23          	sw	a1,308(tp) # 134 <offset+0xcc>

800005b4 <inst_100>:
800005b4:	55555537          	lui	a0,0x55555
800005b8:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
800005bc:	55556593          	ori	a1,a0,1365
800005c0:	12b22c23          	sw	a1,312(tp) # 138 <offset+0xd0>

800005c4 <inst_101>:
800005c4:	55555537          	lui	a0,0x55555
800005c8:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
800005cc:	aaa56593          	ori	a1,a0,-1366
800005d0:	12b22e23          	sw	a1,316(tp) # 13c <offset+0xd4>

800005d4 <inst_102>:
800005d4:	55555537          	lui	a0,0x55555
800005d8:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
800005dc:	00556593          	ori	a1,a0,5
800005e0:	14b22023          	sw	a1,320(tp) # 140 <offset+0xd8>

800005e4 <inst_103>:
800005e4:	55555537          	lui	a0,0x55555
800005e8:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
800005ec:	33356593          	ori	a1,a0,819
800005f0:	14b22223          	sw	a1,324(tp) # 144 <offset+0xdc>

800005f4 <inst_104>:
800005f4:	55555537          	lui	a0,0x55555
800005f8:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
800005fc:	66656593          	ori	a1,a0,1638
80000600:	14b22423          	sw	a1,328(tp) # 148 <offset+0xe0>

80000604 <inst_105>:
80000604:	55555537          	lui	a0,0x55555
80000608:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
8000060c:	fd356593          	ori	a1,a0,-45
80000610:	14b22623          	sw	a1,332(tp) # 14c <offset+0xe4>

80000614 <inst_106>:
80000614:	55555537          	lui	a0,0x55555
80000618:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
8000061c:	02d56593          	ori	a1,a0,45
80000620:	14b22823          	sw	a1,336(tp) # 150 <offset+0xe8>

80000624 <inst_107>:
80000624:	55555537          	lui	a0,0x55555
80000628:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
8000062c:	00256593          	ori	a1,a0,2
80000630:	14b22a23          	sw	a1,340(tp) # 154 <offset+0xec>

80000634 <inst_108>:
80000634:	55555537          	lui	a0,0x55555
80000638:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
8000063c:	55456593          	ori	a1,a0,1364
80000640:	14b22c23          	sw	a1,344(tp) # 158 <offset+0xf0>

80000644 <inst_109>:
80000644:	55555537          	lui	a0,0x55555
80000648:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
8000064c:	00056593          	ori	a1,a0,0
80000650:	14b22e23          	sw	a1,348(tp) # 15c <offset+0xf4>

80000654 <inst_110>:
80000654:	55555537          	lui	a0,0x55555
80000658:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
8000065c:	00456593          	ori	a1,a0,4
80000660:	16b22023          	sw	a1,352(tp) # 160 <offset+0xf8>

80000664 <inst_111>:
80000664:	55555537          	lui	a0,0x55555
80000668:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
8000066c:	33256593          	ori	a1,a0,818
80000670:	16b22223          	sw	a1,356(tp) # 164 <offset+0xfc>

80000674 <inst_112>:
80000674:	55555537          	lui	a0,0x55555
80000678:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
8000067c:	66556593          	ori	a1,a0,1637
80000680:	16b22423          	sw	a1,360(tp) # 168 <offset+0x100>

80000684 <inst_113>:
80000684:	55555537          	lui	a0,0x55555
80000688:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
8000068c:	02c56593          	ori	a1,a0,44
80000690:	16b22623          	sw	a1,364(tp) # 16c <offset+0x104>

80000694 <inst_114>:
80000694:	55555537          	lui	a0,0x55555
80000698:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
8000069c:	55656593          	ori	a1,a0,1366
800006a0:	16b22823          	sw	a1,368(tp) # 170 <offset+0x108>

800006a4 <inst_115>:
800006a4:	55555537          	lui	a0,0x55555
800006a8:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
800006ac:	aab56593          	ori	a1,a0,-1365
800006b0:	16b22a23          	sw	a1,372(tp) # 174 <offset+0x10c>

800006b4 <inst_116>:
800006b4:	55555537          	lui	a0,0x55555
800006b8:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
800006bc:	00656593          	ori	a1,a0,6
800006c0:	16b22c23          	sw	a1,376(tp) # 178 <offset+0x110>

800006c4 <inst_117>:
800006c4:	55555537          	lui	a0,0x55555
800006c8:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
800006cc:	33456593          	ori	a1,a0,820
800006d0:	16b22e23          	sw	a1,380(tp) # 17c <offset+0x114>

800006d4 <inst_118>:
800006d4:	55555537          	lui	a0,0x55555
800006d8:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
800006dc:	66756593          	ori	a1,a0,1639
800006e0:	18b22023          	sw	a1,384(tp) # 180 <offset+0x118>

800006e4 <inst_119>:
800006e4:	55555537          	lui	a0,0x55555
800006e8:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
800006ec:	fd456593          	ori	a1,a0,-44
800006f0:	18b22223          	sw	a1,388(tp) # 184 <offset+0x11c>

800006f4 <inst_120>:
800006f4:	55555537          	lui	a0,0x55555
800006f8:	55550513          	addi	a0,a0,1365 # 55555555 <absimmsh+0x55515557>
800006fc:	02e56593          	ori	a1,a0,46
80000700:	18b22423          	sw	a1,392(tp) # 188 <offset+0x120>

80000704 <inst_121>:
80000704:	aaaab537          	lui	a0,0xaaaab
80000708:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
8000070c:	00356593          	ori	a1,a0,3
80000710:	18b22623          	sw	a1,396(tp) # 18c <offset+0x124>

80000714 <inst_122>:
80000714:	aaaab537          	lui	a0,0xaaaab
80000718:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
8000071c:	55556593          	ori	a1,a0,1365
80000720:	18b22823          	sw	a1,400(tp) # 190 <offset+0x128>

80000724 <inst_123>:
80000724:	aaaab537          	lui	a0,0xaaaab
80000728:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
8000072c:	aaa56593          	ori	a1,a0,-1366
80000730:	18b22a23          	sw	a1,404(tp) # 194 <offset+0x12c>

80000734 <inst_124>:
80000734:	aaaab537          	lui	a0,0xaaaab
80000738:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
8000073c:	00556593          	ori	a1,a0,5
80000740:	18b22c23          	sw	a1,408(tp) # 198 <offset+0x130>

80000744 <inst_125>:
80000744:	aaaab537          	lui	a0,0xaaaab
80000748:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
8000074c:	33356593          	ori	a1,a0,819
80000750:	18b22e23          	sw	a1,412(tp) # 19c <offset+0x134>

80000754 <inst_126>:
80000754:	aaaab537          	lui	a0,0xaaaab
80000758:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
8000075c:	66656593          	ori	a1,a0,1638
80000760:	1ab22023          	sw	a1,416(tp) # 1a0 <offset+0x138>

80000764 <inst_127>:
80000764:	aaaab537          	lui	a0,0xaaaab
80000768:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
8000076c:	fd356593          	ori	a1,a0,-45
80000770:	1ab22223          	sw	a1,420(tp) # 1a4 <offset+0x13c>

80000774 <inst_128>:
80000774:	aaaab537          	lui	a0,0xaaaab
80000778:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
8000077c:	02d56593          	ori	a1,a0,45
80000780:	1ab22423          	sw	a1,424(tp) # 1a8 <offset+0x140>

80000784 <inst_129>:
80000784:	aaaab537          	lui	a0,0xaaaab
80000788:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
8000078c:	00256593          	ori	a1,a0,2
80000790:	1ab22623          	sw	a1,428(tp) # 1ac <offset+0x144>

80000794 <inst_130>:
80000794:	aaaab537          	lui	a0,0xaaaab
80000798:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
8000079c:	55456593          	ori	a1,a0,1364
800007a0:	1ab22823          	sw	a1,432(tp) # 1b0 <offset+0x148>

800007a4 <inst_131>:
800007a4:	aaaab537          	lui	a0,0xaaaab
800007a8:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
800007ac:	00056593          	ori	a1,a0,0
800007b0:	1ab22a23          	sw	a1,436(tp) # 1b4 <offset+0x14c>

800007b4 <inst_132>:
800007b4:	aaaab537          	lui	a0,0xaaaab
800007b8:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
800007bc:	00456593          	ori	a1,a0,4
800007c0:	1ab22c23          	sw	a1,440(tp) # 1b8 <offset+0x150>

800007c4 <inst_133>:
800007c4:	aaaab537          	lui	a0,0xaaaab
800007c8:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
800007cc:	33256593          	ori	a1,a0,818
800007d0:	1ab22e23          	sw	a1,444(tp) # 1bc <offset+0x154>

800007d4 <inst_134>:
800007d4:	aaaab537          	lui	a0,0xaaaab
800007d8:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
800007dc:	66556593          	ori	a1,a0,1637
800007e0:	1cb22023          	sw	a1,448(tp) # 1c0 <offset+0x158>

800007e4 <inst_135>:
800007e4:	aaaab537          	lui	a0,0xaaaab
800007e8:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
800007ec:	02c56593          	ori	a1,a0,44
800007f0:	1cb22223          	sw	a1,452(tp) # 1c4 <offset+0x15c>

800007f4 <inst_136>:
800007f4:	aaaab537          	lui	a0,0xaaaab
800007f8:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
800007fc:	55656593          	ori	a1,a0,1366
80000800:	1cb22423          	sw	a1,456(tp) # 1c8 <offset+0x160>

80000804 <inst_137>:
80000804:	aaaab537          	lui	a0,0xaaaab
80000808:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
8000080c:	aab56593          	ori	a1,a0,-1365
80000810:	1cb22623          	sw	a1,460(tp) # 1cc <offset+0x164>

80000814 <inst_138>:
80000814:	aaaab537          	lui	a0,0xaaaab
80000818:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
8000081c:	00656593          	ori	a1,a0,6
80000820:	1cb22823          	sw	a1,464(tp) # 1d0 <offset+0x168>

80000824 <inst_139>:
80000824:	aaaab537          	lui	a0,0xaaaab
80000828:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
8000082c:	33456593          	ori	a1,a0,820
80000830:	1cb22a23          	sw	a1,468(tp) # 1d4 <offset+0x16c>

80000834 <inst_140>:
80000834:	aaaab537          	lui	a0,0xaaaab
80000838:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
8000083c:	66756593          	ori	a1,a0,1639
80000840:	1cb22c23          	sw	a1,472(tp) # 1d8 <offset+0x170>

80000844 <inst_141>:
80000844:	aaaab537          	lui	a0,0xaaaab
80000848:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
8000084c:	fd456593          	ori	a1,a0,-44
80000850:	1cb22e23          	sw	a1,476(tp) # 1dc <offset+0x174>

80000854 <inst_142>:
80000854:	aaaab537          	lui	a0,0xaaaab
80000858:	aaa50513          	addi	a0,a0,-1366 # aaaaaaaa <imm12+0xaaaaaaab>
8000085c:	02e56593          	ori	a1,a0,46
80000860:	1eb22023          	sw	a1,480(tp) # 1e0 <offset+0x178>

80000864 <inst_143>:
80000864:	00500513          	li	a0,5
80000868:	00356593          	ori	a1,a0,3
8000086c:	1eb22223          	sw	a1,484(tp) # 1e4 <offset+0x17c>

80000870 <inst_144>:
80000870:	00500513          	li	a0,5
80000874:	55556593          	ori	a1,a0,1365
80000878:	1eb22423          	sw	a1,488(tp) # 1e8 <offset+0x180>

8000087c <inst_145>:
8000087c:	00500513          	li	a0,5
80000880:	aaa56593          	ori	a1,a0,-1366
80000884:	1eb22623          	sw	a1,492(tp) # 1ec <offset+0x184>

80000888 <inst_146>:
80000888:	00500513          	li	a0,5
8000088c:	00556593          	ori	a1,a0,5
80000890:	1eb22823          	sw	a1,496(tp) # 1f0 <offset+0x188>

80000894 <inst_147>:
80000894:	00500513          	li	a0,5
80000898:	33356593          	ori	a1,a0,819
8000089c:	1eb22a23          	sw	a1,500(tp) # 1f4 <offset+0x18c>

800008a0 <inst_148>:
800008a0:	00500513          	li	a0,5
800008a4:	66656593          	ori	a1,a0,1638
800008a8:	1eb22c23          	sw	a1,504(tp) # 1f8 <offset+0x190>

800008ac <inst_149>:
800008ac:	00500513          	li	a0,5
800008b0:	fd356593          	ori	a1,a0,-45
800008b4:	1eb22e23          	sw	a1,508(tp) # 1fc <offset+0x194>

800008b8 <inst_150>:
800008b8:	00500513          	li	a0,5
800008bc:	02d56593          	ori	a1,a0,45
800008c0:	20b22023          	sw	a1,512(tp) # 200 <offset+0x198>

800008c4 <inst_151>:
800008c4:	00500513          	li	a0,5
800008c8:	00256593          	ori	a1,a0,2
800008cc:	20b22223          	sw	a1,516(tp) # 204 <offset+0x19c>

800008d0 <inst_152>:
800008d0:	00500513          	li	a0,5
800008d4:	55456593          	ori	a1,a0,1364
800008d8:	20b22423          	sw	a1,520(tp) # 208 <offset+0x1a0>

800008dc <inst_153>:
800008dc:	00500513          	li	a0,5
800008e0:	00056593          	ori	a1,a0,0
800008e4:	20b22623          	sw	a1,524(tp) # 20c <offset+0x1a4>

800008e8 <inst_154>:
800008e8:	00500513          	li	a0,5
800008ec:	00456593          	ori	a1,a0,4
800008f0:	20b22823          	sw	a1,528(tp) # 210 <offset+0x1a8>

800008f4 <inst_155>:
800008f4:	00500513          	li	a0,5
800008f8:	33256593          	ori	a1,a0,818
800008fc:	20b22a23          	sw	a1,532(tp) # 214 <offset+0x1ac>

80000900 <inst_156>:
80000900:	00500513          	li	a0,5
80000904:	66556593          	ori	a1,a0,1637
80000908:	20b22c23          	sw	a1,536(tp) # 218 <offset+0x1b0>

8000090c <inst_157>:
8000090c:	00500513          	li	a0,5
80000910:	02c56593          	ori	a1,a0,44
80000914:	20b22e23          	sw	a1,540(tp) # 21c <offset+0x1b4>

80000918 <inst_158>:
80000918:	00500513          	li	a0,5
8000091c:	55656593          	ori	a1,a0,1366
80000920:	22b22023          	sw	a1,544(tp) # 220 <offset+0x1b8>

80000924 <inst_159>:
80000924:	00500513          	li	a0,5
80000928:	aab56593          	ori	a1,a0,-1365
8000092c:	22b22223          	sw	a1,548(tp) # 224 <offset+0x1bc>

80000930 <inst_160>:
80000930:	00500513          	li	a0,5
80000934:	00656593          	ori	a1,a0,6
80000938:	22b22423          	sw	a1,552(tp) # 228 <offset+0x1c0>

8000093c <inst_161>:
8000093c:	00500513          	li	a0,5
80000940:	33456593          	ori	a1,a0,820
80000944:	22b22623          	sw	a1,556(tp) # 22c <offset+0x1c4>

80000948 <inst_162>:
80000948:	00500513          	li	a0,5
8000094c:	66756593          	ori	a1,a0,1639
80000950:	22b22823          	sw	a1,560(tp) # 230 <offset+0x1c8>

80000954 <inst_163>:
80000954:	00500513          	li	a0,5
80000958:	fd456593          	ori	a1,a0,-44
8000095c:	22b22a23          	sw	a1,564(tp) # 234 <offset+0x1cc>

80000960 <inst_164>:
80000960:	00500513          	li	a0,5
80000964:	02e56593          	ori	a1,a0,46
80000968:	22b22c23          	sw	a1,568(tp) # 238 <offset+0x1d0>

8000096c <inst_165>:
8000096c:	33333537          	lui	a0,0x33333
80000970:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
80000974:	00356593          	ori	a1,a0,3
80000978:	22b22e23          	sw	a1,572(tp) # 23c <offset+0x1d4>

8000097c <inst_166>:
8000097c:	33333537          	lui	a0,0x33333
80000980:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
80000984:	55556593          	ori	a1,a0,1365
80000988:	24b22023          	sw	a1,576(tp) # 240 <offset+0x1d8>

8000098c <inst_167>:
8000098c:	33333537          	lui	a0,0x33333
80000990:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
80000994:	aaa56593          	ori	a1,a0,-1366
80000998:	24b22223          	sw	a1,580(tp) # 244 <offset+0x1dc>

8000099c <inst_168>:
8000099c:	33333537          	lui	a0,0x33333
800009a0:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
800009a4:	00556593          	ori	a1,a0,5
800009a8:	24b22423          	sw	a1,584(tp) # 248 <offset+0x1e0>

800009ac <inst_169>:
800009ac:	33333537          	lui	a0,0x33333
800009b0:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
800009b4:	33356593          	ori	a1,a0,819
800009b8:	24b22623          	sw	a1,588(tp) # 24c <offset+0x1e4>

800009bc <inst_170>:
800009bc:	33333537          	lui	a0,0x33333
800009c0:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
800009c4:	66656593          	ori	a1,a0,1638
800009c8:	24b22823          	sw	a1,592(tp) # 250 <offset+0x1e8>

800009cc <inst_171>:
800009cc:	33333537          	lui	a0,0x33333
800009d0:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
800009d4:	fd356593          	ori	a1,a0,-45
800009d8:	24b22a23          	sw	a1,596(tp) # 254 <offset+0x1ec>

800009dc <inst_172>:
800009dc:	33333537          	lui	a0,0x33333
800009e0:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
800009e4:	02d56593          	ori	a1,a0,45
800009e8:	24b22c23          	sw	a1,600(tp) # 258 <offset+0x1f0>

800009ec <inst_173>:
800009ec:	33333537          	lui	a0,0x33333
800009f0:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
800009f4:	00256593          	ori	a1,a0,2
800009f8:	24b22e23          	sw	a1,604(tp) # 25c <offset+0x1f4>

800009fc <inst_174>:
800009fc:	33333537          	lui	a0,0x33333
80000a00:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
80000a04:	55456593          	ori	a1,a0,1364
80000a08:	26b22023          	sw	a1,608(tp) # 260 <offset+0x1f8>

80000a0c <inst_175>:
80000a0c:	33333537          	lui	a0,0x33333
80000a10:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
80000a14:	00056593          	ori	a1,a0,0
80000a18:	26b22223          	sw	a1,612(tp) # 264 <offset+0x1fc>

80000a1c <inst_176>:
80000a1c:	33333537          	lui	a0,0x33333
80000a20:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
80000a24:	00456593          	ori	a1,a0,4
80000a28:	26b22423          	sw	a1,616(tp) # 268 <offset+0x200>

80000a2c <inst_177>:
80000a2c:	33333537          	lui	a0,0x33333
80000a30:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
80000a34:	33256593          	ori	a1,a0,818
80000a38:	26b22623          	sw	a1,620(tp) # 26c <offset+0x204>

80000a3c <inst_178>:
80000a3c:	33333537          	lui	a0,0x33333
80000a40:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
80000a44:	66556593          	ori	a1,a0,1637
80000a48:	26b22823          	sw	a1,624(tp) # 270 <offset+0x208>

80000a4c <inst_179>:
80000a4c:	33333537          	lui	a0,0x33333
80000a50:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
80000a54:	02c56593          	ori	a1,a0,44
80000a58:	26b22a23          	sw	a1,628(tp) # 274 <offset+0x20c>

80000a5c <inst_180>:
80000a5c:	33333537          	lui	a0,0x33333
80000a60:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
80000a64:	55656593          	ori	a1,a0,1366
80000a68:	26b22c23          	sw	a1,632(tp) # 278 <offset+0x210>

80000a6c <inst_181>:
80000a6c:	33333537          	lui	a0,0x33333
80000a70:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
80000a74:	aab56593          	ori	a1,a0,-1365
80000a78:	26b22e23          	sw	a1,636(tp) # 27c <offset+0x214>

80000a7c <inst_182>:
80000a7c:	33333537          	lui	a0,0x33333
80000a80:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
80000a84:	00656593          	ori	a1,a0,6
80000a88:	28b22023          	sw	a1,640(tp) # 280 <offset+0x218>

80000a8c <inst_183>:
80000a8c:	33333537          	lui	a0,0x33333
80000a90:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
80000a94:	33456593          	ori	a1,a0,820
80000a98:	28b22223          	sw	a1,644(tp) # 284 <offset+0x21c>

80000a9c <inst_184>:
80000a9c:	33333537          	lui	a0,0x33333
80000aa0:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
80000aa4:	66756593          	ori	a1,a0,1639
80000aa8:	28b22423          	sw	a1,648(tp) # 288 <offset+0x220>

80000aac <inst_185>:
80000aac:	33333537          	lui	a0,0x33333
80000ab0:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
80000ab4:	fd456593          	ori	a1,a0,-44
80000ab8:	28b22623          	sw	a1,652(tp) # 28c <offset+0x224>

80000abc <inst_186>:
80000abc:	33333537          	lui	a0,0x33333
80000ac0:	33350513          	addi	a0,a0,819 # 33333333 <absimmsh+0x332f3335>
80000ac4:	02e56593          	ori	a1,a0,46
80000ac8:	28b22823          	sw	a1,656(tp) # 290 <offset+0x228>

80000acc <inst_187>:
80000acc:	66666537          	lui	a0,0x66666
80000ad0:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000ad4:	00356593          	ori	a1,a0,3
80000ad8:	28b22a23          	sw	a1,660(tp) # 294 <offset+0x22c>

80000adc <inst_188>:
80000adc:	66666537          	lui	a0,0x66666
80000ae0:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000ae4:	55556593          	ori	a1,a0,1365
80000ae8:	28b22c23          	sw	a1,664(tp) # 298 <offset+0x230>

80000aec <inst_189>:
80000aec:	66666537          	lui	a0,0x66666
80000af0:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000af4:	aaa56593          	ori	a1,a0,-1366
80000af8:	28b22e23          	sw	a1,668(tp) # 29c <offset+0x234>

80000afc <inst_190>:
80000afc:	66666537          	lui	a0,0x66666
80000b00:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000b04:	00556593          	ori	a1,a0,5
80000b08:	2ab22023          	sw	a1,672(tp) # 2a0 <offset+0x238>

80000b0c <inst_191>:
80000b0c:	66666537          	lui	a0,0x66666
80000b10:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000b14:	33356593          	ori	a1,a0,819
80000b18:	2ab22223          	sw	a1,676(tp) # 2a4 <offset+0x23c>

80000b1c <inst_192>:
80000b1c:	66666537          	lui	a0,0x66666
80000b20:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000b24:	66656593          	ori	a1,a0,1638
80000b28:	2ab22423          	sw	a1,680(tp) # 2a8 <offset+0x240>

80000b2c <inst_193>:
80000b2c:	66666537          	lui	a0,0x66666
80000b30:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000b34:	fd356593          	ori	a1,a0,-45
80000b38:	2ab22623          	sw	a1,684(tp) # 2ac <offset+0x244>

80000b3c <inst_194>:
80000b3c:	66666537          	lui	a0,0x66666
80000b40:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000b44:	02d56593          	ori	a1,a0,45
80000b48:	2ab22823          	sw	a1,688(tp) # 2b0 <offset+0x248>

80000b4c <inst_195>:
80000b4c:	66666537          	lui	a0,0x66666
80000b50:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000b54:	00256593          	ori	a1,a0,2
80000b58:	2ab22a23          	sw	a1,692(tp) # 2b4 <offset+0x24c>

80000b5c <inst_196>:
80000b5c:	66666537          	lui	a0,0x66666
80000b60:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000b64:	55456593          	ori	a1,a0,1364
80000b68:	2ab22c23          	sw	a1,696(tp) # 2b8 <offset+0x250>

80000b6c <inst_197>:
80000b6c:	66666537          	lui	a0,0x66666
80000b70:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000b74:	00056593          	ori	a1,a0,0
80000b78:	2ab22e23          	sw	a1,700(tp) # 2bc <offset+0x254>

80000b7c <inst_198>:
80000b7c:	66666537          	lui	a0,0x66666
80000b80:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000b84:	00456593          	ori	a1,a0,4
80000b88:	2cb22023          	sw	a1,704(tp) # 2c0 <offset+0x258>

80000b8c <inst_199>:
80000b8c:	66666537          	lui	a0,0x66666
80000b90:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000b94:	33256593          	ori	a1,a0,818
80000b98:	2cb22223          	sw	a1,708(tp) # 2c4 <offset+0x25c>

80000b9c <inst_200>:
80000b9c:	66666537          	lui	a0,0x66666
80000ba0:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000ba4:	66556593          	ori	a1,a0,1637
80000ba8:	2cb22423          	sw	a1,712(tp) # 2c8 <offset+0x260>

80000bac <inst_201>:
80000bac:	66666537          	lui	a0,0x66666
80000bb0:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000bb4:	02c56593          	ori	a1,a0,44
80000bb8:	2cb22623          	sw	a1,716(tp) # 2cc <offset+0x264>

80000bbc <inst_202>:
80000bbc:	66666537          	lui	a0,0x66666
80000bc0:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000bc4:	55656593          	ori	a1,a0,1366
80000bc8:	2cb22823          	sw	a1,720(tp) # 2d0 <offset+0x268>

80000bcc <inst_203>:
80000bcc:	66666537          	lui	a0,0x66666
80000bd0:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000bd4:	aab56593          	ori	a1,a0,-1365
80000bd8:	2cb22a23          	sw	a1,724(tp) # 2d4 <offset+0x26c>

80000bdc <inst_204>:
80000bdc:	66666537          	lui	a0,0x66666
80000be0:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000be4:	00656593          	ori	a1,a0,6
80000be8:	2cb22c23          	sw	a1,728(tp) # 2d8 <offset+0x270>

80000bec <inst_205>:
80000bec:	66666537          	lui	a0,0x66666
80000bf0:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000bf4:	33456593          	ori	a1,a0,820
80000bf8:	2cb22e23          	sw	a1,732(tp) # 2dc <offset+0x274>

80000bfc <inst_206>:
80000bfc:	66666537          	lui	a0,0x66666
80000c00:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000c04:	66756593          	ori	a1,a0,1639
80000c08:	2eb22023          	sw	a1,736(tp) # 2e0 <offset+0x278>

80000c0c <inst_207>:
80000c0c:	66666537          	lui	a0,0x66666
80000c10:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000c14:	fd456593          	ori	a1,a0,-44
80000c18:	2eb22223          	sw	a1,740(tp) # 2e4 <offset+0x27c>

80000c1c <inst_208>:
80000c1c:	66666537          	lui	a0,0x66666
80000c20:	66650513          	addi	a0,a0,1638 # 66666666 <absimmsh+0x66626668>
80000c24:	02e56593          	ori	a1,a0,46
80000c28:	2eb22423          	sw	a1,744(tp) # 2e8 <offset+0x280>

80000c2c <inst_209>:
80000c2c:	ffff5537          	lui	a0,0xffff5
80000c30:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000c34:	00356593          	ori	a1,a0,3
80000c38:	2eb22623          	sw	a1,748(tp) # 2ec <offset+0x284>

80000c3c <inst_210>:
80000c3c:	ffff5537          	lui	a0,0xffff5
80000c40:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000c44:	55556593          	ori	a1,a0,1365
80000c48:	2eb22823          	sw	a1,752(tp) # 2f0 <offset+0x288>

80000c4c <inst_211>:
80000c4c:	ffff5537          	lui	a0,0xffff5
80000c50:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000c54:	00556593          	ori	a1,a0,5
80000c58:	2eb22a23          	sw	a1,756(tp) # 2f4 <offset+0x28c>

80000c5c <inst_212>:
80000c5c:	ffff5537          	lui	a0,0xffff5
80000c60:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000c64:	33356593          	ori	a1,a0,819
80000c68:	2eb22c23          	sw	a1,760(tp) # 2f8 <offset+0x290>

80000c6c <inst_213>:
80000c6c:	ffff5537          	lui	a0,0xffff5
80000c70:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000c74:	66656593          	ori	a1,a0,1638
80000c78:	2eb22e23          	sw	a1,764(tp) # 2fc <offset+0x294>

80000c7c <inst_214>:
80000c7c:	ffff5537          	lui	a0,0xffff5
80000c80:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000c84:	fd356593          	ori	a1,a0,-45
80000c88:	30b22023          	sw	a1,768(tp) # 300 <offset+0x298>

80000c8c <inst_215>:
80000c8c:	ffff5537          	lui	a0,0xffff5
80000c90:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000c94:	02d56593          	ori	a1,a0,45
80000c98:	30b22223          	sw	a1,772(tp) # 304 <offset+0x29c>

80000c9c <inst_216>:
80000c9c:	ffff5537          	lui	a0,0xffff5
80000ca0:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000ca4:	00256593          	ori	a1,a0,2
80000ca8:	30b22423          	sw	a1,776(tp) # 308 <offset+0x2a0>

80000cac <inst_217>:
80000cac:	ffff5537          	lui	a0,0xffff5
80000cb0:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000cb4:	55456593          	ori	a1,a0,1364
80000cb8:	30b22623          	sw	a1,780(tp) # 30c <offset+0x2a4>

80000cbc <inst_218>:
80000cbc:	ffff5537          	lui	a0,0xffff5
80000cc0:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000cc4:	00056593          	ori	a1,a0,0
80000cc8:	30b22823          	sw	a1,784(tp) # 310 <offset+0x2a8>

80000ccc <inst_219>:
80000ccc:	ffff5537          	lui	a0,0xffff5
80000cd0:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000cd4:	00456593          	ori	a1,a0,4
80000cd8:	30b22a23          	sw	a1,788(tp) # 314 <offset+0x2ac>

80000cdc <inst_220>:
80000cdc:	ffff5537          	lui	a0,0xffff5
80000ce0:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000ce4:	33256593          	ori	a1,a0,818
80000ce8:	30b22c23          	sw	a1,792(tp) # 318 <offset+0x2b0>

80000cec <inst_221>:
80000cec:	ffff5537          	lui	a0,0xffff5
80000cf0:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000cf4:	66556593          	ori	a1,a0,1637
80000cf8:	30b22e23          	sw	a1,796(tp) # 31c <offset+0x2b4>

80000cfc <inst_222>:
80000cfc:	ffff5537          	lui	a0,0xffff5
80000d00:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000d04:	02c56593          	ori	a1,a0,44
80000d08:	32b22023          	sw	a1,800(tp) # 320 <offset+0x2b8>

80000d0c <inst_223>:
80000d0c:	ffff5537          	lui	a0,0xffff5
80000d10:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000d14:	55656593          	ori	a1,a0,1366
80000d18:	32b22223          	sw	a1,804(tp) # 324 <offset+0x2bc>

80000d1c <inst_224>:
80000d1c:	ffff5537          	lui	a0,0xffff5
80000d20:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000d24:	aab56593          	ori	a1,a0,-1365
80000d28:	32b22423          	sw	a1,808(tp) # 328 <offset+0x2c0>

80000d2c <inst_225>:
80000d2c:	ffff5537          	lui	a0,0xffff5
80000d30:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000d34:	00656593          	ori	a1,a0,6
80000d38:	32b22623          	sw	a1,812(tp) # 32c <offset+0x2c4>

80000d3c <inst_226>:
80000d3c:	ffff5537          	lui	a0,0xffff5
80000d40:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000d44:	33456593          	ori	a1,a0,820
80000d48:	32b22823          	sw	a1,816(tp) # 330 <offset+0x2c8>

80000d4c <inst_227>:
80000d4c:	ffff5537          	lui	a0,0xffff5
80000d50:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000d54:	66756593          	ori	a1,a0,1639
80000d58:	32b22a23          	sw	a1,820(tp) # 334 <offset+0x2cc>

80000d5c <inst_228>:
80000d5c:	ffff5537          	lui	a0,0xffff5
80000d60:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000d64:	fd456593          	ori	a1,a0,-44
80000d68:	32b22c23          	sw	a1,824(tp) # 338 <offset+0x2d0>

80000d6c <inst_229>:
80000d6c:	ffff5537          	lui	a0,0xffff5
80000d70:	afc50513          	addi	a0,a0,-1284 # ffff4afc <imm12+0xffff4afd>
80000d74:	02e56593          	ori	a1,a0,46
80000d78:	32b22e23          	sw	a1,828(tp) # 33c <offset+0x2d4>

80000d7c <inst_230>:
80000d7c:	0000b537          	lui	a0,0xb
80000d80:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000d84:	00356593          	ori	a1,a0,3
80000d88:	34b22023          	sw	a1,832(tp) # 340 <offset+0x2d8>

80000d8c <inst_231>:
80000d8c:	0000b537          	lui	a0,0xb
80000d90:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000d94:	55556593          	ori	a1,a0,1365
80000d98:	34b22223          	sw	a1,836(tp) # 344 <offset+0x2dc>

80000d9c <inst_232>:
80000d9c:	0000b537          	lui	a0,0xb
80000da0:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000da4:	aaa56593          	ori	a1,a0,-1366
80000da8:	34b22423          	sw	a1,840(tp) # 348 <offset+0x2e0>

80000dac <inst_233>:
80000dac:	0000b537          	lui	a0,0xb
80000db0:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000db4:	00556593          	ori	a1,a0,5
80000db8:	34b22623          	sw	a1,844(tp) # 34c <offset+0x2e4>

80000dbc <inst_234>:
80000dbc:	0000b537          	lui	a0,0xb
80000dc0:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000dc4:	33356593          	ori	a1,a0,819
80000dc8:	34b22823          	sw	a1,848(tp) # 350 <offset+0x2e8>

80000dcc <inst_235>:
80000dcc:	0000b537          	lui	a0,0xb
80000dd0:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000dd4:	66656593          	ori	a1,a0,1638
80000dd8:	34b22a23          	sw	a1,852(tp) # 354 <offset+0x2ec>

80000ddc <inst_236>:
80000ddc:	0000b537          	lui	a0,0xb
80000de0:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000de4:	fd356593          	ori	a1,a0,-45
80000de8:	34b22c23          	sw	a1,856(tp) # 358 <offset+0x2f0>

80000dec <inst_237>:
80000dec:	0000b537          	lui	a0,0xb
80000df0:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000df4:	02d56593          	ori	a1,a0,45
80000df8:	34b22e23          	sw	a1,860(tp) # 35c <offset+0x2f4>

80000dfc <inst_238>:
80000dfc:	0000b537          	lui	a0,0xb
80000e00:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000e04:	00256593          	ori	a1,a0,2
80000e08:	36b22023          	sw	a1,864(tp) # 360 <offset+0x2f8>

80000e0c <inst_239>:
80000e0c:	0000b537          	lui	a0,0xb
80000e10:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000e14:	55456593          	ori	a1,a0,1364
80000e18:	36b22223          	sw	a1,868(tp) # 364 <offset+0x2fc>

80000e1c <inst_240>:
80000e1c:	0000b537          	lui	a0,0xb
80000e20:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000e24:	00056593          	ori	a1,a0,0
80000e28:	36b22423          	sw	a1,872(tp) # 368 <offset+0x300>

80000e2c <inst_241>:
80000e2c:	0000b537          	lui	a0,0xb
80000e30:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000e34:	00456593          	ori	a1,a0,4
80000e38:	36b22623          	sw	a1,876(tp) # 36c <offset+0x304>

80000e3c <inst_242>:
80000e3c:	0000b537          	lui	a0,0xb
80000e40:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000e44:	33256593          	ori	a1,a0,818
80000e48:	36b22823          	sw	a1,880(tp) # 370 <offset+0x308>

80000e4c <inst_243>:
80000e4c:	0000b537          	lui	a0,0xb
80000e50:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000e54:	66556593          	ori	a1,a0,1637
80000e58:	36b22a23          	sw	a1,884(tp) # 374 <offset+0x30c>

80000e5c <inst_244>:
80000e5c:	0000b537          	lui	a0,0xb
80000e60:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000e64:	02c56593          	ori	a1,a0,44
80000e68:	36b22c23          	sw	a1,888(tp) # 378 <offset+0x310>

80000e6c <inst_245>:
80000e6c:	0000b537          	lui	a0,0xb
80000e70:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000e74:	55656593          	ori	a1,a0,1366
80000e78:	36b22e23          	sw	a1,892(tp) # 37c <offset+0x314>

80000e7c <inst_246>:
80000e7c:	0000b537          	lui	a0,0xb
80000e80:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000e84:	aab56593          	ori	a1,a0,-1365
80000e88:	38b22023          	sw	a1,896(tp) # 380 <offset+0x318>

80000e8c <inst_247>:
80000e8c:	0000b537          	lui	a0,0xb
80000e90:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000e94:	00656593          	ori	a1,a0,6
80000e98:	38b22223          	sw	a1,900(tp) # 384 <offset+0x31c>

80000e9c <inst_248>:
80000e9c:	0000b537          	lui	a0,0xb
80000ea0:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000ea4:	33456593          	ori	a1,a0,820
80000ea8:	38b22423          	sw	a1,904(tp) # 388 <offset+0x320>

80000eac <inst_249>:
80000eac:	0000b537          	lui	a0,0xb
80000eb0:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000eb4:	66756593          	ori	a1,a0,1639
80000eb8:	38b22623          	sw	a1,908(tp) # 38c <offset+0x324>

80000ebc <inst_250>:
80000ebc:	0000b537          	lui	a0,0xb
80000ec0:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000ec4:	fd456593          	ori	a1,a0,-44
80000ec8:	38b22823          	sw	a1,912(tp) # 390 <offset+0x328>

80000ecc <inst_251>:
80000ecc:	0000b537          	lui	a0,0xb
80000ed0:	50450513          	addi	a0,a0,1284 # b504 <absimm+0x7504>
80000ed4:	02e56593          	ori	a1,a0,46
80000ed8:	38b22a23          	sw	a1,916(tp) # 394 <offset+0x32c>

80000edc <inst_252>:
80000edc:	00200513          	li	a0,2
80000ee0:	00356593          	ori	a1,a0,3
80000ee4:	38b22c23          	sw	a1,920(tp) # 398 <offset+0x330>

80000ee8 <inst_253>:
80000ee8:	00200513          	li	a0,2
80000eec:	55556593          	ori	a1,a0,1365
80000ef0:	38b22e23          	sw	a1,924(tp) # 39c <offset+0x334>

80000ef4 <inst_254>:
80000ef4:	00200513          	li	a0,2
80000ef8:	aaa56593          	ori	a1,a0,-1366
80000efc:	3ab22023          	sw	a1,928(tp) # 3a0 <offset+0x338>

80000f00 <inst_255>:
80000f00:	00200513          	li	a0,2
80000f04:	00556593          	ori	a1,a0,5
80000f08:	3ab22223          	sw	a1,932(tp) # 3a4 <offset+0x33c>

80000f0c <inst_256>:
80000f0c:	00200513          	li	a0,2
80000f10:	33356593          	ori	a1,a0,819
80000f14:	3ab22423          	sw	a1,936(tp) # 3a8 <offset+0x340>

80000f18 <inst_257>:
80000f18:	00200513          	li	a0,2
80000f1c:	66656593          	ori	a1,a0,1638
80000f20:	3ab22623          	sw	a1,940(tp) # 3ac <offset+0x344>

80000f24 <inst_258>:
80000f24:	00200513          	li	a0,2
80000f28:	fd356593          	ori	a1,a0,-45
80000f2c:	3ab22823          	sw	a1,944(tp) # 3b0 <offset+0x348>

80000f30 <inst_259>:
80000f30:	00200513          	li	a0,2
80000f34:	02d56593          	ori	a1,a0,45
80000f38:	3ab22a23          	sw	a1,948(tp) # 3b4 <offset+0x34c>

80000f3c <inst_260>:
80000f3c:	00200513          	li	a0,2
80000f40:	00256593          	ori	a1,a0,2
80000f44:	3ab22c23          	sw	a1,952(tp) # 3b8 <offset+0x350>

80000f48 <inst_261>:
80000f48:	00200513          	li	a0,2
80000f4c:	55456593          	ori	a1,a0,1364
80000f50:	3ab22e23          	sw	a1,956(tp) # 3bc <offset+0x354>

80000f54 <inst_262>:
80000f54:	00200513          	li	a0,2
80000f58:	00056593          	ori	a1,a0,0
80000f5c:	3cb22023          	sw	a1,960(tp) # 3c0 <offset+0x358>

80000f60 <inst_263>:
80000f60:	00200513          	li	a0,2
80000f64:	00456593          	ori	a1,a0,4
80000f68:	3cb22223          	sw	a1,964(tp) # 3c4 <offset+0x35c>

80000f6c <inst_264>:
80000f6c:	00200513          	li	a0,2
80000f70:	33256593          	ori	a1,a0,818
80000f74:	3cb22423          	sw	a1,968(tp) # 3c8 <offset+0x360>

80000f78 <inst_265>:
80000f78:	00200513          	li	a0,2
80000f7c:	66556593          	ori	a1,a0,1637
80000f80:	3cb22623          	sw	a1,972(tp) # 3cc <offset+0x364>

80000f84 <inst_266>:
80000f84:	00200513          	li	a0,2
80000f88:	02c56593          	ori	a1,a0,44
80000f8c:	3cb22823          	sw	a1,976(tp) # 3d0 <offset+0x368>

80000f90 <inst_267>:
80000f90:	00200513          	li	a0,2
80000f94:	55656593          	ori	a1,a0,1366
80000f98:	3cb22a23          	sw	a1,980(tp) # 3d4 <offset+0x36c>

80000f9c <inst_268>:
80000f9c:	00200513          	li	a0,2
80000fa0:	aab56593          	ori	a1,a0,-1365
80000fa4:	3cb22c23          	sw	a1,984(tp) # 3d8 <offset+0x370>

80000fa8 <inst_269>:
80000fa8:	00200513          	li	a0,2
80000fac:	00656593          	ori	a1,a0,6
80000fb0:	3cb22e23          	sw	a1,988(tp) # 3dc <offset+0x374>

80000fb4 <inst_270>:
80000fb4:	00200513          	li	a0,2
80000fb8:	33456593          	ori	a1,a0,820
80000fbc:	3eb22023          	sw	a1,992(tp) # 3e0 <offset+0x378>

80000fc0 <inst_271>:
80000fc0:	00200513          	li	a0,2
80000fc4:	66756593          	ori	a1,a0,1639
80000fc8:	3eb22223          	sw	a1,996(tp) # 3e4 <offset+0x37c>

80000fcc <inst_272>:
80000fcc:	00200513          	li	a0,2
80000fd0:	fd456593          	ori	a1,a0,-44
80000fd4:	3eb22423          	sw	a1,1000(tp) # 3e8 <offset+0x380>

80000fd8 <inst_273>:
80000fd8:	00200513          	li	a0,2
80000fdc:	02e56593          	ori	a1,a0,46
80000fe0:	3eb22623          	sw	a1,1004(tp) # 3ec <offset+0x384>

80000fe4 <inst_274>:
80000fe4:	55555537          	lui	a0,0x55555
80000fe8:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
80000fec:	00356593          	ori	a1,a0,3
80000ff0:	3eb22823          	sw	a1,1008(tp) # 3f0 <offset+0x388>

80000ff4 <inst_275>:
80000ff4:	55555537          	lui	a0,0x55555
80000ff8:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
80000ffc:	55556593          	ori	a1,a0,1365
80001000:	3eb22a23          	sw	a1,1012(tp) # 3f4 <offset+0x38c>

80001004 <inst_276>:
80001004:	55555537          	lui	a0,0x55555
80001008:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
8000100c:	aaa56593          	ori	a1,a0,-1366
80001010:	3eb22c23          	sw	a1,1016(tp) # 3f8 <offset+0x390>

80001014 <inst_277>:
80001014:	55555537          	lui	a0,0x55555
80001018:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
8000101c:	00556593          	ori	a1,a0,5
80001020:	3eb22e23          	sw	a1,1020(tp) # 3fc <offset+0x394>

80001024 <inst_278>:
80001024:	55555537          	lui	a0,0x55555
80001028:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
8000102c:	33356593          	ori	a1,a0,819
80001030:	40b22023          	sw	a1,1024(tp) # 400 <offset+0x398>

80001034 <inst_279>:
80001034:	55555537          	lui	a0,0x55555
80001038:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
8000103c:	66656593          	ori	a1,a0,1638
80001040:	40b22223          	sw	a1,1028(tp) # 404 <offset+0x39c>

80001044 <inst_280>:
80001044:	55555537          	lui	a0,0x55555
80001048:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
8000104c:	fd356593          	ori	a1,a0,-45
80001050:	40b22423          	sw	a1,1032(tp) # 408 <offset+0x3a0>

80001054 <inst_281>:
80001054:	55555537          	lui	a0,0x55555
80001058:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
8000105c:	02d56593          	ori	a1,a0,45
80001060:	40b22623          	sw	a1,1036(tp) # 40c <offset+0x3a4>

80001064 <inst_282>:
80001064:	55555537          	lui	a0,0x55555
80001068:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
8000106c:	00256593          	ori	a1,a0,2
80001070:	40b22823          	sw	a1,1040(tp) # 410 <offset+0x3a8>

80001074 <inst_283>:
80001074:	55555537          	lui	a0,0x55555
80001078:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
8000107c:	55456593          	ori	a1,a0,1364
80001080:	40b22a23          	sw	a1,1044(tp) # 414 <offset+0x3ac>

80001084 <inst_284>:
80001084:	55555537          	lui	a0,0x55555
80001088:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
8000108c:	00056593          	ori	a1,a0,0
80001090:	40b22c23          	sw	a1,1048(tp) # 418 <offset+0x3b0>

80001094 <inst_285>:
80001094:	55555537          	lui	a0,0x55555
80001098:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
8000109c:	00456593          	ori	a1,a0,4
800010a0:	40b22e23          	sw	a1,1052(tp) # 41c <offset+0x3b4>

800010a4 <inst_286>:
800010a4:	55555537          	lui	a0,0x55555
800010a8:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
800010ac:	33256593          	ori	a1,a0,818
800010b0:	42b22023          	sw	a1,1056(tp) # 420 <offset+0x3b8>

800010b4 <inst_287>:
800010b4:	55555537          	lui	a0,0x55555
800010b8:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
800010bc:	66556593          	ori	a1,a0,1637
800010c0:	42b22223          	sw	a1,1060(tp) # 424 <offset+0x3bc>

800010c4 <inst_288>:
800010c4:	55555537          	lui	a0,0x55555
800010c8:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
800010cc:	02c56593          	ori	a1,a0,44
800010d0:	42b22423          	sw	a1,1064(tp) # 428 <offset+0x3c0>

800010d4 <inst_289>:
800010d4:	55555537          	lui	a0,0x55555
800010d8:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
800010dc:	55656593          	ori	a1,a0,1366
800010e0:	42b22623          	sw	a1,1068(tp) # 42c <offset+0x3c4>

800010e4 <inst_290>:
800010e4:	55555537          	lui	a0,0x55555
800010e8:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
800010ec:	aab56593          	ori	a1,a0,-1365
800010f0:	42b22823          	sw	a1,1072(tp) # 430 <offset+0x3c8>

800010f4 <inst_291>:
800010f4:	55555537          	lui	a0,0x55555
800010f8:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
800010fc:	00656593          	ori	a1,a0,6
80001100:	42b22a23          	sw	a1,1076(tp) # 434 <offset+0x3cc>

80001104 <inst_292>:
80001104:	55555537          	lui	a0,0x55555
80001108:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
8000110c:	33456593          	ori	a1,a0,820
80001110:	42b22c23          	sw	a1,1080(tp) # 438 <offset+0x3d0>

80001114 <inst_293>:
80001114:	55555537          	lui	a0,0x55555
80001118:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
8000111c:	66756593          	ori	a1,a0,1639
80001120:	42b22e23          	sw	a1,1084(tp) # 43c <offset+0x3d4>

80001124 <inst_294>:
80001124:	55555537          	lui	a0,0x55555
80001128:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
8000112c:	fd456593          	ori	a1,a0,-44
80001130:	44b22023          	sw	a1,1088(tp) # 440 <offset+0x3d8>

80001134 <inst_295>:
80001134:	55555537          	lui	a0,0x55555
80001138:	55450513          	addi	a0,a0,1364 # 55555554 <absimmsh+0x55515556>
8000113c:	02e56593          	ori	a1,a0,46
80001140:	44b22223          	sw	a1,1092(tp) # 444 <offset+0x3dc>

80001144 <inst_296>:
80001144:	00000513          	li	a0,0
80001148:	00356593          	ori	a1,a0,3
8000114c:	44b22423          	sw	a1,1096(tp) # 448 <offset+0x3e0>

80001150 <inst_297>:
80001150:	00000513          	li	a0,0
80001154:	55556593          	ori	a1,a0,1365
80001158:	44b22623          	sw	a1,1100(tp) # 44c <offset+0x3e4>

8000115c <inst_298>:
8000115c:	00000513          	li	a0,0
80001160:	aaa56593          	ori	a1,a0,-1366
80001164:	44b22823          	sw	a1,1104(tp) # 450 <offset+0x3e8>

80001168 <inst_299>:
80001168:	00000513          	li	a0,0
8000116c:	00556593          	ori	a1,a0,5
80001170:	44b22a23          	sw	a1,1108(tp) # 454 <offset+0x3ec>

80001174 <inst_300>:
80001174:	00000513          	li	a0,0
80001178:	33356593          	ori	a1,a0,819
8000117c:	44b22c23          	sw	a1,1112(tp) # 458 <offset+0x3f0>

80001180 <inst_301>:
80001180:	00000513          	li	a0,0
80001184:	66656593          	ori	a1,a0,1638
80001188:	44b22e23          	sw	a1,1116(tp) # 45c <offset+0x3f4>

8000118c <inst_302>:
8000118c:	00000513          	li	a0,0
80001190:	fd356593          	ori	a1,a0,-45
80001194:	46b22023          	sw	a1,1120(tp) # 460 <offset+0x3f8>

80001198 <inst_303>:
80001198:	33333537          	lui	a0,0x33333
8000119c:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
800011a0:	33256593          	ori	a1,a0,818
800011a4:	46b22223          	sw	a1,1124(tp) # 464 <offset+0x3fc>

800011a8 <inst_304>:
800011a8:	33333537          	lui	a0,0x33333
800011ac:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
800011b0:	66556593          	ori	a1,a0,1637
800011b4:	46b22423          	sw	a1,1128(tp) # 468 <offset+0x400>

800011b8 <inst_305>:
800011b8:	33333537          	lui	a0,0x33333
800011bc:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
800011c0:	02c56593          	ori	a1,a0,44
800011c4:	46b22623          	sw	a1,1132(tp) # 46c <offset+0x404>

800011c8 <inst_306>:
800011c8:	33333537          	lui	a0,0x33333
800011cc:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
800011d0:	55656593          	ori	a1,a0,1366
800011d4:	46b22823          	sw	a1,1136(tp) # 470 <offset+0x408>

800011d8 <inst_307>:
800011d8:	33333537          	lui	a0,0x33333
800011dc:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
800011e0:	aab56593          	ori	a1,a0,-1365
800011e4:	46b22a23          	sw	a1,1140(tp) # 474 <offset+0x40c>

800011e8 <inst_308>:
800011e8:	33333537          	lui	a0,0x33333
800011ec:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
800011f0:	00656593          	ori	a1,a0,6
800011f4:	46b22c23          	sw	a1,1144(tp) # 478 <offset+0x410>

800011f8 <inst_309>:
800011f8:	33333537          	lui	a0,0x33333
800011fc:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
80001200:	33456593          	ori	a1,a0,820
80001204:	46b22e23          	sw	a1,1148(tp) # 47c <offset+0x414>

80001208 <inst_310>:
80001208:	33333537          	lui	a0,0x33333
8000120c:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
80001210:	66756593          	ori	a1,a0,1639
80001214:	48b22023          	sw	a1,1152(tp) # 480 <offset+0x418>

80001218 <inst_311>:
80001218:	33333537          	lui	a0,0x33333
8000121c:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
80001220:	fd456593          	ori	a1,a0,-44
80001224:	48b22223          	sw	a1,1156(tp) # 484 <offset+0x41c>

80001228 <inst_312>:
80001228:	33333537          	lui	a0,0x33333
8000122c:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
80001230:	02e56593          	ori	a1,a0,46
80001234:	48b22423          	sw	a1,1160(tp) # 488 <offset+0x420>

80001238 <inst_313>:
80001238:	66666537          	lui	a0,0x66666
8000123c:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
80001240:	00356593          	ori	a1,a0,3
80001244:	48b22623          	sw	a1,1164(tp) # 48c <offset+0x424>

80001248 <inst_314>:
80001248:	66666537          	lui	a0,0x66666
8000124c:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
80001250:	55556593          	ori	a1,a0,1365
80001254:	48b22823          	sw	a1,1168(tp) # 490 <offset+0x428>

80001258 <inst_315>:
80001258:	66666537          	lui	a0,0x66666
8000125c:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
80001260:	aaa56593          	ori	a1,a0,-1366
80001264:	48b22a23          	sw	a1,1172(tp) # 494 <offset+0x42c>

80001268 <inst_316>:
80001268:	66666537          	lui	a0,0x66666
8000126c:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
80001270:	00556593          	ori	a1,a0,5
80001274:	48b22c23          	sw	a1,1176(tp) # 498 <offset+0x430>

80001278 <inst_317>:
80001278:	66666537          	lui	a0,0x66666
8000127c:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
80001280:	33356593          	ori	a1,a0,819
80001284:	48b22e23          	sw	a1,1180(tp) # 49c <offset+0x434>

80001288 <inst_318>:
80001288:	66666537          	lui	a0,0x66666
8000128c:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
80001290:	66656593          	ori	a1,a0,1638
80001294:	4ab22023          	sw	a1,1184(tp) # 4a0 <offset+0x438>

80001298 <inst_319>:
80001298:	66666537          	lui	a0,0x66666
8000129c:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
800012a0:	fd356593          	ori	a1,a0,-45
800012a4:	4ab22223          	sw	a1,1188(tp) # 4a4 <offset+0x43c>

800012a8 <inst_320>:
800012a8:	66666537          	lui	a0,0x66666
800012ac:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
800012b0:	02d56593          	ori	a1,a0,45
800012b4:	4ab22423          	sw	a1,1192(tp) # 4a8 <offset+0x440>

800012b8 <inst_321>:
800012b8:	66666537          	lui	a0,0x66666
800012bc:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
800012c0:	00256593          	ori	a1,a0,2
800012c4:	4ab22623          	sw	a1,1196(tp) # 4ac <offset+0x444>

800012c8 <inst_322>:
800012c8:	66666537          	lui	a0,0x66666
800012cc:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
800012d0:	55456593          	ori	a1,a0,1364
800012d4:	4ab22823          	sw	a1,1200(tp) # 4b0 <offset+0x448>

800012d8 <inst_323>:
800012d8:	66666537          	lui	a0,0x66666
800012dc:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
800012e0:	00056593          	ori	a1,a0,0
800012e4:	4ab22a23          	sw	a1,1204(tp) # 4b4 <offset+0x44c>

800012e8 <inst_324>:
800012e8:	66666537          	lui	a0,0x66666
800012ec:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
800012f0:	00456593          	ori	a1,a0,4
800012f4:	4ab22c23          	sw	a1,1208(tp) # 4b8 <offset+0x450>

800012f8 <inst_325>:
800012f8:	66666537          	lui	a0,0x66666
800012fc:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
80001300:	33256593          	ori	a1,a0,818
80001304:	4ab22e23          	sw	a1,1212(tp) # 4bc <offset+0x454>

80001308 <inst_326>:
80001308:	66666537          	lui	a0,0x66666
8000130c:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
80001310:	66556593          	ori	a1,a0,1637
80001314:	4cb22023          	sw	a1,1216(tp) # 4c0 <offset+0x458>

80001318 <inst_327>:
80001318:	66666537          	lui	a0,0x66666
8000131c:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
80001320:	02c56593          	ori	a1,a0,44
80001324:	4cb22223          	sw	a1,1220(tp) # 4c4 <offset+0x45c>

80001328 <inst_328>:
80001328:	66666537          	lui	a0,0x66666
8000132c:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
80001330:	55656593          	ori	a1,a0,1366
80001334:	4cb22423          	sw	a1,1224(tp) # 4c8 <offset+0x460>

80001338 <inst_329>:
80001338:	66666537          	lui	a0,0x66666
8000133c:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
80001340:	aab56593          	ori	a1,a0,-1365
80001344:	4cb22623          	sw	a1,1228(tp) # 4cc <offset+0x464>

80001348 <inst_330>:
80001348:	66666537          	lui	a0,0x66666
8000134c:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
80001350:	00656593          	ori	a1,a0,6
80001354:	4cb22823          	sw	a1,1232(tp) # 4d0 <offset+0x468>

80001358 <inst_331>:
80001358:	66666537          	lui	a0,0x66666
8000135c:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
80001360:	33456593          	ori	a1,a0,820
80001364:	4cb22a23          	sw	a1,1236(tp) # 4d4 <offset+0x46c>

80001368 <inst_332>:
80001368:	66666537          	lui	a0,0x66666
8000136c:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
80001370:	66756593          	ori	a1,a0,1639
80001374:	4cb22c23          	sw	a1,1240(tp) # 4d8 <offset+0x470>

80001378 <inst_333>:
80001378:	66666537          	lui	a0,0x66666
8000137c:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
80001380:	fd456593          	ori	a1,a0,-44
80001384:	4cb22e23          	sw	a1,1244(tp) # 4dc <offset+0x474>

80001388 <inst_334>:
80001388:	66666537          	lui	a0,0x66666
8000138c:	66750513          	addi	a0,a0,1639 # 66666667 <absimmsh+0x66626669>
80001390:	02e56593          	ori	a1,a0,46
80001394:	4eb22023          	sw	a1,1248(tp) # 4e0 <offset+0x478>

80001398 <inst_335>:
80001398:	ffff5537          	lui	a0,0xffff5
8000139c:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
800013a0:	00356593          	ori	a1,a0,3
800013a4:	4eb22223          	sw	a1,1252(tp) # 4e4 <offset+0x47c>

800013a8 <inst_336>:
800013a8:	ffff5537          	lui	a0,0xffff5
800013ac:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
800013b0:	55556593          	ori	a1,a0,1365
800013b4:	4eb22423          	sw	a1,1256(tp) # 4e8 <offset+0x480>

800013b8 <inst_337>:
800013b8:	ffff5537          	lui	a0,0xffff5
800013bc:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
800013c0:	aaa56593          	ori	a1,a0,-1366
800013c4:	4eb22623          	sw	a1,1260(tp) # 4ec <offset+0x484>

800013c8 <inst_338>:
800013c8:	ffff5537          	lui	a0,0xffff5
800013cc:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
800013d0:	00556593          	ori	a1,a0,5
800013d4:	4eb22823          	sw	a1,1264(tp) # 4f0 <offset+0x488>

800013d8 <inst_339>:
800013d8:	ffff5537          	lui	a0,0xffff5
800013dc:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
800013e0:	33356593          	ori	a1,a0,819
800013e4:	4eb22a23          	sw	a1,1268(tp) # 4f4 <offset+0x48c>

800013e8 <inst_340>:
800013e8:	ffff5537          	lui	a0,0xffff5
800013ec:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
800013f0:	66656593          	ori	a1,a0,1638
800013f4:	4eb22c23          	sw	a1,1272(tp) # 4f8 <offset+0x490>

800013f8 <inst_341>:
800013f8:	ffff5537          	lui	a0,0xffff5
800013fc:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
80001400:	fd356593          	ori	a1,a0,-45
80001404:	4eb22e23          	sw	a1,1276(tp) # 4fc <offset+0x494>

80001408 <inst_342>:
80001408:	ffff5537          	lui	a0,0xffff5
8000140c:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
80001410:	02d56593          	ori	a1,a0,45
80001414:	50b22023          	sw	a1,1280(tp) # 500 <offset+0x498>

80001418 <inst_343>:
80001418:	ffff5537          	lui	a0,0xffff5
8000141c:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
80001420:	00256593          	ori	a1,a0,2
80001424:	50b22223          	sw	a1,1284(tp) # 504 <offset+0x49c>

80001428 <inst_344>:
80001428:	ffff5537          	lui	a0,0xffff5
8000142c:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
80001430:	55456593          	ori	a1,a0,1364
80001434:	50b22423          	sw	a1,1288(tp) # 508 <offset+0x4a0>

80001438 <inst_345>:
80001438:	ffff5537          	lui	a0,0xffff5
8000143c:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
80001440:	00056593          	ori	a1,a0,0
80001444:	50b22623          	sw	a1,1292(tp) # 50c <offset+0x4a4>

80001448 <inst_346>:
80001448:	ffff5537          	lui	a0,0xffff5
8000144c:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
80001450:	00456593          	ori	a1,a0,4
80001454:	50b22823          	sw	a1,1296(tp) # 510 <offset+0x4a8>

80001458 <inst_347>:
80001458:	ffff5537          	lui	a0,0xffff5
8000145c:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
80001460:	33256593          	ori	a1,a0,818
80001464:	50b22a23          	sw	a1,1300(tp) # 514 <offset+0x4ac>

80001468 <inst_348>:
80001468:	ffff5537          	lui	a0,0xffff5
8000146c:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
80001470:	66556593          	ori	a1,a0,1637
80001474:	50b22c23          	sw	a1,1304(tp) # 518 <offset+0x4b0>

80001478 <inst_349>:
80001478:	ffff5537          	lui	a0,0xffff5
8000147c:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
80001480:	02c56593          	ori	a1,a0,44
80001484:	50b22e23          	sw	a1,1308(tp) # 51c <offset+0x4b4>

80001488 <inst_350>:
80001488:	ffff5537          	lui	a0,0xffff5
8000148c:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
80001490:	55656593          	ori	a1,a0,1366
80001494:	52b22023          	sw	a1,1312(tp) # 520 <offset+0x4b8>

80001498 <inst_351>:
80001498:	ffff5537          	lui	a0,0xffff5
8000149c:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
800014a0:	aab56593          	ori	a1,a0,-1365
800014a4:	52b22223          	sw	a1,1316(tp) # 524 <offset+0x4bc>

800014a8 <inst_352>:
800014a8:	ffff5537          	lui	a0,0xffff5
800014ac:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
800014b0:	00656593          	ori	a1,a0,6
800014b4:	52b22423          	sw	a1,1320(tp) # 528 <offset+0x4c0>

800014b8 <inst_353>:
800014b8:	ffff5537          	lui	a0,0xffff5
800014bc:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
800014c0:	33456593          	ori	a1,a0,820
800014c4:	52b22623          	sw	a1,1324(tp) # 52c <offset+0x4c4>

800014c8 <inst_354>:
800014c8:	ffff5537          	lui	a0,0xffff5
800014cc:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
800014d0:	66756593          	ori	a1,a0,1639
800014d4:	52b22823          	sw	a1,1328(tp) # 530 <offset+0x4c8>

800014d8 <inst_355>:
800014d8:	ffff5537          	lui	a0,0xffff5
800014dc:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
800014e0:	fd456593          	ori	a1,a0,-44
800014e4:	52b22a23          	sw	a1,1332(tp) # 534 <offset+0x4cc>

800014e8 <inst_356>:
800014e8:	ffff5537          	lui	a0,0xffff5
800014ec:	afd50513          	addi	a0,a0,-1283 # ffff4afd <imm12+0xffff4afe>
800014f0:	02e56593          	ori	a1,a0,46
800014f4:	52b22c23          	sw	a1,1336(tp) # 538 <offset+0x4d0>

800014f8 <inst_357>:
800014f8:	0000b537          	lui	a0,0xb
800014fc:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
80001500:	00356593          	ori	a1,a0,3
80001504:	52b22e23          	sw	a1,1340(tp) # 53c <offset+0x4d4>

80001508 <inst_358>:
80001508:	0000b537          	lui	a0,0xb
8000150c:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
80001510:	55556593          	ori	a1,a0,1365
80001514:	54b22023          	sw	a1,1344(tp) # 540 <offset+0x4d8>

80001518 <inst_359>:
80001518:	0000b537          	lui	a0,0xb
8000151c:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
80001520:	aaa56593          	ori	a1,a0,-1366
80001524:	54b22223          	sw	a1,1348(tp) # 544 <offset+0x4dc>

80001528 <inst_360>:
80001528:	0000b537          	lui	a0,0xb
8000152c:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
80001530:	00556593          	ori	a1,a0,5
80001534:	54b22423          	sw	a1,1352(tp) # 548 <offset+0x4e0>

80001538 <inst_361>:
80001538:	0000b537          	lui	a0,0xb
8000153c:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
80001540:	33356593          	ori	a1,a0,819
80001544:	54b22623          	sw	a1,1356(tp) # 54c <offset+0x4e4>

80001548 <inst_362>:
80001548:	0000b537          	lui	a0,0xb
8000154c:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
80001550:	66656593          	ori	a1,a0,1638
80001554:	54b22823          	sw	a1,1360(tp) # 550 <offset+0x4e8>

80001558 <inst_363>:
80001558:	0000b537          	lui	a0,0xb
8000155c:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
80001560:	fd356593          	ori	a1,a0,-45
80001564:	54b22a23          	sw	a1,1364(tp) # 554 <offset+0x4ec>

80001568 <inst_364>:
80001568:	0000b537          	lui	a0,0xb
8000156c:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
80001570:	02d56593          	ori	a1,a0,45
80001574:	54b22c23          	sw	a1,1368(tp) # 558 <offset+0x4f0>

80001578 <inst_365>:
80001578:	0000b537          	lui	a0,0xb
8000157c:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
80001580:	00256593          	ori	a1,a0,2
80001584:	54b22e23          	sw	a1,1372(tp) # 55c <offset+0x4f4>

80001588 <inst_366>:
80001588:	0000b537          	lui	a0,0xb
8000158c:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
80001590:	55456593          	ori	a1,a0,1364
80001594:	56b22023          	sw	a1,1376(tp) # 560 <offset+0x4f8>

80001598 <inst_367>:
80001598:	0000b537          	lui	a0,0xb
8000159c:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
800015a0:	00056593          	ori	a1,a0,0
800015a4:	56b22223          	sw	a1,1380(tp) # 564 <offset+0x4fc>

800015a8 <inst_368>:
800015a8:	0000b537          	lui	a0,0xb
800015ac:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
800015b0:	00456593          	ori	a1,a0,4
800015b4:	56b22423          	sw	a1,1384(tp) # 568 <offset+0x500>

800015b8 <inst_369>:
800015b8:	0000b537          	lui	a0,0xb
800015bc:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
800015c0:	33256593          	ori	a1,a0,818
800015c4:	56b22623          	sw	a1,1388(tp) # 56c <offset+0x504>

800015c8 <inst_370>:
800015c8:	0000b537          	lui	a0,0xb
800015cc:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
800015d0:	66556593          	ori	a1,a0,1637
800015d4:	56b22823          	sw	a1,1392(tp) # 570 <offset+0x508>

800015d8 <inst_371>:
800015d8:	0000b537          	lui	a0,0xb
800015dc:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
800015e0:	02c56593          	ori	a1,a0,44
800015e4:	56b22a23          	sw	a1,1396(tp) # 574 <offset+0x50c>

800015e8 <inst_372>:
800015e8:	0000b537          	lui	a0,0xb
800015ec:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
800015f0:	55656593          	ori	a1,a0,1366
800015f4:	56b22c23          	sw	a1,1400(tp) # 578 <offset+0x510>

800015f8 <inst_373>:
800015f8:	0000b537          	lui	a0,0xb
800015fc:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
80001600:	aab56593          	ori	a1,a0,-1365
80001604:	56b22e23          	sw	a1,1404(tp) # 57c <offset+0x514>

80001608 <inst_374>:
80001608:	0000b537          	lui	a0,0xb
8000160c:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
80001610:	00656593          	ori	a1,a0,6
80001614:	58b22023          	sw	a1,1408(tp) # 580 <offset+0x518>

80001618 <inst_375>:
80001618:	0000b537          	lui	a0,0xb
8000161c:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
80001620:	33456593          	ori	a1,a0,820
80001624:	58b22223          	sw	a1,1412(tp) # 584 <offset+0x51c>

80001628 <inst_376>:
80001628:	0000b537          	lui	a0,0xb
8000162c:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
80001630:	66756593          	ori	a1,a0,1639
80001634:	58b22423          	sw	a1,1416(tp) # 588 <offset+0x520>

80001638 <inst_377>:
80001638:	0000b537          	lui	a0,0xb
8000163c:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
80001640:	fd456593          	ori	a1,a0,-44
80001644:	58b22623          	sw	a1,1420(tp) # 58c <offset+0x524>

80001648 <inst_378>:
80001648:	0000b537          	lui	a0,0xb
8000164c:	50550513          	addi	a0,a0,1285 # b505 <absimm+0x7505>
80001650:	02e56593          	ori	a1,a0,46
80001654:	58b22823          	sw	a1,1424(tp) # 590 <offset+0x528>

80001658 <inst_379>:
80001658:	00000513          	li	a0,0
8000165c:	02d56593          	ori	a1,a0,45
80001660:	58b22a23          	sw	a1,1428(tp) # 594 <offset+0x52c>

80001664 <inst_380>:
80001664:	00000513          	li	a0,0
80001668:	00256593          	ori	a1,a0,2
8000166c:	58b22c23          	sw	a1,1432(tp) # 598 <offset+0x530>

80001670 <inst_381>:
80001670:	00000513          	li	a0,0
80001674:	55456593          	ori	a1,a0,1364
80001678:	58b22e23          	sw	a1,1436(tp) # 59c <offset+0x534>

8000167c <inst_382>:
8000167c:	00000513          	li	a0,0
80001680:	00456593          	ori	a1,a0,4
80001684:	5ab22023          	sw	a1,1440(tp) # 5a0 <offset+0x538>

80001688 <inst_383>:
80001688:	00000513          	li	a0,0
8000168c:	33256593          	ori	a1,a0,818
80001690:	5ab22223          	sw	a1,1444(tp) # 5a4 <offset+0x53c>

80001694 <inst_384>:
80001694:	00000513          	li	a0,0
80001698:	66556593          	ori	a1,a0,1637
8000169c:	5ab22423          	sw	a1,1448(tp) # 5a8 <offset+0x540>

800016a0 <inst_385>:
800016a0:	00000513          	li	a0,0
800016a4:	02c56593          	ori	a1,a0,44
800016a8:	5ab22623          	sw	a1,1452(tp) # 5ac <offset+0x544>

800016ac <inst_386>:
800016ac:	00000513          	li	a0,0
800016b0:	55656593          	ori	a1,a0,1366
800016b4:	5ab22823          	sw	a1,1456(tp) # 5b0 <offset+0x548>

800016b8 <inst_387>:
800016b8:	00000513          	li	a0,0
800016bc:	aab56593          	ori	a1,a0,-1365
800016c0:	5ab22a23          	sw	a1,1460(tp) # 5b4 <offset+0x54c>

800016c4 <inst_388>:
800016c4:	00000513          	li	a0,0
800016c8:	00656593          	ori	a1,a0,6
800016cc:	5ab22c23          	sw	a1,1464(tp) # 5b8 <offset+0x550>

800016d0 <inst_389>:
800016d0:	00000513          	li	a0,0
800016d4:	33456593          	ori	a1,a0,820
800016d8:	5ab22e23          	sw	a1,1468(tp) # 5bc <offset+0x554>

800016dc <inst_390>:
800016dc:	00000513          	li	a0,0
800016e0:	66756593          	ori	a1,a0,1639
800016e4:	5cb22023          	sw	a1,1472(tp) # 5c0 <offset+0x558>

800016e8 <inst_391>:
800016e8:	00000513          	li	a0,0
800016ec:	fd456593          	ori	a1,a0,-44
800016f0:	5cb22223          	sw	a1,1476(tp) # 5c4 <offset+0x55c>

800016f4 <inst_392>:
800016f4:	00000513          	li	a0,0
800016f8:	02e56593          	ori	a1,a0,46
800016fc:	5cb22423          	sw	a1,1480(tp) # 5c8 <offset+0x560>

80001700 <inst_393>:
80001700:	00400513          	li	a0,4
80001704:	00356593          	ori	a1,a0,3
80001708:	5cb22623          	sw	a1,1484(tp) # 5cc <offset+0x564>

8000170c <inst_394>:
8000170c:	00400513          	li	a0,4
80001710:	55556593          	ori	a1,a0,1365
80001714:	5cb22823          	sw	a1,1488(tp) # 5d0 <offset+0x568>

80001718 <inst_395>:
80001718:	00400513          	li	a0,4
8000171c:	aaa56593          	ori	a1,a0,-1366
80001720:	5cb22a23          	sw	a1,1492(tp) # 5d4 <offset+0x56c>

80001724 <inst_396>:
80001724:	00400513          	li	a0,4
80001728:	33356593          	ori	a1,a0,819
8000172c:	5cb22c23          	sw	a1,1496(tp) # 5d8 <offset+0x570>

80001730 <inst_397>:
80001730:	00400513          	li	a0,4
80001734:	66656593          	ori	a1,a0,1638
80001738:	5cb22e23          	sw	a1,1500(tp) # 5dc <offset+0x574>

8000173c <inst_398>:
8000173c:	00400513          	li	a0,4
80001740:	fd356593          	ori	a1,a0,-45
80001744:	5eb22023          	sw	a1,1504(tp) # 5e0 <offset+0x578>

80001748 <inst_399>:
80001748:	00400513          	li	a0,4
8000174c:	02d56593          	ori	a1,a0,45
80001750:	5eb22223          	sw	a1,1508(tp) # 5e4 <offset+0x57c>

80001754 <inst_400>:
80001754:	00400513          	li	a0,4
80001758:	00256593          	ori	a1,a0,2
8000175c:	5eb22423          	sw	a1,1512(tp) # 5e8 <offset+0x580>

80001760 <inst_401>:
80001760:	00400513          	li	a0,4
80001764:	55456593          	ori	a1,a0,1364
80001768:	5eb22623          	sw	a1,1516(tp) # 5ec <offset+0x584>

8000176c <inst_402>:
8000176c:	00400513          	li	a0,4
80001770:	00056593          	ori	a1,a0,0
80001774:	5eb22823          	sw	a1,1520(tp) # 5f0 <offset+0x588>

80001778 <inst_403>:
80001778:	00400513          	li	a0,4
8000177c:	00456593          	ori	a1,a0,4
80001780:	5eb22a23          	sw	a1,1524(tp) # 5f4 <offset+0x58c>

80001784 <inst_404>:
80001784:	00400513          	li	a0,4
80001788:	33256593          	ori	a1,a0,818
8000178c:	5eb22c23          	sw	a1,1528(tp) # 5f8 <offset+0x590>

80001790 <inst_405>:
80001790:	00400513          	li	a0,4
80001794:	66556593          	ori	a1,a0,1637
80001798:	5eb22e23          	sw	a1,1532(tp) # 5fc <offset+0x594>

8000179c <inst_406>:
8000179c:	00400513          	li	a0,4
800017a0:	02c56593          	ori	a1,a0,44
800017a4:	60b22023          	sw	a1,1536(tp) # 600 <offset+0x598>

800017a8 <inst_407>:
800017a8:	00400513          	li	a0,4
800017ac:	55656593          	ori	a1,a0,1366
800017b0:	60b22223          	sw	a1,1540(tp) # 604 <offset+0x59c>

800017b4 <inst_408>:
800017b4:	00400513          	li	a0,4
800017b8:	aab56593          	ori	a1,a0,-1365
800017bc:	60b22423          	sw	a1,1544(tp) # 608 <offset+0x5a0>

800017c0 <inst_409>:
800017c0:	00400513          	li	a0,4
800017c4:	00656593          	ori	a1,a0,6
800017c8:	60b22623          	sw	a1,1548(tp) # 60c <offset+0x5a4>

800017cc <inst_410>:
800017cc:	00400513          	li	a0,4
800017d0:	33456593          	ori	a1,a0,820
800017d4:	60b22823          	sw	a1,1552(tp) # 610 <offset+0x5a8>

800017d8 <inst_411>:
800017d8:	00400513          	li	a0,4
800017dc:	66756593          	ori	a1,a0,1639
800017e0:	60b22a23          	sw	a1,1556(tp) # 614 <offset+0x5ac>

800017e4 <inst_412>:
800017e4:	00400513          	li	a0,4
800017e8:	fd456593          	ori	a1,a0,-44
800017ec:	60b22c23          	sw	a1,1560(tp) # 618 <offset+0x5b0>

800017f0 <inst_413>:
800017f0:	00400513          	li	a0,4
800017f4:	02e56593          	ori	a1,a0,46
800017f8:	60b22e23          	sw	a1,1564(tp) # 61c <offset+0x5b4>

800017fc <inst_414>:
800017fc:	33333537          	lui	a0,0x33333
80001800:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
80001804:	00356593          	ori	a1,a0,3
80001808:	62b22023          	sw	a1,1568(tp) # 620 <offset+0x5b8>

8000180c <inst_415>:
8000180c:	33333537          	lui	a0,0x33333
80001810:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
80001814:	55556593          	ori	a1,a0,1365
80001818:	62b22223          	sw	a1,1572(tp) # 624 <offset+0x5bc>

8000181c <inst_416>:
8000181c:	33333537          	lui	a0,0x33333
80001820:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
80001824:	aaa56593          	ori	a1,a0,-1366
80001828:	62b22423          	sw	a1,1576(tp) # 628 <offset+0x5c0>

8000182c <inst_417>:
8000182c:	33333537          	lui	a0,0x33333
80001830:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
80001834:	00556593          	ori	a1,a0,5
80001838:	62b22623          	sw	a1,1580(tp) # 62c <offset+0x5c4>

8000183c <inst_418>:
8000183c:	33333537          	lui	a0,0x33333
80001840:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
80001844:	33356593          	ori	a1,a0,819
80001848:	62b22823          	sw	a1,1584(tp) # 630 <offset+0x5c8>

8000184c <inst_419>:
8000184c:	33333537          	lui	a0,0x33333
80001850:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
80001854:	66656593          	ori	a1,a0,1638
80001858:	62b22a23          	sw	a1,1588(tp) # 634 <offset+0x5cc>

8000185c <inst_420>:
8000185c:	33333537          	lui	a0,0x33333
80001860:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
80001864:	fd356593          	ori	a1,a0,-45
80001868:	62b22c23          	sw	a1,1592(tp) # 638 <offset+0x5d0>

8000186c <inst_421>:
8000186c:	33333537          	lui	a0,0x33333
80001870:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
80001874:	02d56593          	ori	a1,a0,45
80001878:	62b22e23          	sw	a1,1596(tp) # 63c <offset+0x5d4>

8000187c <inst_422>:
8000187c:	33333537          	lui	a0,0x33333
80001880:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
80001884:	00256593          	ori	a1,a0,2
80001888:	64b22023          	sw	a1,1600(tp) # 640 <offset+0x5d8>

8000188c <inst_423>:
8000188c:	33333537          	lui	a0,0x33333
80001890:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
80001894:	55456593          	ori	a1,a0,1364
80001898:	64b22223          	sw	a1,1604(tp) # 644 <offset+0x5dc>

8000189c <inst_424>:
8000189c:	33333537          	lui	a0,0x33333
800018a0:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
800018a4:	00056593          	ori	a1,a0,0
800018a8:	64b22423          	sw	a1,1608(tp) # 648 <offset+0x5e0>

800018ac <inst_425>:
800018ac:	33333537          	lui	a0,0x33333
800018b0:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
800018b4:	00456593          	ori	a1,a0,4
800018b8:	64b22623          	sw	a1,1612(tp) # 64c <offset+0x5e4>

800018bc <inst_426>:
800018bc:	33333537          	lui	a0,0x33333
800018c0:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
800018c4:	33256593          	ori	a1,a0,818
800018c8:	64b22823          	sw	a1,1616(tp) # 650 <offset+0x5e8>

800018cc <inst_427>:
800018cc:	33333537          	lui	a0,0x33333
800018d0:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
800018d4:	66556593          	ori	a1,a0,1637
800018d8:	64b22a23          	sw	a1,1620(tp) # 654 <offset+0x5ec>

800018dc <inst_428>:
800018dc:	33333537          	lui	a0,0x33333
800018e0:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
800018e4:	02c56593          	ori	a1,a0,44
800018e8:	64b22c23          	sw	a1,1624(tp) # 658 <offset+0x5f0>

800018ec <inst_429>:
800018ec:	33333537          	lui	a0,0x33333
800018f0:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
800018f4:	55656593          	ori	a1,a0,1366
800018f8:	64b22e23          	sw	a1,1628(tp) # 65c <offset+0x5f4>

800018fc <inst_430>:
800018fc:	33333537          	lui	a0,0x33333
80001900:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
80001904:	aab56593          	ori	a1,a0,-1365
80001908:	66b22023          	sw	a1,1632(tp) # 660 <offset+0x5f8>

8000190c <inst_431>:
8000190c:	33333537          	lui	a0,0x33333
80001910:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
80001914:	00656593          	ori	a1,a0,6
80001918:	66b22223          	sw	a1,1636(tp) # 664 <offset+0x5fc>

8000191c <inst_432>:
8000191c:	33333537          	lui	a0,0x33333
80001920:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
80001924:	33456593          	ori	a1,a0,820
80001928:	66b22423          	sw	a1,1640(tp) # 668 <offset+0x600>

8000192c <inst_433>:
8000192c:	33333537          	lui	a0,0x33333
80001930:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
80001934:	66756593          	ori	a1,a0,1639
80001938:	66b22623          	sw	a1,1644(tp) # 66c <offset+0x604>

8000193c <inst_434>:
8000193c:	33333537          	lui	a0,0x33333
80001940:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
80001944:	fd456593          	ori	a1,a0,-44
80001948:	66b22823          	sw	a1,1648(tp) # 670 <offset+0x608>

8000194c <inst_435>:
8000194c:	33333537          	lui	a0,0x33333
80001950:	33250513          	addi	a0,a0,818 # 33333332 <absimmsh+0x332f3334>
80001954:	02e56593          	ori	a1,a0,46
80001958:	66b22a23          	sw	a1,1652(tp) # 674 <offset+0x60c>

8000195c <inst_436>:
8000195c:	66666537          	lui	a0,0x66666
80001960:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
80001964:	00356593          	ori	a1,a0,3
80001968:	66b22c23          	sw	a1,1656(tp) # 678 <offset+0x610>

8000196c <inst_437>:
8000196c:	66666537          	lui	a0,0x66666
80001970:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
80001974:	55556593          	ori	a1,a0,1365
80001978:	66b22e23          	sw	a1,1660(tp) # 67c <offset+0x614>

8000197c <inst_438>:
8000197c:	66666537          	lui	a0,0x66666
80001980:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
80001984:	aaa56593          	ori	a1,a0,-1366
80001988:	68b22023          	sw	a1,1664(tp) # 680 <offset+0x618>

8000198c <inst_439>:
8000198c:	66666537          	lui	a0,0x66666
80001990:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
80001994:	00556593          	ori	a1,a0,5
80001998:	68b22223          	sw	a1,1668(tp) # 684 <offset+0x61c>

8000199c <inst_440>:
8000199c:	66666537          	lui	a0,0x66666
800019a0:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
800019a4:	33356593          	ori	a1,a0,819
800019a8:	68b22423          	sw	a1,1672(tp) # 688 <offset+0x620>

800019ac <inst_441>:
800019ac:	66666537          	lui	a0,0x66666
800019b0:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
800019b4:	66656593          	ori	a1,a0,1638
800019b8:	68b22623          	sw	a1,1676(tp) # 68c <offset+0x624>

800019bc <inst_442>:
800019bc:	66666537          	lui	a0,0x66666
800019c0:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
800019c4:	fd356593          	ori	a1,a0,-45
800019c8:	68b22823          	sw	a1,1680(tp) # 690 <offset+0x628>

800019cc <inst_443>:
800019cc:	66666537          	lui	a0,0x66666
800019d0:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
800019d4:	02d56593          	ori	a1,a0,45
800019d8:	68b22a23          	sw	a1,1684(tp) # 694 <offset+0x62c>

800019dc <inst_444>:
800019dc:	66666537          	lui	a0,0x66666
800019e0:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
800019e4:	00256593          	ori	a1,a0,2
800019e8:	68b22c23          	sw	a1,1688(tp) # 698 <offset+0x630>

800019ec <inst_445>:
800019ec:	66666537          	lui	a0,0x66666
800019f0:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
800019f4:	55456593          	ori	a1,a0,1364
800019f8:	68b22e23          	sw	a1,1692(tp) # 69c <offset+0x634>

800019fc <inst_446>:
800019fc:	66666537          	lui	a0,0x66666
80001a00:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
80001a04:	00056593          	ori	a1,a0,0
80001a08:	6ab22023          	sw	a1,1696(tp) # 6a0 <offset+0x638>

80001a0c <inst_447>:
80001a0c:	66666537          	lui	a0,0x66666
80001a10:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
80001a14:	00456593          	ori	a1,a0,4
80001a18:	6ab22223          	sw	a1,1700(tp) # 6a4 <offset+0x63c>

80001a1c <inst_448>:
80001a1c:	66666537          	lui	a0,0x66666
80001a20:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
80001a24:	33256593          	ori	a1,a0,818
80001a28:	6ab22423          	sw	a1,1704(tp) # 6a8 <offset+0x640>

80001a2c <inst_449>:
80001a2c:	66666537          	lui	a0,0x66666
80001a30:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
80001a34:	66556593          	ori	a1,a0,1637
80001a38:	6ab22623          	sw	a1,1708(tp) # 6ac <offset+0x644>

80001a3c <inst_450>:
80001a3c:	66666537          	lui	a0,0x66666
80001a40:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
80001a44:	02c56593          	ori	a1,a0,44
80001a48:	6ab22823          	sw	a1,1712(tp) # 6b0 <offset+0x648>

80001a4c <inst_451>:
80001a4c:	66666537          	lui	a0,0x66666
80001a50:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
80001a54:	55656593          	ori	a1,a0,1366
80001a58:	6ab22a23          	sw	a1,1716(tp) # 6b4 <offset+0x64c>

80001a5c <inst_452>:
80001a5c:	66666537          	lui	a0,0x66666
80001a60:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
80001a64:	aab56593          	ori	a1,a0,-1365
80001a68:	6ab22c23          	sw	a1,1720(tp) # 6b8 <offset+0x650>

80001a6c <inst_453>:
80001a6c:	66666537          	lui	a0,0x66666
80001a70:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
80001a74:	00656593          	ori	a1,a0,6
80001a78:	6ab22e23          	sw	a1,1724(tp) # 6bc <offset+0x654>

80001a7c <inst_454>:
80001a7c:	66666537          	lui	a0,0x66666
80001a80:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
80001a84:	33456593          	ori	a1,a0,820
80001a88:	6cb22023          	sw	a1,1728(tp) # 6c0 <offset+0x658>

80001a8c <inst_455>:
80001a8c:	66666537          	lui	a0,0x66666
80001a90:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
80001a94:	66756593          	ori	a1,a0,1639
80001a98:	6cb22223          	sw	a1,1732(tp) # 6c4 <offset+0x65c>

80001a9c <inst_456>:
80001a9c:	66666537          	lui	a0,0x66666
80001aa0:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
80001aa4:	fd456593          	ori	a1,a0,-44
80001aa8:	6cb22423          	sw	a1,1736(tp) # 6c8 <offset+0x660>

80001aac <inst_457>:
80001aac:	66666537          	lui	a0,0x66666
80001ab0:	66550513          	addi	a0,a0,1637 # 66666665 <absimmsh+0x66626667>
80001ab4:	02e56593          	ori	a1,a0,46
80001ab8:	6cb22623          	sw	a1,1740(tp) # 6cc <offset+0x664>

80001abc <inst_458>:
80001abc:	0000b537          	lui	a0,0xb
80001ac0:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001ac4:	00356593          	ori	a1,a0,3
80001ac8:	6cb22823          	sw	a1,1744(tp) # 6d0 <offset+0x668>

80001acc <inst_459>:
80001acc:	0000b537          	lui	a0,0xb
80001ad0:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001ad4:	55556593          	ori	a1,a0,1365
80001ad8:	6cb22a23          	sw	a1,1748(tp) # 6d4 <offset+0x66c>

80001adc <inst_460>:
80001adc:	0000b537          	lui	a0,0xb
80001ae0:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001ae4:	aaa56593          	ori	a1,a0,-1366
80001ae8:	6cb22c23          	sw	a1,1752(tp) # 6d8 <offset+0x670>

80001aec <inst_461>:
80001aec:	0000b537          	lui	a0,0xb
80001af0:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001af4:	00556593          	ori	a1,a0,5
80001af8:	6cb22e23          	sw	a1,1756(tp) # 6dc <offset+0x674>

80001afc <inst_462>:
80001afc:	0000b537          	lui	a0,0xb
80001b00:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001b04:	33356593          	ori	a1,a0,819
80001b08:	6eb22023          	sw	a1,1760(tp) # 6e0 <offset+0x678>

80001b0c <inst_463>:
80001b0c:	0000b537          	lui	a0,0xb
80001b10:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001b14:	66656593          	ori	a1,a0,1638
80001b18:	6eb22223          	sw	a1,1764(tp) # 6e4 <offset+0x67c>

80001b1c <inst_464>:
80001b1c:	0000b537          	lui	a0,0xb
80001b20:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001b24:	fd356593          	ori	a1,a0,-45
80001b28:	6eb22423          	sw	a1,1768(tp) # 6e8 <offset+0x680>

80001b2c <inst_465>:
80001b2c:	0000b537          	lui	a0,0xb
80001b30:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001b34:	02d56593          	ori	a1,a0,45
80001b38:	6eb22623          	sw	a1,1772(tp) # 6ec <offset+0x684>

80001b3c <inst_466>:
80001b3c:	0000b537          	lui	a0,0xb
80001b40:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001b44:	00256593          	ori	a1,a0,2
80001b48:	6eb22823          	sw	a1,1776(tp) # 6f0 <offset+0x688>

80001b4c <inst_467>:
80001b4c:	0000b537          	lui	a0,0xb
80001b50:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001b54:	55456593          	ori	a1,a0,1364
80001b58:	6eb22a23          	sw	a1,1780(tp) # 6f4 <offset+0x68c>

80001b5c <inst_468>:
80001b5c:	0000b537          	lui	a0,0xb
80001b60:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001b64:	00056593          	ori	a1,a0,0
80001b68:	6eb22c23          	sw	a1,1784(tp) # 6f8 <offset+0x690>

80001b6c <inst_469>:
80001b6c:	0000b537          	lui	a0,0xb
80001b70:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001b74:	00456593          	ori	a1,a0,4
80001b78:	6eb22e23          	sw	a1,1788(tp) # 6fc <offset+0x694>

80001b7c <inst_470>:
80001b7c:	0000b537          	lui	a0,0xb
80001b80:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001b84:	33256593          	ori	a1,a0,818
80001b88:	70b22023          	sw	a1,1792(tp) # 700 <offset+0x698>

80001b8c <inst_471>:
80001b8c:	0000b537          	lui	a0,0xb
80001b90:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001b94:	66556593          	ori	a1,a0,1637
80001b98:	70b22223          	sw	a1,1796(tp) # 704 <offset+0x69c>

80001b9c <inst_472>:
80001b9c:	0000b537          	lui	a0,0xb
80001ba0:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001ba4:	02c56593          	ori	a1,a0,44
80001ba8:	70b22423          	sw	a1,1800(tp) # 708 <offset+0x6a0>

80001bac <inst_473>:
80001bac:	0000b537          	lui	a0,0xb
80001bb0:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001bb4:	55656593          	ori	a1,a0,1366
80001bb8:	70b22623          	sw	a1,1804(tp) # 70c <offset+0x6a4>

80001bbc <inst_474>:
80001bbc:	0000b537          	lui	a0,0xb
80001bc0:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001bc4:	aab56593          	ori	a1,a0,-1365
80001bc8:	70b22823          	sw	a1,1808(tp) # 710 <offset+0x6a8>

80001bcc <inst_475>:
80001bcc:	0000b537          	lui	a0,0xb
80001bd0:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001bd4:	00656593          	ori	a1,a0,6
80001bd8:	70b22a23          	sw	a1,1812(tp) # 714 <offset+0x6ac>

80001bdc <inst_476>:
80001bdc:	0000b537          	lui	a0,0xb
80001be0:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001be4:	33456593          	ori	a1,a0,820
80001be8:	70b22c23          	sw	a1,1816(tp) # 718 <offset+0x6b0>

80001bec <inst_477>:
80001bec:	0000b537          	lui	a0,0xb
80001bf0:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001bf4:	66756593          	ori	a1,a0,1639
80001bf8:	70b22e23          	sw	a1,1820(tp) # 71c <offset+0x6b4>

80001bfc <inst_478>:
80001bfc:	0000b537          	lui	a0,0xb
80001c00:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001c04:	fd456593          	ori	a1,a0,-44
80001c08:	72b22023          	sw	a1,1824(tp) # 720 <offset+0x6b8>

80001c0c <inst_479>:
80001c0c:	0000b537          	lui	a0,0xb
80001c10:	50350513          	addi	a0,a0,1283 # b503 <absimm+0x7503>
80001c14:	02e56593          	ori	a1,a0,46
80001c18:	72b22223          	sw	a1,1828(tp) # 724 <offset+0x6bc>

80001c1c <inst_480>:
80001c1c:	55555537          	lui	a0,0x55555
80001c20:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001c24:	00356593          	ori	a1,a0,3
80001c28:	72b22423          	sw	a1,1832(tp) # 728 <offset+0x6c0>

80001c2c <inst_481>:
80001c2c:	55555537          	lui	a0,0x55555
80001c30:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001c34:	55556593          	ori	a1,a0,1365
80001c38:	72b22623          	sw	a1,1836(tp) # 72c <offset+0x6c4>

80001c3c <inst_482>:
80001c3c:	55555537          	lui	a0,0x55555
80001c40:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001c44:	aaa56593          	ori	a1,a0,-1366
80001c48:	72b22823          	sw	a1,1840(tp) # 730 <offset+0x6c8>

80001c4c <inst_483>:
80001c4c:	55555537          	lui	a0,0x55555
80001c50:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001c54:	00556593          	ori	a1,a0,5
80001c58:	72b22a23          	sw	a1,1844(tp) # 734 <offset+0x6cc>

80001c5c <inst_484>:
80001c5c:	55555537          	lui	a0,0x55555
80001c60:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001c64:	33356593          	ori	a1,a0,819
80001c68:	72b22c23          	sw	a1,1848(tp) # 738 <offset+0x6d0>

80001c6c <inst_485>:
80001c6c:	55555537          	lui	a0,0x55555
80001c70:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001c74:	66656593          	ori	a1,a0,1638
80001c78:	72b22e23          	sw	a1,1852(tp) # 73c <offset+0x6d4>

80001c7c <inst_486>:
80001c7c:	55555537          	lui	a0,0x55555
80001c80:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001c84:	fd356593          	ori	a1,a0,-45
80001c88:	74b22023          	sw	a1,1856(tp) # 740 <offset+0x6d8>

80001c8c <inst_487>:
80001c8c:	55555537          	lui	a0,0x55555
80001c90:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001c94:	02d56593          	ori	a1,a0,45
80001c98:	74b22223          	sw	a1,1860(tp) # 744 <offset+0x6dc>

80001c9c <inst_488>:
80001c9c:	55555537          	lui	a0,0x55555
80001ca0:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001ca4:	00256593          	ori	a1,a0,2
80001ca8:	74b22423          	sw	a1,1864(tp) # 748 <offset+0x6e0>

80001cac <inst_489>:
80001cac:	55555537          	lui	a0,0x55555
80001cb0:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001cb4:	55456593          	ori	a1,a0,1364
80001cb8:	74b22623          	sw	a1,1868(tp) # 74c <offset+0x6e4>

80001cbc <inst_490>:
80001cbc:	55555537          	lui	a0,0x55555
80001cc0:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001cc4:	00056593          	ori	a1,a0,0
80001cc8:	74b22823          	sw	a1,1872(tp) # 750 <offset+0x6e8>

80001ccc <inst_491>:
80001ccc:	55555537          	lui	a0,0x55555
80001cd0:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001cd4:	00456593          	ori	a1,a0,4
80001cd8:	74b22a23          	sw	a1,1876(tp) # 754 <offset+0x6ec>

80001cdc <inst_492>:
80001cdc:	55555537          	lui	a0,0x55555
80001ce0:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001ce4:	33256593          	ori	a1,a0,818
80001ce8:	74b22c23          	sw	a1,1880(tp) # 758 <offset+0x6f0>

80001cec <inst_493>:
80001cec:	55555537          	lui	a0,0x55555
80001cf0:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001cf4:	66556593          	ori	a1,a0,1637
80001cf8:	74b22e23          	sw	a1,1884(tp) # 75c <offset+0x6f4>

80001cfc <inst_494>:
80001cfc:	55555537          	lui	a0,0x55555
80001d00:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001d04:	02c56593          	ori	a1,a0,44
80001d08:	76b22023          	sw	a1,1888(tp) # 760 <offset+0x6f8>

80001d0c <inst_495>:
80001d0c:	55555537          	lui	a0,0x55555
80001d10:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001d14:	55656593          	ori	a1,a0,1366
80001d18:	76b22223          	sw	a1,1892(tp) # 764 <offset+0x6fc>

80001d1c <inst_496>:
80001d1c:	55555537          	lui	a0,0x55555
80001d20:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001d24:	aab56593          	ori	a1,a0,-1365
80001d28:	76b22423          	sw	a1,1896(tp) # 768 <offset+0x700>

80001d2c <inst_497>:
80001d2c:	55555537          	lui	a0,0x55555
80001d30:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001d34:	00656593          	ori	a1,a0,6
80001d38:	76b22623          	sw	a1,1900(tp) # 76c <offset+0x704>

80001d3c <inst_498>:
80001d3c:	55555537          	lui	a0,0x55555
80001d40:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001d44:	33456593          	ori	a1,a0,820
80001d48:	76b22823          	sw	a1,1904(tp) # 770 <offset+0x708>

80001d4c <inst_499>:
80001d4c:	55555537          	lui	a0,0x55555
80001d50:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001d54:	66756593          	ori	a1,a0,1639
80001d58:	76b22a23          	sw	a1,1908(tp) # 774 <offset+0x70c>

80001d5c <inst_500>:
80001d5c:	55555537          	lui	a0,0x55555
80001d60:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001d64:	fd456593          	ori	a1,a0,-44
80001d68:	76b22c23          	sw	a1,1912(tp) # 778 <offset+0x710>

80001d6c <inst_501>:
80001d6c:	55555537          	lui	a0,0x55555
80001d70:	55650513          	addi	a0,a0,1366 # 55555556 <absimmsh+0x55515558>
80001d74:	02e56593          	ori	a1,a0,46
80001d78:	76b22e23          	sw	a1,1916(tp) # 77c <offset+0x714>

80001d7c <inst_502>:
80001d7c:	aaaab537          	lui	a0,0xaaaab
80001d80:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001d84:	00356593          	ori	a1,a0,3
80001d88:	78b22023          	sw	a1,1920(tp) # 780 <offset+0x718>

80001d8c <inst_503>:
80001d8c:	aaaab537          	lui	a0,0xaaaab
80001d90:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001d94:	55556593          	ori	a1,a0,1365
80001d98:	78b22223          	sw	a1,1924(tp) # 784 <offset+0x71c>

80001d9c <inst_504>:
80001d9c:	aaaab537          	lui	a0,0xaaaab
80001da0:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001da4:	aaa56593          	ori	a1,a0,-1366
80001da8:	78b22423          	sw	a1,1928(tp) # 788 <offset+0x720>

80001dac <inst_505>:
80001dac:	aaaab537          	lui	a0,0xaaaab
80001db0:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001db4:	00556593          	ori	a1,a0,5
80001db8:	78b22623          	sw	a1,1932(tp) # 78c <offset+0x724>

80001dbc <inst_506>:
80001dbc:	aaaab537          	lui	a0,0xaaaab
80001dc0:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001dc4:	33356593          	ori	a1,a0,819
80001dc8:	78b22823          	sw	a1,1936(tp) # 790 <offset+0x728>

80001dcc <inst_507>:
80001dcc:	aaaab537          	lui	a0,0xaaaab
80001dd0:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001dd4:	66656593          	ori	a1,a0,1638
80001dd8:	78b22a23          	sw	a1,1940(tp) # 794 <offset+0x72c>

80001ddc <inst_508>:
80001ddc:	aaaab537          	lui	a0,0xaaaab
80001de0:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001de4:	fd356593          	ori	a1,a0,-45
80001de8:	78b22c23          	sw	a1,1944(tp) # 798 <offset+0x730>

80001dec <inst_509>:
80001dec:	aaaab537          	lui	a0,0xaaaab
80001df0:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001df4:	02d56593          	ori	a1,a0,45
80001df8:	78b22e23          	sw	a1,1948(tp) # 79c <offset+0x734>

80001dfc <inst_510>:
80001dfc:	aaaab537          	lui	a0,0xaaaab
80001e00:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001e04:	00256593          	ori	a1,a0,2
80001e08:	7ab22023          	sw	a1,1952(tp) # 7a0 <offset+0x738>

80001e0c <inst_511>:
80001e0c:	aaaab537          	lui	a0,0xaaaab
80001e10:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001e14:	55456593          	ori	a1,a0,1364
80001e18:	7ab22223          	sw	a1,1956(tp) # 7a4 <offset+0x73c>

80001e1c <inst_512>:
80001e1c:	aaaab537          	lui	a0,0xaaaab
80001e20:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001e24:	00056593          	ori	a1,a0,0
80001e28:	7ab22423          	sw	a1,1960(tp) # 7a8 <offset+0x740>

80001e2c <inst_513>:
80001e2c:	aaaab537          	lui	a0,0xaaaab
80001e30:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001e34:	00456593          	ori	a1,a0,4
80001e38:	7ab22623          	sw	a1,1964(tp) # 7ac <offset+0x744>

80001e3c <inst_514>:
80001e3c:	aaaab537          	lui	a0,0xaaaab
80001e40:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001e44:	33256593          	ori	a1,a0,818
80001e48:	7ab22823          	sw	a1,1968(tp) # 7b0 <offset+0x748>

80001e4c <inst_515>:
80001e4c:	aaaab537          	lui	a0,0xaaaab
80001e50:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001e54:	66556593          	ori	a1,a0,1637
80001e58:	7ab22a23          	sw	a1,1972(tp) # 7b4 <offset+0x74c>

80001e5c <inst_516>:
80001e5c:	aaaab537          	lui	a0,0xaaaab
80001e60:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001e64:	02c56593          	ori	a1,a0,44
80001e68:	7ab22c23          	sw	a1,1976(tp) # 7b8 <offset+0x750>

80001e6c <inst_517>:
80001e6c:	aaaab537          	lui	a0,0xaaaab
80001e70:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001e74:	55656593          	ori	a1,a0,1366
80001e78:	7ab22e23          	sw	a1,1980(tp) # 7bc <offset+0x754>

80001e7c <inst_518>:
80001e7c:	aaaab537          	lui	a0,0xaaaab
80001e80:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001e84:	aab56593          	ori	a1,a0,-1365
80001e88:	7cb22023          	sw	a1,1984(tp) # 7c0 <offset+0x758>

80001e8c <inst_519>:
80001e8c:	aaaab537          	lui	a0,0xaaaab
80001e90:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001e94:	00656593          	ori	a1,a0,6
80001e98:	7cb22223          	sw	a1,1988(tp) # 7c4 <offset+0x75c>

80001e9c <inst_520>:
80001e9c:	aaaab537          	lui	a0,0xaaaab
80001ea0:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001ea4:	33456593          	ori	a1,a0,820
80001ea8:	7cb22423          	sw	a1,1992(tp) # 7c8 <offset+0x760>

80001eac <inst_521>:
80001eac:	aaaab537          	lui	a0,0xaaaab
80001eb0:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001eb4:	66756593          	ori	a1,a0,1639
80001eb8:	7cb22623          	sw	a1,1996(tp) # 7cc <offset+0x764>

80001ebc <inst_522>:
80001ebc:	aaaab537          	lui	a0,0xaaaab
80001ec0:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001ec4:	fd456593          	ori	a1,a0,-44
80001ec8:	7cb22823          	sw	a1,2000(tp) # 7d0 <offset+0x768>

80001ecc <inst_523>:
80001ecc:	aaaab537          	lui	a0,0xaaaab
80001ed0:	aab50513          	addi	a0,a0,-1365 # aaaaaaab <imm12+0xaaaaaaac>
80001ed4:	02e56593          	ori	a1,a0,46
80001ed8:	7cb22a23          	sw	a1,2004(tp) # 7d4 <offset+0x76c>

80001edc <inst_524>:
80001edc:	00600513          	li	a0,6
80001ee0:	00356593          	ori	a1,a0,3
80001ee4:	7cb22c23          	sw	a1,2008(tp) # 7d8 <offset+0x770>

80001ee8 <inst_525>:
80001ee8:	00600513          	li	a0,6
80001eec:	55556593          	ori	a1,a0,1365
80001ef0:	7cb22e23          	sw	a1,2012(tp) # 7dc <offset+0x774>

80001ef4 <inst_526>:
80001ef4:	00600513          	li	a0,6
80001ef8:	aaa56593          	ori	a1,a0,-1366
80001efc:	7eb22023          	sw	a1,2016(tp) # 7e0 <offset+0x778>

80001f00 <inst_527>:
80001f00:	00600513          	li	a0,6
80001f04:	00556593          	ori	a1,a0,5
80001f08:	7eb22223          	sw	a1,2020(tp) # 7e4 <offset+0x77c>

80001f0c <inst_528>:
80001f0c:	00600513          	li	a0,6
80001f10:	33356593          	ori	a1,a0,819
80001f14:	7eb22423          	sw	a1,2024(tp) # 7e8 <offset+0x780>

80001f18 <inst_529>:
80001f18:	00600513          	li	a0,6
80001f1c:	66656593          	ori	a1,a0,1638
80001f20:	7eb22623          	sw	a1,2028(tp) # 7ec <offset+0x784>

80001f24 <inst_530>:
80001f24:	00600513          	li	a0,6
80001f28:	fd356593          	ori	a1,a0,-45
80001f2c:	7eb22823          	sw	a1,2032(tp) # 7f0 <offset+0x788>

80001f30 <inst_531>:
80001f30:	00600513          	li	a0,6
80001f34:	02d56593          	ori	a1,a0,45
80001f38:	7eb22a23          	sw	a1,2036(tp) # 7f4 <offset+0x78c>

80001f3c <inst_532>:
80001f3c:	00600513          	li	a0,6
80001f40:	00256593          	ori	a1,a0,2
80001f44:	7eb22c23          	sw	a1,2040(tp) # 7f8 <offset+0x790>

80001f48 <inst_533>:
80001f48:	00600513          	li	a0,6
80001f4c:	55456593          	ori	a1,a0,1364
80001f50:	7eb22e23          	sw	a1,2044(tp) # 7fc <offset+0x794>
80001f54:	00004217          	auipc	tp,0x4
80001f58:	a1820213          	addi	tp,tp,-1512 # 8000596c <signature_x4_1>

80001f5c <inst_534>:
80001f5c:	00600513          	li	a0,6
80001f60:	00056593          	ori	a1,a0,0
80001f64:	00b22023          	sw	a1,0(tp) # 0 <cryh>

80001f68 <inst_535>:
80001f68:	00600513          	li	a0,6
80001f6c:	00456593          	ori	a1,a0,4
80001f70:	00b22223          	sw	a1,4(tp) # 4 <MMODE_SIG+0x1>

80001f74 <inst_536>:
80001f74:	00600513          	li	a0,6
80001f78:	33256593          	ori	a1,a0,818
80001f7c:	00b22423          	sw	a1,8(tp) # 8 <MMODE_SIG+0x5>

80001f80 <inst_537>:
80001f80:	00600513          	li	a0,6
80001f84:	66556593          	ori	a1,a0,1637
80001f88:	00b22623          	sw	a1,12(tp) # c <MMODE_SIG+0x9>

80001f8c <inst_538>:
80001f8c:	00600513          	li	a0,6
80001f90:	02c56593          	ori	a1,a0,44
80001f94:	00b22823          	sw	a1,16(tp) # 10 <edge2+0x1>

80001f98 <inst_539>:
80001f98:	00600513          	li	a0,6
80001f9c:	55656593          	ori	a1,a0,1366
80001fa0:	00b22a23          	sw	a1,20(tp) # 14 <edge2+0x5>

80001fa4 <inst_540>:
80001fa4:	00600513          	li	a0,6
80001fa8:	aab56593          	ori	a1,a0,-1365
80001fac:	00b22c23          	sw	a1,24(tp) # 18 <edge2+0x9>

80001fb0 <inst_541>:
80001fb0:	00600513          	li	a0,6
80001fb4:	00656593          	ori	a1,a0,6
80001fb8:	00b22e23          	sw	a1,28(tp) # 1c <edge2+0xd>

80001fbc <inst_542>:
80001fbc:	00600513          	li	a0,6
80001fc0:	33456593          	ori	a1,a0,820
80001fc4:	02b22023          	sw	a1,32(tp) # 20 <pos>

80001fc8 <inst_543>:
80001fc8:	00600513          	li	a0,6
80001fcc:	66756593          	ori	a1,a0,1639
80001fd0:	02b22223          	sw	a1,36(tp) # 24 <pos+0x4>

80001fd4 <inst_544>:
80001fd4:	00600513          	li	a0,6
80001fd8:	fd456593          	ori	a1,a0,-44
80001fdc:	02b22423          	sw	a1,40(tp) # 28 <pos+0x8>

80001fe0 <inst_545>:
80001fe0:	00600513          	li	a0,6
80001fe4:	02e56593          	ori	a1,a0,46
80001fe8:	02b22623          	sw	a1,44(tp) # 2c <pos+0xc>

80001fec <inst_546>:
80001fec:	33333537          	lui	a0,0x33333
80001ff0:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
80001ff4:	00356593          	ori	a1,a0,3
80001ff8:	02b22823          	sw	a1,48(tp) # 30 <pos+0x10>

80001ffc <inst_547>:
80001ffc:	33333537          	lui	a0,0x33333
80002000:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
80002004:	55556593          	ori	a1,a0,1365
80002008:	02b22a23          	sw	a1,52(tp) # 34 <pos+0x14>

8000200c <inst_548>:
8000200c:	33333537          	lui	a0,0x33333
80002010:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
80002014:	aaa56593          	ori	a1,a0,-1366
80002018:	02b22c23          	sw	a1,56(tp) # 38 <pos+0x18>

8000201c <inst_549>:
8000201c:	33333537          	lui	a0,0x33333
80002020:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
80002024:	00556593          	ori	a1,a0,5
80002028:	02b22e23          	sw	a1,60(tp) # 3c <pos+0x1c>

8000202c <inst_550>:
8000202c:	33333537          	lui	a0,0x33333
80002030:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
80002034:	33356593          	ori	a1,a0,819
80002038:	04b22023          	sw	a1,64(tp) # 40 <pos+0x20>

8000203c <inst_551>:
8000203c:	33333537          	lui	a0,0x33333
80002040:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
80002044:	66656593          	ori	a1,a0,1638
80002048:	04b22223          	sw	a1,68(tp) # 44 <pos+0x24>

8000204c <inst_552>:
8000204c:	33333537          	lui	a0,0x33333
80002050:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
80002054:	fd356593          	ori	a1,a0,-45
80002058:	04b22423          	sw	a1,72(tp) # 48 <pos+0x28>

8000205c <inst_553>:
8000205c:	33333537          	lui	a0,0x33333
80002060:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
80002064:	02d56593          	ori	a1,a0,45
80002068:	04b22623          	sw	a1,76(tp) # 4c <pos+0x2c>

8000206c <inst_554>:
8000206c:	33333537          	lui	a0,0x33333
80002070:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
80002074:	00256593          	ori	a1,a0,2
80002078:	04b22823          	sw	a1,80(tp) # 50 <pos+0x30>

8000207c <inst_555>:
8000207c:	33333537          	lui	a0,0x33333
80002080:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
80002084:	55456593          	ori	a1,a0,1364
80002088:	04b22a23          	sw	a1,84(tp) # 54 <pos+0x34>

8000208c <inst_556>:
8000208c:	33333537          	lui	a0,0x33333
80002090:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
80002094:	00056593          	ori	a1,a0,0
80002098:	04b22c23          	sw	a1,88(tp) # 58 <pos+0x38>

8000209c <inst_557>:
8000209c:	33333537          	lui	a0,0x33333
800020a0:	33450513          	addi	a0,a0,820 # 33333334 <absimmsh+0x332f3336>
800020a4:	00456593          	ori	a1,a0,4
800020a8:	04b22e23          	sw	a1,92(tp) # 5c <pos+0x3c>

800020ac <inst_558>:
800020ac:	c0000537          	lui	a0,0xc0000
800020b0:	fff50513          	addi	a0,a0,-1 # bfffffff <imm12+0xc0000000>
800020b4:	40056593          	ori	a1,a0,1024
800020b8:	06b22023          	sw	a1,96(tp) # 60 <pos+0x40>

800020bc <inst_559>:
800020bc:	ffffc537          	lui	a0,0xffffc
800020c0:	fff50513          	addi	a0,a0,-1 # ffffbfff <imm12+0xffffc000>
800020c4:	fef56593          	ori	a1,a0,-17
800020c8:	06b22223          	sw	a1,100(tp) # 64 <pos+0x44>

800020cc <cleanup_epilogs>:
800020cc:	0040006f          	j	800020d0 <exit_cleanup>

800020d0 <exit_cleanup>:
800020d0:	00100093          	li	ra,1

800020d4 <write_tohost>:
800020d4:	00001f17          	auipc	t5,0x1
800020d8:	f21f2623          	sw	ra,-212(t5) # 80003000 <tohost>
800020dc:	ff9ff06f          	j	800020d4 <write_tohost>
800020e0:	0000                	unimp
	...

Disassembly of section .tohost:

80003000 <tohost>:
	...

80003100 <fromhost>:
	...

Disassembly of section .data:

80004000 <rvtest_trap_sig>:
80004000:	4020                	lw	s0,64(s0)
80004002:	8000                	0x8000
	...

80004010 <rvtest_data_begin>:
80004010:	cafe                	sw	t6,84(sp)
80004012:	babe                	fsd	fa5,368(sp)
80004014:	cafe                	sw	t6,84(sp)
80004016:	babe                	fsd	fa5,368(sp)
80004018:	cafe                	sw	t6,84(sp)
8000401a:	babe                	fsd	fa5,368(sp)
8000401c:	cafe                	sw	t6,84(sp)
8000401e:	babe                	fsd	fa5,368(sp)

80004020 <mtrap_sigptr>:
80004020:	deadbeef          	jal	t4,7ffdf60a <absimmsh+0x7ff9f60c>
80004024:	deadbeef          	jal	t4,7ffdf60e <absimmsh+0x7ff9f610>

80004028 <rvtest_data_end>:
	...

80005000 <begin_regstate>:
80005000:	0080                	addi	s0,sp,64
	...

80005100 <end_regstate>:
80005100:	0004                	0x4
	...

80005110 <begin_signature>:
80005110:	a309                	j	80005612 <signature_x4_0+0x4a6>
80005112:	6f5c                	flw	fa5,28(a4)

80005114 <signature_x2_0>:
80005114:	deadbeef          	jal	t4,7ffe06fe <absimmsh+0x7ffa0700>
80005118:	deadbeef          	jal	t4,7ffe0702 <absimmsh+0x7ffa0704>
8000511c:	deadbeef          	jal	t4,7ffe0706 <absimmsh+0x7ffa0708>
80005120:	deadbeef          	jal	t4,7ffe070a <absimmsh+0x7ffa070c>
80005124:	deadbeef          	jal	t4,7ffe070e <absimmsh+0x7ffa0710>
80005128:	deadbeef          	jal	t4,7ffe0712 <absimmsh+0x7ffa0714>
8000512c:	deadbeef          	jal	t4,7ffe0716 <absimmsh+0x7ffa0718>
80005130:	deadbeef          	jal	t4,7ffe071a <absimmsh+0x7ffa071c>
80005134:	deadbeef          	jal	t4,7ffe071e <absimmsh+0x7ffa0720>
80005138:	deadbeef          	jal	t4,7ffe0722 <absimmsh+0x7ffa0724>
8000513c:	deadbeef          	jal	t4,7ffe0726 <absimmsh+0x7ffa0728>
80005140:	deadbeef          	jal	t4,7ffe072a <absimmsh+0x7ffa072c>
80005144:	deadbeef          	jal	t4,7ffe072e <absimmsh+0x7ffa0730>
80005148:	deadbeef          	jal	t4,7ffe0732 <absimmsh+0x7ffa0734>
8000514c:	deadbeef          	jal	t4,7ffe0736 <absimmsh+0x7ffa0738>
80005150:	deadbeef          	jal	t4,7ffe073a <absimmsh+0x7ffa073c>
80005154:	deadbeef          	jal	t4,7ffe073e <absimmsh+0x7ffa0740>
80005158:	deadbeef          	jal	t4,7ffe0742 <absimmsh+0x7ffa0744>
8000515c:	deadbeef          	jal	t4,7ffe0746 <absimmsh+0x7ffa0748>
80005160:	deadbeef          	jal	t4,7ffe074a <absimmsh+0x7ffa074c>
80005164:	deadbeef          	jal	t4,7ffe074e <absimmsh+0x7ffa0750>
80005168:	deadbeef          	jal	t4,7ffe0752 <absimmsh+0x7ffa0754>

8000516c <signature_x4_0>:
8000516c:	deadbeef          	jal	t4,7ffe0756 <absimmsh+0x7ffa0758>
80005170:	deadbeef          	jal	t4,7ffe075a <absimmsh+0x7ffa075c>
80005174:	deadbeef          	jal	t4,7ffe075e <absimmsh+0x7ffa0760>
80005178:	deadbeef          	jal	t4,7ffe0762 <absimmsh+0x7ffa0764>
8000517c:	deadbeef          	jal	t4,7ffe0766 <absimmsh+0x7ffa0768>
80005180:	deadbeef          	jal	t4,7ffe076a <absimmsh+0x7ffa076c>
80005184:	deadbeef          	jal	t4,7ffe076e <absimmsh+0x7ffa0770>
80005188:	deadbeef          	jal	t4,7ffe0772 <absimmsh+0x7ffa0774>
8000518c:	deadbeef          	jal	t4,7ffe0776 <absimmsh+0x7ffa0778>
80005190:	deadbeef          	jal	t4,7ffe077a <absimmsh+0x7ffa077c>
80005194:	deadbeef          	jal	t4,7ffe077e <absimmsh+0x7ffa0780>
80005198:	deadbeef          	jal	t4,7ffe0782 <absimmsh+0x7ffa0784>
8000519c:	deadbeef          	jal	t4,7ffe0786 <absimmsh+0x7ffa0788>
800051a0:	deadbeef          	jal	t4,7ffe078a <absimmsh+0x7ffa078c>
800051a4:	deadbeef          	jal	t4,7ffe078e <absimmsh+0x7ffa0790>
800051a8:	deadbeef          	jal	t4,7ffe0792 <absimmsh+0x7ffa0794>
800051ac:	deadbeef          	jal	t4,7ffe0796 <absimmsh+0x7ffa0798>
800051b0:	deadbeef          	jal	t4,7ffe079a <absimmsh+0x7ffa079c>
800051b4:	deadbeef          	jal	t4,7ffe079e <absimmsh+0x7ffa07a0>
800051b8:	deadbeef          	jal	t4,7ffe07a2 <absimmsh+0x7ffa07a4>
800051bc:	deadbeef          	jal	t4,7ffe07a6 <absimmsh+0x7ffa07a8>
800051c0:	deadbeef          	jal	t4,7ffe07aa <absimmsh+0x7ffa07ac>
800051c4:	deadbeef          	jal	t4,7ffe07ae <absimmsh+0x7ffa07b0>
800051c8:	deadbeef          	jal	t4,7ffe07b2 <absimmsh+0x7ffa07b4>
800051cc:	deadbeef          	jal	t4,7ffe07b6 <absimmsh+0x7ffa07b8>
800051d0:	deadbeef          	jal	t4,7ffe07ba <absimmsh+0x7ffa07bc>
800051d4:	deadbeef          	jal	t4,7ffe07be <absimmsh+0x7ffa07c0>
800051d8:	deadbeef          	jal	t4,7ffe07c2 <absimmsh+0x7ffa07c4>
800051dc:	deadbeef          	jal	t4,7ffe07c6 <absimmsh+0x7ffa07c8>
800051e0:	deadbeef          	jal	t4,7ffe07ca <absimmsh+0x7ffa07cc>
800051e4:	deadbeef          	jal	t4,7ffe07ce <absimmsh+0x7ffa07d0>
800051e8:	deadbeef          	jal	t4,7ffe07d2 <absimmsh+0x7ffa07d4>
800051ec:	deadbeef          	jal	t4,7ffe07d6 <absimmsh+0x7ffa07d8>
800051f0:	deadbeef          	jal	t4,7ffe07da <absimmsh+0x7ffa07dc>
800051f4:	deadbeef          	jal	t4,7ffe07de <absimmsh+0x7ffa07e0>
800051f8:	deadbeef          	jal	t4,7ffe07e2 <absimmsh+0x7ffa07e4>
800051fc:	deadbeef          	jal	t4,7ffe07e6 <absimmsh+0x7ffa07e8>
80005200:	deadbeef          	jal	t4,7ffe07ea <absimmsh+0x7ffa07ec>
80005204:	deadbeef          	jal	t4,7ffe07ee <absimmsh+0x7ffa07f0>
80005208:	deadbeef          	jal	t4,7ffe07f2 <absimmsh+0x7ffa07f4>
8000520c:	deadbeef          	jal	t4,7ffe07f6 <absimmsh+0x7ffa07f8>
80005210:	deadbeef          	jal	t4,7ffe07fa <absimmsh+0x7ffa07fc>
80005214:	deadbeef          	jal	t4,7ffe07fe <absimmsh+0x7ffa0800>
80005218:	deadbeef          	jal	t4,7ffe0802 <absimmsh+0x7ffa0804>
8000521c:	deadbeef          	jal	t4,7ffe0806 <absimmsh+0x7ffa0808>
80005220:	deadbeef          	jal	t4,7ffe080a <absimmsh+0x7ffa080c>
80005224:	deadbeef          	jal	t4,7ffe080e <absimmsh+0x7ffa0810>
80005228:	deadbeef          	jal	t4,7ffe0812 <absimmsh+0x7ffa0814>
8000522c:	deadbeef          	jal	t4,7ffe0816 <absimmsh+0x7ffa0818>
80005230:	deadbeef          	jal	t4,7ffe081a <absimmsh+0x7ffa081c>
80005234:	deadbeef          	jal	t4,7ffe081e <absimmsh+0x7ffa0820>
80005238:	deadbeef          	jal	t4,7ffe0822 <absimmsh+0x7ffa0824>
8000523c:	deadbeef          	jal	t4,7ffe0826 <absimmsh+0x7ffa0828>
80005240:	deadbeef          	jal	t4,7ffe082a <absimmsh+0x7ffa082c>
80005244:	deadbeef          	jal	t4,7ffe082e <absimmsh+0x7ffa0830>
80005248:	deadbeef          	jal	t4,7ffe0832 <absimmsh+0x7ffa0834>
8000524c:	deadbeef          	jal	t4,7ffe0836 <absimmsh+0x7ffa0838>
80005250:	deadbeef          	jal	t4,7ffe083a <absimmsh+0x7ffa083c>
80005254:	deadbeef          	jal	t4,7ffe083e <absimmsh+0x7ffa0840>
80005258:	deadbeef          	jal	t4,7ffe0842 <absimmsh+0x7ffa0844>
8000525c:	deadbeef          	jal	t4,7ffe0846 <absimmsh+0x7ffa0848>
80005260:	deadbeef          	jal	t4,7ffe084a <absimmsh+0x7ffa084c>
80005264:	deadbeef          	jal	t4,7ffe084e <absimmsh+0x7ffa0850>
80005268:	deadbeef          	jal	t4,7ffe0852 <absimmsh+0x7ffa0854>
8000526c:	deadbeef          	jal	t4,7ffe0856 <absimmsh+0x7ffa0858>
80005270:	deadbeef          	jal	t4,7ffe085a <absimmsh+0x7ffa085c>
80005274:	deadbeef          	jal	t4,7ffe085e <absimmsh+0x7ffa0860>
80005278:	deadbeef          	jal	t4,7ffe0862 <absimmsh+0x7ffa0864>
8000527c:	deadbeef          	jal	t4,7ffe0866 <absimmsh+0x7ffa0868>
80005280:	deadbeef          	jal	t4,7ffe086a <absimmsh+0x7ffa086c>
80005284:	deadbeef          	jal	t4,7ffe086e <absimmsh+0x7ffa0870>
80005288:	deadbeef          	jal	t4,7ffe0872 <absimmsh+0x7ffa0874>
8000528c:	deadbeef          	jal	t4,7ffe0876 <absimmsh+0x7ffa0878>
80005290:	deadbeef          	jal	t4,7ffe087a <absimmsh+0x7ffa087c>
80005294:	deadbeef          	jal	t4,7ffe087e <absimmsh+0x7ffa0880>
80005298:	deadbeef          	jal	t4,7ffe0882 <absimmsh+0x7ffa0884>
8000529c:	deadbeef          	jal	t4,7ffe0886 <absimmsh+0x7ffa0888>
800052a0:	deadbeef          	jal	t4,7ffe088a <absimmsh+0x7ffa088c>
800052a4:	deadbeef          	jal	t4,7ffe088e <absimmsh+0x7ffa0890>
800052a8:	deadbeef          	jal	t4,7ffe0892 <absimmsh+0x7ffa0894>
800052ac:	deadbeef          	jal	t4,7ffe0896 <absimmsh+0x7ffa0898>
800052b0:	deadbeef          	jal	t4,7ffe089a <absimmsh+0x7ffa089c>
800052b4:	deadbeef          	jal	t4,7ffe089e <absimmsh+0x7ffa08a0>
800052b8:	deadbeef          	jal	t4,7ffe08a2 <absimmsh+0x7ffa08a4>
800052bc:	deadbeef          	jal	t4,7ffe08a6 <absimmsh+0x7ffa08a8>
800052c0:	deadbeef          	jal	t4,7ffe08aa <absimmsh+0x7ffa08ac>
800052c4:	deadbeef          	jal	t4,7ffe08ae <absimmsh+0x7ffa08b0>
800052c8:	deadbeef          	jal	t4,7ffe08b2 <absimmsh+0x7ffa08b4>
800052cc:	deadbeef          	jal	t4,7ffe08b6 <absimmsh+0x7ffa08b8>
800052d0:	deadbeef          	jal	t4,7ffe08ba <absimmsh+0x7ffa08bc>
800052d4:	deadbeef          	jal	t4,7ffe08be <absimmsh+0x7ffa08c0>
800052d8:	deadbeef          	jal	t4,7ffe08c2 <absimmsh+0x7ffa08c4>
800052dc:	deadbeef          	jal	t4,7ffe08c6 <absimmsh+0x7ffa08c8>
800052e0:	deadbeef          	jal	t4,7ffe08ca <absimmsh+0x7ffa08cc>
800052e4:	deadbeef          	jal	t4,7ffe08ce <absimmsh+0x7ffa08d0>
800052e8:	deadbeef          	jal	t4,7ffe08d2 <absimmsh+0x7ffa08d4>
800052ec:	deadbeef          	jal	t4,7ffe08d6 <absimmsh+0x7ffa08d8>
800052f0:	deadbeef          	jal	t4,7ffe08da <absimmsh+0x7ffa08dc>
800052f4:	deadbeef          	jal	t4,7ffe08de <absimmsh+0x7ffa08e0>
800052f8:	deadbeef          	jal	t4,7ffe08e2 <absimmsh+0x7ffa08e4>
800052fc:	deadbeef          	jal	t4,7ffe08e6 <absimmsh+0x7ffa08e8>
80005300:	deadbeef          	jal	t4,7ffe08ea <absimmsh+0x7ffa08ec>
80005304:	deadbeef          	jal	t4,7ffe08ee <absimmsh+0x7ffa08f0>
80005308:	deadbeef          	jal	t4,7ffe08f2 <absimmsh+0x7ffa08f4>
8000530c:	deadbeef          	jal	t4,7ffe08f6 <absimmsh+0x7ffa08f8>
80005310:	deadbeef          	jal	t4,7ffe08fa <absimmsh+0x7ffa08fc>
80005314:	deadbeef          	jal	t4,7ffe08fe <absimmsh+0x7ffa0900>
80005318:	deadbeef          	jal	t4,7ffe0902 <absimmsh+0x7ffa0904>
8000531c:	deadbeef          	jal	t4,7ffe0906 <absimmsh+0x7ffa0908>
80005320:	deadbeef          	jal	t4,7ffe090a <absimmsh+0x7ffa090c>
80005324:	deadbeef          	jal	t4,7ffe090e <absimmsh+0x7ffa0910>
80005328:	deadbeef          	jal	t4,7ffe0912 <absimmsh+0x7ffa0914>
8000532c:	deadbeef          	jal	t4,7ffe0916 <absimmsh+0x7ffa0918>
80005330:	deadbeef          	jal	t4,7ffe091a <absimmsh+0x7ffa091c>
80005334:	deadbeef          	jal	t4,7ffe091e <absimmsh+0x7ffa0920>
80005338:	deadbeef          	jal	t4,7ffe0922 <absimmsh+0x7ffa0924>
8000533c:	deadbeef          	jal	t4,7ffe0926 <absimmsh+0x7ffa0928>
80005340:	deadbeef          	jal	t4,7ffe092a <absimmsh+0x7ffa092c>
80005344:	deadbeef          	jal	t4,7ffe092e <absimmsh+0x7ffa0930>
80005348:	deadbeef          	jal	t4,7ffe0932 <absimmsh+0x7ffa0934>
8000534c:	deadbeef          	jal	t4,7ffe0936 <absimmsh+0x7ffa0938>
80005350:	deadbeef          	jal	t4,7ffe093a <absimmsh+0x7ffa093c>
80005354:	deadbeef          	jal	t4,7ffe093e <absimmsh+0x7ffa0940>
80005358:	deadbeef          	jal	t4,7ffe0942 <absimmsh+0x7ffa0944>
8000535c:	deadbeef          	jal	t4,7ffe0946 <absimmsh+0x7ffa0948>
80005360:	deadbeef          	jal	t4,7ffe094a <absimmsh+0x7ffa094c>
80005364:	deadbeef          	jal	t4,7ffe094e <absimmsh+0x7ffa0950>
80005368:	deadbeef          	jal	t4,7ffe0952 <absimmsh+0x7ffa0954>
8000536c:	deadbeef          	jal	t4,7ffe0956 <absimmsh+0x7ffa0958>
80005370:	deadbeef          	jal	t4,7ffe095a <absimmsh+0x7ffa095c>
80005374:	deadbeef          	jal	t4,7ffe095e <absimmsh+0x7ffa0960>
80005378:	deadbeef          	jal	t4,7ffe0962 <absimmsh+0x7ffa0964>
8000537c:	deadbeef          	jal	t4,7ffe0966 <absimmsh+0x7ffa0968>
80005380:	deadbeef          	jal	t4,7ffe096a <absimmsh+0x7ffa096c>
80005384:	deadbeef          	jal	t4,7ffe096e <absimmsh+0x7ffa0970>
80005388:	deadbeef          	jal	t4,7ffe0972 <absimmsh+0x7ffa0974>
8000538c:	deadbeef          	jal	t4,7ffe0976 <absimmsh+0x7ffa0978>
80005390:	deadbeef          	jal	t4,7ffe097a <absimmsh+0x7ffa097c>
80005394:	deadbeef          	jal	t4,7ffe097e <absimmsh+0x7ffa0980>
80005398:	deadbeef          	jal	t4,7ffe0982 <absimmsh+0x7ffa0984>
8000539c:	deadbeef          	jal	t4,7ffe0986 <absimmsh+0x7ffa0988>
800053a0:	deadbeef          	jal	t4,7ffe098a <absimmsh+0x7ffa098c>
800053a4:	deadbeef          	jal	t4,7ffe098e <absimmsh+0x7ffa0990>
800053a8:	deadbeef          	jal	t4,7ffe0992 <absimmsh+0x7ffa0994>
800053ac:	deadbeef          	jal	t4,7ffe0996 <absimmsh+0x7ffa0998>
800053b0:	deadbeef          	jal	t4,7ffe099a <absimmsh+0x7ffa099c>
800053b4:	deadbeef          	jal	t4,7ffe099e <absimmsh+0x7ffa09a0>
800053b8:	deadbeef          	jal	t4,7ffe09a2 <absimmsh+0x7ffa09a4>
800053bc:	deadbeef          	jal	t4,7ffe09a6 <absimmsh+0x7ffa09a8>
800053c0:	deadbeef          	jal	t4,7ffe09aa <absimmsh+0x7ffa09ac>
800053c4:	deadbeef          	jal	t4,7ffe09ae <absimmsh+0x7ffa09b0>
800053c8:	deadbeef          	jal	t4,7ffe09b2 <absimmsh+0x7ffa09b4>
800053cc:	deadbeef          	jal	t4,7ffe09b6 <absimmsh+0x7ffa09b8>
800053d0:	deadbeef          	jal	t4,7ffe09ba <absimmsh+0x7ffa09bc>
800053d4:	deadbeef          	jal	t4,7ffe09be <absimmsh+0x7ffa09c0>
800053d8:	deadbeef          	jal	t4,7ffe09c2 <absimmsh+0x7ffa09c4>
800053dc:	deadbeef          	jal	t4,7ffe09c6 <absimmsh+0x7ffa09c8>
800053e0:	deadbeef          	jal	t4,7ffe09ca <absimmsh+0x7ffa09cc>
800053e4:	deadbeef          	jal	t4,7ffe09ce <absimmsh+0x7ffa09d0>
800053e8:	deadbeef          	jal	t4,7ffe09d2 <absimmsh+0x7ffa09d4>
800053ec:	deadbeef          	jal	t4,7ffe09d6 <absimmsh+0x7ffa09d8>
800053f0:	deadbeef          	jal	t4,7ffe09da <absimmsh+0x7ffa09dc>
800053f4:	deadbeef          	jal	t4,7ffe09de <absimmsh+0x7ffa09e0>
800053f8:	deadbeef          	jal	t4,7ffe09e2 <absimmsh+0x7ffa09e4>
800053fc:	deadbeef          	jal	t4,7ffe09e6 <absimmsh+0x7ffa09e8>
80005400:	deadbeef          	jal	t4,7ffe09ea <absimmsh+0x7ffa09ec>
80005404:	deadbeef          	jal	t4,7ffe09ee <absimmsh+0x7ffa09f0>
80005408:	deadbeef          	jal	t4,7ffe09f2 <absimmsh+0x7ffa09f4>
8000540c:	deadbeef          	jal	t4,7ffe09f6 <absimmsh+0x7ffa09f8>
80005410:	deadbeef          	jal	t4,7ffe09fa <absimmsh+0x7ffa09fc>
80005414:	deadbeef          	jal	t4,7ffe09fe <absimmsh+0x7ffa0a00>
80005418:	deadbeef          	jal	t4,7ffe0a02 <absimmsh+0x7ffa0a04>
8000541c:	deadbeef          	jal	t4,7ffe0a06 <absimmsh+0x7ffa0a08>
80005420:	deadbeef          	jal	t4,7ffe0a0a <absimmsh+0x7ffa0a0c>
80005424:	deadbeef          	jal	t4,7ffe0a0e <absimmsh+0x7ffa0a10>
80005428:	deadbeef          	jal	t4,7ffe0a12 <absimmsh+0x7ffa0a14>
8000542c:	deadbeef          	jal	t4,7ffe0a16 <absimmsh+0x7ffa0a18>
80005430:	deadbeef          	jal	t4,7ffe0a1a <absimmsh+0x7ffa0a1c>
80005434:	deadbeef          	jal	t4,7ffe0a1e <absimmsh+0x7ffa0a20>
80005438:	deadbeef          	jal	t4,7ffe0a22 <absimmsh+0x7ffa0a24>
8000543c:	deadbeef          	jal	t4,7ffe0a26 <absimmsh+0x7ffa0a28>
80005440:	deadbeef          	jal	t4,7ffe0a2a <absimmsh+0x7ffa0a2c>
80005444:	deadbeef          	jal	t4,7ffe0a2e <absimmsh+0x7ffa0a30>
80005448:	deadbeef          	jal	t4,7ffe0a32 <absimmsh+0x7ffa0a34>
8000544c:	deadbeef          	jal	t4,7ffe0a36 <absimmsh+0x7ffa0a38>
80005450:	deadbeef          	jal	t4,7ffe0a3a <absimmsh+0x7ffa0a3c>
80005454:	deadbeef          	jal	t4,7ffe0a3e <absimmsh+0x7ffa0a40>
80005458:	deadbeef          	jal	t4,7ffe0a42 <absimmsh+0x7ffa0a44>
8000545c:	deadbeef          	jal	t4,7ffe0a46 <absimmsh+0x7ffa0a48>
80005460:	deadbeef          	jal	t4,7ffe0a4a <absimmsh+0x7ffa0a4c>
80005464:	deadbeef          	jal	t4,7ffe0a4e <absimmsh+0x7ffa0a50>
80005468:	deadbeef          	jal	t4,7ffe0a52 <absimmsh+0x7ffa0a54>
8000546c:	deadbeef          	jal	t4,7ffe0a56 <absimmsh+0x7ffa0a58>
80005470:	deadbeef          	jal	t4,7ffe0a5a <absimmsh+0x7ffa0a5c>
80005474:	deadbeef          	jal	t4,7ffe0a5e <absimmsh+0x7ffa0a60>
80005478:	deadbeef          	jal	t4,7ffe0a62 <absimmsh+0x7ffa0a64>
8000547c:	deadbeef          	jal	t4,7ffe0a66 <absimmsh+0x7ffa0a68>
80005480:	deadbeef          	jal	t4,7ffe0a6a <absimmsh+0x7ffa0a6c>
80005484:	deadbeef          	jal	t4,7ffe0a6e <absimmsh+0x7ffa0a70>
80005488:	deadbeef          	jal	t4,7ffe0a72 <absimmsh+0x7ffa0a74>
8000548c:	deadbeef          	jal	t4,7ffe0a76 <absimmsh+0x7ffa0a78>
80005490:	deadbeef          	jal	t4,7ffe0a7a <absimmsh+0x7ffa0a7c>
80005494:	deadbeef          	jal	t4,7ffe0a7e <absimmsh+0x7ffa0a80>
80005498:	deadbeef          	jal	t4,7ffe0a82 <absimmsh+0x7ffa0a84>
8000549c:	deadbeef          	jal	t4,7ffe0a86 <absimmsh+0x7ffa0a88>
800054a0:	deadbeef          	jal	t4,7ffe0a8a <absimmsh+0x7ffa0a8c>
800054a4:	deadbeef          	jal	t4,7ffe0a8e <absimmsh+0x7ffa0a90>
800054a8:	deadbeef          	jal	t4,7ffe0a92 <absimmsh+0x7ffa0a94>
800054ac:	deadbeef          	jal	t4,7ffe0a96 <absimmsh+0x7ffa0a98>
800054b0:	deadbeef          	jal	t4,7ffe0a9a <absimmsh+0x7ffa0a9c>
800054b4:	deadbeef          	jal	t4,7ffe0a9e <absimmsh+0x7ffa0aa0>
800054b8:	deadbeef          	jal	t4,7ffe0aa2 <absimmsh+0x7ffa0aa4>
800054bc:	deadbeef          	jal	t4,7ffe0aa6 <absimmsh+0x7ffa0aa8>
800054c0:	deadbeef          	jal	t4,7ffe0aaa <absimmsh+0x7ffa0aac>
800054c4:	deadbeef          	jal	t4,7ffe0aae <absimmsh+0x7ffa0ab0>
800054c8:	deadbeef          	jal	t4,7ffe0ab2 <absimmsh+0x7ffa0ab4>
800054cc:	deadbeef          	jal	t4,7ffe0ab6 <absimmsh+0x7ffa0ab8>
800054d0:	deadbeef          	jal	t4,7ffe0aba <absimmsh+0x7ffa0abc>
800054d4:	deadbeef          	jal	t4,7ffe0abe <absimmsh+0x7ffa0ac0>
800054d8:	deadbeef          	jal	t4,7ffe0ac2 <absimmsh+0x7ffa0ac4>
800054dc:	deadbeef          	jal	t4,7ffe0ac6 <absimmsh+0x7ffa0ac8>
800054e0:	deadbeef          	jal	t4,7ffe0aca <absimmsh+0x7ffa0acc>
800054e4:	deadbeef          	jal	t4,7ffe0ace <absimmsh+0x7ffa0ad0>
800054e8:	deadbeef          	jal	t4,7ffe0ad2 <absimmsh+0x7ffa0ad4>
800054ec:	deadbeef          	jal	t4,7ffe0ad6 <absimmsh+0x7ffa0ad8>
800054f0:	deadbeef          	jal	t4,7ffe0ada <absimmsh+0x7ffa0adc>
800054f4:	deadbeef          	jal	t4,7ffe0ade <absimmsh+0x7ffa0ae0>
800054f8:	deadbeef          	jal	t4,7ffe0ae2 <absimmsh+0x7ffa0ae4>
800054fc:	deadbeef          	jal	t4,7ffe0ae6 <absimmsh+0x7ffa0ae8>
80005500:	deadbeef          	jal	t4,7ffe0aea <absimmsh+0x7ffa0aec>
80005504:	deadbeef          	jal	t4,7ffe0aee <absimmsh+0x7ffa0af0>
80005508:	deadbeef          	jal	t4,7ffe0af2 <absimmsh+0x7ffa0af4>
8000550c:	deadbeef          	jal	t4,7ffe0af6 <absimmsh+0x7ffa0af8>
80005510:	deadbeef          	jal	t4,7ffe0afa <absimmsh+0x7ffa0afc>
80005514:	deadbeef          	jal	t4,7ffe0afe <absimmsh+0x7ffa0b00>
80005518:	deadbeef          	jal	t4,7ffe0b02 <absimmsh+0x7ffa0b04>
8000551c:	deadbeef          	jal	t4,7ffe0b06 <absimmsh+0x7ffa0b08>
80005520:	deadbeef          	jal	t4,7ffe0b0a <absimmsh+0x7ffa0b0c>
80005524:	deadbeef          	jal	t4,7ffe0b0e <absimmsh+0x7ffa0b10>
80005528:	deadbeef          	jal	t4,7ffe0b12 <absimmsh+0x7ffa0b14>
8000552c:	deadbeef          	jal	t4,7ffe0b16 <absimmsh+0x7ffa0b18>
80005530:	deadbeef          	jal	t4,7ffe0b1a <absimmsh+0x7ffa0b1c>
80005534:	deadbeef          	jal	t4,7ffe0b1e <absimmsh+0x7ffa0b20>
80005538:	deadbeef          	jal	t4,7ffe0b22 <absimmsh+0x7ffa0b24>
8000553c:	deadbeef          	jal	t4,7ffe0b26 <absimmsh+0x7ffa0b28>
80005540:	deadbeef          	jal	t4,7ffe0b2a <absimmsh+0x7ffa0b2c>
80005544:	deadbeef          	jal	t4,7ffe0b2e <absimmsh+0x7ffa0b30>
80005548:	deadbeef          	jal	t4,7ffe0b32 <absimmsh+0x7ffa0b34>
8000554c:	deadbeef          	jal	t4,7ffe0b36 <absimmsh+0x7ffa0b38>
80005550:	deadbeef          	jal	t4,7ffe0b3a <absimmsh+0x7ffa0b3c>
80005554:	deadbeef          	jal	t4,7ffe0b3e <absimmsh+0x7ffa0b40>
80005558:	deadbeef          	jal	t4,7ffe0b42 <absimmsh+0x7ffa0b44>
8000555c:	deadbeef          	jal	t4,7ffe0b46 <absimmsh+0x7ffa0b48>
80005560:	deadbeef          	jal	t4,7ffe0b4a <absimmsh+0x7ffa0b4c>
80005564:	deadbeef          	jal	t4,7ffe0b4e <absimmsh+0x7ffa0b50>
80005568:	deadbeef          	jal	t4,7ffe0b52 <absimmsh+0x7ffa0b54>
8000556c:	deadbeef          	jal	t4,7ffe0b56 <absimmsh+0x7ffa0b58>
80005570:	deadbeef          	jal	t4,7ffe0b5a <absimmsh+0x7ffa0b5c>
80005574:	deadbeef          	jal	t4,7ffe0b5e <absimmsh+0x7ffa0b60>
80005578:	deadbeef          	jal	t4,7ffe0b62 <absimmsh+0x7ffa0b64>
8000557c:	deadbeef          	jal	t4,7ffe0b66 <absimmsh+0x7ffa0b68>
80005580:	deadbeef          	jal	t4,7ffe0b6a <absimmsh+0x7ffa0b6c>
80005584:	deadbeef          	jal	t4,7ffe0b6e <absimmsh+0x7ffa0b70>
80005588:	deadbeef          	jal	t4,7ffe0b72 <absimmsh+0x7ffa0b74>
8000558c:	deadbeef          	jal	t4,7ffe0b76 <absimmsh+0x7ffa0b78>
80005590:	deadbeef          	jal	t4,7ffe0b7a <absimmsh+0x7ffa0b7c>
80005594:	deadbeef          	jal	t4,7ffe0b7e <absimmsh+0x7ffa0b80>
80005598:	deadbeef          	jal	t4,7ffe0b82 <absimmsh+0x7ffa0b84>
8000559c:	deadbeef          	jal	t4,7ffe0b86 <absimmsh+0x7ffa0b88>
800055a0:	deadbeef          	jal	t4,7ffe0b8a <absimmsh+0x7ffa0b8c>
800055a4:	deadbeef          	jal	t4,7ffe0b8e <absimmsh+0x7ffa0b90>
800055a8:	deadbeef          	jal	t4,7ffe0b92 <absimmsh+0x7ffa0b94>
800055ac:	deadbeef          	jal	t4,7ffe0b96 <absimmsh+0x7ffa0b98>
800055b0:	deadbeef          	jal	t4,7ffe0b9a <absimmsh+0x7ffa0b9c>
800055b4:	deadbeef          	jal	t4,7ffe0b9e <absimmsh+0x7ffa0ba0>
800055b8:	deadbeef          	jal	t4,7ffe0ba2 <absimmsh+0x7ffa0ba4>
800055bc:	deadbeef          	jal	t4,7ffe0ba6 <absimmsh+0x7ffa0ba8>
800055c0:	deadbeef          	jal	t4,7ffe0baa <absimmsh+0x7ffa0bac>
800055c4:	deadbeef          	jal	t4,7ffe0bae <absimmsh+0x7ffa0bb0>
800055c8:	deadbeef          	jal	t4,7ffe0bb2 <absimmsh+0x7ffa0bb4>
800055cc:	deadbeef          	jal	t4,7ffe0bb6 <absimmsh+0x7ffa0bb8>
800055d0:	deadbeef          	jal	t4,7ffe0bba <absimmsh+0x7ffa0bbc>
800055d4:	deadbeef          	jal	t4,7ffe0bbe <absimmsh+0x7ffa0bc0>
800055d8:	deadbeef          	jal	t4,7ffe0bc2 <absimmsh+0x7ffa0bc4>
800055dc:	deadbeef          	jal	t4,7ffe0bc6 <absimmsh+0x7ffa0bc8>
800055e0:	deadbeef          	jal	t4,7ffe0bca <absimmsh+0x7ffa0bcc>
800055e4:	deadbeef          	jal	t4,7ffe0bce <absimmsh+0x7ffa0bd0>
800055e8:	deadbeef          	jal	t4,7ffe0bd2 <absimmsh+0x7ffa0bd4>
800055ec:	deadbeef          	jal	t4,7ffe0bd6 <absimmsh+0x7ffa0bd8>
800055f0:	deadbeef          	jal	t4,7ffe0bda <absimmsh+0x7ffa0bdc>
800055f4:	deadbeef          	jal	t4,7ffe0bde <absimmsh+0x7ffa0be0>
800055f8:	deadbeef          	jal	t4,7ffe0be2 <absimmsh+0x7ffa0be4>
800055fc:	deadbeef          	jal	t4,7ffe0be6 <absimmsh+0x7ffa0be8>
80005600:	deadbeef          	jal	t4,7ffe0bea <absimmsh+0x7ffa0bec>
80005604:	deadbeef          	jal	t4,7ffe0bee <absimmsh+0x7ffa0bf0>
80005608:	deadbeef          	jal	t4,7ffe0bf2 <absimmsh+0x7ffa0bf4>
8000560c:	deadbeef          	jal	t4,7ffe0bf6 <absimmsh+0x7ffa0bf8>
80005610:	deadbeef          	jal	t4,7ffe0bfa <absimmsh+0x7ffa0bfc>
80005614:	deadbeef          	jal	t4,7ffe0bfe <absimmsh+0x7ffa0c00>
80005618:	deadbeef          	jal	t4,7ffe0c02 <absimmsh+0x7ffa0c04>
8000561c:	deadbeef          	jal	t4,7ffe0c06 <absimmsh+0x7ffa0c08>
80005620:	deadbeef          	jal	t4,7ffe0c0a <absimmsh+0x7ffa0c0c>
80005624:	deadbeef          	jal	t4,7ffe0c0e <absimmsh+0x7ffa0c10>
80005628:	deadbeef          	jal	t4,7ffe0c12 <absimmsh+0x7ffa0c14>
8000562c:	deadbeef          	jal	t4,7ffe0c16 <absimmsh+0x7ffa0c18>
80005630:	deadbeef          	jal	t4,7ffe0c1a <absimmsh+0x7ffa0c1c>
80005634:	deadbeef          	jal	t4,7ffe0c1e <absimmsh+0x7ffa0c20>
80005638:	deadbeef          	jal	t4,7ffe0c22 <absimmsh+0x7ffa0c24>
8000563c:	deadbeef          	jal	t4,7ffe0c26 <absimmsh+0x7ffa0c28>
80005640:	deadbeef          	jal	t4,7ffe0c2a <absimmsh+0x7ffa0c2c>
80005644:	deadbeef          	jal	t4,7ffe0c2e <absimmsh+0x7ffa0c30>
80005648:	deadbeef          	jal	t4,7ffe0c32 <absimmsh+0x7ffa0c34>
8000564c:	deadbeef          	jal	t4,7ffe0c36 <absimmsh+0x7ffa0c38>
80005650:	deadbeef          	jal	t4,7ffe0c3a <absimmsh+0x7ffa0c3c>
80005654:	deadbeef          	jal	t4,7ffe0c3e <absimmsh+0x7ffa0c40>
80005658:	deadbeef          	jal	t4,7ffe0c42 <absimmsh+0x7ffa0c44>
8000565c:	deadbeef          	jal	t4,7ffe0c46 <absimmsh+0x7ffa0c48>
80005660:	deadbeef          	jal	t4,7ffe0c4a <absimmsh+0x7ffa0c4c>
80005664:	deadbeef          	jal	t4,7ffe0c4e <absimmsh+0x7ffa0c50>
80005668:	deadbeef          	jal	t4,7ffe0c52 <absimmsh+0x7ffa0c54>
8000566c:	deadbeef          	jal	t4,7ffe0c56 <absimmsh+0x7ffa0c58>
80005670:	deadbeef          	jal	t4,7ffe0c5a <absimmsh+0x7ffa0c5c>
80005674:	deadbeef          	jal	t4,7ffe0c5e <absimmsh+0x7ffa0c60>
80005678:	deadbeef          	jal	t4,7ffe0c62 <absimmsh+0x7ffa0c64>
8000567c:	deadbeef          	jal	t4,7ffe0c66 <absimmsh+0x7ffa0c68>
80005680:	deadbeef          	jal	t4,7ffe0c6a <absimmsh+0x7ffa0c6c>
80005684:	deadbeef          	jal	t4,7ffe0c6e <absimmsh+0x7ffa0c70>
80005688:	deadbeef          	jal	t4,7ffe0c72 <absimmsh+0x7ffa0c74>
8000568c:	deadbeef          	jal	t4,7ffe0c76 <absimmsh+0x7ffa0c78>
80005690:	deadbeef          	jal	t4,7ffe0c7a <absimmsh+0x7ffa0c7c>
80005694:	deadbeef          	jal	t4,7ffe0c7e <absimmsh+0x7ffa0c80>
80005698:	deadbeef          	jal	t4,7ffe0c82 <absimmsh+0x7ffa0c84>
8000569c:	deadbeef          	jal	t4,7ffe0c86 <absimmsh+0x7ffa0c88>
800056a0:	deadbeef          	jal	t4,7ffe0c8a <absimmsh+0x7ffa0c8c>
800056a4:	deadbeef          	jal	t4,7ffe0c8e <absimmsh+0x7ffa0c90>
800056a8:	deadbeef          	jal	t4,7ffe0c92 <absimmsh+0x7ffa0c94>
800056ac:	deadbeef          	jal	t4,7ffe0c96 <absimmsh+0x7ffa0c98>
800056b0:	deadbeef          	jal	t4,7ffe0c9a <absimmsh+0x7ffa0c9c>
800056b4:	deadbeef          	jal	t4,7ffe0c9e <absimmsh+0x7ffa0ca0>
800056b8:	deadbeef          	jal	t4,7ffe0ca2 <absimmsh+0x7ffa0ca4>
800056bc:	deadbeef          	jal	t4,7ffe0ca6 <absimmsh+0x7ffa0ca8>
800056c0:	deadbeef          	jal	t4,7ffe0caa <absimmsh+0x7ffa0cac>
800056c4:	deadbeef          	jal	t4,7ffe0cae <absimmsh+0x7ffa0cb0>
800056c8:	deadbeef          	jal	t4,7ffe0cb2 <absimmsh+0x7ffa0cb4>
800056cc:	deadbeef          	jal	t4,7ffe0cb6 <absimmsh+0x7ffa0cb8>
800056d0:	deadbeef          	jal	t4,7ffe0cba <absimmsh+0x7ffa0cbc>
800056d4:	deadbeef          	jal	t4,7ffe0cbe <absimmsh+0x7ffa0cc0>
800056d8:	deadbeef          	jal	t4,7ffe0cc2 <absimmsh+0x7ffa0cc4>
800056dc:	deadbeef          	jal	t4,7ffe0cc6 <absimmsh+0x7ffa0cc8>
800056e0:	deadbeef          	jal	t4,7ffe0cca <absimmsh+0x7ffa0ccc>
800056e4:	deadbeef          	jal	t4,7ffe0cce <absimmsh+0x7ffa0cd0>
800056e8:	deadbeef          	jal	t4,7ffe0cd2 <absimmsh+0x7ffa0cd4>
800056ec:	deadbeef          	jal	t4,7ffe0cd6 <absimmsh+0x7ffa0cd8>
800056f0:	deadbeef          	jal	t4,7ffe0cda <absimmsh+0x7ffa0cdc>
800056f4:	deadbeef          	jal	t4,7ffe0cde <absimmsh+0x7ffa0ce0>
800056f8:	deadbeef          	jal	t4,7ffe0ce2 <absimmsh+0x7ffa0ce4>
800056fc:	deadbeef          	jal	t4,7ffe0ce6 <absimmsh+0x7ffa0ce8>
80005700:	deadbeef          	jal	t4,7ffe0cea <absimmsh+0x7ffa0cec>
80005704:	deadbeef          	jal	t4,7ffe0cee <absimmsh+0x7ffa0cf0>
80005708:	deadbeef          	jal	t4,7ffe0cf2 <absimmsh+0x7ffa0cf4>
8000570c:	deadbeef          	jal	t4,7ffe0cf6 <absimmsh+0x7ffa0cf8>
80005710:	deadbeef          	jal	t4,7ffe0cfa <absimmsh+0x7ffa0cfc>
80005714:	deadbeef          	jal	t4,7ffe0cfe <absimmsh+0x7ffa0d00>
80005718:	deadbeef          	jal	t4,7ffe0d02 <absimmsh+0x7ffa0d04>
8000571c:	deadbeef          	jal	t4,7ffe0d06 <absimmsh+0x7ffa0d08>
80005720:	deadbeef          	jal	t4,7ffe0d0a <absimmsh+0x7ffa0d0c>
80005724:	deadbeef          	jal	t4,7ffe0d0e <absimmsh+0x7ffa0d10>
80005728:	deadbeef          	jal	t4,7ffe0d12 <absimmsh+0x7ffa0d14>
8000572c:	deadbeef          	jal	t4,7ffe0d16 <absimmsh+0x7ffa0d18>
80005730:	deadbeef          	jal	t4,7ffe0d1a <absimmsh+0x7ffa0d1c>
80005734:	deadbeef          	jal	t4,7ffe0d1e <absimmsh+0x7ffa0d20>
80005738:	deadbeef          	jal	t4,7ffe0d22 <absimmsh+0x7ffa0d24>
8000573c:	deadbeef          	jal	t4,7ffe0d26 <absimmsh+0x7ffa0d28>
80005740:	deadbeef          	jal	t4,7ffe0d2a <absimmsh+0x7ffa0d2c>
80005744:	deadbeef          	jal	t4,7ffe0d2e <absimmsh+0x7ffa0d30>
80005748:	deadbeef          	jal	t4,7ffe0d32 <absimmsh+0x7ffa0d34>
8000574c:	deadbeef          	jal	t4,7ffe0d36 <absimmsh+0x7ffa0d38>
80005750:	deadbeef          	jal	t4,7ffe0d3a <absimmsh+0x7ffa0d3c>
80005754:	deadbeef          	jal	t4,7ffe0d3e <absimmsh+0x7ffa0d40>
80005758:	deadbeef          	jal	t4,7ffe0d42 <absimmsh+0x7ffa0d44>
8000575c:	deadbeef          	jal	t4,7ffe0d46 <absimmsh+0x7ffa0d48>
80005760:	deadbeef          	jal	t4,7ffe0d4a <absimmsh+0x7ffa0d4c>
80005764:	deadbeef          	jal	t4,7ffe0d4e <absimmsh+0x7ffa0d50>
80005768:	deadbeef          	jal	t4,7ffe0d52 <absimmsh+0x7ffa0d54>
8000576c:	deadbeef          	jal	t4,7ffe0d56 <absimmsh+0x7ffa0d58>
80005770:	deadbeef          	jal	t4,7ffe0d5a <absimmsh+0x7ffa0d5c>
80005774:	deadbeef          	jal	t4,7ffe0d5e <absimmsh+0x7ffa0d60>
80005778:	deadbeef          	jal	t4,7ffe0d62 <absimmsh+0x7ffa0d64>
8000577c:	deadbeef          	jal	t4,7ffe0d66 <absimmsh+0x7ffa0d68>
80005780:	deadbeef          	jal	t4,7ffe0d6a <absimmsh+0x7ffa0d6c>
80005784:	deadbeef          	jal	t4,7ffe0d6e <absimmsh+0x7ffa0d70>
80005788:	deadbeef          	jal	t4,7ffe0d72 <absimmsh+0x7ffa0d74>
8000578c:	deadbeef          	jal	t4,7ffe0d76 <absimmsh+0x7ffa0d78>
80005790:	deadbeef          	jal	t4,7ffe0d7a <absimmsh+0x7ffa0d7c>
80005794:	deadbeef          	jal	t4,7ffe0d7e <absimmsh+0x7ffa0d80>
80005798:	deadbeef          	jal	t4,7ffe0d82 <absimmsh+0x7ffa0d84>
8000579c:	deadbeef          	jal	t4,7ffe0d86 <absimmsh+0x7ffa0d88>
800057a0:	deadbeef          	jal	t4,7ffe0d8a <absimmsh+0x7ffa0d8c>
800057a4:	deadbeef          	jal	t4,7ffe0d8e <absimmsh+0x7ffa0d90>
800057a8:	deadbeef          	jal	t4,7ffe0d92 <absimmsh+0x7ffa0d94>
800057ac:	deadbeef          	jal	t4,7ffe0d96 <absimmsh+0x7ffa0d98>
800057b0:	deadbeef          	jal	t4,7ffe0d9a <absimmsh+0x7ffa0d9c>
800057b4:	deadbeef          	jal	t4,7ffe0d9e <absimmsh+0x7ffa0da0>
800057b8:	deadbeef          	jal	t4,7ffe0da2 <absimmsh+0x7ffa0da4>
800057bc:	deadbeef          	jal	t4,7ffe0da6 <absimmsh+0x7ffa0da8>
800057c0:	deadbeef          	jal	t4,7ffe0daa <absimmsh+0x7ffa0dac>
800057c4:	deadbeef          	jal	t4,7ffe0dae <absimmsh+0x7ffa0db0>
800057c8:	deadbeef          	jal	t4,7ffe0db2 <absimmsh+0x7ffa0db4>
800057cc:	deadbeef          	jal	t4,7ffe0db6 <absimmsh+0x7ffa0db8>
800057d0:	deadbeef          	jal	t4,7ffe0dba <absimmsh+0x7ffa0dbc>
800057d4:	deadbeef          	jal	t4,7ffe0dbe <absimmsh+0x7ffa0dc0>
800057d8:	deadbeef          	jal	t4,7ffe0dc2 <absimmsh+0x7ffa0dc4>
800057dc:	deadbeef          	jal	t4,7ffe0dc6 <absimmsh+0x7ffa0dc8>
800057e0:	deadbeef          	jal	t4,7ffe0dca <absimmsh+0x7ffa0dcc>
800057e4:	deadbeef          	jal	t4,7ffe0dce <absimmsh+0x7ffa0dd0>
800057e8:	deadbeef          	jal	t4,7ffe0dd2 <absimmsh+0x7ffa0dd4>
800057ec:	deadbeef          	jal	t4,7ffe0dd6 <absimmsh+0x7ffa0dd8>
800057f0:	deadbeef          	jal	t4,7ffe0dda <absimmsh+0x7ffa0ddc>
800057f4:	deadbeef          	jal	t4,7ffe0dde <absimmsh+0x7ffa0de0>
800057f8:	deadbeef          	jal	t4,7ffe0de2 <absimmsh+0x7ffa0de4>
800057fc:	deadbeef          	jal	t4,7ffe0de6 <absimmsh+0x7ffa0de8>
80005800:	deadbeef          	jal	t4,7ffe0dea <absimmsh+0x7ffa0dec>
80005804:	deadbeef          	jal	t4,7ffe0dee <absimmsh+0x7ffa0df0>
80005808:	deadbeef          	jal	t4,7ffe0df2 <absimmsh+0x7ffa0df4>
8000580c:	deadbeef          	jal	t4,7ffe0df6 <absimmsh+0x7ffa0df8>
80005810:	deadbeef          	jal	t4,7ffe0dfa <absimmsh+0x7ffa0dfc>
80005814:	deadbeef          	jal	t4,7ffe0dfe <absimmsh+0x7ffa0e00>
80005818:	deadbeef          	jal	t4,7ffe0e02 <absimmsh+0x7ffa0e04>
8000581c:	deadbeef          	jal	t4,7ffe0e06 <absimmsh+0x7ffa0e08>
80005820:	deadbeef          	jal	t4,7ffe0e0a <absimmsh+0x7ffa0e0c>
80005824:	deadbeef          	jal	t4,7ffe0e0e <absimmsh+0x7ffa0e10>
80005828:	deadbeef          	jal	t4,7ffe0e12 <absimmsh+0x7ffa0e14>
8000582c:	deadbeef          	jal	t4,7ffe0e16 <absimmsh+0x7ffa0e18>
80005830:	deadbeef          	jal	t4,7ffe0e1a <absimmsh+0x7ffa0e1c>
80005834:	deadbeef          	jal	t4,7ffe0e1e <absimmsh+0x7ffa0e20>
80005838:	deadbeef          	jal	t4,7ffe0e22 <absimmsh+0x7ffa0e24>
8000583c:	deadbeef          	jal	t4,7ffe0e26 <absimmsh+0x7ffa0e28>
80005840:	deadbeef          	jal	t4,7ffe0e2a <absimmsh+0x7ffa0e2c>
80005844:	deadbeef          	jal	t4,7ffe0e2e <absimmsh+0x7ffa0e30>
80005848:	deadbeef          	jal	t4,7ffe0e32 <absimmsh+0x7ffa0e34>
8000584c:	deadbeef          	jal	t4,7ffe0e36 <absimmsh+0x7ffa0e38>
80005850:	deadbeef          	jal	t4,7ffe0e3a <absimmsh+0x7ffa0e3c>
80005854:	deadbeef          	jal	t4,7ffe0e3e <absimmsh+0x7ffa0e40>
80005858:	deadbeef          	jal	t4,7ffe0e42 <absimmsh+0x7ffa0e44>
8000585c:	deadbeef          	jal	t4,7ffe0e46 <absimmsh+0x7ffa0e48>
80005860:	deadbeef          	jal	t4,7ffe0e4a <absimmsh+0x7ffa0e4c>
80005864:	deadbeef          	jal	t4,7ffe0e4e <absimmsh+0x7ffa0e50>
80005868:	deadbeef          	jal	t4,7ffe0e52 <absimmsh+0x7ffa0e54>
8000586c:	deadbeef          	jal	t4,7ffe0e56 <absimmsh+0x7ffa0e58>
80005870:	deadbeef          	jal	t4,7ffe0e5a <absimmsh+0x7ffa0e5c>
80005874:	deadbeef          	jal	t4,7ffe0e5e <absimmsh+0x7ffa0e60>
80005878:	deadbeef          	jal	t4,7ffe0e62 <absimmsh+0x7ffa0e64>
8000587c:	deadbeef          	jal	t4,7ffe0e66 <absimmsh+0x7ffa0e68>
80005880:	deadbeef          	jal	t4,7ffe0e6a <absimmsh+0x7ffa0e6c>
80005884:	deadbeef          	jal	t4,7ffe0e6e <absimmsh+0x7ffa0e70>
80005888:	deadbeef          	jal	t4,7ffe0e72 <absimmsh+0x7ffa0e74>
8000588c:	deadbeef          	jal	t4,7ffe0e76 <absimmsh+0x7ffa0e78>
80005890:	deadbeef          	jal	t4,7ffe0e7a <absimmsh+0x7ffa0e7c>
80005894:	deadbeef          	jal	t4,7ffe0e7e <absimmsh+0x7ffa0e80>
80005898:	deadbeef          	jal	t4,7ffe0e82 <absimmsh+0x7ffa0e84>
8000589c:	deadbeef          	jal	t4,7ffe0e86 <absimmsh+0x7ffa0e88>
800058a0:	deadbeef          	jal	t4,7ffe0e8a <absimmsh+0x7ffa0e8c>
800058a4:	deadbeef          	jal	t4,7ffe0e8e <absimmsh+0x7ffa0e90>
800058a8:	deadbeef          	jal	t4,7ffe0e92 <absimmsh+0x7ffa0e94>
800058ac:	deadbeef          	jal	t4,7ffe0e96 <absimmsh+0x7ffa0e98>
800058b0:	deadbeef          	jal	t4,7ffe0e9a <absimmsh+0x7ffa0e9c>
800058b4:	deadbeef          	jal	t4,7ffe0e9e <absimmsh+0x7ffa0ea0>
800058b8:	deadbeef          	jal	t4,7ffe0ea2 <absimmsh+0x7ffa0ea4>
800058bc:	deadbeef          	jal	t4,7ffe0ea6 <absimmsh+0x7ffa0ea8>
800058c0:	deadbeef          	jal	t4,7ffe0eaa <absimmsh+0x7ffa0eac>
800058c4:	deadbeef          	jal	t4,7ffe0eae <absimmsh+0x7ffa0eb0>
800058c8:	deadbeef          	jal	t4,7ffe0eb2 <absimmsh+0x7ffa0eb4>
800058cc:	deadbeef          	jal	t4,7ffe0eb6 <absimmsh+0x7ffa0eb8>
800058d0:	deadbeef          	jal	t4,7ffe0eba <absimmsh+0x7ffa0ebc>
800058d4:	deadbeef          	jal	t4,7ffe0ebe <absimmsh+0x7ffa0ec0>
800058d8:	deadbeef          	jal	t4,7ffe0ec2 <absimmsh+0x7ffa0ec4>
800058dc:	deadbeef          	jal	t4,7ffe0ec6 <absimmsh+0x7ffa0ec8>
800058e0:	deadbeef          	jal	t4,7ffe0eca <absimmsh+0x7ffa0ecc>
800058e4:	deadbeef          	jal	t4,7ffe0ece <absimmsh+0x7ffa0ed0>
800058e8:	deadbeef          	jal	t4,7ffe0ed2 <absimmsh+0x7ffa0ed4>
800058ec:	deadbeef          	jal	t4,7ffe0ed6 <absimmsh+0x7ffa0ed8>
800058f0:	deadbeef          	jal	t4,7ffe0eda <absimmsh+0x7ffa0edc>
800058f4:	deadbeef          	jal	t4,7ffe0ede <absimmsh+0x7ffa0ee0>
800058f8:	deadbeef          	jal	t4,7ffe0ee2 <absimmsh+0x7ffa0ee4>
800058fc:	deadbeef          	jal	t4,7ffe0ee6 <absimmsh+0x7ffa0ee8>
80005900:	deadbeef          	jal	t4,7ffe0eea <absimmsh+0x7ffa0eec>
80005904:	deadbeef          	jal	t4,7ffe0eee <absimmsh+0x7ffa0ef0>
80005908:	deadbeef          	jal	t4,7ffe0ef2 <absimmsh+0x7ffa0ef4>
8000590c:	deadbeef          	jal	t4,7ffe0ef6 <absimmsh+0x7ffa0ef8>
80005910:	deadbeef          	jal	t4,7ffe0efa <absimmsh+0x7ffa0efc>
80005914:	deadbeef          	jal	t4,7ffe0efe <absimmsh+0x7ffa0f00>
80005918:	deadbeef          	jal	t4,7ffe0f02 <absimmsh+0x7ffa0f04>
8000591c:	deadbeef          	jal	t4,7ffe0f06 <absimmsh+0x7ffa0f08>
80005920:	deadbeef          	jal	t4,7ffe0f0a <absimmsh+0x7ffa0f0c>
80005924:	deadbeef          	jal	t4,7ffe0f0e <absimmsh+0x7ffa0f10>
80005928:	deadbeef          	jal	t4,7ffe0f12 <absimmsh+0x7ffa0f14>
8000592c:	deadbeef          	jal	t4,7ffe0f16 <absimmsh+0x7ffa0f18>
80005930:	deadbeef          	jal	t4,7ffe0f1a <absimmsh+0x7ffa0f1c>
80005934:	deadbeef          	jal	t4,7ffe0f1e <absimmsh+0x7ffa0f20>
80005938:	deadbeef          	jal	t4,7ffe0f22 <absimmsh+0x7ffa0f24>
8000593c:	deadbeef          	jal	t4,7ffe0f26 <absimmsh+0x7ffa0f28>
80005940:	deadbeef          	jal	t4,7ffe0f2a <absimmsh+0x7ffa0f2c>
80005944:	deadbeef          	jal	t4,7ffe0f2e <absimmsh+0x7ffa0f30>
80005948:	deadbeef          	jal	t4,7ffe0f32 <absimmsh+0x7ffa0f34>
8000594c:	deadbeef          	jal	t4,7ffe0f36 <absimmsh+0x7ffa0f38>
80005950:	deadbeef          	jal	t4,7ffe0f3a <absimmsh+0x7ffa0f3c>
80005954:	deadbeef          	jal	t4,7ffe0f3e <absimmsh+0x7ffa0f40>
80005958:	deadbeef          	jal	t4,7ffe0f42 <absimmsh+0x7ffa0f44>
8000595c:	deadbeef          	jal	t4,7ffe0f46 <absimmsh+0x7ffa0f48>
80005960:	deadbeef          	jal	t4,7ffe0f4a <absimmsh+0x7ffa0f4c>
80005964:	deadbeef          	jal	t4,7ffe0f4e <absimmsh+0x7ffa0f50>
80005968:	deadbeef          	jal	t4,7ffe0f52 <absimmsh+0x7ffa0f54>

8000596c <signature_x4_1>:
8000596c:	deadbeef          	jal	t4,7ffe0f56 <absimmsh+0x7ffa0f58>
80005970:	deadbeef          	jal	t4,7ffe0f5a <absimmsh+0x7ffa0f5c>
80005974:	deadbeef          	jal	t4,7ffe0f5e <absimmsh+0x7ffa0f60>
80005978:	deadbeef          	jal	t4,7ffe0f62 <absimmsh+0x7ffa0f64>
8000597c:	deadbeef          	jal	t4,7ffe0f66 <absimmsh+0x7ffa0f68>
80005980:	deadbeef          	jal	t4,7ffe0f6a <absimmsh+0x7ffa0f6c>
80005984:	deadbeef          	jal	t4,7ffe0f6e <absimmsh+0x7ffa0f70>
80005988:	deadbeef          	jal	t4,7ffe0f72 <absimmsh+0x7ffa0f74>
8000598c:	deadbeef          	jal	t4,7ffe0f76 <absimmsh+0x7ffa0f78>
80005990:	deadbeef          	jal	t4,7ffe0f7a <absimmsh+0x7ffa0f7c>
80005994:	deadbeef          	jal	t4,7ffe0f7e <absimmsh+0x7ffa0f80>
80005998:	deadbeef          	jal	t4,7ffe0f82 <absimmsh+0x7ffa0f84>
8000599c:	deadbeef          	jal	t4,7ffe0f86 <absimmsh+0x7ffa0f88>
800059a0:	deadbeef          	jal	t4,7ffe0f8a <absimmsh+0x7ffa0f8c>
800059a4:	deadbeef          	jal	t4,7ffe0f8e <absimmsh+0x7ffa0f90>
800059a8:	deadbeef          	jal	t4,7ffe0f92 <absimmsh+0x7ffa0f94>
800059ac:	deadbeef          	jal	t4,7ffe0f96 <absimmsh+0x7ffa0f98>
800059b0:	deadbeef          	jal	t4,7ffe0f9a <absimmsh+0x7ffa0f9c>
800059b4:	deadbeef          	jal	t4,7ffe0f9e <absimmsh+0x7ffa0fa0>
800059b8:	deadbeef          	jal	t4,7ffe0fa2 <absimmsh+0x7ffa0fa4>
800059bc:	deadbeef          	jal	t4,7ffe0fa6 <absimmsh+0x7ffa0fa8>
800059c0:	deadbeef          	jal	t4,7ffe0faa <absimmsh+0x7ffa0fac>
800059c4:	deadbeef          	jal	t4,7ffe0fae <absimmsh+0x7ffa0fb0>
800059c8:	deadbeef          	jal	t4,7ffe0fb2 <absimmsh+0x7ffa0fb4>
800059cc:	deadbeef          	jal	t4,7ffe0fb6 <absimmsh+0x7ffa0fb8>
800059d0:	deadbeef          	jal	t4,7ffe0fba <absimmsh+0x7ffa0fbc>

800059d4 <sig_end_canary>:
800059d4:	a309                	j	80005ed6 <_end+0x4f6>
800059d6:	6f5c                	flw	fa5,28(a4)

800059d8 <rvtest_sig_end>:
	...

Disassembly of section .riscv.attributes:

00000000 <.riscv.attributes>:
   0:	1941                	addi	s2,s2,-16
   2:	0000                	unimp
   4:	7200                	flw	fs0,32(a2)
   6:	7369                	lui	t1,0xffffa
   8:	01007663          	bgeu	zero,a6,14 <edge2+0x5>
   c:	0000000f          	fence	unknown,unknown
  10:	7205                	lui	tp,0xfffe1
  12:	3376                	fld	ft6,376(sp)
  14:	6932                	flw	fs2,12(sp)
  16:	7032                	flw	ft0,44(sp)
  18:	0030                	addi	a2,sp,8

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	0dc8                	addi	a0,sp,724
   2:	0000                	unimp
   4:	00740003          	lb	zero,7(s0)
   8:	0000                	unimp
   a:	0101                	addi	sp,sp,0
   c:	000d0efb          	0xd0efb
  10:	0101                	addi	sp,sp,0
  12:	0101                	addi	sp,sp,0
  14:	0000                	unimp
  16:	0100                	addi	s0,sp,128
  18:	0000                	unimp
  1a:	2f01                	jal	72a <offset+0x6c2>
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
  44:	612d7663          	bgeu	s10,s2,650 <offset+0x5e8>
  48:	6372                	flw	ft6,28(sp)
  4a:	2d68                	fld	fa0,216(a0)
  4c:	6574                	flw	fa3,76(a0)
  4e:	722f7473          	csrrci	s0,0x722,30
  52:	7369                	lui	t1,0xffffa
  54:	742d7663          	bgeu	s10,sp,7a0 <offset+0x738>
  58:	7365                	lui	t1,0xffff9
  5a:	2d74                	fld	fa3,216(a0)
  5c:	74697573          	csrrci	a0,0x746,18
  60:	2f65                	jal	818 <offset+0x7b0>
  62:	7672                	flw	fa2,60(sp)
  64:	5f693233          	0x5f693233
  68:	2f6d                	jal	822 <offset+0x7ba>
  6a:	2f49                	jal	7fc <offset+0x794>
  6c:	00637273          	csrrci	tp,0x6,6
  70:	6f00                	flw	fs0,24(a4)
  72:	6972                	flw	fs2,28(sp)
  74:	302d                	jal	fffff89e <imm12+0xfffff89f>
  76:	2e31                	jal	392 <offset+0x32a>
  78:	00010053          	fadd.s	ft0,ft2,ft0,rne
  7c:	0000                	unimp
  7e:	0500                	addi	s0,sp,640
  80:	0002                	c.slli64	zero
  82:	0000                	unimp
  84:	0380                	addi	s0,sp,448
  86:	0119                	addi	sp,sp,6
  88:	78090603          	lb	a2,1920(s2)
  8c:	0100                	addi	s0,sp,128
  8e:	08090503          	lb	a0,128(s2)
  92:	0100                	addi	s0,sp,128
  94:	0c090503          	lb	a0,192(s2)
  98:	0100                	addi	s0,sp,128
  9a:	0c090503          	lb	a0,192(s2)
  9e:	0100                	addi	s0,sp,128
  a0:	10090503          	lb	a0,256(s2)
  a4:	0100                	addi	s0,sp,128
  a6:	10090503          	lb	a0,256(s2)
  aa:	0100                	addi	s0,sp,128
  ac:	0c090503          	lb	a0,192(s2)
  b0:	0100                	addi	s0,sp,128
  b2:	10090503          	lb	a0,256(s2)
  b6:	0100                	addi	s0,sp,128
  b8:	0c090503          	lb	a0,192(s2)
  bc:	0100                	addi	s0,sp,128
  be:	0c090503          	lb	a0,192(s2)
  c2:	0100                	addi	s0,sp,128
  c4:	0c090503          	lb	a0,192(s2)
  c8:	0100                	addi	s0,sp,128
  ca:	0c090503          	lb	a0,192(s2)
  ce:	0100                	addi	s0,sp,128
  d0:	0c090503          	lb	a0,192(s2)
  d4:	0100                	addi	s0,sp,128
  d6:	0c090503          	lb	a0,192(s2)
  da:	0100                	addi	s0,sp,128
  dc:	0c090503          	lb	a0,192(s2)
  e0:	0100                	addi	s0,sp,128
  e2:	10090503          	lb	a0,256(s2)
  e6:	0100                	addi	s0,sp,128
  e8:	10090503          	lb	a0,256(s2)
  ec:	0100                	addi	s0,sp,128
  ee:	0c090503          	lb	a0,192(s2)
  f2:	0100                	addi	s0,sp,128
  f4:	10090503          	lb	a0,256(s2)
  f8:	0100                	addi	s0,sp,128
  fa:	10090503          	lb	a0,256(s2)
  fe:	0100                	addi	s0,sp,128
 100:	0c090503          	lb	a0,192(s2)
 104:	0100                	addi	s0,sp,128
 106:	10090503          	lb	a0,256(s2)
 10a:	0100                	addi	s0,sp,128
 10c:	0c090503          	lb	a0,192(s2)
 110:	0100                	addi	s0,sp,128
 112:	10090103          	lb	sp,256(s2)
 116:	0100                	addi	s0,sp,128
 118:	08090503          	lb	a0,128(s2)
 11c:	0100                	addi	s0,sp,128
 11e:	0c090503          	lb	a0,192(s2)
 122:	0100                	addi	s0,sp,128
 124:	0c090503          	lb	a0,192(s2)
 128:	0100                	addi	s0,sp,128
 12a:	10090503          	lb	a0,256(s2)
 12e:	0100                	addi	s0,sp,128
 130:	10090503          	lb	a0,256(s2)
 134:	0100                	addi	s0,sp,128
 136:	10090503          	lb	a0,256(s2)
 13a:	0100                	addi	s0,sp,128
 13c:	0c090503          	lb	a0,192(s2)
 140:	0100                	addi	s0,sp,128
 142:	0c090503          	lb	a0,192(s2)
 146:	0100                	addi	s0,sp,128
 148:	10090503          	lb	a0,256(s2)
 14c:	0100                	addi	s0,sp,128
 14e:	0c090503          	lb	a0,192(s2)
 152:	0100                	addi	s0,sp,128
 154:	0c090503          	lb	a0,192(s2)
 158:	0100                	addi	s0,sp,128
 15a:	0c090503          	lb	a0,192(s2)
 15e:	0100                	addi	s0,sp,128
 160:	0c090503          	lb	a0,192(s2)
 164:	0100                	addi	s0,sp,128
 166:	0c090503          	lb	a0,192(s2)
 16a:	0100                	addi	s0,sp,128
 16c:	0c090503          	lb	a0,192(s2)
 170:	0100                	addi	s0,sp,128
 172:	0c090503          	lb	a0,192(s2)
 176:	0100                	addi	s0,sp,128
 178:	0c090503          	lb	a0,192(s2)
 17c:	0100                	addi	s0,sp,128
 17e:	0c090503          	lb	a0,192(s2)
 182:	0100                	addi	s0,sp,128
 184:	0c090503          	lb	a0,192(s2)
 188:	0100                	addi	s0,sp,128
 18a:	0c090503          	lb	a0,192(s2)
 18e:	0100                	addi	s0,sp,128
 190:	0c090503          	lb	a0,192(s2)
 194:	0100                	addi	s0,sp,128
 196:	0c090503          	lb	a0,192(s2)
 19a:	0100                	addi	s0,sp,128
 19c:	0c090503          	lb	a0,192(s2)
 1a0:	0100                	addi	s0,sp,128
 1a2:	0c090503          	lb	a0,192(s2)
 1a6:	0100                	addi	s0,sp,128
 1a8:	0c090503          	lb	a0,192(s2)
 1ac:	0100                	addi	s0,sp,128
 1ae:	0c090503          	lb	a0,192(s2)
 1b2:	0100                	addi	s0,sp,128
 1b4:	0c090503          	lb	a0,192(s2)
 1b8:	0100                	addi	s0,sp,128
 1ba:	0c090503          	lb	a0,192(s2)
 1be:	0100                	addi	s0,sp,128
 1c0:	0c090503          	lb	a0,192(s2)
 1c4:	0100                	addi	s0,sp,128
 1c6:	0c090503          	lb	a0,192(s2)
 1ca:	0100                	addi	s0,sp,128
 1cc:	0c090503          	lb	a0,192(s2)
 1d0:	0100                	addi	s0,sp,128
 1d2:	0c090503          	lb	a0,192(s2)
 1d6:	0100                	addi	s0,sp,128
 1d8:	0c090503          	lb	a0,192(s2)
 1dc:	0100                	addi	s0,sp,128
 1de:	0c090503          	lb	a0,192(s2)
 1e2:	0100                	addi	s0,sp,128
 1e4:	0c090503          	lb	a0,192(s2)
 1e8:	0100                	addi	s0,sp,128
 1ea:	0c090503          	lb	a0,192(s2)
 1ee:	0100                	addi	s0,sp,128
 1f0:	0c090503          	lb	a0,192(s2)
 1f4:	0100                	addi	s0,sp,128
 1f6:	0c090503          	lb	a0,192(s2)
 1fa:	0100                	addi	s0,sp,128
 1fc:	0c090503          	lb	a0,192(s2)
 200:	0100                	addi	s0,sp,128
 202:	10090503          	lb	a0,256(s2)
 206:	0100                	addi	s0,sp,128
 208:	10090503          	lb	a0,256(s2)
 20c:	0100                	addi	s0,sp,128
 20e:	10090503          	lb	a0,256(s2)
 212:	0100                	addi	s0,sp,128
 214:	10090503          	lb	a0,256(s2)
 218:	0100                	addi	s0,sp,128
 21a:	10090503          	lb	a0,256(s2)
 21e:	0100                	addi	s0,sp,128
 220:	10090503          	lb	a0,256(s2)
 224:	0100                	addi	s0,sp,128
 226:	10090503          	lb	a0,256(s2)
 22a:	0100                	addi	s0,sp,128
 22c:	10090503          	lb	a0,256(s2)
 230:	0100                	addi	s0,sp,128
 232:	10090503          	lb	a0,256(s2)
 236:	0100                	addi	s0,sp,128
 238:	10090503          	lb	a0,256(s2)
 23c:	0100                	addi	s0,sp,128
 23e:	10090503          	lb	a0,256(s2)
 242:	0100                	addi	s0,sp,128
 244:	10090503          	lb	a0,256(s2)
 248:	0100                	addi	s0,sp,128
 24a:	10090503          	lb	a0,256(s2)
 24e:	0100                	addi	s0,sp,128
 250:	10090503          	lb	a0,256(s2)
 254:	0100                	addi	s0,sp,128
 256:	10090503          	lb	a0,256(s2)
 25a:	0100                	addi	s0,sp,128
 25c:	10090503          	lb	a0,256(s2)
 260:	0100                	addi	s0,sp,128
 262:	10090503          	lb	a0,256(s2)
 266:	0100                	addi	s0,sp,128
 268:	0c090503          	lb	a0,192(s2)
 26c:	0100                	addi	s0,sp,128
 26e:	0c090503          	lb	a0,192(s2)
 272:	0100                	addi	s0,sp,128
 274:	0c090503          	lb	a0,192(s2)
 278:	0100                	addi	s0,sp,128
 27a:	0c090503          	lb	a0,192(s2)
 27e:	0100                	addi	s0,sp,128
 280:	0c090503          	lb	a0,192(s2)
 284:	0100                	addi	s0,sp,128
 286:	0c090503          	lb	a0,192(s2)
 28a:	0100                	addi	s0,sp,128
 28c:	0c090503          	lb	a0,192(s2)
 290:	0100                	addi	s0,sp,128
 292:	0c090503          	lb	a0,192(s2)
 296:	0100                	addi	s0,sp,128
 298:	0c090503          	lb	a0,192(s2)
 29c:	0100                	addi	s0,sp,128
 29e:	0c090503          	lb	a0,192(s2)
 2a2:	0100                	addi	s0,sp,128
 2a4:	0c090503          	lb	a0,192(s2)
 2a8:	0100                	addi	s0,sp,128
 2aa:	0c090503          	lb	a0,192(s2)
 2ae:	0100                	addi	s0,sp,128
 2b0:	0c090503          	lb	a0,192(s2)
 2b4:	0100                	addi	s0,sp,128
 2b6:	0c090503          	lb	a0,192(s2)
 2ba:	0100                	addi	s0,sp,128
 2bc:	0c090503          	lb	a0,192(s2)
 2c0:	0100                	addi	s0,sp,128
 2c2:	0c090503          	lb	a0,192(s2)
 2c6:	0100                	addi	s0,sp,128
 2c8:	0c090503          	lb	a0,192(s2)
 2cc:	0100                	addi	s0,sp,128
 2ce:	0c090503          	lb	a0,192(s2)
 2d2:	0100                	addi	s0,sp,128
 2d4:	0c090503          	lb	a0,192(s2)
 2d8:	0100                	addi	s0,sp,128
 2da:	0c090503          	lb	a0,192(s2)
 2de:	0100                	addi	s0,sp,128
 2e0:	0c090503          	lb	a0,192(s2)
 2e4:	0100                	addi	s0,sp,128
 2e6:	0c090503          	lb	a0,192(s2)
 2ea:	0100                	addi	s0,sp,128
 2ec:	10090503          	lb	a0,256(s2)
 2f0:	0100                	addi	s0,sp,128
 2f2:	10090503          	lb	a0,256(s2)
 2f6:	0100                	addi	s0,sp,128
 2f8:	10090503          	lb	a0,256(s2)
 2fc:	0100                	addi	s0,sp,128
 2fe:	10090503          	lb	a0,256(s2)
 302:	0100                	addi	s0,sp,128
 304:	10090503          	lb	a0,256(s2)
 308:	0100                	addi	s0,sp,128
 30a:	10090503          	lb	a0,256(s2)
 30e:	0100                	addi	s0,sp,128
 310:	10090503          	lb	a0,256(s2)
 314:	0100                	addi	s0,sp,128
 316:	10090503          	lb	a0,256(s2)
 31a:	0100                	addi	s0,sp,128
 31c:	10090503          	lb	a0,256(s2)
 320:	0100                	addi	s0,sp,128
 322:	10090503          	lb	a0,256(s2)
 326:	0100                	addi	s0,sp,128
 328:	10090503          	lb	a0,256(s2)
 32c:	0100                	addi	s0,sp,128
 32e:	10090503          	lb	a0,256(s2)
 332:	0100                	addi	s0,sp,128
 334:	10090503          	lb	a0,256(s2)
 338:	0100                	addi	s0,sp,128
 33a:	10090503          	lb	a0,256(s2)
 33e:	0100                	addi	s0,sp,128
 340:	10090503          	lb	a0,256(s2)
 344:	0100                	addi	s0,sp,128
 346:	10090503          	lb	a0,256(s2)
 34a:	0100                	addi	s0,sp,128
 34c:	10090503          	lb	a0,256(s2)
 350:	0100                	addi	s0,sp,128
 352:	10090503          	lb	a0,256(s2)
 356:	0100                	addi	s0,sp,128
 358:	10090503          	lb	a0,256(s2)
 35c:	0100                	addi	s0,sp,128
 35e:	10090503          	lb	a0,256(s2)
 362:	0100                	addi	s0,sp,128
 364:	10090503          	lb	a0,256(s2)
 368:	0100                	addi	s0,sp,128
 36a:	10090503          	lb	a0,256(s2)
 36e:	0100                	addi	s0,sp,128
 370:	10090503          	lb	a0,256(s2)
 374:	0100                	addi	s0,sp,128
 376:	10090503          	lb	a0,256(s2)
 37a:	0100                	addi	s0,sp,128
 37c:	10090503          	lb	a0,256(s2)
 380:	0100                	addi	s0,sp,128
 382:	10090503          	lb	a0,256(s2)
 386:	0100                	addi	s0,sp,128
 388:	10090503          	lb	a0,256(s2)
 38c:	0100                	addi	s0,sp,128
 38e:	10090503          	lb	a0,256(s2)
 392:	0100                	addi	s0,sp,128
 394:	10090503          	lb	a0,256(s2)
 398:	0100                	addi	s0,sp,128
 39a:	10090503          	lb	a0,256(s2)
 39e:	0100                	addi	s0,sp,128
 3a0:	10090503          	lb	a0,256(s2)
 3a4:	0100                	addi	s0,sp,128
 3a6:	10090503          	lb	a0,256(s2)
 3aa:	0100                	addi	s0,sp,128
 3ac:	10090503          	lb	a0,256(s2)
 3b0:	0100                	addi	s0,sp,128
 3b2:	10090503          	lb	a0,256(s2)
 3b6:	0100                	addi	s0,sp,128
 3b8:	10090503          	lb	a0,256(s2)
 3bc:	0100                	addi	s0,sp,128
 3be:	10090503          	lb	a0,256(s2)
 3c2:	0100                	addi	s0,sp,128
 3c4:	10090503          	lb	a0,256(s2)
 3c8:	0100                	addi	s0,sp,128
 3ca:	10090503          	lb	a0,256(s2)
 3ce:	0100                	addi	s0,sp,128
 3d0:	10090503          	lb	a0,256(s2)
 3d4:	0100                	addi	s0,sp,128
 3d6:	10090503          	lb	a0,256(s2)
 3da:	0100                	addi	s0,sp,128
 3dc:	10090503          	lb	a0,256(s2)
 3e0:	0100                	addi	s0,sp,128
 3e2:	10090503          	lb	a0,256(s2)
 3e6:	0100                	addi	s0,sp,128
 3e8:	10090503          	lb	a0,256(s2)
 3ec:	0100                	addi	s0,sp,128
 3ee:	10090503          	lb	a0,256(s2)
 3f2:	0100                	addi	s0,sp,128
 3f4:	0c090503          	lb	a0,192(s2)
 3f8:	0100                	addi	s0,sp,128
 3fa:	0c090503          	lb	a0,192(s2)
 3fe:	0100                	addi	s0,sp,128
 400:	0c090503          	lb	a0,192(s2)
 404:	0100                	addi	s0,sp,128
 406:	0c090503          	lb	a0,192(s2)
 40a:	0100                	addi	s0,sp,128
 40c:	0c090503          	lb	a0,192(s2)
 410:	0100                	addi	s0,sp,128
 412:	0c090503          	lb	a0,192(s2)
 416:	0100                	addi	s0,sp,128
 418:	0c090503          	lb	a0,192(s2)
 41c:	0100                	addi	s0,sp,128
 41e:	0c090503          	lb	a0,192(s2)
 422:	0100                	addi	s0,sp,128
 424:	0c090503          	lb	a0,192(s2)
 428:	0100                	addi	s0,sp,128
 42a:	0c090503          	lb	a0,192(s2)
 42e:	0100                	addi	s0,sp,128
 430:	0c090503          	lb	a0,192(s2)
 434:	0100                	addi	s0,sp,128
 436:	0c090503          	lb	a0,192(s2)
 43a:	0100                	addi	s0,sp,128
 43c:	0c090503          	lb	a0,192(s2)
 440:	0100                	addi	s0,sp,128
 442:	0c090503          	lb	a0,192(s2)
 446:	0100                	addi	s0,sp,128
 448:	0c090503          	lb	a0,192(s2)
 44c:	0100                	addi	s0,sp,128
 44e:	0c090503          	lb	a0,192(s2)
 452:	0100                	addi	s0,sp,128
 454:	0c090503          	lb	a0,192(s2)
 458:	0100                	addi	s0,sp,128
 45a:	0c090503          	lb	a0,192(s2)
 45e:	0100                	addi	s0,sp,128
 460:	0c090503          	lb	a0,192(s2)
 464:	0100                	addi	s0,sp,128
 466:	0c090503          	lb	a0,192(s2)
 46a:	0100                	addi	s0,sp,128
 46c:	0c090503          	lb	a0,192(s2)
 470:	0100                	addi	s0,sp,128
 472:	0c090503          	lb	a0,192(s2)
 476:	0100                	addi	s0,sp,128
 478:	10090503          	lb	a0,256(s2)
 47c:	0100                	addi	s0,sp,128
 47e:	10090503          	lb	a0,256(s2)
 482:	0100                	addi	s0,sp,128
 484:	10090503          	lb	a0,256(s2)
 488:	0100                	addi	s0,sp,128
 48a:	10090503          	lb	a0,256(s2)
 48e:	0100                	addi	s0,sp,128
 490:	10090503          	lb	a0,256(s2)
 494:	0100                	addi	s0,sp,128
 496:	10090503          	lb	a0,256(s2)
 49a:	0100                	addi	s0,sp,128
 49c:	10090503          	lb	a0,256(s2)
 4a0:	0100                	addi	s0,sp,128
 4a2:	10090503          	lb	a0,256(s2)
 4a6:	0100                	addi	s0,sp,128
 4a8:	10090503          	lb	a0,256(s2)
 4ac:	0100                	addi	s0,sp,128
 4ae:	10090503          	lb	a0,256(s2)
 4b2:	0100                	addi	s0,sp,128
 4b4:	10090503          	lb	a0,256(s2)
 4b8:	0100                	addi	s0,sp,128
 4ba:	10090503          	lb	a0,256(s2)
 4be:	0100                	addi	s0,sp,128
 4c0:	10090503          	lb	a0,256(s2)
 4c4:	0100                	addi	s0,sp,128
 4c6:	10090503          	lb	a0,256(s2)
 4ca:	0100                	addi	s0,sp,128
 4cc:	10090503          	lb	a0,256(s2)
 4d0:	0100                	addi	s0,sp,128
 4d2:	10090503          	lb	a0,256(s2)
 4d6:	0100                	addi	s0,sp,128
 4d8:	10090503          	lb	a0,256(s2)
 4dc:	0100                	addi	s0,sp,128
 4de:	10090503          	lb	a0,256(s2)
 4e2:	0100                	addi	s0,sp,128
 4e4:	10090503          	lb	a0,256(s2)
 4e8:	0100                	addi	s0,sp,128
 4ea:	10090503          	lb	a0,256(s2)
 4ee:	0100                	addi	s0,sp,128
 4f0:	10090503          	lb	a0,256(s2)
 4f4:	0100                	addi	s0,sp,128
 4f6:	10090503          	lb	a0,256(s2)
 4fa:	0100                	addi	s0,sp,128
 4fc:	10090503          	lb	a0,256(s2)
 500:	0100                	addi	s0,sp,128
 502:	10090503          	lb	a0,256(s2)
 506:	0100                	addi	s0,sp,128
 508:	10090503          	lb	a0,256(s2)
 50c:	0100                	addi	s0,sp,128
 50e:	10090503          	lb	a0,256(s2)
 512:	0100                	addi	s0,sp,128
 514:	10090503          	lb	a0,256(s2)
 518:	0100                	addi	s0,sp,128
 51a:	10090503          	lb	a0,256(s2)
 51e:	0100                	addi	s0,sp,128
 520:	10090503          	lb	a0,256(s2)
 524:	0100                	addi	s0,sp,128
 526:	10090503          	lb	a0,256(s2)
 52a:	0100                	addi	s0,sp,128
 52c:	10090503          	lb	a0,256(s2)
 530:	0100                	addi	s0,sp,128
 532:	10090503          	lb	a0,256(s2)
 536:	0100                	addi	s0,sp,128
 538:	10090503          	lb	a0,256(s2)
 53c:	0100                	addi	s0,sp,128
 53e:	10090503          	lb	a0,256(s2)
 542:	0100                	addi	s0,sp,128
 544:	10090503          	lb	a0,256(s2)
 548:	0100                	addi	s0,sp,128
 54a:	10090503          	lb	a0,256(s2)
 54e:	0100                	addi	s0,sp,128
 550:	10090503          	lb	a0,256(s2)
 554:	0100                	addi	s0,sp,128
 556:	10090503          	lb	a0,256(s2)
 55a:	0100                	addi	s0,sp,128
 55c:	10090503          	lb	a0,256(s2)
 560:	0100                	addi	s0,sp,128
 562:	10090503          	lb	a0,256(s2)
 566:	0100                	addi	s0,sp,128
 568:	10090503          	lb	a0,256(s2)
 56c:	0100                	addi	s0,sp,128
 56e:	10090503          	lb	a0,256(s2)
 572:	0100                	addi	s0,sp,128
 574:	10090503          	lb	a0,256(s2)
 578:	0100                	addi	s0,sp,128
 57a:	10090503          	lb	a0,256(s2)
 57e:	0100                	addi	s0,sp,128
 580:	10090503          	lb	a0,256(s2)
 584:	0100                	addi	s0,sp,128
 586:	10090503          	lb	a0,256(s2)
 58a:	0100                	addi	s0,sp,128
 58c:	10090503          	lb	a0,256(s2)
 590:	0100                	addi	s0,sp,128
 592:	10090503          	lb	a0,256(s2)
 596:	0100                	addi	s0,sp,128
 598:	10090503          	lb	a0,256(s2)
 59c:	0100                	addi	s0,sp,128
 59e:	10090503          	lb	a0,256(s2)
 5a2:	0100                	addi	s0,sp,128
 5a4:	10090503          	lb	a0,256(s2)
 5a8:	0100                	addi	s0,sp,128
 5aa:	10090503          	lb	a0,256(s2)
 5ae:	0100                	addi	s0,sp,128
 5b0:	10090503          	lb	a0,256(s2)
 5b4:	0100                	addi	s0,sp,128
 5b6:	10090503          	lb	a0,256(s2)
 5ba:	0100                	addi	s0,sp,128
 5bc:	10090503          	lb	a0,256(s2)
 5c0:	0100                	addi	s0,sp,128
 5c2:	10090503          	lb	a0,256(s2)
 5c6:	0100                	addi	s0,sp,128
 5c8:	10090503          	lb	a0,256(s2)
 5cc:	0100                	addi	s0,sp,128
 5ce:	10090503          	lb	a0,256(s2)
 5d2:	0100                	addi	s0,sp,128
 5d4:	10090503          	lb	a0,256(s2)
 5d8:	0100                	addi	s0,sp,128
 5da:	10090503          	lb	a0,256(s2)
 5de:	0100                	addi	s0,sp,128
 5e0:	10090503          	lb	a0,256(s2)
 5e4:	0100                	addi	s0,sp,128
 5e6:	10090503          	lb	a0,256(s2)
 5ea:	0100                	addi	s0,sp,128
 5ec:	10090503          	lb	a0,256(s2)
 5f0:	0100                	addi	s0,sp,128
 5f2:	10090503          	lb	a0,256(s2)
 5f6:	0100                	addi	s0,sp,128
 5f8:	10090503          	lb	a0,256(s2)
 5fc:	0100                	addi	s0,sp,128
 5fe:	10090503          	lb	a0,256(s2)
 602:	0100                	addi	s0,sp,128
 604:	10090503          	lb	a0,256(s2)
 608:	0100                	addi	s0,sp,128
 60a:	10090503          	lb	a0,256(s2)
 60e:	0100                	addi	s0,sp,128
 610:	10090503          	lb	a0,256(s2)
 614:	0100                	addi	s0,sp,128
 616:	10090503          	lb	a0,256(s2)
 61a:	0100                	addi	s0,sp,128
 61c:	10090503          	lb	a0,256(s2)
 620:	0100                	addi	s0,sp,128
 622:	10090503          	lb	a0,256(s2)
 626:	0100                	addi	s0,sp,128
 628:	10090503          	lb	a0,256(s2)
 62c:	0100                	addi	s0,sp,128
 62e:	10090503          	lb	a0,256(s2)
 632:	0100                	addi	s0,sp,128
 634:	10090503          	lb	a0,256(s2)
 638:	0100                	addi	s0,sp,128
 63a:	10090503          	lb	a0,256(s2)
 63e:	0100                	addi	s0,sp,128
 640:	10090503          	lb	a0,256(s2)
 644:	0100                	addi	s0,sp,128
 646:	10090503          	lb	a0,256(s2)
 64a:	0100                	addi	s0,sp,128
 64c:	10090503          	lb	a0,256(s2)
 650:	0100                	addi	s0,sp,128
 652:	10090503          	lb	a0,256(s2)
 656:	0100                	addi	s0,sp,128
 658:	10090503          	lb	a0,256(s2)
 65c:	0100                	addi	s0,sp,128
 65e:	10090503          	lb	a0,256(s2)
 662:	0100                	addi	s0,sp,128
 664:	10090503          	lb	a0,256(s2)
 668:	0100                	addi	s0,sp,128
 66a:	10090503          	lb	a0,256(s2)
 66e:	0100                	addi	s0,sp,128
 670:	10090503          	lb	a0,256(s2)
 674:	0100                	addi	s0,sp,128
 676:	10090503          	lb	a0,256(s2)
 67a:	0100                	addi	s0,sp,128
 67c:	10090503          	lb	a0,256(s2)
 680:	0100                	addi	s0,sp,128
 682:	0c090503          	lb	a0,192(s2)
 686:	0100                	addi	s0,sp,128
 688:	0c090503          	lb	a0,192(s2)
 68c:	0100                	addi	s0,sp,128
 68e:	0c090503          	lb	a0,192(s2)
 692:	0100                	addi	s0,sp,128
 694:	0c090503          	lb	a0,192(s2)
 698:	0100                	addi	s0,sp,128
 69a:	0c090503          	lb	a0,192(s2)
 69e:	0100                	addi	s0,sp,128
 6a0:	0c090503          	lb	a0,192(s2)
 6a4:	0100                	addi	s0,sp,128
 6a6:	0c090503          	lb	a0,192(s2)
 6aa:	0100                	addi	s0,sp,128
 6ac:	0c090503          	lb	a0,192(s2)
 6b0:	0100                	addi	s0,sp,128
 6b2:	0c090503          	lb	a0,192(s2)
 6b6:	0100                	addi	s0,sp,128
 6b8:	0c090503          	lb	a0,192(s2)
 6bc:	0100                	addi	s0,sp,128
 6be:	0c090503          	lb	a0,192(s2)
 6c2:	0100                	addi	s0,sp,128
 6c4:	0c090503          	lb	a0,192(s2)
 6c8:	0100                	addi	s0,sp,128
 6ca:	0c090503          	lb	a0,192(s2)
 6ce:	0100                	addi	s0,sp,128
 6d0:	0c090503          	lb	a0,192(s2)
 6d4:	0100                	addi	s0,sp,128
 6d6:	0c090503          	lb	a0,192(s2)
 6da:	0100                	addi	s0,sp,128
 6dc:	0c090503          	lb	a0,192(s2)
 6e0:	0100                	addi	s0,sp,128
 6e2:	0c090503          	lb	a0,192(s2)
 6e6:	0100                	addi	s0,sp,128
 6e8:	0c090503          	lb	a0,192(s2)
 6ec:	0100                	addi	s0,sp,128
 6ee:	0c090503          	lb	a0,192(s2)
 6f2:	0100                	addi	s0,sp,128
 6f4:	0c090503          	lb	a0,192(s2)
 6f8:	0100                	addi	s0,sp,128
 6fa:	0c090503          	lb	a0,192(s2)
 6fe:	0100                	addi	s0,sp,128
 700:	0c090503          	lb	a0,192(s2)
 704:	0100                	addi	s0,sp,128
 706:	10090503          	lb	a0,256(s2)
 70a:	0100                	addi	s0,sp,128
 70c:	10090503          	lb	a0,256(s2)
 710:	0100                	addi	s0,sp,128
 712:	10090503          	lb	a0,256(s2)
 716:	0100                	addi	s0,sp,128
 718:	10090503          	lb	a0,256(s2)
 71c:	0100                	addi	s0,sp,128
 71e:	10090503          	lb	a0,256(s2)
 722:	0100                	addi	s0,sp,128
 724:	10090503          	lb	a0,256(s2)
 728:	0100                	addi	s0,sp,128
 72a:	10090503          	lb	a0,256(s2)
 72e:	0100                	addi	s0,sp,128
 730:	10090503          	lb	a0,256(s2)
 734:	0100                	addi	s0,sp,128
 736:	10090503          	lb	a0,256(s2)
 73a:	0100                	addi	s0,sp,128
 73c:	10090503          	lb	a0,256(s2)
 740:	0100                	addi	s0,sp,128
 742:	10090503          	lb	a0,256(s2)
 746:	0100                	addi	s0,sp,128
 748:	10090503          	lb	a0,256(s2)
 74c:	0100                	addi	s0,sp,128
 74e:	10090503          	lb	a0,256(s2)
 752:	0100                	addi	s0,sp,128
 754:	10090503          	lb	a0,256(s2)
 758:	0100                	addi	s0,sp,128
 75a:	10090503          	lb	a0,256(s2)
 75e:	0100                	addi	s0,sp,128
 760:	10090503          	lb	a0,256(s2)
 764:	0100                	addi	s0,sp,128
 766:	10090503          	lb	a0,256(s2)
 76a:	0100                	addi	s0,sp,128
 76c:	10090503          	lb	a0,256(s2)
 770:	0100                	addi	s0,sp,128
 772:	10090503          	lb	a0,256(s2)
 776:	0100                	addi	s0,sp,128
 778:	10090503          	lb	a0,256(s2)
 77c:	0100                	addi	s0,sp,128
 77e:	10090503          	lb	a0,256(s2)
 782:	0100                	addi	s0,sp,128
 784:	10090503          	lb	a0,256(s2)
 788:	0100                	addi	s0,sp,128
 78a:	0c090503          	lb	a0,192(s2)
 78e:	0100                	addi	s0,sp,128
 790:	0c090503          	lb	a0,192(s2)
 794:	0100                	addi	s0,sp,128
 796:	0c090503          	lb	a0,192(s2)
 79a:	0100                	addi	s0,sp,128
 79c:	0c090503          	lb	a0,192(s2)
 7a0:	0100                	addi	s0,sp,128
 7a2:	0c090503          	lb	a0,192(s2)
 7a6:	0100                	addi	s0,sp,128
 7a8:	0c090503          	lb	a0,192(s2)
 7ac:	0100                	addi	s0,sp,128
 7ae:	0c090503          	lb	a0,192(s2)
 7b2:	0100                	addi	s0,sp,128
 7b4:	10090503          	lb	a0,256(s2)
 7b8:	0100                	addi	s0,sp,128
 7ba:	10090503          	lb	a0,256(s2)
 7be:	0100                	addi	s0,sp,128
 7c0:	10090503          	lb	a0,256(s2)
 7c4:	0100                	addi	s0,sp,128
 7c6:	10090503          	lb	a0,256(s2)
 7ca:	0100                	addi	s0,sp,128
 7cc:	10090503          	lb	a0,256(s2)
 7d0:	0100                	addi	s0,sp,128
 7d2:	10090503          	lb	a0,256(s2)
 7d6:	0100                	addi	s0,sp,128
 7d8:	10090503          	lb	a0,256(s2)
 7dc:	0100                	addi	s0,sp,128
 7de:	10090503          	lb	a0,256(s2)
 7e2:	0100                	addi	s0,sp,128
 7e4:	10090503          	lb	a0,256(s2)
 7e8:	0100                	addi	s0,sp,128
 7ea:	10090503          	lb	a0,256(s2)
 7ee:	0100                	addi	s0,sp,128
 7f0:	10090503          	lb	a0,256(s2)
 7f4:	0100                	addi	s0,sp,128
 7f6:	10090503          	lb	a0,256(s2)
 7fa:	0100                	addi	s0,sp,128
 7fc:	10090503          	lb	a0,256(s2)
 800:	0100                	addi	s0,sp,128
 802:	10090503          	lb	a0,256(s2)
 806:	0100                	addi	s0,sp,128
 808:	10090503          	lb	a0,256(s2)
 80c:	0100                	addi	s0,sp,128
 80e:	10090503          	lb	a0,256(s2)
 812:	0100                	addi	s0,sp,128
 814:	10090503          	lb	a0,256(s2)
 818:	0100                	addi	s0,sp,128
 81a:	10090503          	lb	a0,256(s2)
 81e:	0100                	addi	s0,sp,128
 820:	10090503          	lb	a0,256(s2)
 824:	0100                	addi	s0,sp,128
 826:	10090503          	lb	a0,256(s2)
 82a:	0100                	addi	s0,sp,128
 82c:	10090503          	lb	a0,256(s2)
 830:	0100                	addi	s0,sp,128
 832:	10090503          	lb	a0,256(s2)
 836:	0100                	addi	s0,sp,128
 838:	10090503          	lb	a0,256(s2)
 83c:	0100                	addi	s0,sp,128
 83e:	10090503          	lb	a0,256(s2)
 842:	0100                	addi	s0,sp,128
 844:	10090503          	lb	a0,256(s2)
 848:	0100                	addi	s0,sp,128
 84a:	10090503          	lb	a0,256(s2)
 84e:	0100                	addi	s0,sp,128
 850:	10090503          	lb	a0,256(s2)
 854:	0100                	addi	s0,sp,128
 856:	10090503          	lb	a0,256(s2)
 85a:	0100                	addi	s0,sp,128
 85c:	10090503          	lb	a0,256(s2)
 860:	0100                	addi	s0,sp,128
 862:	10090503          	lb	a0,256(s2)
 866:	0100                	addi	s0,sp,128
 868:	10090503          	lb	a0,256(s2)
 86c:	0100                	addi	s0,sp,128
 86e:	10090503          	lb	a0,256(s2)
 872:	0100                	addi	s0,sp,128
 874:	10090503          	lb	a0,256(s2)
 878:	0100                	addi	s0,sp,128
 87a:	10090503          	lb	a0,256(s2)
 87e:	0100                	addi	s0,sp,128
 880:	10090503          	lb	a0,256(s2)
 884:	0100                	addi	s0,sp,128
 886:	10090503          	lb	a0,256(s2)
 88a:	0100                	addi	s0,sp,128
 88c:	10090503          	lb	a0,256(s2)
 890:	0100                	addi	s0,sp,128
 892:	10090503          	lb	a0,256(s2)
 896:	0100                	addi	s0,sp,128
 898:	10090503          	lb	a0,256(s2)
 89c:	0100                	addi	s0,sp,128
 89e:	10090503          	lb	a0,256(s2)
 8a2:	0100                	addi	s0,sp,128
 8a4:	10090503          	lb	a0,256(s2)
 8a8:	0100                	addi	s0,sp,128
 8aa:	10090503          	lb	a0,256(s2)
 8ae:	0100                	addi	s0,sp,128
 8b0:	10090503          	lb	a0,256(s2)
 8b4:	0100                	addi	s0,sp,128
 8b6:	10090503          	lb	a0,256(s2)
 8ba:	0100                	addi	s0,sp,128
 8bc:	10090503          	lb	a0,256(s2)
 8c0:	0100                	addi	s0,sp,128
 8c2:	10090503          	lb	a0,256(s2)
 8c6:	0100                	addi	s0,sp,128
 8c8:	10090503          	lb	a0,256(s2)
 8cc:	0100                	addi	s0,sp,128
 8ce:	10090503          	lb	a0,256(s2)
 8d2:	0100                	addi	s0,sp,128
 8d4:	10090503          	lb	a0,256(s2)
 8d8:	0100                	addi	s0,sp,128
 8da:	10090503          	lb	a0,256(s2)
 8de:	0100                	addi	s0,sp,128
 8e0:	10090503          	lb	a0,256(s2)
 8e4:	0100                	addi	s0,sp,128
 8e6:	10090503          	lb	a0,256(s2)
 8ea:	0100                	addi	s0,sp,128
 8ec:	10090503          	lb	a0,256(s2)
 8f0:	0100                	addi	s0,sp,128
 8f2:	10090503          	lb	a0,256(s2)
 8f6:	0100                	addi	s0,sp,128
 8f8:	10090503          	lb	a0,256(s2)
 8fc:	0100                	addi	s0,sp,128
 8fe:	10090503          	lb	a0,256(s2)
 902:	0100                	addi	s0,sp,128
 904:	10090503          	lb	a0,256(s2)
 908:	0100                	addi	s0,sp,128
 90a:	10090503          	lb	a0,256(s2)
 90e:	0100                	addi	s0,sp,128
 910:	10090503          	lb	a0,256(s2)
 914:	0100                	addi	s0,sp,128
 916:	10090503          	lb	a0,256(s2)
 91a:	0100                	addi	s0,sp,128
 91c:	10090503          	lb	a0,256(s2)
 920:	0100                	addi	s0,sp,128
 922:	10090503          	lb	a0,256(s2)
 926:	0100                	addi	s0,sp,128
 928:	10090503          	lb	a0,256(s2)
 92c:	0100                	addi	s0,sp,128
 92e:	10090503          	lb	a0,256(s2)
 932:	0100                	addi	s0,sp,128
 934:	10090503          	lb	a0,256(s2)
 938:	0100                	addi	s0,sp,128
 93a:	10090503          	lb	a0,256(s2)
 93e:	0100                	addi	s0,sp,128
 940:	10090503          	lb	a0,256(s2)
 944:	0100                	addi	s0,sp,128
 946:	10090503          	lb	a0,256(s2)
 94a:	0100                	addi	s0,sp,128
 94c:	10090503          	lb	a0,256(s2)
 950:	0100                	addi	s0,sp,128
 952:	10090503          	lb	a0,256(s2)
 956:	0100                	addi	s0,sp,128
 958:	10090503          	lb	a0,256(s2)
 95c:	0100                	addi	s0,sp,128
 95e:	10090503          	lb	a0,256(s2)
 962:	0100                	addi	s0,sp,128
 964:	10090503          	lb	a0,256(s2)
 968:	0100                	addi	s0,sp,128
 96a:	10090503          	lb	a0,256(s2)
 96e:	0100                	addi	s0,sp,128
 970:	10090503          	lb	a0,256(s2)
 974:	0100                	addi	s0,sp,128
 976:	10090503          	lb	a0,256(s2)
 97a:	0100                	addi	s0,sp,128
 97c:	0c090503          	lb	a0,192(s2)
 980:	0100                	addi	s0,sp,128
 982:	0c090503          	lb	a0,192(s2)
 986:	0100                	addi	s0,sp,128
 988:	0c090503          	lb	a0,192(s2)
 98c:	0100                	addi	s0,sp,128
 98e:	0c090503          	lb	a0,192(s2)
 992:	0100                	addi	s0,sp,128
 994:	0c090503          	lb	a0,192(s2)
 998:	0100                	addi	s0,sp,128
 99a:	0c090503          	lb	a0,192(s2)
 99e:	0100                	addi	s0,sp,128
 9a0:	0c090503          	lb	a0,192(s2)
 9a4:	0100                	addi	s0,sp,128
 9a6:	0c090503          	lb	a0,192(s2)
 9aa:	0100                	addi	s0,sp,128
 9ac:	0c090503          	lb	a0,192(s2)
 9b0:	0100                	addi	s0,sp,128
 9b2:	0c090503          	lb	a0,192(s2)
 9b6:	0100                	addi	s0,sp,128
 9b8:	0c090503          	lb	a0,192(s2)
 9bc:	0100                	addi	s0,sp,128
 9be:	0c090503          	lb	a0,192(s2)
 9c2:	0100                	addi	s0,sp,128
 9c4:	0c090503          	lb	a0,192(s2)
 9c8:	0100                	addi	s0,sp,128
 9ca:	0c090503          	lb	a0,192(s2)
 9ce:	0100                	addi	s0,sp,128
 9d0:	0c090503          	lb	a0,192(s2)
 9d4:	0100                	addi	s0,sp,128
 9d6:	0c090503          	lb	a0,192(s2)
 9da:	0100                	addi	s0,sp,128
 9dc:	0c090503          	lb	a0,192(s2)
 9e0:	0100                	addi	s0,sp,128
 9e2:	0c090503          	lb	a0,192(s2)
 9e6:	0100                	addi	s0,sp,128
 9e8:	0c090503          	lb	a0,192(s2)
 9ec:	0100                	addi	s0,sp,128
 9ee:	0c090503          	lb	a0,192(s2)
 9f2:	0100                	addi	s0,sp,128
 9f4:	0c090503          	lb	a0,192(s2)
 9f8:	0100                	addi	s0,sp,128
 9fa:	0c090503          	lb	a0,192(s2)
 9fe:	0100                	addi	s0,sp,128
 a00:	0c090503          	lb	a0,192(s2)
 a04:	0100                	addi	s0,sp,128
 a06:	0c090503          	lb	a0,192(s2)
 a0a:	0100                	addi	s0,sp,128
 a0c:	0c090503          	lb	a0,192(s2)
 a10:	0100                	addi	s0,sp,128
 a12:	0c090503          	lb	a0,192(s2)
 a16:	0100                	addi	s0,sp,128
 a18:	0c090503          	lb	a0,192(s2)
 a1c:	0100                	addi	s0,sp,128
 a1e:	0c090503          	lb	a0,192(s2)
 a22:	0100                	addi	s0,sp,128
 a24:	0c090503          	lb	a0,192(s2)
 a28:	0100                	addi	s0,sp,128
 a2a:	0c090503          	lb	a0,192(s2)
 a2e:	0100                	addi	s0,sp,128
 a30:	0c090503          	lb	a0,192(s2)
 a34:	0100                	addi	s0,sp,128
 a36:	0c090503          	lb	a0,192(s2)
 a3a:	0100                	addi	s0,sp,128
 a3c:	0c090503          	lb	a0,192(s2)
 a40:	0100                	addi	s0,sp,128
 a42:	0c090503          	lb	a0,192(s2)
 a46:	0100                	addi	s0,sp,128
 a48:	0c090503          	lb	a0,192(s2)
 a4c:	0100                	addi	s0,sp,128
 a4e:	10090503          	lb	a0,256(s2)
 a52:	0100                	addi	s0,sp,128
 a54:	10090503          	lb	a0,256(s2)
 a58:	0100                	addi	s0,sp,128
 a5a:	10090503          	lb	a0,256(s2)
 a5e:	0100                	addi	s0,sp,128
 a60:	10090503          	lb	a0,256(s2)
 a64:	0100                	addi	s0,sp,128
 a66:	10090503          	lb	a0,256(s2)
 a6a:	0100                	addi	s0,sp,128
 a6c:	10090503          	lb	a0,256(s2)
 a70:	0100                	addi	s0,sp,128
 a72:	10090503          	lb	a0,256(s2)
 a76:	0100                	addi	s0,sp,128
 a78:	10090503          	lb	a0,256(s2)
 a7c:	0100                	addi	s0,sp,128
 a7e:	10090503          	lb	a0,256(s2)
 a82:	0100                	addi	s0,sp,128
 a84:	10090503          	lb	a0,256(s2)
 a88:	0100                	addi	s0,sp,128
 a8a:	10090503          	lb	a0,256(s2)
 a8e:	0100                	addi	s0,sp,128
 a90:	10090503          	lb	a0,256(s2)
 a94:	0100                	addi	s0,sp,128
 a96:	10090503          	lb	a0,256(s2)
 a9a:	0100                	addi	s0,sp,128
 a9c:	10090503          	lb	a0,256(s2)
 aa0:	0100                	addi	s0,sp,128
 aa2:	10090503          	lb	a0,256(s2)
 aa6:	0100                	addi	s0,sp,128
 aa8:	10090503          	lb	a0,256(s2)
 aac:	0100                	addi	s0,sp,128
 aae:	10090503          	lb	a0,256(s2)
 ab2:	0100                	addi	s0,sp,128
 ab4:	10090503          	lb	a0,256(s2)
 ab8:	0100                	addi	s0,sp,128
 aba:	10090503          	lb	a0,256(s2)
 abe:	0100                	addi	s0,sp,128
 ac0:	10090503          	lb	a0,256(s2)
 ac4:	0100                	addi	s0,sp,128
 ac6:	10090503          	lb	a0,256(s2)
 aca:	0100                	addi	s0,sp,128
 acc:	10090503          	lb	a0,256(s2)
 ad0:	0100                	addi	s0,sp,128
 ad2:	10090503          	lb	a0,256(s2)
 ad6:	0100                	addi	s0,sp,128
 ad8:	10090503          	lb	a0,256(s2)
 adc:	0100                	addi	s0,sp,128
 ade:	10090503          	lb	a0,256(s2)
 ae2:	0100                	addi	s0,sp,128
 ae4:	10090503          	lb	a0,256(s2)
 ae8:	0100                	addi	s0,sp,128
 aea:	10090503          	lb	a0,256(s2)
 aee:	0100                	addi	s0,sp,128
 af0:	10090503          	lb	a0,256(s2)
 af4:	0100                	addi	s0,sp,128
 af6:	10090503          	lb	a0,256(s2)
 afa:	0100                	addi	s0,sp,128
 afc:	10090503          	lb	a0,256(s2)
 b00:	0100                	addi	s0,sp,128
 b02:	10090503          	lb	a0,256(s2)
 b06:	0100                	addi	s0,sp,128
 b08:	10090503          	lb	a0,256(s2)
 b0c:	0100                	addi	s0,sp,128
 b0e:	10090503          	lb	a0,256(s2)
 b12:	0100                	addi	s0,sp,128
 b14:	10090503          	lb	a0,256(s2)
 b18:	0100                	addi	s0,sp,128
 b1a:	10090503          	lb	a0,256(s2)
 b1e:	0100                	addi	s0,sp,128
 b20:	10090503          	lb	a0,256(s2)
 b24:	0100                	addi	s0,sp,128
 b26:	10090503          	lb	a0,256(s2)
 b2a:	0100                	addi	s0,sp,128
 b2c:	10090503          	lb	a0,256(s2)
 b30:	0100                	addi	s0,sp,128
 b32:	10090503          	lb	a0,256(s2)
 b36:	0100                	addi	s0,sp,128
 b38:	10090503          	lb	a0,256(s2)
 b3c:	0100                	addi	s0,sp,128
 b3e:	10090503          	lb	a0,256(s2)
 b42:	0100                	addi	s0,sp,128
 b44:	10090503          	lb	a0,256(s2)
 b48:	0100                	addi	s0,sp,128
 b4a:	10090503          	lb	a0,256(s2)
 b4e:	0100                	addi	s0,sp,128
 b50:	10090503          	lb	a0,256(s2)
 b54:	0100                	addi	s0,sp,128
 b56:	10090503          	lb	a0,256(s2)
 b5a:	0100                	addi	s0,sp,128
 b5c:	10090503          	lb	a0,256(s2)
 b60:	0100                	addi	s0,sp,128
 b62:	10090503          	lb	a0,256(s2)
 b66:	0100                	addi	s0,sp,128
 b68:	10090503          	lb	a0,256(s2)
 b6c:	0100                	addi	s0,sp,128
 b6e:	10090503          	lb	a0,256(s2)
 b72:	0100                	addi	s0,sp,128
 b74:	10090503          	lb	a0,256(s2)
 b78:	0100                	addi	s0,sp,128
 b7a:	10090503          	lb	a0,256(s2)
 b7e:	0100                	addi	s0,sp,128
 b80:	10090503          	lb	a0,256(s2)
 b84:	0100                	addi	s0,sp,128
 b86:	10090503          	lb	a0,256(s2)
 b8a:	0100                	addi	s0,sp,128
 b8c:	10090503          	lb	a0,256(s2)
 b90:	0100                	addi	s0,sp,128
 b92:	10090503          	lb	a0,256(s2)
 b96:	0100                	addi	s0,sp,128
 b98:	10090503          	lb	a0,256(s2)
 b9c:	0100                	addi	s0,sp,128
 b9e:	10090503          	lb	a0,256(s2)
 ba2:	0100                	addi	s0,sp,128
 ba4:	10090503          	lb	a0,256(s2)
 ba8:	0100                	addi	s0,sp,128
 baa:	10090503          	lb	a0,256(s2)
 bae:	0100                	addi	s0,sp,128
 bb0:	10090503          	lb	a0,256(s2)
 bb4:	0100                	addi	s0,sp,128
 bb6:	10090503          	lb	a0,256(s2)
 bba:	0100                	addi	s0,sp,128
 bbc:	10090503          	lb	a0,256(s2)
 bc0:	0100                	addi	s0,sp,128
 bc2:	10090503          	lb	a0,256(s2)
 bc6:	0100                	addi	s0,sp,128
 bc8:	10090503          	lb	a0,256(s2)
 bcc:	0100                	addi	s0,sp,128
 bce:	10090503          	lb	a0,256(s2)
 bd2:	0100                	addi	s0,sp,128
 bd4:	10090503          	lb	a0,256(s2)
 bd8:	0100                	addi	s0,sp,128
 bda:	10090503          	lb	a0,256(s2)
 bde:	0100                	addi	s0,sp,128
 be0:	10090503          	lb	a0,256(s2)
 be4:	0100                	addi	s0,sp,128
 be6:	10090503          	lb	a0,256(s2)
 bea:	0100                	addi	s0,sp,128
 bec:	10090503          	lb	a0,256(s2)
 bf0:	0100                	addi	s0,sp,128
 bf2:	10090503          	lb	a0,256(s2)
 bf6:	0100                	addi	s0,sp,128
 bf8:	10090503          	lb	a0,256(s2)
 bfc:	0100                	addi	s0,sp,128
 bfe:	10090503          	lb	a0,256(s2)
 c02:	0100                	addi	s0,sp,128
 c04:	10090503          	lb	a0,256(s2)
 c08:	0100                	addi	s0,sp,128
 c0a:	10090503          	lb	a0,256(s2)
 c0e:	0100                	addi	s0,sp,128
 c10:	10090503          	lb	a0,256(s2)
 c14:	0100                	addi	s0,sp,128
 c16:	10090503          	lb	a0,256(s2)
 c1a:	0100                	addi	s0,sp,128
 c1c:	10090503          	lb	a0,256(s2)
 c20:	0100                	addi	s0,sp,128
 c22:	10090503          	lb	a0,256(s2)
 c26:	0100                	addi	s0,sp,128
 c28:	10090503          	lb	a0,256(s2)
 c2c:	0100                	addi	s0,sp,128
 c2e:	10090503          	lb	a0,256(s2)
 c32:	0100                	addi	s0,sp,128
 c34:	10090503          	lb	a0,256(s2)
 c38:	0100                	addi	s0,sp,128
 c3a:	10090503          	lb	a0,256(s2)
 c3e:	0100                	addi	s0,sp,128
 c40:	10090503          	lb	a0,256(s2)
 c44:	0100                	addi	s0,sp,128
 c46:	10090503          	lb	a0,256(s2)
 c4a:	0100                	addi	s0,sp,128
 c4c:	10090503          	lb	a0,256(s2)
 c50:	0100                	addi	s0,sp,128
 c52:	10090503          	lb	a0,256(s2)
 c56:	0100                	addi	s0,sp,128
 c58:	10090503          	lb	a0,256(s2)
 c5c:	0100                	addi	s0,sp,128
 c5e:	10090503          	lb	a0,256(s2)
 c62:	0100                	addi	s0,sp,128
 c64:	10090503          	lb	a0,256(s2)
 c68:	0100                	addi	s0,sp,128
 c6a:	10090503          	lb	a0,256(s2)
 c6e:	0100                	addi	s0,sp,128
 c70:	10090503          	lb	a0,256(s2)
 c74:	0100                	addi	s0,sp,128
 c76:	10090503          	lb	a0,256(s2)
 c7a:	0100                	addi	s0,sp,128
 c7c:	10090503          	lb	a0,256(s2)
 c80:	0100                	addi	s0,sp,128
 c82:	10090503          	lb	a0,256(s2)
 c86:	0100                	addi	s0,sp,128
 c88:	10090503          	lb	a0,256(s2)
 c8c:	0100                	addi	s0,sp,128
 c8e:	10090503          	lb	a0,256(s2)
 c92:	0100                	addi	s0,sp,128
 c94:	10090503          	lb	a0,256(s2)
 c98:	0100                	addi	s0,sp,128
 c9a:	10090503          	lb	a0,256(s2)
 c9e:	0100                	addi	s0,sp,128
 ca0:	10090503          	lb	a0,256(s2)
 ca4:	0100                	addi	s0,sp,128
 ca6:	10090503          	lb	a0,256(s2)
 caa:	0100                	addi	s0,sp,128
 cac:	10090503          	lb	a0,256(s2)
 cb0:	0100                	addi	s0,sp,128
 cb2:	10090503          	lb	a0,256(s2)
 cb6:	0100                	addi	s0,sp,128
 cb8:	10090503          	lb	a0,256(s2)
 cbc:	0100                	addi	s0,sp,128
 cbe:	10090503          	lb	a0,256(s2)
 cc2:	0100                	addi	s0,sp,128
 cc4:	10090503          	lb	a0,256(s2)
 cc8:	0100                	addi	s0,sp,128
 cca:	10090503          	lb	a0,256(s2)
 cce:	0100                	addi	s0,sp,128
 cd0:	10090503          	lb	a0,256(s2)
 cd4:	0100                	addi	s0,sp,128
 cd6:	10090503          	lb	a0,256(s2)
 cda:	0100                	addi	s0,sp,128
 cdc:	10090503          	lb	a0,256(s2)
 ce0:	0100                	addi	s0,sp,128
 ce2:	0c090503          	lb	a0,192(s2)
 ce6:	0100                	addi	s0,sp,128
 ce8:	0c090503          	lb	a0,192(s2)
 cec:	0100                	addi	s0,sp,128
 cee:	0c090503          	lb	a0,192(s2)
 cf2:	0100                	addi	s0,sp,128
 cf4:	0c090503          	lb	a0,192(s2)
 cf8:	0100                	addi	s0,sp,128
 cfa:	0c090503          	lb	a0,192(s2)
 cfe:	0100                	addi	s0,sp,128
 d00:	0c090503          	lb	a0,192(s2)
 d04:	0100                	addi	s0,sp,128
 d06:	0c090503          	lb	a0,192(s2)
 d0a:	0100                	addi	s0,sp,128
 d0c:	0c090503          	lb	a0,192(s2)
 d10:	0100                	addi	s0,sp,128
 d12:	0c090503          	lb	a0,192(s2)
 d16:	0100                	addi	s0,sp,128
 d18:	0c090103          	lb	sp,192(s2)
 d1c:	0100                	addi	s0,sp,128
 d1e:	08090503          	lb	a0,128(s2)
 d22:	0100                	addi	s0,sp,128
 d24:	0c090503          	lb	a0,192(s2)
 d28:	0100                	addi	s0,sp,128
 d2a:	0c090503          	lb	a0,192(s2)
 d2e:	0100                	addi	s0,sp,128
 d30:	0c090503          	lb	a0,192(s2)
 d34:	0100                	addi	s0,sp,128
 d36:	0c090503          	lb	a0,192(s2)
 d3a:	0100                	addi	s0,sp,128
 d3c:	0c090503          	lb	a0,192(s2)
 d40:	0100                	addi	s0,sp,128
 d42:	0c090503          	lb	a0,192(s2)
 d46:	0100                	addi	s0,sp,128
 d48:	0c090503          	lb	a0,192(s2)
 d4c:	0100                	addi	s0,sp,128
 d4e:	0c090503          	lb	a0,192(s2)
 d52:	0100                	addi	s0,sp,128
 d54:	0c090503          	lb	a0,192(s2)
 d58:	0100                	addi	s0,sp,128
 d5a:	0c090503          	lb	a0,192(s2)
 d5e:	0100                	addi	s0,sp,128
 d60:	0c090503          	lb	a0,192(s2)
 d64:	0100                	addi	s0,sp,128
 d66:	0c090503          	lb	a0,192(s2)
 d6a:	0100                	addi	s0,sp,128
 d6c:	10090503          	lb	a0,256(s2)
 d70:	0100                	addi	s0,sp,128
 d72:	10090503          	lb	a0,256(s2)
 d76:	0100                	addi	s0,sp,128
 d78:	10090503          	lb	a0,256(s2)
 d7c:	0100                	addi	s0,sp,128
 d7e:	10090503          	lb	a0,256(s2)
 d82:	0100                	addi	s0,sp,128
 d84:	10090503          	lb	a0,256(s2)
 d88:	0100                	addi	s0,sp,128
 d8a:	10090503          	lb	a0,256(s2)
 d8e:	0100                	addi	s0,sp,128
 d90:	10090503          	lb	a0,256(s2)
 d94:	0100                	addi	s0,sp,128
 d96:	10090503          	lb	a0,256(s2)
 d9a:	0100                	addi	s0,sp,128
 d9c:	10090503          	lb	a0,256(s2)
 da0:	0100                	addi	s0,sp,128
 da2:	10090503          	lb	a0,256(s2)
 da6:	0100                	addi	s0,sp,128
 da8:	10090503          	lb	a0,256(s2)
 dac:	0100                	addi	s0,sp,128
 dae:	10090503          	lb	a0,256(s2)
 db2:	0100                	addi	s0,sp,128
 db4:	10090503          	lb	a0,256(s2)
 db8:	0100                	addi	s0,sp,128
 dba:	10090403          	lb	s0,256(s2)
 dbe:	0100                	addi	s0,sp,128
 dc0:	04090103          	lb	sp,64(s2)
 dc4:	0100                	addi	s0,sp,128
 dc6:	1009                	c.nop	-30
 dc8:	0000                	unimp
 dca:	0101                	addi	sp,sp,0

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
  14:	20e0                	fld	fs0,192(s1)
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
  14:	20e0                	fld	fs0,192(s1)
	...

Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	6d6f682f          	0x6d6f682f
   4:	2f65                	jal	7bc <offset+0x754>
   6:	6f6c                	flw	fa1,92(a4)
   8:	6976                	flw	fs2,92(sp)
   a:	65442f73          	csrrs	t5,0x654,s0
   e:	6f746b73          	csrrsi	s6,0x6f7,8
  12:	2f70                	fld	fa2,216(a4)
  14:	6952                	flw	fs2,20(sp)
  16:	6556                	flw	fa0,84(sp)
  18:	5f72                	lw	t5,60(sp)
  1a:	65726f63          	bltu	tp,s7,678 <offset+0x610>
  1e:	7369722f          	0x7369722f
  22:	2f666f63          	bltu	a2,s6,320 <offset+0x2b8>
  26:	6972                	flw	fs2,28(sp)
  28:	2d766373          	csrrsi	t1,0x2d7,12
  2c:	7261                	lui	tp,0xffff8
  2e:	742d6863          	bltu	s10,sp,77e <offset+0x716>
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
  54:	69726f2f          	0x69726f2f
  58:	302d                	jal	fffff882 <imm12+0xfffff883>
  5a:	2e31                	jal	376 <offset+0x30e>
  5c:	682f0053          	0x682f0053
  60:	2f656d6f          	jal	s10,56356 <absimmsh+0x16358>
  64:	6f6c                	flw	fa1,92(a4)
  66:	6976                	flw	fs2,92(sp)
  68:	65442f73          	csrrs	t5,0x654,s0
  6c:	6f746b73          	csrrsi	s6,0x6f7,8
  70:	2f70                	fld	fa2,216(a4)
  72:	6952                	flw	fs2,20(sp)
  74:	6556                	flw	fa0,84(sp)
  76:	5f72                	lw	t5,60(sp)
  78:	65726f63          	bltu	tp,s7,6d6 <offset+0x66e>
  7c:	7369722f          	0x7369722f
  80:	2f666f63          	bltu	a2,s6,37e <offset+0x316>
  84:	6972                	flw	fs2,28(sp)
  86:	666f6373          	csrrsi	t1,0x666,30
  8a:	775f 726f 2f6b      	0x2f6b726f775f
  90:	7672                	flw	fa2,60(sp)
  92:	5f693233          	0x5f693233
  96:	2f6d                	jal	850 <offset+0x7e8>
  98:	2f49                	jal	82a <offset+0x7c2>
  9a:	2f637273          	csrrci	tp,0x2f6,6
  9e:	2d69726f          	jal	tp,97374 <absimmsh+0x57376>
  a2:	3130                	fld	fa2,96(a0)
  a4:	532e                	lw	t1,232(sp)
  a6:	7475642f          	0x7475642f
  aa:	4700                	lw	s0,8(a4)
  ac:	554e                	lw	a0,240(sp)
  ae:	4120                	lw	s0,64(a0)
  b0:	2e322053          	0x2e322053
  b4:	          	snez	a0,zero
