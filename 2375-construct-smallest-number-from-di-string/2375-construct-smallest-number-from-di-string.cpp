class Solution {
public:
    string smallestNumber(string pattern) {
        int i=0;
        int j=0;
        // int cnti = 0;
        int cntd = 0;
        int num = 1;
        string ans;
        for(int i=0;i<pattern.size()+1;i++){
            ans += to_string(i+1);
        }
        i=0;
        // while(i<pattern.size(); i++) {
        for(int i=0; i<pattern.size(); i++) {
            j = i;
            while(j<pattern.size() && pattern[j]=='D')
                j++;
            
            int cntd = j-i;
            cout<<cntd<<" ";
            if(cntd!=0){
                reverse(ans.begin()+i,ans.begin()+j+1);
            }
            i=j;
        }
        return ans;

    }
};