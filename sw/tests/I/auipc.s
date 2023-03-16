.section .text
.global _start

# start address is 0x1054

_start:
    auipc   x1, 0x1234        # x1 = 0x1054 + 0x12340000
    li      x2, 0x12341054
    beq     x1, x2, _good
    j _bad