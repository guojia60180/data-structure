#include <iostream>
using namespace std;

typedef int TElemType;
typedef struct BTNode //���ṹ
{
	TElemType data;//�������
	struct BTNode *lchild, *rchild; //���Һ���ָ��
}BNode, *BTree;
//�����������㣨��dֵ���뵽�������е���Ӧλ�ã�
BTree Insert_tree(BTree root, TElemType d)
{
	BNode * newnode;
	BNode * curnode;
	BNode * parnode;
	newnode = (BNode *)malloc(sizeof(BNode));
	newnode->data = d;
	newnode->lchild = NULL;
	newnode->rchild = NULL;
	if (root == NULL)
		return newnode; //��Ϊ����㷵��
	else
	{
		curnode = root;
		while (curnode != NULL)
		{
			parnode = curnode;//���游���
			if (d<curnode->data)
				curnode = curnode->lchild;
			else
				curnode = curnode->rchild;
		}
		if (d<parnode->data)
			parnode->lchild = newnode;
		else
			parnode->rchild = newnode;
	}
	return root;
}
//����data��Ϊx�Ľ��ָ��
BTree Find_Node(BTree root, TElemType x)
{
	BTree p;
	if (root == NULL || root->data == x)
		return root;
	else if (x>root->data)
		p = Find_Node(root->lchild, x); //����������
	else
		p = Find_Node(root->rchild, x); //����������
	return p;
}
//ͳ�ƶ����������
/*
������������ȴ���������ʱ���򷵻������������+1�����򷵻������������+1
��rootΪҶ�ӽ��ʱ��ֹͣ�ݹ飬����1��Ȼ����������ۼӡ�
*/
int BTDepth(BTree root)
{
	int ldepth, rdepth;
	if (root == NULL)
		return 0;
	else
	{
		ldepth = BTDepth(root->lchild);
		rdepth = BTDepth(root->rchild);
		return (ldepth>rdepth) ? (ldepth + 1) : (rdepth + 1);
	}
}
