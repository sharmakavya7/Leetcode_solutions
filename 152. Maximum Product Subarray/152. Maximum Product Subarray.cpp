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
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int maxi=ans;
        int mini=ans;
        
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]<0) {
                swap(maxi,mini);
            }
            maxi = max(nums[i], nums[i]*maxi);
            mini = min(nums[i], nums[i]*mini);
            ans=max(ans,maxi);
        }
        return ans;
    }
};