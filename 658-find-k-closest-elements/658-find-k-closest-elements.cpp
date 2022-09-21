class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>maxh;  // (absDiff, actual val)
        
        for(int i=0; i<arr.size(); i++) {
            int absDiff = abs(arr[i] - x);
            maxh.push({absDiff, arr[i]});
            
            while(maxh.size()>k) {
                maxh.pop();
            }
        }
        vector<int>ans;
        while(!maxh.empty()) {
            auto t = maxh.top().second;
            maxh.pop();
            ans.push_back(t);
        }        
        sort(ans.begin(),ans.end());
        return ans;
    }
};