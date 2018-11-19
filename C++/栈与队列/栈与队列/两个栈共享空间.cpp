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

//��ջ����ռ�ṹ

typedef struct {
	SElemType data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;

//����Ԫ�صķ���
Status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
	if (S->top1 + 1 == S->top2)//ջ���������ټ��µ�Ԫ����
		return ERROR;
	if (stackNumber == 1)
		S->data[++S->top1] = e;
	else if (stackNumber == 2)
		S->data[--S->top2] = e;
	return OK;
}

//pop��Ԫ�صķ���
//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������IK
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