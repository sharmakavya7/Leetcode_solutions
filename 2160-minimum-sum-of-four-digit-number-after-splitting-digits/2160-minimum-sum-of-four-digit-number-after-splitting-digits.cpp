class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        // int i=0, j=s.size()-1;
        int sum=0;
        sum = ((s[0]-48)*10 + (s[3]-48) + (s[1]-48)*10 + (s[2]-48) );
        return sum;
    }
};