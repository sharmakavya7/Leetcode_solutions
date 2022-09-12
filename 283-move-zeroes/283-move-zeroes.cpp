class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>ans;
        int cnt=0;  // storing number of zeroes
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) {
                cnt++;
            }
        }
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]!=0) {
                ans.push_back(nums[i]);
            }
        }
        while(cnt) {
            ans.push_back(0);
            cnt--;
        }
        nums.clear();
        copy(ans.begin(), ans.end(), back_inserter(nums)); 
    }
};