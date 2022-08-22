class Solution {
public:
    string largestOddNumber(string num) {
        // int dup =stoi(num);
        // if(dup%2 != 0) {
        //     return num;
        // }
        stack<int>st;
        for(auto i:num) {
            st.push(i);
        }
        string ans = "";
        while(!st.empty()) {
            int temp = (int)(st.top());
            if(temp%2!=0) {
                break;
            }
            else {
                st.pop();
            }
        }
        if(!st.empty()) {
            while(!st.empty()) {
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};