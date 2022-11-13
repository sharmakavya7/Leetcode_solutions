class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        stringstream str(s);
        //isi word ko vector me store krna
        string word;
        
        while(str>>word) {
            v.push_back(word);
        }
        reverse(v.begin(), v.end());
        
        string ans;
        for(auto it :v) {
            ans = ans + " " + it;
        }
        ans.erase(0, 1);  //impppp
        return ans;
    }
};

//reverse the whole string then reverse all the whole words
//         reverse(s.begin(), s.end());
//         int j=0, l=0;
//         int res = 0;
//         for(int i=0; i<s.size(); i++) {
//             while(i<s.size() && s[i] == ' ') 
//                 i++;                        // skip spaces in front of word(bfr 1st word too)
            
//             // if(res) {
//             //     s[j] = ' ';
//             //     j++;
//             // }
//             j = i+1;
//             while(j<s.size() && s[j]!=' ') {  //words iterate
//                 j++;
//             }
            
//         }




// sstream method:
// istringstream iss(s);
//     string str ;

//      // Get the word from the istringstream
//     iss>>s;
//     while(iss>>str) {
//         s = str + " " + s;
//         if(s[0] == ' ') {
//             s = "";
//         }
//     }
//     return s;