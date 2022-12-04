class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();

        vector<long long>pref(n,0);
        long long val = 0;

        for( int i = 0 ; i < n ; i++ ){
            val += nums[i];
            pref[i] = val;
        }

        int ans = INT_MAX;
        int index = -1;
        for( int i = 0 ; i < n ; i++ ){
            int t1 = pref[i]/(i+1);
            
            int t2 = 0;
            if(n-i-1!=0) {
                t2 = (val - pref[i])/(n-i-1);
            }
            
            if(abs(t1 - t2) < ans) {
                ans = abs(t1 - t2);
                index = i;
            }
        }

        return index;
    }
};