class Solution {
public:
    int strStr(string haystack, string needle) {
        if(0 == needle.length())
        {
            return 0;
        }
        for (int i = 0; i <= (int)haystack.length() - (int)needle.length(); ++i)
        {
            for (int j = 0; j <= needle.length(); ++j)
            {
                if (needle[j] != haystack[i + j])
                {
                   break; 
                }
                if (j == (needle.length() - 1))
                {
                    return i;
                }
            }
        }
        return -1;
    }
};