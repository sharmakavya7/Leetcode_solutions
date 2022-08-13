class Solution {
public:
    
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
    
        for(int i=0; i<nums.size(); ++i){
            int mini = nums[i], maxi = nums[i];
            for(int j=i; j<nums.size(); ++j){
                mini = min(nums[j], mini);
                maxi = max(nums[j], maxi);
                ans += (maxi - mini);
            }
        }

        return ans;
    }
};