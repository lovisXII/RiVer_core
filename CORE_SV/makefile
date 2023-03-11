CC=verilator
OUTPUT_TYPE=-sc
FLAGS=-Wno-fatal
SRC=include/river_pkg.sv $(shell find . -type f -name '*.sv') 
PACKAGE=include/river_pkg.sv
all:
	$(CC) $(SRC) $(OUTPUT_TYPE) $(FLAGS) 

clean: