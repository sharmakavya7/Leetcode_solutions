class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0, sum=0;
        while(i<nums.size()) {
            sum+=(min(nums[i],nums[i+1]));
            i+=2;
        }
        return sum;
    }
};