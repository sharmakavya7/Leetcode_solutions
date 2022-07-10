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
    bool canChange(string start, string target) {
        // vector<int>v1(start.size()), v2(start.size());
        string s1 ="", t1 = "";
        
        for (auto &c :start) {  // skip all dashes and add in s1
            if (c!='_')
                s1+=(c);
        }
        
        for (auto &c :target) {  // skip all dashes and add in s2
            if (c!='_')
                t1+=(c);
        }
        
        if (s1!=t1)          // If the order of L R's doesn't match, return false;
            return false;
        
        int i=0, j=0;
        while(i<start.size() && j<start.size()) {
            if (start[i]=='_')    // skip dashes
                i++;
            
            else if (target[j]=='_')   // yaha ke bhi
                j++;
            
            else {
                if ((start[i]=='L' && i<j) || (start[i]=='R' && i>j)) // 
                    return false;
                i++;
                j++;
            }
        }
        return true;
    }
};