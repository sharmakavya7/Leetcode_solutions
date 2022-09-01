class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        for (int num : nums)
            mp[num]++;
        
        priority_queue<pair<int,int>>maxh;
        
        for(auto [k,v]:mp) {
            maxh.push({v,k});
        }
        vector<int>ans;
        while(k--) {
            auto top = maxh.top().second;
            maxh.pop();
            ans.push_back(top);
        }
        return ans;
        
    }
};

