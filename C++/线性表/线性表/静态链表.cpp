#define MAXSIZE 1000
#include <stdlib.h>
#include <time.h>
/*顺序结构的存储结构代码*/

typedef int ElemType;


/*顺序存储结构的插入与删除*/

/*获得元素操作*/

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
/*Status 是函数的类型，值是函数状态码*/
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
	space[MAXSIZE - 1].cur = 0;//最后一个元素的cur为0，指向的是第一个数据
	return OK;
}


//静态列表的插入

int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur;
	//当前数组第一个元素cur存的值，返回第一个备用空闲的下标
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

//静态列表删除

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
