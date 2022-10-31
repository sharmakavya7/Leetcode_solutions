class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid) {
        // dp[0][0] = 1;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                
                if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                if( obstacleGrid[i][j] == 1) {
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) {
            return 0;
        }
        vector<vector<int> > dp(m,vector<int>(n, 0));
        // memset(dp, 0, sizeof(dp));
        return solve(m, n, dp, obstacleGrid);
    }
};