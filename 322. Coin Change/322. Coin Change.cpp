#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib> 
#include <string>
#include <map>
#include <climits>
#include <iterator>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // long long dp[n+1][amount+1];
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        for(int i=1; i<n+1; i++) {
            for(int j=0; j<amount+1; j++) {
                // we don't need any coin to make zero amount
                if(i==0) {  
                    dp[i][j]=INT_MAX-1;
                }
                else if(j==0) { 
                    dp[i][j]=0;
                }
            }
        }
        for(int j=1; j<amount+1; j++)
        {    
            if(j%coins[0]==0) {
                dp[1][j]=j/coins[0];
            }
            else dp[1][j] = INT_MAX-1;
        }

        for(int i=2; i<n+1; i++) {
            for(int j=1; j<amount+1; j++) {
                if(coins[i-1]<=j) {
                    dp[i][j] = min(dp[i][j-coins[i-1]]+1, dp[i-1][j]);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        if(dp[n][amount]==INT_MAX-1){
            return -1;
        }
        return dp[n][amount];
    }
};