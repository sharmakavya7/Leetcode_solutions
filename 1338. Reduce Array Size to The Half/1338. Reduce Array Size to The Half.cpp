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
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;
        for(auto i:arr) {
            mp[i]++;
        }
        priority_queue<pair<int, char>> q;
        for (auto [a, frq] : mp) 
            q.push({frq, a});
        
        int k = n;
        
        int cnt=0;
        while(k-q.top().first > n/2) {
            k -= q.top().first;
            q.pop();
            cnt++;
            // cout<<k<<endl;
        }
        cnt++;
        return cnt;
    }
};