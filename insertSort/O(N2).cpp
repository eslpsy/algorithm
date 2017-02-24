#include <iostream>
#include <vector>

using namespace std;

void insertSort(vector<int>& unsortArray) 
{
	for(int i = 1; i<unsortArray.size(); i++) 
	{
		int temp = unsortArray[i];
		int j = i-1;
		while (j>=0 && temp < unsortArray[j]) 
		{
			unsortArray[j+1] = unsortArray[j];
			j--;
		}
		unsortArray[j+1] = temp;
	}
}

int main()
{
	vector<int> unsortArray;
	for(int i = 0; i<10; i++) 
	{
		unsortArray.push_back(rand()%10);
	}
	cout << "unsorted array: ";
	for(vector<int>::iterator it = unsortArray.begin(); it != unsortArray.end(); it++) 
	{
		cout << *it << "  " ;
	}
	cout << endl;
	insertSort(unsortArray);
	cout << "sorted array";
	for(vector<int>::iterator it = unsortArray.begin(); it != unsortArray.end(); it++) 
	{
		cout << *it  << "  ";
	}
	cout << endl;

	system("pause");

	return 0;
}