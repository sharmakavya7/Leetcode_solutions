class Solution {
public:
    void helper(int ind, vector<int>& nums, vector<int>& subs, set<vector<int>>&result, int n) {
        if(n>=2) {
            result.insert(subs);
            // return;
        }
        
        for (int i = ind; i < nums.size(); ++i) {
            if(subs.size() == 0 || nums[i] >= subs[subs.size() - 1]) {
                subs.push_back(nums[i]);
                helper(i+1, nums, subs, result, n+1);
                subs.pop_back();
            }
        }
        // not pick
        // helper(i+1, nums, subs, ans);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        vector<int>subs;
        set<vector<int>>resultSet;
        helper(0, nums, subs, resultSet, 0);
        vector<vector<int>> result(resultSet.begin(), resultSet.end());
        return result;
    }
};