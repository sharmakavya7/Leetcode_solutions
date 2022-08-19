class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(auto it:nums)
            mp[it]++;
        
        for(auto it:nums) {
            if(mp[it] == 0)
                continue;
            
            int freq = mp[it] , curr = it , count = 0;
            
            while(mp.count(curr) && mp[curr] >= freq) {
                freq = fmax(freq,mp[curr]);
                mp[curr]--;
                count++;
                curr++;
            }
            if(count < 3)
                return false;
        }
        return true;
    }
};