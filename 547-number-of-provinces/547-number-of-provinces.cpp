class Solution {
public:
    void dfs(int i, vector<int> &vis, vector<int> adj[]){
        vis[i]=1;
        for(auto x: adj[i]){
            if(vis[x]==0){
                dfs(x,vis,adj);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        
        // pehle list bna lo matrix se extract krke
        vector<int>adjList[V];
        
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(isConnected[i][j]==1) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        vector<int>vis(V, 0);
        int cnt = 0;
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i, vis, adjList);
            }
        }
        return cnt;
    }
};