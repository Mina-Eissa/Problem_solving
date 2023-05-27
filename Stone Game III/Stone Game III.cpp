class Solution
{
public:
    string stoneGameIII(vector<int> &v)
    {
        int n = v.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            long long sum = 0;
            dp[i][0] = LLONG_MIN;
            dp[i][1] = LLONG_MAX;
            for (int j = 1; j <= 3 && i + j - 1 < n; j++)
            {
                sum += v[i + j - 1];
                dp[i][0] = max(dp[i][0], dp[i + j][1] + sum);
                dp[i][1] = min(dp[i][1], dp[i + j][0] - sum);
            }
        }
        if (dp[0][0] > 0)
        {
            return "Alice";
        }
        else if (dp[0][0] < 0)
        {
            return "Bob";
        }
        else
        {
            return "Tie";
        }
    }
};