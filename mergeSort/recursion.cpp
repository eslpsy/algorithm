#include <iostream>

using namespace std;

const int N = 100;

int g_array[N];     //������������

//�ϲ�����
void Merge(int a[], int l, int m, int r)
{
	int i = l, j = m + 1, k = l;
	int b[N];
	while (i <= m && j <= r)
	{
		if (a[i] <= a[j])
		{
			b[k++] = a[i++];
		}
		else
		{
			b[k++] = a[j++];
		}
	}

	if (i > m)
	{
		for (int p = j; p <= r; p++)
		{
			b[k++] = a[p];
		}
	}
	else
	{
		for (int p = i; p <= m; p++)
		{
			b[k++] = a[p];
		}
	}

	//��b[]���źõ�Ԫ��copy��a[]��
	for (int q = l; q <= r; q++)
	{
		a[q] = b[q];
	}
}

//  �鲢���� �ݹ��㷨��ʾ
void MergeSort(int a[], int left, int right)
{
	if (left < right)    //��������Ҫ������Ԫ��
	{
		int i = (right + left) / 2;
		MergeSort(a, left, i);
		MergeSort(a, i + 1, right);
		Merge(a, left, i, right); //��left��right��Ԫ�������
	}
}

//��ӡ�ź��������
void Print()
{
	cout << "����MergeSort��";
	for (int i = 0; i < N; i++)
	{
		cout << g_array[i] << " ";
	}
	cout << endl;
}

int main()
{
	for (int i = 0; i < N; ++i)
	{
		g_array[i] = rand() % 100;
	}
	if (N > 1)
	{
		MergeSort(g_array, 0, N - 1);
		Print();
	}
	else if (N == 1)
	{
		Print();
	}
	system("pause");
	return 0;
}
