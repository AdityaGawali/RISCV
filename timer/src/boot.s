# See LICENSE for license details.

.include "macros.s"
.include "constants.s"

#
# start of trap handler
#

.section .text.init,"ax",@progbits
.globl _start
.globl enable_timer
.globl disable_timer



_start:
    # set up stack pointer based on hartid

    



    csrr    t0, mhartid
    slli    t0, t0, STACK_SHIFT
    la      sp, stacks + STACK_SIZE
    add     sp, sp, t0

    # park all harts excpet hart 0
    csrr    a0, mhartid
    bnez    a0, park

    # jump to main
    j       main

    # sleeping harts mtvec calls trap_fn upon receiving IPI
park:
    wfi
    j       park

    .align 2


enable_timer:
    li t0, 8
    csrw mstatus,t0
    li t0, 128
    csrw mie, t0
    ret

disable_timer:
    li t0, 0
    csrw mie, t0
    ret    

trap_vector:
    jal timer_handler
    mret


    .bss
    .align 4
    .global stacks
stacks:
    .skip STACK_SIZE * MAX_HARTS
