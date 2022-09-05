class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;   // {nums[i], index}
        
        for(int i=0; i<nums.size(); i++) {
            if(mp.find(target - nums[i]) != mp.end()) {
                return {mp[target - nums[i]], i};    //[target - nums] ek key hai, uska index
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};