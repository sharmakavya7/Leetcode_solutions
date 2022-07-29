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

class Solution {
public:
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int n = pattern.size();        
        for(auto word : words){
            
            unordered_map<char,char> mp;
            unordered_map<char,char> mp2;
            bool bitch = true; 
            
            for(int i=0;i<n;i++) {
                
                 if(mp.find(pattern[i]) == mp.end() && mp2.find(word[i]) == mp2.end()){
                    mp[pattern[i]] = word[i];
                    mp2[word[i]] =pattern[i];
                }
                else if(mp[pattern[i]] !=  word[i]) {
                    bitch= false; 
                    break;
                }                
                else if(mp2[word[i]] != pattern[i]){
                    bitch= false; 
                    break;
                }   
            }
            if(bitch){
                ans.push_back(word);
            }
        }
        return ans;        
    }
};

