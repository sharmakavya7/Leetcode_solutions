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
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums) {
            mp[i]++;
        }
        int cnt=0;
        int lone=0;
        for(auto it=mp.begin(); it!=mp.end(); it++) {
            if(it->second%2==0) {
                cnt+=(it->second/2);
            }
            else {
                if(it->second==1) {
                    lone++;
                }
                else 
                    cnt += ((it->second-1)/2),
                    lone++;
            }
        }
        return {cnt, lone};
    }
};