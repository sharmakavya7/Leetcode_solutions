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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>t;     // size pre-define nhi krna tha pta ni kyu (else Runtime)
        for(int i=0; i<numRows; i++) {
            // t[i].resize(numRows+1);   // rows badh rhi hai cols fixed hai
            // t[i][0] = t[i][i] = 1;
            
            vector<int> row(i + 1, 1);

            for(int j=1; j<i; j++) {
                row[j] = t[i-1][j-1]+t[i-1][j]; // upr wali row ka left n right col
            }
            t.push_back(row);
        }
        return t;
    }
};