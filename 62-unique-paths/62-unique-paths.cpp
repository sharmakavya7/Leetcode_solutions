class Solution {
private:
    int helper(int m, int n, vector<vector<int>>&memo) {
        
        if(m<0 || n<0) {
            return 0;
        }
        else if (m == 0 || n == 0) 
            return 1;
        
        if (memo[m][n]!=-1){
            return memo[m][n];
        }
        else {
            memo[m][n] = helper(m-1, n, memo)+ helper(m,n-1, memo);
            return memo[m][n];
        }
    }
    
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return helper(m-1,n-1,memo);
    }
};