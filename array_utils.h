#include <stdio.h>
typedef struct array{
	void * base;
	int length;
	int typeSize;
} Array_util;


Array_util create(int,int);
int areEqual(Array_util,Array_util);
Array_util resize(Array_util array , int length);
int findIndex(Array_util,void *);
void dispose(Array_util util);