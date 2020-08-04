# See LICENSE for license details.

.include "macros.s"
.include "constants.s"

#
# start of trap handler
#

.section .text.init,"ax",@progbits
.globl _start

_start:
    # set up stack pointer based on hartid
    csrr    t0, mhartid
    slli    t0, t0, STACK_SHIFT
    la      sp, stacks + STACK_SIZE
    add     sp, sp, t0

    # park all harts excpet hart 0
    csrr    a0, mhartid
    bnez    a0, park

    # jump to libfemto_start_main
    j       main

    # sleeping harts mtvec calls trap_fn upon receiving IPI
park:
    wfi
    j       park




.bss
.align 4
.global stacks
stacks:
    .skip STACK_SIZE * MAX_HARTS
