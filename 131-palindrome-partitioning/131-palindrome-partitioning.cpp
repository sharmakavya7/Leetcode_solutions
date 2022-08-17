class Solution {
public:
    bool isPalin(string s, int high, int low) {
        while(low<=high) {
            
            if(s[low++]!=s[high--]) {
                return false;
            }
        }
        return true;
    }
    
    void helper(string s, int ind, vector<vector<string>>&ans, vector<string>&subs) {
        
        if(ind==s.size()) {
            ans.push_back(subs);
            return;
        }
        
        for(int i=ind; i<s.size(); i++) {
            if(isPalin(s, i, ind)) {
                //pick
                //
                subs.push_back(s.substr(ind,i-ind+1));  //SUPER IMP LINE
                helper(s, i+1, ans, subs);
                subs.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>subs;
        //int n = s.size();
        helper(s, 0, ans, subs);
        return ans;
    }
};