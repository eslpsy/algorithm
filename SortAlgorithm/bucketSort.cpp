// 桶排序，可用于对玩家活动积分进行排序
#include<cstdio>

static const int BUCKET_MAX_INDEX = 5000;
int a[BUCKET_MAX_INDEX + 1];	// 5000个桶(下标0未使用）

int main()
{
	// 待排序数组
	int unsortedA[10]{ 1, 34, 6, 2, 4, 17, 85, 99, 21, 17 };
	
	for each (auto n in unsortedA)
	{
		a[n] ++;	// 桶内元素+1
	}

	// 输出排序后得元素
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
	// 输出targetScore的排名区间
	printf("lower rank: %d, upper rank: %d.", rank + 1, rank + a[targetScore]);

	getchar();

    return 0;
}