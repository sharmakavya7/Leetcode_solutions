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
    int fib(int n) {
        //int *dp = new int [n+1];
        vector<int> dp(n+1);
        // int dp[n+1]; 
        if(n==0) {
            return 0;
        }
        dp[0] = 0;
        dp[1] = 1;
        
        if(n==0)return 0;
        if(n==1) {
            //dp[n] = 0;
            return 1;
        }
        
        for(int i = 2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
    return dp[n];
    }
};