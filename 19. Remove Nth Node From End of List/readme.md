#### Brute: 
- Time Complex: O(n) + O(n) ~ O(n)
#### Optimal Idea:
- Move fast pointer till n
- Then move slow and fast pointers both by 1 till the fast ptr reaches last node.
- Whenever the fast->next becomes NULL, stop both the pointers and the node after the slow pointer will be the node that we have to delete.
- Now simply, break the link of slows next and point it to the next node of the node which is being deleted ie. slow->next->next
- TC: Fast pointer will be moving at max till n nodes. i.e. TC = O(n)