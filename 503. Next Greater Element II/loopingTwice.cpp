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
        vector<int>ans(n, -1);
        nums.resize(2*n);
        
        for(int i=n; i<2*n; i++) { //concatenate the same array
            nums[i] = nums[i-n];
        }
        
        for(int i=0; i<2*n; i++) {
            
            while(!st.empty() && nums[i] > nums[st.top()])
            {
				//nums[i] is NGE to the value at st.top()
				
                if(st.top() >= n) //index should not exceed n
                {
                    st.top() = st.top() - n;
                }
                
                ans[st.top()] = nums[i];
                st.pop();
            }
            
            st.push(i);
        }
        return ans;
    }
};