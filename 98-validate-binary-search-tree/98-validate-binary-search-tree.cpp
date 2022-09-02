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
    // When we recurse on the left subtree, the upper bound becomes the value of its root.
    // When we recurse on the right subtree, the lower bound becomes the value of its root.
    bool helper(TreeNode* root, long mini, long maxi) {
        if(!root) {
            return true;
        }
        if (root -> val <= mini || root -> val >= maxi) {
            return false;
        }
        bool lefty = helper(root->left, mini, root->val);
        
        bool righty = helper(root->right, root->val, maxi);
        
        return lefty && righty;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};