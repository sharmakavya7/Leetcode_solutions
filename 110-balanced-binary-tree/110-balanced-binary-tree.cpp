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
    // O(n) solution
    int helper(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int lh = helper(root->left);
        // jaise hi hmara koi bhi node -1 return krega, we'll simply keep on returning -1 to the root node;
        if(lh == -1) {
            return -1;
        }
        int rh = helper(root->right);
        if(rh == -1) {
            return -1;
        }
        cout<<lh<<" "<<rh<<" ";
        
        if(abs(lh - rh) > 1)
            return -1;
        
        return 1+max(lh,rh);
    }
    
    bool isBalanced(TreeNode* root) {
        return helper(root)!=-1 ? true : false;
    }
};