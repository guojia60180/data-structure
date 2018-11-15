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
/*Status 是函数的类型，值是函数状态码*/
/*对链表的描述*/
typedef struct Node {
	ElemType data;
	struct  Node *next;

}Node;

typedef struct Node *LinkList;


/*单链表的读取*/

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

/*单链表的插入与删除*/

Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while (p&&j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));/*存放结点Node*/
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e)
{
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while (p->next&&j < i)
	{
		p = p->next;
		++j;

	}
	if (!(p->next) || j > i)
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

/*整表的创建*/
/*头插法*/
void CreateListHead(LinkList *L, int n)
{
	LinkList p;
	int i;
	srand(time(0));/*初始化随机种子*/
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

/*尾插法*/
void CreatListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for (i = 0; i < n; i++)
	{
		p = (Node *)malloc(sizeof(Node));
		p->data= rand() % 100 + 1;
		r->next = p;
		r = p;

	}
	r->next = NULL;
}

/*单链表的整表删除*/
Status ClearList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;
		free (p);
		p = q;

	}
	(*L)->next = NULL;
	return OK;

}