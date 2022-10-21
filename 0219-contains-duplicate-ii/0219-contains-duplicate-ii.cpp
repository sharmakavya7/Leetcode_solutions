class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i = 0, j = 0;
        unordered_map<int,int>mp;
        int n=nums.size();
        
        while(i < n && j < n) {
            if(mp.count(nums[j])!=0 && mp.size() <= k) {
                return true;
            }
            mp[nums[j]] = j;
            if(mp.size() > k) {
                mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};