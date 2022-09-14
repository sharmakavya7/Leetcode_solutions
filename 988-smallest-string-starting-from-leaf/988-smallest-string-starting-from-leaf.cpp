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
    string ans = "";   // {013} -> {310}
    string str = "";   // {014} -> {410}
    
    void helper(TreeNode* root) {
        if(!root) return;
        
        str += (char)(root->val+'a');
        
        if(root->left ==root->right) {
            string s = str;
			reverse(s.begin(),s.end());
            if(ans=="" || s<ans) ans = s;
            
        }
        if(root->left) helper(root->left);
        if(root->right) helper(root->right);
        str.pop_back();
    }
        
    string smallestFromLeaf(TreeNode* root) {
        helper(root);
        return ans;
    }
};