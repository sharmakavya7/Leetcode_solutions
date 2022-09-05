class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Prefix sum
        int rightSum = accumulate(nums.begin(),nums.end(),0);
        int left = 0;
        for(int i=0; i<nums.size(); i++) {
            rightSum -= nums[i];
            if(rightSum==left) {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};