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

class solution {
    public:
    int dp[1001][1001];
    //Function to return max value that can be put in knapsack of capacity W.
    int memo(int W, int wt[], int val[], int n) {
        if(n==0||W==0) {
           return 0;
        }
        if(dp[n][W] != -1) {
            return dp[n][W];
        }
        if(wt[n-1]<=W) {
            return dp[n][W] = std::max(val[n-1] + memo(W-wt[n-1], wt, val, n-1), memo(W, wt, val, n-1));
        }
        else if(wt[n-1]>W) {
            return dp[n][W] = memo(W, wt, val, n-1);
        }
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        memset(dp, -1, sizeof(dp));
        return memo(W, wt, val, n);
       // Your code here
       // RECURSION 
    //   if(n==0||W==0) {
    //       return 0;
    //   }
    //   if(wt[n-1]<=W) {
    //       return max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1));
    //   }
    //   else if(wt[n-1]>W) {
    //       return (knapSack(W, wt, val, n-1));
    //   }
    }
};