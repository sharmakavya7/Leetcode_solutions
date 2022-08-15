class Solution {
public:
    void helper(vector<int>& candidates,int target,int idx, vector<int>&subs, vector<vector<int>>&ans){
        if(target == 0) {
            ans.push_back(subs);
            return;
        }
        // cout<<candidates[idx]<<" "<<target<<" ";

        for(int i=idx; i<candidates.size(); i++) {
            if(candidates[i]>target) break; // no point of it to add it to the ans if the  candidate at ith element exceeds the target no picking up hence break 
            if(i>idx && candidates[i] == candidates[i-1])
                continue;
            subs.push_back(candidates[i]);
            helper(candidates, target-candidates[i], i+1, subs, ans);
            subs.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>subs;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, subs, ans);

        return ans;
    }
};