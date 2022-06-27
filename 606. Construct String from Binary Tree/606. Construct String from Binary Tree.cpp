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
    string tree2str(TreeNode* root) {

        if(root==NULL) {
            return " ";
        }
        string  s = to_string(root->val);
        if(root->left) {
            s = s + "(" + tree2str(root->left) + ")";
        }
        else if(root->right) {
            s = s + "()";
        }
        if(root->right) {
            s = s + "(" + tree2str(root->right) + ")";
        }
        return s;
    }
};