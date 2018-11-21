#include <iomanip>//小数点精确
#include <cstdio>  
#include <cstdlib>  
#include "vector"
#include "string"
#include "algorithm"
#include <iostream>
#include "stack"
#include "math.h"  

using namespace std;

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


int KmpMatch(const string &T, const string &P, vector<int> &next)
{
	int n = 0, m = 0, count = 0;
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
			q = next[q - 1];//寻找下一个匹配  
			count++;
		}
	}
	return count;
}

int main()
{
	string T;//文本  
	string P;//待搜索字符串 
	vector<int> next(200, 0);//保存待搜索字符串的部分匹配表（所有前缀函数的对称值）  
	while (cin >> T >> P)
	{//本题为kmp算法的简单应用
		cout << KmpMatch(T, P, next) << endl;
	}

	return 0;
}
/**************************************************************
Problem: 1094
User: EbowTang
Language: C++
Result: Accepted
Time:160 ms
Memory:3052 kb
****************************************************************/
