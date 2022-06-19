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
    string greatestLetter(string s) {
        sort(s.begin(), s.end(), greater<int>());
        string lower = "", upperStr = "";
        for(int i=0; i<s.size(); i++) {
            if (s[i] >= 65 && s[i] <= 91)
                upperStr = upperStr + s[i];
            else lower = lower + s[i];
        }
        string ans = "";
        for(int i=0; i<s.size(); i++) {
            if (upperStr[i] != 0 && lower[i] != 0)
            {
                for(int j = 0 ; j < min(upperStr.size() , lower.size()) ; j++)
                {
                    int l = int(lower[j]), u = int(upperStr[i]);
                    if(l - u ==32) {
                        ans = ans + upperStr[i];
                        break;
                    }
                    
                }
                if(!ans.empty()) {
                        break;
                    }
            }
            else return "";
        }
        string temp = "";
        temp += ans.at(0);
        for (int i = 1; i < ans.length(); i++) {
            if (!(temp.find(ans.at(i)) < temp.length()))
                temp = temp + ans.at(i);
        }
        return temp;
    }
};