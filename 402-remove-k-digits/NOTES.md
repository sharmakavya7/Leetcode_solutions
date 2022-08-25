**Algorithm:**
- most significant digit will be removed first
- obverse the 1st maxima staring from 0 index, and remove it
- continue the process till k=0
​
​
**stack to string:**
while(!s.empty()) {
num[n-1] = s.top();
s.pop();
n = n-1;
}