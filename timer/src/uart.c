#include "uart.h"

void putchar(uint8_t data)
{	
	while (*(U_TX_DATA) & 0x80000000);
    *(U_TX_DATA) = data;
}

void putstring(char *s)
{
    while (*s)
    {
    	putchar(*s++);
    }
    putchar('\n');
}

void putc ( void* p, char c)
{
	putchar(c);
}