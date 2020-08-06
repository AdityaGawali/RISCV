#include "uart.h"
#include "regs.h"
#include "printf.h"

#define MAX_INTERRUPTS 16

volatile int intr_count;


void (*interrupt_handler[MAX_INTERRUPTS])();
void (*exception_handler[MAX_INTERRUPTS])();

void handle_trap(void) __attribute((interrupt));
void handle_trap()
{  
    unsigned long mcause = read_csr(mcause);
    if (mcause & MCAUSE_INT) {
        printf("interrupt. cause=%d\n", 
            mcause & MCAUSE_CAUSE);
        // mask interrupt bit and branch to handler
        interrupt_handler[mcause & MCAUSE_CAUSE] ();
    } else {
        printf("exception=%d\n", mcause & MCAUSE_CAUSE);
        // synchronous exception, branch to handler
        exception_handler[mcause & MCAUSE_CAUSE]();
    }
    printf("handle trap\n");
}



uint64_t get_cycles(void)
{
	return *(M_TIME);
}
void set_time_cycles(uint64_t cycles)
{
	*(M_TIME_CMP) = cycles;
	printf("lala\n");
}

void timer_handler()
{
	printf("Timer:\n");
	intr_count++;
}

void timer_interrupt_init()
{
	write_csr(mie, read_csr(mie) | (1 << MIE_MTIE_BIT));
	printf("Timer init\n");
}
void global_interrupt_init()
{
	write_csr(mstatus, read_csr(mstatus) | (1 << MSTATUS_MIE_BIT));
	printf("global interrupt init\n");
}

void global_interrupt_deinit()
{
	write_csr(mstatus, read_csr(mstatus) & ~(1 << MSTATUS_MIE_BIT));

}
void timer_interrupt_deinit()
{
	write_csr(mie, read_csr(mie) & ~(1 << MIE_MTIE_BIT));
}


void register_trap_handler(void *func)
{
    write_csr(mtvec, ((unsigned long)func));
}


void main() 
{	
	

	init_printf(0, putc);
	

	interrupt_handler[7] = timer_handler;
	register_trap_handler(handle_trap);
	timer_interrupt_init();


	set_time_cycles(0);
	global_interrupt_init();

	putstring("Main\n");
	int prev_cnt = intr_count;
	while(1)
	{
		global_interrupt_deinit();
		if(prev_cnt != intr_count)
		{
			printf("toggle\n");
			if(intr_count >= 10)
			{
				printf("count:%d reset\n",intr_count );
				intr_count = 0;
			}
		}
		global_interrupt_init();

	}

}