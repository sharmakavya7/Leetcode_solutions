The trick to this ques is, approaching the question mark string from the target string.
- Find a substring in `target` that matches the `stamp`. target = `a | abca | ca`
- Once it is found, we change all the 'stamp-ed' characters as question mark. target = `a | ???? | ca`
- A question mark represents that any character can be put in that place.
- Now if we convert the first three question marks into bca, the substring starting with zero will also resemble from `stamp`. target = `| a??? | ? ca`  { Visualize: | abca | ?ca } -> target= `?????ca`
- Now, take last 4 characters, these can also be converted into a stamp, so change them into question mark. target = `??? | ??ca |` { Visualize: ??? | abca | } -> target = `???????`
- Now the string is all question-marked, i.e. it has question marks equal to the length of the target string. Return the resukt in opposite order.