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
string shortestCommonSupersequence(string text1, string text2) {
        int s1=text1.size();
        int s2=text2.size();
        vector<vector<int>> t(s1+1,vector<int>(s2,-1));
        // int dp[s1+1][s2+1];
        for(int i=0;i<=s1;i++){
            for(int j=0;j<=s2;j++){
                if(i==0 || j==0)
                    t[i][j]=0;
            }
        }
    // LCS
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(text1[i-1]==text2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
    // Print LCS
        string ans="";
        int i=s1, j=s2;
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                ans.push_back(text1[i-1]);
                i--;
                j--;
            }
            else{
                if(t[i][j-1] > t[i-1][j]){
                    ans.push_back(text2[j-1]);
                    j--;
                }
                else{
                    ans.push_back(text1[i-1]);
                    i--;
                }   
            }
        }
// these 2 below loops to check if any one of the string is left with some  character then we also have to pushback them too
        while(i>0){
            ans.push_back(text1[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(text2[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
