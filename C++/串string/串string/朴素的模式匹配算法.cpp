#include <string.h>
#include "vector"
#include <string>
#include <iostream>
#include "algorithm"

using namespace std;
//最简单的模式匹配
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int SElemType;

#define MAX_STRLEN 256 
typedef struct
{
	char str[MAX_STRLEN];
	int length;
} String;
int strStr(char *haystack, char *needle) {
	for (int i = 0; ; ++i)
	{
		for (int j = 0; ; ++j)
		{
			if (!needle[j]) return i; 
			if (!haystack[i + j]) return -1;
			if (needle[j] != haystack[i + j]) break;
		}
	}
}

//KMP

//避免重复的遍历的情况

//计算返回子串T的next数组



//计算模式P的部分匹配值，保存在next数组中  
void MakeNext(const string &P, vector<int> &next)
{
	int q, k;//k记录所有前缀的对称值  
	int m = P.size();//模式字符串的长度  
	next[0] = 0;//首字符的对称值肯定为0  
	for (q = 1, k = 0; q < m; ++q)//计算每一个位置的对称值  
	{
		//k总是用来记录上一个前缀的最大对称值  
		while (k > 0 && P[q] != P[k])
			k = next[k - 1];//k将循环递减，值得注意的是next[k]<k总是成立  
		if (P[q] == P[k])
			k++;//增加k的唯一方法  
		next[q] = k;//获取最终值  
	}
}


void KmpMatch(const string &T, const string &P, vector<int> &next)
{
	int n, m;
	n = T.size();
	m = P.size();
	MakeNext(P, next);
	for (int i = 0, q = 0; i < n; ++i)
	{
		while (q > 0 && P[q] != T[i])
			q = next[q - 1];
		if (P[q] == T[i])
			q++;
		if (q == m)
		{
			cout << "模式文本的偏移为：" << (i - m + 1) << endl;
			q = next[q - 1];//寻找下一个匹配
		}
	}
}

int main()
{
	system("color 0A");
	vector<int> next(20, 0);//保存待搜索字符串的部分匹配表（所有前缀函数的对称值）
	string T = "xyxababcaxxxababca";//文本
	string P = "ababca";//待搜索字符串
	cout << "文本字符串：" << T << endl;
	cout << "模式字符串：" << P << endl;
	KmpMatch(T, P, next);
	cout << "模式字符串的前缀函数表：" << endl;
	for (int i = 0; i < P.size(); i++)
		cout << next[i];
	cout << endl;
	system("pause");
	return 0;
}
