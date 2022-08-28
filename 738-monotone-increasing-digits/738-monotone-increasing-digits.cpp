class Solution {
public:
    // int VectorToInt(vector<int> v)
    // {
    //     reverse(v.begin(), v.end());
    //     int decimal = 1;
    //     int total = 0;
    //     for (auto& it : v)
    //     {
    //         total += it * decimal;
    //         decimal *= 10;
    //     }
    //     return total;
    // }
    
    int monotoneIncreasingDigits(int n) {
        
        string s=to_string(n);
        int decrease=s.size();
        for(int i=s.size()-1; i>0; i--) {
            if(s[i]<s[i-1]) {
                decrease = i;   // save kr lenge so that aage '9' wale loop me use hopae
                s[i-1]--;   // Since we want a number smaller than the given one
            }
            cout<<s[i-1]<<" ";
        }
        for(int i=decrease; i<s.size(); i++) {
            s[i] = '9';
        }
        return stoi(s);
    }
};

// int num=0;
//         bool flag = true;
//         string s=to_string(n);
//         for(int i=s.size()-1; i<=0; i++) {
//             if(s[i]<s[i-1]) {
//                 // flag = false;
//                 decrease = i-1;
//             }
//         }

//         int a = s[decrease]-'0';
//         cout<<a-1<<" ";
//         // s[decrease] = to_sting(k);
//         // num = stoi(s);
//         return num;