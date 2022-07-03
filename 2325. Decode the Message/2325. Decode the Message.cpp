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
    string unique(string s)
    {
        string str;
        int len = s.length();
        for(int i = 0; i < len; i++) {
            char c = s[i];
            auto found = str.find(c);
            if (found == std::string::npos) {
                str += c;
            }
        }
        cout<<str<<"str"<<endl;
        return str;
    }
  
    string decodeMessage(string key, string message) {
        unordered_map<char, char>mp;
        int i=0; 
        string str="";
        remove(key.begin(), key.end(), ' ');
        string res = unique(key);
        for(char c = 'a'; c <= 'z'; c++) {
            mp[res[i++]]=c;
        }
        for(auto it=mp.begin(); it!=mp.end(); it++) {
            cout<< it->first<< " "<<it->second<<endl;
        }
        for(int i = 0; i < message.size(); i++) {
            if(message[i]!=' ') {
                str+=mp[message[i]];                           // this is it!!!!!!!!!!!!!!!!!!
            }
            else {
                str+=' ';
            }
        }
        return str;
    }
};