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

        pair<int,int>meets(intervals[0][0], intervals[0][1]);
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] >= meets.second) {
                meets.first = intervals[i][0];
                meets.second = intervals[i][1];
            }
            else {
                return false;
            }
        }
        return true;
    }
};