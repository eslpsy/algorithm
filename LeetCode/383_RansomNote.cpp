class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        // 记录magazine中的字符个数
        map<char, int>mag;
        for (auto &ch : magazine)
        {
            mag[ch] ++;
        }

        // 如果magazine中某个字符不够组合ransomNote的字符，返回false
        for (int i = 0; i < ransomNote.length(); ++i)
        {
            if (--mag[ransomNote[i]] < 0)
            {
                return false;
            }
        }

        return true;
    }
};