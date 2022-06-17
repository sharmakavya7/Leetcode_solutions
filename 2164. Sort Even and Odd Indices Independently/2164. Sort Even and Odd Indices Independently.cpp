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
    vector<int> alternateMerge(vector<int> arr1, vector<int> arr2, int n1, int n2, vector<int> arr3)
    {
        int i = 0, j = 0, k = 0;

        // Traverse both array
        while (i<n1 && j <n2)
        {
            arr3[k++] = arr1[i++];
            arr3[k++] = arr2[j++];
        }

        // Store remaining elements of first array
        while (i < n1)
            arr3[k++] = arr1[i++];

        // Store remaining elements of second array
        while (j < n2)
            arr3[k++] = arr2[j++];
        
        return arr3;
    }
    
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>num1;
        vector<int>num2;
        //vector<int>ans;
        // for(int i=0; i<nums.size(); i=i+2) {
        //     num1.push_back(nums[i]);
        // }
        // for(int i=1; i<nums.size(); i=i+2) {
        //     num2.push_back(nums[i]);
        // }
        for(int i=0; i<nums.size(); i++) {
            if(i%2==0) {
                num1.push_back(nums[i]);
            }
            else num2.push_back(nums[i]);
        }
        sort(num1.begin(),num1.end());
        sort(num2.begin(),num2.end(),greater<int>());
        //nums.clear();
        return alternateMerge(num1,num2,num1.size(),num2.size(),nums);
    }
};