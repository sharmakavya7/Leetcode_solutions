class Solution {
public:
    int kadane(vector<int>&vt,int k){
        set<int> st;
        int sum=0;
        int result=INT_MIN;
        st.insert(0);
        for(int i=0;i<vt.size();i++){
            sum+=vt[i];
            auto it=st.lower_bound(sum-k);
            
            if(it!=st.end()){
                result=max(result,sum-(*it));
            }
            
            st.insert(sum);
        }
        
        return result;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int result=INT_MIN;
        
        for(int l=0;l<m;l++){
            vector<int> sum(n,0);
            for(int r=l;r<m;r++){
                
                for(int i=0;i<n;i++){
                    sum[i]+=matrix[i][r];
                }
                
                result=max(result,kadane(sum,k));
            }
        }
        
        return result;
        
//         int i=0;
//         int j=n-1;
//         int sum = (matrix[0][n-1]<=k) ? matrix[0][n-1] : 0;   // top right block
//         cout<< sum<<" ";

//         while(i<m && j>=0) {
            
//             int remain = k - sum;
            
//             if(matrix[i][j-1] <= remain && matrix[i][j-1] != '.' && j>=0) {    //right to left
                
//                 sum+=matrix[i][j-1];    // sum
//                 matrix[i][j-1] = '.';
//                 j--;
//             }
//             else if(matrix[i+1][j] <= remain && matrix[i+1][j] != '.' && i<m) {  // top to down
                
//                 sum+=matrix[i+1][j];    // sum
//                 matrix[i+1][j] = '.';
//                 i++;
//             }
//             else if(matrix[i][j+1] <= remain && matrix[i][j+1] != '.' && j<n) {   // left to right
                
//                 sum+=matrix[i][j+1];    // sum
//                 matrix[i][j+1] = '.';
//                 j++;
//             }
//             else if(matrix[i-1][j] <= remain && matrix[i-1][j] != '.' && i>=0) {   // down to top
                
//                 sum+=matrix[i-1][j];    //sum
//                 matrix[i-1][j] = '.';
//                 i--;
//             }
//             else if(sum == k) {
//                 return sum;
//             }
//             else return sum;
//         }
//         return sum;
    }
};