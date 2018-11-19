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

//链栈的结构

typedef struct StackNode {
	SElemType data;
	struct StackNode *next;
	
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
}LinkStack;

//进栈

Status Push(LinkStack *S, SElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s ->data = e;
	s->next = S->top;
	S->top = s;
	S->count++;
}

//出栈

Status Pop(LinkStack *S, SElemType *e)
{
	LinkStackPtr p;
	if (StackEmpty(S))
		return ERROR;
	*e = S->top->data;
	p = S->top;
	S->top = S->top->next;
	free(p);
	S->count--;
	return OK;
}

int StackEmpty(LinkStack *S) {
	if (S->top->next == NULL)
		return TRUE;
	return FALSE;
}
