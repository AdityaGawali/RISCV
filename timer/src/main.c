#include "uart.h"
#include "printf.h"

int main() 
{	
    printf("Timer\n");
    while(1)
    {
    uint64_t a = *(CLINT_M_TIME);


    printf("%llu\n",a);
    }
    return 0;
}