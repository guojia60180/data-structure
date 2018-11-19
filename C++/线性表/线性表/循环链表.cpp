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

p = rearA->next;
rearA->next = rearB->next->next;//将本是指向表B的第一个节点赋值给rearA-》next
q = rearB->next;
rearB->next = p;
free(q);