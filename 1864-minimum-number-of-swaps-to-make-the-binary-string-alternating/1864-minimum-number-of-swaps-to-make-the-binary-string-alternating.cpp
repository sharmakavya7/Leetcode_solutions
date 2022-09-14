class Solution {
public:
    int helper(string s, char st) {
        int swaps = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == st && i % 2 != 0) 
                swaps++;
        }
        return swaps;
    }
    int minSwaps(string s) {
        // int zeros = count(begin(s), end(s), '0');
        int zeros = 0;
        int ones = 0;
        for (auto c : s) {
            if (c == '1')
                ones++;
            else zeros++;
        }
        if (abs(zeros - ones) > 1)
            return -1;
        
        if (zeros < ones)
            return helper(s, '1');
        
        if (zeros > ones) 
            return helper(s, '0');
        
        return min(helper(s, '1'), helper(s, '0'));  
    }
};

/*

int extraone = 0;
        // int needzero = 0;
        int extrazero = 0;
        // int needone = 0;
        int cnt=0;
        for(int i=0; i<s.size(); i++) {
            // if start from 1
            if(s[i]==1) {
                if(s[i+1]!='0') {
                    extraone++;
                    extrazero--;
                    cnt++;
                    s[i+1] = '0';
                }
            }
            else {
                if(s[i+1]!='1') {
                    extrazero++;
                    extraone--;
                    cnt++;
                    s[i+1] = '1';
                }
            }
        }
        cout<<extraone<<" "<<extrazero<<" ";
        if(extraone<0 || extrazero<0) {
            return -1;
        }
        return cnt/2;

*/