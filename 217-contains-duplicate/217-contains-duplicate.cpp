class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>map;
        if (nums.empty()) {
            return false; 
        }
        for(int i = 0; i<nums.size(); i++) {
            //map[nums[i]]++;
            if(++map[nums[i]] >=2) {
                return true;
            }
        }
        return false;
        // for(auto it = map.begin(); it != map.end(); it++) {
        //     if(it->second >= 2) {
        //         return true;
        //     }
        // }
        //return false;
        // int ans = 0;
        // for(int i = 0; i<nums.size(); i++) {
        //     ans = ans ^ nums[i];
        // }
        // if(ans == 0) {
        //     return false;
        // }
        // else {
        //     return true;
        // }
    }
};