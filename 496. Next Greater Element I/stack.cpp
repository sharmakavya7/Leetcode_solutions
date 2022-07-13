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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>ans;
        unordered_map<int,int>mp;
        
        for(int i = nums2.size()-1; i>=0; i--) {         
            
            while(!st.empty() && st.top()<nums2[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                // ans.push_back(-1);
                mp[nums2[i]] = -1;
                // j++;
            }
            
            else {
                // ans.push_back(st.top());
                mp[nums2[i]] = st.top();
                // j++;
            }
            st.push(nums2[i]);
        }
        
        for(auto x : nums1) {
            ans.push_back(mp[x]);
        }
    return ans;
    }
};
