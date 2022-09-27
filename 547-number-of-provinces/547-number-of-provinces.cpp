class Solution {
private:
    void make_set(int n) {
        for(int i = 0; i < n; i++) 
            parent[i] = -1;
    }
    
    int find_set(int v) {
        if (parent[v] < 0)
            return v;
        return parent[v] = find_set(parent[v]);
    }
    
    void join(int a, int b) {
        int p1 = find_set(a);
        int p2 = find_set(b);
        if (p1 != p2)
            parent[p2] = p1;
    }
    
public:
    int parent[201];
    
    int findCircleNum(vector<vector<int>>& M) {
        int i, j, groups = 0, n = M.size();
        make_set(n);
          
        for(i = 0; i < n; i++) {
            for(j = i + 1; j < n; j++) {
                if(M[i][j]==1)
                    join(i, j);
            }
        }
        
        for(i = 0; i < n; i++) {
            if(parent[i] < 0)
                groups++;
        }
        
        return groups;
    }


};