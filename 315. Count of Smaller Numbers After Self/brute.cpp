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
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>ans;
        // int cnt=0;
        for(int i=0; i<nums.size(); i++) {
            int cnt=0;
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[j]<nums[i]) {
                    cnt++;
                }
            } 
            ans.push_back(cnt);
        }
        return ans;
    }
};