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

int solve(string s) {
    stack<char>st;
    int cnt=0;
    for(auto i:s) {
        if(i=='(') {
            st.push('(');
        }
        else if(i==')' && !st.empty()) {
            st.pop();
        }
        else if(i==')' && st.empty()) {
            cnt++;
        }
    }
    if(!st.empty()) {
        cnt+=st.size();
    }
    return cnt;
}