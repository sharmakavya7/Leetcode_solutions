class Solution {
public:
    bool isVowel(char s) {
        if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
            return true;
        return false;
    }
    long long countVowels(string word) {
        long long cnt = 0, ans = 0, n = word.size();
        for(int i=0; i<n; i++) {
            if(isVowel(word[i])) {
                ans += (i+1) * (n - i);
            }
        }
        return ans;
    }
};
/*
If s[i] is vowel, there are (i + 1) * (N - i) substrings that contain s[i] where i + 1 and N - i are the number of possible left and right end points of the substrings, respectively.
*/