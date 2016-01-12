#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "linkedList.h"



void test_createList (){
	LinkedList list = createList();
	assert(list.first == NULL);
	assert(list.last == NULL);
	assert(list.length == 0);
}

void test_add_to_list() {
	LinkedList list = createList();
	int *item =(int*)malloc( sizeof(int));
	*item = 10;
	float *value =(float*)malloc( sizeof(float));
	*value = 11.23;
	assert(1 == add_to_list(&list,item)); 
	assert(10 == *(int*)list.first->value);
	assert(10 == *(int*)list.last->value);
	assert(2 == add_to_list(&list,value)); 
	assert(10 == *(int*)list.first->value);
	printf("%f\n",*(float*)list.last->value);
	item =(int*)malloc( sizeof(int));
	*item = 33;
	assert(3 == add_to_list(&list,item));
	assert(33 == *(int*)list.last->value);
}
void test_get_first_element(){
	LinkedList list = createList();
	int *item =(int*)malloc( sizeof(int));
	*item = 10;
	float *value =(float*)malloc( sizeof(float));
	*value = 11.23;
	assert(1 == add_to_list(&list,item)); 
	assert(2 == add_to_list(&list,value)); 
	item =(int*)malloc( sizeof(int));
	*item = 33;
	assert(3 == add_to_list(&list,item));


	Element * firstElement =  get_first_element(list);
	assert(10 == *(int*)firstElement->value);
}

void test_get_lsst_element(){
	LinkedList list = createList();
	int *item =(int*)malloc( sizeof(int));
	*item = 10;
	float *value =(float*)malloc( sizeof(float));
	*value = 11.23;
	assert(1 == add_to_list(&list,item)); 
	assert(2 == add_to_list(&list,value)); 
	item =(int*)malloc( sizeof(int));
	*item = 33;
	assert(3 == add_to_list(&list,item));


	Element * lastElement =  get_last_element(list);
	assert(33 == *(int*)lastElement->value);
}

void increment (void * value) {
	int *element =(int*)value;
	*element = *(int *)value +1;
} 

void test_forEach() {
	LinkedList list = createList();
	for (int i = 0; i < 10; ++i) {
		int *item =(int*)malloc( sizeof(int));
		*item = i;
		add_to_list(&list,item);
	}
	assert(0 == *(int*)list.first->value);
	assert(9 == *(int*)list.last->value);
	forEach(list,&increment);	
	assert(1 == *(int*)list.first->value);
	assert(10 == *(int*)list.last->value);
}

