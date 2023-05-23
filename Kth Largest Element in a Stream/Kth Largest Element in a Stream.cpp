// link : https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;

public:
    KthLargest(int k, vector<int> &nums)
    {
        K = k;
        for (auto it : nums)
        {
            pq.push(it);
            if (pq.size() > K)
            {
                pq.pop();
            }
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > K)
        {
            pq.pop();
        }
        return pq.top();
    }
};
