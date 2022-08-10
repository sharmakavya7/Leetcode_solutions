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
    bool isVowel(char c){
        return c=='a' ||c=='e' ||c=='u'|| c=='i'||c=='o' ;  
    }
    void helper(string& s, string& v, int i, set<string>& st) {
        if(i>=s.size()) {
            if(isVowel(v[0]) && !isVowel(v[v.size()-1]))
                st.insert(v);
            // v.erase();
            return;
        }
        // st.insert(s[i]);
        v.push_back(s[i]);
        helper(s, v, i+1, st);   // pick
        v.pop_back();
        helper(s, v, i+1, st);   // not picking
    }
    set<string> allPossibleSubsequences(string S) {
        // code here
        set<string>st;
        string v="";
        helper(S, v, 0, st);
        return st;
    }
};