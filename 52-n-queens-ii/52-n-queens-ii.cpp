class Solution {
public:
    bool isValid(int col, int row, int n, vector<string>&board) {
        // check for upper diagonal
        int duprow = row;
        int dupcol = col;
        // for(int i=row, j=col; i>=0 && j>=0; i--, j--) {
        //     if(board[i][j]=='Q') {
        //         return false;
        //     }
        // }
        while(row>=0 && col>=0) {
            if(board[row][col]=='Q') {
                return false;
            }
            row--;
            col--;
        }
        col = dupcol;
        row = duprow;
        // check for lower diagonal 
        // for(int i=row, j=col; i<n && j<0; i++, j--) {
        //     if(board[i][j]=='Q') {
        //         return false;
        //     }
        // }
        while(row<n && col>=0) {
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        col = dupcol;
        row = duprow;
        // check left columns in the same row
        while(col>=0) {
            if(board[row][col]=='Q') {
                return false;
            }
            col--;
        }
        return true;
    }
    void helper(int i, int n, vector<vector<string>>&ans, vector<string>&board) {
        // i = column
        if(i==n) {
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++) {
            if(isValid(i, row, n, board)) {
                board[row][i] = 'Q';
                helper(i+1, n, ans, board);
                board[row][i] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,(string(n,'.')));
        helper(0, n, ans, board);
        return ans.size();
    }
};