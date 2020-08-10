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
#define UART_BASE ((__REG_TYPE_32) 0x10000000)
#define U_DR ((__REG_8)(UART_BASE + 0))
#define U_LSR ((__REG_8)(UART_BASE + 5))
#define U_DATA_EMPTY (1<<6)
//-----//
#define CLINT_BASE ((__REG_TYPE_32) 0x02000000)
#define CLINT_M_TIME_CMP ((__REG_64)(CLINT_BASE + 0x4000))
#define CLINT_M_TIME ((__REG_64)(CLINT_BASE + 0xBFF8))

#endif