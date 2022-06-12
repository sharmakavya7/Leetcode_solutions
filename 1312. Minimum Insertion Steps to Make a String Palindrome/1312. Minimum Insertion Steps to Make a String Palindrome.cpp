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
int LCS(string text1, string text2) {
        int s1=text1.size();
        int s2=text2.size();
        // int dp[s1+1][s2+1];
        vector<vector<int>> dp(s1+1,vector<int>(s2,-1));
        for(int i=0;i<=s1;i++){
            for(int j=0;j<=s2;j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
            }
        }
    // LCS
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[s1][s2];
    }
int longestPalindromeSubseq(string s) {
        string t;
        for(int i=s.size()-1;i>=0;i--)
          t.push_back(s[i]);
        return LCS(s, t);
    }
    int minInsertions(string s) {
        int n = s.size();
        return n - longestPalindromeSubseq(s);
    }
};