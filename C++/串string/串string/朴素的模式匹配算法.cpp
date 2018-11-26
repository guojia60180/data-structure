#include <string.h>
#include "vector"
#include <string>
#include <iostream>
#include "algorithm"

using namespace std;
//��򵥵�ģʽƥ��
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

//�����ظ��ı��������

//���㷵���Ӵ�T��next����



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
			cout << "ģʽ�ı���ƫ��Ϊ��" << (i - m + 1) << endl;
			q = next[q - 1];//Ѱ����һ��ƥ��
		}
	}
}

int main()
{
	system("color 0A");
	vector<int> next(20, 0);//����������ַ����Ĳ���ƥ�������ǰ׺�����ĶԳ�ֵ��
	string T = "xyxababcaxxxababca";//�ı�
	string P = "ababca";//�������ַ���
	cout << "�ı��ַ�����" << T << endl;
	cout << "ģʽ�ַ�����" << P << endl;
	KmpMatch(T, P, next);
	cout << "ģʽ�ַ�����ǰ׺������" << endl;
	for (int i = 0; i < P.size(); i++)
		cout << next[i];
	cout << endl;
	system("pause");
	return 0;
}
