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
    int pivotIndex(vector<int>& nums) {
        // Prefix sum
        int rightSum = accumulate(nums.begin(),nums.end(),0);
        int left = 0;
        for(int i=0; i<nums.size(); i++) {
            rightSum -= nums[i];
            if(rightSum==left) {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};