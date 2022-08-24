class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int>preMax(n);  // specify their size, else runtime error
        vector<int>sufMax(n);
        preMax[0] = height[0];
        sufMax[n-1] = height[n-1];
        for(int i=1; i<n; i++) {
            preMax[i] = max(preMax[i-1],height[i]); 
        }
        for(int i=n-2; i>=0; i--) {
            sufMax[i] = max(sufMax[i+1],height[i]); 
        }
        int res = 0;
        for(int i=0; i<n; i++) {
            res += min(preMax[i],sufMax[i]) - height[i];
        }
        return res;
    }
};