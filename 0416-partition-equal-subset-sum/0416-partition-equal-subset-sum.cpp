class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) {
            return false;
        }
        sum /= 2;
        // cout << sum <<" ";
        int n = nums.size();
        vector<vector<bool>>dp(n, vector<bool>(sum+1, 0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<=sum; j++) {
                if(j == 0) {
                    dp[i][j] = 1;
                }
                if(nums[0] == j) {
                    dp[i][j] = 1;
                }
            }
        }
        for(int i=1; i<n; i++) {
            for(int j=1; j<=sum; j++) {
                bool notTake = dp[i-1][j];
                bool take = 0;
                if(nums[i] <= j) {
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j] = take || notTake;
            }
        }
        return dp[n-1][sum];
    }
};