class Solution {
public:
    vector<vector<bool>> solid, visited;
    int n, m;
    
    void dfs(vector<vector<char>>& board, int i, int j){
        
        if(i < 0 || j < 0 || i == n || j == m || visited[i][j]==true) 
            return;
        
        visited[i][j] = true;
        
        if(board[i][j] == 'X') 
            return;
        
        if(board[i][j] == 'O') 
            solid[i][j] = true;
        
        dfs(board, i + 1, j);
        dfs(board, i, j + 1);
        dfs(board, i - 1, j);
        dfs(board, i, j - 1);
    }
    
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        
        for(int i = 0; i < n; i++){
            vector<bool> v;
            for(int j = 0; j < m; j++){
                v.push_back(false);
            }
            solid.push_back(v);
            visited.push_back(v);
        }
        
        //Step1: Passing cells along the border to find solid cells
        for(int j = 0; j < m; j++)      
            dfs(board, 0, j);
        
        for(int i = 1; i < n; i++)      
            dfs(board, i, m - 1);
        
        for(int j = m - 2; j >= 0; j--) 
            dfs(board, n - 1, j);
        
        for(int i = n - 2; i >= 1; i--) 
            dfs(board, i, 0);
        
        //Step2: Finding the remaining cells and capturing them
        for(int i = 1; i < n - 1; i++){
            for(int j = 1; j < m - 1; j++){
                if(!solid[i][j] && !visited[i][j] && board[i][j] == 'O') 
                    board[i][j] = 'X';
            }
        }
    }
};
