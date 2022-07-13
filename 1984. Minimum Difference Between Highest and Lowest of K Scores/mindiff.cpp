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
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        if(n==1 || n==0) {
            return 0;
        }
        if(n==2 && k==2) {
            return nums[1]-nums[0];
        }
        
        int mini = nums[k-1] - nums[0];
        for(int i=k; i<n; i++) {
            mini = min(mini, nums[i]-nums[i-k+1]);
        }
        return mini;
    }
};