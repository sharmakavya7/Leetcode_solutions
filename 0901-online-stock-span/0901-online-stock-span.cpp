class StockSpanner {
public:
    stack<int>st;   // store the indices of all the previous elements
    vector<int>stocks;
    StockSpanner() {
        
    }
    int i = 0;
    int next(int price) {
        // next greater to left
        stocks.push_back(price);
        int ans=0;   

        while(!st.empty() && price>=stocks[st.top()]) {
            st.pop();
        }
        if(st.empty()) ans = i+1;
        else ans = i - st.top();
        // ans = st.empty() ? (i+1) : (i - st.top());
        st.push(i);
        i++;

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */