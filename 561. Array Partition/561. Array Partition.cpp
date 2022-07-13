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
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        int sum = 0;
        for(int i=0; i<nums.size(); i+=2) {
            mini = min(nums[i],nums[i+1]);
            sum += mini;
        }
        return sum;
    }
};