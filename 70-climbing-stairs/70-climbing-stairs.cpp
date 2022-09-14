class Solution {
public:
    int dp[46];
    int helper(int n) {

        dp[0]=1;
        dp[1]=2;
        dp[2]=2;
        for(int i=2; i<n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
        // int left = helper(n-1) ;
        // int right = helper(n-2);
        // return left+right;
    }
    
    int climbStairs(int n) {
        //int ans = 0;
        return helper(n);
         
    }
};