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
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return NULL;
        }
        if(p==root || q==root) {
            return root;
        }
        auto lefty = helper(root->left, p, q);
        auto righty = helper(root->right, p, q);
        if(lefty==NULL) {       // ek NULL hai to dusra return karo cz vo not null ho skta hai
            return righty;
        }
        if(righty==NULL){
            return lefty;
        }
        else return root;   // if both are not null, return root cz that's the LCA
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q);
    }
};