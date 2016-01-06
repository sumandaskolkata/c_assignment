#include <stdio.h>
typedef int (matchFun)(void *, void *); 
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
int isEven (void *hint,void *item);
void* findFirst(Array_util util, matchFun* match, void* hint);