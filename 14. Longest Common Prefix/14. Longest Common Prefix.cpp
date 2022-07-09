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
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string x = strs[0];
        string y = strs[n-1];
        string res = "";
        for(int i=0; i<x.size();i++) {
            if(x[i]==y[i]) {
                //count++;
                res+=x[i];
            }
            else break;
        }
        return res;
    }
};