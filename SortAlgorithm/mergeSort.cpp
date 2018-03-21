#include <iostream>

using namespace std;

void merge(int *data, int start, int end, int middle, int *result)
{
	int left_index = start;
	int right_index = middle;
	int result_index = start;
	while (left_index < middle && right_index < end + 1)
	{
		if (data[left_index] <= data[right_index])
			result[result_index++] = data[left_index++];
		else
			result[result_index++] = data[right_index++];
	}
	while (left_index < middle)
		result[result_index++] = data[left_index++];
	while (right_index < end + 1)
		result[result_index++] = data[right_index++];
}

void merge_sort(int *data, int start, int end, int *result)
{
	if (1 == end - start)//如果区间中只有两个元素，则对这两个元素进行排序
	{
		if (data[start] > data[end])
		{
			int temp = data[start];
			data[start] = data[end];
			data[end] = temp;
		}
		return;
	}
	else if (0 == end - start)//如果只有一个元素，则不用排序
		return;
	else
	{
		//继续划分子区间，分别对左右子区间进行排序
		int middle = (end - start + 1) / 2 + start;
		merge_sort(data, start, middle - 1, result);
		merge_sort(data, middle, end, result);
		//开始归并已经排好序的start到end之间的数据
		merge(data, start, end, middle, result);
	}
}

int main()
{
	const static int ARR_SIZE = 6;
	int arr[ARR_SIZE]{ 1, 3, 4, 2, 6, 5 };

	for (int &i : arr)
	{
		cout << i << " ";
	}
	cout << endl;

	int* result = new int[ARR_SIZE];

	merge_sort(arr, 0, ARR_SIZE - 1, result);

	for (int i = 0; i < ARR_SIZE; ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl;

	delete[] result;

	return 0;
}
