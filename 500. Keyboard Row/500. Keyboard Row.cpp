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
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiopQWERTYUIOP";
        string row2 = "asdfghjklASDFGHJKL";
        string row3 = "zxcvbnmZXCVBNM";
        
        unordered_map<char,int>mp;
        
        for(auto ch : row1) {
            mp[ch] = 1;
        }
        for(auto ch : row2) {
            mp[ch] = 2;
        }
        for(auto ch : row3) {
            mp[ch] = 3;
        }
        
        bool visited;
        vector<string>ans;
        
        // for(int i=0; i<words.size(); i++) {
        for(auto &word : words) {
            visited = true;
            for(int j=1; j<word.size(); j++) {
                if(mp[word[j]] != mp[word[0]]) {
                    visited = false;
                    break;
                }
            }
            if(visited) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};