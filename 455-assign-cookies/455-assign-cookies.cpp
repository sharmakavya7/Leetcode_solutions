class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size();
        int m = s.size();

        int i = 0, j=0;
        while(i<n && j<m){
            if(s[j]>=g[i])
                i++; // when the child get the cookie, foward child by 1
            j++;
        }
        return i;
        
        
        // unordered_map<int,int>mp;   // storing size
        
        // for(auto i:s) {
        //     mp[i]++;
        // }
        // int cnt=0;
        // for(int i=0; i<g.size(); i++) {
        //     if(mp[g[i]]>0) {
        //         cnt++;
        //         mp[g[i]]--;
        //     }
        // }
        // return cnt;
    }
};