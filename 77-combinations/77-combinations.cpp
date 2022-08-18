class Solution {
public:
    void helper(int idx, int k, int t, vector<int>&nums, vector<int>&subs, vector<vector<int>>&ans) {
        if((k==0 || idx==nums.size()) && subs.size()==t) {
            ans.push_back(subs);
            return;
        }
        // cout<<nums[idx]<<" ";
        for(int i=idx; i<nums.size(); i++) {
            subs.push_back(nums[i]);
            k--;
            helper(i+1, k, t, nums, subs, ans);
            k++;
            subs.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums;
        for(int i=1; i<=n; i++) {
            nums.push_back(i);
        }
        for(auto i:nums) {
            cout<<i<<" ";
        }
        vector<int>subs;
        vector<vector<int>>ans;
        helper(0, k, k, nums, subs, ans);
        return ans;
    }
};