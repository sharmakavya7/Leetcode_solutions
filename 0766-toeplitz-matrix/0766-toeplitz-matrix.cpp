class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][j] != matrix[i-1][j-1]) {
                    return false;
                }
            }
        }
        // while(k < m) {
        //     int prev = matrix[0][k];
        //     while(i > n && j > m) {
        //         if(matrix[i][j] != prev) {
        //             return false;
        //         }
        //         i++, j++;
        //     }
        //     k++;
        // }
        // k = 1, i = k, j = k;
        // while(k < n) {
        //     int prev = matrix[k][0];
        //     while(i > n && j > m) {
        //         if(matrix[i][j] != prev) {
        //             return false;
        //         }
        //         i++, j++;
        //     }
        //     k++;
        // }
        return true;
    }
};