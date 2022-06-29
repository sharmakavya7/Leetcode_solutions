### LOGIC:
***
- We have to increment n-1 elements by 1 to make them equal. This is equal to **decrementing only 1 element by 1.** Since we need to make all the elements equal we can consider he given problem to be equal to decrementing all the elements by 1 in each move *until they are equal to the minimum element in the array*.
- For example- [5,6,7,8] can be made equal if we decrement number 8, three times and 7, two times and 6 one times. Decrementing 8 by 1 is equal to adding 1 to all the other elements.
- Conclusion - We are just reversing the problem to make it simpler!!!!!!!