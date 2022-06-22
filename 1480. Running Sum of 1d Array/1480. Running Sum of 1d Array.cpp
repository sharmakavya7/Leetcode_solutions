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

#include <vector>
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        long long sum = 0;
        
        for(int i=0; i<nums.capacity(); i++) {
            sum = sum + nums[i];
            nums[i] = sum;
            
        }
        return nums;
    }
};
        /*vector<int> sum = {nums[0]};
        
        if(nums.size() == 0) {
            return {};
        }
        
        for(int i=1; i < nums.capacity(); i++) {
            
            sum.push_back(sum.back() + nums[i]);
        } 
        return sum; */
