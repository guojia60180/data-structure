#include <stdlib.h>
#include <time.h>
/*˳��ṹ�Ĵ洢�ṹ����*/
#define MAXSIZE 20
typedef int ElemType;


/*˳��洢�ṹ�Ĳ�����ɾ��*/

/*���Ԫ�ز���*/

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int SElemType;

//��ջ�Ľṹ

typedef struct StackNode {
	SElemType data;
	struct StackNode *next;
	
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
}LinkStack;

//��ջ

Status Push(LinkStack *S, SElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s ->data = e;
	s->next = S->top;
	S->top = s;
	S->count++;
}

//��ջ

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
