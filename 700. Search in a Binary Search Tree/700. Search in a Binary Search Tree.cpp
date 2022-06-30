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
    TreeNode* helper(TreeNode* root, int val) {
        if(!root) {
            return NULL;
        }
        if(root->val < val) {
            return helper(root->right, val);
        }
        else if(root->val > val) {
            return helper(root->left, val);
        }
        else return root;
        
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return helper(root, val);
    }
};
