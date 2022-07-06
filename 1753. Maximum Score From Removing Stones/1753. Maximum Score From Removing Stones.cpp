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
    int maximumScore(int a, int b, int c) {
        priority_queue<int>maxh;
        maxh.push(a);
        maxh.push(b);
        maxh.push(c);
        // auto i = maxh.top();
        int i = 1;
        int score = 0;
        while(i) {
            int i = maxh.top();
            maxh.pop();
            
            int j = maxh.top();
            maxh.pop();
            if(i==0 || j==0)
                break;
            i --;
            j --;
            
            score++;
            
            maxh.push(i);
            maxh.push(j);
        }
        return score;
    }
};