class Solution:
    def dis(self, p1: List[int], p2: List[int]) -> int:
        x = p1[0]-p2[0]
        y = p1[1]-p2[1]
        return math.ceil(math.sqrt((x*x)+(y*y)))

    def dfs(self, node: int, bombs: List[List[int]], vis: List[bool]) -> int:
        ret = 1
        vis[node] = True
        for i in range(len(bombs)):
            if not vis[i] and self.dis(bombs[node], bombs[i]) <= bombs[node][2]:
                ret += self.dfs(i, bombs, vis)
        return ret

    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        maxi = 0
        for i in range(len(bombs)):
            vis = [False]*len(bombs)
            maxi = max(maxi, self.dfs(i, bombs, vis))
        return maxi
