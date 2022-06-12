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
    int maximumUniqueSubarray(vector<int>& nums) {
        // SLIDING WINDOW
        unordered_map<int,int>mp;
        int i=0, j=0, sum=0, maxi=0;
        while(j<nums.size()) {
            // sum+=nums[j];
            mp[nums[j]]++;
            
            while(mp.size()<j-i+1) {
                mp[nums[i]]--;
                sum-=nums[i];
                if(mp[nums[i]]==0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            sum+=nums[j];
            maxi = max(maxi, sum);
            j++;
        }
        return maxi;
    }
};