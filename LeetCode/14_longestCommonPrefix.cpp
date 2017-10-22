class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
		
        for(int idx=0; strs.size()>0; prefix+=strs[0][idx], idx++)	// 这是一个死循环，如果担心出问题可以加上循环次数限制
		{
			// 遍历所有的字符串做比较，如果不相等或者有字符已经比较完，返回结果
            for(int i=0; i<strs.size(); i++)
			{
                if(idx >= strs[i].size() ||(i > 0 && strs[i][idx] != strs[i-1][idx]))
				{
					 return prefix;
				}
			}
		}
		
        return prefix;
    }
};