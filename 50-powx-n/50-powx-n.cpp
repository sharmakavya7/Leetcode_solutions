class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long copy = n;       // copy of n
        if(copy<0) {
            copy = -1 * copy;
        }
        while(copy>0) {
            if(copy%2 ==0) {
                x = x*x;
                copy = copy/2;
            }
            else if(copy%2!=0) {
                ans = ans*x;
                copy = copy-1;
            }
            if(n==0) break;
        }
        if(n<0) {
            ans = 1/ans;
        }
        return ans;
    }
};