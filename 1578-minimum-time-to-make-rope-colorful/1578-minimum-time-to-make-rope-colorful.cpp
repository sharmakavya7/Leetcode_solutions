class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
        stack<pair<char,int>> st;
        int n=s.size(), result=0;
        
        for(int i=0; i<n; i++) {
            
            if(!st.empty() && st.top().first==s[i]) {
                
                if(st.top().second < neededTime[i]) {
                    
                    result += st.top().second;
                    st.pop();
                    st.push({s[i], neededTime[i]});
                }
                else {
                    result += neededTime[i];
                }
            }
            else {
                st.push({s[i], neededTime[i]});
            }
        }
        
        return result;
    }
};