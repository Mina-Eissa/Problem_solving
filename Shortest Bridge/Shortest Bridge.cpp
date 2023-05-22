// link : https://leetcode.com/problems/shortest-bridge/description/

class Solution {
public:
    const int dx[4] = { -1,0,1,0 };
    const int dy[4] = { 0,1,0,-1 };
    inline bool valid(int& i, int& j, int& n, int& m) {
        return (i >= 0 && j >= 0 && i < n&& j < m);
    }
    void changeType(int i, int j, vector<vector<int>>& grid,int&n,int&m) {
        if (!valid(i, j, n, m) || grid[i][j] == 0 || grid[i][j] == 2)
            return;

        grid[i][j] = 2;
        for (int idx = 0; idx < 4; idx++)
            changeType(i + dx[idx], j + dy[idx], grid, n, m);
    }
    int shortestBridge(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size(), ok = 1;
        for (int r = 0; r < n && ok; r++) {
            for (int c = 0; c < m && ok; c++) {
                if (grid[r][c] == 1) {
                    changeType(r, c, grid, n, m);
                    ok = 0;
                }
            }
        }

        queue<pair<int, int>>q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({ i,j });
                }
            }
        }
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                pair<int, int>cur = q.front();
                q.pop();
                for (int idx = 0; idx < 4; idx++) {
                    int x = cur.first + dx[idx], y = cur.second + dy[idx];
                    if (!valid(x, y, n, m))
                        continue;

                    if (grid[x][y] == 0) {
                        grid[x][y] = 2;
                        q.push({ x,y });
                    }

                    if (grid[x][y] == 1)
                        return level;
                }
            }
            level++;
        }
        return level;
    }
};