class Solution {
public:
    bool helper(int n) {
        if(n==0) {  // if it equates to zero, it is anyways not a multiple of 4
            return false;
        }
        cout<<n<<" ";
        // if(n%4!=0) return false;      // remainder check 
        return (n==1 || (n%4==0) && helper(n/4));
    }
    
    bool isPowerOfFour(int n) {
        if(n==1) {
            return true;
        }
        if(n%4 != 0) {
            return false;
        }
        return helper(n);
    }
};