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

    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0, j=0;
        int n=firstList.size();
        int m=secondList.size();
        if(n==0 || m==0) {
            return {};
        }

        vector<vector<int>>ans;
        while(i<n && j<m) {
            int p = max(firstList[i][0],secondList[j][0]);
            int q = min(firstList[i][1],secondList[j][1]);
            if(p<=q) {
                ans.push_back({p,q});
            }
            if(firstList[i][1]<secondList[j][1]) 
                i++;
            else 
                j++;
        }
        return ans;
    }
};