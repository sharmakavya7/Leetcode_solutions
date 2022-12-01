class Solution {   
public:
    int mySqrt(int x) {
        double low = 1;
        double high = x;
        //int n = 2;
        double epsilon = 0.000001;
        
        while((high-low)>epsilon) {              //trim it trim it trim it 
            double mid = (low + high)/2.0;       //shrink them till the diff becomes close to 1e^-6
            if((mid*mid) < x ) {                 // 1e^-6 = 10^-6
                low = mid;
            }
            else if((mid*mid) >= x ) {  //sqrt find krna h, so we have found the sq of mid
                high = mid;                     //if power was different, see below
            }
        }
        return high;
    }
};
// IMPORTANT:
// for powers greater than 2, say for power n:
// we have to change line 10 and 13 to multiple(mid,n)
// this multiple fuunction will return:
// double multiply(int x, int n) {
//     double ans=1.0;
//     for(int i=1; i<=n; i++) {
//         ans *= x;
//     }
//     return ans;
// }