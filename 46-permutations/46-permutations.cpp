class Solution {
public:
    // by swapping (no need to additional data structure):
    void helper(int i, vector<vector<int>>&ans, vector<int>& nums) {
        if(i==nums.size()) {
            ans.push_back(nums);
            return;
        }
        else {
            for(int j=i; j<nums.size(); j++) {
                swap(nums[i],nums[j]);
                helper(i+1, ans, nums);
                swap(nums[i],nums[j]);
            }
        }
    }
//      Another method: by actual backtrack
//     void helper(vector<bool>&vis, vector<int>&subs, vector<vector<int>>&ans, vector<int>& nums) {
//         if(subs.size()==nums.size()) {
//             ans.push_back(subs);
//             return;
//         }

//         for(int i=0; i<nums.size(); i++) {
//             if(!vis[i]) {
//                 subs.push_back(nums[i]);
//                 vis[i]=1;
//                 helper(vis, subs, ans, nums);
//                 subs.pop_back();
//                 vis[i]=0;
//             }
//         }
//     }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        // vector<bool>vis(nums.size(),0);
        // vector<int>subs;
        // helper(vis, subs, ans, nums);
        
        // sort(nums.begin(),nums.end());
        helper(0, ans, nums);
        return ans;
    }
};