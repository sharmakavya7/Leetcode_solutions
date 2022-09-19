class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int>s1, s2;
        string a;
        string b;

        for(int i=0; i<s.size(); i++) {

            if(s[i]=='#'&& !s1.empty()) {
                s1.pop();
            }
            else if(s[i] != '#')
                s1.push(s[i]);
        }

        for(int i=0; i<t.size(); i++) {

            if(t[i]=='#'&& !s2.empty()) {
                s2.pop();
            }
           else if(t[i] != '#')
                s2.push(t[i]);
        }
        
         while(!s1.empty()){
                 
                 a.push_back(s1.top());
                 s1.pop();
                 
         }
            
         while(!s2.empty()){
                 
                 b.push_back(s2.top());
                 s2.pop();
                 
         }
        return a == b;   
    }
};