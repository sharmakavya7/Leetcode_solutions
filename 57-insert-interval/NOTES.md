1. Pehle saare vo wale insert karo jo newinterval se chote hai, when this condition breaks, i.e. jab intervals[i][1] > newinterval[0]
2.**intervals[i][0] <= newInterval[1]** Now run a while loop  and now we'll manipulate newinterval and update it's value with everytime we see a number greater or smaller. How?
- newinterval[0] = min ( intervals[0], newinterval[0] )
- newinterval[1] = max( intervals[1], newinterval[1] )
​
3. Remaining intervals ko bhi ans vector me push krdo.