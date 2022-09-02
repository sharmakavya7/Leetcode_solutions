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
    // OPTIMAL TC: O(3N)
    // explanation in notes
    TreeNode* helper(vector<int>& p, int&i, int upperBound) {
        if(i==p.size() || p[i]>upperBound) {
            return NULL;
        }
        TreeNode* root = new TreeNode(p[i++]);
        root->left = helper(p, i, root->val);
        root->right = helper(p, i, upperBound);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return helper(preorder, i, INT_MAX);
    }
    
    
    // BRUTE TC: O(N*N)
    // TreeNode* helper(TreeNode* root, int node) {
    //     if(!root) {
    //         return new TreeNode(node);
    //     }
    //     if(node<root->val) {
    //         root->left = helper(root->left, node);
    //     }
    //     else if(node>root->val) {
    //         root->right = helper(root->right, node);
    //     }
    //     return root;
    // }
    // TreeNode* bstFromPreorder(vector<int>& preorder) {
    //     TreeNode* root=new TreeNode(preorder[0]);
    //     for(int i=1; i<preorder.size(); i++) {
    //         helper(root, preorder[i]);
    //     }
    //     return root;
    // }
}; 