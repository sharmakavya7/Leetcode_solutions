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
    bool helper(string s, string t) {
        unordered_map<char,char>mp;
        for(int i=0; i<s.size(); i++) {
            if(mp.find(s[i])!=mp.end()) {
                if(mp[s[i]]!=t[i])
                    return false;
            }
            else 
                mp[s[i]]=t[i];
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return helper(s, t) && helper(t, s);
    }
};