class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>temp;
        int i=0;
        for(i=0; i<nums.size(); i++) {
            temp.push_back(nums[i]);
        }
        for(i=0; i<nums.size(); i++) {
            temp.push_back(nums[i]);
        }
        stack<int>st;
        vector<int>ans;
        for(int i=temp.size()-1; i>=0; i--) {
            while(!st.empty() && st.top()<=temp[i]) {
                st.pop();
            }
            if(st.empty()) {
                ans.push_back(-1);
            }
            if(!st.empty() && st.top()>temp[i]) {
                ans.push_back(st.top());
            }
            st.push(temp[i]);
        }
        reverse(ans.begin(),ans.end());
        vector<int> res;
        for(int i=0; i<ans.size()/2; i++) {
            res.push_back(ans[i]);
        }
        return res;
    }
};