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
        
        // vector<int>nums;         // we can also convert it into a vector and do it
        // while(n!=0) { 
        //     int temp = n%10;
        //     nums.push_back(temp);
        //     n/=10;
        // }
        string s=to_string(n);
        int decrease=s.size();
        for(int i=s.size()-1; i>0; i--) {
            if(s[i]<s[i-1]) {
                decrease = i;   // save kr lenge so that aage '9' wale loop me use hopae
                s[i-1]--;
                // cout<<s[i-1]<<" ";
            }
            cout<<s[i-1]<<" ";
        }
        for(int i=decrease; i<s.size(); i++) {
            s[i] = '9';         // Damnnnnn we have to insert CHARACTER '9' not integer 9!!!!!!
        }
        // for(auto i:nums){
        //     cout<<i<<" ";
        // }
        // convert vector to number:
        // int res = VectorToInt(nums);
        // int ans = 0;
        // for(int i=0;i<nums.size();i++)
        //     ans = ans*10 + nums[i];
        // return ans;
        return stoi(s);
    }
};
