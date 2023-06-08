class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int ctr = 0, m = grid[0].size(), st, ed, mid;
        for (auto &it : grid)
        {
            st = 0, ed = m - 1;
            while (st <= ed)
            {
                mid = (st + ed) >> 1;
                if (it[mid] >= 0)
                    st = mid + 1;
                else
                    ed = mid - 1;
            }
            ctr += m - st;
        }
        return ctr;
    }
};