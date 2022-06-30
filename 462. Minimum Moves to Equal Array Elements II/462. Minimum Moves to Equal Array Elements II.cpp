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
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n==1 || n==0) {
            return 0;
        }
        // find mid element
        int mid = nums[n/2];
        cout<<mid<<endl;
        int sum=0;
        for(auto i=0; i<n; i++) {
            int diff=abs(nums[i]-mid);
            if(diff!=0)
            sum+=diff;
        }
        return sum;
    }
};