class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int small = INT_MAX;
        int large = INT_MAX;
        // Hum yha pe do variable liye hai small and large jismei hum extreme large number daal diye
        for(int i=0; i<n; i++) {
            // ismei sb se small number save ho jayega 
            if(nums[i] <= small) {
                small = nums[i];
            }
            // ismei loop run ke baad small se bda number save hoga
            else if(nums[i] <= large) {
                large = nums[i];
            }
            // And agar large se bda v koi number hoga to ye true return kr dega
            else
                return true;
        }
            return false;
    }
};