#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//with help from Jack
void list_add(struct list_element *head, struct list_element* ele){
	struct list_element* prev;
	struct list_element* temp = head;
	while(temp->next){
		prev = temp;
		temp = temp->next;
	}
	temp->prev = prev;
	temp->next = ele;
}
void list_remove(struct list_element* head, int data){
	struct list_element* head_pointer = head;
	if(head == NULL){
		return;
	}
	if(head_pointer->data == data){
		head = head_pointer->next;
		return;
	}
	while(head_pointer->next){
		if(data == head_pointer->data){
			head_pointer->prev->next = head_pointer->next;
			head_pointer = head_pointer->next;
			continue;
		}
		head_pointer = head_pointer->next;
	}
}
