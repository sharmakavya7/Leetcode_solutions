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
    int mod = 1000000007;
    int dp[1001][1001] = {1};
    int kInversePairs(int n, int k) {
        if (dp[n][k])
            return dp[n][k];
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = (dp[i-1][j] + (j>0 ? dp[i][j-1] : 0)) % mod;
                if (j >= i)
                    dp[i][j] = (mod+dp[i][j] - dp[i-1][j-i]) % mod;
            }
        }
        return dp[n][k];
    }
};