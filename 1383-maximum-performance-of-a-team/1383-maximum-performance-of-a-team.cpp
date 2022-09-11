class Solution {
public:
    // struct comparator {
    //     bool operator() (vector<int>& a, vector<int>& b) {
    //         return a[0] > b[0];
    //     }
    // };
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int mod = 1000000007;
        vector<pair<int, int>>V;
        
        for(int i=0; i<n; i++)
            V.push_back({efficiency[i], speed[i]});
        
        sort(V.begin(), V.end(), [](auto a, auto b){
            return a.first > b.first;
        });
        
        
        priority_queue<int>pq;
        
        long long speedT = 0, ans = 0;
        
        
        for(auto it:V)
        {
            speedT += it.second;
            
            pq.push(-it.second);
            
            if(pq.size() > k)
            {
                speedT -= abs(pq.top());
                pq.pop();
            }
            
            ans = max(ans, it.first*speedT);
        }
        
        return ans % mod;
    }
};