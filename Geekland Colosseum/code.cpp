
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib> 
#include <string>
#include <map>
#include <climits>
#include <iterator>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    void solve(int N, vector<int> &nums, vector<long long> &pehla, vector<long long> &dusra){
        priority_queue<int, vector<int>, greater<int>> m;
        priority_queue<int> k;
        long long sum = 0;
        for(int i=0;i<2*N;i++){
            sum+=nums[i];
            m.push(nums[i]);
            if(i<N-1) 
                continue;
            if(i==N-1) 
                pehla[i] = sum;
            else if(i>=N){
                sum = sum - m.top();
                m.pop();
                pehla[i] = sum;
            }
        }
        long long sum2 = 0;
        for(int i=3*N-1;i>=N;i--){
            sum2+=nums[i];
            k.push(nums[i]);
            if(i>2*N) continue;
            if(i==2*N) dusra[i] = sum2;
            else if(i<=2*N-1){
                sum2 = sum2 - k.top();
                k.pop();
                dusra[i] = sum2;
            }
        }
    }
    long long colosseum(int N,vector<int> v) {
       vector<long long> pehla(3*N, 0), dusra(3*N, 0);
       solve(N, v, pehla, dusra);
       long long ans = INT_MIN;
       for(int i=N-1;i<2*N;i++)
        ans = max(ans, pehla[i]-dusra[i+1]);
        return ans;
   }
};