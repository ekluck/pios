#include "list.h"
#include "serial.h"
#include "rprintf.h"
#include "page.h"

int global;
#define NULL (void*)0
extern long __bss_start;
extern long __bss_end;
extern struct ppage* free_list;

unsigned int *gpset1 = 0xFE200020;
unsigned int *gpclr1 = 0xFE20002C;
unsigned int *gpsel4 = 0xFE200010;

//HW1 Office Hours 2/1 w/ Jack
void clear_bss()

{
	int x = 0;
	while ((&__bss_start)+x != &__bss_end){
		(&__bss_start)[x] = 0;
		x++;
		}
}



//hw4
void led_init(){
	unsigned int mask_number = 0xFFFFFE3F;
	*gpsel4 = *gpsel4 & mask_number;
	*gpsel4 = *gpsel4 | (1 << 6);
	return;
}

void led_on(){
	*gpset1 = (1 << 10);
}

void led_off(){
	*gpclr1 = (1 << 10);
}

void delay (unsigned int d){
	unsigned int i, x;

	for(i = 0; i < 0x7f; i++) {
		for (x = 0; x < d; x++){
			asm("nop");
		}
	}

}

int getEL(){
	unsigned int el;

	asm("mrs %0,CurrentEL"
		: "=r"(el)
		:
		:);

}


void kernel_main(){
	clear_bss();

        init_pfa_list();

	struct ppage* test = free_list->next;
	esp_printf(putc, "Physical addr: %x \n", test->physical_addr);
	test = allocate_physical_pages(2);
	esp_printf(putc, "Physical addr (test) after npages: %x \n", test);
	esp_printf(putc, "Physical addr (->physical_addr) after npages: %x \n", test->physical_addr);
	free_physical_pages(test);
	test = free_list->next;
	esp_printf(putc, "Post free addr: %x \n", test->physical_addr);



 	//mmu_on();

	while(1){

	}
}
