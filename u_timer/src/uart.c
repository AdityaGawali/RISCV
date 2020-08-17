#include "uart.h"
#include "printf.h"


void putchar(uint8_t data)
{	
	while (*(U_TX_DATA) & 0x80000000);
    *(U_TX_DATA) = data;
}

// putc function definer here
// putc function declared in printf.h
void _putchar(char character)
{
	putchar(character);

}




void putstring(char *s)
{
    while (*s)
    {
    	putchar(*s++);
    }
    putchar('\n');
}