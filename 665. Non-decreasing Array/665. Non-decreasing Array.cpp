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
    bool checkPossibility(vector<int>& nums) {
        int change = 1;
        int mini = INT_MIN;
        for(int i=0; i<nums.size()-1 && change<=1 ; i++) {
            if(nums[i] <= nums[i + 1]){
                mini = nums[i];
            }
            else {
                if(nums[i + 1] < mini){
                    nums[i+1] = nums[i];
                }
                change--;
            }

        }
        if(change<0) {
            return false;
        }
        return true;
    }
};