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
    int getSum(int n)
    {
        int sum = 0;
        while (n != 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int ans=-1;
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++) {
            int t = getSum(nums[i]);
            
            if(mp.find(t) == mp.end()) {
                mp[t] = i; 
            }
            else {
                int key = mp[t];
                int val = nums[key];
                int sum = val+nums[i];
                ans = max(ans, sum);
                if(nums[i]>val)
                    mp[t]=i;
            }
        }
        return ans;
    }
};
