class Solution {
public:
    int dir_x[4] = {0,1,0,-1};
    int dir_y[4] = {1,0,-1,0};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size(),n=maze[0].size(),s,steps=0;
        // entrance has wall then no path
        
        if(maze[entrance[0]][entrance[1]]=='+')
            return -1;

        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        
        while(!q.empty()){
            s=q.size();
            steps++;
            while(s--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int nx = x + dir_x[i];
                    int ny = y + dir_y[i];
                    
                    if(nx>=0 && ny>=0 && nx<m && ny<n && maze[nx][ny]=='.'){
                        
                        if(nx==0 or nx==m-1 or ny==0 or ny==n-1) 
                            return steps;
                        
                        q.push({nx,ny});
                        maze[nx][ny]='+';
                    }
                }
            }
        }
        return -1;
    }
};