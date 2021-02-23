#include <stdio.h>
#include "list.h"
#include "led.h"

void bss_to_zero();

extern int __bss_start;
extern int __bss_end;

int global;

struct list_element b = {NULL,NULL, 1};
struct list_element a = {NULL,NULL, 5};
struct list_element c = {NULL,NULL, 2};
struct list_element *head = &a;

struct list_element* list = &a;

//new method
/*unsigned long get_timer_count () {
	unsigned long * timer_count_register = 0x3f003004 ;
	return * timer_count_register ;
}*/


void kernel_main(){
	
	bss_to_zero();
	list_add(list, &b);
	list_add(list, &c);
	list_remove(head, 1);
	get_timer_count();
	
	while (1){
		led_on();
		delay();
		led_off();
		delay();
	}
}

void bss_to_zero(){
	(&__bss_start)[0] = 0x0c;
	int x=0;
	while ((&__bss_start)+x != &__bss_end){
		(&__bss_start)[x] = 0;
		x++;
	}
}
