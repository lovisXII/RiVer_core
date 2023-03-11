CC=verilator
OUTPUT_TYPE=-sc
FLAGS=-Wno-fatal
SRC=include/river_pkg.sv CSR/csr.sv DECOD/decod.sv EXE/exe.sv EXE/alu.sv EXE/shifter.sv EXE/x0_multiplier.sv IFETCH/ifetch.sv MEM/mem.sv REG/reg.sv WBK/wbk.sv \
	USEFULL/csa.sv USEFULL/fifo.sv 
PACKAGE=include/river_pkg.sv
all:
	$(CC) $(SRC) $(OUTPUT_TYPE) $(FLAGS) 

clean: