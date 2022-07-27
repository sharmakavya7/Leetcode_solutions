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

bool solve(string s) {
    stack<char>st;
    int cnt=0;
    if(s.empty()) {
        return true;
    }
    for(auto i:s) {
        if(i=='(') {
            st.push('(');
        }
        else if(i==')' && !st.empty()) {
            st.pop();
        }
        // else if(st.empty()) {
        //     return true;
        // }
        else if(i==')' && st.empty()) {
            return false;
        }
    }
    if(!st.empty()) {
        return false;
    }
    return true;;
}