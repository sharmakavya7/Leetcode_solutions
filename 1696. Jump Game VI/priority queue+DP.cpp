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

    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>>maxh;
        vector<int>maxScore(n);
        
        for(int i=0;i<nums.size();i++) {

            while(!maxh.empty() && maxh.top().second < i-k) {
                maxh.pop();
            }
            if(!maxh.empty()) 
                maxScore[i] = nums[i] + maxh.top().first;
            else
                maxScore[i] = nums[i];
            
            maxh.push({maxScore[i],i});
        }
        return maxScore[n-1];
    }
};