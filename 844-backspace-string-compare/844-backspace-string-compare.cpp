class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int k = 0;
        string s1, s2;
        
        for(int i = s.length()-1; i>=0; i--) {
            
            if(s[i] == '#')
                k++;
            
            else if(k == 0) {
                s1.push_back(s[i]);
            } 
            else {
                k--;
            }
        }
        
        k = 0;
        for(int i = t.length()-1; i>=0; i--) {
            
            if(t[i] == '#')
                k++;
            
            else if(k == 0) {
                s2.push_back(t[i]);
            } 
            else {
                k--;
            }
        }
        
        return s1 == s2;
    }
};