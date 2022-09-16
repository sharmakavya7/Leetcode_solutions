1. sort the data first.
2. Take a pq.
3. why pq?
-Kyuki isi se hum track rkhenge ki Konsi meeting ka end time sabse pehle hai mtlb konsi meeting sabse pehle end ho rhi hai
4. Intuition:
- Tab tak traverse karo jab tak prev meet end hoke uski next start ho rhi hai and keep on throwing out that meeting jo ki over ho gyi hai.
- Jab aisi meeting aaaegi jo over nhi hui hai, aur next meet start ho gyi hai, to apan pop nhi krenge, new meeting ko pq me push kr denge aur loop krenge
- Whats the catch?
- We maintain a variable who'll store the max size of the pq at any moment, bcz that will give us the max no of rooms we require.