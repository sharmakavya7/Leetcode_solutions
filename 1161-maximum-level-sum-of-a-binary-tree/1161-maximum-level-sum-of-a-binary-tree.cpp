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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        int maxi = INT_MIN;
        
        if (root == NULL) {
            return maxi;
        }
        int level = 0;
        int ans = 0;
        while(!q.empty()) {
            
            int levelsum=0;
            int sz = q.size();
            level++;
            for(int i=0; i<sz; i++) {
                
                TreeNode* front = q.front();
                q.pop();
                
                // cout<<front->val<<" ";
                
                levelsum += front->val;
                
                // cout<<" sum:"<<levelsum<<" ";
                
                if(front->left) {
                    q.push(front->left);
                }
                if(front->right) {
                    q.push(front->right);
                }
            }
            if (levelsum > maxi) 
                ans = level;
            maxi = max(maxi, levelsum);
            // cout<<maxi<<" ";
            // cout<<endl;
        }
        return ans;
    }
};