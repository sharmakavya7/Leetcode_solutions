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
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int>reminder(60,0);     
        int cnt=0;
        for(int i=0; i<time.size(); i++) {
            // if(time[i]<60) {
            //     continue;
            // }
            int temp = time[i]%60;     // stores remainder
            if(temp==0) {
                cnt+=reminder[0];
            }
            else {
                cnt+=reminder[60 - temp];
            }
            reminder[temp]++;
        }
        
        return cnt;
        
        // Naive approach
        // int cnt=0;
        // for(int i=0; i<time.size(); i++) {
        //     for(int j=i+1; j<time.size(); j++) {
        //         int sum = time[i]+time[j];
        //         if(sum%60==0) {
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
    }
};