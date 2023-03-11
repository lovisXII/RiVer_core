CC=verilator
OUTPUT_TYPE=-sc
FLAGS=-Wno-fatal
PACKAGE=include/river_pkg.sv
SRC= $(shell find . -type f -name '*.sv' ) 
TOP=core.sv
all:
	$(CC) $(SRC) $(OUTPUT_TYPE) $(FLAGS) 

clean:
	rm -rf obj_dir/