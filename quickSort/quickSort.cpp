#include<iostream>

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void quickSort(int * array, int left, int right)
{
	int i = left;
	int j = right;

	while (i <= j)
	{
		// 选取数组第一个元素作为参照
		while (array[left] > array[i]) ++i;
		while (array[left] < array[j]) --j;
		
		if (i <= j)
		{
			swap(array[i], array[j]);
			++i;
			--j;
		}
	}

	// recurtion
	if (left < j) quickSort(array, left, j);
	if (right > i) quickSort(array, i, right);
}

int main()
{
	int a[10] = { 0 };

	for each (auto &n in a)
	{
		n = rand() % 10;
	}

	std::cout << "array before sort:";
	for each (auto n in a)
	{
		std::cout << n << " ";
	}
	std::cout << std::endl;

	quickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);

	std::cout << "array after sort:";
	for each (auto n in a)
	{
		std::cout << n << " ";
	}
	std::cout << std::endl;

	getchar();

    return 0;
}
