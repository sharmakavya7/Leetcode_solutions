Example: ABABBA
See, how are gonna know if a substring [ BABB ] is valid?
- Simple, Just take the current window size - count[max_frq]  ie. 4 - 3 = 1.
- What will this give us (what does this 1 indicate)? This will give us the number of characters that we need to replace from the current string to make the string a possible candidate to our answer.
- Now when we got the number of characters to be replaced, we'll check if that count is **less than or equal to** k or not, if yes, then this is a valid string, if no, then it's not a valid string.
​