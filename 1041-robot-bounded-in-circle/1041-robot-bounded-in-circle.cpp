class Solution {
public:
    bool isRobotBounded(string instructions) {
        int i=0; // +ve x axis
        int j=0; // +ve y axis
        int idx=0;
        int t = 4; // run path 4 times
        int dir= 0;   // 0->'north'; 1->'west'; 2->'south'; 3->'east'
        for (int idx = 0; idx < instructions.size(); ++idx) {
            if(instructions[idx]=='G') {
                if(dir == 0){
                    j++;
                }
                else if(dir == 1) {
                    i--;
                }
                else if(dir == 2) {
                    j--;
                }
                else if(dir == 3) {
                    i++;
                }
            }
            else if(instructions[idx]=='L') {
                if(dir == 3) {
                    dir = 0;
                }
                else dir+=1;
            }
            else if(instructions[idx]=='R') {
                if(dir==0) {
                    dir = 3;
                }
                else dir-=1;
            }
        }
        cout<<i<<" "<<j<<" "<<dir;
        if(dir!=0 || (i==0 && j==0)) {
                return true;
            }
        return false;
    }
};