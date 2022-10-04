class Solution {
public:
    struct compare{
        bool operator()(pair<int,int> &a, pair<int,int> &b){
            return a.second > b.second;         
        }
    };
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstperson) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare>q;
        
        vector<vector<pair<int,int>>>adj(n);
        vector<bool> vis(n,0);
        
        for(auto i : meetings) {
            int u=i[0], v=i[1], t=i[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        
        //{person, time}
        q.push({0,0});    
        q.push({firstperson, 0});    
        
        
        while(!q.empty()) {
            int x = q.top().first;
            int t = q.top().second;
            q.pop();
            
            vis[x] = 1;
            
            for(auto [nx, nt] : adj[x]) {
                if(!vis[nx] && nt>=t){
                    q.push({nx, nt});
                }
            }
        }
        vector<int>ans;
        for(int i=0; i<n; i++) {
            if(vis[i]) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};