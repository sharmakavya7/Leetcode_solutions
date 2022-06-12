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
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // int n=potions.size();
        sort(potions.begin(),potions.end());
        vector<int>result;
        for(int i=0; i<spells.size(); i++) {
            long long temp = ceil(double(success*1.0/spells[i]));
            auto it = lower_bound(potions.begin(), potions.end(), temp);
            int ind = it - potions.begin();  //
            result.push_back(potions.size()-ind);
        }
        return result;
    }
};