class MyCalendarThree {
public:
    map<int, int> times;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        times[start]++; 
        times[end]--; 
        int events_on = 0, ans = 0;
        for (pair<int, int> x : times)
            ans = max(ans, events_on += x.second);
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */