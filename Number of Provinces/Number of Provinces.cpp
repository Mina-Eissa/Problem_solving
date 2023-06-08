class Solution
{
public:
    void dfs(int node, int &n, vector<vector<int>> &g, vector<bool> &vis)
    {
        vis[node] = 1;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && g[node][i])
                dfs(i, n, g, vis);
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size(), ctr = 0;
        vector<bool> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                ctr++;
                dfs(i, n, isConnected, vis);
            }
        }
        return ctr;
    }
};