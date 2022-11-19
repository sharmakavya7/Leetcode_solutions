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
    int leftheight(TreeNode* root) {
        TreeNode* cur = root;
        int lefth = 0;
        while(cur) {
            cur = cur -> left;
            lefth++;
        }
        return lefth;
    }
    int rightheight(TreeNode* root) {
        TreeNode* cur = root;
        int righth = 0;
        while(cur) {
            cur = cur -> right;
            righth++;
        }
        return righth;
    }
    int countNodes(TreeNode* root) {
        int lh = leftheight(root);
        int rh = rightheight(root);
        if(lh == rh) {
            return pow(2, lh) - 1;
        } else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};