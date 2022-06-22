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
    bool isValid(string s) {
        stack<char> stack;
        for(int i = 0; i<s.size(); i++) {                    //for(auto i:s)
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.push(s[i]);
            }
            
            else {
                if(stack.empty() || (stack.top()=='(' && s[i]!=')') || (stack.top()=='[' && s[i]!=']') || (stack.top()=='{' && s[i]!='}')) 
                    return false;
                
                stack.pop();
                //else return true;
            }
        }
        return stack.empty();
            //return false;
    }   
};