// STL SOLUTION
class TimeMap {
public:
    unordered_map<string, map<int, string>> time_map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        // {timestamp, value} 
        time_map[key].insert({ timestamp, value });
    }
    
    string get(string key, int timestamp) {
        
        auto exist = (time_map.find(key) !=  time_map.end());
        
        if (!exist) {
            return "";
        }
        // binary search to find the value with a timestamp greater the requested one.
        
        auto it = time_map[key].upper_bound(timestamp);
        auto mini = time_map[key].begin();
        
        // if the first item with greater timestamp is equal to the first item in the time_map[key], it means there is no value with a timestamp less than or equal to the requestd one 
        
        if (it == mini) {
            return "";
        }

        return prev(it)->second;
    }
};
// ABOUT prev:
/* prev returns an iterator pointing to the element after being advanced by certain number of positions in the reverse direction. It is defined inside the header file iterator. It returns a copy of the argument advanced by the specified amount in the backward direction. If it is a random-access iterator, the function uses just once operator + or operator – for advancing. Otherwise, the function uses repeatedly the increase or decrease operator (operator ++ or operator – -) on the copied iterator until n elements have been advanced.  */
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

// BINARY SEARCH SOLUTION:
// typedef pair<int, string> pis;
// class TimeMap {
// public:
//     unordered_map<string, vector<pis>> m;
    
//     TimeMap() {
        
//     }

//     string greatestValLessThan(int timestamp, vector<pis>& s) {
        
//         int start = 0;
//         int end = s.size()-1;
//         int ans = INT_MIN;
//         string str = "";
        
//         while(start <= end) {
            
//             int mid = start + (end-start)/2;
//             auto x = s[mid];
//             int num = x.first;
//             string str_temp = x.second;
            
//             if(num > timestamp) {
//                 end = mid -1;
//             }
//             else {
//                 if(num > ans) {
//                     str = str_temp;
//                     ans = num;
//                 }
//                 start = mid+1;
//             }
//         }
//         return str;
//     }
    
//     void set(string key, string value, int timestamp) {
//         m[key].push_back({timestamp, value});
//     }
    
//     string get(string key, int timestamp) {
//         string ans = "";
//         ans = greatestValLessThan(timestamp, m[key]);
//         return ans;
//     }
// };

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */