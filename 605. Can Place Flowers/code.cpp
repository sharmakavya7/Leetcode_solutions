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
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if (n == 0) return true;
        if (flowerbed.size() == 0) return false;
        if (flowerbed.size() == 1) return flowerbed[0] == 0;
        
        int m = flowerbed.size();
        int i=0;
        while(i<m) {
            if((i==0 ||flowerbed[i-1]==0) && flowerbed[i]== 0 
               && (i==m-1||flowerbed[i+1]==0 )) {
                flowerbed[i] = 1;
                n--;
            }
            if(n==0) {
                return true;
            }
            i++;
        }
        return false;
    }
};