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
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>maxh;
        int n = matrix.size();
        vector<int>nums(n*n,0);
        for(int i=0; i<n; i++) {   // converting 2D array to 1D array
            for(int j=0; j<n; j++) {
                nums[i*n+j] = matrix[i][j];
            }
        }
        // for(auto i:nums) {
        for(int i=0; i<nums.size(); i++) {
            maxh.push(nums[i]);
            if(maxh.size()>k) {
                maxh.pop();
            }
        }
        return maxh.top();
    }
};