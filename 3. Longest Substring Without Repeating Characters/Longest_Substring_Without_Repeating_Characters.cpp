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
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mp;
        int i=0; int j=0;
        int maxi=0;
        while(j<s.size()) {
            mp[s[j]]++;
            
            if(mp.size()==j-i+1) {    // all unique chal rhe hai abhi tak isliye map size == window ka size
                maxi = max(maxi, j-i+1);
                j++;
            }
            else if(mp.size()<j-i+1) {  // duplicate ele aa gya so mp.size < window size
                while(mp.size()<j-i+1) {
                    mp[s[i]]--;
                    if(mp[s[i]]==0) {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};