/*最小生成树的生成，主要是由两种方法产生的
Prim 算法 主要是以一个结点为起点找最小的边连接另外的结点，把这两个结点作为一个整体，寻求与其相连的其他结点，逐步把图遍历完成的方法
Krustal 算法 主要是对边进行排序，先把边的周边两个结点进行放入一个集合 然后通过新的遍历找寻小值，插入该集合，看是否有边的集合两者之间都重合于该集合，遍历完全所有的结点为止
*/

//Prim生成最小生成树
//邻接矩阵的数据类型
#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MAXV 50 //最大顶点数
#define MAX 50
typedef struct
{
	int no;//顶点编号
		   //InfoType info;//顶点的其他信息
}VertexType;//顶点类型
typedef struct
{
	int edges[MAXV][MAXV];//邻接矩阵的边数组
	int n, e;//顶点数，边数
	VertexType vexs[MAXV];//存放顶点信息
}MGraph;//图邻接矩阵类型
#define INF 32767//表示无穷大

void Prim(MGraph g, int v)//普利姆算法（参数：邻接矩阵，起点（即第一个生成的点，可随便取））
{
	int lowcost[MAXV], closest[MAXV], i, min, j, k;

	/***初始化lowcost数组，closest数组(即从起点开始设置lowcost数组，closest数组相应的值，以便后续生成使用)***/
	for (i = 0; i < g.n; i++)//赋初值，即将closest数组都赋为第一个节点v，lowcost数组赋为第一个节点v到各节点的权重
	{
		closest[i] = v;
		lowcost[i] = g.edges[v][i];//g.edges[v][i]的值指的是节点v到i节点的权重
	}

	/**********************************开始生成其他的节点*********************************/
	for (i = 1; i < g.n; i++)//接下来找剩下的n-1个节点（g.n是图的节点个数）
	{

		/*****找到一个节点，该节点到已选节点中的某一个节点的权值是当前最小的*****/
		min = INF;//INF表示正无穷（每查找一个节点，min都会重新更新为INF，以便获取当前最小权重的节点）
		for (j = 0; j < g.n; j++)//遍历所有节点
		{
			if (lowcost[j] != 0 && lowcost[j] < min)//若该节点还未被选且权值小于之前遍历所得到的最小值
			{
				min = lowcost[j];//更新min的值
				k = j;//记录当前最小权重的节点的编号
			}
		}

		/****************输出被连接节点与连接节点，以及它们的权值***************/
		printf("边(%d,%d)权为:%d\n", closest[k], k, min);

		/***********更新lowcost数组，closest数组，以便生成下一个节点************/
		lowcost[k] = 0;//表明k节点已被选了(作标记)
					   //选中一个节点完成连接之后，作数组相应的调整
		for (j = 0; j < g.n; j++)//遍历所有节点
		{
			/* if语句条件的说明：
			* （1）g.edges[k][j] != 0是指k！=j，即跳过自身的节点
			* （2）g.edges[k][j]是指刚被选的节点k到节点j的权重，lowcost[j]是指之前遍历的所有节点与j节点的最小权重。若g.edges[k][j] < lowcost[j],则说明当前刚被选的节点k与节点j之间存在更小的权重，则需要更新
			* （3）有人会问：为什么只跳过掉自身的节点（即k==j），而不跳过所有的已选节点？当然我们可以在if语句条件中增加跳过所有的已选节点的条件（即lowcost[j] == 0），而在本程序中我们只跳过了自身的节点？（注意：我们假设图中的边的权值大于0）但其实不是，g.edges[k][j] < lowcost[j]条件已包含跳过所有的已选节点，原因是在邻接矩阵中权值为0是最小的，即g.edges[k][j]>=0，而已选节点满足lowcost[j] == 0，则已选节点j是不满足g.edges[k][j] < lowcost[j]，则会被跳过
			*/
			if (g.edges[k][j] != 0 && g.edges[k][j] < lowcost[j])
			{
				//更新lowcost数组，closest数组
				lowcost[j] = g.edges[k][j];//更新权重，使其当前最小
				closest[j] = k;//进入到该if语句里，说明刚选的节点k与当前节点j有更小的权重，则closest[j]的被连接节点需作修改为k
			}
		}
	}
}

//Kruskal 算法实现
// 邻接矩阵
typedef struct _graph
{
	char vexs[MAX];       // 顶点集合
	int vexnum;           // 顶点数
	int edgnum;           // 边数
	int matrix[MAX][MAX]; // 邻接矩阵
}Graph, *PGraph;

// 边的结构体
typedef struct _EdgeData
{
	char start; // 边的起点
	char end;   // 边的终点
	int weight; // 边的权重
}EData;

/*
* 克鲁斯卡尔（Kruskal)最小生成树
*/
void kruskal(Graph G)
{
	int i, m, n, p1, p2;
	int length;
	int index = 0;          // rets数组的索引
	int vends[MAX] = { 0 };     // 用于保存"已有最小生成树"中每个顶点在该最小树中的终点。
	EData rets[MAX];        // 结果数组，保存kruskal最小生成树的边
	EData *edges;           // 图对应的所有边

							// 获取"图中所有的边"
	edges = get_edges(G);
	// 将边按照"权"的大小进行排序(从小到大)
	sorted_edges(edges, G.edgnum);

	for (i = 0; i<G.edgnum; i++)
	{
		p1 = get_position(G, edges[i].start);   // 获取第i条边的"起点"的序号
		p2 = get_position(G, edges[i].end);     // 获取第i条边的"终点"的序号

		m = get_end(vends, p1);                 // 获取p1在"已有的最小生成树"中的终点
		n = get_end(vends, p2);                 // 获取p2在"已有的最小生成树"中的终点
												// 如果m!=n，意味着"边i"与"已经添加到最小生成树中的顶点"没有形成环路
		if (m != n)
		{
			vends[m] = n;                       // 设置m在"已有的最小生成树"中的终点为n
			rets[index++] = edges[i];           // 保存结果
		}
	}
	free(edges);

	// 统计并打印"kruskal最小生成树"的信息
	length = 0;
	for (i = 0; i < index; i++)
		length += rets[i].weight;
	printf("Kruskal=%d: ", length);
	for (i = 0; i < index; i++)
		printf("(%c,%c) ", rets[i].start, rets[i].end);
	printf("\n");
}
// 边的结构体
typedef struct _EdgeData
{
	char start; // 边的起点
	char end;   // 边的终点
	int weight; // 边的权重
}EData;


/*
* 返回ch在matrix矩阵中的位置
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
				// 交换"第i条边"和"第j条边"
				EData tmp = edges[i];
				edges[i] = edges[j];
				edges[j] = tmp;
			}
		}
	}
}

/*
* 获取i的终点
*/
int get_end(int vends[], int i)
{
	while (vends[i] != 0)
		i = vends[i];
	return i;
}
/*
* 获取图中的边
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