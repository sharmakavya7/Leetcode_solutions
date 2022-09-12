class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int k=1;
        // int i=1;
        int ans = 1;    // answer pointer
        for(int i=1; i<nums.size(); i++) { 
            
            if(nums[i-1]==nums[i]) {
                k++;
            }
            else k=1;
            
            if(k<=2) nums[ans++] = nums[i];
        }
        return ans;
    }
};