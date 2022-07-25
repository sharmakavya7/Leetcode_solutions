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
    int numSplits(string s) {
        int cnt=0;
        unordered_map<char,int>mp;
        int k=0;
        for(auto c:s) {
            k = mp[c]++;
        }
        if(mp.size()==1) {
            return k;
        }
        unordered_map<char,int>mp1;
        int i=0;
        int j=0;
        while(j<s.size()) {
            mp[s[j]]--;
            if(mp[s[j]]==0) {
                mp.erase(s[j]);
            }
            j++;
            mp1[s[i]]++;
            if(mp.size()==mp1.size()) {
                cnt++;
            }
            i++;
        }
        return cnt;
    }
};