CC=verilator
OUTPUT_TYPE=-sc
FLAGS=-Wno-fatal
PACKAGE=include/river_pkg.sv
SRC= $(shell find . -type f -name '*.sv') 
TOP=core
all:
	$(CC) $(SRC) $(OUTPUT_TYPE) --top-module $(TOP) $(FLAGS)

clean:
	rm -rf obj_dir/