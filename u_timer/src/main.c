#include "uart.h"
#include "printf.h"
uint64_t M_TIME_INTR = 9223372036854775815U;
volatile uint32_t counter = 0;

void timer_interrupt(void) __attribute__((interrupt, aligned(64)));
void timer_interrupt(void)
{
    uint64_t now = *(CLINT_M_TIME);
    write_csr(mie, read_csr(mie) & ~(1<<7));

    *CLINT_M_TIME_CMP = *CLINT_M_TIME +  5000000;

    write_csr(mie, read_csr(mie) | (1<<7));
    printf("%llu\n",(*CLINT_M_TIME) - now);
    asm volatile ("mret");
}
int main() 
{	
    uint64_t temp =  read_csr(mhartid);

    printf("%llu\n",temp);
    *CLINT_M_TIME_CMP = 0;
    write_csr(mstatus,read_csr(mstatus) | (1<<3));
    write_csr(mtvec, &timer_interrupt);
    //*CLINT_M_TIME = 0x00;
    *CLINT_M_TIME_CMP = 0xFFFF;
    write_csr(mie,read_csr(mie) | (1<<7) );

    // asm volatile ("wfi");
    while(1);
   
    return 0;
}