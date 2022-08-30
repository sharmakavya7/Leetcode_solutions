class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int ret = 0;
        int i = 0;

        while (startFuel < target) {
            while (i < stations.size() && stations[i][0] <= startFuel) {
                pq.push(stations[i++][1]);
            }
            if (pq.empty()) 
                return -1;
            startFuel += pq.top();
            pq.pop();
            ret++;
        }
        return ret;
    }
};