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
    int helper(vector<int>& nums, int k, int i) {
        if(i >= size(nums) - 1) 
            return nums.back();
        int score = INT_MIN;
        for(int j = 1; j <= k; j++) 
            score = max(score, nums[i] + helper(nums, k, i + j));
        return score;
    }
    
    int maxResult(vector<int>& nums, int k) {
        return helper(nums, k, 0);
    }
};