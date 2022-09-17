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
    int helper(TreeNode* root, int& maxi) {
        if(root==NULL) {
            return 0;
        }
        int leftMax = max(helper(root->left, maxi),0);
        int rightMax = max(helper(root->right, maxi),0);

        maxi = max(maxi, leftMax + rightMax+ root->val);
        
        return root->val + max(leftMax, rightMax);
        
    }
    
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        helper(root, mx);
        return mx;
    }
};