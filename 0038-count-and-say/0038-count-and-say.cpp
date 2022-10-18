class Solution {
public:
    string countAndSay(int n) {
        if(n==1) {
            return "1";
        }
        if(n==2) {
            return "11";
        }
        string s="11";
        // string s1 ="";
        for(int i=3; i<=n; i++) {
            string s1 ="";
            s+='&';
            int c=1;
            for(int j=1; j<s.size(); j++) {
                if(s[j]!=s[j-1]) {
                    s1+=to_string(c);
                    s1+=s[j-1];
                    c=1;
                }
                else c++;
            }
            s = s1;
        }
        return s;
    }
};