class Solution {
public:
    int myAtoi(string str) {
        double result = 0;
		int flag = 0;		// 是否开始计数的标志
		std::vector<int> temp_num;
		for (int i = 0; i < (int)str.length(); ++i)
		{
			// 开始计数，只允许数字
			if (flag != 0 && !('0' <= str[i] && str[i] <= '9'))
			{
				break;
			}

			// 未开始计数，允许空格，tab和+ - 号
			if (0 == flag)
			{
				if (isspace(str[i]))
				{
					continue;
				}
				else if ('-' == str[i])
				{
					flag = -1;
				}
				else if ('+' == str[i])
				{
					flag = 1;
				}
				else if (!('0' <= str[i] && str[i] <= '9'))
				{
					break;
				}
			}

			// 将数字存入数组中
			if ('0' <= str[i] && str[i] <= '9')
			{
				if (0 == flag)
				{
					flag = 1;
				}
				int num = (int)str[i] - (int)'0';
				temp_num.push_back(num);
			}
		}

		// 计算的结果
		for (int i = 0; i < (int)temp_num.size(); ++i)
		{
			result += temp_num[i] * pow(10, temp_num.size() - i - 1);
		}
		
		// 判断符号和处理溢出
		double ans = flag * result;
		if (ans > INT_MAX)
		{
			ans = INT_MAX;
		}
		if (ans < INT_MIN)
		{
			ans = INT_MIN;
		}

		return (int)ans;
	}
};