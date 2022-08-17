class Solution {
public:
    // void helper(int idx, vector<bool>&vis, vector<int>&subs, vector<vector<int>>&ans, vector<int>& nums) {
    //     if(subs.size()==nums.size()) {
    //         ans.push_back(subs);
    //         return;
    //     }
    //     vis[idx] = 0;
    //     for(int i=0; i<nums.size(); i++) {
    //         if(vis[i]==0) {
    //             subs.push_back(nums[i]);
    //             helper(i+1, vis, subs, ans, nums);
    //             subs.pop_back();
    //             vis[i]=1;
    //         }
    //     }
    // }
    void helper(vector<bool>&vis, vector<int>&subs, vector<vector<int>>&ans, vector<int>& nums) {
        if(subs.size()==nums.size()) {
            ans.push_back(subs);
            return;
        }

        for(int i=0; i<nums.size(); i++) {
            if(!vis[i]) {
                subs.push_back(nums[i]);
                vis[i]=1;
                helper(vis, subs, ans, nums);
                subs.pop_back();
                vis[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>vis(nums.size(),0);
        vector<int>subs;
        vector<vector<int>>ans;
        helper(vis, subs, ans, nums);
        return ans;
    }
};