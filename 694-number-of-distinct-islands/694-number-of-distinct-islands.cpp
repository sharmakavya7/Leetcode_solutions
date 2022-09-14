class Solution {
public:
    int DR[4] = {-1, 0, +1, 0};
    int DC[4] = {0, +1, 0, -1};
    
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid, vector<pair<int,int>>&temp, int baseR, int baseC) {
        int m = grid.size();
        int n = grid[0].size();
        vis[i][j] = 1;
        temp.push_back({i-baseR, j-baseC});
        
        for(int k =0; k<4; k++) {
            int nrow = DR[k]+i;
            int ncol = DC[k]+j;
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol]&& grid[nrow][ncol]==1) {
                dfs(nrow, ncol, vis, grid, temp, baseR, baseC);
            }
        }
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>vis(m, vector<int>(n,0));
        set<vector<pair<int,int>>>st;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j]&&grid[i][j]==1) {
                    vector<pair<int,int>>temp;
                    dfs(i, j, vis, grid, temp, i, j);
                    st.insert(temp);
                //     vis[i][j]=1;
                }
            }
        }
        return st.size();
    }
};