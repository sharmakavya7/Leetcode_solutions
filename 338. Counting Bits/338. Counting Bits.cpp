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
    vector<int> countBits(int n) {
        vector<int>ans(n);
        ans.push_back(0);
        if(n==0) {
            return ans;
        }
        for(int i=0; i<=n; i++) {
            // else if(i==1) {
            //     ans.push_back(1);
            //     // return 1;
            // }
            if(i%2==0) {
                ans[i] = ans[i/2];
            }
            else {
                ans[i] = ans[i-1]+1;
            }
        }
        return ans;
    }
};


