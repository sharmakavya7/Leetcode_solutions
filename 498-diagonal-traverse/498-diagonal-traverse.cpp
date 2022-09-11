class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int i=0;
        int j=0;
        bool upward = true;
        vector<int>ans;
        
        while(i<m && j<n) {
            if(upward==true) {
                while(i>0 && j<n-1) {
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                ans.push_back(mat[i][j]);
                if(j==n-1) {
                    i++;
                }
                else j++;
            }
            else {
                while(j>0 && i<m-1) {
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                ans.push_back(mat[i][j]);
                if(i==m-1) {
                    j++;
                }
                else i++;
            }
            upward=!upward;
        }
        return ans;
    }
};