class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        unordered_map<long long,long long> mpp;
        for(int i=0;i<n;i++) {
            if(mpp[edges[i]]==0) {
                mpp[edges[i]]=i;
            }else {
                mpp[edges[i]]= (long long)(mpp[edges[i]]+i);
            }
        }
        long long maxi =INT_MIN;
        long long ans =INT_MAX;
        for(auto i: mpp) {
           // cout<<i.first<<" "<<i.second<<" "<<endl;
            if(i.second >= maxi) {
                maxi = i.second;
               // ans = min(ans,i.first);
            }
        }
        for(auto it: mpp) {
            if(it.second == maxi) {
                ans = min(ans,it.first);
            }
        }
        return ans;
    }
};