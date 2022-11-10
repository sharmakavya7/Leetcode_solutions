class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        stack<int>st;
        for(int i=0; i<n; i++) {
            if(!st.empty() && s[i] == '*') {
                st.pop();
            }
            else {
                // cout<<s[i]<<" ";
                st.push(s[i]);
            }
        }
        string res;
        while(!st.empty()) {
            int topi = st.top();
            st.pop();
            res.push_back(topi);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};