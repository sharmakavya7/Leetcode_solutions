class Solution {
public:
    string decodeAtIndex(string s, int k) {
        size_t decodedSize=0;        // change int to size_t 
        int N = s.size();
        // Find size = length of decoded string
        // for (auto a : s) {
        for(int i=0; i<s.size(); i++) {
            if (isdigit(s[i]))
                decodedSize *= (s[i] - '0');
            else
                decodedSize++;
        }
        string res="";
        // Then we go back from the decoding position.
        for (int i = s.size()-1; i >= 0; i--) {
            
            // if it's S[i] = digit, then N /= d before repeat and K %= N is what we want
            
            k %= decodedSize;
            
            // If it's S[i] = character, we return c if K == 0 or K == N
            if (k == 0 && !isdigit(s[i]) )
                return (string)"" + s[i];
            
            if (isdigit(s[i]))
                decodedSize /= s[i]-'0';
            else
                decodedSize--;
        }
        
        return res.substr(k,1);
        
        // string popped;
        // for(int i=0; i<s.size(); i++) {
        //     if(s[i]>=97 && s[i]<=122) {
        //         st.push(s[i]);
        //     }
        //     else if(s[i]>=50 && s[i]<=57) {
        //         int digit = (int)(s[i]);
        //         while(!st.empty()) {
        //             popped.push_back(st.top());
        //             st.pop();
        //         }
        //         reverse(popped.begin(),popped.end());
        //         for(int j=0; j<digit; j++) {
        //             decoded+=popped;        // leetleet
        //         }
        //     }
        //     for(int l=0; l<decoded.size();l++)
        //         cout<<decoded[l];
        //     cout<<endl;
        // }
        // // string ans = decoded[k];
        // return decoded[k];
    }
};