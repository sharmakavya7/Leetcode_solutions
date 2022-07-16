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
    int mod = 1e9 + 7;
    int helper(int m, int n, int maxMoves, int i, int j, int cnt) {
        if(maxMoves==0) {
            return i>=m || j>=n || i<0 || j<0;
        }
        if(i>=m || j>=n || i<0 || j<0) {
            return 1;
        }
        // down
        return (helper (m, n, maxMoves-1, i+1, j, cnt) + 
        // up
        helper(m, n, maxMoves-1, i-1, j, cnt) +
        // left
        helper(m, n, maxMoves-1, i, j-1, cnt) +
        // right
        helper(m, n, maxMoves-1, i, j+1, cnt))% mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        return helper(m, n, maxMove, startRow, startColumn, 0);
    }
};