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
    // LIS + LCS
    int lcs(string text1, string text2) {
        int m = text1.size(),  n = text2.size();
        // int t[m+1][n+1];
        vector<vector<int>> t(m+1,vector<int>(n,-1));
        for(int i=0; i<m+1; i++) {
            for(int j=0; j<n+1; j++) {
                if(i==0 || j==0) {
                    t[i][j]=0;
                }
            }
        }
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(text1[i-1] == text2[j-1]){
                    t[i][j] = 1+t[i-1][j-1];   //(text1, text2, m-1, n-1);
                } 
                else 
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        return t[m][n];
    }
    
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }
    
    int longestStrChain(vector<string>& words) {

        int n = words.size();
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),compare);
        for(int i = 1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(words[i].length()-words[j].length()==1 && lcs(words[i],words[j])==words[j].length() && dp[i]<dp[j]+1)
                    dp[i] = dp[j] + 1;
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};