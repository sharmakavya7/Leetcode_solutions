class Solution {
public:

    int dp[21][2001];
    int dfs(int index, vector<int>& nums, int &S, int sum) {

        if(index==nums.size())
            return (sum==S) ? 1 : 0;
        
        if(dp[index][sum+1000]!=-1) 
            return dp[index][sum+1000];
        
        int count = 0;
        
        count+= dfs(index+1,nums,S,sum+nums[index]);
        count+= dfs(index+1,nums,S,sum-nums[index]);
        
        return dp[index][sum+1000] = count;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // int sum = accumulate(nums.begin(), nums.end(), 0);
        memset(dp,-1,sizeof(dp));
        return dfs(0,nums,target,0);
        // return targetsum(nums.size()-1, , 0, nums);
    }
};