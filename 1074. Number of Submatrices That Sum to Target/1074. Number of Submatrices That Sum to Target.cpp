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
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // For each row, calculate the prefix sum.
        for(int i=0; i<m; i++) {
            for(int j=1; j<n; j++) {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        int res=0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                for(int k = 0; k < m; k++){
                    int sum = 0;
                    for(int l = k; l < m; l++){
                        sum += matrix[l][j] - (i ? matrix[l][i - 1] : 0);
                        if(sum == target) res++;
                    }
			    }
            }
        }
        return res;
    }
};