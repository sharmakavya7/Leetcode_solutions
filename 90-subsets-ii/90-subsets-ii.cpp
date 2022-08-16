class Solution {
public:
    // in this method, duplicate entriews are also added in ans array. To remove them, 
    // we need to sort the array and erase the duplicate entires which will cost us 
    // more O(logn) time. 
    void brute(int idx, vector<int>& nums, vector<int>& subs, vector<vector<int>>& ans) {
        if(idx==nums.size()) { 
            ans.push_back(subs);
            return;
        }
        // if include
        subs.push_back(nums[idx]);
        helper(idx+1, nums, subs, ans);    
        
        //if exclude
        subs.pop_back();
        helper(idx+1, nums, subs, ans);
    }
    // To optimize the above approach:
    void helper(int idx, vector<int>& nums, vector<int>& subs, vector<vector<int>>& ans) {
        ans.push_back(subs);
        for(int i=idx; i<nums.size(); i++) {
            if(i!=idx && nums[i]==nums[i-1] ) continue;
            subs.push_back(nums[i]);
            helper(i+1, nums, subs, ans);
            subs.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subs;
        sort(nums.begin(),nums.end());
        // brute(0, nums, subs, ans);
        // additional work(in case of brute force)
        // sort(ans.begin(),ans.end());
        // ans.erase(unique (ans.begin(), ans.end()), ans.end());
        helper(0, nums, subs, ans);
        return ans;
    }
};