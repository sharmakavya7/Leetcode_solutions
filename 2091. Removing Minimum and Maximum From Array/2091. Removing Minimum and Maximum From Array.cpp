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
    int minimumDeletions(vector<int>& nums) {
        int n =nums.size();
        if(n==1) {
            return 1;
        }
        if(n==2) {
            return 2;
        }
        int mini = min_element(nums.begin(),nums.end()) - nums.begin();   // 5
        int maxi = max_element(nums.begin(),nums.end()) - nums.begin();   // 1
 
        cout<<mini<<" "<<maxi<<endl;
        
        int front = max(maxi, mini) + 1;  //When removed from front only
		
		
        int back = n - min(mini, maxi);  //When removed from back only
		
		//When removed from both front and back
        int frontback = (min(mini, maxi) + 1) + (n - max(mini, maxi));
        
        return min(min(back,front),frontback);
    }
};