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
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>lefty(n,1),righty(n,1);
        
         //traverse left to right and compare cur value with left side value
        for(int i=1; i<n; i++) {
            if(ratings[i]>ratings[i-1]) {
                lefty[i] = lefty[i-1] + 1;
            }
        }
        // traverse right to left and compare curr value with right side value
        for(int i = n-2; i>=0; i--) {
            if(ratings[i]>ratings[i+1]) {
                righty[i] = righty[i+1] + 1;
            }
        }
        int res=0;
        for(int i=0; i<n; i++) {
            res += max(lefty[i], righty[i]); 
        }
        // int res = accumulate(ans.begin(), ans.end(),1);
        return res;
    }
};