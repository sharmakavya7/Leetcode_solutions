class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int right = 1;
        vector<int>ans(nums.size(),1);       // left product so far at ith index
        for(int i=1; i<nums.size(); i++) {
            ans[i] = ans[i-1] * nums[i-1];   // store the left product in the array
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        for(int i=nums.size()-1; i>=0; i--) {
            ans[i] *= right;
            right *= nums[i];
            // cout<<right<<" ";
        }
        return ans;
    }
};