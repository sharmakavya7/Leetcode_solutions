class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<int>st;
        for(int i=0; i<n; i++) {
            if(!st.empty() && st.top() == s[i]) {
                st.pop();
            }
            else st.push(s[i]);
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