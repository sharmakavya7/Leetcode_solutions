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
    bool isAnagram(string s, string t) {
        unordered_map<int, int>mp;
        if(t.size()<s.size()) {
            return false;
        }
        for(auto c:t) {
            mp[c]++;
        }
        
        int count = mp.size();
        
        for(int i=0; i<s.size(); i++) {
            if(mp.find(s[i])!=mp.end()) {
                mp[s[i]]--;
                if(mp[s[i]]==0) {
                    count--;
                }
            }
        }
        if(count == 0) {
            return true;
        }
        return false;
    }
};