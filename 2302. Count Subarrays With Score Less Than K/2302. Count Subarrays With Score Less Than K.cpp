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
    long long countSubarrays(vector<int>& nums, long long k) {
        // unordered_map<int,int>mp;
        int i=0, j=0;
        long long cnt=0;
        long long sum=0;
        int n = nums.size();
        while(j<nums.size())
        {
            sum+=nums[j];
            // int score = sum*n;
            while(sum*(j-i+1)>=k) {
                sum-=nums[i];
                i++;
            } 
            // if(j-i+1 < k) {
            //     cnt++;
            // }
            cnt += j-i+1;
            j++;
        }
        return cnt;
    }
};