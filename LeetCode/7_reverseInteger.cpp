class Solution {
public:
    int reverse(int x)
	{
		int result = 0;
		int i = 0;
		int temp = x;
		while (abs(temp) > 0)
		{
			temp /= 10;
			i++;
		}
		do
		{
			if (x % 10 != 0)
			{
				//��ת��ʱ���ܷ����������2147483647��ת�����λ��Ϊ7�����
				if (abs(double(result) + double(x % 10)*pow(10, i - 1)) > 2147483647)
				{
					result = 0;
					break;
				}
				result += x % 10 * pow(10,i-1);
			}
			i--;
			x /= 10;
		} while (abs(x) > 0);
		return result;
	}
};