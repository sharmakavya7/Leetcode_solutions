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

class NumArray {
public:
    vector<int>vec;
    int sum=0;
    NumArray(vector<int>& nums) {
        vec = nums;
        for(auto i:nums) {
            sum+=i;
        }
    }
    
    void update(int index, int val) {
        sum-=vec[index];
        vec[index] = val;
        sum+=val;
    }
    
    int sumRange(int left, int right) {
        int ans=sum;
        for(int i=0; i<left; i++) {
            ans-=vec[i];
        }
        for(int i=right+1; i<vec.size(); i++) {
            ans-=vec[i];
        }
        return ans;
    }
};