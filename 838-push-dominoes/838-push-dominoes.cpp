class Solution {
public:
    string pushDominoes(string s) {
        int N = s.size();
        int right=-1;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='.')
                continue;
            
            if(s[i]=='L') {
                if(right == -1) {
                    int j = i-1;
                    while(j>=0 && s[j] == '.') {
                        s[j] = 'L';
                        j--;
                    }
                }
                else {
                    for (int j = right + 1, k = i - 1; j < k; ++j, --k) {
                        s[j] = 'R';
                        s[k] = 'L';
                    } 
                    right = -1;
                }
            }
            
            else if (s[i] == 'R') {
                if (right != -1) {
                    for (int j = right + 1; j < i; ++j) 
                        s[j] = 'R';
                }
                right = i;
            }
        }
        if (right != -1) {
            for (int j = right + 1; j < N; ++j) s[j] = 'R';
        }
        return s;
    }
};
