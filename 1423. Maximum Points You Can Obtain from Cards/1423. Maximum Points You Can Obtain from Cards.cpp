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
    int maxScore(vector<int>& cardPoints, int k) {
        // int i=0, j=cardPoints.size()-1;
        if(k==1) {
            return max(cardPoints[0], cardPoints[cardPoints.size()-1]);
        }
        int sum=0;
        for(int i=0; i<k; i++) {
            sum+=cardPoints[i];
        }
        int cur_best = sum;
        int i = k-1;
        int j = cardPoints.size()-1;
        while(i >= 0) {
        // for(int i = k-1, j = cardPoints.size()-1; i>=0; i--, j--){ // other way
            sum += cardPoints[j] - cardPoints[i];
            cur_best = max(cur_best, sum);
            i--, j--;
        }
        return cur_best;
    } 
};