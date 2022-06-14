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


vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    
     long long i = 0, j = 0;
     deque<long long>l;
     vector<long long>ans;
     
     while(j<N) {
         // calculations
         if(A[j]<0) {
             l.push_back(A[j]);
         }
         if(j-i+1 < K) {
             j++;
         }
         
         else if(j-i+1==K) {
             
            if(l.size()==0)     // when all no in window are +ve, i.e. no -ve number
                ans.push_back(0);
            else {
                ans.push_back(l.front());
            }
            if(A[i]<0)         // while moving window, we check if i is negative
                l.pop_front();  // if -ve; we pop it from queue bcz we no longer need it
            i++;j++;           // move window forward
        }
     }
     return ans;
                                                 
 }