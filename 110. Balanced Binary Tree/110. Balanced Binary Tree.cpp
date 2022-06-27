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
    int helper(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        int hL = helper(root->left);
        int hR = helper(root->right);
        
        return 1+ max(hL,hR);
    }
    
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) {
            return true;
        }
        
        return isBalanced(root->left) 
            && isBalanced(root->right) 
            && abs(helper(root->left) - helper(root->right)) <= 1;
        
    }
};