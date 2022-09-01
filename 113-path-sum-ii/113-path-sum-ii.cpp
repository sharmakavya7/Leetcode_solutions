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
    vector<int>paths;
    vector<vector<int>>ans;
    
    void helper(TreeNode* root, int target) {
        if(!root) {
            return;
        }
        paths.push_back(root->val);
        if(!root->left && !root->right &&target==root->val) {
            ans.push_back(paths);
            // return;   
        }
        helper(root->left, target - root->val);
        
        helper(root->right, target - root->val);
        paths.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        helper(root, targetSum);
        return ans;
    }
};