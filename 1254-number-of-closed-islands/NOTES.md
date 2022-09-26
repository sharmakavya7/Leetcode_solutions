https://www.linkedin.com/in/awais-tyagi-1073a1172/
/* IMPORTANT NOTE:
WHY I CANNOT USE `return dfs(g, i+1, j) && dfs(g, i, j+1) && dfs(g, i-1, j) && dfs(g, i, j-1);`???
- BECAUSE IF ANY OF THE FIRST DFS() RETURNS FALSE, FOLLOWING ONES WILL NOT EXECUTE!!! THEN WE DON'T HAVE THE CHANCE TO MARK THOSE 0s TO 1s!!!