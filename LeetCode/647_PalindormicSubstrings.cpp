class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            result += countSize(s, i);  // 计算i + 1个字母个数的substring的数量
        }

        return result;
    }

private:
    int countSize(string s, int size)
    {
        int result = 0;

        for (int i = 0; i < s.length() - size; ++i)
        {
            bool isPalindormic = true;
            int temp_size = size;   // 后面对临时的size值进行--操作，不能修改到size本身的值
            for (int j = 0; j < temp_size; ++j,--temp_size) // 前后双下标索引，判断对称位置的字母是否相等
            {
                if (s[i + j] != s[i + temp_size])
                {
                    isPalindormic = false;
                    break;
                }
            }
            if (isPalindormic)
            {
                ++result;
            }
        }

        return result;
    }
};