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
    string tree2str(TreeNode* root) {

        if(root==NULL) {
            return " ";
        }
        string  s = to_string(root->val);
        if(root->left) {
            s = s + "(" + tree2str(root->left) + ")";
        }
        else if(!root->left && root->right) {  //left side not present, but right side present (expln down)
            s = s + "()";
        }
        if(root->right) {
            s = s + "(" + tree2str(root->right) + ")";
        }
        return s;
    }
};

// NOTE:
// The difference that can observed is that for left part we create parentheses even when there is no left child, but for right part we create parentheses only when there is right child.