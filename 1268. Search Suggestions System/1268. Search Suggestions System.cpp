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
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        string current = "";
        vector<vector<string>> ans;
        // int start = 0, end = product.size();
        sort(products.begin(), products.end());
        for(auto ch : searchWord) {
            current += ch;
            auto it = lower_bound(products.begin(), products.end(), current);
            vector<string> suggestions;
            for(int i=0; i < 3 && (it+i) != products.end(); i++) {
                string temp = *(it+i);
                if(temp.find(current)) {
                    break;
                }
                suggestions.push_back(temp);
            }
            ans.push_back(suggestions);
        }
        return ans;
    }
};