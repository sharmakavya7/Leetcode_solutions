#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib> 
#include <string>
#include <map>
#include <climits>
#include <iterator>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

bool compare(string &a,string &b){
    return a.length()>b.length();
}
class Solution {
public:
    
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        string res="";
        res=res+words[0]+"#";
        
        for(int i=1;i<words.size();i++){
            
            int t=res.find(words[i]+"#");
            if(t!=-1)
                continue;
            else
                res+=words[i]+"#";
            
        }
        
        return res.length();
    }
};