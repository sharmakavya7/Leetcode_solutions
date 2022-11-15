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
        int steal = nums[i] + maxMoney(i-2, nums, dp);
        
        // not pick
        int notSteal = 0 + maxMoney(i-1, nums, dp);
        
        return dp[i] = max(steal, notSteal);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return maxMoney(nums.size()-1, nums, dp);
        // space optimization
        // int prev = nums[0], prev2 = 0, curi = 0;
        // int ans = 0;
        // for(int i = 1; i<nums.size(); i++) {
        //     int steal = nums[i] + prev2;
        //     int noSteal = 0 + prev;
        //     curi = max(steal, noSteal);
        //     prev2 = prev;
        //     prev = curi;
        // }
        // return prev;
    }
};

// DP tabulation:
// vector<int>dp(nums.size(), 0);
//         // int ans = maxMoney(nums.size()-1, nums, dp);
//         int ans = 0;
//         int n = nums.size();
//         dp[0] = nums[0];
        
//         for(int i=1; i<nums.size(); i++) {
//             int steal = nums[i];
//             if(i>=2) {
//                 steal += dp[i-2];
//             }
//             int noSteal = 0 + dp[i-1];
            
//             dp[i] = max(steal, noSteal);
//         }
        
//         return dp[n-1];