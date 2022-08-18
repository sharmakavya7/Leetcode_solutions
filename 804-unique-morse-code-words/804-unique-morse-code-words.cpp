class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        // unordered_map<char,string>mp = {{'a',".-"},{'b',"-..."},{'c',"-.-."},{'d',"-.."},{'e',"."}, {'f',"..-."} ,{'g',"--."},{'h',"...."},{'i',".."},{'j',".---"},{'k',"-.-"}, {'l',".-.."}, {'m',"--"},{'n',"-."}, {'o',"---"}, {'p',".--."}, {'q',"--.-"}, {'r',".-."}, {'s',"..."}, {'t',"-"}, {'u',"..-"},{'v',"...-"}, {'w',".--"},{'x',"-..-"}, {'y',"-.--"}, {'z',"--.."}};
        vector<string>v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string>st;
        
        for(auto word:words) {
            
            string str = "";
            
            for(auto ch:word) {
                
                str+=v[ch - 97];
            }
            st.insert(str);
        }
        return st.size();
    }
};