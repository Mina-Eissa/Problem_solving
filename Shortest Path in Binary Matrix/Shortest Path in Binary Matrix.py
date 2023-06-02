class Solution:
    def valid(self, i: int, j: int, n: int) -> bool:
        return i >= 0 and j >= 0 and i < n and j < n

    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if grid[0][0] == 1 or grid[n-1][n-1] == 1:
            return -1
        self.dx = [-1, 1, 0, 0, -1, -1, 1, 1]
        self.dy = [0, 0, -1, 1, -1, 1, 1, -1]
        q = deque([(0, 0, 1)])
        while len(q) != 0:
            cur = q.popleft()
            if cur[0] == n-1 and cur[1] == n-1:
                return cur[2]

            for i in range(8):
                x, y = cur[0]+self.dx[i], cur[1]+self.dy[i]
                if self.valid(x, y, n) and grid[x][y] == 0:
                    q.append((x, y, cur[2]+1))
                    grid[x][y] = 1
        return -1
