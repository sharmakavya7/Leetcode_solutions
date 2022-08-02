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
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // sorts the 2D array in decreasing order of their seconds
        // t = [[5,10],[2,5],[4,7],[3,9]]
        // after sorting: [[5,10],[3,9],[4,7],[2,5]]
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>&a, vector<int>&b) {
            return a[1]>b[1];
        });
        // cout<<boxTypes[0][0]<<endl;
        int cntBox = 0;
        int ans = 0;  // total number of units
        
        for(int i=0; i<boxTypes.size(); i++) {
            // cntBox+=boxTypes[i][0];
            if(truckSize > cntBox+boxTypes[i][0]) {
                ans+=(boxTypes[i][0]*boxTypes[i][1]);
                cntBox += boxTypes[i][0];
            }
            else {
                // cout<<"yaha pe cnt: "<<cntBox<<" ";
                int temp = truckSize-cntBox;
                ans+=(temp*boxTypes[i][1]);
                break;
            }
        }
        return ans;
    }
};