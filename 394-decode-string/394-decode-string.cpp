class Solution {
public:
    string decodeString(string s) {
        // stack<int>s1;
        stack<char>st;
        string ans;
        for(int i=0; i<s.size(); i++) {
            if(s[i] != ']') {
                st.push(s[i]);
            }
            else{
                string curr_str = "";
                
                while(st.top() != '['){
                    curr_str = st.top() + curr_str ;
                    st.pop();
                }
                
                st.pop();   // for '['
                string number = "";
                
                // for calculating number
                
                while(!st.empty() && isdigit(st.top())){
                    number = st.top() + number;
                    st.pop();
                }
                int num = stoi(number);    // convert string to number
                
                while(num--){
                    for(int p = 0; p < curr_str.size() ; p++)
                        st.push(curr_str[p]);
                }
            }
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


/*
        string str="";
        string combined = "";
        int num = 0;
        while(isdigit(s[i])) {
            num = num*10 + s[i]-'0';
            i++;
        }
        s1.push(num);
        if(s[i]=='[') {
            s2.push(s[i]);
        }
        else if(s[i]>'a' && s[i]<'z') {
            s2.push(s[i]);
        }
        else if(s[i]==']') {
            while(!s2.empty() && s2.top()!='[') {
                str+=s2.top();
                s2.pop();
            }
            for(int i=0; i<s1.top(); i++) {
                combined+=str;
            }
            s1.pop();
            for(int i=0; i<combined.size(); i++) {
                s2.push(combined[i]);
            }
        }

*/