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
    int countAsterisks(string s) {
        int barcnt = 0;
        int star = 0;
        for(auto ch:s) {
            if(ch=='|') {
                barcnt++;
            }
            if(barcnt%2 != 0) {
                continue;
            }
            else {
                if(ch == '*') {
                    star++;
                }
                else continue;
            }
        }
        return star;
    }
};