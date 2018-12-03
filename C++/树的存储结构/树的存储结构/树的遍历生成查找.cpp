#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define MAX 1000
#define LENGTH 100
typedef char datatype;
typedef struct node {
	datatype data;
	int lchild, rchild;
	int parent;
}Node;

Node tree[LENGTH];
int length;
int root;



typedef struct BinNode {
	datatype data;
	struct BinNode* lchild;
	struct BinNode* rchild;
}BinNode;

typedef BinNode* bintree;          //bintree本身是个指向结点的指针

//递归实现
void preorder(bintree t) {
	if (t) {
		printf("%c ", t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

//非递归实现
typedef struct seqstack {
	bintree data[SIZE];
	int tag[SIZE];   //为后续遍历准备的
	int top;     //top为数组的下标
}seqstack;

void push(seqstack *s, bintree t) {

	if (s->top == SIZE) {
		printf("the stack is full\n");
	}
	else {
		s->top++;
		s->data[s->top] = t;
	}
}

bintree pop(seqstack *s) {
	if (s->top == -1) {
		return NULL;
	}
	else {
		s->top--;
		return s->data[s->top + 1];
	}
}
//前序遍历
void preorder_dev(bintree t) {
	seqstack s;
	s.top = -1;     //因为top在这里表示了数组中的位置，所以空为-1
	if (!t) {
		printf("the tree is empty\n");
	}
	else {
		while (t || s.top != -1) {
			while (t) {    //只要结点不为空就应该入栈保存，与其左右结点无关    
				printf("%c ", t->data);
				push(&s, t);
				t = t->lchild;
			}
			t = pop(&s);
			t = t->rchild;
		}
	}
}


//中序遍历
void midorder(bintree t) {
	seqstack s;
	s.top = -1;
	if (!t) {
		printf("the tree is empty!\n");
	}
	else {
		while (t || s.top != -1) {
			while (t) {
				push(&s, t);
				t = t->lchild;
			}
			t = pop(&s);
			printf("%c ", t->data);
			t = t->rchild;
		}
	}
}

//后序遍历
void postorder_dev(bintree t) {
	seqstack s;
	s.top = -1;
	if (!t) {
		printf("the tree is empty!\n");
	}
	else {
		while (t || s.top != -1) {    //栈空了的同时t也为空。
			while (t) {
				push(&s, t);
				s.tag[s.top] = 0;   //设置访问标记，0为第一次访问，1为第二次访问
				t = t->lchild;
			}
			if (s.tag[s.top] == 0) {  //第一次访问时，转向同层右结点
				t = s.data[s.top];   //左走到底时t是为空的，必须有这步！
				s.tag[s.top] = 1;
				t = t->rchild;
			}
			else {
				while (s.tag[s.top] == 1) { //找到栈中下一个第一次访问的结点，退出循环时并没有pop所以为其左子结点
					t = pop(&s);
					printf("%c ", t->data);
				}
				t = NULL; //必须将t置空。跳过向左走，直接向右走
			}
		}
	}
}


//层次遍历
//采用队列来进行存储

typedef struct seqqueue {
	bintree data[MAX];
	int front;
	int rear;
}seqqueue;


void enter(seqqueue *q, bintree t) {
	if (q->rear == MAX) {
		printf("the queue is full!\n");
	}
	else {
		q->data[q->rear] = t;
		q->rear++;
	}
}

bintree del(seqqueue *q) {
	if (q->front == q->rear) {
		return NULL;
	}
	else {
		q->front++;
		return q->data[q->front - 1];
	}
}


void level_tree(bintree t) {
	seqqueue q;
	bintree temp;
	q.front = q.rear = 0;
	if (!t) {
		printf("the tree is empty\n");
		return;
	}
	enter(&q, t);
	while (q.front != q.rear) {
		t = del(&q);
		printf("%c ", t->data);
		if (t->lchild) {
			enter(&q, t->lchild);
		}
		if (t->rchild) {
			enter(&q, t->rchild);
		}
	}
}

//利用前序遍历的结果生成二叉树

//递归调用，不存点，想的时候只关注于一个点，因为还会回来的，不要跟踪程序运行，否则容易多加循环

void createtree(bintree *t) {
	datatype c;
	if ((c = getchar()) == '#')
		*t = NULL;
	else {
		*t = (bintree)malloc(sizeof(BinNode));
		(*t)->data = c;
		createtree(&(*t)->lchild);
		createtree(&(*t)->rchild);
	}
}
//二叉树查找
bintree search_tree(bintree t, datatype x) {
	if (!t) {
		return NULL;
	}
	if (t->data == x) {
		return t;
	}
	else {
		if (!search_tree(t->lchild, x)) {
			return search_tree(t->rchild, x);
		}
		return t;
	}
}
//统计结点个数
int count_tree(bintree t) {
	if (t) {
		return (count_tree(t->lchild) + count_tree(t->rchild) + 1);
	}
	return 0;
}

//比较两个结点是否相同
int is_equal(bintree t1, bintree t2) {
	if (!t1 && !t2) {      //都为空就相等
		return 1;
	}
	if (t1 && t2 && t1->data == t2->data) {      //有一个为空或数据不同就不判断了
		if (is_equal(t1->lchild, t2->lchild))
			if (is_equal(t1->rchild, t2->rchild)) {
				return 1;
			}
	}
	return 0;
}

//求一个二叉树的深度
int hight_tree(bintree t) {
	int h, left, right;
	if (!t) {
		return 0;
	}
	left = hight_tree(t->lchild);
	right = hight_tree(t->rchild);
	h = (left>right ? left : right) + 1;
	return h;
}
