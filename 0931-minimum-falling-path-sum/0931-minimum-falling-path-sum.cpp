class Solution {
public:
    int solve(vector<vector<int>> &mat, int i, int j, int m, vector<vector<int>> &dp) {
        if (j < 0 || j >= m) 
            return 1e9;
        
        if (i == 0) 
            return mat[i][j];
        
        if (dp[i][j] != -1) 
            return dp[i][j];
        
        int up = mat[i][j] + solve(mat, i - 1, j, m, dp);
        int upleft = mat[i][j] + solve(mat, i - 1, j - 1, m, dp);
        int upright = mat[i][j] + solve(mat, i - 1, j + 1, m, dp);
        
        return dp[i][j] = min(up, min(upleft, upright));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        int mini = 1e9;
        for (int j = 0; j < m; j++) {
            mini = min(mini, solve(matrix, n - 1, j, m, dp));
            cout << mini <<" ";
        }
        return mini;
    }
    
};