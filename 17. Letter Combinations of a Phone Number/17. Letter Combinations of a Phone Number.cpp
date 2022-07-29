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
    
    vector<string>mp = {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs" , "tuv", "wxyz"};

    void helper (string d, string choti, int i, vector<string>&ans) {
 
        if(i == d.size()) {        // if(st.size()==d.size()) {
            ans.push_back(choti);
            return;
        }
        // st += mp[d[i]-'0'];
        string st = mp[d[i]-'0'];
        // cout<<st[i]<<" ";
        for(int j=0; j<st.size(); j++) {
            cout<<st[i]<<" ";
            helper(d, choti+st[j], i+1, ans);   // ad, ae, af
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits=="") {
            return {};
        }
        string choti;   // for storing choti strings jo ans vector me dalni hai
        vector<string>ans;
        helper(digits, choti, 0, ans); // i is pointing to d
        return ans;
    }
};