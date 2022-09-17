- TC:
The TC should be O(n*logK). Here is why-
​
Max size of heap at any time is K.
We are inserting every element in the heap once which will cost us O(nlogK)
The inner loop is used to remove elements from the heap. So it will also run N times in total which will cost us O(nlogK)
Hence total TC will be 2O(nlogK) == O(n*logk)
​
And space complexity will be O(k) for maxheap.
​
-