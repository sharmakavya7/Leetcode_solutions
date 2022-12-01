class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size(), first = 0, sec = 0;
        
        for(int i=0; i<n/2; i++) {
            s[i] = tolower(s[i]);
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                first++;
            }
        }
        for(int i=n/2; i<n; i++) {
            s[i] = tolower(s[i]);
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                sec++;
            }
        }
        return (first == sec);
    }
};