# Compilers

VERILATOR=verilator
RISC=riscv32-unknown-elf-gcc 

# VERILATOR 

FLAGS=-sc -Wno-fatal -I../ELFIO
TB=core_tb.cpp
SRC= $(shell find . -type f -name '*.sv') $(TB)
TOP=core


# G++

INCLUDE_PATH= -I../../ELFIO
LIBS=-lsystemc -lm
C_ARGS=$(INCLUDE_PATH) -Wl, $(LIBS) -g 

# RISCV

SW_DIR=../SOFT/
LD_SCRIPT= -T $(SW_DIR)/kernel.ld
RISC_FLAGS= -nostdlib $(LD_SCRIPT)

all: core_tb

core_tb: kernel
	export SYSTEMC_INCLUDE=/usr/local/systemc-2.3.3/include/
	export SYSTEMC_LIBDIR=/usr/local/systemc-2.3.3/lib-linux64/
	$(VERILATOR) -CFLAGS "$(C_ARGS)" $(FLAGS) $(SRC) --top-module $(TOP)  --exe $(TB)
	$(MAKE) -j -C obj_dir -f Vcore.mk

kernel:$(SW_DIR)/exception.s $(SW_DIR)/reset.s
	$(RISC) $(RISC_FLAGS) $^ -o $@

clean:
	rm -rf obj_dir/