class Solution {
public:
    int climbStairs(int n) {
        int pre = 2;
        int pre_pre = 1;
        int result = 0;
        if (n <= 2)
        {
            result = n;
        }
        else while (n > 2)
        {
            result = pre + pre_pre;
            pre_pre = pre;
            pre = result;
            -- n;
        }
        return result;
    }
};