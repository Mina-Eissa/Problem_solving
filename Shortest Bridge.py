#link: https://leetcode.com/problems/shortest-bridge/description/

from typing import List
from collections import deque


class Solution:

    def valid(self, i: int, j: int, n: int, m: int) -> bool:
        return i >= 0 and j >= 0 and i < n and j < m

    def changeType(self, i: int, j: int, grid: List[List[int]], n: int, m: int) -> None:
        if not self.valid(i, j, n, m) or grid[i][j] == 0 or grid[i][j] == 2:
            return
        grid[i][j] = 2
        for idx in range(4):
            self.changeType(i + self.dx[idx], j + self.dy[idx], grid, n, m)

    def shortestBridge(self, grid: List[List[int]]) -> int:
        self.dx = [-1, 0, 1, 0]
        self.dy = [0, 1, 0, -1]
        n, m = len(grid), len(grid[0])
        ok = True
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    self.changeType(i, j, grid, n, m)
                    ok = 0
                    break
            if not ok:
                break

        q = deque()
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    q.append((i, j))
        level = 0
        while len(q) != 0:
            sz = len(q)
            for _ in range(sz):
                cur = q.popleft()
                for idx in range(4):
                    x, y = cur[0] + self.dx[idx], cur[1] + self.dy[idx]
                    if not self.valid(x, y, n, m):
                        continue
                    if grid[x][y] == 0:
                        grid[x][y] = 2
                        q.append((x, y))
                    if grid[x][y] == 1:
                        return level
            level += 1
