#include <iostream>
#include <vector>

using namespace std;

vector<int> insertSort(vector<int> unsortArray) {
	for(int i = 1; i<unsortArray.size(); i++) {
		int temp = unsortArray[i];
		for(int j = i-1; j >= 0; j--) {
			if(temp < unsortArray[j] && 0 == j) {
				unsortArray[j+1] = unsortArray[j];
				unsortArray[j] = temp;
			} 
			else if(temp < unsortArray[j]) {
				unsortArray[j+1] = unsortArray[j];
			} 
			else if(temp >= unsortArray[j]) {
				unsortArray[j+1] = temp;
				break;
			}
		}
	}
	return unsortArray;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> unsortArray;
	for(int i = 0; i<10; i++) {
		unsortArray.push_back(rand()%10);
	}
	for(vector<int>::iterator it = unsortArray.begin(); it != unsortArray.end(); it++) {
		cout << *it << "  " ;
	}
	cout << endl;
	unsortArray = insertSort(unsortArray);
	for(vector<int>::iterator it = unsortArray.begin(); it != unsortArray.end(); it++) {
		cout << *it  << "  ";
	}
	cout << endl;

	system("pause");

	return 0;
}