#include <stdlib.h>
#include "array_utils.h"
Array_util create(int typeSize , int length) {
	Array_util a;
	a.base = calloc(length,typeSize);
	a.length = length;
	a.typeSize = typeSize;
	return a;
}

int areEqual(Array_util firstArray,Array_util secondArry) {
	if((firstArray.length == secondArry.length)&&(firstArray.typeSize == secondArry.typeSize))
		return 1;
	else
		return 0;
}