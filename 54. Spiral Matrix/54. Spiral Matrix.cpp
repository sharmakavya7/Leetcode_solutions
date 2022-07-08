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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n = matrix.size();        // col
        int m = matrix[0].size();     // row
        int top = 0;
        int down = n-1;
        int right = m-1;
        int left = 0;
        int dir = 0;
        vector<int>ans;
        
        while(left<=right && top<=down) {
            
            if(dir==0) {
                for(int i=left; i<=right; i++) {
                    ans.push_back(matrix[top][i]);
                }
                dir=1;
                top++;
            }
            else if(dir==1) {
                for(int i=top; i<=down; i++) {
                    ans.push_back(matrix[i][right]);
                }
                dir = 2;
                right--;
            }
            else if(dir==2) {
                for(int i=right; i>=left; i--) {
                    ans.push_back(matrix[down][i]);
                }
                dir = 3;
                down--;
            }
            else if(dir==3) {
                for(int i=down; i>=top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                dir = 0;
                left++;
            }
        }
        return ans;
    }
};