class Solution {
public:
//     bool isPrime(int n) {
//         if (n < 1)
//             return false;

//         // Check from 2 to n-1
//         for (int i = 2; i < n; i++)
//             if (n % i == 0)
//                 return false;

//         return true;
//     }
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 == 1) return {};
        sort(changed.begin(),changed.end());
        vector<int>ans;
        map<int,int>mp;
        for(int i:changed) {
            mp[i]++;
        }
        for(auto i:changed) {
            if (mp[i] == 0) continue;
            if (mp[i*2] == 0) return {};
            ans.push_back(i);
            mp[i]--;
            mp[i*2]--;
            // mp.erase(i);
            // mp.erase(i*2);
            
        }
        // cout<<endl;
        // if(mp.size()!=0) return {};
        return ans;
    }
};