class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) 
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int closest = nums[0]+nums[1]+nums[2];
        // int closest = 0;
        
        for(int i = 0; i<nums.size()-2; i++) {
            
            if(i>0 && nums[i]==nums[i-1]) continue;
            int low = i+1;
            int high = nums.size()-1;

            while(low<high) {
                int sum = nums[i]+nums[low]+nums[high];
                if(sum == target) {
                    return sum;
                }

                if(abs(target - sum) < abs(closest-target)) {
                    closest = sum;
                }
                
                if(sum > target) {
                    high--;
                }
                else low++;
                
                // cout<<i<<" "<<low<<" "<<high<<" ";
            }
        }
        return closest;
    }
};