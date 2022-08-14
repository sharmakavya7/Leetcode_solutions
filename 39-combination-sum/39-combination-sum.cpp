class Solution {
public:
    void helper(vector<int>& candidates,int target,int idx, vector<int>&subs, vector<vector<int>>&ans){
        if(idx==candidates.size()) {
            if(target == 0) {
                ans.push_back(subs);
                // return;
            }
            return;
        }
        
        if(candidates[idx]<=target) {
            subs.push_back(candidates[idx]);
            helper(candidates, target-candidates[idx], idx, subs, ans);
            subs.pop_back();
        }
        helper(candidates, target, idx+1, subs, ans);
        // if(candidates[idx]<target) {
        //     subs.push_back(candidates[idx]);
        //     for(int i=idx; i<candidates.size(); i++) {
        //         helper(candidates, target, idx, sum+candidates[i], subs, ans);
        //     }
        // }
        // helper(candidates, target, idx+1, sum+candidates[idx], subs, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>subs;
        helper(candidates, target, 0, subs, ans);
        return ans;
    }
};