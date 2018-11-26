/* 树的双亲表法结点结构定义*/

#define MAX_TREE_SIZE 100

typedef int  ElemeType;

typedef struct PTNode { // 结点结构
	ElemeType data; //结点数据
	int parent;    // 双亲位置
}PTNode;

typedef struct { // 树结构
	PTNode nodes[MAX_TREE_SIZE];   // 结点数组
	int r; // 根的位置
	int n; // 结点数
}PTree;


//树的孩子表示法结构定义
#define MAX_TREE_SIZE 100
typedef struct CTNode{
	int child;
	struct CTNode *next;
}*ChildPtr;

typedef struct {
	ElemeType data;
	ChildPtr firstchild;
}CTBox;

typedef struct {
	CTBox nodes[MAX_TREE_SIZE];
	int r, n;
};

//设计两种结构
//一个是孩子链表的孩子节点
//一个是表头数组的表头结点


//树的孩子兄弟表示法结构定义
//把一棵树变成了二叉树的形式
typedef struct CSNode {
	ElemeType data;
	struct CSNode *firstchild, *rightsib;
}CSNode,*CSTree;


