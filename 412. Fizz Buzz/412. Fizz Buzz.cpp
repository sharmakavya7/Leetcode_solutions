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
    vector<string> fizzBuzz(int n) {
        
        vector<string> ans(n);
        
        for(int i = 1;i <= n; i++) {    // Initially fill the string with i=1 to n
            ans[i - 1] = to_string(i);
        }
        
        for(int i = 2;i < n; i += 3) {  // 0,1,2; 2 pe 3 hoga, so 2nd index+3 everytime
            ans[i] = "Fizz";
        }
        
        for(int i = 4;i < n; i += 5) {
            ans[i] = "Buzz";
        }
        for(int i = 14;i < n; i += 15) {
            ans[i] = "FizzBuzz";
        }
        return ans;
    }
};