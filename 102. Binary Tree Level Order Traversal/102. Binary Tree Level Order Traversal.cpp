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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root==NULL) {
            return ans;
        }
        q.push(root);
        
        while(!q.empty()) {
            vector<int>level;
            int n = q.size();
            for(int i=0; i<n; i++) {
                TreeNode* front = q.front();
                q.pop();
                if(front->left!=NULL) {
                    q.push(front->left);
                }
                if(front->right!=NULL) {
                    q.push(front->right);
                }
                level.push_back(front->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};