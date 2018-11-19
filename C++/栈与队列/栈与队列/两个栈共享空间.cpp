#include <stdlib.h>
#include <time.h>
/*顺序结构的存储结构代码*/
#define MAXSIZE 20
typedef int ElemType;


/*顺序存储结构的插入与删除*/

/*获得元素操作*/

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int SElemType;

//两栈共享空间结构

typedef struct {
	SElemType data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;

//插入元素的方法
Status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
	if (S->top1 + 1 == S->top2)//栈满，不能再加新的元素了
		return ERROR;
	if (stackNumber == 1)
		S->data[++S->top1] = e;
	else if (stackNumber == 2)
		S->data[--S->top2] = e;
	return OK;
}

//pop出元素的方法
//若栈不空，则删除S的栈顶元素，用e返回其值，并返回IK
Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (S->top1 == -1)
			return ERROR;
		*e = S->data[S->top1--];

	}
	else if (stackNumber==2)
	{
		if (S->top2 == MAXSIZE)
			return ERROR;
		*e = S->data[S->top2++];
	}
	return OK;
}