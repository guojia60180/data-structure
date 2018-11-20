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

//ѭ������ ˳��洢�ṹ

typedef int QElemType;

typedef struct
{
	QElemType data[MAXSIZE];
	int front;//ͷָ��
	int rear;//βָ�룬�����в��գ�ָ����ж�βԪ�ص���һ��λ��
}SqQueue;

//��ʼ��һ���ն���
Status InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

//����Q��Ԫ�ظ�����Ҳ���ǵ�ǰ����
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//����Ԫ��
//������δ���������Ԫ��eΪQ�µĶ�βԪ��
Status EnQueue(SqQueue *Q, QElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)//���������ж�
		return ERROR;
	Q->data[Q->rear] = e;//��Ԫ��e��ֵ����β
	Q->rear = (Q->rear + 1) % MAXSIZE;//rearָ�������1λ��
	//���������ת������ͷ��
	return OK;
}

//���Ӳ���
//�����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ

Status DeQueue(SqQueue *Q, QElemType *e)
{
	if (Q->front == Q->rear)
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;

	return OK;
}


//���е���ʽ�洢�ṹʵ��

typedef int QElemType;

typedef struct QNode//���ṹ
{
	QElemType data;
	struct QNode *next;

}QNode,*QueuePtr;

typedef struct//���е�����ṹ
{
	QueuePtr front, rear;//��ͷ��βָ��

}LinkQueue;

//��Ӳ���
//����Ԫ��eΪQ���µĶ�βԪ��

Status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s)//�洢����ʧ��
		exit(0);
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	//��ӵ��Ԫ��e�½ڵ�s��ֵ��ԭ��β���ĺ��

}

//���Ӳ���

//�����в�Ϊ�գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR

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