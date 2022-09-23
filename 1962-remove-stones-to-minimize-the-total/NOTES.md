The time complexity would be:
​
Creation of priority queue takes O(n) time.
i.) the for loop is running k times i.e O(k).
ii.) the insertion and deletion in a priority queue takes O(logn) time.
Traversing the priority queue to get the answer and deleting the top most element is taking O(nlogn) time.
Hence the total time complexity is O(n)+O(klogn)+O(nlogn)
=> O((n+k) logn)
​
Space Complexity: O(n) because of the priority queue.