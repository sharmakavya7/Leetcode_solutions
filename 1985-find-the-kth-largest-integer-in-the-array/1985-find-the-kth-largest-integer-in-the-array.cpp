class Solution {
public:
    static bool cmp(string &a, string &b){
        if(a.size() == b.size())
            return a<b;  //lexicographical comparision
        else
            return a.size() < b.size();
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        return nums[nums.size()-k];
        
        // priority_queue<int, vector<int>, greater<int>>pq;
        // for(int i=0; i<nums.size(); i++) {
        //     int num = stoi(nums[i]);
        //     pq.push(num);
        //     if(pq.size()>k) {
        //         pq.pop();
        //     }
        // }
        // string ans = to_string(pq.top());
        // return ans;
    }
};