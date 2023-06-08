class Solution
{
public:
    int dfs(int node, int par, vector<vector<int>> &adj, vector<int> &informTime)
    {
        int ret = 0;
        for (auto it : adj[node])
        {
            if (it != par)
            {
                ret = max(ret, dfs(it, node, adj, informTime));
            }
        }
        return ret + informTime[node];
    }
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            if (~manager[i])
                adj[manager[i]].push_back(i);
        }
        return dfs(headID, -1, adj, informTime);
    }
};