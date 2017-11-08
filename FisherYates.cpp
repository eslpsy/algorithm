// 费雪椰兹算法 以O(N)的时间复杂度，对数组进行乱序，且数组乱序的每一种可能性的出现概率都是相等的
#include <iostream>
#include <vector>

using namespace std;

void FisherYates(vector<int> &nums)
{
	for(int i = nums.size() - 1; i > 0; --i)
	{
		int j = rand() % (i + 1);
		swap(nums[i], nums[j]);		//将随机到的索引j位置的值换到最后位置，然后最后位置的索引往前一位
	}
}

int main()
{
	vector<int> original{ 1,2,3,4,5,6,7,8 };
	
	int loopTimes = 10;
	while(loopTimes--)
	{
		FisherYates(original);

		for (auto n : original)
		{
			cout << n << " ";
		}
		cout << endl;
	}
	
	getchar();

    return 0;
}