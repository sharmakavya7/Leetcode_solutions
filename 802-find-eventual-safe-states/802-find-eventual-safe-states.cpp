class Solution {
public:
    bool dfs(int start, vector<int>&vis, vector<int>&pathvis, int V, vector<vector<int>>& graph, vector<int>&check) {
        vis[start] = 1;
        pathvis[start] = 1;
        check[start]=0;
        for(int i:graph[start]) {
            // when the nod eis not visited
            if(!vis[i]) {
                if(dfs(i, vis, pathvis, V, graph, check)){
                    // if it is a cycle this guy can't be a safe node
                    check[start]=0;
                    return true;
                }
            }
            // when the node has been prev visted (only if it is the same path)
            // mtlb usi path pe hmare ko vo node mil gyi, i.e. cycle hai brooooo
            else if(pathvis[i]) {
                // if it is a cycle this guy can't be a safe node
                check[start]=0;
                return true;
            }
        }
        // if it didnot find any cycle
        check[start] = 1;
        pathvis[start] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        vector<int>safeNodes;   // ans vec
        vector<int>check(V,0);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs(i, vis, pathvis, V, graph, check);
            }
        }
        
        for(int i=0; i<V; i++) {
            if(check[i]==1) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};