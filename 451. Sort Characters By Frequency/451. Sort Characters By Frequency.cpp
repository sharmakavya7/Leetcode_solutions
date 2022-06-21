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
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto ch : s) {
            mp[ch]++;
        }
        priority_queue<pair<int,char>> maxheap;
        string ans = "";
        
        for(auto it: mp)
            maxheap.push({it.second,it.first}); 
        
        while(!maxheap.empty()){
            ans+=string(maxheap.top().first,maxheap.top().second);
            maxheap.pop();
        }
        return ans;
    }
};