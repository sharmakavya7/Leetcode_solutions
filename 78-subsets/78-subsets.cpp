class Solution {
public:
    void helper(int i, vector<int>& nums, vector<int>& subs, vector<vector<int>>& ans) {
        if(i==nums.size()) {
            ans.push_back(subs);
            return;
        }
        subs.push_back(nums[i]);
        helper(i+1, nums, subs, ans);
        subs.pop_back();
        helper(i+1, nums, subs, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subs;
        vector<vector<int>> ans;
        helper(0, nums, subs, ans);
        return ans;
    }
};