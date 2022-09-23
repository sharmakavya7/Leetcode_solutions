class Solution {
public:
    // TC: O((n+k) logn)
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>maxh;
        
        for(int i:piles) {
            maxh.push(i);
        }
        
        while(k && !maxh.empty()) {
            int top = maxh.top();
            maxh.pop();
            top-=(top/2);
            maxh.push(top);
            k--;
        }
        
        int stones=0;
        while(!maxh.empty()) {
            stones+=maxh.top();
            maxh.pop();
        }
        return stones;
    }
};