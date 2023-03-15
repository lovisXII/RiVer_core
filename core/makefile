CC=verilator
RISC=riscv32-unknown-elf-gcc 
OUTPUT_TYPE=-sc
FLAGS=-Wno-fatal -I../ELFIO
SRC= $(shell find . -type f -name '*.sv') core_tb.cpp
TOP=core

# SYSTEMC?=/usr/local/systemc-2.3.3/
INCLUDE_PATH= -I../../ELFIO

# LINK_PATH=-L $(SYSTEMC)/lib-linux64
# LINKER_ARGS=-rpath=$(SYSTEMC)/lib-linux64 
LIBS=-lsystemc -lm
C_ARGS=$(INCLUDE_PATH) $(LINK_PATH) -Wl,$(LINKER_ARGS) $(LIBS) -g 
SW_DIR=../SOFT/
LD_SCRIPT= -T $(SW_DIR)/kernel.ld
RISC_FLAGS= -nostdlib $(LD_SCRIPT)

all: core_tb

core_tb: kernel
	export SYSTEMC_INCLUDE=/usr/local/systemc-2.3.3/include/
	export SYSTEMC_LIBDIR=/usr/local/systemc-2.3.3/lib-linux64/
	$(CC) -CFLAGS "$(C_ARGS)" $(FLAGS) $(SRC) $(OUTPUT_TYPE) --top-module $(TOP)  --exe core_tb.cpp 
	$(MAKE) -j -C obj_dir -f Vcore.mk

kernel:$(SW_DIR)/exception.s $(SW_DIR)/reset.s
	$(RISC) $(RISC_FLAGS) $^ -o $@

clean:
	rm -rf obj_dir/