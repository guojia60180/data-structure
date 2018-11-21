#include <iomanip>//С���㾫ȷ
#include <cstdio>  
#include <cstdlib>  
#include "vector"
#include "string"
#include "algorithm"
#include <iostream>
#include "stack"
#include "math.h"  

using namespace std;

//����ģʽP�Ĳ���ƥ��ֵ��������next������    
void MakeNext(const string &P, vector<int> &next)
{
	int q, k;//k��¼����ǰ׺�ĶԳ�ֵ    
	int m = P.size();//ģʽ�ַ����ĳ���    
	next[0] = 0;//���ַ��ĶԳ�ֵ�϶�Ϊ0    
	for (q = 1, k = 0; q < m; ++q)//����ÿһ��λ�õĶԳ�ֵ    
	{
		//k����������¼��һ��ǰ׺�����Գ�ֵ    
		while (k > 0 && P[q] != P[k])
			k = next[k - 1];//k��ѭ���ݼ���ֵ��ע�����next[k]<k���ǳ���    
		if (P[q] == P[k])
			k++;//����k��Ψһ����    
		next[q] = k;//��ȡ����ֵ    
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
			q = next[q - 1];//Ѱ����һ��ƥ��  
			count++;
		}
	}
	return count;
}

int main()
{
	string T;//�ı�  
	string P;//�������ַ��� 
	vector<int> next(200, 0);//����������ַ����Ĳ���ƥ�������ǰ׺�����ĶԳ�ֵ��  
	while (cin >> T >> P)
	{//����Ϊkmp�㷨�ļ�Ӧ��
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
