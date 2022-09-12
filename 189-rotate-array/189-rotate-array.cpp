class Solution {
public:    
    void rotate(vector<int>& nums, int k) {
        //nums.end()-k th index pe jake, vo sare elements starting me daldenge
        int n = nums.size();
        k = k%n;
        // Reverse the first n - k numbers.
        reverse(nums.begin(), nums.end()-k);

        // Reverse tha last k numbers.
        reverse(nums.end()-k , nums.end());
        
        // Reverse all the numbers.
        reverse(nums.begin(), nums.end());
    }
};


