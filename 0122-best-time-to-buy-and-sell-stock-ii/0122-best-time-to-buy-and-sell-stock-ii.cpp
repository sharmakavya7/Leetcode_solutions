class Solution {
public:
    /* RECURRENCE
    - profit(buying) = max( (take + moving to nxt ind we can't take), (not take + moving to next ind we can take) );
    - profit(selling) = max ( (sell + moving to nxt ind we can buy/take), (not sell + moving to next ind we can't buy cz we still have a stock that should be sold first) )
    */
    // int helper(int i, int buy, vector<int>& prices, int profit) {
    //     if(i==prices.size()) {
    //         return 0;
    //     }
    //     // 2 choices in buying 
    //     if(buy) {
    //         profit = max((-prices[i]+helper(i+1, 0, prices, profit)), 
    //                      (0 + helper(i+1, 1, prices, profit)));
    //     }
    //     else {
    //         profit = max((prices[i] + helper(i+1, 1, prices, profit)), 
    //                     (0 + helper(i+1, 0, prices, profit)));
    //     }
    //     return profit;
    // }
    
    int memo(int i, bool buy, vector<int>& prices, int profit, vector<vector<int>>& dp) {
        if(i==prices.size()) {
            return 0;
        }
        
        if(dp[i][buy]!=-1) 
            return dp[i][buy];
        
        // 2 choices in buying 
        // buying
        if(buy) {
            profit = max((-prices[i]+memo(i+1, 0, prices, profit, dp)), 
                         (0 + memo(i+1, 1, prices, profit, dp)));
        }
        // selling
        else {
            profit = max((prices[i] + memo(i+1, 1, prices, profit, dp)), 
                        (0 + memo(i+1, 0, prices, profit, dp)));
        }
        return dp[i][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
        return memo(0, 1, prices, 0, dp);

    }
};

/*
        // int profit=0;
        // // for(auto i:prices) {
        // for(int i=1; i<prices.size();i++) {
        //     if(prices[i-1]<prices[i]) {
        //         profit+=(prices[i]-prices[i-1]);
        //     }
        // }
        // return profit;
        
*/