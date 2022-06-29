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
    int minMoves(vector<int>& nums) {
        int mini = *min_element(nums.begin(),nums.end());
        int sum = 0;
        for(auto i:nums) {
            sum+=(i-mini);
        }
        return sum;
    }
};