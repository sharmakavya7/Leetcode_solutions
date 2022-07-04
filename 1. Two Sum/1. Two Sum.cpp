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
    vector<int> twoSum(vector<int>& nums, int target) {               
        
        unordered_map<int,int>ans;
        //if(nums[i]<target) {
        for (int i = 0; i < nums.size(); i++) {
            
            if (ans.find(target - nums[i]) != ans.end()) { 
                
                return {ans[target - nums[i]], i};        //map use kia h but insertion nhi kia..why?
            }                                             //cz pair return krna tha to humne seedha 2 ele daalke return kr dia
            //ans.push_back(i); 
            //number was not found. Put it in the map.
            ans[nums[i]] = i;
        }
    return { };
    }
};