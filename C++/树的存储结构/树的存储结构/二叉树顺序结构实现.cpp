//二叉树顺序结构
#include <iostream>
using namespace std;
#define MAX 20
/***  生成二叉树
思路：所有结点都需要和根结点比较大小，小于根结点的结点放在左子树，反之，
大于根结点的结点放在右子树。
----- 本算法需要定义两个数组，数组b_tree用于存储最终的二叉树，数组node用于
保存结点数值，为了使数组的下标和结点的编号相对应，b_tree[0]不存储数据，
从b_tree[1]开始存储。
***/
void Create_bTree(int *b_tree, int *node, int len)
{
	int i;
	int level;
	b_tree[1] = node[1];
	for (i = 2; i<len; i++)
	{
		level = 1;
		while (b_tree[level] != 0) //结点为空，退出循环，进行存储
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
	int b_tree[MAX] = { 0 }; //初始为空
	int node[11] = { 0,8,6,7,4,2,3,15,1,14,16 };//8是根结点
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
