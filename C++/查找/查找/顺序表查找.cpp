//顺序查找，a为数组，n为要查找的数组长度，key为要查找的关键字
//正常的简单寻找
int Sequential_Search(int *a, int n, int key)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (a[i] == key)
			return key;
	}
	return 0;
}


//优化顺序表查找

int Sequential_Search2(int *a, int n, int key)
{
	int i;
	a[0] = key;
	i = n;
	while (a[i] = key)
	{
		i--;
	}
	return i;
}
