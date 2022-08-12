class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        //int i = 0;
        //while(!s.empty())
        //storing
        int n = num.size(); 
        for(char c : num) {
            while(k>0 && !s.empty() && s.top()>c) {
                s.pop();
                k--;
            }
            if(!s.empty() || c!= '0') {   
                s.push(c);
            }
            
        }
        //removing the largest value from the top
        while(!s.empty() && k--) 
            s.pop();
        
        if(s.empty()) 
            return "0";
        
        // stack ko khali krke string num me kaise daalte h?
        while(!s.empty()) {
            num[n-1] = s.top();
            s.pop();
            n = n-1;
        }
        
        return num.substr(n);
    }
};