class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());   // 升序排列
        sort(s.begin(), s.end());   // 升序排列
        
        int result = 0;
        for (auto s_it = s.begin(); s_it != s.end(); ++s_it)
        {
            for(auto g_it = g.begin() + result; g_it != g.end(); ++g_it)
            {
                if (*s_it >= *g_it)
                {
                    ++result;
                    break;   // 一个披萨最多只能喂一次
                }
            }
        }
        
        return result;
    }
};