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
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 0;
        int end = n;
        int temp = 0;
        while(start<end) {
            int mid = start + (end - start)/2;
            // int temp = 0;
            if(!isBadVersion(mid)) {
                // temp = mid;
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        return start;
    }
};