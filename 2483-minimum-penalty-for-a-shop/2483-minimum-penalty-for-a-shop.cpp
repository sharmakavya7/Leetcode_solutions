class Solution {
public:
    int bestClosingTime(string c) {
        int n = c.size();
        // vector<int>pref(n, 0), suff;
        int p=0;
        
        for(int i=0; i<n; i++) {
            if(c[i] == 'Y') {
                p++;
            }
        }
        int mini=p, j=0;
        for(int i=0; i<n; i++) {
            p += (c[i] == 'Y' ? -1 : 1);
            if(p < mini) {
                mini = p;
                j = i + 1;
            }
        }
        return j;
    }
};