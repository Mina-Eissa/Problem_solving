class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        adj = [[] for _ in range(n)]
        for i in range(n):
            if manager[i]!=-1:
                adj[manager[i]].append(i)
        def dfs(node:int,par:int)->int:
            ret=0
            for x in adj[node]:
                if x != par:
                    ret=max(ret,dfs(x,node))
            return ret+informTime[node]
        return dfs(headID,-1)