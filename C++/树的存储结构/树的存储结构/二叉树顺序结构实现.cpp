//������˳��ṹ
#include <iostream>
using namespace std;
#define MAX 20
/***  ���ɶ�����
˼·�����н�㶼��Ҫ�͸����Ƚϴ�С��С�ڸ����Ľ���������������֮��
���ڸ����Ľ�������������
----- ���㷨��Ҫ�����������飬����b_tree���ڴ洢���յĶ�����������node����
��������ֵ��Ϊ��ʹ������±�ͽ��ı�����Ӧ��b_tree[0]���洢���ݣ�
��b_tree[1]��ʼ�洢��
***/
void Create_bTree(int *b_tree, int *node, int len)
{
	int i;
	int level;
	b_tree[1] = node[1];
	for (i = 2; i<len; i++)
	{
		level = 1;
		while (b_tree[level] != 0) //���Ϊ�գ��˳�ѭ�������д洢
		{
			if (node[i]<b_tree[level])
				level = 2 * level;
			else
				level = 2 * level + 1;
		}
		b_tree[level] = node[i];
	}
}
int main()
{
	int b_tree[MAX] = { 0 }; //��ʼΪ��
	int node[11] = { 0,8,6,7,4,2,3,15,1,14,16 };//8�Ǹ����
	Create_bTree(b_tree, node, 11);
	for (int i = 1; i<MAX; i++)
	{
		cout << b_tree[i] << "\t";
		if (i % 5 == 0)
			cout << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
