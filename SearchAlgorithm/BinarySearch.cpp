#include<iostream>
#include<time.h>

using namespace std;

// BinarySearch 用于从小到大排序的有序数列
int BinarySearch(int array[], int left, int right, int target)
{
	if (NULL == array) return -2;

	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (array[mid] > target)
		{
			right = mid - 1;
		}
		else if (array[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}

	return -1;
}

// qsort排序函数，返回负数，会交换a，b的位置
int cmp(const void * a, const void *b)
{
	return *((int*)a) - *((int*)b);
}

int main()
{
	int array[10] = { 0 };

	time_t now_time;
	srand(time(&now_time));

	for (int i = 0; i < 10; ++i)
	{
		array[i] = rand() % 10;
	}
	
	// 快速排序
	std::qsort(array, 10, sizeof(array[0]), cmp);

	cout << "sorted array: ";
	for each (auto n in array)
	{
		cout << n;
	}
	cout << endl;

	int random_search_num = array[rand() % 10];
	cout << "serach num is: " << random_search_num << endl;

	int result2 = BinarySearch(array, 0, 10, random_search_num);
	cout << "BinarySearch result = " << result2 << endl;

	getchar();
	return 0;
}