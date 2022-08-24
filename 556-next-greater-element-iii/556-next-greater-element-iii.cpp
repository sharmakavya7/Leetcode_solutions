class Solution {
public:
    // next_permutation implementation
//     bool nextPermutation(string& nums) {
//         int i = nums.size()-1;
//         while (i > 0 && nums[i-1] >= nums[i]) 
//              i--;
//         if (i == 0) return false;
        
//         int j = nums.size()-1;
//         while (j > 0 && nums[j] <= nums[i-1]) j--;
//         swap(nums[j], nums[i-1]);
//         reverse(nums.begin()+i, nums.end());
//         return true;
//     }
    
    int nextGreaterElement(int n) {
        string s = to_string(n);
        // for(auto c:s) cout<<c<<" ";
        next_permutation(s.begin(), s.end());
        auto num = stol(s);
        // cout<<num<<endl;
        if(num <= n || num > INT_MAX) {
            return -1;
        }
        else return num;
    }
};