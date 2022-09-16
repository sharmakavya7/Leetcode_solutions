class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size()==0) {
            return 0;
        }
        if(intervals.size()==1) {
            return 1;
        }
        int rooms = 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto inter: intervals) {
            int start = inter[0], end = inter[1];
            while(!pq.empty() && pq.top() <=start) 
                pq.pop();
            pq.push(end);
            rooms = max(rooms, (int)pq.size());
        }
        return rooms;

    }
};