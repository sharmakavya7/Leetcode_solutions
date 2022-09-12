class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int left = 0;
        int right = tokens.size()-1;
        int score = 0;
        int maxi = 0;
        
        while(left <= right && power>=0) {
            // face up
            if(tokens[left]<=power) {
                power-=tokens[left];
                left++;
                score++;
                maxi = max(maxi,score);
            }
            // face down
            else {
                power+=tokens[right];
                right--;
                score--;
                if(score<0) {
                    return maxi;
                }
            }
        }
        return maxi;
    }
};