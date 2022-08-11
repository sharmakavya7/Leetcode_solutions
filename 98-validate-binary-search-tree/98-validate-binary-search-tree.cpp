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
    vector<int>ans;
    void inOrder(TreeNode* root) {
        if (!root)
            return;
        inOrder(root->left);
        ans.push_back(root->val);
        inOrder(root->right);
    }

//  bool validBST(TreeNode* root, long min, long max) {
//         if(root==nullptr) 
//             return true;
//         if(root->val<=min || root->val>=max) {
//             return false;
//         }
//         return validBST(root->left, min, root->val) && validBST(root->right, root->val, max);
        
        //return true;
//    }
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        for(int i=1; i<ans.size(); i++)
            if(ans[i] <= ans[i-1])
                return false;
        return true;
    }
};