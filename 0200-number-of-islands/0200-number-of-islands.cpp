class Solution {
public:
    int DR[4] = {-1, 0, +1, 0};
    int DC[4] = {0, +1, 0, -1};
    
    void dfs(int i, int j, vector<vector<char>>& grid, int n, int m) {
        // vis[i][j] = 1;
        for(int k=0; k<4; k++) {
            int nrow = DR[k] + i;
            int ncol = DC[k] + j;
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol]=='1') {
                grid[nrow][ncol]='0';
                dfs(nrow, ncol, grid, n, m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int,int>>vis(n, vector<int>(m, 0));
        int islands=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1') {
                    islands++;
                    dfs(i,j, grid, n, m);
                }
            }
        }
        return islands;
    }
};