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
    // k->string, i->row, j->col
    bool helper(vector<vector<char>>& board, const string& word, int i, int j, int k) {
        if(word.size()==k) {
            return true;
        }
        // not found
        if(i<0 || j<0 || i>board.size()-1 || j>board[0].size()-1) {  
            // cout<<"i: "<<i<<" j: "<<j<<endl;
            return false;
        }
        if(board[i][j] != word[k]) {
            return false;
        }
        // found
        
        board[i][j] = '1';     
        
        bool temp = helper(board, word, i, j+1, k+1) ||  // right
             helper(board, word, i+1, j, k+1) ||         // down
             helper(board, word, i-1, j, k+1) ||         // up
             helper(board, word, i, j-1, k+1);           // left
        
        board[i][j] = word[k];     // VERY IMP:  modify the content back
        
        return temp;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        // return helper(board, word, 0, 0, 0, n-1, m-1);  // Bhaiiiiii pass to kr sahi se
        for(int i=0; i<m; i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(helper(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};