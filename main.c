	#include <stdio.h>
#include <assert.h>
#include "array_utils.h"

void test_array_util_create(){
	Array_util array = create(4,12);
	assert(array.length == 12);
	assert(array.typeSize == 4);
}

void test_array_utils_areEqual(){
	Array_util array1 = create(4,12);
	Array_util array2 = create(4,12);
	int * a = array1.base;
	int * b = array2.base;
	a[0] = 1;
	a[1] = 2;
	b[0] = 1;
	b[1] = 2;
	assert(areEqual(array1,array2) == 1);
}
void test_array_utils_are_not_Equal(){
	Array_util array1 = create(4,12);
	Array_util array2 = create(4,12);
	int * a = array1.base;
	int * b = array2.base;
	a[0] = 1456;
	a[1] = 21;
	b[0] = 1;
	b[1] = 29;
	assert(areEqual(array1,array2) == 0);
}
void test_array_util_resize(){
	Array_util array = create(4,5);
	array = resize(array,8);
	assert(array.length = 8);
}
void test_findIndex(){
	Array_util util = create(4,8);
	int x = 67;
	int y = 100;
	int z = 69;
	int * ptr = (int *)util.base;
	ptr[0] = 65;
	ptr[1] = 66;
	ptr[2] = 67;
	ptr[3] = 68;
	ptr[4] = 69;
	assert(findIndex(util,&x)== 2);
	assert(findIndex(util,&y)== -1);
	assert(findIndex(util,&z)== 4);
	dispose(util);
}
int isEven (void *hint,void *item) {
	int *a = (int *)item;
	if(*a == 0){
		return 0;
	}
	return !(*a%2);
}


void test_findFirst_isEven(){
	int * result;
	Array_util util = create(4,8);
	int *ptr =  (int *)util.base;
	ptr[0]= 65;
	ptr[1]= 66;
	ptr[2]= 67;
	ptr[3]= 68;
	result = findFirst(util,&isEven,NULL);
	assert(*result == 66);
	ptr[0]= 90;
	result = findFirst(util,&isEven,NULL);
	assert(*result == 90);
}
void test_findFirst_isEven_if_no_element_is_there() {
	// int * result;
	Array_util util = create(4,8);
	int *ptr =  (int *)util.base;
	ptr[0]= 65;
	ptr[1]= 63;
	ptr[2]= 67;
	ptr[3]= 69;
	void * a = NULL;
	int *result = (int *)findFirst(util,&isEven, &a);
	assert(result == NULL);
}

int isDivisible(void* hint, void* item) {
	int *hints = (int *)hint;
	int *num = (int *)item;
	if(*num == 0)
		return 0;
	if((*num % *hints) == 0){
		return 1;
	}
	else
		return 0;
}

void test_findFirst_isDivisible(){
	int * result;
	int hint = 3;
	Array_util util = create(4,8);
	int *ptr =  (int *)util.base;
	ptr[0]= 15;
	ptr[1]= 26;
	ptr[2]= 17;
	ptr[3]= 60;
	result = findFirst(util,&isDivisible,&hint);
	assert(*result == 15);
	hint = 5;
	result = findFirst(util,&isDivisible,&hint);
	assert(*result == 15);
	int nt = 7;
	int *result1 = (int *)findFirst(util,&isDivisible,&nt);
	assert(result1 == NULL);
}

void test_findLast_isEven() {
	int * result;
	Array_util util = create(4,8);
	int *ptr =  (int *)util.base;
	ptr[0]= 65;
	ptr[1]= 66;
	ptr[2]= 67;
	ptr[3]= 68;
	result = (int*)findLast(util,&isEven,NULL);
	assert(*result == 68);
	ptr[4]= 90;
	result = findLast(util,&isEven,NULL);
	assert(*result == 90);
}


void test_count() {
	Array_util util = create(4,8);
	int *ptr =  (int *)util.base;
	ptr[0]= 65;
	ptr[1]= 66;
	ptr[2]= 67;
	ptr[3]= 68;
	ptr[4]= 98;
	ptr[5]= 54;
	ptr[6]= 32;
	ptr[7]= 33;
	int result=count(util,&isEven,NULL);
	assert(result == 5);
}

void test_filter() {
	Array_util util = create(4,8);
	int *ptr = (int *)util.base;
	ptr[0]= 65;
	ptr[1]= 66;
	ptr[2]= 67;
	ptr[3]= 68;
	ptr[4]= 98;
	ptr[5]= 54;
	ptr[6]= 32;
	ptr[7]= 33;
	Array_util result = create(8,8);
	int numItems = result.length;
	int matchNumber = filter(util,&isEven,NULL,result.base,numItems);
	assert(matchNumber == 5);
	int **r = (int**)result.base;
	assert(*r[0] == 66);
	assert(*r[1] == 68);
	assert(*r[2] == 98);
	assert(*r[3] == 54);
	assert(*r[4] == 32);
}

void addFive(void* hint, void* sourceItem, void* destinationItem) {
	int *num = (int*)sourceItem;
	*(int*)destinationItem = *num + *(int*)hint;
}
void test_map(){
	Array_util util = create(4,8);
	Array_util destination = create(4,8);
	int *ptr = (int *)util.base;
	int hint =5;
	ptr[0]= 65;
	ptr[1]= 66;
	ptr[2]= 67;
	ptr[3]= 68;
	ptr[4]= 98;
	ptr[5]= 54;
	ptr[6]= 32;
	ptr[7]= 33;
	_map(util, destination,&addFive,&hint);
	int *p =(int*)destination.base;
	assert(70 == p[0]);
	assert(71 == p[1]);
	assert(72 == p[2]);
	assert(73 == p[3]);
	assert(103 == p[4]);
	assert(59 == p[5]);
	assert(37 == p[6]);
	assert(38 == p[7]);
}


void addTen(void *hint,void * item) {
	int * value = (int *)item;
	*value = *value + *(int *)hint;
}
void test_forEach(){
	Array_util util = create(4,8);
	int *ptr = (int *)util.base;
	int hint = 10;
	ptr[0]= 65;
	ptr[1]= 66;
	ptr[2]= 67;
	ptr[3]= 68;
	ptr[4]= 98;
	ptr[5]= 54;
	ptr[6]= 32;
	ptr[7]= 33;
	forEach(util,&addTen,&hint);
	assert( 75==ptr[0]);
	assert( 76==ptr[1]);
	assert( 77==ptr[2]);

}
void* Reducer(void* hint, void* previousItem, void* item) {
	int *previousvalue = (int*)previousItem;
	int *currentValue = (int*)item;
	*previousvalue=*previousvalue+(*currentValue + *(int*)hint);
		return previousvalue;

}


void test_reduce(){
	Array_util util = create(4,8);
	int *ptr = (int *)util.base;
	int hint = 10;
	int initialValue = 0;
	ptr[0]= 1;
	ptr[1]= 2;
	ptr[2]= 3;
	ptr[3]= 4;
	ptr[4]= 5;
	ptr[5]= 6;
	int * result = (int*)reduce(util,&Reducer,&hint,&initialValue);
	assert(101 == *result);


}
int main(void){
	test_array_util_create();
	test_array_utils_areEqual();
	test_array_utils_are_not_Equal();
	test_array_util_resize();
	test_findIndex();
	test_findFirst_isEven();
	test_findFirst_isEven_if_no_element_is_there();
	test_findFirst_isDivisible();
	test_findLast_isEven();
	test_count();
	test_filter();
	test_map();
	test_forEach();
	test_reduce();
	return 0;
}