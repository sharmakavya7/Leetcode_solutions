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
    int leftHeight(TreeNode* root) {
        int hgt = 0;
        while(root) {
            hgt++;
            root = root->left;
        }
        return hgt;
    }
     int rightHeight(TreeNode* root) {
        int hgt = 0;
        while(root) {
            hgt++;
            root = root->right;
        }
        return hgt;
    }
    // logn x logn
    int countNodes(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        
        // formula for total no of nodes in a CBT = 2^height - 1;
        if(lh==rh) {
            return (1<<lh) -1;
        }
        return 1+ countNodes(root->left) + countNodes(root->right);
    }
};