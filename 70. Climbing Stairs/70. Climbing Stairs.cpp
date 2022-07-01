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
    int dp[46];
    int helper(int n) {
        // if(n==0) {
        //     return 1;
        // }
        // if(n==1) {
        //     return 1;
        // }
        // if(n==2) {
        //     return 2;
        // }
        dp[0]=1;
        dp[1]=2;
        dp[2]=2;
        for(int i=2; i<n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
        // int left = helper(n-1) ;
        // int right = helper(n-2);
        // return left+right;
    }
    
    int climbStairs(int n) {
        return helper(n);
    }
};