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

//循环队列 顺序存储结构

typedef int QElemType;

typedef struct
{
	QElemType data[MAXSIZE];
	int front;//头指针
	int rear;//尾指针，若队列不空，指向队列队尾元素的下一个位置
}SqQueue;

//初始化一个空队列
Status InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

//返回Q的元素个数，也就是当前长度
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//插入元素
//若队列未满，则插入元素e为Q新的队尾元素
Status EnQueue(SqQueue *Q, QElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)//队列满的判断
		return ERROR;
	Q->data[Q->rear] = e;//将元素e赋值给队尾
	Q->rear = (Q->rear + 1) % MAXSIZE;//rear指针向后移1位置
	//若到最后则转到数组头部
	return OK;
}

//出队操作
//若队列不空，则删除Q中队头元素，用e返回其值

Status DeQueue(SqQueue *Q, QElemType *e)
{
	if (Q->front == Q->rear)
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;

	return OK;
}


//队列的链式存储结构实现

typedef int QElemType;

typedef struct QNode//结点结构
{
	QElemType data;
	struct QNode *next;

}QNode,*QueuePtr;

typedef struct//队列的链表结构
{
	QueuePtr front, rear;//队头队尾指针

}LinkQueue;

//入队操作
//插入元素e为Q的新的队尾元素

Status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s)//存储分配失败
		exit(0);
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	//把拥有元素e新节点s赋值给原队尾结点的后继

}

//出队操作

//若队列不为空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR

Status DeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	if (Q->front == Q->rear)
		return ERROR;
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return OK;
}