// ��ѩҬ���㷨 ��O(N)��ʱ�临�Ӷȣ�������������������������ÿһ�ֿ����Եĳ��ָ��ʶ�����ȵ�
#include <iostream>
#include <vector>

using namespace std;

void FisherYates(vector<int> &nums)
{
	for(int i = nums.size() - 1; i > 0; --i)
	{
		int j = rand() % (i + 1);
		swap(nums[i], nums[j]);		//�������������jλ�õ�ֵ�������λ�ã�Ȼ�����λ�õ�������ǰһλ
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