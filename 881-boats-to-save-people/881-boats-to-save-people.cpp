class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // int remain=limit;
        int sum = 0;
        int cnt=0;
        sort(people.begin(), people.end());
        int i=0;
        int j=people.size()-1;
        while(i<=j) {
            
            if(people[i]+people[j]<=limit) {
                cnt++;
                i++;
                j--;
            }
            else {
                cnt++;
                j--;
            }
        }
        // if((remain<limit && remain>0) || ) cnt++;
        return cnt;
    }
};
            // if(people[i]==limit) {
            //     cnt++;
            // }
            // sum+=people[i];
            // if(sum>limit) {
            //     sum = 0;
            //     cnt=cnt+2;
            // }
            // i++;