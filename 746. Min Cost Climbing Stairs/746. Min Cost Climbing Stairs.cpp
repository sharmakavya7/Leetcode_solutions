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
    int dp[1001];
    int helper(vector<int>& cost, int n) {
        dp[0] = cost[0];
        dp[1] = cost[1];
        // dp[2] = cost[0]<cost[1] ? cost[0]:cost[1];
        
        for(int i=2; i<n; i++) {
            dp[i] = cost[i]+ min(dp[i-1], dp[i-2]);
        }
        // int minCost = minCost + min(cost[n],cost[n-1]);
        return min(dp[n-1], dp[n-2]);
        // return dp[n-1];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return helper(cost, n);
    }
};