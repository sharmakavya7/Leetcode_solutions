class Solution {
public:
    bool dfs(int node, vector<int>&vis, vector<int>&pathVis, vector<int>adj[]) {
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto i:adj[node]) {
            if(!vis[i]) {
                if(dfs(i, vis, pathVis, adj)==false)
                    return false;
            }
            // cycle exists
            else if(pathVis[i]) {
                return false;
            }
        }
        pathVis[node] = 0;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
        vector<int>vis(n);
        vector<int>pathVis(n);

        vector<int>adj[n];

        for(auto i:prerequisites) {
            adj[i[0]].push_back(i[1]);
        }
        
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(dfs(i, vis, pathVis, adj)==false) {
                    return false;
                }
            }
        }
        return true;
    }
};

/*

// n=2, pre: [[1,0],[0,1]]
// 1  0   :  false
// n = 5, pre:[[0,1], [0,2], [1,3], [1,4], [3,4]]
// 4  3  1  2  0  :  true

// n=4 pre:[[0,1],[2,3]]
//  1 -> 0    3 -> 2

//  0  ->

bool dfs(int node, vector<int>&vis, vector<int>&pathVis, vector<int>adj[]) {
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto i:adj[node]) {
        if(!vis[i]) {
            dfs(i, vis, pathVis, adj);
        }
        // cycle exists
        else if(vis[i] && pathVis[i]) {
            return false;
        }
    }
    pathVis[node] = 0;
    return true;
}

bool result(vector<int>&vis, vector<int>&pathVis, vector<int>adj[]) {
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            if(dfs(i, vis, pathVis, adj)==false) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    
    int n = 5;
    int prerequisites[] = {{0,1},{0,2},{1,3},{1,4},{3,4}};

    vector<int>vis;
    vector<int>pathVis;

    vector<int>adj[n];

    for(auto i:prerequisites) {
        adj[i.first].push_back(i.second);
    }

    bool ans = result(vis pathVis, adj);

    if(ans==true) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;

}


*/