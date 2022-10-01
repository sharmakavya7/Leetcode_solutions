class Solution {
public:
    
    bool isValid(char a,char b){
        return a == '1'||(a == '2' && b <='6');
    }
    
    bool isValid(char a){
        return a != '0';
    }
    
    int numDecodings(string s) {
        
    int n = s.size();
    if ( n == 0 || s[0] == '0' ) return 0;
    if ( n == 1 ) return 1;
    int prev_ways = 1;   // upto index i-1
    int cur_ways = 1;          // upto index i (cur index)
    int num;             // temp to store i ways till cur index
        
    for ( int i = 1; i < n; i++ ) {
        
        num = 0;
        if ( !isValid(s[i]) && !isValid(s[i-1], s[i]) ) 
            return 0;
        
        if ( isValid(s[i]) )
            num = prev_ways;
        
        if ( isValid(s[i-1], s[i]) ) 
            num += cur_ways;
        
        cur_ways = prev_ways;
        prev_ways = num;
    }
    return num;
}
    
};