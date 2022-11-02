- The only way to find out which path is the shortest is to try all the paths and return the minimum. Recursion is helpful for solving such problems.
- We start from the initial position (top of the triangle), then choose between two paths. We can go to the same column or one ahead (column + 1). In terms of row, we have no choice but to move on to the next row (row + 1). Hence the two choices are,
1.  go to triangle[row + 1][col]
2.  go to triangle[row + 1][col + 1]
- This forms a recursive structure and the base case is when we pass the last row, where the answer will always be 0.
- Then optimize it to memo (Ezzzz)
​
Striver approach:
- Why didn't we start from the end in this ques like we previously did?
- Bcz it is more preferrable to start from a fixed point, i.e. first index. Had we started from the last row, we must have made n different recursive calls.