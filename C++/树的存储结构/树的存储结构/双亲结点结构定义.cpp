/* ����˫�ױ����ṹ����*/

#define MAX_TREE_SIZE 100

typedef int  ElemeType;

typedef struct PTNode { // ���ṹ
	ElemeType data; //�������
	int parent;    // ˫��λ��
}PTNode;

typedef struct { // ���ṹ
	PTNode nodes[MAX_TREE_SIZE];   // �������
	int r; // ����λ��
	int n; // �����
}PTree;


//���ĺ��ӱ�ʾ���ṹ����
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

//������ֽṹ
//һ���Ǻ�������ĺ��ӽڵ�
//һ���Ǳ�ͷ����ı�ͷ���


//���ĺ����ֵܱ�ʾ���ṹ����
//��һ��������˶���������ʽ
typedef struct CSNode {
	ElemeType data;
	struct CSNode *firstchild, *rightsib;
}CSNode,*CSTree;


