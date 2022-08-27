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
public:
    // vector<TreeNode*>ans;
    TreeNode* helper(TreeNode* root, TreeNode*p) {
        if(!root || p==nullptr) {
            return nullptr;
        }
        // if(root->left == p) {
        //     return root;
        // }
        // if(root == p) {
        //     return root->right;
        // }
        if(root->val <= p->val)
            return helper(root->right,p);
        TreeNode* left = helper(root->left,p);
        
        return left!=nullptr?left:root;
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        return helper(root, p);
    }
};