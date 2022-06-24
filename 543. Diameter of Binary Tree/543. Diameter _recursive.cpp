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
    int height(TreeNode* root, int&mx) {
        if(root== nullptr) {
            return 0;
        }
        int lh = height(root->left, mx);
        int rh = height(root->right, mx);
        
        mx = max(mx, (lh+rh));
        
         return 1+max(lh,rh);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int mx=0;
        height(root,mx);
        return mx; 
        
    }
};