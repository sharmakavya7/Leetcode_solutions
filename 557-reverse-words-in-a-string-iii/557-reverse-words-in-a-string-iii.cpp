class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string temp = "";
        for(int i=0; i<s.size(); i++) {
            // string temp = "";
            if( s[i]!=' ') {
                temp+=s[i];
                // i++;
                // cout<<temp[i]<<" ";
            }
            else {
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans+=' ';
                temp = "";
            }
            
        }
        reverse(temp.begin(),temp.end());
        ans+=temp;
        return ans;
    }
};