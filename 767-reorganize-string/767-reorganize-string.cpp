class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(auto c:s) {
            mp[c]++;
        }
        priority_queue<pair<int,char>>maxh;
        for(auto [k,v]:mp) {
            maxh.push({v,k});
        }
        string res="";
        pair<int, char>mostFreq, secMost;
        int cnt=0;
        while(maxh.size()>1) {
            mostFreq = maxh.top();
            maxh.pop();
            secMost = maxh.top();
            maxh.pop();
            
            res+=mostFreq.second;
            res+=secMost.second;
            
            secMost.first--;
            mostFreq.first--;
            
            if(mostFreq.first>0) {
                maxh.push(mostFreq);
            }
            if(secMost.first>0) {
                maxh.push(secMost);
            }
            
        }
        if(!maxh.empty()) {
            if(maxh.top().first>1) {
                return "";
            }
            else if(maxh.top().first==0) {
                return res;
            }
            else {
                res+=maxh.top().second;
            }
        }
        
        return res;
    }
};