/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int curSum = 0;
    bool helper(TreeNode* root, int target) {
        if(!root) {
            return false;
        }

        if(!root->left && !root->right && root->val==target) {
            return true;
        }
        
        bool lefty = helper(root->left, target - root->val);
        bool righty = helper(root->right, target - root->val);
        
        return lefty || righty;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum);
    }
};