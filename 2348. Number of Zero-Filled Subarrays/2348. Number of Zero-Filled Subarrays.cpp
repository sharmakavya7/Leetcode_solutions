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
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt=0;
        int i=0, j=0;
        while(j<nums.size()) {
            
            while(j<nums.size() && nums[j]!=0 ) {
                // i++;
                j++;
                i = j;
            }
            while(j<nums.size()&& nums[j]==0) {
                j++;
                // cnt0+=(j-i+1);
            }
            long long n = j-i;
            cnt+=(n*(n+1)/2);
        }
        return cnt;

    }
};