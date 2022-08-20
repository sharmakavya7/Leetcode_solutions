class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int ret = 0;
        int id = 0;

        while (startFuel < target) {
            while (id < stations.size() && stations[id][0] <= startFuel) {
                pq.push(stations[id++][1]);
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