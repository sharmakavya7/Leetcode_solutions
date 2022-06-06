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

class solution {
    // MEMOIZATION 
    // bool helper(vector<int>&arr, int sum) {
        // if(sum==0) {
        //     return 1;
        // }
        // if(n==0) {
        //     return 0;
        // }
        // bool t[101][100001];
        
        // for(int i=0; i<arr.size()+1;i++) {
        //     for(int j=1; j<sum+1; j++) {
        //         if(i==0 ) {
        //             t[i][j]=false;
        //         }
        //         if(j==0) {
        //             t[i][j]=true;
        //         }
        //     }
        // }
    //}

    bool isSubsetSum(vector<int>arr, int sum){
        // // code here
       int s = arr.size();
       // bool dp[s+1][sum+1];
        vector<vector<int>> dp(arr.size()+1,vector<int>(sum+1,-1));
       for (int i = 0; i < sum+1; i++)
       {
           dp[0][i]=false;
       }
       for (int i = 0; i < s+1; i++)
       {
           dp[i][0]=true;
       }
       
       for (int i = 1; i < s+1; i++)
       {
           for (int j = 1; j < sum+1; j++)
           {
               if (arr[i-1]<=j)
               {
                   dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
               }
               else
               {
                   dp[i][j]=dp[i-1][j];
               }
               
               
           }
           
       }
   
   return dp[s][sum];
    }
};

// int main() {

//     int N, sum; cin >> N;
//     vector<int>arr(N);|
//     for (int i = 0; i < N; i++){ 
//         cin >> arr[i];
//     }
//     cin >> sum;
//     solution ob;
//     cout << ob.isSubsetSum(arr, sum) << endl;

//     return 0;
// }