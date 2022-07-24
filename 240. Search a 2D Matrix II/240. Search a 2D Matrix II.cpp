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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(m==1 && n==1) {
            return matrix[0][0]==target;
        }
        int i = 0;
        int j = n-1;
        // for(i=0; i<m && j<n; i++) {
        while(i<m && j>=0) {
            if(matrix[i][j] == target) {
                return true;
            }
            else if(matrix[i][j]>target) {
                j--;
            }
            else if(matrix[i][j]<target) {
                i++;
            }
            // else break;
            else return false;
        }
        return false;
    }
};