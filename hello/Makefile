RV_PREFIX = riscv64-unknown-elf-#Prefix for our RISC-V tools (e.g. gcc and objdump)
CC = $(RV_PREFIX)gcc #Our compiler
CCFLAGS = -nostdlib -Iinclude -mcmodel=medany -Tlink.ld #Flags telling GCC to compile without libraries (e.g. baremetal), to use a differen memory model so that we can put our code at 0x80000000 and to use the specified linker script.
ASMFLAGS = -Iinclude

OUT_FILE = a.out

BUILD_DIR = build
SRC_DIR = src

all: kernel

#Compile init.s
# init:
# 	$(CC) -c init.s -o init.o

# #Compile hello.c and link hello.o and init.o
# hello:
# 	$(CC) $(CCFLAGS) -c hello.c -o hello.o
# 	$(CC) $(CCFLAGS) -o $(OUT_FILE) hello.o init.o

#Remove .out and .o files
clean:
	rm -rf $(BUILD_DIR) 

#For debugging purposes and objdump of our output file.
dump:
	$(RV_PREFIX)objdump -D $(BUILD_DIR)/kernel
run:
	spike -p1 $(BUILD_DIR)/kernel
rund:
	spike -p1 -d $(BUILD_DIR)/kernel

$(BUILD_DIR)/%_c.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CCFLAGS) -MMD -c $< -o $@

$(BUILD_DIR)/%_s.o: $(SRC_DIR)/%.S
	$(CC) $(ASMFLAGS) -MMD -c $< -o $@

C_FILES = $(wildcard $(SRC_DIR)/*.c)
ASM_FILES = $(wildcard $(SRC_DIR)/*.S)
OBJ_FILES = $(C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%_c.o)
OBJ_FILES += $(ASM_FILES:$(SRC_DIR)/%.S=$(BUILD_DIR)/%_s.o)

DEP_FILES = $(OBJ_FILES:%.o=%.d)
-include $(DEP_FILES)

kernel: link.ld $(OBJ_FILES)
	$(RV_PREFIX)ld -T link.ld -o $(BUILD_DIR)/kernel $(OBJ_FILES)
