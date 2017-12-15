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
    vector<int> nums;	// 存储每一个二叉树的每一个节点
public:
    int getMinimumDifference(TreeNode* root) {

		traverseTree(root);
        
        sort(nums.begin(), nums.end());		// 二叉树升序排列
        
		int result = INT_MAX;
        for (auto it = nums.begin(); it != nums.end() - 1; ++it)	// 找到两个节点间最小的差值
        {
            if (abs(*it - *(it + 1)) < result)
            {
                result = abs(*it - *(it + 1));
            }
        }
        
        return result;
    }
    
private:
    void traverseTree(TreeNode *node)	// 先序遍历二叉树
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