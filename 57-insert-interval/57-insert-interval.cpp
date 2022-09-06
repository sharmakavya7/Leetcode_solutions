class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int i=0;
        
        while(i<intervals.size() && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }
        
        while(i<intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        
        while(i<intervals.size()) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};





/*
for(auto i=0; i<intervals.size(); i++) {
            vector<int>intrv;
            if(intervals[i][0] < newInterval[0] && intervals[i][1] > newInterval[0]) {
                intrv.push_back(intervals[i][0]);
                while(intervals[i][1] < newInterval[1]) {
                    i++;
                }
                cout<<newInterval[1]<<" ";
                int maxi = max(intervals[i][1], newInterval[1]);
                intrv.push_back(maxi);
                ans.push_back(intrv);
            }
            else if(intervals[i][0] < newInterval[0] && intervals[i][1] < newInterval[1]) {
                intrv.push_back(intervals[i][0]);
                intrv.push_back(intervals[i][1]);
                ans.push_back(intrv);
            }
        }
        return ans;
*/