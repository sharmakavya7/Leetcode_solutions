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
    bool checkXMatrix(vector<vector<int>>& grid) {
        bool flag = false;
        int n = grid.size();
        if(grid[0][0]==0 || grid[n-1][n-1]==0 || grid[0][n-1]==0 || grid[n-1][0]==0) {
            return false;
        }
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {            // All the elements in the diagonals of the matrix are non-zero : true
                                                            // All other elements are 0: true
                if(grid[i][j]==0){
                    if(i!=j || i+j!=grid.size()-1) {     // not diagonal
                        flag = true;
                    }
                    else                     // diagonal
                        return false;
                }
                else {  // non zero
                    if(i==j || i+j==grid.size()-1) {     // diagonal
                        flag = true;
                    }
                    else                    // not diagonal
                        return false;
                }
            }
        }
        return flag;
    }
};