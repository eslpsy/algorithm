/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> nums;	// �洢ÿһ����������ÿһ���ڵ�
public:
    int getMinimumDifference(TreeNode* root) {

		traverseTree(root);
        
        sort(nums.begin(), nums.end());		// ��������������
        
		int result = INT_MAX;
        for (auto it = nums.begin(); it != nums.end() - 1; ++it)	// �ҵ������ڵ����С�Ĳ�ֵ
        {
            if (abs(*it - *(it + 1)) < result)
            {
                result = abs(*it - *(it + 1));
            }
        }
        
        return result;
    }
    
private:
    void traverseTree(TreeNode *node)	// �������������
    {
        if (node != NULL)
        {
            getNodeMinAbsDiff(*node);

            traverseTree(node->left);
            traverseTree(node->right);
        }
    }
    
    void getNodeMinAbsDiff(TreeNode& node)
    {
        nums.push_back(node.val);
    }
};