#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


LinkedList createList(void) {
	LinkedList list;
	list.first = list.last = NULL;
	list.length = 0;
	return list;
}

int add_to_list(LinkedList * list,void * item) {
	Element *newElement;
	newElement = (Element *) malloc( sizeof(Element) );
	newElement->value =item;
	newElement->next = NULL;
	if(list->first == NULL){
		list->first = list->last = newElement;
	}
	else {
		list->last->next = newElement;
		list->last = newElement;
	}
	list->length = list->length +1;
	return list->length;
}

void * get_first_element(LinkedList list) {
	Element * firstElement = list.first;
	return firstElement;
}

void *get_last_element(LinkedList list) {
	Element * lastElement = list.last;
	return lastElement;
}
void forEach(LinkedList list, ElementProcessor prosser) {
	for (int i = 0; i < list.length; ++i) {
		void * value = list.first->value;
		prosser(value);
		list.first = list.first->next;
	}
}

















