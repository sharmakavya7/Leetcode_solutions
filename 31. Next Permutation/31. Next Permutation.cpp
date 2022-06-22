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
    void nextPermutation(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int n = nums.size();
        int i, j;
        // next_permutation(nums.begin(),nums.end());
        for(i=n-2; i>=0; i--) {
            if(nums[i]<nums[i+1]) {
                break;
            }
        }
        if(i<0) {
            reverse(nums.begin(), nums.end());
        }

        else {
            for( j = n-1; j>i; j--) {
                if(nums[j]>nums[i]) {
                    break;
                }
            }
        
            swap(nums[i], nums[j]);
            reverse(nums.begin()+i+1, nums.end());
        }
    }
};