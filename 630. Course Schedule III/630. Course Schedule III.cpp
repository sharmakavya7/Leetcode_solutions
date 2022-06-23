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
    // bool ststic cmp(int& a, int& b) {
    //     return a[1] < b[1];
    // }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        int sum = 0;
        for(auto &i : courses) {
            sum += i[0];
            pq.push(i[0]);
            if (sum > i[1]) {
                sum -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};