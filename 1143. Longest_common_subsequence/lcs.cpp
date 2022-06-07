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
//     int t[1001][1001];
    
//     int LCS(string text1, string text2,int m, int n){
//         if(m==0 || n==0){
//             return 0;
//         }
//         if(t[m][n]!=-1) {
//             return t[m][n];
//         }
//         if(text1[m-1] == text2[n-1]){
//             return t[m][n] = 1+LCS(text1, text2, m-1, n-1);
//         }
//         else {
//             return t[m][n] = max(LCS(text1, text2, m-1, n),LCS(text1, text2, m, n-1));
//         }
//     }
    
    int helper(string text1, string text2,int m, int n) {
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
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        // memset(t, -1, sizeof(t));
        // int res = LCS(text1, text2, m, n);
        // return res;
        return helper(text1, text2, m, n);
    }
};