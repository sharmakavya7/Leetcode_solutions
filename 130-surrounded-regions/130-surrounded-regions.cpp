class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(grid[i][j] == 'O'){

            grid[i][j] = '1';

            if(i+1 < grid.size()) 
                dfs(grid, i+1, j);
            
            if(i > 1) 
                dfs(grid, i-1, j);
            
            if(j+1 < grid[i].size()) 
                dfs(grid, i, j+1);
            
            if(j > 1) 
                dfs(grid, i, j-1);
        }
    }
    
    void solve(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return;
        int row = grid.size(), col = grid[0].size();
        
        // traverse boundaries and mark all boundary zeroes and their surr region as 1
        
        //first row and last row
        for(int i=0; i<row; i++){
            dfs(grid, i, 0);
            dfs(grid, i, col-1);
        }
        //first col and last col
        for(int j=1; j<col-1; j++){
            dfs(grid, 0, j);
            dfs(grid, row-1, j);
        }
        
        // last me convert all Os to Xs and all 1s to Os
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (grid[i][j] == 'O') 
                    grid[i][j] = 'X';
        
                else if (grid[i][j] == '1') 
                    grid[i][j] = 'O';
    }
    

    
    
    // METHOD-1 (exp in notes)
//     bool seen;
//     void mark(vector<vector<char>>& board,int i,int j,int r,int c)
//     {
//         if(i<0 || i>r-1 || j<0 || j>c-1)
//             return;
//         if(board[i][j]=='X')
//             return;
        
//         board[i][j] = 'X';
        
//         mark(board,i-1,j,r,c);
//         mark(board,i+1,j,r,c);
//         mark(board,i,j-1,r,c);
//         mark(board,i,j+1,r,c);       
//     }
    
//     void dfs(vector<vector<char>>& board,int i,int j,int r,int c,vector<vector<bool>>& visited)
//     {
//         if(i<0 || i>r-1 || j<0 || j>c-1)
//             return;
        
//         if(board[i][j]=='X' || visited[i][j])
//             return;
//         if(i<=0 || i>=r-1 || j<=0 || j>=c-1)
//             seen = true;
        
//         visited[i][j] = true;
//         // up
//         dfs(board,i-1,j,r,c,visited);
//         // down
//         dfs(board,i+1,j,r,c,visited);
//         // left
//         dfs(board,i,j-1,r,c,visited);
//         // right
//         dfs(board,i,j+1,r,c,visited);
//     }
    
//     void solve(vector<vector<char>>& board) {
//         int r=board.size();
//         if(r<=1)
//             return;
//         int c=board[0].size();
//         if(c<=1)
//             return;
//         vector<vector<bool>> visited(r,vector<bool>(c,false));
        
//         for(int i=1;i<r-1;++i)
//         {
//             for(int j=1;j<c-1;++j)
//             {
//                 if(board[i][j]=='O' && !visited[i][j])
//                 {
//                     seen = false;
//                     dfs(board,i,j,r,c,visited);
//                     if(seen==false)
//                         mark(board,i,j,r,c);
//                     seen = true;
//                 }
//             }
//         }
//     }
};
