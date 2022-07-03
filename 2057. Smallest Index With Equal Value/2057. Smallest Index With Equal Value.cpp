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
    int smallestEqual(vector<int>& nums) {
        for(auto i=0; i<nums.size(); i++) {
            if(nums[i] == i % 10)
                return i;
        }
        return -1;
    }
};