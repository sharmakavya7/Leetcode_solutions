class Solution {
public:
    int dx[4] = { -1, 0, 0, 1 };
    int dy[4] = { 0, -1, 1, 0 };
    // BFS
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int m = grid.size(), n = grid[0].size(), steps = 0;
        vector<vector<int>> remains(m, vector<int>(n, -1e9));
        
        // queue {x, y, k} ,x, y->coordinate and r->number of obstacles you can remove
        queue<array<int, 3>> q;
        q.push({0, 0, k});
        remains[0][0] = k;
        
        while (!q.empty()) {
            
            for (int it = q.size(); it > 0; it--) {
                
                auto cur = q.front(); q.pop();
                
                // lower right corner (m - 1, n - 1) return the minimum number of steps
                if (cur[0] == m - 1 && cur[1] == n - 1) 
                    return steps;
                
                // see all 4 directions
                for (int i = 0; i < 4; i++) {
                    int nrow = cur[0] + dx[i];
                    int ncol = cur[1] + dy[i];

                    if(nrow < 0 || nrow >= m || ncol < 0 || ncol >= n) continue;
                    // remove obstacle:
                    // 1. remain is greater or equal to 0
                    // 2. target remaining k must be less than current remaining k
                    int remain = cur[2] - grid[nrow][ncol];
                    
                    if(remain >= 0 && remains[nrow][ncol] < remain) {
                        q.push({nrow, ncol, remain});
                        remains[nrow][ncol] = remain;
                    }
                }
            }
            steps += 1;
        }
        return -1;
    }
};