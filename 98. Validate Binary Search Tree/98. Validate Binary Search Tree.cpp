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
    bool validBST(TreeNode* root, long min, long max) {
        if(root==nullptr) 
            return true;
        if(root->val<=min || root->val>=max) {
            return false;
        }
        return validBST(root->left, min, root->val) && validBST(root->right, root->val, max);
        
        //return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        return validBST(root, LONG_MIN, LONG_MAX);
    }
};