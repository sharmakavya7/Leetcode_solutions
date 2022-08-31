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
    // 1. search key
    // 2. save key node in dummy
    // 3. find that node in it's subtree which is greater than the key
    // 4. attach that subtree into current root->left
    // 5. return root and dummy
    
    TreeNode* greaterValNode(TreeNode* root, int target) {
        if(root->right==NULL || root->left!=NULL) {
            return NULL;
        }
        if(root->right==NULL && root->left==NULL) {
            return NULL;
        }
        TreeNode* rightChild = root->right;
        if(rightChild->val > target) {
            return rightChild;
        }
        return greaterValNode(root->right, target);
    }
    
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        // if(!root) {
        //     return {};
        // }
        // TreeNode* main = root;
        // TreeNode* targetNode = root;
        // while(root) {
        //     if(root->val > target) {
        //         if(root->left!=NULL && root->left->val==target) {
        //             targetNode = root->left;
        //             root->left = greaterValNode(root->left, target);
        //             break;
        //         }
        //         else {
        //             root = root->left;
        //         }
        //     }
        //     else {
        //         if(root->right!=NULL && root->right->val==target) {
        //             targetNode = root->right;
        //             root->right = greaterValNode(root->right, target);
        //             break;
        //         }
        //         else {
        //             root = root->right;
        //         }
        //     }
        // }
        // vector<TreeNode*>ans;
        // ans.push_back(targetNode);
        // ans.push_back(root);
        // return ans;
        if (!root) {
            return vector<TreeNode*>(2,NULL);
        } 
        if (target >= root->val) {
            auto split = splitBST(root->right, target) ;
            root->right = split[0];
            split[0]=root;
            return split;
        } else {
            auto split = splitBST(root->left, target) ;
            root->left = split[1];
            split[1]=root;
            return split;
        }
    }
};