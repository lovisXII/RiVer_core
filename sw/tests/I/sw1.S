.section .text
.global _start

_start:
    li t0, 0xdeadbeef
    li t1, 0x70000000
    
    sw t0, 0(t1)        # [t1] = 0xdeadbeef
    li t0, 0xFF
    sb t0, 3(t1)        # [t1] = 0xdeadbeff

    li t0, 0xffadbeef
    lw t2,0(t1)
    beq t2, t0, _good
    j _bad