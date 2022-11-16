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
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1, -1));
        int ans = coinWays(coins.size()-1, amount, coins, dp);
        return (ans < INT_MAX-1)?ans:-1;
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