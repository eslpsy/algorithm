//�㷨ʱ�临�Ӷ�ΪO(NlogN)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        {
			//ʹ����algorithm�е�std::find���������ֲ���
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