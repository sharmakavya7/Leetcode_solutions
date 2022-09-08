(1).  0 0 0 0        deals with only i=0 or j=0, sirf unhi ko change krega
0 1 1 1
0 1 1 1
(2).  ye i=1 & j=1 se start krega
For example, in 2nd example, consider 0,3 wala 0. it will pass the condition and jump in
mat[i][j] = 0, it will convert from i=1 to i=2 as 0.
(3). Sees if a col is true, traverse entire row and convert it to 0.
(4). Sees if a row is true, traverse entire col and convert it to 0.