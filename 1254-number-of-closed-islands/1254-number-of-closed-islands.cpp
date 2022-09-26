class Solution {
public:
    /* IMPORTANT NOTE: 
        WHY I CANNOT USE `return dfs(g, i+1, j) && dfs(g, i, j+1) && dfs(g, i-1, j) && dfs(g, i, j-1);`???
        BECAUSE IF ANY OF THE FIRST DFS() RETURNS FALSE, FOLLOWING ONES WILL NOT EXECUTE!!! THEN WE DON'T
        HAVE THE CHANCE TO MARK THOSE 0s TO 1s!!!
        */
    void dfs(int i, int j, vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        if(i < 0 || j < 0 || j >= c || i >= r || grid[i][j] != 0) return;
        grid[i][j] = 1;
        dfs(i-1, j, grid);dfs(i, j-1, grid);dfs(i+1, j, grid);dfs(i, j+1, grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 ||  j==0 || j==m-1 || i==n-1) {
                    if(grid[i][j]==0) {
                        dfs(i, j, grid);
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==0) {
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
};