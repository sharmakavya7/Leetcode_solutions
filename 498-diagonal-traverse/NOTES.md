Logic:
- The first diagonal is (0, 0). The second is (0, 1), (1, 0), the third is (2, 0), (1, 1), (0, 2), etc.
​
- It should be clear that the sum of row i and column j is equal to the index of the diagonal (diagonal number - 1). e.g. for the second diagonal (index 1), all possible pairings of (i, j) sum to 1, i.e. i + j = 1 for the 2nd diagonal. The maximum diagonal index is simply ((N-1) + (M-1)) = N + M - 2
​
- So to solve the problem we simply need iterate through all possible diagonal indices (denote this as s) and find all possible pairs (i, j) such that i + j = s
​
- We can find the ordering by looking at whether the diagonal index is even or odd.
- When the diagonal index is even we want to the first pair to be (s, 0) and
- when it is odd when want the first pair to be (0, s), and we decrease or increase i/j by 1 accordingly.