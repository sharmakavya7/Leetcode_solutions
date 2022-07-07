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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //also check out GAP ALGO from GFG 
        int a=m-1;
        int b=n-1;
        int i=m+n-1;    // calculate the index of the last element of the merged array
        
        // go from the back by A and B and compare and put to the A element which is larger
        
        while(a>=0 && b>=0){
            
            if(nums1[a]>nums2[b])   
                nums1[i--]=nums1[a--];
            
            else            
                nums1[i--]=nums2[b--];
        }
        
        // if B is longer than A just copy the rest of B to A location, otherwise no need to do anything
        
        while(b>=0)         
            nums1[i--]=nums2[b--];
    }
};