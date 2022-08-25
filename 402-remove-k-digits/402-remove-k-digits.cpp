class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;

        //storing
        int n = num.size(); 
        for(int i=0; i<num.size(); i++) {
            while(k>0 && !s.empty() && s.top()>num[i]) {  // meaning, there is a dip, so remove the maxima which is the top of stack
                s.pop();
                k--;
            }
            if(!s.empty() || num[i]!= '0') {   
                s.push(num[i]);
            }
            
        }
        //removing the largest value from the top
        while(!s.empty() && k--) // this is to make sure we fulfil the deletion condition
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