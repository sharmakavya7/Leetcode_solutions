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
    int mod = 1e9 + 7;
    int helper(int m, int n, int maxMoves, int i, int j, int cnt, vector<vector<vector<int>>> & dp) {
        if(maxMoves==0) {
            return i>=m || j>=n || i<0 || j<0;
        }
        if(i>=m || j>=n || i<0 || j<0) {
            return 1;
        }
        if(dp[maxMoves][i][j]!= -1) {
            return dp[maxMoves][i][j]%mod;
        }
        int x = 0;
        // down
        x = (x + helper (m, n, maxMoves-1, i+1, j, cnt, dp))% mod;  
        // up
        x = (x + helper(m, n, maxMoves-1, i-1, j, cnt, dp))% mod;
        // left
        x = (x + helper(m, n, maxMoves-1, i, j-1, cnt, dp))% mod;
        // right
        x = (x + helper(m, n, maxMoves-1, i, j+1, cnt, dp))% mod;
                  
        dp[maxMoves][i][j] = x;
        return dp[maxMoves][i][j]% mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        vector<vector<vector<int>>>dp(maxMove+1,vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return helper(m, n, maxMove, startRow, startColumn, 0, dp);
    }
};