#define MAXSIZE 1000
#include <stdlib.h>
#include <time.h>
/*˳��ṹ�Ĵ洢�ṹ����*/

typedef int ElemType;


/*˳��洢�ṹ�Ĳ�����ɾ��*/

/*���Ԫ�ز���*/

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
/*Status �Ǻ��������ͣ�ֵ�Ǻ���״̬��*/

/*�����������*/
typedef struct Node {
	ElemType data;
	struct  Node *next;

}Node;

typedef struct Node *LinkList;


/*������Ķ�ȡ*/

Status GetElem(LinkList L, int i, ElemType *e)
{
	int j;
	LinkList p;
	p = L->next;
	j = 1;
	while (p&&j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;
	*e = p->data;
	return OK;
}

p = rearA->next;
rearA->next = rearB->next->next;//������ָ���B�ĵ�һ���ڵ㸳ֵ��rearA-��next
q = rearB->next;
rearB->next = p;
free(q);