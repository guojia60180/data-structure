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
/*  ��˳��� L ����������ð����������棩  */
void BubbleSort0(SqList *L)
{
	int i, j;
	for (i = 1; i<L->length; i++)
	{
		for (j = i + 1; j <= L->length; j++)
		{
			if (L->r[i]>L->r[j])
			{
				swap(L, i, j);/*  ���� L->r[i]�� L->r[j]��ֵ  */
			}
		}
	}
}
/*  ��˳��� L ��ð������  */
void BubbleSort(SqList *L)
{
	int i, j;
	for (i = 1; i<L->length; i++)
	{
		for (j = L->length - 1; j >= i; j--)   /*  ע�� j �ǴӺ���ǰѭ��  */
		{
			if (L->r[j]>L->r[j + 1]) /*  ��ǰ�ߴ��ں��ߣ�ע����������һ�㷨�Ĳ��죩*/
			{
				swap(L, j, j + 1);/*  ���� L->r[j]�� L->r[j+1]��ֵ  */
			}
		}
	}
}
/*  ��˳��� L ���Ľ�ð���㷨  */
void BubbleSort2(SqList *L)
{
	int i, j;
	Status flag = TRUE;      /* flag ������Ϊ���  */
	for (i = 1; i<L->length && flag; i++) /*  �� flag Ϊ true ˵���й����ݽ���������ֹͣѭ��  */
	{
		flag = FALSE;        /*  ��ʼΪ False */
		for (j = L->length - 1; j >= i; j--)
		{
			if (L->r[j]>L->r[j + 1])
			{
				swap(L, j, j + 1);  /*  ���� L->r[j]�� L->r[j+1]��ֵ  */
				flag = TRUE;    /*  ��������ݽ������� flag Ϊ true */
			}
		}
	}
}