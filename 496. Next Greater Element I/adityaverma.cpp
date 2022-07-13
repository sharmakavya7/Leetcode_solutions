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
        
        int n = nums2.size();
        stack<int>st;
        vector<int>ans;
        
        for(int i=n-1; i>=0; i--) {
            if(st.empty()) {
                ans.push_back(-1);
            }
            if(!st.empty() && st.top()>nums2[i]) {
                ans.push_back(nums2[i]);
            }
            if(!st.empty() && st.top()<=nums2[i]) {
                while(!st.empty() && st.top()<=nums2[i]) {
                    st.pop();
                    // if(st.top()>nums2[i]) break;
                }
                if(st.empty()) {
                    ans.push_back(-1);
                }
                else ans.push_back(nums2[i]);
            }
            st.push(nums2[i]);
        }
        return ans;
    }
};