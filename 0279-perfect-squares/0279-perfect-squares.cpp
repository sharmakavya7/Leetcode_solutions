class Solution {
public:
    vector<int>dp;
    int ways(int n) {

        if(n == 0) {
            dp[0]=0;
            return 0;
        } 
        if(dp[n] != -1) {
            return dp[n];
        }
        int minvalue = INT_MAX;
        for(int i=1;i*i<=n;i++){
            int ans=ways(n-i*i);
            minvalue=min(minvalue,ans);
        }
        minvalue+=1;
        return dp[n] = minvalue;
    }
    int numSquares(int n) {
        dp.resize(1e4, -1);
        return ways( n);
    }
};