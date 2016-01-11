#include <stdio.h>
typedef int (matchFun)(void *, void *);
typedef void (ConvertFun) (void *,void *,void *);
typedef  void (OperationFun) (void *,void *);
typedef void* (ReducerFun)(void*,void*,void*);
typedef struct array{
	void * base;
	int length;
	int typeSize;
} Array_util;


Array_util create(int,int);
int areEqual(Array_util,Array_util);
Array_util resize(Array_util , int);
int findIndex(Array_util,void *);
void dispose(Array_util);
int isEven (void *,void *);
void* findFirst(Array_util , matchFun* , void* );
void* findLast(Array_util , matchFun*, void*);
int count(Array_util , matchFun*, void* );
int filter(Array_util, matchFun*, void* , void** , int );
void _map(Array_util , Array_util , ConvertFun* , void* );
void forEach(Array_util , OperationFun* operation, void* );
void* reduce(Array_util util, ReducerFun*, void* hint, void* intialValue);

