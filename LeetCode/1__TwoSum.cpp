//算法时间复杂度为O(NlogN)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        {
			//使用了algorithm中的std::find方法，二分查找
            vector<int>::iterator find_result = find(it + 1, nums.end(), target - *it);
            if (find_result != nums.end())
            {
                result.push_back(it - nums.begin());
                result.push_back(find_result - nums.begin());
                break;
            }
        }
        
        return result;
    }
};