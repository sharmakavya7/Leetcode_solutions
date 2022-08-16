class Solution {
public:
    void helper(int idx, vector<int>& nums, vector<int>& subs, vector<vector<int>>& ans) {
        // if(idx>=nums.size()) {
            ans.push_back(subs);
        // }
        for(int i=idx; i<nums.size(); i++) {
            if(i!=idx && nums[i]==nums[i-1] ) continue;
            subs.push_back(nums[i]);
            helper(i+1, nums, subs, ans);
            subs.pop_back();
        }
        // helper(idx+1, nums, subs, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subs;
        sort(nums.begin(),nums.end());
        helper(0, nums, subs, ans);
        return ans;
    }
};