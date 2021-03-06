#include <iostream>

using namespace std;

inline int left(int);
inline int right(int);
void maxHeapSort(int*, int, int);
void swap(int*, int, int);

int main()
{
	int a[9] = { 9, 2, 3, 5, 6, 1, 4, 8, 7 };
	int heap_size = sizeof(a) / sizeof(a[0]);
	while (heap_size >= 2)
	{
		for (int i = heap_size/2 - 1; i >= 0; --i)
		{
			maxHeapSort(a, i, heap_size);
		}
		swap(a, 0, heap_size-1);
		heap_size--;
	}
	for (int n : a)
	{
		cout << n << " ";
	}
	cout << endl;

	getchar();

    return 0;
}

inline int left(int i)
{
	return (i << 1) + 1;
}

inline int right(int i)
{
	return (i << 1) + 2;
}
void swap(int* a, int i, int j)
{
	int temp = a[i];
   	a[i] = a[j];
	a[j] = temp;
}
void maxHeapSort(int* a, int i, int heap_size)
{
	int r = right(i);
	int l = left(i);
	int largest = i;
	if (a[l] > a[i])
	{
		largest = l;
	}
	if (r <= heap_size - 1 && a[r] > a[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		swap(a, largest, i);
	}
}
