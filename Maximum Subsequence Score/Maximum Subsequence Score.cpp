// link:https://leetcode.com/problems/maximum-subsequence-score/
class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> v;
        for (int i = 0; i < nums1.size(); i++)
        {
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] > b[0]; });
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0, sum = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            pq.push(v[i][1]);
            sum += v[i][1];
            if (pq.size() == k)
            {
                ans = max(ans, sum * v[i][0]);
                sum -= pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};