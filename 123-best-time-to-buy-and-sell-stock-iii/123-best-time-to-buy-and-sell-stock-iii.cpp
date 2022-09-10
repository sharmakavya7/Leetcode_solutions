class Solution {
public:
    
//     int helper(int i, int buy, int cap, vector<int>& prices, int profit) {
//         if(i==prices.size() || cap == 0) {
//             return 0;
//         }

//         // 2 choices in buying 
//         if(buy==1) {
//             profit = max((-prices[i]+helper(i+1, 0, cap, prices, profit)), 
//                          (0 + helper(i+1, 1, cap, prices, profit)));
//         }
//         // when we sold, transaction got completed, => cap-1
//         else {
//             profit = max((prices[i] + helper(i+1, 1, cap-1, prices, profit)), 
//                         (0 + helper(i+1, 0, cap, prices, profit)));
//         }
//         return profit;
//     }
        
    int memo(int i, int buy, int cap, vector<int>& prices, int profit, vector<vector<vector<int>>>&dp) {
        if(i==prices.size() || cap == 0) {
            return 0;
        }
        
        if(dp[i][buy][cap]!=-1) {
            return dp[i][buy][cap];
        }
        // 2 choices in buying 
        if(buy==1) {
            profit = max((-prices[i]+memo(i+1, 0, cap, prices, profit, dp)), 
                         (0 + memo(i+1, 1, cap, prices, profit, dp)));
        }
        // when we sold, transaction got completed, => cap-1
        else {
            profit = max((prices[i] + memo(i+1, 1, cap-1, prices, profit, dp)), 
                        (0 + memo(i+1, 0, cap, prices, profit, dp)));
        }
        return dp[i][buy][cap] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        // 3D DP  [ind(n)][buy(2)][cap(3)]
        vector<vector<vector<int>>>dp(prices.size(), 
                vector<vector<int>>(2, vector<int>(3, -1)));
        return memo(0, 1, 2, prices, 0, dp);
    }
};