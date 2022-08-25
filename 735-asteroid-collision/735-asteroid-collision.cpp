class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        for(int i=0; i<asteroids.size(); i++) {
            if(asteroids[i]>0 || st.empty()) {
                st.push(asteroids[i]);
            }
            else if(asteroids[i]<0) {
                while(!st.empty() && st.top()>0 && st.top()<-asteroids[i]) {
                    st.pop();
                }
                if(!st.empty() && st.top()>-asteroids[i]) {
                    continue;        // -ve one will explode 
                }
                
                else if(!st.empty() && st.top()==-asteroids[i]) {
                    st.pop();
                    continue;
                }
                else if(st.empty() || st.top()<0) { 
                    st.push(asteroids[i]);
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

// [8, 9, 6, -7, -9, 12, 50, -34]