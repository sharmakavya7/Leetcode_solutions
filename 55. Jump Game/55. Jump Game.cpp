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

    bool canJump(vector<int>& nums) {
        int size=nums.size();
        int step=nums[0];
        for(int i=1;i<size;++i){
            step--;
            if(step<0)
               return false;
            if(nums[i]>step)
               step=nums[i];
        }
        return true;
    }
};