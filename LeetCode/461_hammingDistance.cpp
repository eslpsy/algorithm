#include <string>
#include <iostream>
using namespace std;

int hammingDis(int x, int y)
{
	int result = 0;
	
	while (x != 0 || y != 0)
	{
		// 用除2取余法计算二进制进行比较
		if (x != 0 && y != 0)
		{
			if(x % 2 != y % 2)	result++;
		}
		else if (x != 0 && x % 2 != 0)
		{
			result++;
		}
		else if (y != 0 && y % 2 != 0)
		{
			result++;
		}

		x /= 2;
		y /= 2;
	}
	
	return result;
}

int main()
{
	cout << hammingDis(3, 1) << endl;

	getchar();

    return 0;
}
