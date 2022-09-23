class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>&a, vector<int>&b) {
            return a[1]>b[1];
        });
        int cntBox = 0;   // count of boxes till this index
        int ans = 0;  // total number of units
        
        for(int i=0; i<boxTypes.size(); i++) {
            if(truckSize > cntBox+boxTypes[i][0]) {
                ans+=(boxTypes[i][0]*boxTypes[i][1]);
                cntBox += boxTypes[i][0];
            }
            else {
                int temp = truckSize-cntBox;
                ans+=(temp*boxTypes[i][1]);
                break;
            }
        }
        return ans;
    }
};