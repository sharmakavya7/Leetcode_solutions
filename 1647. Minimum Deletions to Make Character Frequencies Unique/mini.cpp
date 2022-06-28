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
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        for(auto ch:s) {
            mp[ch]++;
        }
        int deletion = 0;
        
        unordered_set<int>included;
        for(auto [k,v]:mp) {
            while(included.find(v)!=included.end()) {
                deletion++;
                v--;
            }
            if(v>0) {
                included.insert(v);
            }
        }
        return deletion;
    }
};

// TC: 
// SC: O(n)+O(n)
