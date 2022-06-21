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
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int overall_mx = 0;
	    int ans = -1, row = 0;
	    for(int i=0; i<arr.size(); i++) {
	        int cur_mx = 0; // row = 0;
	        for(int j=0; j<arr[0].size(); j++) {
	            if(arr[i][j]==1) {
	                cur_mx++;
	                overall_mx = max(overall_mx, cur_mx);
	                
	               // row = j;
	               // if(overall_mx<cur_mx) {
        	       //     overall_mx = cur_mx;
        	       //     ans = row;
        	       // }
	            }
	            else cur_mx = 0;
	        }
	        if(row < cur_mx) {
	            row = cur_mx;
	            ans = i;
	        }
	    }
	    return ans;
	}

};