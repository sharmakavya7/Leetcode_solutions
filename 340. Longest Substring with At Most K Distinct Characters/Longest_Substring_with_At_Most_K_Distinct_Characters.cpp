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
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // ADITYA VERMA
        unordered_map<int,int>mp;
        int i=0; int j=0;
        int maxi=0;
        while(j<s.size()) {
            mp[s[j]]++;     
            if(mp.size()>k) {  
                while(mp.size()>k) {
                    mp[s[i]]--;
                    if(mp[s[i]]==0) {
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};