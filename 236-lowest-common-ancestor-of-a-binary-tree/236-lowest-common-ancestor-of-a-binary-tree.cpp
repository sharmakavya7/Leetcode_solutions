/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int cnt{0};
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        auto left = dfs(root->left, p, q);
        auto right = dfs(root->right, p, q);
        if(left && right) return root;
        if(root == p || root == q){
            cnt++;
            return root;
        }
        return left != nullptr ? left : right;        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto ans = dfs(root, p, q);
        return cnt==2 ? ans : NULL;
    }
};