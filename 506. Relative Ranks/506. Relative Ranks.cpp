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
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string>ans(score.size());
        priority_queue<pair<int,int>>maxh;
        for(int i=0; i<score.size(); i++) {
            maxh.push({score[i],i});
        }
        int flag = 0;
        while(!maxh.empty()) {
            auto top = maxh.top();
            
            if(flag==0) {
                ans[top.second] = "Gold Medal";
            }
            else if(flag==1) {
                ans[top.second] = "Silver Medal";
            }
            else if(flag==2) {
                ans[top.second] = "Bronze Medal";
            }
            else ans[top.second] = to_string(flag+1);
            
            flag++;
            maxh.pop();
        }
        return ans;
    }
};