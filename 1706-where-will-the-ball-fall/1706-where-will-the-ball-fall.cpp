class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, int m, int n) {

        if(i == m) 
            return j;
        
        // ball can move right if cur & next board are towards right
        if(grid[i][j] == 1 && j + 1 < n && grid[i][j + 1] == 1){
            return dfs(i + 1, j + 1, grid, m, n);
        }
        
        // ball can move left if cur& prev board sre towards left
        if(grid[i][j] == -1 && j - 1 >= 0 && grid[i][j - 1] == -1) {
            return dfs(i + 1, j - 1, grid, m, n);
        }
        // can't move => trapped
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            ans[i] = dfs(0, i, grid, m, n);
            // ans.push_back(t);
            // cout << ans[i] <<" ";
        }
        
        return ans;
    }
};