class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto i : arr) {
            mp[i]++;
        }
        unordered_set<int> st;
        for(auto x : mp){
            st.insert(x.second);
        }
        return (st.size() == mp.size());
    }
};