class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>jeeto_bhyi, better_luck;
        int n = matches.size();
        for(int i=0; i<n; i++) {
            int jeeta = matches[i][0];
            int haara = matches[i][1];
            
            jeeto_bhyi[jeeta]++;
            better_luck[haara]++;
        }
        vector<vector<int>>ans;
        vector<int>chotu1, chotu2;
        for(auto i : jeeto_bhyi) {
            if(better_luck[i.first] == 0) {
                // ans[0].push_back(i.first);
                chotu1.push_back(i.first);
            }
        }
        for(auto i : better_luck) {
            if(i.second == 1) {
                // ans[1].push_back(i.first);
                chotu2.push_back(i.first);
            }
        }
        sort(chotu1.begin(), chotu1.end());
        sort(chotu2.begin(), chotu2.end());
        ans.push_back(chotu1);
        ans.push_back(chotu2);
        return ans;
    }
};

/*
for(auto i = 0; i < better_luck.size(); i++) {
            if(better_luck.find(jeeto_bhyi[i]) != better_luck.end()) {
                continue;
            } else {
                ans[0].push_back(jeeto_bhyi[i]);
            }
        }
*/