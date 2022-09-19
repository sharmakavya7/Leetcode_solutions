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
    void helper(TreeNode* root, int &curVal, int& finalans) {
        if(!root) {
            return;
        }
        curVal = curVal * 10;
        curVal += root -> val;
        
        if(!root->left && !root->right) {
            finalans+=curVal;
        }
        
        if(root->left) {
            helper(root->left, curVal, finalans);
            curVal/=10;
        }
        if(root->right) {
            helper(root->right, curVal, finalans);
            curVal/=10;
        }
    }
    int sumNumbers(TreeNode* root) {
        int curVal=0, finalans = 0;
        helper(root, curVal, finalans);
        return finalans;
    }
};

/*

Suppose Binary Tree is:
		1
	  /   \
	 2     3
		  /
		 4
Let func. name be DFS
DFS(1) = DFS(2, 1) + DFS(3, 1)
DFS(2, 1) = 10 + 2 = 12     // Base case
DFS(3, 1) = DFS(4, 10 + 3) + 0 = DFS(4, 13)
DFS(4, 13) = 130 + 4 = 134    // Base Case
=> DFS(1) = 12 + 134 = 146

*/