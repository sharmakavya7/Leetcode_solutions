class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>mp;
        if(n==0) {
            return ans;
        }

        for(int i=0; i<n; i++) {
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(strs[i]);    
        }
        // 1st: key: aet, val: eat
        // 2nd: key: aet  val: eat, tea
        // 3rd  key: ant  val: tan
        // 4th  key: aet  val: eat, tea, ate
        // 5th  key: ant  val: tan, nat
        // 6th  key: abt  val: bat

        for(auto i:mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};