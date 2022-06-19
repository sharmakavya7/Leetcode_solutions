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
    // int minimumNumbers(int num, int k) {
    //     int ud = num % 10;
    //     if(num==0 && k>=0) {
    //         return 0;
    //     }
    //     else if(k==0 && ud!=0) {
    //         return -1;
    //     }
    //     else if(num<k) {
    //         return -1;
    //     }
    //     else {
    //         if(num%2==1 && k%2==0) {
    //             return -1;
    //         }
    //         else if(ud==k) {
    //             return 1;
    //         }
    //         else {
    //             int temp = 1;
    //             while(num>0){
    //                 temp += 1;
    //                 num-=k;
    //                 ud = num%10;
    //                 if(ud == k) {
    //                     return temp;
    //                 }
    //                 if(num<k) {
    //                     return -1;
    //                 }
    //             }
    //             return temp;
    //         }
    //     }
    //     return -1;
    // }
    
    // My solution:
    int minimumNumbers(int num, int k) {
        // Edge cases
        if(num==0) {
            return 0;
        }
        if( k%2 == 0 && num%2 != 0 || num<k ) {
            return -1;
        }
        
        // If a num's unit digit is in the multiplication table of k
        
        vector<int>possibility;
        
        for(auto i = 1; i<=10; i++) {
            int multiples = i*k;
            int ud = multiples%10;  // possible numbers ki unit digit sirf yei ho skti hai jo uski table me numbers hai unki unit digit hai
            possibility.push_back(ud);
        }
        // now we find the index of the unit digit of the sum(num) we're given
        auto it = find(possibility.begin(), possibility.end(), num%10);
        int index = it - possibility.begin();
        
        // if the index is not found, return -1
        
        if(index == possibility.size()) {
            return -1;
        }
        else { 
            index += 1;
        }
        // edge case(eg num = 4, k = 7 , then although 14's unit digit is 4 but 14 > 4)
        if(k*index > num) {
            return -1;
        }
        return index;
    }
};

