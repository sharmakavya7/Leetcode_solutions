class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size()==0) {
            return true;
        }
        if(intervals.size()==1) {
            return true;
        }
        sort(intervals.begin(),intervals.end());
        bool ans = true;
        pair<int,int>meets(intervals[0][0], intervals[0][1]);
        // meets.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] >= meets.second) {
                // meets[1] = max(meets[1],intervals[i][1]);
                // meet = intervals[i];
                meets.first = intervals[i][0];
                meets.second = intervals[i][1];
                ans = true;
            }
            else {
                return false;
            }
        }
        return ans;
    }
};