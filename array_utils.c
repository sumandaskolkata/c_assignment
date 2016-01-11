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



void* findFirst(Array_util util, matchFun* match, void* hint) {
	void *ptr = util.base;
	for (int i = 0; i < util.length; i++) {
		if(match(hint,ptr)){
			return ptr;
		}
		ptr+=util.typeSize;
	}
	return NULL;
}

void* findLast(Array_util util, matchFun* match, void* hint) {
	void *ptr = util.base;
	ptr = ptr+((util.length) * (util.typeSize));
	for (int i = util.length-1; i >=0 ; i--) {
		if(match(hint,ptr)){
			return ptr;
		}
		ptr-=util.typeSize;
	}
	return NULL;
}

int count(Array_util util, matchFun* match, void* hint) {
	void *ptr = util.base;
	int count = 0;
	for (int i = 0; i < util.length; i++) {
		if(match(hint,ptr)){
			++count;
		}
		ptr = ptr + util.typeSize;
	}
	return count;
}

int filter(Array_util util, matchFun* match, void* hint, void** destination, int maxItems ) {
	void *ptr = util.base;
	int count = 0;
	void **dest = destination;
	for (int i = 0; i < util.length; i++) {
		if(match(hint,ptr)){
			*dest = ptr;
			dest++;
			++count;
		}
		ptr +=util.typeSize;
	}
	return count;
}

void _map(Array_util source, Array_util destination, ConvertFun* convert, void* hint) {
	void * source_base = source.base;
	void * destination_base = destination.base;
	for (int i = 0; i < source.length; i++) {
		convert(hint,source_base,destination_base);
		source_base+=source.typeSize;
		destination_base+=destination.typeSize;
	}

}

void forEach(Array_util util, OperationFun* operation, void* hint) {
	void *ptr = util.base;
	for (int i = 0; i < util.length; i++)
	{
		operation(hint,ptr);
		ptr+=util.typeSize;
	}
}

void* reduce(Array_util util, ReducerFun* reducer, void* hint, void* intialValue) {
	void *ptr = util.base;
	void * previousValue = intialValue;
	for (int i = 0; i < util.length;i++)
	{
		previousValue =  reducer(hint,previousValue,ptr);
		ptr+=util.typeSize;
	}
	return previousValue;
}




















