- 0s and 1s are already grouped, so we dont need to care about the grouping.
- LOGIC: For example, if we find a group that is "0001111", then we know that we've found multiple answer counts centered on the "01". Each additional extra character on both sides will be an extra answer, which means that "0011" and "000111" are also answers. In other words, the number that we should add to ans is equal to min(zeros, ones), or 3 in this example.
- Check for the consecutive 0s and 1s by s[i]!=s[i-1]
- if this holds true then we'll add that count which is minimum(either zeroes' or ones')
- Else we inc the cur pointer as it has the count of the current group.
- the moment other groups arrives we put current count in the previous one.
- Detailed explanation: https://leetcode.com/problems/count-binary-substrings/discuss/1172553/JS-Python-Java-C%2B%2B-or-Easy-Rolling-Count-Solution-w-Explanation