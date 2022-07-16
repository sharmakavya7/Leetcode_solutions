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
    int helper(int n) {   // o(n)
        int level = 1;
        for (long sum = 0; sum <= n; level++) 
            sum += level;
        return max(level - 2, 0);    
    }
    
    int arrangeCoins(int n) {
        return helper(n);
    }
};