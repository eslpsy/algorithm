class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        // 记录ransomNote中的字符个数
        map<char, int> ran;
	    for (auto ch : ransomNote)
        {
            ran[ch] ++;
        }

        // 记录ransomNote中的字符个数
        map<char, int>mag;
        for (auto ch : magazine)
        {
            mag[ch] ++;
        }

        // 如果magazine中某个字符的数量比ransomNote中的少，返回false
        for (char i = 'a'; i <= 'z'; ++i)
        {
            if (ran[i] > mag[i])
            {
                return false;
            }
        }

        return true;
    }
};