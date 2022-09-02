class Solution {
public:
    long long result = 0;
    
    bool isPalin(string& s){
        int i = 0;
        int j = s.length() - 1;
 
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    // 3 choices:
    // include that char in first string
    // include that char in second string
    // exclude that char from both strings
    
    void helper(int i, string& s, string&s1, string&s2) {
        if(i==s.size()) {
            if(isPalin(s1)&&isPalin(s2)) {
                long long val =(int) s1.size() * s2.size();
                result = max(result, val);
            }
            return;
        }
        // 1. pick s[i] for s1 but don't pick s[i] for s2 (because they should be disjoint)
        s1.push_back(s[i]);
        helper(i+1, s, s1, s2);
        s1.pop_back();
        
        // 2. pick s[i] for s2 but don't pick s[i] for s1 (because they should be disjoint)
        s2.push_back(s[i]);
        helper(i+1, s, s1, s2);
        s2.pop_back();
        
        // don't pick s[i] at all - explore this path and find the result then backtrack
        helper(i+1, s, s1, s2);
    }
    
    int maxProduct(string s) {
        string s1="", s2="";
        helper(0, s, s1, s2);
        return result;
    }
};