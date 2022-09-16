class Solution {
public:
    int trap(vector<int>& height) {
        // 2 pointer: O(N)
        int n = height.size(); 
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        
        while(left<=right) {
            if(height[left]<=height[right]) {
                
                if(height[left]>=maxleft) 
                    maxleft=height[left];
                
                else 
                    res+=maxleft-height[left];
                
                left++;
            }
            else {
                if(height[right]>=maxright) 
                    maxright= height[right];
                
                else 
                    res+=maxright-height[right];
                
                right--;
            }
        }
        return res;
        
        // Space: 3*O(N)
        // int n = height.size();
        // vector<int>preMax(n);  // specify their size, else runtime error
        // vector<int>sufMax(n);
        // preMax[0] = height[0];
        // sufMax[n-1] = height[n-1];
        // for(int i=1; i<n; i++) {
        //     preMax[i] = max(preMax[i-1],height[i]); 
        // }
        // for(int i=n-2; i>=0; i--) {
        //     sufMax[i] = max(sufMax[i+1],height[i]); 
        // }
        
        // PreMax: 0,1,1,2,2,2,2,3,3,3,3,3
        // SufMax: 3,3,3,3,3,3,3,3,2,2,2,1
        
        // int res = 0;
        // for(int i=0; i<n; i++) {
        //     res += min(preMax[i],sufMax[i]) - height[i];
        // }
        // return res;
    }
};