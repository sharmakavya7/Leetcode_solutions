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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int maxi=0;
        for(int i=0; i<nums.size(); i++) {
            // if((i==0 && nums[i+1]==1) || nums[i]==1 && nums[i-1]==1 && nums[i+1]==1) {
            // if(nums[i]==1) {    
            //     maxi = max(maxi,count);
            //     count++;
            // }
            if(nums[i]!=1) {
                count = 0;
            }
            else count++;
            
            maxi = max(maxi,count);
        }
        return maxi;
    }
};