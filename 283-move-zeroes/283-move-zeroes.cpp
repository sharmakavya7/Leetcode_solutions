class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        while (k < n) {
            if (nums[k] == 0) {
                break;
            } 
            else {
              k = k + 1;
            }
        }
        //finding zeros and immediate non-zero elements and swapping them
        int i = k, j = k + 1;

        while (i < n && j < n) {
            if (nums[j] != 0) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;

            }

            j++;

        }
    }
};