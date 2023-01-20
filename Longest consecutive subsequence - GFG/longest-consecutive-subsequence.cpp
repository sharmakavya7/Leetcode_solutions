//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n) {
        unordered_map<int, int>mp;
        int mn = 1e9;
        int mx = 0;
        for(int i=0; i<n; i++) {
            mp[arr[i]]++;
            mn = min(mn, arr[i]);
            mx = max(mx, arr[i]);
        }
        int curlen = 0;
        int maxlen = 0;
        for(int i=mn; i<=mx; i++) {
            if(mp.find(i) !=mp.end()) {
                curlen++;
            }
            else {
                curlen=0;
            }
            maxlen = max(curlen, maxlen);
        }
        return maxlen;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends