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
    // NOTE: PASS THE VECTOR BY REFERENCE!!!!!! else return nhi hoga!!!
    vector<string>ans;
    void helper(int n, vector<string>&ans, string s, int khula, int band) {
        if(s.size()==n*2) {
            // cout<<" s: "<< s;
            ans.push_back(s);
            // for(auto i:ans)
            //     cout<<" ans: "<<i;
            return;
        }
        // cout<<" k: "<< khula;
        // cout<<" b: "<< band;
        // insert open bracket
        if(khula<n)     // khula tab tak fill hoga jab tak n is reached
            helper(n, ans, s+'(', khula+1, band);
        // insert closing bracket
        if(band<khula)  // band tabtak fill hoga jabtak khule ka count is reached
            helper(n, ans, s+')', khula, band+1);
    }
    vector<string> generateParenthesis(int n) {
        
        helper(n, ans, "", 0, 0);
        return ans;
    }
};