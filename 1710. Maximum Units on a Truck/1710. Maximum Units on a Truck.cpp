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
        int ans=0;
        int tsize = truckSize;
        int i=0;
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, vector<int>& b) {
                return b[1]<a[1];
            });
        for(int i=0; i<boxTypes.size(); i++) {
            if(tsize < boxTypes[i][0]) {
                return ans + (tsize*boxTypes[i][1]);
            }
            ans+=boxTypes[i][0]*boxTypes[i][1];
            tsize -= boxTypes[i][0];
            if(tsize==0) {
                break;
            }
        }
        return ans;
    }
};
