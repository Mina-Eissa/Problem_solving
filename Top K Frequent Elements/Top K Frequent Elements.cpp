// link: https://leetcode.com/problems/top-k-frequent-elements/description/
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<pair<int, int>> fre;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int ctr = 1, n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                fre.push_back({ctr, nums[i - 1]});
                ctr = 1;
            }
            else
            {
                ctr++;
            }
        }
        fre.push_back({ctr, nums[n - 1]});
        sort(fre.rbegin(), fre.rend());
        for (int i = 0; i < k; i++)
            ans.push_back(fre[i].second);
        return ans;
    }
};