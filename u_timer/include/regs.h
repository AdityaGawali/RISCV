#ifndef _REGS_H
#define _REGS_H

#include "inttypes.h"

#define __REG_TYPE_32 volatile uint32_t
#define __REG_32 __REG_TYPE_32*

#define __REG_TYPE_8 volatile uint8_t
#define __REG_8 __REG_TYPE_8*

#define __REG_TYPE_64 volatile uint64_t
#define __REG_64 __REG_TYPE_64*

//-----//
#define UART_BASE ((__REG_TYPE_32) 0x10010000)
#define U_TX_DATA ((__REG_32) (UART_BASE + 0x00))
#define U_RX_DATA ((__REG_32) (UART_BASE + 0x04))
#define U_TX_CTRL ((__REG_32) (UART_BASE + 0x08))
#define U_RX_CTRL ((__REG_32) (UART_BASE + 0x0C))
#define U_IENB ((__REG_32) (UART_BASE + 0x10))
#define U_IPEND ((__REG_32) (UART_BASE + 0x14))
#define U_B_DIV ((__REG_32) (UART_BASE + 0x18))
//-----//
#define CLINT_BASE ((__REG_TYPE_32) 0x02000000)
#define CLINT_M_TIME_CMP ((__REG_64)(CLINT_BASE + 0x4008))
#define CLINT_M_TIME ((__REG_64)(CLINT_BASE + 0xBFF8))

#define read_csr(reg) ({ unsigned long __tmp; \
  asm volatile ("csrr %0, " #reg : "=r"(__tmp)); \
  __tmp; })

#define write_csr(reg, val) ({ \
  asm volatile ("csrw " #reg ", %0" :: "rK"(val)); })





#endif


