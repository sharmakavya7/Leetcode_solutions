class Solution {
public:
    int coinWays(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if(amount == 0) {
            return 0;
        }
        if(i<0 || amount < 0) 
            return INT_MAX-1;
        if(dp[i][amount] != -1) {
            return dp[i][amount];
        }
        int pick = 1 + coinWays(i, amount - coins[i], coins, dp);
        
        int notPick = coinWays(i-1, amount, coins, dp);
        
        return dp[i][amount] = min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        // memo:
        
        // vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1, -1));
        // int ans = coinWays(coins.size()-1, amount, coins, dp);
        // return (ans < INT_MAX-1)?ans:-1;
        
        // tabulation:
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, 0));
        // dp[0][0] = 0;
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=amount; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = (j == 0) ? 0 : INT_MAX - 1;
                }
            }
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=amount; j++) {
                if(coins[i-1] <= j) {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1) ;
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        int res = dp[n][amount];
        return (res == INT_MAX - 1) ? -1 : res;
    }
};

/*

class Solution {
public:
    int coinWays(int i, int amount, vector<int>& coins) {
        if(amount == 0) {
            return 0;
        }
        if(i<0 || amount < 0) return INT_MAX-1;
        int pick = 0;
        if(coins[i] <= amount)
            pick = 1 + coinWays(i, amount - coins[i], coins);
        
        int notPick = coinWays(i-1, amount, coins);
        
        return min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = coinWays(coins.size()-1, amount, coins);
        return (ans < INT_MAX-1)?ans:-1;
    }
};

*/