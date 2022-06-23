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
class solution {
    public:
    //Function to find the largest number after k swaps.
    void helper(string& str, int k, int i, string& ans) {
        if(k==0 || i==str.size()) {
            if(ans<str) {
                ans = str;
            }
            return;
        }
        for(int j=i+1; j<str.size(); j++) {
            // swap krenge
            if(str[j]>str[i]) {
                swap(str[i],str[j]);
                helper(str, k-1, i+1, ans);
                swap(str[i],str[j]);
            }
        }
        // swap nhi krenge
        helper(str, k, i+1, ans);
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans = str;
        helper(str, k, 0, ans);
        return ans;
    }
};