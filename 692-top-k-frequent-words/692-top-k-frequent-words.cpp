class myComparator {
  public:
    bool operator() (const pair<int, string> &p1, const pair<int, string> &p2) {
      if(p1.first == p2.first) return p1.second < p2.second;
      
      return p1.first > p2.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>mp;
        for(string i:words) {
            mp[i]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,myComparator>pq;
        
        for(auto [l,v]:mp) {
            
            pq.push({v,l});

            if(pq.size()>k) {
                pq.pop();
            }
        }
        vector<string> ans;
        while(!pq.empty() ) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};