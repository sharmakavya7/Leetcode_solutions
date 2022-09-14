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
    int ans=0;
    void helper(TreeNode* root, unordered_map<int,int>& mp) {
        mp[root->val]++;        
        if(!root->left && !root->right) {
            int cnt=0;
            for(auto i:mp) {
                if(i.second%2!=0) {
                    cnt++;
                }
            }
            if(cnt<=1) {
                ans++;
            }
            mp[root->val]--;
            return;
        }
        if(root->left) {
            helper(root->left, mp);
        }
        if(root->right) {
            helper(root->right, mp);
        }
        mp[root->val]--;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int>mp;
        
        helper(root, mp);
        return ans;
    }
};

/*

bool isPalin(vector<int>arr, int n) {
        // Initialise flag to zero.
        int flag = 0;

        vector<int>arr2(n);

        reverse(arr.begin(),arr.end());

        for (int i = 0; i < n; i++)
            if (arr[i] != arr2[i]) {
                flag = 1;
                break;
            }

        if (flag == 0)
            return 1;
        else
            return 0;
    }
    bool permute(vector<int>& path) {
        int n = path.size();
        for(int j=0; j<n; j++) {
            next_permutation(path.begin(),path.end());
            for(int i=0; i<path.size(); i++) cout<<path[i]<<" ";
            if(isPalin(path, path.size())) {
                return true;
            }
            cout<<endl;
        }
        return 0;
    }
    
    vector<int>path;
    void helper(TreeNode* root, int ans) {
        if(!root) {
            return;
        }
        // cout<<root->val<<" ";
        path.push_back(root->val);
        if(root->left)
            helper(root->left, ans);
        if(permute(path) && (!root->left && !root->right)) {
            ans+=1;
        }
        path.pop_back();
        if(root->right)
            helper(root->right, ans);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        helper(root, ans);
        return ans;
    }

*/