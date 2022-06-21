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

class Solutions {
    public:
		string FirstNonRepeating(string A){
		    // Code here
		    // int i = 0, j = 0;
		    queue<char>q;
		    unordered_map<char,int>mp;
		  //  for(auto ch : A) {
		  //      mp[ch]++;
		  //  }
		    string ans = "";
		    for(auto ch:A) {
		    // for(int i=0;i<A.length();i++){
		        // auto ch = A[i];
		        mp[ch]++;
		        q.push(ch);
		        while(!q.empty()) {
		            // auto t = q.front();
		            if(mp[q.front()]>1) {
		                q.pop();
		            }
		            else {
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty()) {
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}
};