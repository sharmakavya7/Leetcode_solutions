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
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int sum = 0;
        if(nums.size() == 0) 
            return 0;
        
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] < 0 && cnt < k) {
                nums[i] = -nums[i];
                ++cnt;
            }
        }
        sort(nums.begin(), nums.end());
        k -= cnt;
        if(k % 2) {
            nums[0] = -nums[0];
        }
        return accumulate(nums.begin(), nums.end(),0);
    }
};
//          if(k==1) {
//              int mini = *min_element(nums.begin(),nums.end());
//              // mini = -mini;
//              sum = accumulate(nums.begin(), nums.end(),0);
//              sum-=2*mini;
//              return sum;
//          }
//          sort(nums.begin(),nums.end());
//         // sum = accumulate(nums.begin(), nums.end(),0);
                
//         for(int i=0; i<k; i++) {
//             // flip all the negative numbers till k<0
//             while(k>0) {
//                 if(nums[i]<0) {
//                     nums[i] = -nums[i];
//                     k--;
//                 }
//                 else break;
//                 i++;
//             }
//             if(k%2==0) {
//                 return accumulate(nums.begin(), nums.end(),0);
//             }
//             else if(k%2!=0) {
//                 nums[i] = -nums[i];
//                 k--;
//                 int mini = *min_element(nums.begin(), nums.end());
//                 sum = accumulate(nums.begin(), nums.end(),0) -  mini* 2;
//             }
//             else if(nums[i]==0) {
//                 k = 0;
//             }
//             if(k==0) break;
//         }
//         // sum = accumulate(nums.begin(), nums.end(),0);
//         return sum;