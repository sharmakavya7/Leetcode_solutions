class Solution {
public:
    // T.C. O(n)
    // S.C. O(1)
    int fib(int n) {
        if(n<2) {
            return n;
        }
        int prev1 = 1;
        int prev2 = 0;
        int cur = 0;
        
        for(int i=2; i<=n; i++) {
            cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};