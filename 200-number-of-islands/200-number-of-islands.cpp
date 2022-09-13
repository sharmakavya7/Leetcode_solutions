class Solution {
public:
    int DR[4]={1, 0, -1, 0};
    int DC[4]={0, -1, 0, 1};
    
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j) {
        queue<pair<int, int>>q;
        q.push({i, j});
        vis[i][j]=1;
        
        int m = grid.size();
        int n = grid[0].size();
        
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k=0; k<4; k++) {
                int ci=DR[k]+i;  // neightbour row
                int cj=DC[k]+j;  // neighbour row
                
                if(ci >= 0 && ci < m && cj >= 0 && cj < n 
                   &&grid[ci][cj]=='1' && !vis[ci][cj]) {
                    q.push({ci, cj});
                    vis[ci][cj]=1;
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cnt=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]=='1' && !vis[i][j]) {
                    cnt++;
                    bfs(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
};