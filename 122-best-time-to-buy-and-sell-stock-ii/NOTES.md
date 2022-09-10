Recurrence:
- profit = max( (take + moving to nxt ind we can't take), (not take + moving to next ind we can take) );
- profit = max ( (sell + moving to nxt ind we can buy/take), (not sell + moving to next ind we can't buy cz we still have a stock that should be sold first) )
​
​
​
​
​
Brooooooooooooooooooooooooooooo
Trickkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
Ezzzzzzzzzzzzzzzzzzzz Pzzzzzzzzzzzzzz
- start iterating and find the the local minima, how?
- See if the prev ele is smaller than the cur one. If yes, add their diffference in profit.
​
​