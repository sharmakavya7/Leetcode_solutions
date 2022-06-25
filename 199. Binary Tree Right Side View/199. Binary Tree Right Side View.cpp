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
private: 
    void rightView(TreeNode* root, vector<int>&ans, int level) {
        
        if(root==nullptr) {
            return;
        }
        if(level == ans.size()) {
            ans.push_back(root->val);
        }
        rightView(root->right, ans, level+1);
        rightView(root->left, ans, level+1);
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        rightView(root, ans, 0);
        return ans;
    }
};