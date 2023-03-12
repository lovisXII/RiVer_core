CC=verilator
OUTPUT_TYPE=-sc
FLAGS=-Wno-fatal
PACKAGE=include/river_pkg.sv
SRC= $(shell find . -type f -name '*.sv') 
TOP=core

SYSTEMC?=/usr/local/systemc-2.3.3/
INCLUDE_PATH=-I$(SYSTEMC)/include -I../ELFIO -I obj_dir
LINK_PATH=-L $(SYSTEMC)/lib-linux64
LINKER_ARGS=-rpath=$(SYSTEMC)/lib-linux64 
LIBS=-lsystemc -lm
C_ARGS=$(INCLUDE_PATH) $(LINK_PATH) -Wl,$(LINKER_ARGS) $(LIBS) -g 

all:
	$(CC) $(SRC) $(OUTPUT_TYPE) --top-module $(TOP) $(FLAGS) --exe core_tb.cpp


core.o: core_tb.cpp 
	g++ -c $< $(C_ARGS) -o $@
clean:
	rm -rf obj_dir/