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
    
    int findMaxDistance(map<TreeNode*, TreeNode*> &mpp, TreeNode* target) {
    queue<TreeNode*> q; 
    q.push(target); 
    map<TreeNode*,int> vis; 
    vis[target] = 1;
    int time = 0;       // timer to infect entire tree
    while(!q.empty()) {
        int sz = q.size();
        int fl = 0; 
        for(int i = 0;i<sz;i++) {
            auto node = q.front();
            q.pop();
            // if left exists, mark flag=1 (signifies that we burnt atleast 1 node)
            if(node->left && !vis[node->left]) {
                fl = 1; 
                vis[node->left] = 1; 
                q.push(node->left); 
            }
            // if right exists, mark flag=1 (signifies that we burnt atleast 1 node)
            if(node->right && !vis[node->right]) {
                fl = 1; 
                vis[node->right] = 1; 
                q.push(node->right); 
            }
            // if parent exists, mark flag=1 (signifies that we burnt atleast 1 node)
            if(mpp[node] && !vis[mpp[node]]) {
                fl = 1; 
                vis[mpp[node]] = 1; 
                q.push(mpp[node]); 
            } 
        }
        if(fl) time++; // if atleast 1 flag is made 1, signifies we took 1 unit time
    }
    return time; 
}
    
    TreeNode* bfsToMapParents(TreeNode* root, 
                                     map<TreeNode*, TreeNode*> &mpp, int start) {
    queue<TreeNode*> q; 
    q.push(root); 
    TreeNode* res; 
    while(!q.empty()) {
        TreeNode* node = q.front(); 
        if(node->val == start) res = node; 
        q.pop(); 
        if(node->left) {
            mpp[node->left] = node; 
            q.push(node->left); 
        }
        if(node->right) {
            mpp[node->right] = node;
            q.push(node->right); 
        }
    }
    return res; 
}
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> mpp; 
        TreeNode* target = bfsToMapParents(root, mpp, start); 
        int maxi = findMaxDistance(mpp, target); 
        return maxi; 
    }
};