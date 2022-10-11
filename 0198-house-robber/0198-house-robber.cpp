class Solution {
public:
    int maxMoney(int i, vector<int>&nums, vector<int>&dp) {
        if(i == 0) {
            return nums[i];
        }
        if(i<0) {
            return 0;
        }
        if(dp[i]!=-1) {
            return dp[i];
        }
        // pick
        // if(i>=2)
            int steal = nums[i] + maxMoney(i-2, nums, dp);
        // not pick
        // if(i>=1)
            int notSteal = 0 + maxMoney(i-1, nums, dp);
        
        return dp[i] = max(steal, notSteal);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        int ans = maxMoney(nums.size()-1, nums, dp);
        return ans;
    }
};