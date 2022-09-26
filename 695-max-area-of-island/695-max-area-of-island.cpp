class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1) {
            return 0;
        }
        grid[i][j]=0;   // mark water, i.e. visited

        return 1 + helper(grid, i+1, j) + helper(grid, i-1, j) + helper(grid, i, j+1)+ helper(grid, i, j-1);
        // cout<<res<<endl;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;     // stores the maximum area
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    ans = max(ans, helper(grid, i, j));
                }
            }
        }
        return ans;
    }
};

// int DR[4]={1, 0, -1, 0};
//     int DC[4]={0, -1, 0, 1};

//     int area=0;
//     void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j) {
//         int n = grid.size();
//         int m = grid[0].size();
        
//         grid[i][j]=0;   // mark water, i.e. visited
        
//         for(int k=0; k<4; k++) {
//             int nrow = DR[k]+i;
//             int ncol = DC[k]+j;
//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]) {
//                 area+=1;
//                 dfs(grid, vis, nrow, ncol);
//             }
//         }
//     }
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> vis(m, vector<int>(n,0));
//         int ans = 0;     // stores the maximum area
        
//         for(int i = 0; i < grid.size(); i++) {
//             for(int j = 0; j < grid[0].size(); j++) {
//                 if(grid[i][j] == 1 && !vis[i][j]) {
//                     ans = 1;
//                     dfs(grid, vis, i, j);
//                 }
//                 ans = max(ans, area);
//             }
//         }
//         return ans;
//     }