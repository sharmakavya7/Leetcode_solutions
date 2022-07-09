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
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());   // pas[] = 4 11 13 19 21 25 26 , buses[] = 10 20 30 , c=2
        
        unordered_map<int,int> mp;
        // int j=0;
        int i=0;
        int maxi = -1;

        for(int j=0; j<buses.size(); j++) {
            
            int temp = capacity;
            
            while(i<passengers.size() && passengers[i] <= buses[j]  && temp) {
                mp[passengers[i]]++;
                i++;
                temp--;
            }
            if(j == buses.size()-1) {
                if(temp==0) 
                    maxi = passengers[i-1];
                else maxi = buses[j];
            }
        }
        
        while(mp[maxi]) {
            maxi--;
        }
        return maxi;
    }
};