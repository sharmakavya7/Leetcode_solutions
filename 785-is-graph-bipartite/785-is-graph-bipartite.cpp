class Solution {
private: 
    bool bfs(int start, int V, vector<vector<int>>& graph, vector<int>&color) {
	    queue<int>q;
	    q.push(start);
	    color[start] = 0;
	    // O(N)
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        for(auto i:graph[node]) {
	            if(color[i]==-1 ) {
	                color[i] = !color[node];
	                q.push(i);
	            }
	            else if(color[i]==color[node]) {
	                return false;
	            }
	        }
	    }
	    return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int>q;
        q.push(0);
        int V = graph.size();
        vector<int>color(V, -1);
        for(int i=0; i<V; i++) {
	        color[i] = -1; 
	    }
	    // O(N) + O(N)
	    for(int i=0; i<V; i++) {
	        if(color[i]==-1) {
	            if(!bfs(i, V, graph, color)){
	                return false;
	            }
	        }
	    }
	    return true;
    }
};