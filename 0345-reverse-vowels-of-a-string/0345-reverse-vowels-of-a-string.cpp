class Solution {
public:
    bool isVowel(char ch) {     
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'
           ||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U') {
            
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        // for(int i=0; i<s.size(); i++) {
        int i=0, j=s.size();
        while(i<j) {
            while (i < j && !isVowel(s[i])) ++i;
            while (i < j && !isVowel(s[j])) --j;
            swap(s[i++], s[j--]);
        }
        return s;
    }
};