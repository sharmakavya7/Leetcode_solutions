#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib> 
#include <string>
#include <map>
#include <climits>
#include <iterator>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

//  * Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 }; 

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // if(key==0) return root;
        if(!root) {
            return NULL;
        }
        if(root) {
            if(root->val < key) {
                root->right = deleteNode(root->right, key);
            }
            else if(root->val > key) {
                root->left = deleteNode(root->left, key);
            }
            else {  // key found
                if(!root->left && !root->right) 
                    return NULL;          //No child 

                if (!root->left || !root->right) { //One child -> replace node with child
                    return root->left ? root->left : root->right;   
                }
        // Two child condition
                TreeNode* temp = root->left;
                while(temp->right != NULL) temp = temp->right;     
                root->val = temp->val;                      
                root->left = deleteNode(root->left, temp->val);
            }
        }
        return root;
        
    }
};