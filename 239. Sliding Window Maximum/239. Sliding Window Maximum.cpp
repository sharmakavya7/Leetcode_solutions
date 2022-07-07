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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0, j=0;
        vector<int>ans;
        priority_queue<pair<int,int>> maxh;
        while(j<nums.size()){
              maxh.push({nums[j],j});
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                while(!maxh.empty() && maxh.top().second<i){
                    maxh.pop();
                }
                j++;i++;
                ans.push_back(maxh.top().first);
            }           
        }
        return ans;
    }
};