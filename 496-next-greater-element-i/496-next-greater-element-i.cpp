class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>st;
        int i=0;
        // while(i<nums2.size()) {
        for(int i=nums2.size()-1; i>=0; i--) {
            
            while(!st.empty() && st.top()<=nums2[i]) {
                st.pop();
            }
            if( !st.empty() && st.top()>nums2[i]) {
                // ans.push_back(nums[i]);
                mp[nums2[i]] = st.top();
            }
            if(st.empty()) {
                // ans.push_back(-1);
                mp[nums2[i]] = -1;
            }
        
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(auto i:nums1) {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};