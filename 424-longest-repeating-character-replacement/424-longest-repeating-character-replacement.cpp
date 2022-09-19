class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int> count(26);
        int i=0, j=0, maxi=0;
        int temp = k;
        
        while(j<s.size()) {
            count[s[j]-'A']++;
            maxi = max(maxi, count[s[j]-'A']);
            
            if((j-i+1) - maxi > k) {
                count[s[i]-'A']--;
                i++;
            }
            j++;
        }
        return s.size()-i;
    }
};