class Solution {
public:
    int minSwaps(string s) {
        int even1 = 0, odd1 = 0, n = s.size();
        
        // Number of '1' at event position
        for (int i=0; i<n; i+=2) {
            even1 += s[i] == '1';
        }
        
        // Number of '1' at odd position
        for (int i=1; i<n; i+=2) {
            odd1 += s[i] == '1';   
        }
        
        // If length is odd -> It should be: 10101 or 01010
        if (n % 2 == 1) {
            
            // 01010 case
            if (even1 + odd1 == n/2) {
                return even1;
                
            } 
            else if (even1 + odd1 == n/2 + 1) { // 10101 case
                return odd1;
            }
        } 
        else {
            // Should be 010101 or 101010
            if (even1 + odd1 == n/2)
                return min(even1, odd1);
        }
        
        return -1;
    }
};