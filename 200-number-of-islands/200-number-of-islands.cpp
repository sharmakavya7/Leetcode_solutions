class Solution {
public:
    void helper(vector<vector<char>>& grid, int i, int j) {
        if( i>=grid.size() || j>=grid[0].size() || grid[i][j]!='1') {
            return;
        }
        grid[i][j]=0;   // mark water, i.e. visited
        
        helper(grid, i+1, j);
        helper(grid, i-1, j);
        helper(grid, i, j+1);
        helper(grid, i, j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;     // stores the maximum area
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    helper(grid, i, j);
                }
            }
        }
        return ans;
    }
};