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
class WordFilter {
public:
    unordered_map<string, int> mp;
    WordFilter(vector<string>& words) {
        int n = words.size();
        for(int i = 0; i < n;i++)
        {
            int len = words[i].length();
            string p = "" , s = "";
            for(int j = 0;j<=len;j++)
            {
                s = "";
                for(int k = len-1;k>=0;k--)
                {
                    s = words[i][k] + s;
                    mp[p + '|' + s] = i;
                }
                p += words[i][j];
            }
        }
    }
    
    int f(string prefix, string suffix) {
        if(mp.find(prefix + '|' + suffix) == mp.end())
        {
            return -1;
        }
        return mp[prefix + '|' + suffix];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */