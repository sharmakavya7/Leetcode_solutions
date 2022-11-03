class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;  // [lc : 1, cl : 1, gg : 1] 
        
        for(auto i:words) {
            mp[i]++;
        }
        
        int cnt=0;
        bool flag = true;
        
        for(auto word:words) {
            
            string temp = word;   
            reverse(temp.begin(), temp.end());
            
            // word->lc temp->cl 
            if(temp!=word && mp[temp]>0 && mp[word]>0) {  // if both exixts in map
                mp[temp]--;
                mp[word]--;
                cnt+=4;
                // cout<<"kk"<<" ";
            }
            // word-> gg temp-> gg  (string contains 2 same lettered word, ie, "gg", "gg")
            else if(temp==word && mp[word]>1) {
                mp[word]-=2;
                cnt+=4;
                // cout<<"ll"<<" ";
            } 
            // word-> gg temp->gg (string contains only 1 same lettered word, ie, "gg")
            else if(temp==word && mp[word]>0 && flag==true) {
                mp[word]--;
                cnt+=2;
                flag=false;
                // cout<<"kitni baar?"<<" ";
            }
        }
        return cnt;
    }
};