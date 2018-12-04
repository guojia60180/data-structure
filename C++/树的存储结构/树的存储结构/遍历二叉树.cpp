#include <stdio.h>
#include <stdlib.h>
//����״̬�������
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;
typedef char TElemType;
typedef struct Node {
	ElemType data;
	struct Node *lchild, *rchild;
}BiTnode, *BiTree;

void PreOrder(BiTree T) /*�������: ��-��-��*/
{
	if (T != NULL)
	{
		Visit(T);   /*���ʸ��ڵ�*/
		PreOrder(T->lchild);  /*�������ӽڵ�*/
		PreOrder(T->rchild);  /*�������ӽڵ�*/
	}
}

void InOrder(BiTree T)/*�����������-��-��*/
{
	if (T != NULL)
	{
		InOrder(T->lchild);  //��
		Visit(T);            //��
		InOrder(T->rchild);  //��
	}
}

void PostOrder(BiTree T)/*�����������-��-��*/
{
	if (T != NULL)
	{
		PostOrder(T->lchild);  //��
		PostOrder(T->rchild);  //��
		Visit(T);              //��
	}
}

/*������� ˼·�����������ҵ�˳����������ÿ���ڵ㣬��������Ĺ�����Ҫ����*/
void LevelOrder(BiTree T)
{
	BiTree p = T;

	queue<BiTree> queue;         /*����*/
	queue.push(p);               /*���ڵ����*/

	while (!queue.empty())        /*���в���ѭ�� */
	{
		p = queue.front();       /*��ͷԪ�س���*/
								 //printf("%c ",p->data); /*����pָ��Ľ��*/
		cout << p->data << " ";

		queue.pop();             /*�˳�����*/
		if (p->lchild != NULL) {   /*���������գ������������*/
			queue.push(p->lchild);
		}
		if (p->rchild != NULL) {   /*���������գ������������*/
			queue.push(p->rchild);
		}
	}
}

