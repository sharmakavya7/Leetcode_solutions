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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        // vector<int>res;
        queue<TreeNode*>q;
        q.push(root);
        int flag = 0;
        bool leftToRight = true; 
        
        if (root == NULL) {
            return ans;
        }
        
        while(!q.empty()) {
            int sz = q.size();
            vector<int>res(sz);
            
            for(int i=0; i<sz; i++) {
                TreeNode* front = q.front();
                q.pop();
                
                int ind = (leftToRight) ? i : (sz - 1 - i);
                
                res[ind] = front->val;
                //flag++;
                
                if(front->left) {
                    q.push(front->left);
                }
                if(front->right) {
                    q.push(front->right);
                }
            }
            leftToRight = !leftToRight;
            ans.push_back(res);
            //flag++;
            
        }
        return ans;
    }
};