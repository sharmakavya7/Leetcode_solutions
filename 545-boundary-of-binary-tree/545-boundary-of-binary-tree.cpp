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
    
    void leftBoundary(TreeNode* root, vector<int>&ans) {
        
        if(!root || !root->left && !root->right)
            return;

        ans.push_back(root->val);
        
        if(root->left)
            leftBoundary(root->left, ans);
        else 
            leftBoundary(root->right, ans);
    }
    void rightBoundary(TreeNode* root, vector<int>&ans) {
                
        if(!root || !root->left && !root->right)
            return;
    
        if(root->right)
            rightBoundary(root->right, ans);
        else
            rightBoundary(root->left, ans);
            
        ans.push_back(root->val);
    }
    
    void leafNodes(TreeNode* root, vector<int>&ans) {

        if(!root) return;
        
        if(!root->left and !root->right)
            ans.push_back(root->val);
        
        if(root->left)
            leafNodes(root->left, ans);
        if(root->right)
            leafNodes(root->right, ans);
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int>ans;

        if(!root) return ans;
        ans.push_back(root->val);
        leftBoundary(root->left, ans);
        leafNodes(root->left, ans);
        leafNodes(root->right, ans);
        rightBoundary(root->right, ans);
        return ans;  
    }
};