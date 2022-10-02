class Solution {
public:
    int mod = 1e9+7;
    int solve(int d,int f,int target, vector<vector<int>> &dp) {
        
        if(target==0 && d==0) 
            return 1;
        if(target<0 || d==0) 
            return 0;
        
        if(dp[d][target]!=-1) 
            return dp[d][target];
        
        int ans=0;
        
        for(int i=1;i<=f;i++) {
            
            ans = (ans + solve(d-1, f, target-i, dp)) % mod;
        }
        return dp[d][target]=ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        
		vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(n, k, target, dp);
    }
};