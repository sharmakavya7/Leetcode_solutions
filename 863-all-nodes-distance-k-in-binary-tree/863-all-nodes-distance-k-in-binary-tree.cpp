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
private:
    void markParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&mp) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            if(front->left) {
                q.push(front->left);
                mp[front->left] = front;
            }
            if(front->right) {
                q.push(front->right);
                mp[front->right] = front;
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;    // parent tracker [node->parent]
        markParent(root, mp);  // basically BFS to mark every parent
        
        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;
        int radial_dist = 0;
        
        while(!q.empty()) {
            int sz = q.size();
            if(radial_dist++==k) 
                break;

            for(int i=0; i<sz; i++) {
                TreeNode* front = q.front();
                q.pop();
                // if left exist
                if(front->left && !visited[front->left]) {
                    q.push(front->left);
                    visited[front->left] = true;
                }
                // if right exists
                if(front->right && !visited[front->right]) {
                    q.push(front->right);
                    visited[front->right] = true;
                }
                // if parent exists
                if(mp[front] && !visited[mp[front]]) {
                    q.push(mp[front]);
                    visited[mp[front]] = true;
                }
            }
        }
        vector<int> result;
        while(!q.empty()) {
            TreeNode* current = q.front(); q.pop();
            result.push_back(current->val);
        }
        return result;
    }
};







