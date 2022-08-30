class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        
        vector<int>v;
        v.push_back(target);
        v.push_back(0);
        // insert target also in stations {100,0} (0 means no fuel at target)
        stations.push_back(v);
        
        priority_queue<int>maxh;
        int ans=0;
        
        for(int i=0; i<stations.size(); i++) {
            if(stations[i][0]>startFuel) {
                while(!maxh.empty() && startFuel < stations[i][0]) {
                    int top = maxh.top();
                    startFuel+=top;
                    maxh.pop();
                    ans++;
                }
                if(stations[i][0]>startFuel) {
                    return -1;
                }
            }
            maxh.push(stations[i][1]);
        }
        return ans;
    }
};