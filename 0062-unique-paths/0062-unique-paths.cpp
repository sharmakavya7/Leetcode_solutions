class Solution {
public:
    // T.C. => m x n
    // S.C. => m x n

    int solve(int m, int n, vector<vector<int>>& dp) {
        // dp[0][0] = 1;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                int up = 0, left = 0;
                if(i > 0)
                    up = dp[i-1][j];
                if(j > 0)
                    left = dp[i][j-1];
                
                dp[i][j] = up + left;
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m,vector<int>(n,-1));
        // memset(dp, 0, sizeof(dp));
        return solve(m, n, dp);
    }
};