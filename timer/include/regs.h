#ifndef _REGS_H
#define _REGS_H

#include "inttypes.h"

#define _REG_TYPE_32 volatile uint32_t
#define _REG_32 _REG_TYPE_32*

#define _REG_TYPE_64 volatile uint64_t
#define _REG_64 _REG_TYPE_64*

#define UART_BASE ((_REG_TYPE_32) 0x10013000)


#define U_TX_DATA ((_REG_32) (UART_BASE + 0x00))
#define U_RX_DATA ((_REG_32) (UART_BASE + 0x04))
#define U_TX_CTRL ((_REG_32) (UART_BASE + 0x08))
#define U_RX_CTRL ((_REG_32) (UART_BASE + 0x0C))
#define U_IENB ((_REG_32) (UART_BASE + 0x10))
#define U_IPEND ((_REG_32) (UART_BASE + 0x14))
#define U_B_DIV ((_REG_32) (UART_BASE + 0x18))

#define M_TIME ((_REG_64)(0x0200BFF8))
#define M_TIME_CMP ((_REG_64)(0x02004000))

#define read_csr(reg) ({ unsigned long __tmp; \
  asm volatile ("csrr %0, " #reg : "=r"(__tmp)); \
  __tmp; })

#define write_csr(reg, val) ({ \
  asm volatile ("csrw " #reg ", %0" :: "rK"(val)); })


#define MCAUSE_INT      0x80000000UL
#define MCAUSE_CAUSE    0x000003FFUL
#define MSTATUS_MIE_BIT     (3)  // global interrupt enable bit mask. 
#define MIE_MTIE_BIT        (7)  //Timer interrupt enable bit mask

#endif