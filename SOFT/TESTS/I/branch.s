.section .text
.global _start

_start:
    addi x1,x0,1254
    bge x0,x0,_good
    nop
