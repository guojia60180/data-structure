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
/*  对顺序表 L 作简单选择排序  */
void SelectSort(SqList *L)
{
	int i, j, min;
	for (i = 1; i<L->length; i++)
	{
		min = i;            /*  将当前下标定义为最小值下标  */
		for (j = i + 1; j <= L->length; j++)/*  循环之后的数据  */
		{
			if (L->r[min]>L->r[j])  /*  如果有小于当前最小值的关键字  */
				min = j;        /*  将此关键字的下标赋值给 min */
		}
		if (i != min)            /*  若 min 不等于 i，说明找到最小值，交换  */
			swap(L, i, min);        /*  交换 L->r[i]与 L->r[min]的值  */
	}
}