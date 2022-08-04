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
    // 2.5 hrs (bad score for this problem)
    int mirrorReflection(int p, int q) {
        if(p==q) {
            return 1;
        }
        int ans;
        
        while(p%2==0 && q%2==0) {
            p/=2;
            q/=2;
        }
        
        if(p%2==0 && q%2!=0) {
            return 2;
        } 
        
        else if(p%2!=0 && q%2!=0)
            return 1;
        
        else {                     // if(p%2!=0 && q%2==0) 
            return 0;
        }
    }
};