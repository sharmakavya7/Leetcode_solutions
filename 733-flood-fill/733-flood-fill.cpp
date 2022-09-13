class Solution {
public:
    int DR[4]={1, 0, -1, 0};
    int DC[4]={0, -1, 0, 1};
    
    void bfs(vector<vector<int>>& image, int row, int col, int Newcolor) {
        int m = image.size();
        int n = image[0].size();
        
        int val = image[row][col];    // the color which we need to find and transform
        image[row][col] = Newcolor;
        
        queue<pair<int,int>>q;
        q.push({row,col});
        
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int k=0; k<4; k++)  {
                int ci=DR[k]+row;  // neightbour row
                int cj=DC[k]+col;  // neighbour row
                
                if(ci >= 0 && ci < m && cj >= 0 && cj < n 
                   && image[ci][cj]!=Newcolor && image[ci][cj]==val) {
                    q.push({ci, cj});
                    image[ci][cj]=Newcolor;
                }
            }
        }
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        
        bfs(image, sr, sc, color);
        
        return image;
    }
};