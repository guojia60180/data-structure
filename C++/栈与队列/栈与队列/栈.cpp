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
typedef struct
{
	SElemType data[MAXSIZE];
	int top;//用于栈顶指针
}SqStack;

//进栈操作

//插入元素e为新的栈顶元素

Status Push(SqStack *S, SElemType e)
{
	if (S->top == MAXSIZE - 1)//栈满了
	{
		return ERROR;

	}
	S->top++;//栈顶指针加一
	S->data[S->top] = e;//将新插入元素赋值给栈空间
	return OK;
}

//出栈操作
//若栈不为空，删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR

Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == -1)
		return ERROR;
	*e = S->data[S->top];//将要删除的栈顶元素赋值给e
	S->top--;//栈顶指针-1
	return OK;
}


