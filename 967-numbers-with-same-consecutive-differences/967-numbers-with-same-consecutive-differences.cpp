class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        for (int i = 2; i <= n; ++i) {
            vector<int> num;
            for (int x : nums) {
                int y = x % 10;
                if (y + k < 10) {
                    cout<<x * 10<<"+"<< y + k <<"="<<  x * 10 + y + k<<" ";
                    num.push_back(x * 10 + y + k);
                }
                // cout<<endl;
                if (k > 0 && y - k >= 0) {
                    cout<< x * 10<<"+"<<  y - k << "=" << x * 10 + y - k<<" . ";
                    num.push_back(x * 10 + y - k);
                }
            }
            nums = num;
        }
        
        return nums;
        
        
        
        
        
//         vector<pair<int,int>>possible;
//         for(int i=1; i<=9; i++) {
//             if(i+k <= 9) {
//                 possible.push_back({i, i+k});
//             }
//         }
//         int num = 0;
//         bool flag = true;
//         for(auto [k,v]:possible) {
//             cout<<k<<","<<v<<" ";
            
//             for(int i=1; i<pow(10,n); i*=10) {
//                 num += (flag) ? k*i : v*i;
//                 flag = !flag;
//             }
//             ans.push_back(num);
//             k = v;
//         }
        
//         cout<<endl;
//         for(auto t:ans) cout<<t<<" ";
        
//         return ans;
    }
};