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
    int removePalindromeSub(string s) {
        // int count = 0;
        // check if entire s is a palindrome
        if(s==" ") {
            return 0;
        }
        // int start=0;
        // int end=s.size();
        // while(start<=end) {
        //     if(s[start]!=s[end]) {
        //         return 2;
        //     }
        //     start++;
        //     end--;
        // }
        // for(int i=0; int j=s.size()-1; i<j; i++; j--) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if(s[i]!=s[j]) {
                return 2;
            }
        }
        return 1;
    }
};