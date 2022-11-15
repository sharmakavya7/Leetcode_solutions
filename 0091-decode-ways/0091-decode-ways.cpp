class Solution {
public:
    vector<int>dp;
    int decode(string &s, int i) {
        if(i == s.size()) {
            return 1;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        int ans = 0;
        // 2 cases, 1st: s[i] != '0', 2nd: s[i] == '1' || s[i] == '2' && s[i+1] <= '6'
        if(s[i] != '0') {
            ans += decode(s, i+1);
        }
        if(i+1 < s.size() && ( s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) {
            ans += decode(s, i+2);
        }
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        dp.resize(101, -1);
        return decode(s, 0);
    }
};