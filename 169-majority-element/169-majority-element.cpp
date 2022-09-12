class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //boyer moore voting algo
        int ansIndex = 0;
        int count = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] == nums[ansIndex]) {
                count++;
            }
            else count--;
            if(count == 0) {
                ansIndex = i;
                count = 1;
            }
        }
        return nums[ansIndex];
    }
};

// unordered_map<int,int>mp;
//         int k = nums.size()/2;
//         int ans = 0;
//         for(int i = 0; i<nums.size(); i++) {
//             mp[nums[i]]++;
//         }
        
//         //vector<int,int>::iterator it;
//         for(auto it = mp.begin(); it!=mp.end(); it++) {
//             if(it->second > k) {
//                 ans = it->first;
//             }
//         }
//         return ans;