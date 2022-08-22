class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;         // will store the indices of opening parantheses
        stk.push(-1);
        int maxL=0;
        for(int i=0;i<s.size();i++) {
            int t=stk.top(); 
            // check if for an opening ( there is a closing ) or not, if yes, then pop 
            if(t!=-1 && s[i]==')'&& s[t]=='(') {  
                stk.pop();                          
                maxL=max(maxL,i-stk.top());    // compare it sath me hi if its the longest
            }
            // if not then push the index of extra bracket into the stack
            else                   
                stk.push(i);
        }
        return maxL;
    }
};