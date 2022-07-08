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
    bool isHappy(int n) {
        
        unordered_map<int,int> tmp;
        
        while(n != 1)
        {
            if(tmp[n] == 0)
                tmp[n]++;
            else
                return false;
            
            int sumsq=0;
            
            while (n != 0) {
                
                // int r = ;
                sumsq += pow(n % 10,2);
                n = n / 10;
            }
            
            n = sumsq;
        }
        return true;
    }
};