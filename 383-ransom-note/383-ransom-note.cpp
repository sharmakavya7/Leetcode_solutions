class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.size()<ransomNote.size()) {
            return 0;
        }
        int freq[26] = {0};
        for(auto i=0; i<magazine.size();i++) {
            // freq[i] = magazine[i] + 'a';
            freq[magazine[i] - 'a']++;
        }
        for(auto i=0; i<ransomNote.size(); i++) {
            freq[ransomNote[i] - 'a']--;
        }
        for(int i=0; i<26; i++) {
            if(freq[i]<0){
                return false;
            }
        }
        return true;
        // unordered_map<char,int>mp1;
        // unordered_map<char,int>mp2;
        // for(auto c:ransomNote) {
        //     mp1[c]++;
        // }
        // for(auto c:magazine) {
        //     mp2[c]++;
        // }
        // for(auto i:mp1) {
        //     if(i.first!=)
        // }
    }
};