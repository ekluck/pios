//#include <stdio.h>//comment this out for serial port hw
#include "led.h"
#include "serial.h"
#include "rprint.h"

int global;
#define NULL (void*)0; //added for serial port hw in tuesday class
extern long __bss_start;
extern long __bss_end;


//void clear_bss(){
	
//	char * bssStart = &__bss_start;
//	char * bssEnd = &__bss_end;
//	for(int i = 0; i+(&__bss_start) < __bss_end; i++){
//		(&__bss_start)[i] = 0;
//	}
//}

int *mu_io_reg = 0x3F215040; //added for serial port hw in tuesday class
void kernel_main(){
//	clear_bss();
//	led_init();
	int *mu_io_reg = 0x7E215040;
	*mu_io_reg = 'E';
	*mu_io_reg = 'V';
	*mu_io_reg = 'I';
	*mu_io_reg = 'E';
	esp_printf(putc, "The memory location is %x", kernel_main); //added for serial port hw tuesday class
    while(1){
//	led_on(); //comment these out before commit and pushing serial port hw
//	delay(10);
//	led_off();
//	delay(10);
    }
}
