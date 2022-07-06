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
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
	    int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];
        
        if(y2<=y3 || x4<=x1 || y4<=y1 || x2<=x3) {
            return false;
        }
        else return true;
        
//          Case-1: Rec2 intersects with Rec1 on top right corner

//                ____________________x4,y4
//               |                   |
//        _______|______x2,y2        |
//       |       |______|____________|
//       |      x3,y3   |
//       |______________|
//      x1,y1
              
//      Case-2: Rec2 intersects with Rec1 on top left corner
//        ___________________  x4,y4
//       |                   |
//       |            _______|____________x2,y2
//       |___________|_______|           |
//     x3,y3         |                   | 
//                   |___________________|
//                 x1,y1

//      Case-3: Rec2 intersects with Rec1 on bottom left corner
     
//                ____________________x2,y2
//               |                   |
//        _______|______x4,y4        |
//       |       |______|____________|
//       |      x1,y1   |
//       |______________|
//      x3,y3
              
//      Case-4: Rec2 intersects with Rec1 on bottom right corner
     
//        ___________________  x2,y2
//       |                   |
//       |            _______|____________x4,y4
//       |___________|_______|           |
//     x1,y1         |                   | 
//                   |___________________|
//                 x3,y3
    }
};