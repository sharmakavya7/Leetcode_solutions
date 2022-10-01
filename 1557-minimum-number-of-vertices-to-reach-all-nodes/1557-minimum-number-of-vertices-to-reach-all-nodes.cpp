class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // just find nodes with no indegree
        // int n = edges.size();
        // int m = edges[0].size();
        vector<int>adj[n];

        for(auto i:edges) {
            adj[i[0]].push_back(i[1]);
        }
        vector<int>indegree(n,0);
        for(int i=0; i<n; i++) {
            for(int it:adj[i]) {
                indegree[it]++;
            }
        }
        vector<int>ans;
        for(int i=0; i<indegree.size(); i++) {
            if(indegree[i]==0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};