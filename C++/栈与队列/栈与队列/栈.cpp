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
typedef struct
{
	SElemType data[MAXSIZE];
	int top;//����ջ��ָ��
}SqStack;

//��ջ����

//����Ԫ��eΪ�µ�ջ��Ԫ��

Status Push(SqStack *S, SElemType e)
{
	if (S->top == MAXSIZE - 1)//ջ����
	{
		return ERROR;

	}
	S->top++;//ջ��ָ���һ
	S->data[S->top] = e;//���²���Ԫ�ظ�ֵ��ջ�ռ�
	return OK;
}

//��ջ����
//��ջ��Ϊ�գ�ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR

Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == -1)
		return ERROR;
	*e = S->data[S->top];//��Ҫɾ����ջ��Ԫ�ظ�ֵ��e
	S->top--;//ջ��ָ��-1
	return OK;
}


