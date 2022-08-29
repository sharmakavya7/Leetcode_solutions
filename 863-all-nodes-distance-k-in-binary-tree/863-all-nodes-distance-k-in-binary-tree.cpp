/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &backEdge, TreeNode* target){
        if(!root || (root == target)) return;
    
        if(root->left){
            backEdge[root->left] = root;
            dfs(root->left, backEdge, target);
        }
        if(root->right){
            backEdge[root->right] = root;
            dfs(root->right, backEdge, target);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> backEdge;
        unordered_set<TreeNode*> visited;
        vector<int> res;
        dfs(root, backEdge, target);
        queue<TreeNode*> q;
        q.push(target);
        while(!q.empty() && k >= 0){
            int s = q.size();
            while(s--){
                TreeNode* front = q.front();
                int val = front->val; q.pop();
                visited.insert(front);
                
                if(k == 0) 
                    res.push_back(val); 
                
                if(!visited.count(backEdge[front]) && backEdge[front]) 
                    q.push(backEdge[front]);
                
                if(!visited.count(front->left) && front->left) 
                    q.push(front->left);
                
                if(!visited.count(front->right) && front->right) 
                    q.push(front->right);
            } 
            k--;  
        }
        return res;
    }
};