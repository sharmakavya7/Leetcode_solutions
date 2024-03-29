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
    TreeNode* findMinNode(TreeNode* root) {
        if (root->left) return findMinNode(root->left);
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) 
            return root;    
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        
        else {
            if (!root->left) {
                TreeNode* right = root->right;
                delete root;
                return right;
            }
            else if (!root->right) {
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            else {
                TreeNode* successor = findMinNode(root->right); // find the inorder successor (the minimal node in right subtree)
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }
};