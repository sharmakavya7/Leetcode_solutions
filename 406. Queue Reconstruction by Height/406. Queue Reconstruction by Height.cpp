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
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>&a, vector<int>&b) {
            if(a[0]==b[0]) {
                return a[1] < b[1];
            }
            return a[0] > b[0];
        });  // sorting wrt seconds
        
        vector<vector<int>> res;
        
        for(int i=0; i<people.size(); i++) {
            res.insert(res.begin()+people[i][1], people[i]);
        }
        return res;
    }
};