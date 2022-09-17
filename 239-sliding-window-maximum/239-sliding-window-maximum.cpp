class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0, j=0;
        vector<int>ans;
        priority_queue<pair<int,int>> maxh;
        while(j<nums.size()){
              maxh.push({nums[j],j});
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                // remove all the elments which are not in the current window
                while(!maxh.empty() && maxh.top().second<i) {
                    maxh.pop();
                }
                j++;i++;
                ans.push_back(maxh.top().first);
            }
            
        }
        return ans;
    }
};

// the basic idea is that we are keeping the size of the heap as at most k by removing the elements that are out of the k-size window