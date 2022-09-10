class Solution {
public:
    int getAns(vector<int>& Arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp ){
        if(ind==n || cap==0) return 0;
        
        if(dp[ind][buy][cap]!=-1)
            return dp[ind][buy][cap];
        
        int profit=0;
        
        // 2 choices in buying 
        profit = max( -Arr[ind] + getAns(Arr,n,ind+1,1,cap,dp), 
                     0 + getAns(Arr,n,ind+1,0,cap,dp) );
        
        // when we sold, transaction got completed, => cap-1
        if(buy==1){// We can sell the stock
            profit = max(0+getAns(Arr,n,ind+1,1,cap,dp),
                        Arr[ind] + getAns(Arr,n,ind+1,0,cap-1,dp));
        }

        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),
                                    vector<vector<int>>
                                            (2,vector<int>(k+1,-1)));
    
        return getAns(prices,prices.size(),0,0,k,dp);
    }
};