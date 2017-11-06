// Ͱ���򣬿����ڶ���һ���ֽ�������
#include<cstdio>

static const int BUCKET_MAX_INDEX = 5000;
int a[BUCKET_MAX_INDEX + 1];	// 5000��Ͱ(�±�0δʹ�ã�

int main()
{
	// ����������
	int unsortedA[10]{ 1, 34, 6, 2, 4, 17, 85, 99, 21, 17 };
	
	for each (auto n in unsortedA)
	{
		a[n] ++;	// Ͱ��Ԫ��+1
	}

	// ���������Ԫ��
	for (int i = 1; i <= BUCKET_MAX_INDEX; ++i)
	{
		int tempCount = a[i];
		while (tempCount > 0)
		{
			printf("%d ", i);
			--tempCount;
		}
	}
	
	int targetScore = 17;
	int rank = 0;
	for (int i = BUCKET_MAX_INDEX; i > targetScore; --i)
	{
		rank += a[i];
	}
	printf("\n");
	// ���targetScore����������
	printf("lower rank: %d, upper rank: %d.", rank + 1, rank + a[targetScore]);

	getchar();

    return 0;
}