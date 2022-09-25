class Solution {
public:
    void BSlast(vector<int>& nums, int start, int end, int res, int target, vector<int>&ans) {
        while(start<=end) {
            int mid = start + (end-start)/2;
            cout<<mid<<endl;
            if(nums[mid]==target) {
                res = mid;                      // res found so seach to its right side only
                start = mid+1;   //TURNING POINT // cz rt side me we have greater elements 
            }                             // and last occurrence ke hone ki chnaces wahi h
            else if(target > nums[mid]) {
                start = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        ans.push_back(res);
    }
    void BS1(vector<int>& nums, int start, int end, int res, int target, vector<int>&ans) {
        while(start<=end) {
            int mid = start + (end-start)/2;
            if(nums[mid]==target) {
                res = mid;                       // res found so seach to its left side only
                end = mid-1;   //TURNING POINT   // cz left side me we have smaller elements 
            }                              // and 1st occurrence ke hone ki chnaces wahi h
            else if(target > nums[mid]) {
                start = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        ans.push_back(res);
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        BS1(nums, 0, nums.size()-1, -1, target, ans);
        BSlast(nums, 0, nums.size()-1, -1, target, ans);
        return ans;
    }
};