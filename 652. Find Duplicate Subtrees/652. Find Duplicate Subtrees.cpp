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
    string dup(TreeNode* root, string s, unordered_map<string,int>&m, vector<TreeNode*>&v) {
        if(root==NULL) {
            return "";
        }
        string a = "";
        string b = "";

        a = dup(root->left, s, m, v);

        b = dup(root->right, s, m, v);

        s = to_string(root->val) + "," + a + "," + b;
        
        // m[s]++;
        
        if(++m[s]==2) {
            v.push_back(root);
        }
        return s;
    }
    
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string s;
        unordered_map<string,int>m;
        vector<TreeNode*>v;
        dup(root, s, m, v);
        // reverse(v.begin(),v.end());  // not necessaryy
        return v;
    }
};