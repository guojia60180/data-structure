/*��С�����������ɣ���Ҫ�������ַ���������
Prim �㷨 ��Ҫ����һ�����Ϊ�������С�ı���������Ľ�㣬�������������Ϊһ�����壬Ѱ������������������㣬�𲽰�ͼ������ɵķ���
Krustal �㷨 ��Ҫ�ǶԱ߽��������Ȱѱߵ��ܱ����������з���һ������ Ȼ��ͨ���µı�����ѰСֵ������ü��ϣ����Ƿ��бߵļ�������֮�䶼�غ��ڸü��ϣ�������ȫ���еĽ��Ϊֹ
*/

//Prim������С������
//�ڽӾ������������
#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MAXV 50 //��󶥵���
#define MAX 50
typedef struct
{
	int no;//������
		   //InfoType info;//�����������Ϣ
}VertexType;//��������
typedef struct
{
	int edges[MAXV][MAXV];//�ڽӾ���ı�����
	int n, e;//������������
	VertexType vexs[MAXV];//��Ŷ�����Ϣ
}MGraph;//ͼ�ڽӾ�������
#define INF 32767//��ʾ�����

void Prim(MGraph g, int v)//����ķ�㷨���������ڽӾ�����㣨����һ�����ɵĵ㣬�����ȡ����
{
	int lowcost[MAXV], closest[MAXV], i, min, j, k;

	/***��ʼ��lowcost���飬closest����(������㿪ʼ����lowcost���飬closest������Ӧ��ֵ���Ա��������ʹ��)***/
	for (i = 0; i < g.n; i++)//����ֵ������closest���鶼��Ϊ��һ���ڵ�v��lowcost���鸳Ϊ��һ���ڵ�v�����ڵ��Ȩ��
	{
		closest[i] = v;
		lowcost[i] = g.edges[v][i];//g.edges[v][i]��ֵָ���ǽڵ�v��i�ڵ��Ȩ��
	}

	/**********************************��ʼ���������Ľڵ�*********************************/
	for (i = 1; i < g.n; i++)//��������ʣ�µ�n-1���ڵ㣨g.n��ͼ�Ľڵ������
	{

		/*****�ҵ�һ���ڵ㣬�ýڵ㵽��ѡ�ڵ��е�ĳһ���ڵ��Ȩֵ�ǵ�ǰ��С��*****/
		min = INF;//INF��ʾ�����ÿ����һ���ڵ㣬min�������¸���ΪINF���Ա��ȡ��ǰ��СȨ�صĽڵ㣩
		for (j = 0; j < g.n; j++)//�������нڵ�
		{
			if (lowcost[j] != 0 && lowcost[j] < min)//���ýڵ㻹δ��ѡ��ȨֵС��֮ǰ�������õ�����Сֵ
			{
				min = lowcost[j];//����min��ֵ
				k = j;//��¼��ǰ��СȨ�صĽڵ�ı��
			}
		}

		/****************��������ӽڵ������ӽڵ㣬�Լ����ǵ�Ȩֵ***************/
		printf("��(%d,%d)ȨΪ:%d\n", closest[k], k, min);

		/***********����lowcost���飬closest���飬�Ա�������һ���ڵ�************/
		lowcost[k] = 0;//����k�ڵ��ѱ�ѡ��(�����)
					   //ѡ��һ���ڵ��������֮����������Ӧ�ĵ���
		for (j = 0; j < g.n; j++)//�������нڵ�
		{
			/* if���������˵����
			* ��1��g.edges[k][j] != 0��ָk��=j������������Ľڵ�
			* ��2��g.edges[k][j]��ָ�ձ�ѡ�Ľڵ�k���ڵ�j��Ȩ�أ�lowcost[j]��ָ֮ǰ���������нڵ���j�ڵ����СȨ�ء���g.edges[k][j] < lowcost[j],��˵����ǰ�ձ�ѡ�Ľڵ�k��ڵ�j֮����ڸ�С��Ȩ�أ�����Ҫ����
			* ��3�����˻��ʣ�Ϊʲôֻ����������Ľڵ㣨��k==j���������������е���ѡ�ڵ㣿��Ȼ���ǿ�����if��������������������е���ѡ�ڵ����������lowcost[j] == 0�������ڱ�����������ֻ����������Ľڵ㣿��ע�⣺���Ǽ���ͼ�еıߵ�Ȩֵ����0������ʵ���ǣ�g.edges[k][j] < lowcost[j]�����Ѱ����������е���ѡ�ڵ㣬ԭ�������ڽӾ�����ȨֵΪ0����С�ģ���g.edges[k][j]>=0������ѡ�ڵ�����lowcost[j] == 0������ѡ�ڵ�j�ǲ�����g.edges[k][j] < lowcost[j]����ᱻ����
			*/
			if (g.edges[k][j] != 0 && g.edges[k][j] < lowcost[j])
			{
				//����lowcost���飬closest����
				lowcost[j] = g.edges[k][j];//����Ȩ�أ�ʹ�䵱ǰ��С
				closest[j] = k;//���뵽��if����˵����ѡ�Ľڵ�k�뵱ǰ�ڵ�j�и�С��Ȩ�أ���closest[j]�ı����ӽڵ������޸�Ϊk
			}
		}
	}
}

//Kruskal �㷨ʵ��
// �ڽӾ���
typedef struct _graph
{
	char vexs[MAX];       // ���㼯��
	int vexnum;           // ������
	int edgnum;           // ����
	int matrix[MAX][MAX]; // �ڽӾ���
}Graph, *PGraph;

// �ߵĽṹ��
typedef struct _EdgeData
{
	char start; // �ߵ����
	char end;   // �ߵ��յ�
	int weight; // �ߵ�Ȩ��
}EData;

/*
* ��³˹������Kruskal)��С������
*/
void kruskal(Graph G)
{
	int i, m, n, p1, p2;
	int length;
	int index = 0;          // rets���������
	int vends[MAX] = { 0 };     // ���ڱ���"������С������"��ÿ�������ڸ���С���е��յ㡣
	EData rets[MAX];        // ������飬����kruskal��С�������ı�
	EData *edges;           // ͼ��Ӧ�����б�

							// ��ȡ"ͼ�����еı�"
	edges = get_edges(G);
	// ���߰���"Ȩ"�Ĵ�С��������(��С����)
	sorted_edges(edges, G.edgnum);

	for (i = 0; i<G.edgnum; i++)
	{
		p1 = get_position(G, edges[i].start);   // ��ȡ��i���ߵ�"���"�����
		p2 = get_position(G, edges[i].end);     // ��ȡ��i���ߵ�"�յ�"�����

		m = get_end(vends, p1);                 // ��ȡp1��"���е���С������"�е��յ�
		n = get_end(vends, p2);                 // ��ȡp2��"���е���С������"�е��յ�
												// ���m!=n����ζ��"��i"��"�Ѿ���ӵ���С�������еĶ���"û���γɻ�·
		if (m != n)
		{
			vends[m] = n;                       // ����m��"���е���С������"�е��յ�Ϊn
			rets[index++] = edges[i];           // ������
		}
	}
	free(edges);

	// ͳ�Ʋ���ӡ"kruskal��С������"����Ϣ
	length = 0;
	for (i = 0; i < index; i++)
		length += rets[i].weight;
	printf("Kruskal=%d: ", length);
	for (i = 0; i < index; i++)
		printf("(%c,%c) ", rets[i].start, rets[i].end);
	printf("\n");
}
// �ߵĽṹ��
typedef struct _EdgeData
{
	char start; // �ߵ����
	char end;   // �ߵ��յ�
	int weight; // �ߵ�Ȩ��
}EData;


/*
* ����ch��matrix�����е�λ��
*/
static int get_position(Graph G, char ch)
{
	int i;
	for (i = 0; i<G.vexnum; i++)
		if (G.vexs[i] == ch)
			return i;
	return -1;
}

void sorted_edges(EData* edges, int elen)
{
	int i, j;

	for (i = 0; i<elen; i++)
	{
		for (j = i + 1; j<elen; j++)
		{
			if (edges[i].weight > edges[j].weight)
			{
				// ����"��i����"��"��j����"
				EData tmp = edges[i];
				edges[i] = edges[j];
				edges[j] = tmp;
			}
		}
	}
}

/*
* ��ȡi���յ�
*/
int get_end(int vends[], int i)
{
	while (vends[i] != 0)
		i = vends[i];
	return i;
}
/*
* ��ȡͼ�еı�
*/
EData* get_edges(Graph G)
{
	int i, j;
	int index = 0;
	EData *edges;

	edges = (EData*)malloc(G.edgnum * sizeof(EData));
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = i + 1; j < G.vexnum; j++)
		{
			if (G.matrix[i][j] != INF)
			{
				edges[index].start = G.vexs[i];
				edges[index].end = G.vexs[j];
				edges[index].weight = G.matrix[i][j];
				index++;
			}
		}
	}

	return edges;
}