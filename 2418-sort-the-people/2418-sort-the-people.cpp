class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        priority_queue<pair<int,string>>maxh;
        
        for(auto i=0; i<names.size(); i++) {
            maxh.push({heights[i], names[i]});
        }
        
        vector<string>ans;
        
        while(!maxh.empty()) {
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        return ans;
    }
};