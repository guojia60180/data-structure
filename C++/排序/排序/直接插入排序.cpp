void insert_sort(int a[], int n)
{
	int i, j, k;

	for (i = 1; i < n; i++)
	{
		//Ϊa[i]��ǰ���a[0...i-1]������������һ�����ʵ�λ��
		for (j = i - 1; j >= 0; j--)
			if (a[j] < a[i])
				break;

		//���ҵ���һ�����ʵ�λ��
		if (j != i - 1)
		{
			//����a[i]������������
			int temp = a[i];
			for (k = i - 1; k > j; k--)
				a[k + 1] = a[k];
			//��a[i]�ŵ���ȷλ����
			a[k + 1] = temp;
		}
	}
}
