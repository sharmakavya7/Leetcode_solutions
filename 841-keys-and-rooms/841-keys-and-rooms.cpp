class Solution {
public:
    void dfs(int u, vector<vector<int>>&g, vector<int> &vis){
        vis[u] = 1;
        for(int i: g[u]){
            if(vis[i])continue;
            dfs(i,g,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        vector<int> vis(rooms.size(),0);
        dfs(0,rooms,vis);
        int all_visited = accumulate(vis.begin(), vis.end(), 0);
        if(all_visited == rooms.size()){
            return true;
        }
        return false;
    }
};