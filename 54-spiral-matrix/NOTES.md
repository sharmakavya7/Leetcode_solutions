#### Break the problem
Given that we are at (row, col), where row is the row index, and col is the column index.
- move right: (row, col + 1)
- move downwards: (row + 1, col)
- move left: (row, col - 1)
- move upwards: (row - 1, col)
- When shall we change our direction? We need to turn when we either reach the matrix boundaries, or we reach the cells in the array that we have visited before. Matrix boundaries are fixed and provided already, but how could we know if we have visited a particular cell or not?
-  In fact, we have two different strategies and they will be introduced in the following approaches. Generally speaking, they are as follows:
1. Approach 1. We can move the boundaries towards the center of the matrix after we have traversed a row or a column. Then when we meet a boundary, we know it's time to change the direction and update the boundary.
2. Approach 2. While traversing the matrix, we can record each location that we have visited. Then when we meet a matrix boundary or a previously visited cell, we know it's time to change the direction.