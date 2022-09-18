class Solution {
public:
//     NAIVE:
//     TIME : O ( N * LOG N ) -> sort
//     O ( N ) -> number of diagonals
//     TOTAL -> O ( N * N * LOG N )

//     SPACE : O ( N ) -> Only on extra vector used

//     Create a vector k in which we will store the elements for a particular diagional.
//     We simply sort the vector and change the elements of that diagonal with elements of sorted vector.
    
    
//     OPTIMAL:
    
//     We can use a min heap instead of using vector and explicitly sorting after insert.
//     Priority_queue will sort automatically and then you have to just replace values after insertion.
    
//     T.C: O(m*n)
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        map<int, priority_queue<int, vector<int>, greater<int>>> diagonal;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                diagonal[j-i].push(mat[i][j]);  // this is getting pushed in a priority queue not in map, map ke [j-i]th key ke value me ye wali priority queue bani hai, jisme hum diagonal elements push kr rhe 
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                mat[i][j] = diagonal[j-i].top();
                diagonal[j-i].pop();
            }
        }
        return mat;
    }
};