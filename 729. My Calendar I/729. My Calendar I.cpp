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
class MyCalendar {
public:
    map<int, int> events;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if (events.size() == 0) {
            events[start] = end;
            return true;
        }
        auto p = events.upper_bound(start);
        if (p != events.end() && end > p->first)
            return false;
        if (p != events.begin() && start < prev(p)->second)
            return false;
        events[start] = end;
        return true;
    }
         
};