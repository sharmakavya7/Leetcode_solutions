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
    int longestPalindrome(string s) {
        int res = 0;
        int n = s.size();
        if(n==1) {
            return 1;
        }
        unordered_map<char, int>mp;
        for(auto ch:s) {
            mp[ch]++;
        }
        for(auto ch = mp.begin(); ch!=mp.end(); ch++) {
            if(ch->second%2 != 0) {
                res++;
            }
        }
        if(res) {
            return n-res+1;
        }
        return n;
    }
};