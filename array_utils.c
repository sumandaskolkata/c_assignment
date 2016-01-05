#include <stdlib.h>
#include <string.h>
#include "array_utils.h"


Array_util create(int typeSize , int length) {
	Array_util a;
	a.base = calloc(length,typeSize);
	a.length = length;
	a.typeSize = typeSize;
	return a;
}

int areEqual(Array_util firstArray,Array_util secondArray) {
	char * first_util =(char *) firstArray.base; 
	char * second_util =(char *) secondArray.base; 
	if((firstArray.length == secondArray.length)&&(firstArray.typeSize == secondArray.typeSize)){
		for (int i = 0; i < (firstArray.length * firstArray.typeSize); i++) {
			if (first_util[i] != second_util[i]) {
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

Array_util resize(Array_util array,int length) {
	Array_util newAray;
	newAray.base = realloc(array.base,length);
	newAray.length = length;
	newAray.typeSize = array.typeSize;
	return newAray;
}
int findIndex(Array_util array,void * element) {
	char * ptr = (char*)array.base;
	int result,size = array.typeSize;
	for (int i = 0; i < array.length; i++) {
		result = memcmp(ptr ,element , size);
		if(result == 0)
			return i;
		ptr +=size; 
	}
	return -1;
}

void dispose(Array_util util) {
	void* p =util.base;
	free(p);
}
























