#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib> 
#include <string>
#include <map>
#include <climits>
#include <iterator>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <deque>
#include <queue>
#include <stack>

using namespace std;
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