class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row = false, col = false;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0) {                       // (1)
                    if(i == 0) 
                        row = true;
                    if(j == 0) 
                        col = true;
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++){               // (2)
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) 
                    matrix[i][j] = 0;
            }
        }
        if(col){                                              // (3)
            for(int i = 0; i < matrix.size(); i++) // run loop throughout the row of this col(0)
                matrix[i][0] = 0;
        }
        if(row){                                              // (4)
            for(int j = 0; j < matrix[0].size(); j++) // run loop throughout the col of this row(0)
                matrix[0][j] = 0;
        }
    }
    
};