#include <stdio.h>
#include <stdlib.h>
//函数状态结果代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef char TElemType;
typedef struct Node {
	ElemType data;
	struct Node *lchild, *rchild;
}BiTnode, *BiTree;

void PreOrder(BiTree T) /*先序遍历: 根-左-右*/
{
	if (T != NULL)
	{
		Visit(T);   /*访问根节点*/
		PreOrder(T->lchild);  /*访问左子节点*/
		PreOrder(T->rchild);  /*访问右子节点*/
	}
}

void InOrder(BiTree T)/*中序遍历：左-根-右*/
{
	if (T != NULL)
	{
		InOrder(T->lchild);  //左
		Visit(T);            //根
		InOrder(T->rchild);  //右
	}
}

void PostOrder(BiTree T)/*后序遍历：左-右-根*/
{
	if (T != NULL)
	{
		PostOrder(T->lchild);  //左
		PostOrder(T->rchild);  //右
		Visit(T);              //根
	}
}

/*层序遍历 思路：按从左至右的顺序来逐层访问每个节点，层序遍历的过程需要队列*/
void LevelOrder(BiTree T)
{
	BiTree p = T;

	queue<BiTree> queue;         /*队列*/
	queue.push(p);               /*根节点入队*/

	while (!queue.empty())        /*队列不空循环 */
	{
		p = queue.front();       /*对头元素出队*/
								 //printf("%c ",p->data); /*访问p指向的结点*/
		cout << p->data << " ";

		queue.pop();             /*退出队列*/
		if (p->lchild != NULL) {   /*左子树不空，将左子树入队*/
			queue.push(p->lchild);
		}
		if (p->rchild != NULL) {   /*右子树不空，将右子树入队*/
			queue.push(p->rchild);
		}
	}
}

