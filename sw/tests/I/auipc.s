.section .text
.global _start

# start address is 0x10054

_start:
    auipc   x1, 0x1230        # x1 = 0x10054 + 0x12340000
    li      x2, 0x12310054
    beq     x1, x2, _good
    j _bad