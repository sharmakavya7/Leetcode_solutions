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
    int findKthLargest(vector<int>& nums, int k) {
        // int n = nums.size();
        priority_queue<int,vector<int>,greater<int>>minh;
        for(int i :nums) {
            minh.push(i);
            if(minh.size() > k) {
                minh.pop();
            }
        }
        return minh.top();
    }
};