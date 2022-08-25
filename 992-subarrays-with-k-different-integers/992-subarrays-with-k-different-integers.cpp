class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int cnt = 0;          // store subarray count
        
        while(j<nums.size()) {

            mp[nums[j]] = j;// store the last apperance index of a character
            
            while(mp.size() > k) {

                if (mp[nums[i]] == i) { // A[left] can be removed from the map if left is the last apperance
                    mp.erase(nums[i]);
                }
                i++;
            }
            if(mp.size()==k) {
                int mini = j;
                for(auto c:mp) {
                    mini = min(mini, c.second);
                }
                cnt += mini - i + 1;    // Any window start between [left, mini] and end with right is a qualified answer.
                // cnt++;
            }
            j++;
        }
        return cnt;
    }
};