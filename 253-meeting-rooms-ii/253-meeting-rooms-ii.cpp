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
        // sort(intervals.begin(), intervals.end(), [](vector<int> &i, vector<int> &j) {
        //     return i.first < j.first;
        // });
//         int ans=0;
//         pair<int,int>meets(intervals[0][0], intervals[0][1]);

//         for(int i=1; i<intervals.size(); i++) {
//             if(intervals[i][0] < meets.second) {
//                 // meets[1] = max(meets[1],intervals[i][1]);
//                 // meet = intervals[i];
//                 meets.first = intervals[i][0];
//                 meets.second = intervals[i][1];
//                 ans++;
//             }
//             else {
//                 continue;
//             }
//         }
//         return ans+1;
    }
};