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
    TreeNode* helper(TreeNode* root, int node) {
        if(!root) {
            return new TreeNode(node);
        }
        if(node<root->val) {
            root->left = helper(root->left, node);
        }
        else if(node>root->val) {
            root->right = helper(root->right, node);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode(preorder[0]);
        for(int i=1; i<preorder.size(); i++) {
            helper(root, preorder[i]);
        }
        return root;
    }
};