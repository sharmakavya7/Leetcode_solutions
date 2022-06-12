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
    	int LCS(string X, string Y, int n, int m) {
        	// int dp[n + 1][m + 1]; // DP - matrix
            vector<vector<int>> dp(n+1,vector<int>(m,-1));
        	for (int i = 0; i <= n; i++)
        		for (int j = 0; j <= m; j++)
        			if (i == 0 || j == 0)
        				dp[i][j] = 0;
        
        	for (int i = 1; i <= n; i++)
        		for (int j = 1; j <= m; j++)
        			if (X[i - 1] == Y[j - 1] && i != j) // jsut add an condition that element at ith index should not be equal to jth index 
        				dp[i][j] = 1 + dp[i - 1][j - 1];
        			else
        				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        
        	return dp[n][m];
        }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.size();
		    return LCS(str, str, n, n);
		}    
};