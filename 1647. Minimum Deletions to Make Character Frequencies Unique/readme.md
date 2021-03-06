#### SET operations:
 
begin(): Returns an iterator to the first element of the set. 
Its time complexity is O(1).

clear(): Deletes all the elements in the set and the set will be empty. 
Its time complexity is O(N) where N is the size of the set.

count(): Returns 1 or 0 if the element is in the set or not respectively. 
Its time complexity is O(logN) where N is the size of the set.

empty(): Returns true if the set is empty and false if the set has at least 
one element. Its time complexity is O(1).

end(): Returns an iterator pointing to a position which is next to the 
last element. Its time complexity is O(1).

erase(): Deletes a particular element or a range of elements from the set. 
Its time complexity is O(N) where N is the number of element deleted.

find(): Searches for a particular element and returns the iterator 
pointing to the element if the element is found otherwise it will return 
the iterator returned by end(). Its time complexity is O(logN)
where N is the size of the set.

insert(): insert a new element. 
Its time complexity is O(logN) where N is the size of the set.

size(): Returns the size of the set or the number of elements in the set. 
Its time complexity is O(1).