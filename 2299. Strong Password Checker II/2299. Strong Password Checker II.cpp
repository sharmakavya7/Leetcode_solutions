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
    bool adjacent(string&s) {
        char prev;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (prev == *it)
            {
                return false;   // same elements
            }
            else {
                prev = *it;
            }
        }
        return true;     // no same adj ele
    }
    
    bool strongPasswordCheckerII(string password) {
        int n = password.size();
        unordered_set<char> s({'!','@','#','$','%','^','&','*','(',')','-','+'});
        if(n<8) {
            return false;
        }
        // int l=0, u=0, d=0, sc;
        bool l=false, u=false, d=false, sc=false;
        bool adj = adjacent(password);
        for(int i=0; i<n; i++) {
            // if (password[i]>=33 && password[i]<=45) something++ ;   // special chars
            if (password[i]>=48 && password[i]<=57) d=true;//d++; // digists
             if (password[i]>='A' && password[i]<='Z') u=true;//u++;   // Capital alphabets: 65-90
            if (password[i]>='a' && password[i]<='z') l=true;//l++;   // Small alphabets: 97-122
            if(s.find(password[i])!=s.end()) sc=true; //sc++;
        }
        // if(d>=1 && u>=1 && l>=1 && sc>=1) {
        if(d==true && u==true && l==true && sc==true && adj==true) {
            return true;
        }
        return false;
    }
};