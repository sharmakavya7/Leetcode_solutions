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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<vector<int>> maxh;
        
        for (auto p : points) {
            int x = p[0], y = p[1];    // x=points[i][0], y=points[i][1]
            
            maxh.push({x*x + y*y, x, y});
            
            if(maxh.size()>k) {
                maxh.pop();
            }
        }
        vector<vector<int>>dist(k);
        
        for(int i=0; i<k; i++) {
            vector<int> top = maxh.top();
            maxh.pop();
            dist[i] = {top[1], top[2]};  // pq.second and third
        }
        return dist;
    }
};