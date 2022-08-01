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
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start=0, end=nums.size(); 
        int mid = (start+end)/2;
        while(start<end) {
            mid = (start+end)/2;
            if(mid<nums[mid]) {
                end = mid;
            }
            else start = mid+1;
        }
         return start;
        
    }
};