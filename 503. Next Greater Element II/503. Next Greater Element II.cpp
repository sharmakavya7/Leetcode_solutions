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
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>ans;
        for(int i=nums.size()-1;i>=0;i--) {
			st.push(nums[i]);
		}

        for(int i=n-1; i>=0; i--) {
            
            while(!st.empty() && st.top()<=nums[i]) {
                st.pop();
            }
            if(st.empty()) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(st.top());
            }
            
            st.push(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};