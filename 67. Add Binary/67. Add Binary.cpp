#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib> 
#include <string>
#include <map>
#include <climits>
#include <iterator>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size();
        int m=b.size();
        int carry=0;
        string res;
        int i = n-1;
        int j = m-1;
        
        while(i>=0 || j>=0) {

            int sum = carry;
            if(i>=0) {
                sum+=a[i]-'0';
                i--;
            }
            if(j>=0) {
                sum+=b[j]-'0';
                j--;
            }
            carry = sum > 1 ? 1 : 0;
            res+=to_string(sum%2);

        }
        if(carry!=0) {
            res+=to_string(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
