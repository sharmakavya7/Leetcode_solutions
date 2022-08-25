class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0) {
            return false;
        }
        if(hand.size()<groupSize) {
            return false;
        }
        sort(hand.begin(), hand.end());
        map<int,int>mp;
        for(int i:hand) {
            mp[i]++;
        }
        // for(auto i=mp.begin(); i!=mp.end(); i++) {   
        // for(int i=1; i<mp.size(); i++) {
            
        while(mp.size()!=0) {
            // cout<<mp[i]<<" ";
            auto cur = mp.begin()->first;
            for(int i=0; i<groupSize; i++) {
                
                if(mp[cur+i]==0) {
                    return false;
                }
                else if(--mp[cur+i]<1) {
                    mp.erase(cur+i);
                }
                // mp[cur+i]--;
            }
        }
        return true;
    }
};