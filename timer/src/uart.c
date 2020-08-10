#include "uart.h"
#include "printf.h"

void putchar(uint8_t data)
{	
	while((*(U_LSR) & U_DATA_EMPTY)== 0);
	*(U_DR) = data;
}

void putstring(char *s)
{
    while (*s)
    {
    	putchar(*s++);
    }
    putchar('\n');
}
// putc function definer here
// putc function declared in printf.h
void _putchar(char character)
{
	putchar(character);

}
