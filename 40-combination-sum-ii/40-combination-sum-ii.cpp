class Solution {
public:
    void helper(vector<int>& candidates,int target,int idx, vector<int>&subs, set<vector<int>>&ans){
        if(idx==candidates.size()) {
            if(target == 0) {
                ans.insert(subs);
                // return;
            }
            return;
        }
        if(candidates[idx]<=target) {
            subs.push_back(candidates[idx]);
            helper(candidates, target-candidates[idx], idx+1, subs, ans);  // pick,
            subs.pop_back();
        }
        int next_index = idx;
        while (next_index < candidates.size() && candidates[next_index] == candidates[idx])
            next_index++;
        helper(candidates, target, next_index, subs, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>>ans;
        vector<int>subs;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, subs, ans);
        vector<vector<int>>res;
        for(auto x: ans) {
            res.push_back(x);
        }
        return res;
    }
};