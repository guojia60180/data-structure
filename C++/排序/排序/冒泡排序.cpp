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
#define MAX_LENGTH_INSERT_SORT 7 /*  用于快速排序时判断是否选用插入排序阙值  */
typedef int Status;
#define MAXSIZE 10000   /*  用于要排序数组个数最大值，可根据需要修改  */
typedef struct
{
	int r[MAXSIZE + 1];  /*  用于存储要排序数组，r[0]用作哨兵或临时变量  */
	int length;      /*  用于记录顺序表的长度  */
}SqList;
/*  交换 L 中数组 r 的下标为 i 和 j 的值  */
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
/*  对顺序表 L 作交换排序（冒泡排序初级版）  */
void BubbleSort0(SqList *L)
{
	int i, j;
	for (i = 1; i<L->length; i++)
	{
		for (j = i + 1; j <= L->length; j++)
		{
			if (L->r[i]>L->r[j])
			{
				swap(L, i, j);/*  交换 L->r[i]与 L->r[j]的值  */
			}
		}
	}
}
/*  对顺序表 L 作冒泡排序  */
void BubbleSort(SqList *L)
{
	int i, j;
	for (i = 1; i<L->length; i++)
	{
		for (j = L->length - 1; j >= i; j--)   /*  注意 j 是从后往前循环  */
		{
			if (L->r[j]>L->r[j + 1]) /*  若前者大于后者（注意这里与上一算法的差异）*/
			{
				swap(L, j, j + 1);/*  交换 L->r[j]与 L->r[j+1]的值  */
			}
		}
	}
}
/*  对顺序表 L 作改进冒泡算法  */
void BubbleSort2(SqList *L)
{
	int i, j;
	Status flag = TRUE;      /* flag 用来作为标记  */
	for (i = 1; i<L->length && flag; i++) /*  若 flag 为 true 说明有过数据交换，否则停止循环  */
	{
		flag = FALSE;        /*  初始为 False */
		for (j = L->length - 1; j >= i; j--)
		{
			if (L->r[j]>L->r[j + 1])
			{
				swap(L, j, j + 1);  /*  交换 L->r[j]与 L->r[j+1]的值  */
				flag = TRUE;    /*  如果有数据交换，则 flag 为 true */
			}
		}
	}
}