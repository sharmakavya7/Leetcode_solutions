class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>maxh;
        
        for(int i:piles) {
            maxh.push(i);
        }
        
        while(k && !maxh.empty()) {
            int top = maxh.top();
            // cout<<"before: "<<top<<" ";
            maxh.pop();
            top-=(top/2);
            // cout<<"after: "<<top<<" ";
            maxh.push(top);
            k--;
        }
        
        int stones=0;
        while(!maxh.empty()) {
            // cout<<stones<<" ";
            stones+=maxh.top();
            maxh.pop();
        }
        return stones;
    }
};