
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
    
    int solve(int N, int a, vector<int> x) {
        // code here
        // int res = 0;
        if (N==2) {
            return abs(x[0]-a) + abs(x[1]-a);
        }
        int mx = 0;
        for(int i=0; i<N; i++) {
            x[i] = abs(x[i] - a);
        }
        sort(x.begin(),x.end());
        
        return x[N-2]+x[N-1];
    }
};