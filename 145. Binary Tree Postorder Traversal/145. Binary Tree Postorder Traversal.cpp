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
    void helper(TreeNode* root, vector<int>&v) {
        if(root==NULL) {
            return;
        }
        helper(root->left,v);
        helper(root->right, v);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        helper(root, v);
        return v;
    }
};