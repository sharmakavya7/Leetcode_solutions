class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        int n = s.size();
        if(n==1) {
            return 1;
        }
        unordered_map<char, int>mp;
        
        for(int i=0; i<s.size(); i++) {
            mp[s[i]]++;
            if(mp[s[i]]%2==0) {
                res += mp[s[i]];
                mp[s[i]] = 0;
            }
            
        }
        for(auto x: mp) {
            if(x.second==1) {
              res++;
              break;
            }  
        }
        return res;
    }
};