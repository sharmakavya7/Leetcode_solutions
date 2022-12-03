class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>mp;
        for(auto c:s) {
            mp[c]++;
        }
        priority_queue<pair<int, char>>pq;
        
        for(auto [k, v] : mp) {
            pq.push({v, k});
        }
        string ans = "";
        while(!pq.empty()) {
            auto freq = pq.top().first;
            auto c = pq.top().second;
            // cout << pq.top().second <<" " << freq <<" ";
            pq.pop();
            
            for(int i=0; i<freq; i++) {
                ans += c;
            }
        }
        return ans;
    }
};