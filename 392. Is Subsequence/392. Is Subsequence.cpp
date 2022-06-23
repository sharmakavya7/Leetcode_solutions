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
    bool isSubsequence(string s, string t) {
        int j = 0;
        
        for (int i = 0; i < t.length() && j < s.length(); i++) {
            if (s[j] == t[i])
                j++;
        }
        return (j==s.size());
    }
};