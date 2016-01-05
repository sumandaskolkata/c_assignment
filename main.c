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
	assert(areEqual(array1,array2) == 1);
}
void test_array_utils_are_not_Equal(){
	Array_util array1 = create(4,15);
	Array_util array2 = create(4,12);
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

int main(void)
{
	Array_util util = create(4,6);
	int *ptr =  (int *)util.base;
	ptr[0]= 65;
	ptr[1]= 66;
	ptr[2]= 67;
	ptr[3]= 68	; 
	test_array_util_create();
	test_array_utils_areEqual();
	test_array_utils_are_not_Equal();
	test_array_util_resize();
	test_findIndex();
	return 0;
}