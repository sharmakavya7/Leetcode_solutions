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
        int mx = 0;
        int zero=0;
        int i=0, j=0;
        while(j<nums.size()) {
            if(nums[j]==0) {
                zero++;
            }
            while(zero>1) {
                if(nums[i]==0) {
                    zero--;
                }
                i++;
            }
            mx = max(mx,j-i+1);
            j++;
            
        }
        return mx;
    }
};