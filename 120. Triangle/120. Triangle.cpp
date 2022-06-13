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
    int helper(vector<vector<int>>& t, int i, int j, vector<vector<int>>&dp) {
        if(i >= t.size() || j >= t.size()) {
            return 0;
        }
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        return dp[i][j] = t[i][j] + min(helper(t, i+1, j,dp), helper(t, i+1, j+1,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        // int n = triangle[0].size();         // what's the matter with this?!
        vector<vector<int>>dp(m, (vector<int>(m, -1)));
        
        return helper(triangle, 0, 0, dp);
    }
};
