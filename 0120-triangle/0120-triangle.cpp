class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>> &t, vector<vector<int>> &dp) {
        if(i == n-1) {
            return t[i][j];
        }
        if(dp[i][j] != -1 ) {
            return dp[i][j];
        }
        int down = 0, diag = 0;
        down = t[i][j] + solve(i+1, j, n, t, dp);
        diag = t[i][j] + solve(i+1, j+1, n, t, dp);
        
        return dp[i][j] = min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0, 0, n, triangle, dp);
    }
};