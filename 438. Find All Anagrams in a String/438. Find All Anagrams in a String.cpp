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
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>mp;
        int k = p.size();
        for(int i=0; i<k; i++) {
            mp[p[i]]++;           //key a-1, b-1, c-1
        }
        int count = mp.size();     //stores no of distinct char in map, mtlb map.size()
        
        vector<int> ans;
        int i=0, j=0;
        
        while(j<s.size()) {
            
            if(mp.find(s[j]) != mp.end()) {  // check in map if nums[j] exist
                mp[s[j]]--;                  // if yes, reduce its freq
                
                if(mp[s[j]]==0) {            // 
                    count--;
                }  
            }
            if((j-i+1) < k) {
                j++;
            }
            
            else if((j-i+1) == k) {
                
                if(count==0) {
                    ans.push_back(i);
                }
                
                if(mp.find(s[i])!=mp.end()) {
                    mp[s[i]]++;
                    
                    if(mp[s[i]]==1) {
                        count++;
                    }
                }
                i++;
                j++;
                
            }
        }
        return ans;
    }
};