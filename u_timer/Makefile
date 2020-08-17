RISCV_PREFIX = riscv64-unknown-elf-
CC = $(RISCV_PREFIX)gcc 
CCFLAGS = -Wall -Werror -O -fno-omit-frame-pointer -MD -mcmodel=medany -nostdlib -fno-builtin  -Iinclude -T link.lds
ASMFLAGS = -Iinclude

OUT_FILE = kernel

BUILD_DIR = build
SRC_DIR = src

WINDOWS_EXE = .exe

all: kernel

clean:
	rm -rf $(BUILD_DIR)

dump:
	$(RISCV_PREFIX)objdump -D $(BUILD_DIR)/kernel

run:
	qemu-system-riscv64$(WINDOWS_EXE) -m 2048M   -nographic -smp 2 -machine sifive_u -bios none -kernel $(BUILD_DIR)/kernel

debug:
	qemu-system-riscv64$(WINDOWS_EXE) -m 2048M -nographic -smp 2 -machine sifive_u -bios none -monitor telnet:127.0.0.1:1234,server,nowait -kernel $(BUILD_DIR)/kernel


$(BUILD_DIR)/%_c.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CCFLAGS) -MMD -c $< -o $@

$(BUILD_DIR)/%_s.o: $(SRC_DIR)/%.s
	$(CC) $(CCFLAGS) -MMD -c $< -o $@

C_FILES = $(wildcard $(SRC_DIR)/*.c)
ASM_FILES = $(wildcard $(SRC_DIR)/*.s)
OBJ_FILES = $(C_FILES:$(SRC_DIR)%.c=$(BUILD_DIR)/%_c.o)
OBJ_FILES += $(ASM_FILES:$(SRC_DIR)/%.s=$(BUILD_DIR)/%_s.o)

DEP_FILES = $(OBJ_FILES:%.o=%.d)
-include $(DEP_FILES)

kernel: link.lds $(OBJ_FILES)
	$(RISCV_PREFIX)ld -T link.lds -o $(BUILD_DIR)/kernel $(OBJ_FILES)	
