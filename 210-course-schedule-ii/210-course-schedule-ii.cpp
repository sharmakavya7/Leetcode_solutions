class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<int>adj[V];
        for(auto i:prerequisites) {
            adj[i[1]].push_back(i[0]);
        }
        // chekc for topo sort

	    vector<int>indegree(V,0);
	    for(auto i=0; i<V; i++) {
	        for(auto it:adj[i]) {
	            indegree[it]++; 
	        }
	    } 
	    queue<int>q;
	    for(int i=0; i<V; i++) {
	        if(indegree[i]==0) {
	            q.push(i);
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()) {
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        for(int i:adj[node]) {
	            indegree[i]--;
	            if(indegree[i]==0)
	                q.push(i);
	        }
	    }
	    
        if(topo.size()==V) {
            return topo;
        }
        return {};
    }
};