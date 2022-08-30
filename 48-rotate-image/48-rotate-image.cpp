class Solution {
public:
    void transpose(int n, vector<vector<int>>& matrix) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        //TRANSPOSE OF A MATRIX!!! and then REVERSE its row elements
        int n = matrix.size();
        
        transpose(n, matrix);
        for(int i=0; i<n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};