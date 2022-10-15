class Solution {
public:
    int f(int idx, char prev, int curCharFreqCount, string &s, int k,int dp[][27][11][101]) {
        if(k < 0) return 1e9;
        
        if(idx >= s.size())
            return 0;
        
        if(curCharFreqCount >= 10)
            curCharFreqCount = 10;
        
        if(dp[idx][prev - 'a'][curCharFreqCount][k] != -1)
            return dp[idx][prev - 'a'][curCharFreqCount][k];
        
        int res = 1e9;
        
        // case 1
        res = min(res, f(idx+1, prev, curCharFreqCount, s, k-1,dp));
        
        // case 2
        if(s[idx] != prev)
            res = min(res, 1 + f(idx + 1, s[idx], 1, s, k,dp));
        
        // case 3
        else {
            
            // case 3.1
            if(curCharFreqCount == 1 || curCharFreqCount == 9 || curCharFreqCount == 99) {
                res = min(res, 1 + f(idx + 1, prev, curCharFreqCount + 1, s, k,dp));
            }
            
            // case 3.2
            else {
                res = min(res, f(idx + 1, prev, curCharFreqCount + 1, s, k, dp));
            }
        }
        
        return dp[idx][prev - 'a'][curCharFreqCount][k] = res;
    }
    
public:
    int getLengthOfOptimalCompression(string s, int k) {
        
        int n = s.size();
        
        if(n == 100) {
            bool allSame = true;
            
            // Base case
            for(int i = 1; i < n; i++) {
                if(s[i] != s[i-1]) {
                    allSame = false;
                    break;
                }
            }
            if(allSame) return 4;
        }
        // [idx][prev_char][freq_count][k]
        int dp[n+1][27][11][101];
        
        memset(dp, -1, sizeof(dp));
        
        return f(0, 'z' + 1, 0, s, k, dp);
    }
};