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
    int longestConsecutive(vector<int>& nums) { 
        
        if(nums.size()==1) return 1;
        if(nums.size()==0) return 0;
        int cnt=1;  // current streak
        sort(nums.begin(), nums.end());
        int maxi=0;  // longest streak
        for(int i=1; i<nums.size(); i++) {

            if(nums[i] == nums[i - 1]) continue;  // this is important!!!!!

            else if(nums[i] - nums[i-1] == 1){
                cnt++;
            }
            else {
                cnt=1;
            }
            maxi = max(cnt, maxi);  // isko if ke bhr likhna tha!!!!!
            
            // else maxi = max(maxi, cnt), cnt = 1;
        }
        return max(maxi,cnt);     // yaha max return krna thaaa!!!!
        
        // SET SOLUTION
//         unordered_set<int>set;
//         for(auto i:nums) {
//             set.insert(i);
//         }
        
//         int longStreak = 0;
        
//         for(auto i : nums) {
//             if(!set.count(i-1)) {
//                 int cur = i;
//                 int curStreak = 1;
                
//                 while(set.count(cur+1)) {
//                     curStreak++;
//                     cur++;
//                 }
//                 longStreak = max(longStreak, curStreak);
//             }
//         }
//         return longStreak;
       
    }
};