class Solution {
public:
    const int N = 101;
    int dp[101][101];
    int solve(int i, int j) {
        if(i == 0 && j == 0) {
            return 1;
        }
        if(i < 0 || j < 0) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int up = solve(i - 1, j);
        int left = solve(i, j - 1);
        
        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(m-1, n-1);
    }
};