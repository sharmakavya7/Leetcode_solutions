#### Logic: 

1. Go deep to the right most lead
2. Return back maintain a count variable
3. Assign the count to current root->val
4. Recur for left if not NULL

-  ###### TC: O(N) (Ulta Inorder Traversal) 

**In order to analyse the time complexity of a tree traversal you have to think in the terms of number of nodes visited. If a tree has n nodes, then each node is visited only once in inorder traversal and hence the complexity is O(n).**
-  ###### S.C: O(N)