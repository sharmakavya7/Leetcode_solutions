class Solution {
public:
    int dp[31][1001];
    int MOD = 1e9+7;
    int solve(int d,int f,int target) {
        
        if(target==0 && d==0) 
            return 1;
        if(target<0 || d==0) 
            return 0;
        
        if(dp[d][target]!=-1) 
            return dp[d][target];
        
        int ans=0;
        
        for(int i=1;i<=f;i++) {
            
            ans = (ans + solve(d-1, f, target-i)) % MOD;
        }
        return dp[d][target]=ans;
    }
    
    int numRollsToTarget(int d, int f, int target) {
        memset(dp, -1, sizeof dp);
        return solve(d, f, target);
    }
};