class Solution {
public:
    string largestPalindromic(string num) {
        
        vector<int>count(10);
        
        for(auto i:num) {
            count[i-'0']++;
        }
        
        string leftpartition, rightpartition;
        
        for (int i: num) {
            for (int j = 9; j >= 0; j--)  {
                if (count[j] > 1 && (j > 0 || leftpartition.size())) {
                    leftpartition += '0' + j;
                    rightpartition += '0' + j;
                    count[j] -= 2;
                    break;
                }
            }
        }
        
        for(int i=9; i>=0; i--) {
            if(count[i]) {
                leftpartition += i+'0';
                break;
            }
        }
        reverse(rightpartition.begin(), rightpartition.end());
        return leftpartition+rightpartition;
        
        
        
//         map<char,int>mp;
//         sort(num.begin(),num.end());
//         string ans="";
        
//         for(auto c:num) {
//             mp[c-'0']++;
//         }
//         for(auto i:num) {
//             cout<<i<<" ";
//         }
//         cout<<endl;
//         for(auto i:mp) {
//             cout<<i.first<<":"<<i.second<<" ";
//         }
//         cout<<endl;
//         for (auto it = mp.rbegin(); it != mp.rend(); it++) {
//             int t = it->second;
//             // we need at least a frequency of 2
//             if(t>=2) {
//                 ans += string(t/2, it->first+'0');
//             }
//         }
        
//         // we can put some zeros as well for cases like 0099 -> 9009
        
        
        // return ans;
    }
};