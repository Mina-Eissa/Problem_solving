class Solution
{
public:
    long long dis(int &x1, int &y1, int &x2, int &y2)
    {
        long long x = (x2 - x1), y = (y2 - y1);
        return ceil(sqrt((x * x) + (y * y)));
    }
    int dfs(int node, vector<vector<int>> &b, vector<bool> &vis)
    {
        vis[node] = 1;
        int ret = 1;
        for (int i = 0; i < b.size(); i++)
        {
            if (!vis[i] && dis(b[node][0], b[node][1], b[i][0], b[i][1]) <= b[node][2])
                ret += dfs(i, b, vis);
        }
        return ret;
    }
    int maximumDetonation(vector<vector<int>> &b)
    {
        int n = b.size(), maxi = 0, ctr = 0;
        for (int i = 0; i < n; i++)
        {
            vector<bool> vis(n, 0);
            maxi = max(maxi, dfs(i, b, vis));
        }
        return maxi;
    }
};