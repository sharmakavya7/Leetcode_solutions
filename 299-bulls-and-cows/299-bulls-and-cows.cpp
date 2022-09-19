class Solution {
public:
    string getHint(string s, string g) {
        unordered_map<char, int>secret;
        int bulls=0; // correct position
        int cows=0;  // wrong position
        
        for(int i=0; i<g.size(); i++) {
            
            if(s[i]==g[i]) {
                
                bulls++;
                continue;
            }
            secret[s[i]]++;
        }
        
        for(int i=0; i<g.size(); i++) {
            
            if(s[i]!=g[i] && secret[g[i]]) {
                cows++;
                secret[g[i]]--;
                // cout<<" cows: "<<cows;
            }
        }
        string ans = to_string(bulls) + 'A' + to_string(cows) + 'B';
        return ans;
    }
};