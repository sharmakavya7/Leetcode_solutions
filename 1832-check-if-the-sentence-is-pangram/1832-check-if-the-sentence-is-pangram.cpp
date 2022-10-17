class Solution {
public:
    bool checkIfPangram(string sentence) {
        // string s = "abcdefghijklmnopqrstuvwxyz";
        // sort(sentence.begin(), sentence.end());
        set<char>st;
        for(int i=0; i<sentence.size(); i++) {
            st.insert(sentence[i]);
        }
        if(st.size()==26) {
            return true;
        }
        return false;
    }
};