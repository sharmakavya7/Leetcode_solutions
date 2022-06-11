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

    int minOperations(vector<int>& nums, int x) {
        int completeSum = 0;
        for(int i:nums) {
            completeSum+=i;
        }
        // sum of remaining array which is the desired subarray sum
        completeSum-=x;
        // sum of array is equal to X . means we'll have to remove all elements
        if(completeSum==0) {
            return nums.size();
        }
        int i=0;
        int curSum = 0;
        int maxiLen=0;
        
        // while(j<nums.size()) {
        for(int j=0; j<nums.size(); j++) {
            
            curSum += nums[j];   // window ka sum
            
            // if sum of current subaaray is greater than desired sum
            while(i<nums.size() && completeSum<curSum) {
                
                curSum -= nums[i++];
                //i++;
            }
            // if sum of current subarray is equal to desired sum then update length
            if(completeSum==curSum) {
                maxiLen = max(maxiLen, j-i+1); // max of window size and prev subarray length
            }
        }
        if(!maxiLen) {
            return -1;
        }
        return nums.size()-maxiLen;
        
    }
};

// RECURSIVE SOLUTION GIVES TLE
//     int helper(vector<int>& nums, int i, int j,  int x) {
        
//         if(x==0) {
//             return 0;
//         }
//         if(x<0) {
//             return INT_MAX-1;
//         }
//         if(i>j) {
//             return INT_MAX-1;
//         }
//         int left = 1 + helper(nums, i+1, j, x - nums[i]);
//         int right = 1 + helper(nums, i, j-1, x - nums[j]);
        
//         return min({left, right, INT_MAX-1});
//     }
//     int minOperations(vector<int>& nums, int x) {
//         // int cnt=0;
//         int i=0;
//         int j=nums.size()-1;
//         auto ans = helper(nums, i, j, x);
//         if(ans == INT_MAX-1) {
//             return -1;
//         }
//         return ans;
//     }