class Solution {
private:
    
    int robi(vector<int>& nums) {
        // space optimization
        int prev = nums[0], prev2 = 0, curi = 0;
        int ans = 0;
        for(int i = 1; i<nums.size(); i++) {
            int steal = nums[i] + prev2;
            int noSteal = 0 + prev;
            curi = max(steal, noSteal);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
    
public:
    int rob(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
//         if(nums.size()==2) return max(nums[0], nums[1]);
        
        vector<int> apart_from_one(nums.begin() + 1, nums.end());
        vector<int> apart_from_last(nums.begin(), nums.end()-1);
        
        return max(robi(apart_from_one), robi(apart_from_last ));

    }
};