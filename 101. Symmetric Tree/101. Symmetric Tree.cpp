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
    bool helper(TreeNode* p, TreeNode* q) {
        if(p ==NULL && q==NULL) {
            return true;
        }
        else if(p==NULL || q==NULL) {
            return false;
        }
        if(p->val != q->val) {
            return false;
        }
        return helper(p->left, q->right) && helper(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) {
            return true;
        }
        return helper(root->left, root->right);
    }
};