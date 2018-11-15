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
typedef struct
{
	ElemType data;
	int cur;
}Component,StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space)
{
	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;//���һ��Ԫ�ص�curΪ0��ָ����ǵ�һ������
	return OK;
}


//��̬�б�Ĳ���

int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur;
	//��ǰ�����һ��Ԫ��cur���ֵ�����ص�һ�����ÿ��е��±�
	if (space[0].cur)
		space[0].cur = space[i].cur;

	return i;
}

Status ListInsert(StaticLinkList L, int i, ElemType e)
{
	int j, k, l;
	k = MAXSIZE - 1;
	if (i<1 || i>ListLength(L) + 1)
		return ERROR;
	j = Malloc_SLL(L);
	if (j)
	{
		L[j].data = e;
		for (l = 1; l <= i - 1; l++)
			k = L[k].cur;
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return OK;

	}
	return ERROR;
}

//��̬�б�ɾ��

Status ListDelete(StaticLinkList L, int i)
{
	int j, k;
	if (i<1 || i>ListLength(L))
		return ERROR;
	k = MAXSIZE - 1;
	for (j = 1; j <= 1; j++)
		k = L[k].cur;
	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SSL(L, j);
	return OK;
}

void Free_SSL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

int ListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while (i)
	{
		i = L[i].cur;
		j++;
	}
	return j;
}
