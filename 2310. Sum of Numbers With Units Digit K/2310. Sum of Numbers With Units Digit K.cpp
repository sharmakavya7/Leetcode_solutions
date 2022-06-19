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
    int minimumNumbers(int num, int k) {
        int ud = num % 10;
        if(num==0 && k>=0) {
            return 0;
        }
        else if(k==0 && ud!=0) {
            return -1;
        }
        else if(num<k) {
            return -1;
        }
        else {
            if(num%2==1 && k%2==0) {
                return -1;
            }
            else if(ud==k) {
                return 1;
            }
            else {
                int temp = 1;
                while(num>0){
                    temp += 1;
                    num-=k;
                    ud = num%10;
                    if(ud == k) {
                        return temp;
                    }
                    if(num<k) {
                        return -1;
                    }
                }
                return temp;
            }
        }
        return -1;
    }
};