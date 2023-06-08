class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int ctr = 0;
        while (c || a || b)
        {
            if (c & 1)
            {
                ctr += !(a & 1) && !(b & 1);
            }
            else
            {
                ctr += (a & 1) + (b & 1);
            }
            a >>= 1, b >>= 1, c >>= 1;
        }
        return ctr;
    }
};