//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
// int dp[100001][100001];
    bool subsetSum(int i, int k, vector<int>&arr, vector<vector<int>> &dp) {
        if(k == 0) {
            return true;
        }
        if(i == 0) {
            return (arr[0] == k);
        }
        if(dp[i][k] != -1) {
            return dp[i][k];
        }
        bool notTake = subsetSum(i-1, k, arr, dp);
        bool take = false;
        if(arr[i] <= k) {
            take = subsetSum(i-1, k-arr[i], arr, dp);
        }
        return dp[i][k] = take || notTake;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        // vector<vector<int>> dp (arr.size(), vector<int> (sum+1, -1));
        // memset(dp, -1, sizeof(dp));
        // return subsetSum(arr.size()-1, sum, arr, dp);
        
        int n = arr.size();
        vector<vector<bool>> dp (arr.size(), vector<bool> (sum+1, 0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(j == 0) {
                    dp[i][j] = 1;
                }
                if(arr[0] == j) {
                    dp[i][j] = 1;
                }
            }
        }
        
        for(int i=1; i<n; i++) {
            for(int j=1; j<=sum; j++) {
                bool notTake = dp[i-1][j];
                bool take = false;
                if(arr[i] <= j) {
                    take = dp[i-1][j-arr[i]];
                }
               dp[i][j] = take || notTake;
            }
        }
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends