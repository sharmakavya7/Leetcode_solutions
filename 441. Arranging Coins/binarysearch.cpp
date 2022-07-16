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
    int binarySearch(int n) {    // logn
        
        long low = 1, high = n;
        
        while (low < high) {
            
            long mid = low + (high - low + 1) / 2;
            
            if ((mid + 1) * mid / 2 <= n) 
                low = mid;
            
            else 
                high = mid - 1;
        }
        return high;
    }
    
    int arrangeCoins(int n) {
        return binarySearch(n);
    }
};