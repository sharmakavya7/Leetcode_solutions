/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        stack<int>s;
        
        for(int i=0; i<n; i++) {
            s.push(i);
        }
        
        while(s.size()!=1) {
            int top1 = s.top();
            s.pop();
            int top2 = s.top();
            s.pop();
            
            if(knows(top1,top2)) {
                s.push(top2);
            }
            else s.push(top1);
        }
        int potential_candidate = s.top();
        // now single ele is left in stack which could or could not be the celeb
        // verify it:
        for(int i=0;i<n;i++){
            if(i != potential_candidate){
                if(knows(i,potential_candidate) == false) return -1;
                if(knows(potential_candidate,i)) return -1;
            }
        }
        return potential_candidate;
        // if(rowCheck && colCheck) {
        //     return candidate;
        // }
        // return -1;
    }
};