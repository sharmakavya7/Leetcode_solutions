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
vector<vector<int>> solve(vector<vector<int>>& intervals, vector<int>& cut) {
    vector<vector<int>>ans;
    int i=0;
    // while(i<intervals.size()) {
    for(int i=0; i<intervals.size(); i++) {
        if(intervals[i][0]<cut[0]) {
            int p = min(intervals[i][1], cut[0]);
            ans.push_back({intervals[i][0],p});
        }
        if(intervals[i][1]>cut[1]) {
            int q = max(intervals[i][0], cut[1]);
            ans.push_back({q,intervals[i][1]});
        }
    }
    return ans;
}