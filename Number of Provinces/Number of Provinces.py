class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        ctr = 0
        vis = [False] * n
        def dfs(node: int):
            vis[node] = True
            for i in range(n):
                if not vis[i] and isConnected[node][i]:
                    dfs(i)
        for i in range(n):
            if not vis[i]:
                ctr += 1
                dfs(i)
        return ctr