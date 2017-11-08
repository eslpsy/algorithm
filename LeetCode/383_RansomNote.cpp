class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        // ��¼ransomNote�е��ַ�����
        map<char, int> ran;
	    for (auto ch : ransomNote)
        {
            ran[ch] ++;
        }

        // ��¼ransomNote�е��ַ�����
        map<char, int>mag;
        for (auto ch : magazine)
        {
            mag[ch] ++;
        }

        // ���magazine��ĳ���ַ���������ransomNote�е��٣�����false
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