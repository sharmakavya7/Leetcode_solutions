class Solution {
public:
    // Intuition
    // str = "231"
    // s[0] - '0' + s[1] - '0' + s[2] - '0'
    //   2*100   +    3*10   +      1*1
    int myAtoi(string s) {
        // int ans = 0;
        // bool flag = true;
        // int cnt=0;
        
        size_t index = s.find_first_not_of(' ');
        if(index == string::npos) return 0;
        
        long result = 0;
        bool flag = false;
        if(s[index] == '-') {
            flag = true;
            index++;
        } else if(s[index] == '+') {
            index++;
        }
        for(int i=index; i<s.size(); i++) {
            if(isdigit(s[i])) {
                result = result * 10 + (s[i]-'0');
                if(flag && -result <= INT_MIN) return INT_MIN;
                if(!flag && result >= INT_MAX) return INT_MAX;
            } else {
                break;
            }
        }
        if(flag) result = -result;
        
        return int(result);
        
//         for(int i=0; i<s.size(); i++) {
//             while(s[i]==' ') i++;
//             if(s[i] == '-' || (s[i]>= '0' && s[i]<='9') && (cnt==0||cnt==1)) {
//                 if(s[i]=='-') {
//                     flag = false;
//                     cnt++;
//                     continue;
//                 }
                
//                 else if(cnt>1) return -1;
//                 else {
//                     if(isdigit(s[i])) {
//                         int t = s[i]-48;
//                         ans = 10*ans + t; 
//                     }
//                     else break;
//                 }
//             }
//             // else return -1;
//         }
//         if(flag == false) {
//             ans -= (2*ans);
//         }
        // return ans;
    }
};