class Solution {
public:
    bool isValid(vector<vector<char>>& board, int i, int j, char num) {
        for (int idx = 0; idx < 9; idx++) {
            
            if (board[i][idx] == num) 
                return false;
            
            if (board[idx][j] == num) 
                return false;
            
            // Yaad krlo ye formula(explanation in striver's vid)
            if (board[(i/3)*3 + (idx/3)][(j/3)*3 + (idx%3)] == num) 
                return false;
        }
        
        return true;
    }
    bool helper(vector<vector<char>> &board, int row, int col) {    
        if(row == 9) 
            return true;

        // call next row
        if(col == 9) 
            return helper(board, row + 1, 0);

        // already marked
        if(board[row][col] != '.') 
            return helper(board, row, col + 1);

        for(char c = '1'; c <= '9'; c++) {

            if(isValid(board, row, col, c)) {

                board[row][col] = c;

                if(helper(board, row, col + 1)==true)
                    return true;

                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};