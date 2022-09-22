class Solution {
public:
    string reverseWords(string s) {
        // inplace
        int i=0; 
        for(int j=0; j<s.size(); j++) {
            if(s[j]==' ') {
                reverse(s.begin()+i, s.begin()+j);
                i = j+1;
            }
        }
        // for the last word
        reverse(s.begin() + i, s.end());
        return s;
    }
};

// BRUTE:
/*
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

*/