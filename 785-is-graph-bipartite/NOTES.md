EXPLAINATION :
​
BIPARTITE GRAPH :
1. wo graph jisme parent node aur child node ka color same nhi hona chahiye ( baap aur bete ka color agar same he to graph biparte nhi hoga )
​
2. graph me ODD cycle nhi hona chahiye (agar odd cycle hoga to kisi na kisi parent node aur child node ka color same ho jayega )
​
Simply hme 1 conditions check karna he :-
​
1. baap(parent) aur bete(child) ka color same nhi hona chahiye. agar same he to Family(Graph) Bipartite NHI he.
​
​
NOTE : ham code me color ko 0 aur 1 se represent kar rahe he
​
Approach : using dfs
​
--> create a visited vector(jisme initially saare Node Unvisited rahege )
​
--> create a color vector (jisme initially saare nodes ka color 0 hoga)
​
​
--> if node is not visited to dfs krke check krlo
​
-->DFS :
​
--> pahle curr node ko visited mark kardo
​
--> abb uske neighbour(child) par traverse krO
​
--> child ka color baap ke color ka opposite mark karo (Baap gora beta KALA (Racism hogya ji)
​
--> agar beta visited nhi he to uske liye dfs call karke check karlo
​
--> kya bete(child) aur baap(parent) ka color same he
​
--> if Yess return False (Graph se not Bipartite)