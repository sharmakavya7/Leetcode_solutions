class Solution {
public:
    bool is_cycle(int src, int parent, vector<int>&vis, vector<int>adj[]) {
        
        vis[src]=1; 
        
        for(auto i:adj[src]) {
            if(!vis[i])  {
                if(is_cycle(i, src, vis, adj))
                    return true;
            }
            else if(i!=parent) {
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int>vis(n);
        vector<int>adj[n];
        
        for(auto i:edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int componentCount = 0;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                componentCount++;
                // if cycle found, return false as it can't be a tree
                if(is_cycle(i, -1, vis, adj))
                    return false;
            }
        }
        return componentCount == 1 ? true : false;
    }
};