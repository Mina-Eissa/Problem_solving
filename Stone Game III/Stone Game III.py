class Solution:
    def stoneGameIII(self, v: List[int]) -> str:
        n = len(v)
        dp = [[0] * 2 for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            total_sum = 0
            dp[i][0] = -10**18
            dp[i][1] = 10**18
            for j in range(1, 4):
                if i + j - 1 < n:
                    total_sum += v[i + j - 1]
                    dp[i][0] = max(dp[i][0], dp[i + j][1] + total_sum)
                    dp[i][1] = min(dp[i][1], dp[i + j][0] - total_sum)
        if dp[0][0] > 0:
            return "Alice"
        elif dp[0][0] < 0:
            return "Bob"
        else:
            return "Tie"
