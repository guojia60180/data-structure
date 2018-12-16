#include <stdio.h>    
#include <string.h>
#include <ctype.h>      
#include <stdlib.h>   
#include <io.h>  
#include <math.h>    
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAX_LENGTH_INSERT_SORT 7 /*  ���ڿ�������ʱ�ж��Ƿ�ѡ�ò���������ֵ  */
typedef int Status;
#define MAXSIZE 10000   /*  ����Ҫ��������������ֵ���ɸ�����Ҫ�޸�  */
typedef struct
{
	int r[MAXSIZE + 1];  /*  ���ڴ洢Ҫ�������飬r[0]�����ڱ�����ʱ����  */
	int length;      /*  ���ڼ�¼˳���ĳ���  */
}SqList;
/*  ���� L ������ r ���±�Ϊ i �� j ��ֵ  */
void swap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}
void print(SqList L)
{
	int i;
	for (i = 1; i<L.length; i++)
		printf("%d,", L.r[i]);
	printf("%d", L.r[i]);
	printf("\n");
}
/*  ��˳��� L ����ѡ������  */
void SelectSort(SqList *L)
{
	int i, j, min;
	for (i = 1; i<L->length; i++)
	{
		min = i;            /*  ����ǰ�±궨��Ϊ��Сֵ�±�  */
		for (j = i + 1; j <= L->length; j++)/*  ѭ��֮�������  */
		{
			if (L->r[min]>L->r[j])  /*  �����С�ڵ�ǰ��Сֵ�Ĺؼ���  */
				min = j;        /*  ���˹ؼ��ֵ��±긳ֵ�� min */
		}
		if (i != min)            /*  �� min ������ i��˵���ҵ���Сֵ������  */
			swap(L, i, min);        /*  ���� L->r[i]�� L->r[min]��ֵ  */
	}
}