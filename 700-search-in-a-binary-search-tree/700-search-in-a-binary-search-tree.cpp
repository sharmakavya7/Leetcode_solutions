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
    TreeNode*  helper(TreeNode* root, int val) {
        if(!root) {
            return NULL;
        }
        // if(val == root->val) {
        //     return root;
        // }
        if(val < root->val) {
            return helper(root->left, val); 
        }
        else if(val > root->val) {
            return helper(root->right, val);
        }
        else return root;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return helper(root, val);
    }
};