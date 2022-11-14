class Solution {
public:
    vector<int> vis;
    int n;
    void dfs(int idx, vector<vector<int>> &stones){
        vis[idx] = true;
        
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            if(stones[idx][0] == stones[i][0] || stones[idx][1] == stones[i][1])
                dfs(i, stones);
        }
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        
        vis.resize(n, 0);
        
        int val = 0;
        
        for(int i = 0; i < n; i++){
            if(!vis[i]) {
                dfs(i, stones);
                val++;
            }
        }
        
        return n - val;
    }
};