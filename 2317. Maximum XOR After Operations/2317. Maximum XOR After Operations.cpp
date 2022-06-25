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
    int maximumXOR(vector<int>& nums) {
        int res = 0;
        for(int i=0; i<nums.size(); i++) {
            res |= nums[i];
        }
        return res;
    }
};