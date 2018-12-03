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

typedef BinNode* bintree;          //bintree�����Ǹ�ָ�����ָ��

//�ݹ�ʵ��
void preorder(bintree t) {
	if (t) {
		printf("%c ", t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

//�ǵݹ�ʵ��
typedef struct seqstack {
	bintree data[SIZE];
	int tag[SIZE];   //Ϊ��������׼����
	int top;     //topΪ������±�
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
//ǰ�����
void preorder_dev(bintree t) {
	seqstack s;
	s.top = -1;     //��Ϊtop�������ʾ�������е�λ�ã����Կ�Ϊ-1
	if (!t) {
		printf("the tree is empty\n");
	}
	else {
		while (t || s.top != -1) {
			while (t) {    //ֻҪ��㲻Ϊ�վ�Ӧ����ջ���棬�������ҽ���޹�    
				printf("%c ", t->data);
				push(&s, t);
				t = t->lchild;
			}
			t = pop(&s);
			t = t->rchild;
		}
	}
}


//�������
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

//�������
void postorder_dev(bintree t) {
	seqstack s;
	s.top = -1;
	if (!t) {
		printf("the tree is empty!\n");
	}
	else {
		while (t || s.top != -1) {    //ջ���˵�ͬʱtҲΪ�ա�
			while (t) {
				push(&s, t);
				s.tag[s.top] = 0;   //���÷��ʱ�ǣ�0Ϊ��һ�η��ʣ�1Ϊ�ڶ��η���
				t = t->lchild;
			}
			if (s.tag[s.top] == 0) {  //��һ�η���ʱ��ת��ͬ���ҽ��
				t = s.data[s.top];   //���ߵ���ʱt��Ϊ�յģ��������ⲽ��
				s.tag[s.top] = 1;
				t = t->rchild;
			}
			else {
				while (s.tag[s.top] == 1) { //�ҵ�ջ����һ����һ�η��ʵĽ�㣬�˳�ѭ��ʱ��û��pop����Ϊ�����ӽ��
					t = pop(&s);
					printf("%c ", t->data);
				}
				t = NULL; //���뽫t�ÿա����������ߣ�ֱ��������
			}
		}
	}
}


//��α���
//���ö��������д洢

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

//����ǰ������Ľ�����ɶ�����

//�ݹ���ã�����㣬���ʱ��ֻ��ע��һ���㣬��Ϊ��������ģ���Ҫ���ٳ������У��������׶��ѭ��

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
//����������
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
//ͳ�ƽ�����
int count_tree(bintree t) {
	if (t) {
		return (count_tree(t->lchild) + count_tree(t->rchild) + 1);
	}
	return 0;
}

//�Ƚ���������Ƿ���ͬ
int is_equal(bintree t1, bintree t2) {
	if (!t1 && !t2) {      //��Ϊ�վ����
		return 1;
	}
	if (t1 && t2 && t1->data == t2->data) {      //��һ��Ϊ�ջ����ݲ�ͬ�Ͳ��ж���
		if (is_equal(t1->lchild, t2->lchild))
			if (is_equal(t1->rchild, t2->rchild)) {
				return 1;
			}
	}
	return 0;
}

//��һ�������������
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
