#include <stdio.h>
#include <stdlib.h>
#define  MAX_VERTEX_NUM 20//��󶥵����

typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode
{
	int adjvex;
	EdgeType weight;
	struct EdgeNode *next;
	
}EdgeNode;

typedef struct VertexNode
{
	VertexType data;
	EdgeNode *firstedge;
}VertexNode, AdjList[MAX_VERTEX_NUM];

typedef struct {

	AdjList adjList;
	int numVertexes, numEdges;
}GraphAdjList;


//����ͼ���ڽӱ�ṹ
void CreateALGraph(GraphAdjList *G)
{
	int i, j, k;
	EdgeNode *e;
	printf("���붥�����ͱ���");
	scanf("%d,%d", &G->numVertexes, &G->numEdges);
	for (i = 0; i < G->numVertexes; i++)
	{
		scanf(&G->adjList[i].data);
		G->adjList[i].firstedge = NULL;
	}
	for (k = 0; k < G->numEdges; k++)
	{
		printf("����ߵĶ������");
		scanf("%d,%d", &i, &j);
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;

	}
}

//������ͷ�巨