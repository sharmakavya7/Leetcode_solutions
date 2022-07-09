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

 // Definition for a binary tree node.
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
    bool helper(TreeNode* root) {
        if(!root) {
            return root->val;
        }
        bool temp = root->val;
        // cout<<temp<<endl;
        if(root->left&& root->right) {
            if(root->val == 3) {
                root->val = helper(root->left)&&helper(root->right);
            }
            else if(root->val ==2) {
                root->val = helper(root->left)||helper(root->right);
            }
        }
        //     bool r = helper(root->right);
        // if(temp==2) {
        //     return l || r;
        // }
        // else if(temp==3) {
        //     return l && r;
        // }
        return root->val;
    }
    bool evaluateTree(TreeNode* root) {
        return helper(root);
    }
};