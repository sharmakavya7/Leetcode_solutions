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
    int countBinarySubstrings(string s) {
        // prev has prev grp ka count and cur has cur grp ka(ie. 11100 prev=3, cur=2)
        int prev=0, cur=1;
        int cnt=0;
        for(int i=1; i<s.size(); i++) {
            //00001110011
            //  0 0 0 0
            //  |     |
            // prev0  cur4           [prev0 => prev=0]
            //  0 0 0 0 1 1 1 
            //        |     |
            //      prev4  cur3
            //   0 0 0 0 1 1 1 0 0 
            //               |   |
            //             prev3 cur2
            //   0 0 0 0 1 1 1 0 0 1 1
            //                   |   |
            //                 prev2 cur2
            if(s[i]!=s[i-1]) {
                cnt+=min(prev,cur);
                prev=cur;
                cur=1;
            }
            else // when we encounter same numbers(say,1) till break point(say, 0 comes) 
                cur++;
        }
        // for final window
        cnt+=min(prev, cur);
        return cnt;
    }
};