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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,(vector<int>(n,0)));
        int top=0;
        int right=n-1;
        int down=n-1;
        int left=0;
        int dir=0;
        int j=1;
        while(top<=down && right>=left) {

            for(int i=left; i<=right; i++) {
                ans[top][i] = j++;
            }
            top++;

            for(int i=top; i<=down; i++) {
                ans[i][right] = j++;
            }
            right--;

            for(int i=right; i>=left; i--) {
                ans[down][i] = j++;
            }
            down--;

            for(int i=down; i>=top; i--) {
                ans[i][left] = j++;
            }
            left++;

        }
        return ans;
    }
};