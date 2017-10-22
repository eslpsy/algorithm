class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty())
        {
            return;
        }
        set<int> ai;
        set<int> aj;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    ai.insert(i);
                    aj.insert(j);
                }
            }
        }
        
        for (std::set<int>::iterator it = ai.begin(); it != ai.end(); ++it)
        {
            for(int j = 0; j < n; ++j)
            {
                matrix[*it][j] =0;
            }
        }
        
        for (std::set<int>::iterator it = aj.begin(); it != aj.end(); ++it)
        {
            for (int i = 0; i < m; ++i)
            {
                matrix[i][*it] = 0;
            }
        }
    }
};