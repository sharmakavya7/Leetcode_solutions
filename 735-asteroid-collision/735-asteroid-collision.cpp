class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        for(int i=0; i<asteroids.size(); i++) {
            if(asteroids[i]>0 || ans.empty() || ans.back()<0){
                ans.push_back(asteroids[i]);
            }
            else if(ans.back()<=(-asteroids[i])) {
                if(ans.back()<(-asteroids[i])) {
                    i--;
                }
                ans.pop_back();
            }
        }
        return ans;
        // int neg=0, pos=0;
        // for(int i=0; i<asteroids.size(); i++) {
        //     if(asteroids[i]<0) {
        //         neg = i;
        //         pos = i-1;
        //         break;
        //     }
        // }
        // cout<<pos<<" "<<neg<<" ";
        // while(pos>0 || neg<asteroids.size()) {
        //     if(asteroids[pos]>(-asteroids[neg])) {
        //         neg++;
        //     }
        //     if(asteroids[pos]<(-asteroids[neg])) {
        //         pos--;
        //     }
        //     if(asteroids[pos]==(-asteroids[neg])) {
        //         pos--;
        //         neg++;
        //     }
        // }
        // cout<<pos<<" "<<neg<<" ";
        // if(pos>=0) {
        //     for(int i=0; i<=pos; i++) {
        //         ans.push_back(asteroids[i]);
        //     }
        // }
        // if(neg!=asteroids.size()) {
        //     for(int i=neg; i<asteroids.size();i++) {
        //         ans.push_back(asteroids[i]);
        //     }
        // }
        // return ans;
    }
};

// [1,2,3,4,5,-2,-3,-4,-5,-11,-12,-14]
// [4,2,-4,-1,90,-2,-4,-5,-11,-12,-14]
// [-2,-4,-5,6,3,2,7]