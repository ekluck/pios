#include <stdio.h>
#include "list.h"


void bss_to_zero();

extern int __bss_start;
extern int __bss_end;

int global;

struct list_element b = {NULL,NULL, 1};
struct list_element a = {NULL,NULL, 5};
struct list_element c = {NULL,NULL, 2};
struct list_element *head = &a;

struct list_element* list = &a;

void kernel_main(){
	bss_to_zero();
	list_add(list, &b);
	list_add(list, &c);
	list_remove(head, 1);
	while (1){
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
