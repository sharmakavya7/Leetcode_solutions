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
    int firstMissingPositive(vector<int>& nums) {
        
        for(int i=0; i<nums.size();i++) {
            // int temp = nums[i];
            while(nums[i]>0 && nums[i]<=nums.size() && nums[i]!=nums[nums[i]-1]) {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]!=i+1) {
                return i+1;
            }
        }
        return nums.size()+1;
    }
};