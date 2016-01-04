#include <stdio.h>
typedef struct array{
	void * base;
	int length;
	int typeSize;
} Array_util;


Array_util create(int,int);
int areEqual(Array_util,Array_util);