class Solution {
public:
    int helper(string s, char st) {
        int swaps = 0;
        // 0 se shuru kro alternate index dkeho kon kon st ke equal nhi hai
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == st && i % 2 != 0) 
                swaps++;
        }
        return swaps;
    }
    int minSwaps(string s) {
        int zeros = 0;
        int ones = 0;
        for (auto c : s) {
            if (c == '1')
                ones++;
            else zeros++;
        }
        if (abs(zeros - ones) > 1)
            return -1;
        
        // case 1 --> if ones>zeros then 0th position pe 1 hi aa skta to make alternating
        if (zeros < ones)
            return helper(s, '1');
        
        // case 2 --> if zero>ones then 0th position pe 0 hi aa skta to make alternating
        if (zeros > ones) 
            return helper(s, '0');
        
        //case 3 --> if zero==ones then koi bhi starting me aa skta dono case check kro MIN
        return min(helper(s, '1'), helper(s, '0'));  
    }
};
