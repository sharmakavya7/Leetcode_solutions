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
    TreeNode* addrow(TreeNode* root, int v, int d) {
        if(!root)return nullptr;
        if(d == 1){
            TreeNode* ans = new TreeNode(v);
            ans->left = root;
            return ans;
        }
        if(d == 2){
            {
                auto temp = root->left;
                root->left = new TreeNode(v);
                root->left->left = temp;
            }
            {
                auto temp = root->right;
                root->right = new TreeNode(v);
                root->right->right = temp;
            }
            return root;
        }
        addrow(root->left,v,d-1);
        addrow(root->right,v,d-1);
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return addrow(root, val, depth);
    }
};