#include <iostream>
using namespace std;

typedef int TElemType;
typedef struct BTNode //结点结构
{
	TElemType data;//结点数据
	struct BTNode *lchild, *rchild; //左右孩子指针
}BNode, *BTree;
//插入二叉树结点（将d值插入到二叉树中的相应位置）
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
		return newnode; //作为根结点返回
	else
	{
		curnode = root;
		while (curnode != NULL)
		{
			parnode = curnode;//保存父结点
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
//返回data域为x的结点指针
BTree Find_Node(BTree root, TElemType x)
{
	BTree p;
	if (root == NULL || root->data == x)
		return root;
	else if (x>root->data)
		p = Find_Node(root->lchild, x); //访问左子树
	else
		p = Find_Node(root->rchild, x); //访问右子树
	return p;
}
//统计二叉树的深度
/*
当左子树的深度大于右子树时，则返回左子树的深度+1，否则返回右子树的深度+1
当root为叶子结点时，停止递归，返回1，然后逐层向上累加。
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
