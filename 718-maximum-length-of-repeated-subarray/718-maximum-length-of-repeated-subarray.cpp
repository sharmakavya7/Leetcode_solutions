class Solution {
public:
    int LCSkaBhai(vector<int>& nums1, vector<int>& nums2,int m, int n) {
        int t[m+1][n+1];
        for(int i=0; i<m+1; i++) {
            for(int j=0; j<n+1; j++) {
                if(i==0 || j==0) {
                    t[i][j]=0;
                }
            }
        }
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(nums1[i-1] == nums2[j-1]){
                    t[i][j] = 1+t[i-1][j-1];   //(text1, text2, m-1, n-1);
                } 
                // else 
                //     t[i][j] = max(t[i-1][j], t[i][j-1]);
                else t[i][j]=0;
            }
        }
        // return t[m][n];
        int mx = INT_MIN;
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++)
                mx = max(mx, t[i][j]);
        return mx;
    }
        
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return LCSkaBhai(nums1, nums2, nums1.size(), nums2.size());
    }
};