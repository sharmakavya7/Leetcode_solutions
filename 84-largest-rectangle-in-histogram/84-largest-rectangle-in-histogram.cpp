class Solution {
public:
    void nseToLeft(vector<int>& leftSmall,vector<int> heights,int n){
        stack<int> s;
        for(int i=0;i<n;i++){

            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty())
                leftSmall[i]=-1;

            else
                leftSmall[i]=s.top();
            
            s.push(i);
        }
    }

    void nseToRight(vector<int>& rightSmall,vector<int> heights,int n){
        stack<int> s;
        for(int i=n-1; i>=0; i--){

            while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();

            if(s.empty())
                rightSmall[i] = n;

            else
                rightSmall[i] = s.top();

            s.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {

        int i,n=heights.size(),mx=0;
        vector<int> leftSmall(n),rightSmall(n);
        nseToLeft(leftSmall,heights,n);
        nseToRight(rightSmall, heights, n);

        vector<int>width(n);
        for(int i=0; i<n; i++) {
            width[i] = rightSmall[i]-leftSmall[i]-1;
        }
        for(int i=0;i<n;i++) {
            mx=max(mx,(width[i])*heights[i]);
        }

        return mx;
    }
};