class Solution
{
public:
    double slope(vector<int> &a, vector<int> &b)
    {
        if (a[1] == b[1])
            return 0;
        if (a[0] == b[0])
            return a[0];
        return (double)(a[1] - b[1]) / (a[0] - b[0]);
    }
    bool checkStraightLine(vector<vector<int>> &coor)
    {
        double s = slope(coor[1], coor[0]);
        for (int i = 2; i < coor.size(); i++)
        {
            if (slope(coor[i], coor[i - 1]) != s)
                return false;
        }
        return true;
    }
};