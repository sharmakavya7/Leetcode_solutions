class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        int cntfresh=0;
        // traverse and get all rotten oranges
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==2) {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1) {
                    cntfresh++;
                }
            }
        }
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        // up, right, down, left
        int time = 0;
        int cnt=0;
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);
            // visit all the neighbouring guys
            for(int i=0; i<4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n 
                    && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2) {
                        q.push({{nrow,ncol},t + 1});
                        vis[nrow][ncol]=2;
                        cnt++;
                }
            }
        }
        // bool flag = false;
        if(cnt!=cntfresh) {
            return -1;
        }
        return time;
    }
};