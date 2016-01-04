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
int main(void)
{
	test_array_util_create();
	test_array_utils_areEqual();
	return 0;
}