class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        // ��¼magazine�е��ַ�����
        map<char, int>mag;
        for (auto &ch : magazine)
        {
            mag[ch] ++;
        }

        // ���magazine��ĳ���ַ��������ransomNote���ַ�������false
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