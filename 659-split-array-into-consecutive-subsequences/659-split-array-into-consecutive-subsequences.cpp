class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(auto i:nums) {
            mp[i]++;
        }
        
        for(auto i:nums) {
            
            if(mp[i] == 0)
                continue;
            
            int freq = mp[i];
            int curr = i;
            int cnt = 0;
            
            while(mp[curr] >= freq) {
                freq = fmax(freq,mp[curr]);
                mp[curr]--;
                cnt++;
                curr++;
            }
            if(cnt < 3)
                return false;
        }
        return true;
    }
};