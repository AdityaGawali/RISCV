#ifndef _REGS_H
#define _REGS_H

#include "inttypes.h"

#define __REG_TYPE volatile uint32_t
#define __REG __REG_TYPE*

#define UART_BASE ((__REG_TYPE) 0x10013000)


#define U_TX_DATA ((__REG) (UART_BASE + 0x00))
#define U_RX_DATA ((__REG) (UART_BASE + 0x04))
#define U_TX_CTRL ((__REG) (UART_BASE + 0x08))
#define U_RX_CTRL ((__REG) (UART_BASE + 0x0C))
#define U_IENB ((__REG) (UART_BASE + 0x10))
#define U_IPEND ((__REG) (UART_BASE + 0x14))
#define U_B_DIV ((__REG) (UART_BASE + 0x18))

#endif