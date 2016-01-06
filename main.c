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

int main(void){
	Array_util util = create(4,6);
	int *ptr =  (int *)util.base;
	ptr[0]= 65;
	ptr[1]= 66;
	ptr[2]= 67;
	ptr[3]= 68;
	test_array_util_create();
	test_array_utils_areEqual();
	test_array_utils_are_not_Equal();
	test_array_util_resize();
	test_findIndex();
	test_findFirst_isEven();
	test_findFirst_isEven_if_no_element_is_there();
	test_findFirst_isDivisible();
	test_findLast_isEven();
	return 0;
}