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
    int minSteps(string s, string t) {
        unordered_map<char,int>mp;
        // unordered_map<char,int>mp2;
        for(auto i:t) {
            mp[i]++;
        }
        int cnt=0;
        // for(auto it=mp.begin(); it!=mp.end(); it++) {
        for(int i=0; i<s.size(); i++) {
            if(mp.find(s[i])==mp.end()) {  // not found t
                cnt++;
            }
            else if(mp.find(s[i])!=mp.end()){  // found in t 
                mp[s[i]]--;
                if(mp[s[i]]==0) {
                    mp.erase(s[i]);
                }
            }
        }
        return cnt;
    }
};