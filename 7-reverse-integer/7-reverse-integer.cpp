class Solution {
public:
    
    int reverse(int x) {
        long long ans = 0;
        long long temp =0;
        while(x!=0) {
            long long cur = x % 10;
                      
            temp = ans * 10 + cur;
            
            // if (temp > INT_MAX/10 || (temp == INT_MAX / 10)) return 0;
//             if (temp < 0 && temp < (INT_MIN/10)) return 0;
            
            
//             if (temp / 10 != ans) {
//                 return 0;
//             }
            
            ans = temp;
            x = x/10;
        }
        return (ans<INT_MIN || ans>INT_MAX) ? 0 : ans;
        // return ans;
    }
};

/* Function to get sum of digits */
// class gfg {  -2147483648
// public:
//     int getSum(int n)
//     {
//         int sum = 0;
//         while (n != 0) {
//             sum = sum + n % 10;         //this logic helps!!!!
//             n = n / 10;                 //Get the rightmost digit of the number with help of the remainder                                                ‘%’ operator by dividing it by 10 and add it to sum.
//         }                               //Divide the number by 10 with help of ‘/’ operator to remove the                                                  rightmost digit.
//         return sum;
//     }
// };