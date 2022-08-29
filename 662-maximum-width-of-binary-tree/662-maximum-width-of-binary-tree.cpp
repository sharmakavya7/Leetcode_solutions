/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // i -> i-1
    //         i 
    //     /      \
    // 2(i-1)+1  2(i-1)+2
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root) {
            return 0;
        }
        int width = 0;
        queue<pair<TreeNode*,long long>>q;   // (node, index)
        q.push({root,0});
        
        while(!q.empty()) {
            
            // i-1 kr rhe the na, sabseMin uska '1' hai
            // in most of the cases sabseMin will be one but in some cases it could be 2
            
            int sabseMin = q.front().second;
            int sz = q.size();
            int first=0, last=0;              // width = last_index - first_index + 1
            
            for(int i=0; i<sz; i++) {
                
                // cur mtlb i is changing to i-1 (or i-2 in a few cases)
                
                auto cur = q.front().second - sabseMin;
                TreeNode* front = q.front().first;
                q.pop();
                if(i==0) {
                    first = cur;
                }
                if(i == sz-1) {
                    last = cur;
                }
                // cout<<cur<<" ";
                // cout<<last<<" "<<first<<" ";
                if(front->left) {
                    q.push({front->left, cur*2+1});
                }
                if(front->right) {
                    q.push({front->right, cur*2+2});
                }
            }
            width = max(width, last-first + 1);
        }
        return width;
    }
};