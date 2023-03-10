CC=verilator
FLAGS= -cc -Wno-fatal
SRC=CSR/csr.sv DECOD/decod.sv EXE/exe.sv EXE/alu.sv EXE/shifter.sv EXE/x0_multiplier.sv IFETCH/ifetch.sv MEM/mem.sv REG/reg.sv WBK/wbk.sv USEFULL/csa.sv USEFULL/fifo.sv
PACKAGE=+incdir+include/riscv_pkg.sv
all:
	$(CC) $(FLAGS) $(SRC)

clean: