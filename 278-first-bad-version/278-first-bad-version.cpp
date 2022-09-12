// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 0;
        int end = n;
        int temp = 0;
        while(start<end) {
            int mid = start + (end - start)/2;
            // int temp = 0;
            if(!isBadVersion(mid)) {
                // temp = mid;
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        return start;
    }
};